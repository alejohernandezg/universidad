//
// Created by Sebastían on 26/09/2016.
//

#ifndef TALLERGRAFOS_ARISTA_H
#define TALLERGRAFOS_ARISTA_H

#include "Vertice.h"

template <typename T>
class Arista {
    Vertice<T> * verticeAnterior;
    Vertice<T> * verticeSiguiente;
    float costo;

public:
    Arista(Vertice<T> * anterior, Vertice<T> * siguiente, float _costo): verticeAnterior(anterior), verticeSiguiente(siguiente), costo(_costo) {}

    void setVerticeAnterior(Vertice<T> * anterior) {
        verticeAnterior = anterior;
    }

    void setVerticeSiguiente(Vertice<T> * siguiente) {
        verticeSiguiente = siguiente;
    }

    void setCosto(float _costo) {
        costo = _costo;
    }

    Vertice<T> * getVerticeAnterior() {
        return verticeAnterior;
    }

    Vertice<T> * getVerticeSiguiente() {
        return verticeSiguiente;
    }

    bool conectaConVertices(int anteriorIndex, int siguienteIndex) {
        if (verticeAnterior -> getIdentificador() == anteriorIndex &&
                verticeSiguiente -> getIdentificador() == siguienteIndex)
            return true;

        return false;
    }

    float getCosto() {
        return costo;
    }
};


#endif //TALLERGRAFOS_ARISTA_H

