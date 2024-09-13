DROP TABLE Documento CASCADE;
DROP TABLE Tramite CASCADE;
DROP TABLE tipoTramite CASCADE;
DROP TABLE Usuario CASCADE;
DROP TABLE Vehiculo CASCADE;
DROP TABLE Empresa CASCADE;
DROP TABLE Servicio CASCADE;
DROP TABLE Carroceria CASCADE;
DROP TABLE Combustible CASCADE;
DROP TABLE Linea CASCADE;
DROP TABLE Marca CASCADE;
DROP TABLE Ciudad CASCADE;
DROP TABLE Identificacion CASCADE;

CREATE TABLE Identificacion (
   codigoDoc VARCHAR PRIMARY KEY,
   tipoDoc CHAR(10) CHECK (tipoDoc IN('CC','NIT','N.N','PASAPORTE', 'TI', 'NUIP', 'CD', 'CE')) NOT NULL,
   noDoc int NOT NULL
);

CREATE TABLE Ciudad (
   codCiudad int PRIMARY KEY,
   nombreCiudad VARCHAR NOT NULL
);


CREATE TABLE Marca (
   codMarca int PRIMARY KEY,
   nombreMarca VARCHAR NOT NULL
);

CREATE TABLE Linea (
   codLinea int PRIMARY KEY,
   nombreLinea VARCHAR NOT NULL
);


CREATE TABLE Combustible (
   codCombustible int PRIMARY KEY,
   nombreCombustible VARCHAR NOT NULL
);

CREATE TABLE Carroceria (
   codCarroceria int PRIMARY KEY,
   nombreCarroceria VARCHAR NOT NULL
);


CREATE TABLE Servicio (
   codServicio int PRIMARY KEY,
   nombreServicio VARCHAR NOT NULL
);

CREATE TABLE Empresa (
   NIT int PRIMARY KEY,
   nombreEmpresa VARCHAR NOT NULL
);


CREATE TABLE Vehiculo (
        placa VARCHAR PRIMARY KEY,
        codMarca int REFERENCES Marca,
        codLinea int REFERENCES Linea,
        codCombustible int REFERENCES Combustible,
        codCarroceria int REFERENCES Carroceria,
        codServicio int REFERENCES Servicio,
        NIT  int REFERENCES Empresa,
        capacidad int NOT NULL,
        blindaje BOOLEAN NOT NULL,
        desmoteBlindaje BOOLEAN NOT NULL,
        NoMotor int NOT NULL,
        NoChasis int NOT NULL,
        NoAutomotores int NOT NULL,
        observaciones VARCHAR
);


CREATE TABLE Usuario (
   IDUsuario int PRIMARY KEY,
   primerApellido VARCHAR NOT NULL,
   segundoApellido VARCHAR NOT NULL,
   nombre VARCHAR NOT NULL,
   codigoDoc VARCHAR REFERENCES Identificacion,
   placa VARCHAR NOT NULL REFERENCES vehiculo,
   codCiudad int NOT NULL REFERENCES Ciudad,
   telefono int NOT NULL,
   firma varchar NOT NULL,
   comprador BOOLEAN NOT NULL
);

CREATE TABLE tipoTramite (
        codtipoTramite int PRIMARY KEY,
        nombreTramite VARCHAR NOT NULL
);

CREATE TABLE Tramite (
        codTramite int PRIMARY KEY,
        codtipoTramite int REFERENCES tipoTramite,
        placa VARCHAR REFERENCES Vehiculo NOT NULL,
        fechaTramite DATE NOT NULL,
        fechaPago DATE NOT NULL,
        codUsuario int REFERENCES Usuario(IDUsuario) NOT NULL,
        codComprador int REFERENCES Usuario(IDUsuario),
        valorPago int
);


CREATE TABLE Documento(
        codDocumento int PRIMARY KEY,
        codtipoTramite int REFERENCES tipoTramite,
        codTramite int REFERENCES Tramite,
        nombreDocumento VARCHAR NOT NULL
);

