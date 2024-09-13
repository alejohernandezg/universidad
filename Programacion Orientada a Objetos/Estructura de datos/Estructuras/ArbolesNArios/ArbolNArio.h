//
// Created by lufe0_000 on 4/11/2016.
//

#ifndef ARBOLESESTUDIANTES_ARBOLNARIO_H
#define ARBOLESESTUDIANTES_ARBOLNARIO_H

#include <cstdlib>
#include <iostream>
#include "ListaDoble.h"


using std::cout;
using std::string;

//Se resuelve lista doble
class ListaDoble;

struct NodoArbolN{
    string nombre; //Info que guardar lo que esta en la lista
    ListaDoble *  hijos; //Lista de hijos
};

class ArbolNArio {
private:
    NodoArbolN * root;
    int size;
public:

    ArbolNArio(){
       root= nullptr;
    }
    NodoArbolN * getRoot();

    bool esVacio(NodoArbolN *pActual);
    bool esHoja(NodoArbolN *pActual);
    int calcularAltura( NodoArbolN * pActual);
    void mostrarPreorden(NodoArbolN *pActual=NULL);
    void mostrarEnOrden(NodoArbolN *pActual);
    void mostrarPostOrden(NodoArbolN *pActual);
    int contarHojas(NodoArbolN *pActual);

    /* Calcula todos los descendientes de un nodo dado*/
    int contarDescendientes(NodoArbolN *pActual);

    /*Calculcula los hijos directos de uno nodo dado */
    int contarHijos(NodoArbolN *pActual);

    /*Cuenta cuantos nodos tiene el arbol dado*/
    int contarNodosArbol(NodoArbolN *pActual);

    /* Retorna el nodoArbolN_t dado una cadena de texto */
    NodoArbolN * buscarNodo(string nombreBuscar);

    /* Inserta un nuevo nodo en el valor dado la cadena que identifica al nodo padre */
    bool insertarNodo( string padre, string nuevoHijo, NodoArbolN * pActual);


};


#endif //ARBOLESESTUDIANTES_ARBOLNARIO_H

