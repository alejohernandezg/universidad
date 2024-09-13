#include "Arreglos.h"

int main()
{
	//Se define el arreglo de enteros que se pasará por parámetros
	int arregloEnteros[SIZE];

	//Ejm Arreglo con lista inicializadora
	int arregloInicializada[4]={-1,-2,-3,-4};

	//Se llama a la operación que llena el arreglo
	llenarArregloPares(arregloEnteros);

	//Se llama a la operación que imprime el arreglo
	imprimirArreglo(arregloEnteros);

	mostrarImpares(arregloEnteros);

	int valor;
	cout << "Digite su valor:"<< endl;
	cin >> valor; 

	int funcionTieneValor = tieneValor(arregloEnteros, valor);

	if(funcionTieneValor == 1){
		cout << "El valor esta" << endl;
	}
	else{
		cout << "No esta el valor" << endl;
	}

	imprimirDeMenos50a10(arregloEnteros);

	

}
