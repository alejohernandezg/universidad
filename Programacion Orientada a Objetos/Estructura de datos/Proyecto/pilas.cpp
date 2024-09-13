#include "pilas.h"

void Stack::push(int elem1, int elem2){
    list.anexarF(elem1, elem2);
}

bool Stack::pop(){
    list.removeUlt();
}

int Stack::peek1(){
    return list.retornarUlt1();
}
int Stack::peek2(){
    return list.retornarUlt2();
}

void Stack::printStack(){
    int val1;
    int val2;
    while(!list.isEmpty()){
        val1=peek1();
        val2=peek2();
        cout << val1<< ","<<val2 << endl;
        pop();
    }
}//
// Created by ALEJANDRO on 17/04/2016.
//

