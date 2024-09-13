#include <iostream>
#include <cstdlib>

using namespace std;

#pragma once

class ListaSencilla
{

    //Cabeza de la lista
    node * head = NULL;

public:
    int size();
    void addLast(int elem);
    void addFirst(int elem);
    bool removeElement(int elem);
    void imprimir();
    bool contains(int elem);
    void elmListaPos(int pos);
    int getLast();
    bool isEmpety();

    struct node
    {
        int value;
        struct node *pSgte;

        node() : value(0),pSgte(NULL){
        }
    };
};