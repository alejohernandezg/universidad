#include <iostream>
#include "ListaDobe.h"

using namespace std;

int main() {
    ListaDoble miListaDoble;

    miListaDoble.addFirst(5);
    miListaDoble.addlast(10);
    miListaDoble.addFirst(7);
    cout << endl;
    miListaDoble.print();
    miListaDoble.remove(7);
    cout << endl;
    miListaDoble.print();
}