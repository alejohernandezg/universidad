//ALEJANDRO HERNANDEZ
//CARLOS PALOMEQUE


#include "Persona.h"


// CLASE PERSONA--------------------------------------------------------------
string persona::getNombre(){
	return nombre;
};

string persona::getDireccion(){
	return direccion;
};

string persona::getSexo(){
	return sexo;
};
int  persona::getEdad(){
	return edad;
};

void persona::setNombre(string nuevoNombre){
	nombre = nuevoNombre;
};

void persona::setDireccion(string nuevaDireccion){
	direccion = nuevaDireccion;
};

void persona::setSexo(string nuevoSexo){
	sexo = nuevoSexo;
};
void  persona::setEdad(int nuevaEdad){
	edad = nuevaEdad;
};

// CLASE ESTUDIANTE--------------------------------------------------------------

string estudiante::getCarrera(){
	return carrera;
};

void estudiante::setCarrera(string nuevaCarrera){
	carrera=nuevaCarrera;
};

// CLASE EMPLEADO--------------------------------------------------------------

string empleado::getEmpresa(){
	return empresa;
};

void empleado::setEmpresa(string nuevaEmpresa){
	empresa=nuevaEmpresa;
};


// CLASE EMPLEADO_ESTUDIANTE--------------------------------------------------------------

VOID empleado_estudiante::getEmpresaEstudios(){
	cout << "Trabaja en " << getEmpresa() << " y estudia "<< getCarrera()<<endl;
};
