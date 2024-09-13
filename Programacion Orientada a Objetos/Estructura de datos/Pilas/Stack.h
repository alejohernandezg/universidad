#include "ListaSencilla.h"

class Pila
{
    ListaSencilla lst;
public:
    Pila();
    void push(int elem);
    void pop();
    int peek();
    bool vaciaPila();
    void print();
};