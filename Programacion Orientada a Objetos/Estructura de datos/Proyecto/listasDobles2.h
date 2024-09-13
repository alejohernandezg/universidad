#ifndef listasdobles2
#define listasDobles2

#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class listaDoble{


public:
    struct nodo{
        int valor1;
        int valor2;
        nodo *pSgte;
        nodo *pAnt;
    };

    nodo *head;
    nodo *tail;

    listaDoble(){
        head=NULL;
        tail=NULL;
    }
    int size();
    int retornarUlt1();
    int retornarUlt2();
    int retornarFirst1();
    int retornarFirst2();
    void print();
    bool isEmpty();
    nodo* contains(int val1, int val2);
    void anexarP(int val1, int val2);
    void anexarF(int val1, int val2);
    bool removerValor(int val1, int val2);
    bool removeUlt();
    bool removeFirst();
};

#endif