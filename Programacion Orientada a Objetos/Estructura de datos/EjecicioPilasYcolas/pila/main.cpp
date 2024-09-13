#include "Pilas.h"

bool sonIguales(PilaConArreglos *pilaUno,PilaConArreglos *pilaDos)
{
	while(!pilaUno->esVacia() && !pilaDos->esVacia())
	{
		if(pilaUno->peek() == pilaDos->peek())
		{
			pilaUno->pop();
			pilaDos->pop();
		}else
		{
			return false;
		}
	}
	if(pilaUno->esVacia() && pilaDos->esVacia())
		{
			return true;
		}
	return false;
}
int main()
{
	PilaConArreglos pilaUno;
	PilaConArreglos pilaDos;

	pilaUno.push(2);
	pilaUno.push(4);
	pilaUno.push(6);

	pilaDos.push(2);
	pilaDos.push(4);
	pilaDos.push(6);
	
	
	

	/*cout << "Pila 1" << endl;
	pilaUno.printPila();
	cout << "pila 2"<<endl;
	pilaDos.printPila();*/

	cout<< sonIguales(&pilaUno,&pilaDos) << endl;
}