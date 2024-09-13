#include <iostream>
#include "Taller3.h"

using namespace std;
void punto1()
{
    polinomio polinomioVacio;
    int numPolinomios;
    int opcion= 0;
    cout << "Cuantos polinomios desea multiplicar?" << endl;
    cin >> numPolinomios;

    polinomio misPolinomios[numPolinomios];
    // Este for es para llenar el arreglo de polinomios
    for (int j = 0; j <= numPolinomios ; ++j)
    {
        misPolinomios[j] = polinomioVacio;
    }


    for(int i=1;i<= numPolinomios;i++)
    {
        cout << "Polinomio " << i << endl;
        do{
            cout << "1.Agregar un factor" << endl;
            cout << "-1.No agregar mas" << endl;
            cin >> opcion;
            switch(opcion)
            {
                case 1:
                    int exponente,coeficiente=0;
                    cout << "Digite el coeficiente:" ;
                    cin>> coeficiente;
                    cout << "Digite el exponente:";
                    cin >> exponente;
                    misPolinomios[i].addFactor(coeficiente,exponente);
                    break;
            }
        }while(opcion !=-1);
    }
    for (int k = 1; k <=numPolinomios ; ++k)
    {
        misPolinomios[0]=misPolinomios[0].multiplicar(misPolinomios[k]);
        misPolinomios[0].printPolinomio();
    }
    misPolinomios[0].printPolinomio();
}

void punto2()
{
    int opcion = 0;
    int exponente;
    polinomio polinomio1;

    cout << "Cree su polinomio!" << endl;
    do {
        cout << "1.Agregar un factor" << endl;
        cout << "-1.No agregar mas" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                int exponente, coeficiente = 0;
                cout << "Digite el coeficiente:";
                cin >> coeficiente;
                cout << "Digite el exponente:";
                cin >> exponente;
                polinomio1.addFactor(coeficiente, exponente);
                break;
        }
    }while(opcion !=-1);
    do{
        cout << "Digite el exponente que desea eliminar(Mayor que 0):" << endl;
        cin >> exponente;
    }while(exponente<0);

    cout << "Primer polinomio:";
    polinomio1.printPolinomio();
    cout<< endl;

    if(!polinomio1.containsExp(exponente))
    {
        cout << "El exponente no esta en el polinomio" << endl;
    }else{
        polinomio1.eliminarByExp(exponente);
        cout << "Polinomio final: ";
        polinomio1.printPolinomio();
        cout << endl;
    }
}

int main()
{
    int opcion =0;
    do{
        cout << "1.Punto 1" << endl;
        cout << "2.Punto 2" << endl;
        cout << "-1.Salir" << endl;
        cout << "Opc:";
        cin >> opcion;
        switch(opcion){
            case 1:punto1();
            case 2:punto2();
        }
    }while(opcion !=-1);


}