//TABLAS

#include <iostream>
using namespace std;

int main()
{
    int num=1, fila;

    cout<<"Ingrese la cantidad de filas para la tabla: "; cin>>fila;

    cout<<"--------------------------\n";
    for (int i=1; i<fila+1; i++)
    {
        cout<<"  :    ";
        for (int j=i; j<(fila+1)*i; j+=i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}