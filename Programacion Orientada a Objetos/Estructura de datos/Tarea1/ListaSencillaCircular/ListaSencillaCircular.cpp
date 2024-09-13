//
// Created by ALEJANDRO on 18/05/2016.
//

#include "ListaSencillaCircular.h"

bool ListaSencillaCircular::isEmpty()
{
    return head == NULL && tail == NULL;
}

int ListaSencillaCircular::size()
{
    if(!isEmpty())
    {
        if(head==tail){
            return 1;
        }else {
            node *temp = head->pSgte;
            int contador = 1;
            while (temp != head) {
                contador++;
                temp = temp->pSgte;
            }
            return contador;
        }
    }
    return 0;
}

void ListaSencillaCircular::addLast(int value)
{
    node * nuevoNodo = new node;
    nuevoNodo->value = value;
    if(isEmpty())
    {
        head = nuevoNodo;
        tail = nuevoNodo;
        tail->pSgte = head;
    }else{
        nuevoNodo->pSgte = head;
        tail->pSgte = nuevoNodo;
        tail = nuevoNodo;
    }
}

void ListaSencillaCircular::addFirst(int elem)
{
    node * nuevoNodo = new node;
    nuevoNodo->value = elem;
    if(isEmpty())
    {
        tail = nuevoNodo;
        tail->pSgte = nuevoNodo;
    }else{
        nuevoNodo->pSgte = head;
        tail->pSgte = nuevoNodo;
    }
    head = nuevoNodo;
}

bool ListaSencillaCircular::removeElement(int elem)
{
    if(!isEmpty())
    {
        if(head ->value== elem)
        {
            head = head ->pSgte;
            tail -> pSgte = head;
            return true;
        }
        node * temp2 = head;
        node * temp1 = head->pSgte;
        while(temp2!=tail)
        {
            if(temp1->value==elem)
            {
                temp2->pSgte = temp1->pSgte;
                if(temp1 == tail)
                {
                    tail = temp2;
                }
                return true;
            }
            temp1 =temp1->pSgte;
            temp2=temp2->pSgte;
        }
        return false;
    }
    return false;
}

void ListaSencillaCircular::imprimir()
{
    if(!isEmpty())
    {
        node * temp = head->pSgte;
        cout << head ->value << ";";
        while(temp!= head)
        {
            cout << temp->value << ";";
            temp = temp ->pSgte;
        }
    }
}

bool ListaSencillaCircular::contains(int elem)
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

void ListaSencillaCircular::elmListaPos(int pos)
{
    node * temp=head;
    node * temp2=head->pSgte;
    int contador=0;
    if(pos==1)
    {
        head = head->pSgte;
        tail->pSgte = head;
    }
    else if(pos >1 && pos<=size())
    {
        while(temp -> pSgte != head)
        {
            if(contador==pos-2)
            {
                temp -> pSgte = temp2 -> pSgte;
                if(temp2 == tail)
                {
                    tail = temp;
                }
            }
            contador++;
            temp = temp->pSgte;
            temp2 = temp2->pSgte;
        }
    }else
        cout << "Posicion no valida" << endl;
}










