#include <iostream>

using namespace std;

class noDivisible
{
private:
	string mensaje;
public:
	noDivisible(string nuevoMensaje){mensaje=nuevoMensaje;cout << mensaje << endl;};
	//~noDivisible();

	int manejador();
};

int noDivisible::manejador(){
	bool opcion= true;
	int nuevoNum2;
	while(opcion){
		cout << "Digite un numero diferente de 0 para que sea el divisor:";
		cin >> nuevoNum2;

		if (nuevoNum2 != 0)
		{
			opcion = false;
			return nuevoNum2;
		}
	}
};


class Calculadora
{
private:
	int num1;
	int num2;
public:
	Calculadora(int nuevoNum1,int nuevoNum2){
		num1=nuevoNum1;
		num2=nuevoNum2;
	};
	//~Calculadora();     PROFE SI DEJABA EL DESTRUCTOR ME SALIA ERROR

	int suma();
	int resta();
	int multiplicacion();
	int division();
	void setNum2(int nuevonum2);
};


int Calculadora::suma(){
	int resultado;
	resultado = num1 + num2;
	return resultado;
};

int Calculadora::resta(){
	int resultado;
	resultado = num1 - num2;
	return resultado;
};

int Calculadora::multiplicacion(){
	int resultado;
	resultado= num1 * num2;
	return resultado;
};

int Calculadora::division(){
	if (num2 == 0)
	{
		throw noDivisible("Math Error");
	}
	int resultado;
	resultado = num1/num2;
	return resultado;
};

void Calculadora::setNum2(int nuevoNum2){
	num2 = nuevoNum2;
};



// Menu de la calculadora
void calculo(Calculadora *miCalculadora){
	int opcion;
	do
	{
		cout << "-----------------------------------" << endl;
		cout << "Que opcion desea realizar" << endl;
		cout << "1. Suma" << endl;
		cout << "2. Resta" << endl;
		cout << "3. Multiplicacion" << endl;
		cout << "4. Division" << endl;
		cout << "5. Salir" << endl;
		cin >> opcion;

		switch(opcion){
			case 1:
				cout << "Resultado:";
				cout << miCalculadora->suma()<< endl;
				break;
			case 2:
				cout << "Resultado:";
				cout << miCalculadora->resta()<<endl;
				break;
			case 3:
				cout << "Resultado:";
				cout << miCalculadora->multiplicacion()<< endl;
				break;
			case 4:
				cout << "Resultado:";
				cout <<miCalculadora->division()<< endl;
				break;
			case 5:
				opcion =5;
				break;
			}
	}while (opcion!=5);
}