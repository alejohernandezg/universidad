--a
SELECT noDoc, nombre

FROM Usuario NATURAL JOIN Identificacion
    JOIN Tramite ON(IDUsuario = codUsuario)


EXCEPT

(SELECT noDoc, nombre
FROM Usuario NATURAL JOIN Identificacion
    JOIN Tramite ON(IDUsuario = codComprador));

----b
Listar la identificación, el nombre 
y la ciudad de las personas que han comprado más de 3
carros en el año 2017(como compradores o por registro de 
matrícula inicial)
SELECT noDoc, nombre, nombreCiudad, COUNT(noDoc)
FROM Identificacion NATURAL JOIN Usuario
    NATURAL JOIN ciudad
    JOIN Tramite ON(IDUsuario = codUsuario or IDUsuario = codComprador)
    NATURAL JOIN tipoTramite
WHERE  EXTRACT('YEAR' FROM fechaTramite) = 2017
GROUP BY IDUsuario,noDoc,nombre,nombreCiudad
HAVING count(noDoc)>3;
---c
SELECT     valorPago, nombreCiudad
FROM ciudad NATURAL JOIN Usuario
    JOIN Tramite ON(IDUsuario = codUsuario)
    NATURAL JOIN tipoTramite
WHERE  EXTRACT('YEAR' FROM fechaTramite) = 2017 AND nombreTramite='TRASPASO'
GROUP BY nombreCiudad, valorPago
ORDER BY valorPago desc;
---D
SELECT nombreCiudad, nombreMarca, count(nombreTramite)
FROM Usuario NATURAL JOIN ciudad
    NATURAL JOIN Vehiculo
    NATURAL JOIN Marca
    JOIN Tramite ON(IDUsuario = codUsuario)
    NATURAL JOIN tipoTramite
WHERE EXTRACT('YEAR' FROM fechaTramite) = 2017 AND nombreTramite ='MATRICULA'
GROUP BY nombreCiudad, nombreMarca
ORDER BY count(nombreTramite) desc;
---E
SELECT nombreCiudad, fechaTramite, AVG(valorPago)
FROM ciudad NATURAL JOIN Usuario
    JOIN Tramite ON(IDUsuario = codUsuario)
WHERE EXTRACT('YEAR' FROM fechaTramite) > 2009 or EXTRACT('YEAR' FROM fechaTramite) < 2018
GROUP BY nombreCiudad, fechaTramite
ORDER BY EXTRACT('YEAR' FROM fechaTramite) desc;
--F
SELECT nombre, COUNT(nombreTramite), nombreTramite
FROM Usuario JOIN Tramite ON(IDUsuario = codUsuario)
    NATURAL JOIN tipoTramite
GROUP BY nombre, nombreTramite
ORDER BY nombreTramite;
--G
SELECT nombreCiudad, AVG(valorPago), fechaTramite
FROM ciudad NATURAL JOIN Usuario
    JOIN Tramite ON(IDUsuario = codUsuario)
    WHERE EXTRACT('YEAR' FROM fechaTramite) = 2014
GROUP BY nombreCiudad, EXTRACT('MONTH' FROM fechaTramite), fechaTramite
HAVING AVG(valorPago) > 100000000

INTERSECT
SELECT nombreCiudad, AVG(valorPago), fechaTramite
FROM ciudad NATURAL JOIN Usuario
    JOIN Tramite ON(IDUsuario = codUsuario)
    WHERE EXTRACT('YEAR' FROM fechaTramite) = 2015
GROUP BY nombreCiudad, EXTRACT('MONTH' FROM fechaTramite), fechaTramite
HAVING AVG(valorPago) > 110000000

INTERSECT
SELECT nombreCiudad, AVG(valorPago), fechaTramite
FROM ciudad NATURAL JOIN Usuario
    JOIN Tramite ON(IDUsuario = codUsuario)
    WHERE EXTRACT('YEAR' FROM fechaTramite) = 2016
GROUP BY nombreCiudad, EXTRACT('MONTH' FROM fechaTramite), fechaTramite
HAVING AVG(valorPago) > 121000000;