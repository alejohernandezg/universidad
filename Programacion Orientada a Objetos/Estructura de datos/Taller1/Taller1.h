#pragma once
#include <iostream>
#include <string>
using namespace std;

/* Buen trabajo por definir las constantes con mayusculas sostenida */
//El cobro que tiene el parqueadero por hora
const int COBRO=1800;

//Numero de parqueaderos disponibles
const int SIZE = 40;

//Esto son los dias de los meses en su orden
const int arregloMeses[12]={31,28,31,30,31,30,31,31,30,31,30,31};

typedef struct Carro
{
	string placa;
	int horain;
	int mesin;
	int diain;
}carro_t;

void llenarArreglo(carro_t arreglo[]);
void ingresarCarro(carro_t arreglo[]);
void imprimirParqueadero(carro_t arreglo[]);
int retirarCarro(carro_t arreglo[]);
