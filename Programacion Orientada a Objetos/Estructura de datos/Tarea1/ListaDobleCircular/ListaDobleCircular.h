//
// Created by ALEJANDRO on 14/03/2016.
//

#include <iostream>
#include <cstdlib>

using namespace std;

class ListaDobleCircular {
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

        ListaDobleCircular()
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

