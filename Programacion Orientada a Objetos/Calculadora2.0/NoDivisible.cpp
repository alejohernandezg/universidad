//
// Created by ALEJANDRO.
//

#include "NoDivisible.h"

NoDivisible::NoDivisible(string nuevo_mensaje) {
    mensaje = nuevo_mensaje;
    cout << mensaje << endl;
}

int NoDivisible::Manejador() {
    bool loop= true;
    int nuevo_segundo_factor;
    while(loop){
        cout << "Digite un numero diferente de 0 para que sea el divisor:";
        cin >> nuevo_segundo_factor;

        if (nuevo_segundo_factor != 0)
        {
            return nuevo_segundo_factor;
        }
    }
}