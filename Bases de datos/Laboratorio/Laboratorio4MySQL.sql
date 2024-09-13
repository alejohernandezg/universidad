-- 1) Use una subconsulta para seleccionar los números de los teléfonos que no tienen un plan activo. Presente la lista ordenada por número de teléfono

SELECT
numeroLinea
FROM
Telefono
WHERE
ROW(IMEI,IDCliente)
NOT IN
(
SELECT
IMEI,IDCliente
FROM
PlanTelefono
WHERE
estado = 'A'
)
ORDER BY numeroLinea;

-- 2) Liste en orden alfabético el apellido y nombre de todos los clientes, para aquellos que tienen un plan de teléfono activo, liste también el número de línea y el id del plan.

SELECT
nombre,
apellido,
numeroLinea,
IDPlan
FROM
Cliente LEFT JOIN 
(
    SELECT
    IDCliente,numeroLinea,IDPlan
    FROM
    Telefono INNER JOIN PlanTelefono USING(IMEI,IDCliente)
    WHERE
    PlanTelefono.estado='A'
)AS T ON(ID=IDCliente);


-- 3) Seleccione el nombre de los clientes que en alguna factura pagaron más que el promedio de los pagos de los clientes de su misma ciudad

SELECT
nombre
FROM
Cliente
INNER JOIN Telefono ON(id=IDCliente)
INNER JOIN PlanTelefono USING(IMEI,IDCliente)
INNER JOIN Factura ON(IDplantel = IDPlanTelefono)
NATURAL JOIN
(
    SELECT
    AVG(valorAPagar) AS promedioPago,codCiudad
    FROM
    Cliente
    INNER JOIN Telefono ON (id = idCliente)
    INNER JOIN planTelefono USING(IMEI,IDCliente)
    INNER JOIN Factura ON(IDPlanTel = IDPlanTelefono)
    GROUP BY codCiudad
)AS T
WHERE
valorAPagar > promedioPago
GROUP BY nombre;

-- 4)Seleccione el nombre de los clientes que tienen registrados al menos 3 teléfonos activos y con planes diferentes


SELECT DISTINCT
nombre,IDPlan
FROM
Cliente
INNER JOIN Telefono ON(id = IDCliente)
INNER JOIN PlanTelefono USING(IMEI,IDCliente)
WHERE
telefono.estado = 'A'
GROUP BY nombre
HAVING IDPlan >= 3;