//
// Created by lufe0_000 on 5/11/2016.
//
#include <iomanip>
#include "Archivos.h"

void writeFile(){
    int account;
    string name;
    double balance;
    ofstream outClientFile("clients.txt",ios::out);
    if (!outClientFile){
        cout << "File could not be opened"<<endl;
        exit(1);
    }
    cout << "Enter the account, name and balance" << endl;
    //Until no more data is received
    while(cin>>account>>name>>balance){
        outClientFile << account<<' '<<name<<' '<<balance<<endl;
    }
    outClientFile.close();

    // Also it is possible to have an output stream without a file
    // In this case, we have to use the open function to associate the file later.
    ofstream outClient2;
    outClient2.open("NuevoArchivo.txt", ios::out);
    if (!outClient2){
        cout << "File could not be opened"<<endl;
        exit(1);
    }
    outClient2<< "NuevoArchivo"<<endl;

    outClient2.close();

}

void writeUsingPut(){
    ofstream outClientFile("text.txt",ios::out);
    if (!outClientFile){
        cout << "File could not be opened"<<endl;
        exit(1);
    }
    //File output
    outClientFile.put('e').put('o').put('a');

    //Screen output
    cout.put('e').put('a').put('o');

}

void filesReadUsingGet(){
   
}

void readUsingGet(){
    int const SIZE =200;
    char textToSave[SIZE];
    char textToSave2[SIZE];

    cin.get();
    cout << "Conjuntos de lineas" << endl;
    cin.get(textToSave,SIZE);
    cout << textToSave << endl;
    cin.get();
    cout << "getline" << endl;
    cin.getline(textToSave2,SIZE);
    cout << "Linea leida" << textToSave2;
    cin.get();
}

void readFile(){
    ifstream inClientFile("clients.txt",ios::in);
    if(!inClientFile){
        cerr <<"File could not be opened"<<endl;
        exit(1);
    }
    int account;
    string name;
    double balance;
    cout << "Account " <<" Name " << " Balance "<<endl;
    while(!inClientFile.eof()){
        inClientFile >> account >> name >> balance;
        //setw indica de cuanto sera el tamanio del campo
        cout << account<<setw(11)<<name <<setw(8)<<balance<<endl;
    }
    
    
    inClientFile.close();

}

void readFullFile(){
    
}
