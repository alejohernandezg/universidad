/* Esto se incluye para evitar inclusion repetida de informacion*/
#ifndef STRUCTS_H_
#define STRUCTS_H_

#include <iostream>


using std::cout;
using std::cin;
using std::endl;


typedef struct Fish {
	char nombre[25];
	char especie[20];
	int numDientes;
	int edad;
	float peso;
}fish_t;


fish_t llenarFish();
void imprimirFish(fish_t fish);


#endif