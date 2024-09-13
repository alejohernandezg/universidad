//
// Created by lufe0_000 on 5/15/2016.
//

#include "ArchivosBinarios.h"

void readBinaryFile()
{
    Account account;
    std::ifstream ifile("datos.dat", std::ios::binary);
    while (!ifile.eof())
    {
        ifile.read( reinterpret_cast< char * >(&account),sizeof(account));
        if (!ifile.eof())
        {
            std::cout << account.accountNumber << "," <<account.owner <<" , "<<account.balance<<" Sex "<< account.sex << std::endl;
        }else
            std::cout << "EOF\n";
        
    }
}

void writeBinaryList(Account accounts[], int size){
    std::ofstream ofile("datos.dat", std::ios::binary);
    // Datos a almacenar
    ofile.write(reinterpret_cast< const char * >(accounts),sizeof(Account)*size);
    ofile.close();
}


void readBinaryList(const int SIZE){
    std::ifstream ifile("datos.dat", std::ios::binary);
    while (!ifile.eof()) 
    {
        Account accounts[SIZE];
        ifile.read( reinterpret_cast< char * >(accounts),sizeof(Account)*SIZE);
        if (!ifile.eof())
            for (int i=0;i<SIZE;i++){
                std::cout << accounts[i].accountNumber << "," <<accounts[i].owner <<" , "<<accounts[i].balance<<" Sex "<< accounts[i].sex << std::endl;
            }
        else
            std::cout << "EOF\n";
    }

    ifile.close();
}

void writeBinaryFile(Account account){
    std::ofstream ofile("datos.dat", std::ios::binary);
    ofile.write(reinterpret_cast< const char * >(&account),sizeof(account));
    ofile.close();
}
