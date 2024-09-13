#include "Taller1.h"



//Esta funcion llena un arreglo de tipo carro para simular un parqueadero
void llenarArreglo(carro_t arreglo[]){
	for(int i=0; i< SIZE; i++){
		arreglo[i].placa= "Vacio";
		arreglo[i].horain= 0;
		arreglo[i].mesin =0;
		arreglo[i].diain =0;
	}
}


/* En esta funcion hay varias cosas de logica a corregir
 * 1) Si los datos no cumple el if de la validacion  deberias
 * preguntarle nuevamente el valor al usuario hasta que meta el valor
 * correcto, en lugar de terminar directamente el ciclo
 * 2) No consideras el caso en el que todo el arreglo este lleno y no hallan espacios
 * vacios*/
void ingresarCarro(carro_t arreglo[])
{
	for(int i=0; i<SIZE; i++)
	{
		if(arreglo[i].placa=="Vacio")
		{
			cout << "Digite la placa del carro:" << endl;
			cin >> arreglo[i].placa;
			cout << "Digite la hora de ingreso(Reloj 24-Horas):" << endl;
			cin >> arreglo[i].horain;
			if(arreglo[i].horain< 1 || arreglo[i].horain>24)
			{
				cout << "Hora no valida" << endl;
				break;
			}
			cout << "Digite el mes(El numero):" << endl;
			cin >> arreglo[i].mesin;
			if(arreglo[i].mesin < 1 || arreglo[i].mesin>12)
			{
				cout << "Mes no valido" << endl;
				break;
			}
			cout << "Digite el dia:" << endl;
			cin >> arreglo[i].diain;
			if(arreglo[i].diain>24)
			{
				cout << "Dia no valido" << endl;
				break;
			}
			break;
		}
	}
}
/*En esta funcion se pide el dia, la hora y el mes en el que es carro
sale del parqueadero y con esta informacion realiza otra operacion so-
-bre el arregloMeses y a partir de esto optiene los dias, premitiendo-
-nos calcular los hora en total que debe pagar*/

/* Aqui también la forma de la validacion de los datos
 * se podría mejorar para que pregunte una vez más hasta que se resuelva
 *
 * No usas la constante*/
int retirarCarro(carro_t arreglo[])
{	
	string placaRetirada;
	int horaReti=0;
	int mesReti= 0;
	int diaReti =0;
	int contadorDias=0;
	int totalAPagar =0;

	cout << "Digite la placa que desea retirar:" << endl;
	cin >> placaRetirada;
	for(int i = 0; i < SIZE; i++)
	{
		//  OJO, NO DEBERIAN SER IF SINO ELSEIF LA MAYORIA DE LOS CASOS


		if(arreglo[i].placa == placaRetirada)
		{
			cout << "ingrese la hora en la que se retira(Reloj 24-Horas):" << endl;
			cin >> horaReti;
			if(horaReti< 1 || horaReti>24)
			{
				cout << "Hora no valida" << endl;
				break;
			}
			cout << "ingrese el mes en el que se retira(El numero):" << endl;
			cin >> mesReti;
			if(mesReti < 1 || mesReti>12)
			{
				cout << "Mes no valido" << endl;
				break;
			}
			cout << "ingrese el dia en el que se retira:" << endl;
			cin >> diaReti;
			if(diaReti>24)
			{
				cout << "Dia no valido" << endl;
				break;
			}
			if(arreglo[i].mesin == mesReti && arreglo[i].diain == diaReti)
			{
				//OJO NO ESTAS USANDO LA CONSTANTE!!!!!!!!!!!
				totalAPagar = (horaReti-arreglo[i].horain)*1800;
				cout << "TRUE" << endl;
			}
			if(arreglo[i].mesin == mesReti && arreglo[i].diain != diaReti)
			{
				contadorDias = (arregloMeses[(arreglo[i].mesin)-1]-arreglo[i].diain)-(arregloMeses[(arreglo[i].mesin)-1]-diaReti);
				//Hace falta comentarios que explique pq le restas 48 al calculo
				// y que explique pq se estan haciendo los cálculos.

				totalAPagar = (contadorDias*24)-48;
				totalAPagar += ((24-arreglo[i].horain)+horaReti)*1800;

				//Esto no deberia estar aqui
				cout << "TRUE1" << endl;
			}

			if(arreglo[i].mesin != mesReti)
			{
				contadorDias = ((arregloMeses[(arreglo[i].mesin)-1])-arreglo[i].diain)+diaReti;
				for(int j=((arreglo[i].mesin)) ;j<12;j++)
					{
						contadorDias += arregloMeses[j];
						if(arregloMeses[j] == arregloMeses[mesReti-2])
							break;
					}
				totalAPagar = (contadorDias*24)-48;
				totalAPagar += ((24-arreglo[i].horain)+horaReti)*1800;
				cout << "TRUE2" << endl;
			}

			
			cout << "Usted debe:" << totalAPagar<<endl;

			// Esto ultimo lo podrias sacar a una funcion aparte
			// para simplifica el código
			arreglo[i].placa = "Vacio";
			arreglo[i].horain =0;
			arreglo[i].mesin =0;
			arreglo[i].diain =0;
			return totalAPagar;	
		}
	}
}

void imprimirParqueadero(carro_t arreglo[])
{
	for(int i=0;i<SIZE;i++)
	{
		cout << arreglo[i].placa << ";" ;
		cout << arreglo[i].horain << ";";
		cout << arreglo[i].mesin << ";" ;
		cout << arreglo[i].diain << ";";
		cout << endl;
	}
}
