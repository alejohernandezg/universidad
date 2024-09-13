#pragma once
#include <iostream>

using std :: cin;
using std :: cout;
using std :: endl;

typedef struct curso
{
	int numEstudiantes;
	int numCreditos;
}curso_t;

void llenarArreglo(curso_t arreglo[],int max);
void imprimirArreglo(curso_t arreglo[], int max);