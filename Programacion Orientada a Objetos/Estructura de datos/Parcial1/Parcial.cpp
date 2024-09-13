#include "Parcial.h"

void administradores(){
	float  salario=0;
	float ventas = 0, prestSociales = 0; // Valores que se piden
	do{

		cout << "Ingrese las ventas(Ingrese -1 para terminar):" << endl;
		cin >> ventas;
		if(ventas == -1){
			break;
		}
		cout << "Ingrese las prestaciones sociales:" << endl;
		cin >> prestSociales;
		salario = ((ventas)*(0.04))+((prestSociales)*(0.12));
		cout << "Su salario fue de:"<< salario << endl;
		
			
		}while(ventas != -1);	
}

void trabajadoresPorHora(){
	float  salario=0;
	float valorHora = 0, hora = 0; // Valores que se piden
	//Este dowhile aquí no es la mejor solucion
	do{

		cout << "Si es del area de ventas digite 1, si es de la fabrica digite 0(Ingrese -1 para terminar)" << endl;
		cin >> valorHora;
		if(valorHora == -1){
			break;
		}
		if(valorHora == 1){
			valorHora = 25000;
		}
		if(valorHora == 0){
			valorHora = 1500;
		}
		cout << "Ingrese cuantas horas trabajo:" << endl;
		cin >> hora;
		if(hora > 40){
			/*Ojo este calculo es incorrecto, no es valorHora/1.5,
			sino que es valorHora*1.5 */
			valorHora= valorHora + ((valorHora/(1.5))*(hora-40));
		}
		//Pq le sumas 1875, es para el subsidio de transporte ?
		salario = valorHora*(hora) + 1875;
		cout << "Su salario fue de:"<< salario << endl;
		
			
		}while(valorHora != -1);	
}

void trabajadoresPorItem(){
	/**/
}

