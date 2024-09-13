//
// Created by ALEJANDRO on 16/05/2016.
//

#ifndef TAREA4_MATRICES_H
#define TAREA4_MATRICES_H
#include <iostream>

#include <cstdlib>

using namespace std;

template <typename T>
class Matrices{
    struct node
    {
        T* value;
        node *pArriba;
        node *pAbajo;
        node *pIzq;
        node *pDer;
    };

    int size;
    node *topLeft;
    node *topRight;
    node *bottomLeft;
    node *bottomRight;

    bool isEmpty();
public:

    Matrices()
    {
        topLeft=NULL;
        topRight=NULL;
        bottomLeft=NULL;
        bottomRight=NULL;
        size=0;
    }

    void addFilaCol();
    void delFilaCol();
    void print();
    T infoCelda();
    void addCelda(int,int,T);
    node * newFil(int);
    node * newCol(int);
};

template<typename T>
node *Matrices::newFil(int size) {
    node * nuevoNodo = new node;
    node * headFil=nuevoNodo;
    if(size == 1)
    {
        return headFil;
    }else{
        node * temp=headFil;
        int contador=0;
        while(contador < size){
            node * nodon = new node;
            temp->pAbajo=nodon;
            nodon->pArriba = temp;
            contador++;
            temp=temp->pAbajo;
        }
    }
}

template<typename T>
bool Matrices::isEmpty()
{
    return size==0;
}

template<typename T>
void Matrices<T>::addFilaCol()
{

}
template<typename T>
void Matrices<T>::delFilaCol()
{

}
template<typename T>
void Matrices<T>::print()
{

}

template<typename T>
void Matrices<T>::infoCelda()
{

}

template<typename T>
void Matrices<T>::addCelda(int fila, int col, T value)
{

}




#endif //TAREA4_MATRICES_H
