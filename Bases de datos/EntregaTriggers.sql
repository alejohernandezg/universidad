
-- ARBOL --------------------------------------------------------------
CREATE OR REPLACE FUNCTION generarArbol(INTEGER ,INTEGER )
RETURNS SETOF TEXT AS $$
DECLARE
tempData TEXT;
color TEXT;
 
cursArcos SCROLL CURSOR FOR 
SELECT 
noDocumento,
nombre,
primerApellido,
vehiculoPlaca,
propietarioDocumento,
compradorDocumento,
tramiteTipo,
fechaTramite,
ROW_NUMBER() OVER (ORDER BY vehiculoPlaca, fechaTramite ASC) AS ROW 
FROM
Propietario INNER JOIN Tramite ON (noDocumento = propietarioDocumento)
WHERE 
EXTRACT('YEAR' FROM fechaTramite)>= $1 AND EXTRACT('YEAR' FROM fechaTramite)<= $2;

cursPlaca SCROLL CURSOR FOR 
SELECT 
vehiculoPlaca 
FROM
Propietario INNER JOIN Tramite ON (noDocumento = propietarioDocumento)
WHERE 
EXTRACT('YEAR' FROM fechaTramite) >=$1 AND EXTRACT('YEAR' FROM fechaTramite) <=$2 
GROUP BY
vehiculoPlaca;

cursNombres SCROLL CURSOR FOR 
SELECT 
noDocumento,
nombre,
primerApellido 
FROM
Propietario INNER JOIN Tramite ON (noDocumento = propietarioDocumento)
WHERE 
EXTRACT('YEAR' FROM fechaTramite) >= $1 AND EXTRACT('YEAR' FROM fechaTramite) <= $2 
GROUP BY
noDocumento;

cursActual RECORD;
cursSiguiente RECORD;
temp RECORD;
 
BEGIN
    RETURN NEXT 'graph tramites {';
    OPEN cursNombres;
    LOOP
        FETCH cursNombres INTO cursActual;
            tempData := '"' || cursActual.noDocumento || '_' || cursActual.nombre || cursActual.primerApellido || '"' || '[color=cyan];';
            EXIT WHEN NOT FOUND;
        RETURN NEXT tempData;
    END LOOP;

    OPEN cursPlaca;
    LOOP
        FETCH cursPlaca INTO cursActual;
            tempData := '"' || cursActual.vehiculoPlaca || '"' || '[color=aquamarine];';
            EXIT WHEN NOT FOUND;
        RETURN NEXT tempData;
    END LOOP;

    OPEN cursArcos;
    LOOP
        FETCH cursArcos INTO cursActual;
        FETCH cursArcos INTO cursSiguiente;
        MOVE BACKWARD 1 FROM cursArcos;        
        
        IF cursActual.vehiculoPlaca != cursSiguiente.vehiculoPlaca THEN
            -- cambio de color al VERDE soy el dueño
            -- Si es matricula o cancelacion el dueño es el propietario
            color := 'green';
        ELSE
            color := 'red';
            --Si el cursor siguiente del actual el nulo quiere decir que llego al final y es una placa diferente
            IF cursSiguiente.vehiculoPlaca IS NULL THEN
                IF cursActual.tramiteTipo = 0  OR cursActual.tramiteTipo = 2 THEN
                    color = 'green';
                ELSE
                    color = 'red';
                END IF;
            END IF;
        END IF;

        --Si el tramite de la placa es Matricularse o Cancelacion, el Propietario sera el propietarioDocumento
        IF cursActual.tramiteTipo = 0 OR cursActual.tramiteTipo = 1 THEN
                tempData := '"' || cursActual.propietarioDocumento || '_'  || cursActual.nombre || cursActual.primerApellido || '" -- "' || cursActual.vehiculoPlaca || '" [color=' || color || ', label="' || EXTRACT(YEAR FROM cursActual.fechaTramite) || '"];';
        ELSE
                --Si el tramite de la placa es Traspaso, el Propietario sera el compradorDocumento
                SELECT nombre, primerApellido INTO temp FROM Propietario WHERE noDocumento = cursActual.compradorDocumento;
                tempData := '"' || cursActual.compradorDocumento || '_'  || temp.nombre || temp.primerApellido || '" -- "' || cursActual.vehiculoPlaca || '" [color=' || color || ', label="' || EXTRACT(YEAR FROM cursActual.fechaTramite) || '"];';
        END IF;

        EXIT WHEN NOT FOUND;
        RETURN NEXT tempData;
    END LOOP;
    RETURN NEXT '}';

END; $$ LANGUAGE 'plpgsql';
-- ------------------------------------------------------------------------------
1)
CREATE OR REPLACE FUNCTION insertarTrasCancel()
RETURNS TRIGGER AS $$
DECLARE
temp INTEGER;
BEGIN
    IF NEW.tramiteTipo = 0 THEN
        RETURN NEW;
    END IF;
    
    SELECT tramiteTipo INTO temp FROM Tramite WHERE vehiculoPlaca = NEW.vehiculoPlaca AND (tramiteTipo = 0 OR tramiteTipo = 1) ORDER BY fechaTramite DESC LIMIT(1);
        IF temp = 0 THEN
            RETURN NEW;
        END IF;
    RETURN NULL;
