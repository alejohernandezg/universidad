#include "Stack.h"

Pila::Pila()
{
    lst = *(new ListaSencilla());
}

void Pila::push(int value)
{
    lst.addLast(value);
}

void Pila::pop()
{
    lst.elmListaPos(lst.size());
}

int Pila::peek() {
    return lst.getElement();
}


void Pila::print()
{
    int val;
    while(!lst.isEmpety())
    {
        val = peek();
        cout << val;
        pop();
    }
}
