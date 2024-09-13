#include "ArchivosBinarios.h"



int main(int argc, char *argv[])
{
    Account account1={154210,"Pedro Perez",250000,Male};
    Account account2={154211,"Ricardo Rojas",280400,Male};
    Account account3={1,"Luisa Rincon",500000,Female};
    Account account4={2331,"Alejandro Hernandez",12000,Male};
    Account account5={2183,"Camilo Pena",40000,Male};
    writeBinaryFile(account1);
   // writeBinaryFile(account2);

    //Leer archivo
    readBinaryFile();

    //Leer lista de accounts
    const int SIZE=5;
    Account accounts[SIZE]={account1,account2,account3,account4,account5};
    //writeBinaryList(accounts,SIZE);
    //readBinaryList(SIZE);

    return 0;
}
