//
// Created by ALEJANDRO on 14/03/2016.
//

#ifndef LISTADOBLE_LISTADOBE_H
#define LISTADOBLE_LISTADOBE_H

#include <iostream>
#include <cstdlib>

using namespace std;

class ListaDoble {
    struct node
    {
        int value;
        node *pSgte;
        node *pAnt;
    };

    node *head;
    node *tail;

    bool isEmpty();
    public:

        ListaDoble()
        {
            head=NULL;
            tail=NULL;
        }

        int size();
        void addFirst(int value);
        void addlast(int value);
        bool remove(int value);
        bool removeByFdx(int pos);
        void print();
        bool contains(int value);

};


#endif //LISTADOBLE_LISTADOBE_H
