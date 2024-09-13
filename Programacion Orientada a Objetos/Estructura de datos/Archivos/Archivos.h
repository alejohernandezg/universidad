//
// Created by lufe0_000 on 5/11/2016.
//

#ifndef ARCHIVOS_ARCHIVOS_H_H
#define ARCHIVOS_ARCHIVOS_H_H

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <fstream>


void writeFile();

/* Pruebe la logica de escribir en un archivo del cual reciba el nombre por consola. Pruebe los
 * diferentes tipos de entrada que puede soportar el archivo */
void writeFile2();
void readFile();
void readFullFile();

//Haga una funcion que lea los datos del archivo y los imprima dos veces. La primera vez llega hasta el final
// y luego la segunda vez vuelve al inicio y los imprime de nuevo
void readFullFileTwice();

/* Haga una menu que le pregunte al usuario que tipo de registros quiere ver, el debe seleccionar entre aquellos que tengan un balance inferior a cero,
 * un balance entre 1 y 1000 y un balance superior a 1000. Luego recorrar el archivo y muestre unicamente aquellos registros que en el campo balance
 * se ajusten a lo que escribió el usuario */
void showByBalance();

void writeUsingPut();

void readUsingGet();
#endif //ARCHIVOS_ARCHIVOS_H_H
