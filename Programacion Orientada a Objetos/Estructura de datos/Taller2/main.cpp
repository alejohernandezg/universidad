#include <iostream>
#include "Taller2.h"


void verMenuPunto1()
{
    int opcion=0;
    int **matriz;
    int **matrizResultado;
    do{
        cout << "Opciones:" << endl;
        cout << "1.Crear Matriz." << endl;
        cout << "2.Ver repetidos" << endl;
        cout << "3.Imprimir ambas Matrices" << endl;
        cout << "-1.Salir." << endl;
        cout << "Opc:";
        cin >> opcion;
        switch(opcion){
            case 1:
                int SIZE;
                cout << "Ingrese el tamaño de la Matriz nxn:" << endl;
                cin >> SIZE;
                matriz = crearMatriz(SIZE);
                matrizResultado=crearMatriz(SIZE);
                llenarMatriz(matriz,SIZE);
                break;
            case 2:
                sacarRepetidos(matriz,SIZE,matrizResultado);
                break;
            case 3:
                imprimirMatriz(matriz,SIZE);
                imprimirMatriz(matrizResultado,SIZE);
                break;
        }
    }while(opcion!=-1);
}

void verMenuPunto2()
{
    int opcion=0;
    int SIZE=0;
    cout << "Digite el numero de participantes:" << endl;
    cin >> SIZE;
    nadador_t *arreglo = new nadador_t[SIZE];
    iniciarArreglo(arreglo,SIZE);
    llenarArreglo(arreglo,SIZE);
    cout << "///////////" << endl;
    imprimirArreglo(arreglo,SIZE);
    cout << "///////////" << endl;
    if(simetrico(arreglo,SIZE))
    {
        cout << "Es simetrico." << endl;
    }else
    {
        cout << "No es simetrico." << endl;
    }

    delete(arreglo);

}

void verMenuPrincipal()
{
    int opcion=0;
    do{
        cout << "Opciones:" << endl;
        cout << "1.Primer punto." << endl;
        cout << "2.Segundo punto." << endl;
        cout << "-1.Salir." << endl;
        cout << "Opc:";
        cin >> opcion;
        switch(opcion){
            case 1: verMenuPunto1();
                break;
            case 2: verMenuPunto2();
                break;
        }
    }while(opcion!=-1);
}


int main() {
    verMenuPrincipal();
}