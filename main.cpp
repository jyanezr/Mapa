#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream archivo("mapa.txt");
    char matriz[20][71];
    int pos1=0, pos2=0, pos3=0, pos4=0;

    if(archivo.fail())
        cerr << "Can't open" << endl;
    else
    {
        for(int i=0; i<20; i++)
        {
            for(int j=0; j<71; j++)
            {
                archivo.read(&matriz[i][j],1);
                if(matriz[i][j] == '1'){
                    pos1 = i; pos2 = j;
                }else if(matriz[i][j] == '2'){
                    pos3 = i; pos4 = j;
                }
            }
        }
        if(pos1 < pos3 && pos2 < pos4){ //Si 1 esta arriba-izquierda y 2 abajo-derecha.
            do{
                pos2++;
                matriz[pos1][pos2] = '*';
            }while(pos2 < pos4);
            do{
                matriz[pos1][pos4] = '*';
                pos1++;
            }while(pos1 < pos3);
        }else
        if(pos3 < pos1 && pos2 < pos4){ //Si 1 esta abajo-izquierda y 2 esta arriba-derecha.
            do{
                pos2++;
                matriz[pos1][pos2] = '*';
            }while(pos2 < pos4);
            do{
                pos3++;
                matriz[pos3][pos4] = '*';
            }while(pos3 < pos1);
        }else
        if(pos3 < pos1 && pos4 < pos2){ //Si 2 esta arriba-izquierda y 1 abajo-derecha.
            do{
                pos4++;
                matriz[pos3][pos4] = '*';
            }while(pos4 < pos2);
            do{
                matriz[pos3][pos2] = '*';
                pos3++;
            }while(pos3 < pos1);
        }else
        if(pos1 < pos3 && pos4 < pos2){ //Si 2 esta abajo-izquierda y 1 arriba-derecha.
            do{
                pos4++;
                matriz[pos3][pos4] = '*';
            }while(pos4 < pos2);
            do{
                pos1++;
                matriz[pos1][pos2] = '*';
            }while(pos1 < pos3);
        }else
        if(pos1 == pos3 && pos2 < pos4){ //Ambos numeros en la misma fila con 1 antes que 2.
            while(pos2 < pos4-1){
                pos2++;
                matriz[pos1][pos2] = '*';
            }
        }else
        if(pos3 == pos1 && pos4 < pos2){ //Ambos numeros en la misma fila con 2 antes que 1.
            while(pos4 < pos2-1){
                pos4++;
                matriz[pos3][pos4] = '*';
            }
        }else
        if(pos2 == pos4 && pos1 < pos3){ //Ambos numeros en la misma columna con 1 antes que 2.
            while(pos1 < pos3-1){
                pos1++;
                matriz[pos1][pos2] = '*';
            }
        }else
        if(pos4 == pos2 && pos3 < pos1){ //Ambos numeros en la misma columna con 2 antes que 1.
            while(pos3 < pos1-1){
                pos3++;
                matriz[pos3][pos4] = '*';
            }
        }
    }
    for(int i=0; i<20; i++){ //Imprime matriz modificada
        for(int j=0; j<71; j++){
            cout << matriz[i][j];
        }
    }
    archivo.close();
    return 0;
}
