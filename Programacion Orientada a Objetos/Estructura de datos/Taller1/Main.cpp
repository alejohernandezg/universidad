#include "Taller1.h"

/* El estandar de codificacion en la mayoria de partes se sigue bien
 * aunque recuerda que las variables se deben nombrar con min�sculas y no con may�sculas
 *  En la parte del c�lculo del valor a pagar falta documentaci�n que expliques
 *  la raz�n de los c�lculos que hiciste
 *
 *  Hay algunos errores de l�gica en algunas funciones que estan comentados dentro del c�digo
 *
 *  Me parece buena la soluci�n que le diste al tema de manejar cuantos dias tienen los meses del a�o */

void menu()
{
	int opcion = 0;
	carro_t arregloParqueadero[SIZE]; //Este arreglo seria el parqueadero ya que contiene structs de tipo carro adentro de el
	llenarArreglo(arregloParqueadero);
	int AcumuladoGanancias =0;
	do {
		cout <<" Opciones para el parqueadero" << endl;
		cout <<"1. ingresarCarro" << endl;
		cout <<"2. retirarCarro" << endl;
		cout <<"3. Mostrar parqueadero" << endl;
		cout <<"4. Mostrar acumulado" << endl;
		cout <<"-1. Salir" << endl;
		cout <<" Opc: " << endl;
		cin >> opcion;
		switch (opcion) {
			case 1:
				ingresarCarro(arregloParqueadero);
				break;
			case 2:
				AcumuladoGanancias+=retirarCarro(arregloParqueadero);
				break;
			case 3:
				imprimirParqueadero(arregloParqueadero);
				break;
			case 4:
				cout << AcumuladoGanancias << endl;
				break;
		
		}
	
	} while(opcion!=-1);
}
int main()
{	
	menu();
}