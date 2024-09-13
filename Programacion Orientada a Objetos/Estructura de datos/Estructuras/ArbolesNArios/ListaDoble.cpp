//
// Created by lufe0_000 on 3/13/2016.
//

#include "ListaDoble.h"


void ListaDoble::addLast(NodoArbolN * arbol) {
    nodoLista * pNuevoNodo = new nodoLista;;
    pNuevoNodo->valor =arbol;
    if(isEmpty()){
        pCabeza=pNuevoNodo;
        pFin=pNuevoNodo;
        pNuevoNodo->pAnterior=NULL;
    }else{
        pFin->pSgte=pNuevoNodo;
        pNuevoNodo->pAnterior=pFin;
    }
    pNuevoNodo->pSgte=NULL;
    pFin=pNuevoNodo;
    size++;
}


bool ListaDoble::isEmpty() {
    if (pCabeza==NULL || pFin==NULL){
        return true;
    }
    return false;
}

void ListaDoble::removeFirst() {
    nodoLista * temp=pCabeza;
    if(!isEmpty()){
        pCabeza= temp->pSgte;
        pCabeza->pAnterior=NULL;
        size--;
        delete(temp);
    }

}

NodoArbolN * ListaDoble::getValueByIdx(int idx) {
    nodoLista * pTemp=pCabeza;
   //Completar este método
}

int ListaDoble::getSize() {
    return size;
}
