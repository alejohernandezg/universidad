#include "Matrices.h"

void llenarMatriz(int matriz [][COLUMNAS],  int fil, int col) {
	int i,j;
	for (i = 0; i < fil; i++) {
		for (j = 0; j < col; j++) {
			cout << "Ingrese un numero un numero "<<endl;
			cin >> matriz[i][j];
		}
	}
}

void mostrarMatriz(int matriz [][COLUMNAS],  int fil, int col) {
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			cout << matriz[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void mostrarMatrizAritmPunt(int matriz [][COLUMNAS],  int fil, int col) {
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			cout << (*(matriz+i)+j);
			cout << *(*(matriz+i)+j);
			cout << (*(*matriz+i)+j);	
		}
		cout << endl;
	}
	cout << endl;
}

void imprimirAlReves(int matriz [][COLUMNAS] , int fil, int col){
	for (int i = (fil-1); i >= 0; i--) {
		for (int j = (col-1); j >= 0; j--) {
			cout << matriz[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

bool esCuadrada(int fil, int col){
	if (fil == col){
		return true;
	}
	else{
		return false;
	}
}

void mostrarDiagonal(int matriz [][COLUMNAS] , int fil,int col){
	for (int i = 0; i < fil; i++){
		for (int j = 0; j < col; j++){
			if (i==j){
				cout << matriz[i][j] << endl;;
			}
		}
	}
}

void transponerMatriz(int matriz [][3] , int fil, int col)
{
	int temp =0;
	if(esCuadrada(fil,col))
	{
		for(int i = 0;i < fil;i++) {
            for (int j = 0; j < col; j++) {
                for (int j = i; j < col; j++) {
                    if (i != j) {
                        temp = matriz[i][j];
                        matriz[i][j] = matriz[j][i];
                        matriz[j][i] = temp;
                    }

                    cout << matriz[i][j] << ";";
                }
            }
        }
			cout << endl;
		}
	}else
		cout << "No es una matriz nxn o cuadrada" << endl;
}





/* Adicionar aquí el resto de funciones */