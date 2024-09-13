//
// Created by Sebastían on 26/09/2016.
//

#ifndef TALLERGRAFOS_GRAFOLOADER_H
#define TALLERGRAFOS_GRAFOLOADER_H

#include <string>
#include "Grafo.h"
#include <iostream>

using std::string;

class GrafoUtils {
    static float * cachedValues;

public:

    template <typename T>
    static void guardarGrafo(Grafo<T> & grafo, string direccion) {
        ofstream out(direccion);

        vector<Arista<T> *> aristas;
        int verticesAmount = grafo.getVertices().size();
        out << verticesAmount << "\n";
        for (int i = 0; i < verticesAmount; i ++) {
            if (grafo.getVertices()[i] -> getAristas().size() > 0) {
                for (Arista<T> * arista : grafo.getVertices()[i] -> getAristas()) {
                    aristas.push_back(arista);
                }
            }

            out << *(grafo.getVertices()[i] -> getData()) << "\n";
        }
        int aristasAmount = aristas.size();
        out << aristasAmount << "\n";
        for (int i = 0; i < aristasAmount; i ++) {
            out << (aristas[i] -> getVerticeAnterior() -> getIdentificador()) << "\n"
            << (aristas[i] -> getVerticeSiguiente() -> getIdentificador()) << "\n"
            << (aristas[i] -> getCosto()) << "\n";
        }
        out.close();
    }


    template <typename T>
    static Grafo<T> * cargarGrafo(string direccion) {
        Grafo<T> * grafo = new Grafo<T>();
        ifstream in(direccion);
        int nVertices;
        in >> nVertices;
        cachedValues = new float[nVertices];
        for (int i = 0; i < nVertices; i ++) {
            cachedValues[i] = 0;
        }
        string data;
        for (int i = 0; i < nVertices; i ++) {
            in >> data;
            cachedValues[i] = ::atof(data.c_str());
            grafo -> insVertice((cachedValues + i));
        }
        in >> data;
        int conexiones = ::atoi(data.c_str());
        string vertAnt, vertSig, costo;
        int vA, vS, cS;
        for (int i = 0; i < conexiones; i ++) {
            in >> vertAnt >> vertSig >> costo;
            vA = ::atoi(vertAnt.c_str());
            vS = ::atoi(vertSig.c_str());
            cS = ::atoi(costo.c_str());
            grafo->setArco(vA, vS, cS);
        }
        in.close();
        return grafo;
    }
};

float * GrafoUtils::cachedValues;
#endif //TALLERGRAFOS_GRAFOLOADER_H
