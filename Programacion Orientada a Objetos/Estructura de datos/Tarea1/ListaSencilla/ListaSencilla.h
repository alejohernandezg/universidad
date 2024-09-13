#include <iostream>
#include <cstdlib>

using namespace std;

#pragma once

class ListaSencilla 
{
	struct node
	{
		int value;
		struct node *pSgte;

		node() : value(0),pSgte(NULL){
		}
	};

	//Cabeza de la lista
	node * head = NULL;

	public:
		int size();
		void addLast(int elem);
		void addFirst(int elem);
		bool removeElement(int elem);
		void imprimir();
		bool contains(int elem);
		void elmListaPos(int pos);
};