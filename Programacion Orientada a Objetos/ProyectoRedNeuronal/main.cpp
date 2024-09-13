#include <iostream>
#include "redNeuronal.h"
#include "Grafo.h"
#include "GrafoUtils.h"

using std::string;

using namespace std;

/*float sumaPredecesores(Grafo<float> &grafo, int vertice) {
    vector<Vertice<float> * > predecesores = grafo.predecesores(vertice);
    float producto = 0;
    for (Vertice<float> * verticeIt  : predecesores) {
        Arista<float> * arista = verticeIt->getArista(vertice);
        if (arista != nullptr) {
            producto += (*(verticeIt->getData())) * arista->getCosto();
        }
    }
    return producto;
}*/

int main() {
    float valoresEntrada1[2]={1,0};
    float valoresEsperados1[1] ={1};
    float valoresEntrada2[2]={0,1};
    float valoresEsperados2[1] ={1};
    float valoresEntrada3[2]={1,1};
    float valoresEsperados3[1] ={0};
    float valoresEntrada4[2]={0,0};
    float valoresEsperados4[1] ={0};
    int epocas =0;
    int cantidad = 0;
    cin >> cantidad;
    redNeuronal* red = new redNeuronal(2, 3, 1, 0.01);
    while(epocas < cantidad){
        red->propagarAdelante(valoresEntrada1, valoresEsperados1);
        //red->imprimirRed();
        red->propagarError();
        //red->imprimirRed();
        red->propagarAdelante(valoresEntrada2, valoresEsperados2);
        //red->imprimirRed();
        red->propagarError();
        //red->imprimirRed();
        red->propagarAdelante(valoresEntrada3, valoresEsperados3);
        //red->imprimirRed();
        red->propagarError();
        //red->imprimirRed();
        red->propagarAdelante(valoresEntrada4, valoresEsperados4);
        //red->imprimirRed();
        red->propagarError();
        //red->imprimirRed();
        epocas++;

    }
        
        red->propagarAdelante(valoresEntrada1, valoresEsperados1);
        red->imprimirRed();
        red->propagarAdelante(valoresEntrada2, valoresEsperados2);
        red->imprimirRed();
        red->propagarAdelante(valoresEntrada3, valoresEsperados3);
        red->imprimirRed();
        red->propagarAdelante(valoresEntrada4, valoresEsperados4);
        red->imprimirRed();
        
        
    
    /*Grafo<float> grafo;
    float s = 500;
    float m = 1000;
    float g = 1500;
    float ss = 50000;
    grafo.insVertice(&s);
    grafo.insVertice(&m);
    grafo.insVertice(&g);

    grafo.setArco(0, 2, 5);
    grafo.setArco(0, 1, 2);
    grafo.setArco(2, 0, 55555);
    grafo.setVertice(0, &ss);

    grafo.imprimirGrafo();

    GrafoUtils::guardarGrafo(grafo, "C:/Users/Usuario/Desktop/grafo.txt");*/
    //Grafo<float> * grafo = GrafoUtils::cargarGrafo<float>("C:/Users/Usuario/Desktop/grafo.txt");
    /*float va = sumaPredecesores(*grafo, 2);
    cout << "VA: " << va;*/
    //cout << *grafo; //print overload

    /*float elemn = (*(grafo))[3]; Print sobrecarga de array
    cout << elemn;*/
    return 0;
}