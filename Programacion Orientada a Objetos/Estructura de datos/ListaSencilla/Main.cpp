#include "ListaSencilla.h"
#include "Pila.h"

int main()
{
	ListaSencilla miLista;

	miLista.addFirst(5);
	miLista.addFirst(10);
	miLista.addLast(6);

	miLista.imprimir();

	cout << miLista.size() << endl;
	cout << miLista.contains(5) << endl;
	cout << miLista.contains(2) << endl;
	miLista.elmListaPos(1);
    miLista.imprimir();
    cout << endl ;

    cout << "///////////////////////////////////////////////////" << endl;

    Pila miPila;

    miPila.push(2);
}

