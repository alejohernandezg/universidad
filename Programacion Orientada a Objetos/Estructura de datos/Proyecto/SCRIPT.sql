DROP TABLE TipoDocumento;
DROP TABLE Ciudad;
DROP TABLE Propietario;
DROP TABLE Marca;
DROP TABLE Linea;
DROP TABLE Color;
DROP TABLE ClaseVehiculo;
DROP TABLE Carroceria;
DROP TABLE Servicio;
DROP TABLE Empresa;
DROP TABLE Vehiculo;
DROP TABLE Propietario_Vehiculo;
DROP TABLE Organizacion;
DROP TABLE Documento;
DROP TABLE Tipo_Tramite;
DROP TABLE Doc_Tramites;
DROP TABLE Tramite;

CREATE TABLE TipoDocumento(
	tipoDocumento SMALLINT PRIMARY KEY CHECK (tipoDocumento >= 0),
	Nombre VARCHAR(20) NOT NULL
);

CREATE TABLE Ciudad(
	codCiudad INTEGER PRIMARY KEY,
	nombre VARCHAR(15) NOT NULL
);

CREATE TABLE Propietario(
	noDocumento BIGINT PRIMARY KEY CHECK (noDocumento >= 0),
	tipoDocumento SMALLINT NOT NULL REFERENCES TipoDocumento (tipoDocumento),
	nombre VARCHAR(25) NOT NULL,
	primerApellido VARCHAR(15) NOT NULL,
	segundoApellido VARCHAR(15) NOT NULL,
	direccion VARCHAR(30),
	codCiudad INTEGER NOT NULL REFERENCES Ciudad (codCiudad),
	telefono VARCHAR(12),
	firma BYTEA NOT NULL
);

CREATE TABLE Marca(
	codMarca INTEGER PRIMARY KEY,
	nombre VARCHAR(15) NOT NULL
);

CREATE TABLE Linea(
	codLinea INTEGER PRIMARY KEY,
	nombre VARCHAR(10) NOT NULL
);

CREATE TABLE Color(
	codColor SMALLINT PRIMARY KEY,
	nombre VARCHAR(10) NOT NULL
);

CREATE TABLE ClaseVehiculo(
	codClase SMALLINT PRIMARY KEY,
	nombre VARCHAR(20) NOT NULL
);

CREATE TABLE Carroceria(
	codCarroceria SMALLINT PRIMARY KEY,
	nombre VARCHAR(20) NOT NULL
);

CREATE TABLE Servicio(
	codServicio SMALLINT PRIMARY KEY,
	nombre VARCHAR(10) NOT NULL
);

CREATE TABLE Empresa(
	NIT INTEGER PRIMARY KEY CHECK (NIT >= 0),
	nombre VARCHAR(25) NOT NULL
);

CREATE TABLE Vehiculo (
	placa CHAR(6) PRIMARY KEY,
	codMarca INTEGER NOT NULL REFERENCES Marca(codMarca),
	codLinea INTEGER NOT NULL REFERENCES Linea(codLinea),
	codColor SMALLINT NOT NULL REFERENCES Color(codColor),
	modelo INTEGER NOT NULL CHECK (modelo > 0),
	cilindrada DECIMAL NOT NULL CHECK (cilindrada > 0),
	capacidad INTEGER NOT NULL CHECK (capacidad > 0),
	blindaje BOOLEAN NOT NULL,
	blindajeResolucion DATE,
	desmonteBlind BOOLEAN NOT NULL,
	desmonteBlindResol DATE CHECK (desmonteBlindResol >= blindajeResolucion),
	potencia INTEGER NOT NULL CHECK (potencia > 0),
	codClase SMALLINT NOT NULL REFERENCES ClaseVehiculo(codClase),
	codCarroceria SMALLINT NOT NULL REFERENCES Carroceria(codCarroceria),
	noMotor INTEGER NOT NULL CHECK (noMotor > 0),
	motorRegrabado BOOLEAN NOT NULL,
	noChasis INTEGER NOT NULL CHECK (noChasis > 0),
	chasisRegrabado BOOLEAN NOT NULL,
	noSerie INTEGER NOT NULL CHECK (noSerie > 0),
	serieRegrabado BOOLEAN NOT NULL,
	tipoImpRem CHAR(1) NOT NULL CHECK (tipoImpRem = 'M' OR tipoImpRem = 'D' OR tipoImpRem = 'A' OR tipoImpRem = 'L' OR tipoImpRem = 'C'),
	docImpRem INTEGER NOT NULL CHECK (docImpRem > 0),
	fechaImpRem DATE NOT NULL,
	alerta VARCHAR(10) NOT NULL,
	codServicio SMALLINT NOT NULL REFERENCES Servicio(codServicio),
	NIT INTEGER REFERENCES Empresa(NIT),
	observacionesAlerta VARCHAR(25),
	ObservacionesTras VARCHAR(25)
 );

CREATE TABLE Propietario_Vehiculo(
	noDocumento BIGINT NOT NULL REFERENCES Propietario(noDocumento),
	placa CHAR(6) NOT NULL REFERENCES Vehiculo(placa),
	PRIMARY KEY(noDocumento,placa)
);

CREATE TABLE Organizacion(
	organizacionId INTEGER PRIMARY KEY,
	codCiudad INTEGER NOT NULL REFERENCES Ciudad(codCiudad)
);

CREATE TABLE Documento(
	documentoId SMALLINT PRIMARY KEY,
	nombre VARCHAR(15) NOT NULL
);

CREATE TABLE Tipo_Tramite(
    tramiteTipo INTEGER PRIMARY KEY,
    nombre VARCHAR(15) NOT NULL,
    pago INTEGER NOT NULL CHECK (pago >= 0)
);

CREATE TABLE Doc_Tramites(
	documentoId SMALLINT PRIMARY KEY REFERENCES Documento(documentoId),
	tramiteId BIGINT NOT NULL REFERENCES Tramite(tramiteId)
);

CREATE TABLE Tramite(
	tramiteId BIGINT PRIMARY KEY CHECK(tramiteId >= 0),
	propietarioDocumento BIGINT NOT NULL REFERENCES Propietario(noDocumento),
	vehiculoPlaca CHAR(6) NOT NULL REFERENCES Vehiculo(placa),
	compradorDocumento BIGINT REFERENCES Propietario(noDocumento),
	fechaTramite DATE NOT NULL,
	fechaPago DATE CHECK(fechaPago >= fechaTramite),
	entidadBancaria VARCHAR(20) NOT NULL,
	noComprobante INTEGER NOT NULL CHECK(noComprobante >= 0),
	organizacion INTEGER NOT NULL REFERENCES Organizacion(organizacionId),
    tramiteTipo INTEGER NOT NULL REFERENCES Tipo_Tramite(tramiteTipo)
 );

CREATE TABLE Doc_Necesarios(
	idTramite SMALLINT NOT NULL REFERENCES Tipo_Tramite(tramiteTipo),
	documentoId SMALLINT NOT NULL REFERENCES Documento(documentoId),
	PRIMARY KEY(idTramite,documentoId)
);