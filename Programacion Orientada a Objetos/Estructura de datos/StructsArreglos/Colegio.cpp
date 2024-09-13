#include "Colegio.h"

void llenarArreglo(curso_t arreglo[], int max){
	int contadorCurso = 1;
	int i;
	for(i = 0; i < max; i+=1){
		cout << "Digite el numero de estudiantes del curso " << contadorCurso << ":"<< endl;
		cin >> arreglo[i].numEstudiantes;
		cout << "Digite el numero de creditos del curso " << contadorCurso << ":"<< endl;
		cin >> arreglo[i].numCreditos;
		contadorCurso += 1;
	}
	
}

void imprimirArreglo(curso_t arreglo[], int max){
	int contador = 1;
	for(int i=0; i< max ; i++){
		cout << "el curso" << contador << endl;
		cout << "Numero de estudiantes:"<<arreglo[i].numEstudiantes << endl;
		cout << "Numero de creditos:"<<arreglo[i].numCreditos << endl;
		contador += 1;
	}
}