INSERT INTO Identificacion VALUES (0000, 'CC', 1144105552);
INSERT INTO Identificacion VALUES (0001, 'NIT', 1245106553);
INSERT INTO Identificacion VALUES (0010, 'N.N', 0011023458);
INSERT INTO Identificacion VALUES (0011, 'PASAPORTE', 123321587);
INSERT INTO Identificacion VALUES (0100, 'CE', 00121222);
INSERT INTO Identificacion VALUES (0101, 'TI', 990101117);
INSERT INTO Identificacion VALUES (0110, 'NUIP', 11235813);
INSERT INTO Identificacion VALUES (0111, 'CD', 3459876);
INSERT INTO Identificacion VALUES (1000, 'CC', 1144105552);
INSERT INTO Ciudad VALUES (00, 'Cali');
INSERT INTO Ciudad VALUES (01, 'Medellin');
INSERT INTO Ciudad VALUES (10, 'Bogota');
INSERT INTO Ciudad VALUES (11, 'Popayan');
INSERT INTO Marca VALUES (00, 'Kia');
INSERT INTO Marca VALUES (01, 'Mazda');
INSERT INTO Marca VALUES (10, 'BMW');
INSERT INTO Marca VALUES (11, 'Toyota');
INSERT INTO Linea VALUES (00, 'Linea1');
INSERT INTO Linea VALUES (01, 'Linea2');
INSERT INTO Linea VALUES (10, 'Linea3');
INSERT INTO Linea VALUES (11, 'Linea4');
INSERT INTO Combustible VALUES (00, 'Combustible1');
INSERT INTO Combustible VALUES (01, 'Combustible2');
INSERT INTO Combustible VALUES (10, 'Combustible3');
INSERT INTO Combustible VALUES (11, 'Combustible4');
INSERT INTO Carroceria VALUES (00, 'Carroceria1');
INSERT INTO Carroceria VALUES (01, 'Carroceria2');
INSERT INTO Carroceria VALUES (10, 'Carroceria3');
INSERT INTO Carroceria VALUES (11, 'Carroceria4');
INSERT INTO Servicio VALUES (00, 'Servicio1');
INSERT INTO Servicio VALUES (01, 'Servicio2');
INSERT INTO Servicio VALUES (10, 'Servicio3');
INSERT INTO Servicio VALUES (11, 'Servicio4');
INSERT INTO Empresa VALUES (00, 'Empresa1');
INSERT INTO Empresa VALUES (01, 'Empresa2');
INSERT INTO Empresa VALUES (10, 'Empresa3');
INSERT INTO Empresa VALUES (11, 'Empresa4');
--Placa, Marca, Linea, Combustible,Carroceria,Servicio,NIT,capacidad,blindaje,desmoteblindaje,#moto,#chasis,#automores,#observacion
INSERT INTO Vehiculo VALUES ('HPQ133', 00, 00, 00, 00, 00, 00, 6, false, false, 123, 132, 321, 'Carro en buen estado');
INSERT INTO Vehiculo VALUES ('ZWY321', 00, 00, 00, 00, 00, 00, 6, false, false, 123, 132, 321, 'Carro en buen estado');
INSERT INTO Vehiculo VALUES ('ABC123', 00, 00, 00, 00, 00, 00, 6, false, false, 123, 132, 321, 'Carro en buen estado');
INSERT INTO Vehiculo VALUES ('IVO101', 00, 00, 00, 00, 00, 00, 6, false, false, 123, 132, 321, 'Carro en buen estado');
INSERT INTO Vehiculo VALUES ('CFY111', 00, 00, 00, 00, 00, 00, 6, false, false, 123, 132, 321, 'Carro en buen estado');
INSERT INTO Vehiculo VALUES ('TWS788', 00, 00, 00, 00, 00, 00, 6, false, false, 123, 132, 321, 'Carro en buen estado');
INSERT INTO Vehiculo VALUES ('VAS888', 00, 00, 00, 00, 00, 00, 6, false, false, 123, 132, 321, 'Carro en buen estado');
INSERT INTO Vehiculo VALUES ('VSS798', 00, 00, 00, 00, 00, 00, 6, false, false, 123, 132, 321, 'Carro en buen estado');
INSERT INTO Vehiculo VALUES ('VWK789', 00, 00, 00, 00, 00, 00, 6, false, false, 123, 132, 321, 'Carro en buen estado');
--ID,apellido1,apellido2,nombre,codigoDoc,Placa,Telefono,firma,comprador
INSERT INTO Usuario VALUES (0000, 'Mamian','Del Rio', 'Jeferson Daniel', 0000, 'HPQ133',00, 123321, 'DANIEL MAMIAN', false);
INSERT INTO Usuario VALUES (0001, 'Hernandez','Gonzales', 'Alejandro', 0001, 'ZWY321', 01,123322, 'ALEJANDRO', false);
INSERT INTO Usuario VALUES (0010, 'Quiceno','Rico', 'Juan Sebastian', 0010, 'ABC123', 11,123323, 'QUICENO', false);
INSERT INTO Usuario VALUES (0011, 'Murcia','Ramanujan', 'Danny Julian', 0011, 'IVO101', 01,123324, 'RAMANUJAN', false);
INSERT INTO Usuario VALUES (0100, 'Escobar','Escobar2', 'Juan Fernando', 0100, 'HPQ133', 00, 123325, 'ESCOBAR', true);
INSERT INTO Usuario VALUES (0101, 'Carrero','Rivas', 'Maria Paula', 0101, 'ZWY321', 00,123326, 'CARRERO', true);
INSERT INTO Usuario VALUES (0110, 'Balanta','Posso', 'Nombre Balanta', 0110, 'ABC123', 01,123327, 'BALANTA', true);
INSERT INTO Usuario VALUES (0111, 'Franco','Lara', 'Nicolas', 0111, 'CFY111', 01,123321, 'FRANCO', false);
INSERT INTO Usuario VALUES (1000, 'Velazco','Garcia', 'Juan Sebastian', 1000, 'TWS788', 10, 123328, 'VELAZCO', false);
INSERT INTO Usuario VALUES (0000, 'Mamian','Del Rio', 'Jeferson Daniel', 0000, 'VAS888',00, 123321, 'DANIEL MAMIAN', false);
INSERT INTO Usuario VALUES (0000, 'Mamian','Del Rio', 'Jeferson Daniel', 0000, 'VSS798',00, 123321, 'DANIEL MAMIAN', false);
INSERT INTO Usuario VALUES (0000, 'Mamian','Del Rio', 'Jeferson Daniel', 0000, 'VWK789',00, 123321, 'DANIEL MAMIAN', false);
INSERT INTO tipoTramite VALUES (00, 'MATRICULA');
INSERT INTO tipoTramite VALUES (01, 'CANCELACION');
INSERT INTO tipoTramite VALUES (10, 'TRASPASO');
--idtramite, codtipotramite,placa,fechatramite,fechapago,codusuario,codcomprador,valorpago
INSERT INTO Tramite VALUES (0000, 10, 'HPQ133', '2017-11-11','2017-10-10', 0000, 0100, 25000000);
INSERT INTO Tramite VALUES (0001, 10, 'ZWY321', '2017-11-11','2017-10-10', 0001, 0101, 30000000);
INSERT INTO Tramite VALUES (0010, 10, 'ABC123', '2017-11-11','2017-10-10', 0010, 0110, 35000000);
INSERT INTO Tramite VALUES (0011, 00, 'CFY111', '2017-11-11','2017-10-10', 0111, null, 0);
INSERT INTO Tramite VALUES (0100, 00, 'TWS788', '2017-11-11','2017-10-10', 1000, null, 0);
INSERT INTO Tramite VALUES (0101, 01, 'IVO101', '2017-11-11','2017-10-10', 0011, null, 0); --va a cancelar
INSERT INTO Tramite VALUES (0110, 00, 'VAS888', '2017-11-11','2017-10-10', 0000, null, 0);
INSERT INTO Tramite VALUES (0111, 00, 'VSS798', '2017-11-11','2017-10-10', 0000, null, 0);
INSERT INTO Tramite VALUES (1000, 00, 'VWK789', '2017-11-11','2017-10-10', 0000, null, 0);
--tipotramite,tramitesactuales
INSERT INTO Documento VALUES (0000, 00, null, 'documentos1');
INSERT INTO Documento VALUES (0001, 01, null, 'documentos2');
INSERT INTO Documento VALUES (0010, 10, null, 'documentos3');
INSERT INTO Documento VALUES (0011, null, 0000, 'documentos3');
INSERT INTO Documento VALUES (0100, null, 0001, 'documentos3');
INSERT INTO Documento VALUES (0101, null, 0010, 'documentos3');
INSERT INTO Documento VALUES (0110, null, 0011, 'documentos1');
INSERT INTO Documento VALUES (0111, null, 0100, 'documentos1');
INSERT INTO Documento VALUES (1000, null, 0101, 'documentos2');
INSERT INTO Documento VALUES (1001, null, 0110, 'documentos1');
INSERT INTO Documento VALUES (1010, null, 0111, 'documentos1');
INSERT INTO Documento VALUES (1011, null, 1000, 'documentos1');