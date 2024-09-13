//
// Created by ALEJANDRO.
//

#ifndef CALCULADORA2_0_CALCULADORA_H
#define CALCULADORA2_0_CALCULADORA_H

#include "NoDivisible.h"


class Calculadora {
protected:
    int primer_factor;
    int segundo_factor;
public:
    Calculadora(int nuevo_primer_factor,
                int nuevo_segundo_factor);
    void SetNum2(int nuevo_segundo_factor);
    int Suma();
    int Resta();
    int Multiplicacion();
    int Division();
};


#endif //CALCULADORA2_0_CALCULADORA_H
