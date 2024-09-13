#include "PilasArreglos.h"

bool PilaConArreglos::esVacia()
{
	return idx == -1;
}

bool PilaConArreglos::esLlena()
{
	return idx == (tam-1);
}

bool PilaConArreglos::pop()
{
	if(!esVacia()){
		idx--;
		return true;
	}

	return false;	
}

int PilaConArreglos::peek()
{
	if(!esVacia()){
		return elements[idx];
	}
	return 0;
	
}

bool PilaConArreglos::push(int elem)
{
	if(!esLlena())
	{
		elements[++idx] = elem;
		return true;
	}
	return false;
}

void PilaConArreglos::printPila()
{
	int elem;
	while(!esVacia())
	{
		elem = peek();
		pop();
		cout << "Elemento:" << elem << endl;
	}
}