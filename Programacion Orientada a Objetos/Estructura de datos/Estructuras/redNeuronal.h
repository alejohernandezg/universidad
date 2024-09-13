#include "Grafo.h"
#include <math.h>
#include <iostream>
#include <cstdlib>
using namespace std;
class redNeuronal{
	Grafo<float>* red;
	int numEntradas;
	int numCapasOcultas;
	int numSalidas;
	float factorAprendizaje;
	float* valorEntrada;
	float* valorEsperados;
	float* valoresFinal;

public:
	float sigmoide(float x){
		//modificado
		return (1/(1 + exp(-x)));
	}
	void propagarError(){
		int iterador = 0;
		//defino el delta de la ultima capa
		for(int i =numEntradas+numCapasOcultas; i < red->size()-1; i++){
			red->setDeltaVertice(i,((valorEsperados[iterador] - valoresFinal[iterador])*valoresFinal[iterador]*(1-valoresFinal[iterador])));
			iterador++;
		}
		iterador = 0;
		//asigno los pesos de la ultima capa de pesos y asigno los deltas
		for(int i =numEntradas; i < numEntradas+numCapasOcultas; i++){
			for(int j = numEntradas+numCapasOcultas; j < red->size()-1; j++){
				if(j == numEntradas+numCapasOcultas){
					red->setDeltaVertice(i, red->costoArco(i,j)*red->getDeltaVertice(j));
				}
				else{
					red->setDeltaVertice(i, red->getDeltaVertice(i)+(red->costoArco(i,j)*red->getDeltaVertice(j)));
				}
				if(j >= red->size()-1){
					red->setDeltaVertice(i, (red->getDeltaVertice(i))*(red->infoVertice(i))*(1-red->infoVertice(i)));
				}
				red->setArco(i,j ,(red->costoArco(i,j)+ (factorAprendizaje)*(red->getDeltaVertice(j))*(red->infoVertice(i))));
			}
		}
		//asigno los pesos del neuron balanceo
		for(int i = numEntradas; i < red->size()-1; i++){
			red->setArco(red->size()-1, i,(red->costoArco(red->size()-1,i)+ (factorAprendizaje)*(red->getDeltaVertice(i))*(-1)));
		}
		//asigno pesos a la primera capa
		for(int i =0; i < numEntradas; i++){
			for(int j = numEntradas; j < numEntradas+numCapasOcultas; j++){
				red->setArco(i,j ,(red->costoArco(i,j)+ (factorAprendizaje)*(red->getDeltaVertice(j))*(red->infoVertice(i))));
			}
		}
	}
	redNeuronal(int numEntradasP, int numcapasOcultasP, int numSalidasP, float factorDeAprendizaje){
		red = new Grafo<float>;
		numEntradas = numEntradasP;
		numCapasOcultas = numcapasOcultasP;
		numSalidas = numSalidasP;
		//valorEntrada = valoresDeEntrada;
		//valorEsperados= valoresSalida;
		factorAprendizaje = factorDeAprendizaje;
		//valoresFinal = new float(numSalidas);
		// se conecta el grafo
		for(int i = 0; i < numEntradas + numCapasOcultas + numSalidas; i++){
			red->insVertice(0);
		}
		red->insVertice(-1);
		float var = rand() % 1;
		float var2 = rand() % 1;
		float var3 = rand() % 1;
		float var4 = rand() % 1;
		float var5 =rand() % 1;

		for(int i= 0; i < numEntradas ; i++){
			//red->setVertice(i,valoresDeEntrada[i]);
			red->setArco(red->size()-1,i, var);
			var+=0.1;
			for(int j = numEntradas; j < numEntradas+numCapasOcultas; j++){
				red->setArco(i,j,var);
				var+=0.1;
			}
		}
		for(int j = numEntradas; j < numEntradas+numCapasOcultas; j++){
				red->setArco(red->size()-1,j, var2);
				var2+=0.1;
				if(var2 >= 1){
					var2 = 0.1;
				}
				for(int k = numEntradas + numCapasOcultas; k < red->size()-1; k++){
				red->setArco(j,k,var2);
				var2+=0.1;
				if(var2 >=1){
					var2 = 0.1;
				}
			}
		}
		for(int i=numEntradas+numCapasOcultas; i< red->size()-1; i++){
			red->setArco(red->size()-1,i, var2);
		}
	}
	void propagarAdelante(float* valoresDeEntrada, float* valoresSalida){
		valorEntrada = valoresDeEntrada;
		valorEsperados= valoresSalida;
		valoresFinal = new float(numSalidas);
		float valorArco;
		float valorVertice1;
		float valorVertice2;
		int cont = 0;
		float cont2 = 0;
		//asigno entradas
		for(int i= 0; i < numEntradas ; i++){
			red->setVertice(i,valoresDeEntrada[i]);
		}
		//propago a la capa oculta
		for(int i = 0; i < numEntradas; i++){
			for(int j = numEntradas; j < numEntradas + numCapasOcultas; j++){
				valorVertice1 = red->infoVertice(i);
				valorVertice2 = red->infoVertice(j);
				valorArco = red-> costoArco(i, j);
				if(i == 0){
					red->setVertice(j, valorArco*valorVertice1);
				}
				else{
					red->setVertice(j, valorArco*valorVertice1 + valorVertice2);
				}
			}
		}
		cout << "aplicos sigmoide a primera capa oculta : " << endl;
		for(int i =numEntradas; i < numEntradas+numCapasOcultas; i++){
			cont2 = red->infoVertice(i);
			cout << "cont : " << cont2 << "costo arco: " << red->costoArco(red->size()-1,i) << "la sigmoide: " << sigmoide(cont2-(red->costoArco(red->size()-1,i))) << endl;
			red->setVertice(i, sigmoide(cont2-(red->costoArco(red->size()-1,i))));
		}
		for(int j = numEntradas; j < numEntradas + numCapasOcultas; j++){
			for(int i = numEntradas + numCapasOcultas; i < red->size()-1; i++){
				valorVertice1 = red->infoVertice(j);
				valorVertice2 = red->infoVertice(i);
				valorArco = red-> costoArco(j, i);
			    //cout << "costo vertice " << j << ": " << valorVertice1 << endl;
				//cout << "valor arco : " << valorArco << endl;
				if(j==numEntradas){
					red->setVertice(i, valorArco*valorVertice1);
					//cout << "valor que entra : " << valorArco*valorVertice1 << endl;
					//cout << "el vertice es" <<i << " :" << red->infoVertice(i) << endl;

				}
				else{
					red->setVertice(i, valorArco*valorVertice1 + valorVertice2);
					//cout << "valor que entra : " << valorArco*valorVertice1 +valorVertice2 << endl; 
					//cout << "el vertice es" << i<< " :" << red->infoVertice(i) << endl;

				}
			}
		}
		cout << "aplicos sigmoide a segunda capa oculta : " << endl;
		for(int i = numEntradas+numCapasOcultas; i < red->size()-1; i++){
			cont2 = red->infoVertice(i);
			cout << "cont : " << cont2 << "costo arco: " << red->costoArco(red->size()-1,i) << "la sigmoide: " << sigmoide(cont2-(red->costoArco(red->size()-1,i))) << endl;
			red->setVertice(i, sigmoide(cont2-(red->costoArco(red->size()-1,i))));
		}
		cont = 0;
		//cout << "guardo los valores finales" << endl;
		for(int i = numEntradas+numCapasOcultas; i < red->size()-1; i++){
			//cout << " el vertice " << i << " es :" << red->infoVertice(i) << endl;
			valoresFinal[cont] = red->infoVertice(i);
			cont++;
		}
	}
	void imprimirRed(){
	cout << "numero de entradas: " << numEntradas << endl;
	cout << "numero de vertices capa oculta1: " << numCapasOcultas << endl;
	cout << "numero de salidas: " << numSalidas << endl;
	cout << "valores entradas: ";
	for(int i = 0; i < numEntradas; i++){
		cout << valorEntrada[i] <<", ";
	}
	cout <<endl;
	cout << "valor esperado: ";
	for(int i=0; i<numSalidas; i++){
		cout << valorEsperados[i] <<", ";
	}
	cout << endl;
	cout << "valor calculado: " << endl;
	for(int i =0; i < numSalidas; i++){
		cout<< valoresFinal[i]<< endl;
		if(valoresFinal[i] > 0.5){
			cout << "aplicando sigma da: " << 1 << endl;
		}
		else{
			cout << "aplicando sigma da: "  << 0 << endl;
		}
	}
	cout <<endl;
	red->imprimirGrafo();
	}	

};