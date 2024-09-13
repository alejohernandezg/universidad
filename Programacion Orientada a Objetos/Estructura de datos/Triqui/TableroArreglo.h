//
// Created by ALEJANDRO on 3/08/2016.
//

#ifndef TRIQUI_TABLEROARREGLO_H
#define TRIQUI_TABLEROARREGLO_H

#endif //TRIQUI_TABLEROARREGLO_H
#include <stdio.h>

typedef struct{
    int celdas[9];
}tablero;



tablero crear();

int marcar(tablero, int,int);

int hayGanador(tablero);

int juegoCerrado(tablero);
void imprimirTablero(tablero);

int estaPuesto(tablero, int);

int esX(tablero, int pos);