#include "Apuntadores.h"

int main(){

	int variableUno= 50;
	int variableDos= 11;
	float division=0.0;

	//Se incluye el & en la invocación de la función para obtener las direcciones de memoria
	dividir(&variableUno, &variableDos, &division);

	//Se prueba el resultado de la división
	cout << " El valor de la division es " << division << endl;
	cout << "La direccion de la variableUno es " << &variableUno << endl;

	//Incluir aqui el esto de las operaciones desarrolladas para probar que funcionan. 

	int valorn1=5;
	int *pvalorn1 = &valorn1;
	int valornSum1=3;
	int valornSum2=2;
	int resultado=0;
	
	elevarCuadrado(pvalorn1); 
	sumarNumeros(valornSum1,valornSum2,&resultado);
	sumarNumerosApuntadores(&valornSum1,&valornSum2,&resultado);
	intercambiar(&valornSum1,&valornSum2);
}