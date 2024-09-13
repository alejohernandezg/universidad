#include "Structs.h"

int main()
{
	fish_t pirana1 = {"Snappy", "Piranha", 69, 4};
	fish_t pirana2;
	pirana2=llenarFish();
	cout << "Pirana 1" << endl;
	imprimirFish(pirana1);
	cout << "Pirana 2" << endl;
	imprimirFish(pirana2);
}
