//
// Created by ALEJANDRO on 14/03/2016.
//

#include "ListaDoble.h"

bool ListaDoble::isEmpty()
{
    return head == NULL && tail == NULL;
}

int ListaDoble::size()
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

void ListaDoble::addFirst(int value) {
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

void ListaDoble::addlast(int value) {
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

bool ListaDoble::remove(int value)
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

bool ListaDoble::removeByFdx(int pos)
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


void ListaDoble::print()
{
    node * temp=head;
    while(temp!=NULL)
    {
        cout << temp->value << ";";
        temp = temp->pSgte;
    }
}

bool ListaDoble::contains(int value)
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

int ListaDoble::returnFirts(){
    if(!isEmpty()){
        return head->value;
    }else{
        return 0;
    }
}
