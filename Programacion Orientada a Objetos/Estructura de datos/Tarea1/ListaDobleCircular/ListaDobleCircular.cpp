//
// Created by ALEJANDRO on 14/03/2016.
//

#include "ListaDobleCircular.h"

bool ListaDobleCircular::isEmpty()
{
    return head == NULL && tail == NULL;
}

int ListaDobleCircular::size()
{
    if(!isEmpty()){ 
        int contador = 1;
        node * temp=head->pSgte;
        while(temp !=head)
        {
            contador++;
            temp=temp->pSgte;
        }
        return contador;
    }
    return 0;
}

void ListaDobleCircular::addFirst(int value) {
    node *nuevoNodo = new node;
    nuevoNodo->value=value;
    nuevoNodo->pAnt=tail;
    if(isEmpty())
    {
        head = nuevoNodo;
        tail=nuevoNodo;
        nuevoNodo->pSgte=nuevoNodo;
    }else
    {
        nuevoNodo->pSgte = head;
        head->pAnt = nuevoNodo;
        head=nuevoNodo;
        head->pAnt = tail;
        tail->pSgte = head;
    }
    
}

void ListaDobleCircular::addlast(int value) {
    node *nuevoNodo = new node;
    nuevoNodo->value=value;
    nuevoNodo->pSgte=head;
    if(isEmpty())
    {
        head = nuevoNodo;
        nuevoNodo->pAnt = tail;
        tail = nuevoNodo;
    }else
    {
        tail->pSgte = nuevoNodo;
        nuevoNodo->pAnt=tail;
        tail = nuevoNodo;
        head->pAnt = tail;
    }
    

}

bool ListaDobleCircular::remove(int value)
{
    if(contains(value))
    {
        if(head->value == value)
        {
            head = head->pSgte;
            head->pAnt = tail;
            tail->pSgte = head;
            return true;
        }
        if(tail->value == value)
        {
            tail = tail->pAnt;
            tail->pSgte = head;
            head->pAnt = tail;
            return true;
        }
        node *temp=head->pSgte;
        while(temp!=tail)
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

bool ListaDobleCircular::removeByFdx(int pos)
{

    int contador=0;
    if(pos==1)
    {
        head = head -> pSgte;
        head->pAnt = tail;
        tail->pSgte=head;
        return true;
    }
    
    if(pos==size())
    {
        tail->pAnt->pSgte = head;
        tail = tail->pAnt;
        head->pAnt=tail;
        return true;
    }
    else if(pos>1 && pos < size())
    {
        node * temp= head->pSgte;
        while(temp -> pSgte != head)
        {
            if(contador==pos-2)
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



void ListaDobleCircular::print()
{
    if(!isEmpty())
    {
        node * temp = head->pSgte;
        cout << head->value << ";";
        while(temp!= head)
        {
            cout << temp->value << ";";
            temp = temp ->pSgte;
        }
    }else{
        cout << "Esta vacio!" << endl;
    }
}

bool ListaDobleCircular::contains(int elem)
{
    if(!isEmpty())
    {
        if(head->value==elem)
        {
            return true;
        }
        if(tail->value==elem)
        {
            return true;
        }
        node * temp= head;
        while(temp!=tail){
            if(temp->value == elem)
            {
                return true;
            }
            temp=temp->pSgte;
        }
        return false;
    }
}
