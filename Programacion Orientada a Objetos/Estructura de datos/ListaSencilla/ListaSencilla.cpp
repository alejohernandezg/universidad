#include "ListaSencilla.h"

void ListaSencilla::addFirst(int elem)
{
	node * nuevoNodo = new node;
	nuevoNodo->value=elem;

	if(head==NULL)
	{
		nuevoNodo->pSgte=NULL;

	}else
	{
		nuevoNodo->pSgte=head;
	}
	head = nuevoNodo;
}

void ListaSencilla::imprimir()
{
	node *temp=head;
	while(temp!=NULL)
	{
		cout << temp->value << ";";
		temp=temp->pSgte;
	}
}

int ListaSencilla::size()
{
	node *temp=head;
	int contador = 0;
	while(temp!=NULL)
	{	
		contador++;
		temp =temp->pSgte;
	}
	return contador;
}

bool ListaSencilla::contains(int elem)
{
	node *temp=head;
	while(temp!=NULL)
	{
		if(temp->value==elem)
		{
			return true;
		}
		temp = temp->pSgte;
	}
	return false;
}

void ListaSencilla::addLast(int elem)
{
	//Crea un nuevo nodo 
	node * nuevoNodo = new node; // Le asigna un espacio de memoria
	nuevoNodo->value=elem; //Le asigna el elemento al nodo

	node * temp = head;
	while(temp->pSgte != NULL)
	{
		temp = temp->pSgte;
	}
	temp -> pSgte = nuevoNodo;
}

bool ListaSencilla::removeElement(int elem)
{
	//Crea temporales para el ciclo
	node * temp1=head;
	node * temp2=temp1->pSgte;

	while(temp2!=NULL)
	{
		if(temp1->value==elem)
		{
			temp1->pSgte=temp2->pSgte;
			return true;
		}
		temp1=temp1->pSgte;
		temp2=temp2->pSgte;
	}
	return false;
}

void ListaSencilla::elmListaPos(int pos)
{
	node * temp=head;
	int contador=1;
	if(pos==1)
	{
		head = head -> pSgte;
	}
	else if(pos>1 && pos <= size())
	{
		while(temp != NULL)
		{
			if(contador==pos-1)
			{
				temp->pSgte=temp->pSgte ->pSgte;
			}
		contador++;
		temp = temp -> pSgte;
		}
	}else
	{
		cout << "Posicion no valida" << endl;
	}

}