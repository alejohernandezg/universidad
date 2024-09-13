#include "cola.h"
#include "listasDobles2.h"
#include "pilas.h"
#include <time.h>
#include <cstdlib>
#pragma once

listaDoble llenarListaAleatorio();
Cola llenarColaDomino();
listaDoble llenarFichasJugador(Cola &C, listaDoble list);
Stack llenarSobrantes(Cola &C, Stack pila);
int empiezaJuego(listaDoble arreglo[], int tam, listaDoble &fichasEnJuego);
void verFichasJugadores(listaDoble jugadores[], int tam)