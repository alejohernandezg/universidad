//
// Created by ALEJANDRO on 14/03/2016.
//
#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
class ListaDoble {
    struct node
    {
        T value;
        node *pSgte;
        node *pAnt;
    };

    node *head;
    node *tail;

    
    public:

        ListaDoble()
        {
            head=NULL;
            tail=NULL;
        }
        bool isEmpty();
        int size();
        void addFirst(T value);
        void addlast(T value);
        bool remove(T value);
        bool removeByFdx(int pos);
        void print();
        bool contains(T value);
        T returnFirts();

};

template<typename T>
bool ListaDoble<T>::isEmpty()
{
    return head == NULL && tail == NULL;
}

template<typename T>
int ListaDoble<T>::size()
{
    int contador = 0;
    node * temp=head;
    while(temp !=NULL)
    {
        contador++;
        temp=temp->pSgte;
    }
    return contador;
}

template<typename T>
void ListaDoble<T>::addFirst(T value) {
    node *nuevoNodo = new node;
    nuevoNodo->value=value;
    if(isEmpty())
    {
        tail=nuevoNodo;
        nuevoNodo->pAnt=NULL;
        nuevoNodo->pSgte=NULL;
    }else
    {
        nuevoNodo->pSgte = head;
        head->pAnt = nuevoNodo;
    }
    head=nuevoNodo;
}

template<typename T>
void ListaDoble<T>::addlast(T value) {
    node *nuevoNodo = new node;
    nuevoNodo->value=value;
    nuevoNodo->pSgte=NULL;
    if(isEmpty())
    {
        head = nuevoNodo;
        nuevoNodo->pAnt = NULL;
        nuevoNodo->pSgte =NULL;
    }else
    {
        tail->pSgte = nuevoNodo;
        nuevoNodo->pAnt=tail;
    }
    tail = nuevoNodo;

}

template<typename T>
bool ListaDoble<T>::remove(T value)
{
    if(contains(value))
    {
        if(head->value == value)
        {
            head = head->pSgte;
            head->pAnt = NULL;
            return true;
        }
        if(tail->value == value)
        {
            tail = tail->pAnt;
            tail->pSgte = NULL;
            return true;
        }
        node *temp=head->pSgte;
        while(temp->pSgte !=NULL)
        {
            if(temp->value == value)
            {
                temp->pAnt->pSgte = temp->pSgte;
                temp->pSgte->pAnt = temp->pAnt;
                delete temp;
                return true;
            }
            temp = temp ->pSgte;
        }
    }
    return false;
}

template<typename T>
bool ListaDoble<T>::removeByFdx(int pos)
{
    node * temp=head;
    int contador=0;
    if(pos==1)
    {
        if(size() == 1){
            head = NULL;
            tail = NULL;
        }else {
            head = head->pSgte;
            head->pAnt = NULL;
            delete temp;
            return true;
        }
    }
    else if(pos == size())
    {
        temp = tail;
        tail = tail -> pAnt;
        tail->pSgte=NULL;
        delete temp;
        return true;

    }
    else if(pos>1 && pos < size())
    {
        while(temp != NULL)
        {
            if(contador==pos-1)
            {
                temp->pAnt->pSgte = temp->pSgte;
                temp->pSgte->pAnt = temp->pAnt;

                return true;
            }
            contador++;
            temp = temp -> pSgte;
        }
    }else
    {
        cout << "Posicion no valida" << endl;
        return false;
    }

}

template<typename T>
void ListaDoble<T>::print()
{
    node * temp=head;
    while(temp!=NULL)
    {
        cout << temp->value << ";";
        temp = temp->pSgte;
    }
}

template<typename T>
bool ListaDoble<T>::contains(T value)
{
    node * temp=head;
    while(temp != NULL)
    {
        if(temp->value == value)
        {
            return true;
        }
        temp = temp->pSgte;
    }
    return false;
}

template<typename T>
T ListaDoble<T>::returnFirts(){
    if(!isEmpty()){
        return head->value;
    }
}

