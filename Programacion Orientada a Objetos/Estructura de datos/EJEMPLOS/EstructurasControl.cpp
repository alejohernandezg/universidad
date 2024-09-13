#include <iostream>
#include <cmath>

//Usar cin y cout sin los prefijos
using namespace std;

/* calcular teorema pitágoras */
void calcularPitagoras(){
	float cat1 = 0;
	float cat2 = 0;
	float hip = 0;
	cout << "Digite la medida del cateto 1:" << endl;
	cin >> cat1;
	cout << "Digite la medida del cateto 2:" << endl;
	cin >> cat2;
	cat1 = pow(cat1,2);
	cat2 = pow(cat2,2);
	hip = sqrt(cat1+cat2);
	cout << "La hipotenusa es:" << hip << endl;

}

void calcularTransportexdia(){
	float Kmxdia = 0;
	float galonGas = 0;
	float promKmxGas = 0;
	float parqueadero = 0;
	float costoTotal = 0;
	cout << "Digite el total de kilometros conducidos por su dia:" << endl;
	cin >> Kmxdia;
	cout <<"Digite el costo por galon de gasolina:"<< endl;
	cin >> galonGas;
	cout <<"Digite el promedio de kilometros por galon:"<< endl;
	cin >> promKmxGas;
	cout <<"Digite los costos por parqueadero:"<< endl;
	cin >> parqueadero;
	costoTotal = ((Kmxdia/promKmxGas)*galonGas) + parqueadero;
	cout << "Su gasto en e dia fue:" << costoTotal;
}

void imprimirAsteriscosConWhile(int numAstericos){
	cout << numAstericos;
	while (numAstericos > 0){
		cout << "*";
		numAstericos -= 1;
	}
}
void imprimirAsteriscosConFor(int numAstericos){
	cout << numAstericos;
	for(numAstericos; numAstericos > 0; numAstericos -= 1){
		cout << "*";
	}

}

void calcularPromedioNotas(){
	float nota=0;
	float sumNotas = 0;
	int contador = 0;
	float promedio = 0;
	while (nota > -1){
		cout << "Digite su nota:" << endl;
		cin >> nota;
		if(0 <= nota <= 5 && nota != -1){
			sumNotas += nota;
			contador += 1;
		}	
	if(nota == -1){
			promedio = sumNotas/contador;
			cout << "Su promedio es:" << promedio << endl;
	}
	
	}
}

void creditLimit(){
	int accountNumber;
	float beginningBalance, totalCharges, totalCredits, limiteCreditos, newBalance;
	bool loop = true;
	cout << "Enter account number(or -1 to quit):" << endl;
	cin >> accountNumber;
	while(accountNumber !=-1){
		cout << "Enter beginning balance:" << endl;
		cin >> beginningBalance;
		cout << "Enter total charges:" << endl;
		cin >> totalCharges;
		cout << "Enter total credits:" << endl;
		cin >> totalCredits;
		cout << "Enter credit Limit:" << endl;
		cin >> limiteCreditos;
		newBalance = (beginningBalance + totalCharges - totalCredits);
		cout << "New balance is:" << newBalance << endl;
		cout << "Account:" << accountNumber << endl;
		cout << "Credit limit:" << limiteCreditos << endl;
		cout << "Balance:" << newBalance << endl;
		if(newBalance >= limiteCreditos)
			cout << "Credit Limit Exceeded";
			
		
		
	} 
}



int main() {
	//calcularPitagoras();
	//calcularTransportexdia();
	//imprimirAsteriscosConWhile(5);
	//imprimirAsteriscosConFor(5);
	calcularPromedioNotas();
	//creditLimit();
}

