#include "Finanzas.h"
using namespace std;

void calculatingTotalSales(){
	float producto1 = 2.98;
	float producto2 = 4.50;
	float producto3 = 9.98;
	float producto4 = 4.49;
	float producto5 = 6.87;
	float total = 0;
	int recibir;

	while(recibir != -1){
		cout << "Ingrese el numero del producto:" << endl;
		cin >> recibir;
		if(recibir != -1){
			switch(recibir){
				case 1: cout << "ingreso el producto 1" << endl;
					total += producto1;
					break;
				case 2: cout << "ingreso el producto 2" << endl;
					total += producto2;						
					break;
				case 3: cout << "ingreso el producto 3" << endl;
					total += producto3;
					break;
				case 4: cout << "ingreso el producto 4" << endl;
					total += producto4;						
					break;
				case 5: cout << "ingreso el producto 5" << endl;
					total += producto5;
					break;
				default: cout << "No existe el producto" << endl;
					break;
			}
		}
	}
	cout << "Su total es:" << total << endl;
}

void salesCommissionCalculator(){
	int dinero, total;

	do{
		cout << "Enter sales in dollars(-1 to end):" << endl;
		cin >> dinero;
		if(dinero != -1){
			total = ((dinero*9)/100) + 200;
			cout << "Salary is:" << total << endl;
		}
	}while(dinero !=-1);
		
}