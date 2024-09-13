#include "taller4.h"

listaDoble llenarListaAleatorio(){
	listaDoble lst;
	int var1=0;
	int var2=0;
	int cont=0;
	while (cont < 28){
		var1 = rand()%7;
		var2 = rand()%7;
		if((lst.contains(var1, var2)== NULL) && (lst.contains(var2, var1)==NULL)){
			lst.anexarP(var1, var2);
			cont++;
		}
	}
	return lst;
}

Cola llenarColaDomino(){
	listaDoble lst;
	Cola C;
	lst = llenarListaAleatorio();
	int cont = 0;
	int a = 0;
	int b = 0;
	while(cont < 28){
		C.pushCola(lst.retornarUlt1(), lst.retornarUlt2());
		lst.removeUlt();
		cont++;
	}
	return C;
}

listaDoble llenarFichasJugador(Cola &C, listaDoble list){
	int i = 0;
	while(i < 6){
		list.anexarF(C.peekCola1(), C.peekCola2());
		C.popCola();
		i++;
	}
	return list;
}

Stack llenarSobrantes(Cola &C, Stack pila){
	while(!C.vaciaCola()){
		pila.push(C.peekCola1(), C.peekCola2());
		C.popCola();
	}
	return pila;
}

int empiezaJuego(listaDoble arreglo[], int tam, listaDoble &fichasEnJuego){
	for(int j=6; j>= 0; j--){
		for(int i =0 ; i<tam ; i++){
			if(arreglo[i].contains(j, j) != NULL){
				fichasEnJuego.anexarP(j,j);
				arreglo[i].removerValor(j, j);
				return i;
			}
		}
	}
	for(int j= 6; j>=0; j--){
		for(int i = j-1; i>=0; i--){
			for(int k=0; k<tam; k++){
				if(arreglo[k].contains(j, i) != NULL){
					fichasEnJuego.anexarP(j,i);
					arreglo[k].removerValor(j, i);
					return k;
				}
			}
		}
	}
}


void verFichasJugadores(listaDoble jugadores[], int tam){
	for(int i=0; i < tam; i++){
		cout << "jugador" << i << endl;
		jugadores[i].print();
	}
}