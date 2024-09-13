//ALEJANDRO HERNANDEZ
//CARLOS PALOMEQUE



#include "Figuras.h"

// CLASE FIGURA-------------------------------------------------
void Figura::getPos(){
	cout << "(" << posX << " , " << posY<< ")";
};

float Figura::getGrosor(){return grosorLinea;};

string Figura::getColor(){return color;};



float circulo::getRadio(){return radio;};

void circulo::changeRadio(float nuevoValor){
	radio = nuevoValor;
};

// CLASE CIRCULO-------------------------------------------------
float circulo::getArea(){
	float area;
	area = pi*(radio*radio);
	return area;
};

float circulo::getPerimetro(){
	float perimetro;
	perimetro = 2*pi*radio;
	return perimetro;	
};


// CLASE CUADRADO-------------------------------------------------
float cuadrado::getLado(){
	return lado;
};

void cuadrado::changeLado(float nuevoValor){
	lado = nuevoValor;
};

float cuadrado::getArea()
{
	float area;
	area = lado*lado;
	return area;
};

float cuadrado::getPerimetro(){
	float perimetro;
	perimetro = 4*lado;
	return perimetro;	
};

// CLASE EQUILATERO-------------------------------------------------

float equilatero::getArea()
{
	float area;
	altura = ((sqrt(3))*lado)/2;
	area = (lado*altura)/2 ; 
	return area;
};

float equilatero::getPerimetro(){
	return (lado*3);
};

// CLASE ISOSELES-------------------------------------------------

float isoseles::getArea()
{
	float area;
	altura = (sqrt((ladoIgual*ladoIgual)-((base*base)/4)));
	area = (base*altura)/2 ; 
	return area;
};

float isoseles::getPerimetro(){
	return ((ladoIgual*2)+base);
};

// CLASE ESCALENO-------------------------------------------------

float escaleno::getPerimetro()
{
	return lado1+lado2+lado3;
};

float escaleno::getArea()
{
	float s;
	float area;
	s= getPerimetro();
	s = s/2;

	area=sqrt(s*(s-lado1)*(s-lado2)*(s-lado3));
	return area;
};