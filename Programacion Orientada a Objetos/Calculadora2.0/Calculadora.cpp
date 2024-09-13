//
// Created by ALEJANDRO.
//

#include "Calculadora.h"

Calculadora::Calculadora(int nuevo_primer_factor,
                         int nuevo_segundo_factor) {
    primer_factor = nuevo_primer_factor;
    segundo_factor = nuevo_segundo_factor;
}

void Calculadora::SetNum2(int nuevo_segundo_factor) {
    segundo_factor = nuevo_segundo_factor;
}

int Calculadora::Suma() {
    return primer_factor + segundo_factor;
}

int Calculadora::Resta() {
    return primer_factor - segundo_factor;
}

int Calculadora::Multiplicacion() {
    return primer_factor * segundo_factor;
}

int Calculadora::Division() {
    if(segundo_factor == 0) throw NoDivisible("Math Error");
    return primer_factor / segundo_factor;
}

