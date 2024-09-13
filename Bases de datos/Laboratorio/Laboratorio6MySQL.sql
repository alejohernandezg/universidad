-- PUNTO 1

CREATE OR REPLACE FUNCTION fechaConsumo(numeroTelefono VARCHAR(12))
RETURNS INTEGER AS $$
	DECLARE
		newFechaCV DATE;
        newFechaCD DATE;
	BEGIN
		SELECT MAX(ConsumoVoz.fecha), MAX(ConsumoDatos.fecha) INTO newFechaCV,newFechaCD
		FROM ConsumoVoz NATURAL JOIN PlanTelefono INNER JOIN Telefono USING(IMEI,IDCliente) INNER JOIN ConsumoDatos USING(IDPlantel)
		WHERE numeroLinea = numeroTelefono
        GROUP BY numeroLinea;
        
        RAISE NOTICE 'Consumo de voz: %', newFechaCV;
        RAISE NOTICE 'Consumo de datos: %', newFechaCD;
        RETURN newFechaCV - newFechaCD;
    END; $$ LANGUAGE 'plpgsql';
    
    
-- PUNTO 2
    
CREATE OR REPLACE FUNCTION numerosCliente(nombreCliente VARCHAR(25),apellidoCliente VARCHAR(25))
RETURNS TEXT AS $$
    DECLARE
        rowData RECORD;
        numerosCliente TEXT := '';
    BEGIN        
        PERFORM * FROM Cliente INNER JOIN Telefono ON(ID=IDCliente) WHERE nombre = nombreCliente AND apellido = apellidoCliente;
        IF NOT FOUND THEN
            numerosCliente := 'Cliente no encontrado';
        ELSE 
            FOR rowData IN SELECT numeroLinea FROM Cliente INNER JOIN Telefono ON(ID=IDCliente) WHERE nombre=nombreCliente AND apellido=apellidoCliente LOOP
            numerosCliente := numerosCliente || rowData.numeroLinea || ', ';
            END LOOP;
        END IF;
    RETURN numerosCliente;
    END;$$ LANGUAGE 'plpgsql';
    
-- PUNTO 3

CREATE OR REPLACE FUNCTION cantidadSegundos()
RETURNS SETOF RECORD AS $$
DECLARE
    retReturn RECORD;
    retRecordNA RECORD;
    retRecordFC RECORD;
    fecha1 DATE;
    fecha2 DATE;
    fecha3 DATE;
    segundos1 SMALLINT;
    segundos2 SMALLINT;
    segundos3 SMALLINT;
    contador SMALLINT;
BEGIN
    DROP TABLE IF EXISTS tempTable;
    CREATE TABLE tempTable(nombre VARCHAR(25),apellido VARCHAR(25),nroTelefono VARCHAR(12), fecha1 DATE, segundos1 SMALLINT, fecha2 DATE, segundos2 SMALLINT, fecha3 DATE, segundos3 SMALLINT);
    
    FOR retRecordNA IN SELECT nombre,apellido,numeroLinea,ID FROM Cliente INNER JOIN Telefono ON (ID=IDCliente) LOOP
        contador = 1;
         fecha1 = NULL;
        fecha2 = NULL;
        fecha3 = NULL;
        segundos1 = 0;
        segundos2 = 0;
        segundos3 = 0;
        FOR retRecordFC IN SELECT fecha,segundos FROM PlanTelefono NATURAL JOIN ConsumoVoz INNER JOIN Telefono USING(IMEI,IDCliente) WHERE retRecordNA.ID = IDCliente AND retRecordNA.numeroLinea = numeroLinea ORDER BY fecha DESC LIMIT 3 LOOP
            IF contador = 1 THEN
                fecha1 = retRecordFC.fecha;
                segundos1 = retRecordFC.segundos;
            ELSEIF contador = 2 THEN
                fecha2 = retRecordFC.fecha;
                segundos2 = retRecordFC.segundos;
            ELSEIF contador = 3 THEN
                fecha3 = retRecordFC.fecha;
                segundos3 = retRecordFC.segundos;
            END IF;
            contador =contador+ 1;
        END LOOP;
        
        INSERT INTO tempTable VALUES(retRecordNA.nombre,retRecordNA.apellido,retRecordNA.numeroLinea,fecha1,segundos1,fecha2,segundos2,fecha3,segundos3);
    END LOOP;
        
    FOR retReturn IN SELECT * FROM tempTable ORDER BY nombre,apellido LOOP
        RETURN NEXT retReturn;
   
    END LOOP;
