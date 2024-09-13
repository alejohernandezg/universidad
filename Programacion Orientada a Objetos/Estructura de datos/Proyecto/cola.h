#pragma once
#include "listasDobles2.h"
class Cola{
private:
    listaDoble list;
public:
    bool vaciaCola();
    void pushCola(int elem1, int elem2);
    bool popCola();
    int peekCola1();
    int peekCola2();
    void printCola();
};