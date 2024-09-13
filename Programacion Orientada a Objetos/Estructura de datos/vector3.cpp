
#include <iostream>
#include <string>
#include <initializer_list>
using namespace std;

template <typename T>
class Vector {
  public:
    
   Vector(int nElem=10);               // constructor ordinario
   Vector(initializer_list<T> lst);      //constructor con lista 
   Vector(const Vector& original);     //constructor con copia
   Vector (Vector && original);        //constructor de traslado

   Vector& operator =(const Vector &fuente); // asignacion, se borra el destino y se copia
  Vector operator=(Vector&& fuente);  //asignación para traslado. borra el destino y mueve

 // otras operaciones
   T& operator[](int indice) { return vec[indice]; }

   // la destructora
   ~Vector();

   //otras operaciones
   template <typename Q>friend  Vector<Q> operator +(Vector<Q> &a, Vector<Q> &b); // observe que se retorna por valor
   static int totalEjemplares(){return numEjemplares;} // debe ser una función static
   template <typename Q> friend ostream& operator <<(ostream &os, Vector<Q> &v);  
  private:
   int nElementos;
   T *vec;
 static int numEjemplares;// podemos ponerlo privado y definir una fx que retorne su valor.
  

  };

// Definición:
template <typename T>
int Vector<T>::numEjemplares=0;           //definción de una var static

template <typename T>
Vector<T>::Vector(int nElem) : nElementos(nElem) {
   vec = new T[nElementos];
   ++numEjemplares;
}

template <typename T>
Vector <T>::Vector(initializer_list<T> lst): 
   nElementos(lst.size()){ // vec no queda inicializado

   vec = new T[nElementos];
   uninitialized_copy(lst.begin(), lst.end(), vec);

  /* //de forma manual 
    auto q = vec;
   for(auto x : lst){
        *q = x; q++;
   }
*/
   ++numEjemplares;

}
template <typename T>
Vector<T>::Vector(const Vector& original):     //constructor con copia
 nElementos(original.nElementos),
 vec{new T[original.nElementos]}
{
   uninitialized_copy(original.vec,original.vec+nElementos,vec);
   ++ numEjemplares;   
}

template <typename T>
Vector<T>::Vector(Vector &&original):        //constructor de traslado
nElementos(original.nElementos),vec(original.vec) // se toman los datos de original.
// observe que se copia el apuntador vec.
// cómo sabe el compilador o el usuario cuando usar esto??
{
   original.nElementos = 0; // limpia el vector original.
   original.vec = nullptr; 
}


template <typename T>
Vector<T>& Vector<T>::operator =(const Vector &fuente) // asignacion, se borra el dest
{

   if(nElementos != fuente.nElementos){
      delete[] vec;
      vec = new T[fuente.nElementos];
      nElementos = fuente.nElementos;
   }
   uninitialized_copy(fuente.vec,fuente.vec+nElementos,vec);   
   return *this;
}

template <typename T>
void miSwap(T& a, T& b) // tomado de C++Programing language,stroutrup pg 516
// intercambia sin hacer copias.Ideal para clases con gran número de elem.
{
      T tmp = move(a);
      a = move(b);
      b = move(tmp);
}
template <typename T>
Vector<T> Vector<T>::operator =(Vector<T>&& fuente)  //asignación para traslado. borra el destino y mueve
// lo usa el compilador cuando ve que la fuente será destruida en la siguiente línea. Por ejemplo en una instruccion: Return unVec; 
{
   if(this != &fuente){       //que no sea el mismo objeto
      miSwap(nElementos,fuente.nElementos);
      miSwap(vec,fuente.vec); 
   }
   return *this;  

}  


template <typename T>
Vector<T>::~Vector() {
   --numEjemplares;
   delete[] vec;
}

// Otras operaciones

template <typename Q>
Vector<Q> operator +(Vector<Q> &a,  Vector<Q> &b){ // observe que se retorna por valor
   Vector<Q> resp(a.nElementos+b.nElementos);
   int j=0;
   for(int i=0; i < a.nElementos; i++,j++)
           resp.vec[j] = a.vec[i];

   for(int i=0; i < b.nElementos; i++,j++)
           resp.vec[j] = b.vec[i];
    
   return resp;   
// aqui utiliza asignación con traslado.
// se hace un "swap" entre el el objeto que llama y resp. 
// al salir de la función resp es destruida con la info del "objeto llamador"
   
}

template <typename  Q>
ostream& operator<<(ostream &os, Vector<Q> &v){

 for(int i=0; i < v.nElementos; i++)
     cout << v[i] << " ";    // aunque sería mas eficiente: cout << v.vec[i] << " ";
  return os;

}



int main() {
   Vector<int> unVecInt(10);
      
   Vector<string> nombres(3);

   Vector<int> otroVecInt={1,2,3,4};

   Vector<int> copia=otroVecInt;
   cout<< "ejemplares: "<< Vector<int>::totalEjemplares()<< endl;

   cout<< "ejemplares: "<< Vector<string>::totalEjemplares()<< endl;

     for(int i = 0; i < 10; i++)
      unVecInt[i] = 10-i;
 

   cout << " impreso con sobrecarga\n";
   cout << unVecInt;
   cout <<"\n impreso con metodos convencionales:\n" ; 


   for(int i = 0; i < 10; i++)
      cout << unVecInt[i] << " ";

   
   copia = unVecInt;
   cout << endl;
   for(int i = 0; i < 10; i++)
      cout << copia[i] << endl;

   otroVecInt = unVecInt + copia;

     
/* for(int i = 0; i < 3; i++){
   cout << "nombre" << " : " ;   
   cin >> nombres[i];
      
   }
*/

 cout << "concatenando" << endl;
  for(int i = 0; i < 20; i++)
     cout << otroVecInt[i] << "  "; 

      cout <<endl;



   return 0;
}
