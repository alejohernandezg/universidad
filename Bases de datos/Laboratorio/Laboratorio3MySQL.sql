-- 1) Seleccionar el número de los teléfonos registrados del cliente ‘Bette’ ‘Imeson’ y la fecha de registro. Ordene por el número de teléfono. (Use funciones agregadas –aggregate functions, y cláusula ORDER BY)

SELECT
nombre,apellido,COUNT(numeroLinea) 
FROM
telefono INNER JOIN Cliente ON(ID=IDCliente)
WHERE
nombre='Bette'AND apellido='Imeson' GROUP BY nombre,apellido;

-- 2) Seleccione el mínimo y el máximo valor de las facturas del año 2016 (Use funciones agregadas –aggregate functions)

SELECT
MIN(valorAPagar),MAX(valorAPagar)
FROM
Factura NATURAL JOIN Periodo 
WHERE
EXTRACT(YEAR FROM fechaFacturacion)=2016;

-- 3) Listar el nombre de los clientes que viven en ‘CALI’, cuyo nombre inicia con ‘H’ o ‘B’ y tiene longitud mayor o igual a 3. (función LIKE) 

SELECT
nombre 
FROM
Ciudad INNER JOIN Cliente USING(codCiudad)
WHERE 
nombreCiudad='Cali' AND (nombre LIKE '%H%' OR nombre LIKE '%B%') AND char_length(nombre) >= 3;

-- 4) Seleccione el nombre de los clientes que en 2016 facturaron más de $ 1.000.000 (clausula HAVING)

SELECT
Cliente.nombre
FROM 
telefono INNER JOIN Cliente ON(ID=IDCliente) INNER JOIN PlanTelefono USING(IMEI,IDCliente) INNER JOIN Factura ON(IDPlantel=IDPlantelefono) INNER JOIN Periodo USING(idPeriodo) 
WHERE 
EXTRACT(YEAR FROM fechaFacturacion)=2016 GROUP BY Cliente.nombre HAVING SUM(Factura.valorAPagar) > 1000000;

-- 5) Seleccione el total de consumo de voz de cada mes del año 2016 que realizaron los clientes que viven en ‘BOGOTA’ (cláusula GROUP BY)

SELECT 
EXTRACT(MONTH FROM consumoVoz.fecha),SUM(consumoVoz.segundos) 
FROM 
consumoVoz NATURAL JOIN planTelefono INNER JOIN telefono USING(IMEI,IDCliente) INNER JOIN cliente ON(ID=IDCliente) NATURAL JOIN Ciudad
WHERE 
EXTRACT(YEAR FROM consumoVoz.fecha)=2016 AND Ciudad.nombreCiudad='Bogota' GROUP BY EXTRACT(MONTH FROM consumoVoz.fecha) ORDER BY EXTRACT(MONTH FROM consumoVoz.fecha);

-- 6) Seleccione por cada ciudad el total de consumo de datos por mes del año 2016 (cláusula GROUP BY).


SELECT
nombreCiudad,SUM(consumoDatos.cantidad)
FROM
Cliente NATURAL JOIN Ciudad INNER JOIN Telefono ON(IDCliente=ID) INNER JOIN PlanTelefono USING(IMEI,IDCliente) NATURAL JOIN ConsumoDatos
WHERE
EXTRACT(YEAR FROM consumoDatos.fecha)=2016 GROUP BY nombreCiudad;

-- 7) Listar el nombre de los clientes registraron un(os) teléfono(s) en 2015 pero no en 2016

SELECT 
nombre 
FROM 
Telefono INNER JOIN Cliente ON (IDCliente = ID)
WHERE
EXTRACT(YEAR FROM Telefono.fechaRegistro) = 2015
EXCEPT 
SELECT 
nombre
FROM
TELEFONO INNER JOIN Cliente ON (IDCliente = ID)
WHERE 
EXTRACT(YEAR FROM Telefono.fechaRegistro) = 2016; 

-- 8) Listar fecha y número de teléfono para los consumos de voz y los consumos de datos realizados en 2017

SELECT 
numeroLinea, fecha
FROM 
PlanTelefono NATURAL JOIN ConsumoVoz INNER JOIN Telefono USING (IDCliente, IMEI)
WHERE
EXTRACT(YEAR FROM fecha) = 2017 
UNION 
SELECT 
numeroLinea, fecha
FROM
ConsumoDatos NATURAL JOIN PlanTelefono INNER JOIN Telefono USING (IDCliente, IMEI) WHERE 
EXTRACT(YEAR FROM fecha) = 2017;

-- 9) Listar el nombre de los clientes que registraron un(os) teléfono(s) en 2015 y otro(s) en 2016

SELECT
nombre 
FROM
Cliente INNER JOIN Telefono ON (ID = IDCliente)
WHERE 
EXTRACT(YEAR FROM fechaRegistro) = 2015
INTERSECT
SELECT nombre FROM Cliente INNER JOIN Telefono ON (ID = IDCliente)
WHERE
EXTRACT(YEAR FROM fechaRegistro) = 2016;