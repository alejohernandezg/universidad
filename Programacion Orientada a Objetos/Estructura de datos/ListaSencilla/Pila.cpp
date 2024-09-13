#include "Pila.h"

Pila::Pila()
{
	lst = *(new ListaSencilla());
}

void Pila::push(int value)
{
	lst.addLast(value);
	lst.imprimir();
}

void Pila::pop()
{
	lst.elmListaPos(lst.size());
}