END; $$ LANGUAGE 'plpgsql';
    
SELECT * FROM cantidadSegundos() AS (nombre varchar,apellido varchar, numeroLinea varchar, fecha1 date, segundos1 smallint,fecha2 date,segundos2 smallint,fecha3 date,segundos3 smallint);

-- PUNTO 4

CREATE OR REPLACE FUNCTION updateValor(nombreTabla VARCHAR,atributo VARCHAR,valor1 VARCHAR,valor2 VARCHAR)
RETURNS VARCHAR AS $$
DECLARE
    retRecord RECORD;
BEGIN
EXECUTE 'SELECT ' || atributo || ' FROM ' || nombreTabla || ' WHERE ' || valor1 ||' = '|| nombreTabla|| '.' || atributo INTO retREcord;
 IF retRecord IS NOT NULL THEN
 EXECUTE 'UPDATE ' || nombreTabla || ' SET ' || atributo || ' = ' || valor2 || ' WHERE ' || atributo || ' = '|| valor1;
 RETURN 'Se actualizo el valor';
 ELSE
 Raise notice 'El Valor no existe en la base de datos';
 RETURN NULL;
 END IF;
 END;
 $$ LANGUAGE 'plpgsql';
 
 -- PUNTO 5
 
 CREATE OR REPLACE FUNCTION punto5(date) RETURNS TABLE(nombrecuidad varchar(20),TotalConsumoVozEnero integer, TotalConsumoVozFebrero integer, TotalConsumoVozMarzo integer) AS $$
DECLARE
	ano ALIAS FOR $1;
BEGIN
	RETURN QUERY SELECT nombrecuidad, segundos1, segundos2, segundos3 FROM (
		(SELECT ciudad.nombreciudad AS nombrecuidad, sum(segundos) as segundos1 FROM ciudad 
		JOIN cliente USING(codciudad) 
		JOIN plantelefono ON (id = idcliente) 
		JOIN consumovoz USING(idplantel) 
		WHERE (EXTRACT(MONTH FROM consumovoz.fecha) = 1) AND (EXTRACT(YEAR FROM consumovoz.fecha) = 2015)
		GROUP BY nombrecuidad) as enero
		NATURAL JOIN
		(SELECT ciudad.nombreciudad AS nombrecuidad, sum(segundos) as segundos2 FROM ciudad 
		JOIN cliente USING(codciudad) 
		JOIN plantelefono ON (id = idcliente) 
		JOIN consumovoz USING(idplantel) 
		WHERE (EXTRACT(MONTH FROM consumovoz.fecha) = 2) AND (EXTRACT(YEAR FROM consumovoz.fecha) = 2015)
		GROUP BY nombrecuidad) as febrero
		NATURAL JOIN
		(SELECT ciudad.nombreciudad AS nombrecuidad, sum(segundos) as segundos3 FROM ciudad 
		JOIN cliente USING(codciudad) 
		JOIN plantelefono ON (id = idcliente) 
		JOIN consumovoz USING(idplantel) 
		WHERE (EXTRACT(MONTH FROM consumovoz.fecha) = 3) AND (EXTRACT(YEAR FROM consumovoz.fecha) = 2015)
		GROUP BY nombrecuidad) as marzo)
		ORDER BY nombrecuidad;
END;
$$ LANGUAGE 'plpgsql';
