#include <iostream>
#include "ListaDoble.h"

using namespace std;

int main() {
    ListaDoble miListaDoble;

    miListaDoble.addFirst(5);
    miListaDoble.addlast(10);
    miListaDoble.addFirst(7);
    cout << endl;
    miListaDoble.print();
    cout<<endl;
    miListaDoble.removeByFdx(1);
    miListaDoble.print();
}