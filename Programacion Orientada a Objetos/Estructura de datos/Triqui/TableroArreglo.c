//
// Created by ALEJANDRO on 3/08/2016.
//

#include "TableroArreglo.h"

tablero crear(){
    tablero miTablero;
    int i;
    for(i=0;i<9;i++)
    {
        miTablero.celdas[i] = 2;
    }
    return miTablero;
}

int marcar(tablero miTablero, int pos,int fichaJugador)
{
    if(!estaPuesto(miTablero,pos))
    {
        miTablero.celdas[fichaJugador];
        return 1;
    }else{
        return 0;
    }
}


void imprimirTablero(tablero miTablero)
{
    int i;
    for(i= 0; i < 9; ++i)
    {
        if(miTablero.celdas[i]%3==0)
        {
            printf(miTablero.celdas[i]);
        }else{
            printf("/n");
        }
    }
}

int estaPuesto(tablero miTablero,int pos)
{
    int i;
    for (i= 0; i < 9; ++i)
    {
        if(miTablero.celdas[pos]==2){
            return 1;
        }
    }
    return 0;
}

int esX(tablero miTablero, int pos)
{
    if(miTablero.celdas[pos])== 1){
        return 1;
    }
    return 0;
}

int hayGanador(tablero miTablero)
{
    
}

