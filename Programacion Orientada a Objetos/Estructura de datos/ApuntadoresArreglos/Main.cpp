#include "Arreglos.h"

int main()
{

	int tamUno=15, tamDos=5, tamDiferencia=0;
	int arregloUno[tamUno], arregloDos[tamDos];
	int arregloDiferencia[tamUno];
	
	//Se llena el arregloUno
	llenarArregloAritmeticaPunteros(arregloUno, tamUno, 2);
	
	//Se imprime en pantalla el arregloUno
	cout << "Arreglo uno" << endl;
	imprimirArregloAritmeticaPunteros(arregloUno, tamUno);
	//Solo por ejemplo ver las direcciones de memoria del arregloUno
	recorrerArreglosxPosiciones(arregloUno, tamUno);
	
	//Se llena el arregloDos
	llenarArregloAritmeticaPunteros(arregloDos, tamDos, 5);


	//Se imprime en pantalla el arregloUno
	cout << "Arreglo dos" << endl;
	imprimirArregloAritmeticaPunteros(arregloDos, tamDos);
	
	// Se calcula la diferencia entre el arregloUno y el arregloDos
	calcularDiferenciaArreglos(arregloUno,arregloDos,arregloDiferencia, tamUno,tamDos, &tamDiferencia);

	//Se imprime cual es el tamaño del arreglo diferencia
	cout << "El tamanio del arreglo diferencia es " << tamDiferencia << endl;

	// Se imprime el arregloDiferencia. Note que se imprime hasta tamDiferencia que es el tamaño real del arregloDiferencia
	cout << "Arreglo diferencia" << endl;
	imprimirArregloAritmeticaPunteros(arregloDiferencia, tamDiferencia);

	//Completar con las otras operaciones. Reutilice la funcion imprimir para ver los resultados.
	// Puede llenar el arreglo con otros valores si le conviene para sus pruebas. Note que la
	// operacion llenarArreglo llena el arreglo con números consecutivos que inician en el valor
	// que se recibe como último parámetro

	//Hacer un menu con el llamado a los ejercicios aquí propuestos. 


}
