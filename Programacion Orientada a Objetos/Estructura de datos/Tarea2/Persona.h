//ALEJANDRO HERNANDEZ
//CARLOS PALOMEQUE

#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

class persona{
protected:
	string nombre;
	string direccion;
	string sexo;
	int edad;

public:
	persona(){};
	persona(string nuevoNombre,string nuevaDireccion,string nuevoSexo,int nuevaEdad):nombre(nuevoNombre), direccion(nuevaDireccion), sexo(nuevoSexo), edad(nuevaEdad){};
	string getNombre();
	string getDireccion();
	string getSexo();
	int getEdad();
	void setNombre(string);
	void setDireccion(string);
	void setSexo(string);
	void setEdad(int);
	~persona(){}
};


class estudiante : public persona
{
private:
	string carrera;
public:
	estudiante(string nuevaCarrera):carrera(nuevaCarrera){};
	string getCarrera();
	void setCarrera(string);
	~estudiante();
};


class empleado : public persona
{
private:
	string empresa;
public:
	empleado(string nuevaEmpresa):empresa(nuevaEmpresa){};
	string getEmpresa();
	void setEmpresa(string);
	~empleado();
};

class empleado_estudiante : public estudiante, public empleado
{
public:
	void getEmpresaEstudios();
	empleado_estudiante();
	~empleado_estudiante();
	
};