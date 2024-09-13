#include "Arreglos.h"


/* EJEMPLOS */
void imprimirArregloAritmeticaPunteros(int arreglo[], int tam){
	for (int i = 0; i < tam; ++i){
		cout << "valor de " << i <<" es : "<< *(arreglo+i) <<endl;
	}

}

void llenarArregloAritmeticaPunteros(int arreglo[], int tam, int semilla){
	for (int i = 0; i < tam; ++i){
		//Llena el arreglos con números consecutivos 
		// más el valor recibido en semilla.
		*(arreglo + i) = i+semilla;
	}
}

void recorrerArreglosxPosiciones(int arreglo[], int tam){
	for (int i = 0; i < tam; ++i){
		cout << "valor de " << i <<" es : "<< 
			arreglo[i] << " dir: " << &arreglo[i] <<endl;
	}
}

/* Recibe por parámetros dos arreglos y sus tamaños y calcula la diferencia
del arreglo del primer parametro con el arreglo del segundo parametro.
Usa aritmética de punteros. El tercer arreglo de parametros corresponde al arreglo en el que
se guardará la diferencia y el tamanio real del arreglo diferencia se puede obtener
del parametro tamDiferencia que es un apuntador al tamaño con el que queda el arreglo diferencia */
void calcularDiferenciaArreglos(int arregloUno[], int arregloDos[], 
		int arregloDiferencia[], int tam1, int tam2, int * tamDiferencia){

	bool estaValor= false; 
	int i, j;

	for( i=0; i < tam1; i++){
		estaValor=false;
		for(j=0;j<tam2 && estaValor==false;j++){
			//Cuando ambos valores son iguales se cambia la variable bandera de estado. 
			//Se usa aritmetica de punteros 
			// Equivalente a arregloUno[i] == arregloDos[j]
			if(*(arregloUno+i) == *(arregloDos+j)){
				//Se cambia la bandera para interrumpir el ciclo
				estaValor=true;
			}
		}
		if(estaValor == false){
			// Usando aritmética de punteros se asigna a al arreglo resultado el valor de arregloUno en la posicion i
			// Se usa el * en tamDiferencia porque tamDiferencia es un apuntador y aquí se necesita el contenido de esa dirección que es donde
			// se va guardando la posición

			// Equivalente a arregloDiferencia[*tamDiferencia] == arregloUno[i]
			*(arregloDiferencia + (*tamDiferencia)) = *(arregloUno+i);
			(*tamDiferencia)++;
		}
	}
}

void calcularInterseccionArreglos(int arregloUno[], int arregloDos[], int arregloInterseccion [], int tam1, int tam2, int * tamIntersec){
	int i, j; 
	for(i=0; i<tam1; i++){
		for(j=0; j<tam2; j++){
			if(arregloUno[i] == arregloDos[j] && !verRepetidos(arregloUno[i],arregloInterseccion,tamIntersec)){
				arregloInterseccion[*tamIntersec] = arregloUno[i];
				(*tamIntersec)++;
			}
		}
	}
}

bool verRepetidos(int elemento, int arregloUno[], int tam1){
	int i;
	for(i=0; i < tam1; i++){
		if(elemento == arregloUno[i]){
			return true;
		}
	}
}

