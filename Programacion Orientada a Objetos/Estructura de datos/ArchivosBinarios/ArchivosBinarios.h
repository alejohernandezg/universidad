//
// Created by lufe0_000 on 5/15/2016.
//

#ifndef ARCHIVOSBINARIOS_ARCHIVOSBINARIOS_H
#define ARCHIVOSBINARIOS_ARCHIVOSBINARIOS_H

#include <iostream>
#include <fstream>
#include <string>


enum Sex {Female, Male, Other};

struct Account {
    int accountNumber;
    char owner[20];
    int balance;
    Sex sex;
};

void readBinaryFile();
void writeBinaryFile(Account account);
void readBinaryList(const int SIZE);
void writeBinaryList(Account accounts[], int size);
#endif //ARCHIVOSBINARIOS_ARCHIVOSBINARIOS_H
