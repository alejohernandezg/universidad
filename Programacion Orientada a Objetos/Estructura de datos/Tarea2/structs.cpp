//
// Created by ALEJANDRO on 25/05/2016.
//

#include "structs.h"


cliente_t llenarDatosCliente()
{
    cliente_t nuevoCliente;
    cout << "Digite cuantas transacciones va a realizar:" << endl;
    cin >> nuevoCliente.nTransacciones;

    return nuevoCliente;
}

