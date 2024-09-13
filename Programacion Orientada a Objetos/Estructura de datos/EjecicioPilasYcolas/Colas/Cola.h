#include "ListaDoble.h"

class Cola
{
	ListaDoble * lst;
	public:
		Cola()
		{	
			lst = new ListaDoble();
		}
		int peek();
		void push();
		bool pop();
};
