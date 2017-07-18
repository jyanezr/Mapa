#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream archivo("mapa.txt");
    //char **matriz = NULL;
    if(archivo.fail())
        cerr << "Can't open" << endl;
    else
    {
        cout << "OK" << endl;
    }

	system("pause");
	return 0;
}
