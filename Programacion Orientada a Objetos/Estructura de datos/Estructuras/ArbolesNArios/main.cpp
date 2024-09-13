#include <iostream>
#include "ArbolNArio.h"

    using namespace std;

    int main() {
        ArbolNArio arbol;

        cout << " Nueva raiz";
        arbol.insertarNodo("","0.Maria",arbol.getRoot());
        arbol.insertarNodo("0.Maria", "1.Juana",arbol.getRoot());
        arbol.insertarNodo("0.Maria", "1.Julieta",arbol.getRoot());
        arbol.insertarNodo("0.Maria", "1.Josefa",arbol.getRoot());
        arbol.insertarNodo("1.Juana", "2.Sara",arbol.getRoot());
        arbol.insertarNodo("1.Juana", "2.Sofia",arbol.getRoot());
        arbol.insertarNodo("1.Juana", "2.Salome",arbol.getRoot());
        arbol.insertarNodo("1.Josefa", "2.Paula",arbol.getRoot());
        arbol.insertarNodo("1.Josefa", "2.Paulina",arbol.getRoot());
        arbol.insertarNodo("2.Sofia", "3.Martina",arbol.getRoot());
        arbol.insertarNodo("3.Martina", "4.Lina",arbol.getRoot());
        cout << "Arbol en preorden";
        arbol.mostrarPreorden(arbol.getRoot());
        int altura= arbol.calcularAltura(arbol.getRoot());
        cout << altura;
    return 0;
}