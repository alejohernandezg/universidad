#include <iostream>

//Garantizar que solo se incluya una vez el .h
#pragma once

using std::cin;
using std::cout;
using std::endl;

/* EJEMPLOS */

/*Imprime de la posición 0 hasta la última posición de un arreglo de valores enteros. */
void imprimirArregloAritmeticaPunteros(int arreglo[], int tam);

/* Recibe por parámetros dos arreglos y sus tamaños y calcula la diferencia
del arreglo del primer parametro con el arreglo del segundo parametro.
Usa aritmética de punteros. El tercer arreglo de parametros corresponde al arreglo en el que
se guardará la diferencia y el tamanio real del arreglo diferencia se puede obtener
del parametro tamDiferencia que es un apuntador al tamaño con el que queda el arreglo diferencia */
void calcularDiferenciaArreglos(int arregloUno[], int arregloDos[], int arregloDiferencia[] , int tam1, int tam2, int* tamDiferencia);

/*LLena de la posición 0 hasta la última posición de un arreglo de valores enteros 
que son pedidos por consola*/
void llenarArregloAritmeticaPunteros(int arreglo[], int tam, int semilla);

/* Imprime los elementos de un arreglo y sus direcciones de memoria */
void recorrerArreglosxPosiciones(int arreglo[], int tam);

/* EJERCICIOS */

/* Recibe por parámetros dos arreglos y sus tamaños y calcula la intersección
de ambos arreglos.
Usa aritmética de punteros. El tercer arreglo de parametros corresponde al arreglo en el que
se guardará la intersección y el tamanio real de la intersección se puede obtener
del parametro tamIntersec que es un apuntador al tamaño real con el que queda el arreglo intersección
al terminar la operación. */
void calcularInterseccionArreglos(int arregloUno[], int arregloDos[], int arregloInterseccion [], int tam1, int tam2, int * tamIntersec);



/* Recibe por parámetros dos arreglos y sus tamaños y calcula la unión
de ambos arreglos. La unión de dos arreglos es igual a un arreglo que tiene los elementos del primer arreglo y los elementos
del segundo arreglo sin repetidos. 
Usa aritmética de punteros. 
Note que tamUnion debe ser un apuntador al tamaño con el que queda el arreglo unión al terminar
la operación. */

void calcularUnion(int arregloUno[], int arregloDos[], int arregloUnion[], int tam1, int tam2, int* tamUnion);


