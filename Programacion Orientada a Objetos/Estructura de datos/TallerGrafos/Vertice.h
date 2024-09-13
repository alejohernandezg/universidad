//
// Created by Sebastían on 26/09/2016.
//

#ifndef TALLERGRAFOS_VERTICE_H
#define TALLERGRAFOS_VERTICE_H

#include <vector>

using std::vector;

template <typename T>
class Arista;

template <typename T>
class Vertice {
    int identificador;
    T * data;
    vector<Arista<T> *> aristas;

public:
    Vertice(int _indentificador, T * _data): identificador(_indentificador), data(_data) {}

    void setData(T * _data) {
        data = _data;
    }

    void insertarArista(Arista<T> * arista) {
        aristas.push_back(arista);
    }

    void eliminaConexion(Arista<T> * lookup) {
        int index = 0;
        for (Arista<T> * arista : aristas) {
            if (arista -> getVerticeSiguiente() == lookup -> getVerticeSiguiente()) {
                aristas.erase(aristas.begin() + index);
                break;
            }
            index ++;
        }
    }

    Arista<T> * getArista(int vertSiguiente) {
        for (Arista<T> * arista : aristas) {
            if (arista -> conectaConVertices(identificador, vertSiguiente))
                return arista;
        }
        return nullptr;
    }

    vector<Arista<T> *> getAristas() {
        return aristas;
    }

    T * getData() {
        return data;
    }

    int getIdentificador() {
        return identificador;
    }
};


#endif //TALLERGRAFOS_VERTICE_H
