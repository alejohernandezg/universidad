#pragma once
#include "listasDobles2.h"

class Stack{
private:
	listaDoble list;
public:
	void push(int elem1, int elem2);
	bool pop();
	int peek1();
	int peek2();
	void printStack();
};