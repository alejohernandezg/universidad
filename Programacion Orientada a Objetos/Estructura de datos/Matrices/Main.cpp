#include "Matrices.h"

void mostrarMenu() {
	int opcion = 0;
	
	int matriz[FILAS][COLUMNAS];
	int matrizListCompl[FILAS][COLUMNAS] = { { 1, 2, 10 }, { 3, 4, 98} };
	int matrizListInic[FILAS][COLUMNAS] = { { 1, 2 }, { 3, 4} };
	int matrizCero[FILAS][COLUMNAS] = { { 0 }, { 0} };
	int matrizCuadrada[][COLUMNAS] = { {1,2,1}, { 3, 4,2},{ 1, 2,6 }};
	do {
		cout <<" Opciones para matrices" << endl;
		cout <<"1. LLenar matriz" << endl;
		cout <<"2. Mostrar matriz" << endl;
		cout <<"3. Mostrar matriz al revez" << endl;
		cout <<"4. Es cuadrada?" << endl;
		cout <<"5. Mostrar diagonal" << endl;
		cout <<"6. Mostrar Transpuesta" << endl;
		cout <<"-1. Salir" << endl;
		cout <<" Opc: ";
		cin >> opcion;
		cout << endl;
		switch (opcion) {
			case 1:
				llenarMatriz(matriz,FILAS,COLUMNAS);
				break;
			case 2:
				mostrarMatriz(matrizCuadrada,FILAS,COLUMNAS);
				break;
			case 3:
				imprimirAlReves(matriz,FILAS,COLUMNAS);
				break;
			case 4:
				esCuadrada(FILAS,COLUMNAS);
				break;
			case 5:
				mostrarDiagonal(matriz,FILAS,COLUMNAS);
				break;
			case 6:
				transponerMatriz(matriz,FILAS,COLUMNAS);
				break;
		}
		//Cuando el usuario ingrese -1 se terminará el while y se terminará el menu
	} while(opcion!=-1);
}



int main()
{
	//Menu que muestra las opciones disponibles
	mostrarMenu();
}