END; $$ LANGUAGE 'plpgsql';
    
CREATE TRIGGER insertarTrasCancel BEFORE INSERT ON Tramite FOR EACH ROW EXECUTE PROCEDURE insertarTrasCancel();
2) 

CREATE OR REPLACE FUNCTION insertarVerificar()
RETURNS TRIGGER AS $$
DECLARE
temp RECORD;
BEGIN
    IF NEW.tramiteTipo = 1 OR NEW.tramiteTipo = 2 THEN
        SELECT tramiteTipo, propietarioDocumento, compradorDocumento INTO temp FROM Tramite WHERE vehiculoPlaca = NEW.vehiculoPlaca ORDER BY fechaTramite DESC LIMIT(1);

            IF temp.tramiteTipo = 2 THEN -- Traspaso
                IF temp.compradorDocumento = NEW.propietarioDocumento THEN
                    RETURN NEW;
                END IF;
                RETURN NULL;
            END IF;

            IF temp.tramiteTipo = 1 AND NEW.tramiteTipo = 1 THEN -- No puede cancelar dos veces
                RETURN NULL;
            END IF;

            IF (temp.propietarioDocumento = NEW.propietarioDocumento) THEN-- si es cancelar o si es matricula compare
                RETURN NEW;
            END IF;
            RETURN NULL;
    END IF;
    RETURN NEW;
END; $$ LANGUAGE 'plpgsql';

CREATE TRIGGER insertarVerificar BEFORE INSERT ON Tramite FOR EACH ROW EXECUTE PROCEDURE insertarVerificar();

3)

CREATE OR REPLACE FUNCTION verificarAños()
RETURNS TRIGGER AS $$
DECLARE
fechaMatricula DATE := NOW();

BEGIN
    SELECT fechaTramite INTO fechaMatricula FROM Propietario INNER JOIN Tramite ON (noDocumento = propietarioDocumento) INNER JOIN Tipo_Tramite USING (tramiteTipo) WHERE Tipo_Tramite.nombre = 'Matricula'
            AND vehiculoPlaca = NEW.vehiculoPlaca;

    IF (NEW.fechaTramite - fechaMatricula >= 14600) THEN -- 40 años
        IF NEW.tramiteTipo = 1 THEN
            RETURN NEW;
        END IF;
        RETURN NULL;
    END IF;      
       
    RETURN NEW;
END; $$ LANGUAGE 'plpgsql';
    
CREATE TRIGGER verificarAños BEFORE INSERT ON Tramite FOR EACH ROW EXECUTE PROCEDURE verificarAños();

4)

CREATE OR REPLACE FUNCTION verificarPago()
RETURNS TRIGGER AS $$
DECLARE
pagoTemp INTEGER;
BEGIN
    SELECT Tipo_Tramite.pago INTO pagoTemp FROM Tipo_Tramite WHERE tramiteTipo = NEW.tramiteTipo;

    IF (NEW.pagoRealizado = pagoTemp) THEN
            RETURN NEW;
    END IF;    
    RETURN NULL;
END; $$ LANGUAGE 'plpgsql';
    
CREATE TRIGGER verificarPago BEFORE INSERT OR UPDATE ON Tramite FOR EACH ROW EXECUTE PROCEDURE verificarPago();


5)

CREATE OR REPLACE FUNCTION verificarPago()
RETURNS TEXT AS $$
DECLARE
textRetorno TEXT;
curs1 CURSOR FOR SELECT noDocumento, nombre, primerApellido, vehiculoPlaca, propietarioDocumento, compradorDocumento, tramiteTipo, fechaTramite FROM Propietario INNER JOIN Tramite ON (noDocumento = propietarioDocumento) ORDER BY vehiculoPlaca, fechaTramite ASC;
cursActual RECORD;
cursSiguiente RECORD;

BEGIN
    OPEN curs1;
    LOOP
        FETCH curs1 INTO cursActual;
        MOVE curs1;
        FETCH curs1 INTO cursSiguiente;
        BACKWARD curs1; -- Hipoteticamente

        IF cursActual.vehiculoPlaca != cursSiguiente.vehiculoPlaca THEN
            -- cambio de color al VERDE soy el dueño

            -- Si es matricula o cancelacion el dueño es el propietario
            IF cursActual.tramiteTipo = 0 OR cursActual.tramiteTipo = 1 THEN
                RAISE NOTICE 'EL DUEÑO ES: %', cursActual.propietarioDocumento;
            END IF;

            -- el dueño es al que se traspaso el carro
            IF cursActual.tramiteTipo = 2 THEN
                RAISE NOTICE 'EL DUEÑO ES: %', cursActual.compradorDocumento;
            END IF;
        ELSE
            -- NO cambio color sigo en ROJO
            IF cursActual.tramiteTipo = 0 OR cursActual.tramiteTipo = 1 THEN
                RAISE NOTICE 'EL DUEÑO ES: %', cursActual.propietarioDocumento;
            END IF;

            -- el dueño es al que se traspaso el carro
            IF cursActual.tramiteTipo = 2 THEN
                RAISE NOTICE 'EL DUEÑO ES: %', cursActual.compradorDocumento;
            END IF;
        END IF;
    END LOOP;
END; $$ LANGUAGE 'plpgsql';

