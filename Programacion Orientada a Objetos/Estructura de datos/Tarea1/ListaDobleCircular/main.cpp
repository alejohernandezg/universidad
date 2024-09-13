#include <iostream>
#include "ListaDobleCircular.h"

using namespace std;

int main() {
    ListaDobleCircular miListaDobleCircular;
    miListaDobleCircular.addFirst(3);
    miListaDobleCircular.addFirst(1);
    miListaDobleCircular.addFirst(4);
    miListaDobleCircular.addlast(2);
    miListaDobleCircular.print();
    miListaDobleCircular.removeByFdx(1);
    cout << endl;
    miListaDobleCircular.print();
}