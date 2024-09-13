#ifndef listasdobles2
#define listasDobles2

#include "taller4.h"


int main()
{
	srand(time(NULL));
	int cantJ = 0;
	int empieza= 0;
	Cola fichasTotal;
	Stack sobrantes;
	listaDoble fichasEnJuego;
	fichasTotal = llenarColaDomino();
	cout << "cuantos van a jugar? (max 4)" << endl;
	cin >> cantJ;
	listaDoble jugadores[cantJ];
	for(int i=0; i < cantJ; i++ ){
		jugadores[i]= llenarFichasJugador(fichasTotal, jugadores[i]);
	}
	verFichasJugadores(jugadores, cantJ);
	sobrantes = llenarSobrantes(fichasTotal, sobrantes);
	empieza = empiezaJuego(jugadores, cantJ, fichasEnJuego);
	cout << "empieza jugador: " << empieza << endl;
	verFichasJugadores(jugadores, cantJ);



}

#endif
