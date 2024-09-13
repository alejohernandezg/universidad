#include "Arreglos.h"
/*Imprime de la posición 0 hasta la última posición de 
un arreglo de valores enteros
que recibe por parámetro. */
void imprimirArreglo(int arreglo[]){
	for(int i=0; i< SIZE; i++){
		cout << "valor " << arreglo[i]<<endl;
	}
}




/*LLena de la posición 0 hasta la última posición de un 
arreglo con números pares. Es un ejemplo*/
void llenarArregloPares(int arreglo[]){
	int numPar=0;
	for(int i=0; i< SIZE; i++,numPar+=2){
		arreglo[i]=numPar;
	}
}


void mostrarImpares(int arreglo[]){
	int numImpar = 1;
	for(int i = 1; i < SIZE; i+=2){
		
		cout << "valor " << arreglo[i]<<endl;
	}
}

int tieneValor(int arreglo[], int num){
	for(int i = 0; i < SIZE; i++){
		if(arreglo[i]==num){
			return 1;
		}
	}
}

void imprimirDeMenos50a10(int arreglo[]){
	for(int i = -50; i <= 10; i++){
		cout << arreglo[i] << endl;
	}

}