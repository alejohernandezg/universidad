#include "cola.h"

bool Cola::vaciaCola()
	{
	return list.isEmpty();
	}
void Cola::pushCola(int elem1, int elem2){
	list.anexarF(elem1,elem2);
}

bool Cola::popCola(){
	list.removeFirst();
}

int Cola::peekCola1(){
	return list.retornarFirst1();
}
int Cola::peekCola2(){
	return list.retornarFirst2();
}

void Cola::printCola(){
	while(!vaciaCola()){
		cout << peekCola1() << "," << peekCola2() << endl;
		popCola();
	}
}