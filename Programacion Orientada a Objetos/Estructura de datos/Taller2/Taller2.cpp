//
// Created by ALEJANDRO on 12/03/2016.
//

#include "Taller2.h"

//FUNCIONES DEL PUNTO 1

void imprimirMatriz(int **matriz,int SIZE)
{
    for(int i =0; i < SIZE;i++)
    {
        for(int j=0; j<SIZE;j++)
        {
            cout << matriz[i][j] << ";" ;
        }
        cout << endl;
    }
    cout << endl;
}

int **crearMatriz(int SIZE)
{
    int **matriz;
    matriz = (int**) calloc (SIZE, sizeof(int*));
    for (int i = 0; i < SIZE; i++){
        matriz[i] = (int*) calloc (SIZE, sizeof(int));
    }
    return matriz;
}

void llenarMatriz(int **matriz,int SIZE)
{
    for(int i =0; i < SIZE;i++)
    {
        for(int j=0; j<SIZE;j++)
        {
            cout << "Digite el numero entero en la posicion " << i+1 << "."<< j+1 << " de la matriz:" << endl;
            cin >> matriz[i][j];
        }
    }
}



int contarRepeticiones(int arreglo[],int elem, int SIZE)
{
    int contador=0;
    for(int i=0;i<SIZE;i++)
    {
        if(elem == arreglo[i])
        {
            contador++;
        }
    }
    return contador;
}
bool contains(int arreglo[],int elem,int SIZE)
{
    for(int i=0;i<SIZE;i++)
    {
        if(arreglo[i]==elem)
        {
            return true;
        }
    }
    return false;
}
bool contains2(int arreglo[],int elem,int SIZE)
{
    for(int i=1;i<SIZE;i++)
    {
        if(arreglo[i]==elem)
        {
            return true;
        }
    }
    return false;
}

void addElem(int elem, int arreglo[],int SIZE)
{
    for(int i=1; i<SIZE;i++)
    {
        arreglo[i] = elem ;
    }
}
int compararArreglo(int **matriz,int fila,int SIZE)
{
    int total=0;
    int * arregloComparar = (int *) malloc(SIZE * sizeof(int));

    for(int j=0;j<SIZE;j++)
    {
        if(!contains(arregloComparar,matriz[fila][j],SIZE))
        {
            if(contarRepeticiones(matriz[fila],matriz[fila][j],SIZE)<3)
            {
                total++;
            }
            arregloComparar[j] = matriz[fila][j];
        }
    }
    return total;
}

void agregarElementos(int arreglo[],int arreglo2[],int SIZE, int SIZE2)
{
    for (int i = 0; i < SIZE ; ++i)
    {
        if(contarRepeticiones(arreglo,arreglo[i],SIZE2)<3)
        {
            for (int j = 1; j < SIZE2; ++j)
            {
                arreglo2[j]=arreglo[i];
            }
        }
    }
}

void sacarRepetidos(int **matriz,int SIZE, int **matrizResultado)
{
    for (int i = 0; i < SIZE; i++)
    {
        int SIZE2 = compararArreglo(matriz,i,SIZE);
        SIZE2++;
        matrizResultado[i] = (int*) calloc (SIZE2, sizeof(int));
        for(int j=0;j<SIZE2;j++)
        {
            if(!contains2(matrizResultado[i],matriz[i][j],SIZE2)&&contarRepeticiones(matriz[i],matriz[i][j],SIZE2)<3)
            {
               addElem(matriz[i][j],matrizResultado[i],SIZE2);
            }

        }

        cout << "Fila:"<< i <<" Size: "<<SIZE2 << endl;
        matrizResultado[i][0] = SIZE2;
       //agregarElementos(matriz[i],matrizResultado[i],SIZE,SIZE2);

    }
}



//FUNCIONES DEL PUNTO2
void iniciarArreglo(nadador_t arreglo[],int SIZE)
{

    for(int i=0;i<SIZE;i++)
    {
        arreglo[i].nombre = "vacio";
        arreglo[i].edad =0;
        arreglo[i].tipoPrueba ="vacio";
        arreglo[i].tiempoMin =0;
        arreglo[i].tiempoSeg = 0;
    }
}

void llenarArreglo(nadador_t arreglo[],int SIZE)
{
    for(int i =0;i < SIZE; i++)
    {

        cout << "Competidor " << i << endl;
        cout << "NOMBRE:" << endl;
        cin >> arreglo[i].nombre;
        cout << "EDAD:"<<endl;
        cin >> arreglo[i].edad;
        cout << "TIPO DE PRUEBA:" << endl;
        cin >> arreglo[i].tipoPrueba;
        cout << "MINUTOS:" << endl;
        cin >> arreglo[i].tiempoMin;
        cout << "SEGUNDOS:" << endl;
        cin >> arreglo[i].tiempoSeg;
    }
}

bool simetrico(nadador_t arreglo[], int SIZE)
{
    int i=0;
    int j=SIZE-1;

    while(i!=j)
    {

        if(arreglo[i].edad == arreglo[j].edad)
        {
            if(i+1==j)
            {
                break;
            }
            i++;
            j--;
            break;
        }
        else{
            return false;
        }
    }
    return true;
}

void imprimirArreglo(nadador_t arreglo[], int SIZE)
{
    for(int i=0;i<SIZE;i++)
    {
        cout << "Competidor: "<< i << endl;
        cout << "Nombre: "<<arreglo[i].nombre << endl;
        cout << "Edad: "<<arreglo[i].edad<< endl;
        cout << "Tipo de prueba: "<<arreglo[i].tipoPrueba<< endl;
        cout << "Minutos: " <<arreglo[i].tiempoMin << endl;
        cout << "Segundos: "<<arreglo[i].tiempoSeg << endl;
        cout << endl;
    }
}

