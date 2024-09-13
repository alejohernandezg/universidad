#include "ListaSencilla.h"

class Pila
{
	public:
		ListaSencilla lst;

		Pila();
		void push(int elem);
		void pop();
		int peek();
		bool vaciaPila(); 
};