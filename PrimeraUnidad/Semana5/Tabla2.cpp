//Reescriba el ejercicio de la tabla de multiplicación usando funciones.

#include <iostream>
using namespace std;

void generar_tabla(int);

int main()
{
    int fila{};
    cout<<"Ingrese el rango maximo de la tabla de multiplicar: "; cin>>fila;
    generar_tabla(fila);

    return 0;
}

void generar_tabla(int x)
{
    cout<<"----*----------------------\n";
    for (int i=1; i<x+1; i++)
    {
        cout<<i<<"   :    ";
        for (int j=i; j<(x+1)*i; j+=i)
            cout<<j<<" ";
        cout<<endl;
    }    
}