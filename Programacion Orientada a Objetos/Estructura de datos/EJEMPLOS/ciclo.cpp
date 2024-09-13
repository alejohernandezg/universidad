#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void ejenmploSinBreak(){
	int i=0;
	int suma =0;
	cout << "...for sin break" << endl;
	for(i=0 ; i<100;i++);{
		suma +=i;
	}
	cout <<"El valor de la suma sin break es:"<<suma<<endl;
	
}
void funcion(){
	int num=0;
	int sumt=0;

	while (num != -1){
		cout << "Digite un numero:";
		cin >> num;
		if (num != -1){
			sumt += num;
		}
		
	}
	cout << "La sumatoria de los numero que introdujo es:" << sumt;

}

int main(){
	/*funcion();*/
	ejenmploSinBreak();

}

