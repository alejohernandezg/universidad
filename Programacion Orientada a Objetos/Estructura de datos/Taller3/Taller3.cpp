//
// Created by ALEJANDRO on 14/03/2016.
//

#include "Taller3.h"

bool polinomio::isEmpety()
{
    return head == NULL && tail == NULL;
}

void polinomio::addFactor(int coeficiente, int exponente)
{
    node * nuevoNodo = new node;
    nuevoNodo->coeficiente = coeficiente;
    nuevoNodo->exponente = exponente;
    nuevoNodo->pSgte = NULL;
    nuevoNodo->pAnt = NULL;
    if(isEmpety())
    {
        head = nuevoNodo;
        tail = nuevoNodo;
    }else{
        node *temp = head;
        if(containsExp(exponente))
        {
            node * temp= head;
            while(temp->pSgte!= NULL)
            {
                if(temp->exponente==exponente)
                {
                    temp->coeficiente = temp->coeficiente + coeficiente;
                }
                temp = temp ->pSgte;
            }
        }else
        {
            nuevoNodo -> pAnt = tail;
            tail->pSgte = nuevoNodo;
            tail = nuevoNodo;
        }
    }
}

int polinomio::size()
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

void polinomio::printPolinomio()
{
    node * temp=head;
    if(isEmpety())
    {
        cout << "Polinomio vacio" << endl;
    }else{
        while(temp!=NULL)
        {
            cout << temp->coeficiente << "x a la " << temp ->exponente;
            cout << " + ";
            temp = temp->pSgte;
        }
    }
}


bool polinomio::containsExp(int exponente)
{
    node * temp= head;
    while(temp!= NULL)
    {
        if(temp->exponente==exponente)
        {
            return true;
        }
        temp = temp ->pSgte;
    }
}


polinomio polinomio::multiplicar(polinomio polinomio1)
{
    polinomio polinomioResultado;
    node *temp = head;
    node *temp1 = polinomio1.head;
    if(isEmpety())
    {
        return polinomio1;
    }
    else{
        while(temp1->pSgte != NULL)
        {
            while(temp->pSgte != NULL)
            {
                int coeficiente = (temp1->coeficiente)*(temp->coeficiente);
                int exponente =temp->exponente+temp1->exponente;
                polinomioResultado.addFactor(coeficiente,exponente);
                temp=temp->pSgte;
            }
            temp1 = temp1->pSgte;
        }
        return polinomioResultado;
    }
}

bool polinomio::eliminarByExp(int exponente)
{
    node *temp = head;

    if(head->exponente==exponente)
    {
        head = head->pSgte;
        return true;
    }
    else if (tail->exponente==exponente)
    {
        tail = tail->pAnt;
        return true;
    }else{
        while(temp->pSgte != NULL)
        {
            if(temp->exponente==exponente)
            {
                temp->pAnt->pSgte = temp->pSgte;
                temp->pSgte->pAnt = temp->pAnt;
                delete temp;
                return true;
            }
            temp= temp->pSgte;
        }
    }

    return false;
}
