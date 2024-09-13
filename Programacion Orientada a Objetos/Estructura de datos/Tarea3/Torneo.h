#include <iostream>
#include <cstdlib>

using namespace std;

/*
INVARIANTES:

-El numero de jugadores debe de ser par y mayores que 1.
-Los sets de cada jugador deben ser mayores o iguales que 0 y menores o iguales que 6.

*/

struct jugador{
    int numJugador;
    int setsGanados
    equipo * pHijoIzq;
    equipo * pHijoDer;
};

class ArbolBinario {
	jugador crearArbol(int numJugadores);
	/* Esta funcion crea un arbol segun el numero de 
	equipos que tenga. Ej: Si hay 4 equipos crea un
	 arbol de 3 niveles*/

	void llenarRaices();
	/*Esta funcion llena de manera aleatoria las raices
	del arbol con los numeros de los equipos de manera aleatoria*/

	jugador elegirGanador(jugador * pHijoIzq,jugador * pHijoDer, pHijoIzq->setsGanados, pHijoDer->setsGanados);
	/*Esta funcion elige el ganador entre dos equipos 
	haciendo que la raiz de estos sea el ganador*/

	jugador ganador(jugador * pActual);
	/*Esta funcion retorna el ganador del torneo
	solo si el arbol esta lleno*/

	void imprimirTorneo(jugador * pActual);
	/*Esta funcion imprime el arbol del torneo*/

};