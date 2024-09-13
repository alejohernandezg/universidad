#include "Parcial.h"


/* Alejandro desafortunadamente este parcial
te quedo bastante incompleto 
Revisa los comentarios que te hice sobre lo que
pusiste*/
int main()
{
	
	//Falta el ciclo para controlar la repetición indefinida
	int num;
	cout <<"ingrese el tipo de trabajor" << endl;
	cin >> num;

	switch(num){
		case 1: administradores();
				break;
		case 2: trabajadoresPorHora();
				break;
		case 3: trabajadoresPorItem();
				break;
		default: 
				break;
	
}
	
}