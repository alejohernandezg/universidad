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

void llenarSobrantes(Cola &C, Stack &pila){
    while(!C.vaciaCola()){
        pila.push(C.peekCola1(), C.peekCola2());
        C.popCola();
    }
}
void borrarPorRef(listaDoble &lst, int val1, int val2){
    lst.removerValor(val1, val2);
}

int empiezaJuego(listaDoble arreglo[], int tam, listaDoble &fichasEnJuego){
    for(int j=6; j>= 0; j--){
        for(int i =0 ; i<tam ; i++){
            //cout << i << endl;
            if(arreglo[i].contains(j, j) != NULL){
                //cout <<" entro a: " << i << endl;
                fichasEnJuego.anexarP(j,j);
                //cout << "anexo al juego" << endl;
                borrarPorRef(arreglo[i], j, j);
                //cout << "removio el valor" << endl;
                return i;
            }
        }
    }
    for(int j= 6; j>=0; j--){
        for(int i = j-1; i>=0; i--){
            for(int k=0; k<tam; k++){
                //cout << k << endl;
                if((arreglo[k].contains(j, i) != NULL) || (arreglo[k].contains(i, j) != NULL)){
                    if(arreglo[k].contains(j, i) != NULL){
                        fichasEnJuego.anexarP(j,i);
                        borrarPorRef(arreglo[k], j, i);
                        return k;
                    }
                    else
                        fichasEnJuego.anexarP(i ,j);
                    borrarPorRef(arreglo[k], i, j);
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

bool fichaValida(listaDoble &jugador, listaDoble &juego){
    int P1 = juego.retornarFirst1();
    int F2 = juego.retornarUlt2();
    //cout << P1 << F2 << endl;
    for(int i = 6; i >= 0; i--){
        if(((jugador.contains(i, P1)!= NULL) || jugador.contains(P1,i)) || ((jugador.contains(F2, i) != NULL || jugador.contains(i, F2)!= NULL)))
            return true;
    }
    return false;
}

bool jugarFicha(listaDoble &jugador, listaDoble &juego, int f1, int f2, int lado){
    if(jugador.contains(f1, f2) != NULL || jugador.contains(f2, f1) != NULL){
        if(lado == 1){
            int p2= juego.retornarUlt2();
            if(p2 == f1){
                juego.anexarF(f1, f2);
                jugador.removerValor(f1, f2);
                return true;
            }
            if(p2 == f2){
                juego.anexarF(f2, f1);
                jugador.removerValor(f1, f2);
                return true;
            }
            return false;
        }
        else{
            int p1 =  juego.retornarFirst1();
            if(p1 == f2){
                juego.anexarP(f1, f2);
                jugador.removerValor(f1, f2);
                return true;
            }
            if(p1 == f1){
                juego.anexarP(f2, f1);
                jugador.removerValor(f1, f2);
                return true;
            }
            return false;
        }
    }
    else
        return false;
}

bool tomarFichaPila(listaDoble &jugador, Stack &pila){
    int val1 = pila.peek1();
    int val2 = pila.peek2();
    if(pila.pop()){
        jugador.anexarF(val1, val2);
        return true;
    }
    else
        return false;
}
int sumaFichas(listaDoble jugador){
    int cont=0;
    while(!jugador.isEmpty()){
        cont = jugador.retornarFirst1() + jugador.retornarFirst2();
        jugador.removeFirst();
    }
    return cont;
}

int ganadorJuegoCerrado(listaDoble jugadores[], int tam){
    int cont =0;
    int cont2= 0;
    int pos= 0;
    for(int i= 0; i < tam -1; i++){
        cont = sumaFichas(jugadores[i]);
        if(cont > cont2){
            cont2 = cont;
            pos = i;
        }
    }
    return pos;
}
