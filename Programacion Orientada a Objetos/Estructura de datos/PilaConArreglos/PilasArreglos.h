#include <iostream>
using std::cout;
using std::endl;

class PilaConArreglos
{   
    static const int tam =10;
 
    int elements[tam];
    int idx;
public:
    PilaConArreglos()
    {
        idx =-1;
    }

    bool esVacia();
    bool esLlena();
    bool pop();
    int peek();
    bool push(int);
    void printPila();

};

