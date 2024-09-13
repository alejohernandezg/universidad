#include "cola.h"
#include "listasDobles2.h"
#include "pilas.h"
#include <time.h>
#include <cstdlib>
#pragma once

listaDoble llenarListaAleatorio();
Cola llenarColaDomino();
listaDoble llenarFichasJugador(Cola &C, listaDoble list);
void llenarSobrantes(Cola &C, Stack &pila);
int empiezaJuego(listaDoble arreglo[], int tam, listaDoble &fichasEnJuego);
void verFichasJugadores(listaDoble jugadores[], int tam);
bool fichaValida(listaDoble &jugador, listaDoble &juego);
bool jugarFicha(listaDoble &jugador, listaDoble &juego, int f1, int f2, int lado);
bool tomarFichaPila(listaDoble &jugador, Stack &pila);
void borrarPorRef(listaDoble &lst, int val1, int val2);
int sumaFichas(listaDoble jugador);
int ganadorJuegoCerrado(listaDoble jugadores[], int tam);