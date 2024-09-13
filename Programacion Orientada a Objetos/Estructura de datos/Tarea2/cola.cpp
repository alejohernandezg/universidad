#include "cola.h"

bool Cola::vaciaCola()
	{
	return list.isEmpty();
	}
void Cola::pushCola(int elem){
	list.addlast(elem);
}

bool Cola::popCola(){
	list.removeByFdx(1);
}

int Cola::peekCola(){
	return list.returnFirts();
}

void Cola::printCola(){
	while(!vaciaCola()){
		cout << peekCola()<< endl;
		popCola();
	}
}