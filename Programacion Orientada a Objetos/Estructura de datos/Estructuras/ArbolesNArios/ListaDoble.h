//
// Created by lufe0_000 on 3/13/2016.
//

#ifndef LISTASDOBLES_LISTADOBLE_H
#define LISTASDOBLES_LISTADOBLE_H

#include <iostream>
#include <cstdlib>
#include "ArbolNArio.h"
#include <string.h>

using std::endl;
using std::cout;
using std::string;

// Se da una referencia a la clase Nodo para solucionar referencia circular
class ArbolNArio;

class ListaDoble {

private:
    struct nodoLista{
        NodoArbolN * valor;
        nodoLista * pSgte;
        nodoLista * pAnterior;
    };

    nodoLista * pCabeza;
    nodoLista * pFin;
    int size;

public:
    ListaDoble(){
        pCabeza=NULL;
        pFin=NULL;
        size=0;
    }

    int getSize();
    void addLast(NodoArbolN * arbol);
    NodoArbolN  * getValueByIdx(int idx);
    void removeFirst();

    bool isEmpty();


};


#endif //LISTASDOBLES_LISTADOBLE_H
