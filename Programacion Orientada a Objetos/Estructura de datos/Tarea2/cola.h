#pragma once
#include "listaDoble.h"

template<typename T>
class Cola{
private:
	ListaDoble<T> list;
public:
	bool vaciaCola();
	void pushCola(T);
	bool popCola();
	T peekCola();
	void printCola();
};

template<typename T>
bool Cola<T>::vaciaCola()
{
	return list.isEmpty();
}

template<typename T>
void Cola<T>::pushCola(T elem){
	list.addlast(elem);
}

template<typename T>
bool Cola<T>::popCola(){
	list.removeByFdx(1);
}

template<typename T>
T Cola<T>::peekCola(){
	return list.returnFirts();
}

template<typename T>
void Cola<T>::printCola(){
	while(!vaciaCola()){
		cout << peekCola()<< endl;
		popCola();
	}
}