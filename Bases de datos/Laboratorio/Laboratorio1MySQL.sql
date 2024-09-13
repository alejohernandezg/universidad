DROP TABLE Ciudad;
DROP TABLE Plan;
DROP TABLE Cliente;
DROP TABLE planTelefono;
DROP TABLE telefono;

CREATE TABLE Ciudad(
    codCiudad INTEGER,
    nombreCiudad VARCHAR(20) NOT NULL,
    PRIMARY KEY(codCiudad)
);

INSERT INTO Ciudad (codCiudad,nombreCiudad) VALUES (76001,'Cali'),(11001,'Bogota'),(05001,'Medellin'),(08001,'Cartagena');

CREATE TABLE Plan(
    IDPlan SMALLINT PRIMARY KEY,
    tipoPlan CHAR(1) CHECK (tipoPlan = 'V' OR tipoPlan = 'D' OR tipoPlan = 'A'),
    INTEGER CHECK (maxMinutos >= 0) NOT NULL,maxGigaB SMALLINT CHECK (maxGigaB >= 0) NOT NULL,
    valorMes INTEGER CHECK(valorMes > 10000) NOT NULL
);

INSERT INTO Plan (IDPlan,tipoPlan,maxMinutos,maxGigaB,valorMes) VALUES (100,'V',100000,0,25000),(200,'V',300000,0,45000),(300,'V',500000,0,60000),(400,'D',0,2,30000),(500,'D',0,5,50000),(600,'D',0,10,65000),(700,'A',100000,2,45000),(800,'A',300000,2,60000),(900,'A',500000,10,75000);

CREATE TABLE Cliente(
    ID BIGINT PRIMARY KEY,
    nombre VARCHAR(25),
    apellido VARCHAR(25) NOT NULL,
    direccion VARCHAR(30),
    codCiudad INTEGER REFERENCES Ciudad
);


CREATE TABLE Telefono(
    IMEI BIGINT UNIQUE,
    ID BIGINT,
    numeroLinea VARCHAR(12) NOT NULL,
    fechaRegistro DATE NOT NULL,
    fechaRetiro DATE CHECK(fechaRetiro >= fechaRegistro),
    estado CHAR(1) NOT NULL CHECK(estado = 'A' OR estado = 'I'),
    PRIMARY KEY(IMEI,ID)
);

CREATE TABLE PlanTelefono(
    IDPlanTel BIGINT PRIMARY KEY,
    IMEI BIGINT NOT NULL REFERENCES Telefono (IMEI),
    ID BIGINT NOT NULL REFERENCES Telefono (ID),
    IDPlan SMALLINT REFERENCES Plan,
    fechaInicio DATE NOT NULL,
    fechaFin DATE CHECK(fechaFin >= fechaInicio),
    estado CHAR(1) NOT NULL CHECK(estado = 'A' OR estado = 'I')
);

CREATE TABLE Periodo(
    IDPeriodo SMALLINT PRIMARY KEY,
    fechaFacturacion DATE NOT NULL,
    fechaInicioPeriodo DATE NOT NULL,
    fechaFinPeriodo DATE NOT NULL CHECK (fechaFinPeriodo > fechaInicioPeriodo),
    fechaPago DATE NOT NULL CHECK (fechaPago > fechaFinPeriodo)
);

CREATE TABLE ConsumoDatos(
    nroConsumoD BIGINT PRIMARY KEY,
    IDPlanTel BIGINT NOT NULL REFERENCES PlanTelefono,
    fecha DATE NOT NULL,
    cantidad NUMERIC(6,2) NOT NULL CHECK (cantidad > 0),
    IDPeriodo SMALLINT NOT NULL REFERENCES Periodo
);

CREATE TABLE ConsumoVoz(
    nroConsumoV BIGINT PRIMARY KEY,
    IDPlanTel BIGINT NOT NULL REFERENCES PlanTelefono,
    fecha DATE NOT NULL,
    segundos SMALLINT NOT NULL CHECK(segundos > 0),
    IDPeriodo SMALLINT NOT NULL REFERENCES Periodo
);

CREATE TABLE Factura(
    nroFactura BIGINT PRIMARY KEY,
    IDPlanTel BIGINT NOT NULL REFERENCES PlanTelefono,
    IDPeriodo SMALLINT NOT NULL REFERENCES Periodo,
    totalSegundos BIGINT CHECK(totalSegundos >= 0) DEFAULT 0,
    totalDatos NUMERIC(6,2) CHECK(totalDatos >= 0) DEFAULT 0,
    valorAPagar BIGINT CHECK(valorAPagar >= 0) DEFAULT 0
);

-- Convertimos el xlsx a csv//
-- Abrimos otro escher en otro terminal//
-- 	sftp bd07@escher.puj.edu.co
-- 	put Cliente.csv
-- En el terminal de la base de datos//

\copy Cliente FROM 'Cliente.csv' DELIMITER ',';
\copy Telefono FROM 'Telefono.csv' DELIMITER ';';
\copy PlanTelefono FROM 'PlanTelefono.csv' DELIMITER ';';
\copy Periodo FROM 'Periodo.csv' DELIMITER ';';
\copy ConsumoVoz FROM 'ConsumoVoz.csv' DELIMITER ';';
\copy Factura FROM 'Factura.csv' DELIMITER ';';
\copy ConsumoDatos FROM 'ConsumoDatos.csv' DELIMITER ';';
