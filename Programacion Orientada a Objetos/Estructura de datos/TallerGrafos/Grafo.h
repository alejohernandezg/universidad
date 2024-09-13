//
// Created by Sebastían on 26/09/2016.
//

#ifndef TALLERGRAFOS_GRAFO_H
#define TALLERGRAFOS_GRAFO_H

#include <iostream>
#include <stdlib.h> // atof
#include <string>
#include <vector>
#include <fstream>
#include "Vertice.h"
#include "Arista.h"

using std::ifstream;
using std::ofstream;
using std::vector;
using std::endl;
using std::string;
using std::cout;

template <typename T>
class Vertice;
template <typename T>
class Arista;

template <typename T>
class Grafo {

    /**
     * Representa un conjunto de vertices
     */
    vector<Vertice<T> *> vertices;

public:
    // Constructor vacio
    Grafo(): vertices(vector<Vertice<T> *>()) {}

    // Constructor con elementos
    Grafo(vector<T> datosGrafos, float ** arcos, int numVertices) {
    }

    /**
     * Destructor
     */
    ~Grafo() {
        for (Vertice<T> * vertice : vertices) {
            if (vertice == nullptr)
                continue;
            for (Arista<T> * arista : vertice -> getAristas()) {
                if (arista == nullptr)
                    continue;
                delete(arista);
            }
            delete(vertice);
        }
        vertices.clear();
    }
