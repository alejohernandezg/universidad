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
        node *temp=head;
        while(temp !=NULL)
        {
            if(temp->value == value)
            {
                temp->pAnt->pSgte = temp->pSgte;
                delete temp;
                return true;
            }
            temp = temp ->pSgte;
        }
    }
    return false;
}

bool ListaDoble::removeByFdx(int pos) {
    return false;
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
    while(temp->pSgte != NULL)
    {
        if(temp->value == value)
        {
            return true;
        }
        temp = temp->pSgte;
    }
    return false;
}
