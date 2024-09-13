//
// Created by ALEJANDRO on 14/03/2016.
//

#ifndef LISTADOBLE_LISTADOBE_H
#define LISTADOBLE_LISTADOBE_H

#include <iostream>
#include <cstdlib>

using namespace std;

class polinomio {
    struct node
    {
        int coeficiente;
        int exponente;
        node *pSgte;
        node *pAnt;
    };

    node *head;
    node *tail;

    bool isEmpty();
public:
    polinomio()
    {
        head=NULL;
        tail=NULL;
    }

    bool isEmpety();

    void addFactor(int,int);
    int size();
    void printPolinomio();
    bool containsExp(int);
    polinomio multiplicar(polinomio);
    bool eliminarByExp(int);

};


#endif //LISTADOBLE_LISTADOBE_H
