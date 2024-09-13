#include "ListaSencilla.h"

int main()
{
	ListaSencilla miLista;

	miLista.addFirst(5);
	miLista.addFirst(10);
	miLista.addLast(6);

	miLista.imprimir();
	cout << endl;
	miLista.elmListaPos(3);
    miLista.imprimir();
    cout << endl ;
}

