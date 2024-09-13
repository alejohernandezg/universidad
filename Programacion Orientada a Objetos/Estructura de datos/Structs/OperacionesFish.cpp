#include "Structs.h"

fish_t llenarFish(){
	
	fish_t fish;
	cout << "ingrese un nombre para el pez"
	"max 24 caracteres\n"; 
	cin >> fish.nombre;
	cout <<"ingrese el numero de dientes \n";
	cin >> fish.numDientes;
	cout <<"ingrese la especie"
	"max 20 caracteres\n";
	cin >> fish.especie;
	cout << "ingrese la edad\n";
	cin >> fish.edad;
	cout << "ingrese el peso\n";
	cin >> fish.peso;


	return fish;
}


/* Se recibe la direccion de la estructura y no su valor para impresion*/
void imprimirFish(fish_t fish){
	cout << ".......\n......";
	cout << "Nombre pez:" << fish.nombre << endl;
	cout << "NumDientes:" << fish.numDientes << endl ;
	cout << "edad" << fish.edad << endl;
	cout << "especie" << fish.especie << endl;
	cout << "peso" << fish.peso << endl;
}