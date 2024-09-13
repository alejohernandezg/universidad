#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//Tamanios
const int FILAS=3, COLUMNAS=3;


//Ejemplos
//El tamaño de las columnas siempre se debe enviar como parámetro
void llenarMatriz(int matriz [][COLUMNAS] , int fil, int col); 
void mostrarMatriz(int matriz [][COLUMNAS] , int fil, int col); 
//Muestra la matriz iniciando con j en la posicion columnas-1 e i en la posicion fila -1
void imprimirAlReves(int matriz [][COLUMNAS] , int fil, int col);



//Imprime la matriz usando aritmetica de punteros
void mostrarMatrizAritmPunt(int matriz [][COLUMNAS] , int fil, int col); 

//Retorna true si la matriz es cuadrada y false si la matriz no es cuadrada
bool esCuadrada(int fil, int col); 

//Transponer matriz. 
//Si la matriz es cuadrada intercambia las filas con las columnas
// reutilizar la operacion es cuadrada antes de transponer
void transponerMatriz(int matriz [][COLUMNAS] , int fil, int col);

//Muestra la diagonal de una matriz, si la matriz es cuadrada. Reutilice
//la función esCuadrada
void mostrarDiagonal(int matriz [][COLUMNAS] , int fil, int col); 





