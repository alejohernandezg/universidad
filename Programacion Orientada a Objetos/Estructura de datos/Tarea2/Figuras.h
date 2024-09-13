//ALEJANDRO HERNANDEZ
//CARLOS PALOMEQUE



#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;



class Figura
{
protected:
	float posX;
	float posY;
	float grosorLinea;
	string color;

public:
	Figura(float nuevaPosX,float nuevaPosY,float nuevoGrosor,string nuevoColor):posX(nuevaPosX),posY(nuevaPosY),grosorLinea(nuevoGrosor),color(nuevoColor){};
	void getPos();
	float getGrosor();
	string getColor();
	virtual float getArea(){};
	virtual float getPerimetro(){};
};


class circulo:public Figura{

private:
	float radio;
	float pi;

public:

	circulo(float nuevoRadio,float nuevaPosX,float nuevaPosY,float nuevoGrosor,string nuevoColor):Figura(nuevaPosX,nuevaPosY,nuevoGrosor,nuevoColor){
		radio = nuevoRadio;
		posX = nuevaPosX;
		posY = nuevaPosY;
		grosorLinea = nuevoGrosor;
		color = nuevoColor;
		pi=3.14159265358979323846;
	}
	float getRadio();
	void changeRadio(float nuevoValor);
	float getArea();
	float getPerimetro();
};

class cuadrado:public Figura
{
private:
	float lado;
public:
	cuadrado(float nuevoLado,float nuevaPosX,float nuevaPosY,float nuevoGrosor,string nuevoColor):Figura(nuevaPosX,nuevaPosY,nuevoGrosor,nuevoColor){
		lado = nuevoLado;
		posX = nuevaPosX;
		posY = nuevaPosY;
		grosorLinea = nuevoGrosor;
		color = nuevoColor;
	}
	float getLado();
	void changeLado(float nuevoValor);
	float getArea();
	float getPerimetro();
	//int getPerimetro();	PROFE NO ME DEJA HACERSE SOBRECARGA POR QUE ME DICE QUE ES VIRTUAL//////////////////
};



class triangulo:public Figura
{
protected:
	float altura;
public:
	triangulo();
	~triangulo();
};


class equilatero:public triangulo
{
private:
	float lado;
public:
	equilatero();
	equilatero(int nuevolado):lado(nuevolado){};
	~equilatero();
	float getArea();
	float getPerimetro();
};


class isoseles:public triangulo
{
private:
	float base;
	float ladoIgual;
public:
	isoseles();
	~isoseles();
	float getArea();
	float getPerimetro();
};


class escaleno
{
private:
	float lado1;
	float lado2;
	float lado3;
public:
	escaleno();
	~escaleno();
	float getArea();
	float getPerimetro();
};