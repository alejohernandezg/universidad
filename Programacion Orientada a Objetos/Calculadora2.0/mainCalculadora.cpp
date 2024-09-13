//
// Created by ALEJANDRO.
//
#include "mainCalculadora.h"

int PedirNumero() {
    int nuevo_factor;
    bool loop;
    loop = true;
    while (loop) {
        cout << "Digite un entero:" << endl;
        cin >> nuevo_factor;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Error! Digite un entero!" << endl;
        }
        else {
            return nuevo_factor;
        }
    }
}

// Esta funcion crea un menu para que el usuario eliga que
// funcion utilizar a con la calculadora.
void calculo(Calculadora *miCalculadora){
    int opcion;
    do
    {
        cout << "-----------------------------------" << endl;
        cout << "Que opcion desea realizar" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Division" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;

        switch(opcion){
            case 1:
                cout << "Resultado:";
                cout << miCalculadora->Suma()<< endl;
                break;
            case 2:
                cout << "Resultado:";
                cout << miCalculadora->Resta()<<endl;
                break;
            case 3:
                cout << "Resultado:";
                cout << miCalculadora->Multiplicacion()<< endl;
                break;
            case 4:
                cout << "Resultado:";
                cout <<miCalculadora->Division()<< endl;
                break;
            case 5:
                opcion =5;
                break;
        }
    }while (opcion!=5);
}