//
// Created by ALEJANDRO on 18/05/2016.
//

#ifndef NUEVA_CARPETA_LISTASENCILLACIRCULAR_H
#define NUEVA_CARPETA_LISTASENCILLACIRCULAR_H


#include <iostream>
#include <cstdlib>

using namespace std;

#pragma once

class ListaSencillaCircular
{
    struct node
    {
        int value;
        node *pSgte;
    };

    node * head;
    node * tail;

public:
    ListaSencillaCircular()
    {
        head=NULL;
        tail=NULL;
    }

    bool isEmpty();
    int size();
    void addLast(int elem);
    void addFirst(int elem);
    bool removeElement(int elem);
    void imprimir();
    bool contains(int elem);
    void elmListaPos(int pos);
};


#endif //NUEVA_CARPETA_LISTASENCILLACIRCULAR_H
