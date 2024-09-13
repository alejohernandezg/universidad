//Para garantizar que solo se incluya una vez el codigo
#pragma once
#include <iostream>

//Instrucciones para facilitar cin y cout
using std::cin;
using std::cout;
using std::endl;

//Constante para el tamanio del arreglo
const int SIZE=10;

/*Imprime de la posición 0 hasta la última posición de un 
arreglo de valores enteros
que recibe por parámetro. */
void imprimirArreglo(int arreglo[]);

/*LLena de la posición 0 hasta la última posición de 
un arreglo con números pares. Ojo
es un ejemplo*/
void llenarArregloPares(int arreglo[]);



//Ejercicios

/*LLena de la posición 0 hasta la última posición de un arreglo de valores enteros 
que son pedidos por consola*/
void llenarArreglo(int arreglo[]);



/* Recibe por parámetros un arreglo y su tamaño y luego muestra los números que 
se encuentran en las POSICIONES impares*/
void mostrarImpares(int arreglo[]);



/* Busca el valor en el arreglo y si se encuentra retorna 1, 
de lo contrario retorna 0*/
int tieneValor(int arreglo[], int num);


//Adicione aquí los prototipos de las operaciones que le hagan falta

void imprimirDeMenos50a10(int arreglo[]);