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

    /**
     * Representa el ultimo vertice asociado
     */
    int ultimoVertice;

    /**
     * Coge e incrementa el ultimo vertice
     */
    int getAndIncrementLastVertex() {
        return ultimoVertice ++;
    }

    /**
     * Mira si el vertice esta en un rango valido
     */
    bool vertexIndexInRange(int index) {
        return index >= 0 && index < ultimoVertice;
    }

public:
    // Constructor vacio
    Grafo(): vertices(vector<Vertice<T> *>()), ultimoVertice(0) {}

    // Constructor con elementos
    // Nota: numVertices es innecesario ya que tenemos ultimo vertice
    Grafo(vector<T> datosGrafos, float ** arcos, int numVertices) {
        for (T element : datosGrafos) {
            vertices.push_back(new Vertice<T>(getAndIncrementLastVertex(), element));
        }
        //for (int i = 0; i < numvertices)
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
        ultimoVertice = -1;
    }

    /**
     * Sobrecarga del operador del arreglo en la pos {@code i}
     * @param i el index de la posicion
     */
    const int& operator[](int i)
    {
        if (!vertexIndexInRange(i))
            return -1;

        return (int) (*(vertices[i] -> getData()));
    }

    /**
     * Inserta un nuevo vertice basado en un {@code dato}
     * @param dato  el valor del vertice
     */
    void insVertice(T  dato) {
        vertices.push_back(new Vertice<T>(getAndIncrementLastVertex(), dato));
    }

    /**
     * Modifica el valor que tiene {@code x index} vertice con un nuevo {@code dato}
     * @param index el index
     * @param dato  el dato a modificar
     */
    void setVertice(int index, T  dato) {
        if (!vertexIndexInRange(index))
            return;

        vertices[index] -> setData(dato);
    }
    void setDeltaVertice(int index, float nuevoDelta){
        if(!vertexIndexInRange(index))
            return;
        vertices[index] -> setDelta(nuevoDelta);
    }
    float getDeltaVertice(int index){
        if(!vertexIndexInRange(index))
            return -10000;
        return vertices[index] -> getDelta();
    }
    /**
     * Modifica un arco existente dados un vertice origen y un vertice siguiente y el nuevo costo
     * @param vertAnterior  el vertice origen
     * @param vertSiguiente el vertice siguiente
     * @param costo el costo de la arista
     */
    void setArco(int vertAnterior, int vertSiguiente, float costo) {
        if (!vertexIndexInRange(vertAnterior) || !vertexIndexInRange(vertSiguiente))
            return;

        Arista<T> * arista = vertices[vertAnterior] -> getArista(vertSiguiente);
        if (arista == nullptr) {
            Vertice<T> * anterior = vertices[vertAnterior];
            Vertice<T> * siguiente = vertices[vertSiguiente];
            Arista<T> * conexion = new Arista<T>(anterior, siguiente, costo);

            anterior -> insertarArista(conexion);
        } else {
            arista -> setCosto(costo);
        }
    }

    /**
     * Elimina un arco dados dos vertices origen y siguiente
     * @param vertAnterior  representa el vertice origen
     * @param vertSiguiente representa el vertice siguiente
     */
    void elimArco(int vertAnterior, int vertSiguiente) {
        if (!vertexIndexInRange(vertAnterior) || !vertexIndexInRange(vertSiguiente))
            return;

        Arista<T> * arista = vertices[vertAnterior] -> getArista(vertSiguiente);
        if (arista != nullptr) {
            Vertice<T> * anterior = vertices[vertAnterior];
            anterior -> eliminaConexion(arista);
        }
    }

    /**
     * Nos genera una lista de los preecesores de cierto index
     */
    vector<Vertice<T> *> predecesores(int verticeIdx) {
        typename vector<Vertice<T> *>::const_iterator fromIdx = vertices.begin();
        typename vector<Vertice<T> *>::const_iterator endIdx = vertices.begin() + verticeIdx;
        return vector<Vertice<T> *>(fromIdx, endIdx);
    }

    /**
     * Nos genera una lista de sucesores de cierto index
     */
    vector<Vertice<T> *> sucesores(int verticeIdx) {
        typename vector<Vertice<T> *>::const_iterator fromIdx = vertices.begin() + verticeIdx + 1;
        typename vector<Vertice<T> *>::const_iterator endIdx = vertices.end();
        return vector<Vertice<T> *>(fromIdx, endIdx);
    }

    /**
     * Devuelve el costo del arco basado el vertice origen y el siguiente
     * @param vertAnterior el vertice origen
     * @param vertSiguiente el vertice siguiente
     */
    float costoArco(int vertAnterior, int vertSiguiente) {
        if (!vertexIndexInRange(vertAnterior) || !vertexIndexInRange(vertSiguiente))
            return -1;

        Arista<T> * arista = vertices[vertAnterior] -> getArista(vertSiguiente);
        if (arista != nullptr) {
            return arista -> getCosto();
        }

        return -1;
    }

    /**
     * Coge la lista de vertices que tiene el grafo
     */
    vector<Vertice<T> *> getVertices() {
        return vertices;
    }

    /**
     * Agarra el valor como un T de cierto vertice
     */
    T infoVertice(int vertice) {
        if (vertexIndexInRange(vertice))
            return vertices[vertice] -> getData();
    }

    /**
     * Devuelve el tamaño del grafo respecto a los vertices
     */
    int size() {
        return ultimoVertice;
    }

    /***
     * Imprime el grafo
     */
    void imprimirGrafo() {
        cout.setf(cout.fixed);
        cout.precision(2);
        for (Vertice<T> * vertice : vertices) {
            cout << "************************************************************************************" << endl;
            if (vertice -> getAristas().size() > 0) {
                cout << "El vertice con [ID, VALOR]: [" << vertice -> getIdentificador() << ", " << vertice->getData() << "] esta conectado con los siguientes elementos: " << endl;
                for (Arista<T> * arista : vertice -> getAristas()) {
                    cout << "[CONECTADO_CON_ID, CONECTADO_CON_VALOR, COSTO_ARISTA]: [" << (arista->getVerticeSiguiente()->getIdentificador()) << ", " << arista->getVerticeSiguiente()->getData() << ", " << arista->getCosto() << "]." << endl;
                }
                cout << "************************************************************************************" << endl;
            } else {
                cout << "El vertice con [ID, VALOR]: [" << vertice -> getIdentificador() << ", " << vertice->getData() << "] no esta conectado con nada." << endl;
            }
        }
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Grafo<T>& obj) {
    obj.imprimirGrafo();
    return os;
}

#endif //TALLERGRAFOS_GRAFO_H
