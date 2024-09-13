
#include "Calculadora.h"
#include "mainCalculadora.h"



int main() {
   Calculadora *miCalculadora;
    int primer_factor;
    int segundo_factor;

    //Pide los valores verificando que sean un entero
    primer_factor = PedirNumero();
    segundo_factor = PedirNumero();

    //Crea una objeto Calculadora con los enteros digitados
    miCalculadora = new Calculadora(primer_factor,segundo_factor);

    try{calculo(miCalculadora);}
    catch(NoDivisible error){
        int errorNum2;
        errorNum2 = error.Manejador();
        miCalculadora->SetNum2(errorNum2);
        cout << "Resultado:";
        cout <<miCalculadora->Division()<< endl;
    }
}