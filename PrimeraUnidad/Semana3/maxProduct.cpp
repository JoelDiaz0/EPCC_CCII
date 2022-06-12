/*Producto máximo de dos números en una secuencia
• Dada una secuencia de n números no negativos y mayores que cero. 
• El objetivo es encontrar el mayor número que se pueda obtener
multiplicando dos números*/

#include <iostream>
using namespace std;

int main()
{
  int mayor1 = 0, mayor2 = 0, N;

  cout<<"Ingrese la cantidad de numeros que quiere ingresar: "; cin>>N;

  for (int i = 0; i < N; i++)
  {
    int num;
    cout<<"Ingrese un numero ["<<i+1<<"]: "; cin>>num;
    if (num > mayor1)
    {
      mayor2 = mayor1;
      mayor1 = num;
    }
    if (num > mayor2 && num < mayor1)
    {
      mayor2 = num;
    }
  }
  cout<<"El mayor numero que se puede obtener multiplicando de los valores ingresados es: "<<mayor1*mayor2<<endl;
  return 0;
}
