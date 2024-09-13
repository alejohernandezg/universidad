//
// Created by lufe0_000 on 3/13/2016.
//

#include "ArbolNArio.h"


NodoArbolN * ArbolNArio::  getRoot(){
    return root;
}
bool ArbolNArio::esVacio(NodoArbolN *pActual) {
    return pActual== nullptr;
}

bool ArbolNArio::esHoja(NodoArbolN *pActual) {
    return pActual!= nullptr and pActual->hijos== nullptr;
}
bool ArbolNArio::insertarNodo(string padre, string nuevoHijo, NodoArbolN * pActual) {
   //Se crea el nuevo nodo
    NodoArbolN * nuevoNodo= new NodoArbolN;
    nuevoNodo->nombre=nuevoHijo;
    nuevoNodo->hijos = new ListaDoble;

    if(esVacio(pActual)){
     //Si esta vacio se actualiza la raiz y se retorna true
        root=nuevoNodo;
    }else{

        if(pActual->nombre == padre){
            //Cuando se encuentra el padre, se inserta el nuevo nodo al final de la lista de hijos
            //Se retorna true
            pActual->hijos->addLast(nuevoNodo);


        }else {
            //Se comienza a buscar el valor de la cadena del padre en los hijos
        }    // Uno a uno de manera recursiva
    }
}

int ArbolNArio::calcularAltura( NodoArbolN * pActual) {
    if ( pActual== nullptr){
        return 0;
    }else{
        int maxAltura=0;

        ListaDoble *pListaHijos =pActual->hijos;
        int cantHijos = pListaHijos->getSize();
        int altura;
        //Se comienza a calcular la altura de los hijos
        for(int i=0; i <cantHijos; i++){




        }
        //Se retorna la altura máxima mas uno
    }
}

void ArbolNArio::mostrarPreorden(NodoArbolN *pActual) {

    if(!esVacio(pActual)){
        cout << "Nodo: "<< pActual->nombre<<endl;
        ListaDoble *pListaHijos =pActual->hijos;
        int cantHijos = pListaHijos->getSize();
        if(cantHijos>0){
            cout << "Sus hijos son"<<endl;
            for(int i=0; i <cantHijos; i++){
                mostrarPreorden(pListaHijos->getValueByIdx(i));
            }
        }
    }
}

