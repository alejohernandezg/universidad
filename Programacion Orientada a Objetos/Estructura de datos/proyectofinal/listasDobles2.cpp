#include "listasDobles2.h"

int listaDoble::size(){
	listaDoble::nodo *tmp = head;
	int cont = 1;
	if(tmp == NULL)
		return 0;
	while(tmp -> pSgte != NULL){
		cont++;
	}
	return cont;
}

int listaDoble::retornarUlt1(){
	if(isEmpty())
		return 0;
	return tail->valor1;
}

int listaDoble::retornarUlt2(){
	if(isEmpty())
		return 0;
	return tail-> valor2;
}


void listaDoble::print(){
	nodo *tmp = head;
	while( tmp != NULL && tmp->pSgte != NULL){
		cout << tmp -> valor1<< "," << tmp-> valor2 << endl;
		tmp = tmp->pSgte;
	}
	if(tmp!=NULL && tmp->pSgte == NULL){
		cout << tmp -> valor1 << ",";
		cout << tmp -> valor2<< endl;
	}
}

bool listaDoble::isEmpty(){
	if(tail == NULL && head==NULL)
		return true;
	return false;
}

listaDoble::nodo* listaDoble::contains(int val1, int val2){
	listaDoble::nodo *tmp = head;
	if(isEmpty())
		return NULL;
	while(tmp -> pSgte != NULL){
		if(tmp -> valor1 == val1 && tmp-> valor2 == val2)
			return tmp;
		tmp = tmp -> pSgte;
	}
	if(tmp -> pSgte == NULL && (tmp-> valor1 == val1 && tmp ->valor2 == val2))
		return tmp;
	return NULL;
}

void listaDoble::anexarP(int val1, int val2){
	nodo *nuevoNodo= new nodo();
	nuevoNodo -> valor1 = val1;
	nuevoNodo -> valor2 = val2;
	nuevoNodo -> pAnt = NULL;
	if(isEmpty()){
		nuevoNodo->pSgte = NULL;
		head = nuevoNodo;
		tail = nuevoNodo;
	}
	else{
		nuevoNodo -> pSgte = head;
		head -> pAnt = nuevoNodo;
		head = nuevoNodo;
	}
}

void listaDoble::anexarF(int val1, int val2){
	nodo *nuevoNodo = new nodo();
	nuevoNodo -> valor1 = val1;
	nuevoNodo -> valor2 = val2;
	nuevoNodo -> pSgte = NULL;
	if(isEmpty()){
		nuevoNodo -> pAnt = NULL;
		tail = nuevoNodo;
		head = nuevoNodo;
	}
	else{
		nuevoNodo -> pAnt = tail;
		tail -> pSgte = nuevoNodo;
		tail = nuevoNodo;
	}
}

bool listaDoble::removerValor(int val1, int val2){
	nodo *tmp = contains(val1, val2);
	if(tmp == NULL)
		return false;
	else{
		if(tmp -> pAnt == NULL && tmp -> pSgte == NULL){
			head = NULL;
			tail = NULL;
		}
		if(tmp -> pAnt == NULL && tmp -> pSgte != NULL){
			head= head -> pSgte;
			head -> pAnt = NULL;
			tmp -> pSgte = NULL;
			tmp = NULL;
		}
		if(tmp -> pAnt != NULL && tmp -> pSgte == NULL){
			tail = tail -> pAnt;
			tail -> pSgte = NULL;
			tmp -> pAnt = NULL;
			tmp = NULL;
		}
		if(tmp -> pAnt != NULL && tmp -> pSgte != NULL){
			tmp -> pAnt -> pSgte = tmp -> pSgte;
			tmp -> pSgte -> pAnt = tmp -> pAnt;
			tmp = NULL;
		}

	}
	delete tmp;
}

bool listaDoble::removeUlt()
{
	if(isEmpty())
		return false;
	if(tail -> pAnt == NULL){
		head = NULL;
		tail = NULL;
		return true;
	}
	else{
		tail = tail->pAnt;
		tail -> pSgte -> pAnt = NULL;
		tail -> pSgte = NULL;
		return true;
	}
}

bool listaDoble::removeFirst(){
	if(isEmpty())
		return false;
	else
	{
		if(head ->pSgte == NULL){
			head =NULL;
			tail = NULL;
			return true;
		}
		else{
			head = head -> pSgte;
			head -> pAnt ->pSgte = NULL;
			head -> pAnt = NULL;
			return true;
		}
	}

}

int listaDoble::retornarFirst1(){
	if(isEmpty())
		return 0;
	else{
		return head -> valor1;
	}
}

int listaDoble::retornarFirst2(){
	if(isEmpty())
		return 0;
	else{
		return head-> valor2;
	}
}