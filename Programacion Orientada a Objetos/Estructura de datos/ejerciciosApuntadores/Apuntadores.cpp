#include "Apuntadores.h"

/* Operacion de ejemplo */
void dividir (int* pNum1, int* pNum2, float *pResultado){

	//Se hacen las operaciones con el contenido de los apuntadores pNum1, pNum2, pResultado
	// por eso se usa el *
	if( *pNum2 !=0){
		 *pResultado= *pNum1 / (float) * pNum2;

	}else{
		cout << " No se puede dividir por cero" <<endl;
	}

	//NOTE QUE NO HAY VALOR DE RETORNO PORQUE TODO SE LLEVO A CABO CON APUNTADORES
}

void elevarCuadrado(int * pValor){
	*pValor = (*pValor)*(*pValor);
	cout << "El primer numero elevado al cuadrado es:" << *pValor << endl;
}

void sumarNumeros(int num1, int num2, int * pResultado){
	*pResultado = num1 + num2;
	cout << "Sus numeros sumados son:" << *pResultado << endl;
}

void sumarNumerosApuntadores(int* pNum1, int* pNum2, int *pResultado){
	*pResultado = *pNum1 + *pNum2;
	cout << "Sus numeros sumados son:" << *pResultado << endl;
}

void intercambiar ( int *pValor1, int *pValor2){
	int varInter = 0;
	int *pVarInter = &varInter;
	*pVarInter = *pValor1;
	*pValor1 = *pValor2;
	*pValor2 = *pVarInter;
	cout << *pValor1 << endl;
	cout << *pValor2 << endl;
}