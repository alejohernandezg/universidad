#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

typedef struct Nadador {
    string nombre;
    int edad;
    string tipoPrueba;
    int tiempoMin;
    int tiempoSeg;
}nadador_t;

//FUNCIONES DEL PUNTO1
void crearMatriz(int **matriz, int SIZE);
void imprimirMatriz(int **matriz,int SIZE);
int **crearMatriz(int SIZE);
void llenarMatriz(int **matriz, int SIZE);
void sacarRepetidos(int **matriz,int SIZE,int **matrizResultado);

//FUNCIONES DEL PUNTO2
void iniciarArreglo(nadador_t arreglo[],int SIZE);
void llenarArreglo(nadador_t arreglo[],int SIZE);
bool simetrico(nadador_t arreglo[],int SIZE);
void imprimirArreglo(nadador_t arreglo[],int SIZE);