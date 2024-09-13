#include "tarea2.h"

int main()
{
    Cola<cliente_t> colaClientes;
    int numCajeros;
    cout << "Digite el numero de cajeros en servicio:" << endl;
    cin >> numCajeros;
    cliente_t arregloCajero[numCajeros];
    llenarCajero(arregloCajero,numCajeros);
    int opcion =0;
    do{
        cout << "------------MENU------------" << endl;
        cout << "1.Crear colaMP con N cajeros" << endl;
        cout << "2.Agregar una persona a la colaMP" << endl;
        cout << "3.Atender una transaccion por parte de todos los cajeros y actualizar la cola" << endl;
        cout << "4.Informar si la cola esta vacia" << endl;
        cout << "5.Informar el numero de cajeros del banco" << endl;
        cout << "6.informar el numero de transaccion de la persona que esta en el cajero N" << endl;
        cout << "-1.Salir:" << endl;
        cout << "1.Opc:" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:

                break;
            case 2:
                cliente_t nuevoCliente;
                cout << "Digite el numero de transacciones del nuevo cliente:";
                cin >> nuevoCliente.nTransacciones;
                colaClientes.pushCola(nuevoCliente);
                break;
            case 3:

                break;
            case 4:
                if(colaClientes.vaciaCola()){
                    cout << "La cola esta vacia" << endl;
                }else{
                    cout << "Hay alguien en la cola" << endl;
                }
                break;
            case 5:
                cout << "el numero de cajeros del banco es:" << numCajeros<< endl;
                break;
            case 6:
                int cajeroRevisar;
                cout << "Digite el numero del cajero que quiere revisas" << " (Maximo "<< numCajeros << ")"<< endl;
                cin >> cajeroRevisar;
                cajeroRevisar--;
                if(arregloCajero[cajeroRevisar].nTransacciones== 0)
                {
                    cout << "No hay nadie en el cajero"<< endl;
                }else{
                    cout << "La persona tiene " << arregloCajero[cajeroRevisar].nTransacciones << "transacciones" << endl;
                }
                break;
        }
    }while(opcion != -1);

}