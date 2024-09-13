#include "ListaSencillaCircular.h"

int main()
{
    ListaSencillaCircular miLista;

    miLista.addLast(4);
    miLista.addLast(3);
    miLista.addFirst(5);
    miLista.imprimir();
    cout << endl;
    miLista.elmListaPos(2);
    miLista.imprimir();
    cout << endl;
    cout << miLista.contains(3);



}
