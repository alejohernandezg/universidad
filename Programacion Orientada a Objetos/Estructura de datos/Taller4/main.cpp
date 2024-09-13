#ifndef listasdobles2
#define listasDobles2

#include "taller4.h"

int main(){
	srand(time(NULL));
	int cantJ = 0;
	int turnoPaga = 0;
	int turno= 0;
	int f1=0;
	int f2=0;
	int lado =0;
	int juegoCerrado = 0;
	bool turnoBool = true;
	Cola fichasTotal;
	Stack sobrantes;
	listaDoble fichasEnJuego;
	bool loop = false;
	cout << "cuantos van a jugar? (max 4)" << endl;
	cin >> cantJ;
	listaDoble *jugadores=  new listaDoble[cantJ];
	int dineroJugadores[cantJ];
	llenarColaDomino(fichasTotal);
	llenarDineroJugadores(dineroJugadores, cantJ);
	llenarFichasJugadores(fichasTotal, cantJ);
	verFichasJugadores(jugadores, cantJ);
	llenarSobrantes(fichasTotal, sobrantes);
	turno = empiezaJuego(jugadores, cantJ, fichasEnJuego);
	cout << "empieza jugador: " << turno << endl;
	verFichasJugadores(jugadores, cantJ);
	iniciarJuego(turno, turnoPaga, cantJ);
	while(!loop)
	{	
		cout<<"dinero jugadores"<< endl;
		imprimirArreglo(dineroJugadores, cantJ);
		turnoBool = true;
		cout << "fichas en juego: "<< endl;
		fichasEnJuego.print();
		cout << "jugador: " << turno << endl;
		if(fichaValida(jugadores[turno], fichasEnJuego))
		{
			turnoPaga=turno;
			while(turnoBool){
				jugadores[turno].print();
				cout<< "turno del jugador: " << turno << endl;
				cout<< "digite la ficha que desea jugar" << endl;
				cin >> f1;
				cin >> f2;
				cout<< "¿por que lado desea jugar? (1 derecha, 0 izquierda)" << endl;
				cin >> lado;
				if(jugarFicha(jugadores[turno], fichasEnJuego, f1, f2, lado)){
					turnoBool = false;
					cout<<"fichas actuales del jugador" << endl;
					jugadores[turno].print();
				}
				else
					cout<< "ficha no valida" << endl;
			}
		}
		else{
			if(tomarFichaPila(jugadores[turno], sobrantes)){
				dineroJugadores[turnoPaga]+=100;
				dineroJugadores[turno]-=100;
				cout<<"no tiene fichas para jugar, se toma una ficha de la pila"<< endl;
			}
			else
				cout<<"no tiene fichas para jugar, pila vacía, se continua sin comer"<< endl;
		}
		for(int i=0; i<= cantJ-1 ; i++){
			if(!fichaValida(jugadores[i], fichasEnJuego)){
				juegoCerrado++;
			}
		}
		loop = jugadores[turno].isEmpty();
		if(loop == false){
			if(turno == cantJ-1)
				turno = 0;
			else
				turno++;
		}
		if(juegoCerrado == cantJ){
			turno = ganadorJuegoCerrado(jugadores, cantJ);
			loop = true;
			for(i = 0; i < cantJ; i++){
				if(i!=turno){
					dineroJugadores[turno]+=100;
					dineroJugadores[i] -= 100;
				}
			}
		}
		juegoCerrado=0;
	}
	for(int i=0; i < cantJ; i++){
		if(i!=turno){
			dineroJugadores[turno]+= 500;
			dineroJugadores[i]-= 500;
		}
	}
	cout << "ganó el jugador: " << turno << endl;
	imprimirArreglo(dineroJugadores, cantJ);
	
}

#endif
