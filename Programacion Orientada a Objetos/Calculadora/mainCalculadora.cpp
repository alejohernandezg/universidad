#include "calculadora.h"


int main()
{
//		Pide los datos verificando que se digiten solo enteros
	int nuevoNum1,nuevoNum2;
	bool loop;
	loop = true;
	while (loop)
	{
		cout << "Digite el primer factor:" << endl;
		cin >> nuevoNum1;

	    if (cin.fail())
	    {
	        cin.clear();
	        cin.ignore();
	        cout << "Error! Digite un entero!" << endl;
	    }
	    else
	        loop = false;
	}
	loop = true;

	while (loop)
	{
		cout << "Digite el segundo factor:" << endl;
		cin >> nuevoNum2;

	    if (cin.fail())
	    {
	        cin.clear();
	        cin.ignore();
	        cout << "Error! Digite un entero!" << endl;
	    }
	    else
	        loop = false;
	}

//		Crea un puntero a Calculadora con los valores ingresados
	Calculadora *miCalculadora;
	miCalculadora = new Calculadora(nuevoNum1,nuevoNum2);

// 		Intenta realizar el calculo pero si el segundo factor es 0 arroja un error y lo soluciona
	try{calculo(miCalculadora);}
	catch(noDivisible error){
		int errorNum2;
		errorNum2 = error.manejador();
		miCalculadora->setNum2(errorNum2);
		cout << "Resultado:";
		cout <<miCalculadora->division()<< endl;
	}
};



