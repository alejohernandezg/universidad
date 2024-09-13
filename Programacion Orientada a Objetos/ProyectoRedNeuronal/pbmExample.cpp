#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



struct PPMObject
{
  std::string magicNum;
  int ancho, largo, maxColor;
  char * C_imagen;
};



class imagenBin
{
	int col;
	int fil;
	int **pm;

	public:

	imagenBin crearMatrizImagen(PPMObject &other);
	void imprimir();
	vector<int> patronImagen(); 


};
imagenBin imagenBin::crearMatrizImagen(PPMObject &other)
{
	col = other.largo;
	fil = other.ancho*3;
	pm = new  int* [col];
	for(int i = 0; i < col ; i++)
	{
		pm[i] = new int [fil];
	}
	int j = 0;
	int p = 0;
	   for (int i = 0; i < col*fil; i ++) 
	 	{
		    if(((other.C_imagen[i] & 0xff) + ((other.C_imagen[i] >> 8 & 0xff) + ((other.C_imagen[i] >> 16) & 0xff))/3 > 127))
		    	pm[p][j]=0;
		    else
		    	pm[p][j]=1;

		    if(j== fil)
		    {
		    	j = 0;
		    	p++;
		    }
		    j++;
		}
}

void imagenBin::imprimir()
{
	for(int i = 0; i < col; i++)
    {
    	for(int j = 1; j < fil; j++)
    	{
    		cout<<pm[i][j];
    	}
    	cout<<endl;
    }
}

vector<int> imagenBin::patronImagen()
{
	
	int patron =0;
	vector<int> vectorPatron;
	for (int j = 2; j < col; j+=2)
	{
		patron =0;
		for (int i = 1; i < fil; ++i)
		{

			if (i+1<fil)
			{
				if(pm[j][i]==1 && pm[j][i+1]==0)
				{
				patron++;
				}
			}
			
		}
		cout << "Patron:" << patron;
		vectorPatron.push_back (patron);
	}
	
	

}


std::istream& operator >>(std::istream &inputStream, PPMObject &other)
{
    inputStream >> other.magicNum;
    inputStream >> other.ancho >> other.largo >> other.maxColor;
    inputStream.get(); // skip the trailing white space
    size_t size = other.ancho * other.largo * 3;
    other.C_imagen = new char[size];
    inputStream.read(other.C_imagen, size);

    return inputStream;
}


std::ostream& operator <<(std::ostream &outputStream, const PPMObject &other)
{
    outputStream << "P6"     << "\n"
        << other.ancho       << " "
        << other.largo      << "\n"
        << other.maxColor   << "\n"
       ;
    size_t size = other.ancho * other.largo * 3;
 

    outputStream.write(other.C_imagen, size);

    

    return outputStream;
}

/*imagenBin crearMatrizImagen(PPMObject &other)
{
	int matriz[other.largo][other.ancho *3];
	int j = 0;
	int p = 0;
    for (int i = 0; i < other.ancho*other.largo*3; i ++) {
    	if((other.C_imagen[i] & 0xff) + ((other.C_imagen[i] >> 😎 & 0xff) + ((other.C_imagen[i] >> 16) & 0xff)/3 > 127)
    		matriz[p][j]=0;
    	else
    		matriz[p][j]=1;

    	if(j== other.ancho*3)
    	{
    		cout <<endl;
    		j = 0;
    		p++;
    	}
    	
    	j++;

    }
    return 
    /*for(int i = 0; i < other.largo; i++)
    {
    	for(int j = 0; j < other.ancho*3; j++)
    	{
    		cout<<matriz[i][j];
    	}
    	cout<<endl;
    }*/



int main ()
{
    PPMObject ppmObject = PPMObject();
    std::ifstream image;
    std::ofstream outFile;
    image.open("1.ppm", std::ios::binary);
    image >> ppmObject;

    //image.clear();
    //image.close();

    /*outFile.open("peneNuevo.ppm", std::ios::binary);
    outFile << ppmObject;

    outFile.clear();
    outFile.close();*/

    imagenBin matriz_imagen; 
    matriz_imagen.crearMatrizImagen(ppmObject);
    matriz_imagen.imprimir();
    matriz_imagen.patronImagen();


    return 0;
}