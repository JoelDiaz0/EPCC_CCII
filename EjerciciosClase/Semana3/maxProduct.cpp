/*Producto máximo de dos números en una secuencia
• Dada una secuencia de n números no negativos y mayores que cero. 
• El objetivo es encontrar el mayor número que se pueda obtener
multiplicando dos números*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int num, mayor1, mayor2;
  vector <int> vec;

  do
  {
    cout<<"Ingrese numeros mayores a cero y termine ingresado -1: " ; cin>>num;  
    if (num>0)
      vec.push_back(num);
    else if (num==-1)
      break;
    else
      cout<<"Ingrese un numero valido!\n";
  } while (num!=-1);

  mayor1=vec.front();
  mayor2=vec.back();

  if (vec.size()%2==0)
  {
    for (int i=0, j=vec.size()-1; i<=vec.size()/2&&j>=vec.size()/2; i++,j--)
    {
      if (mayor1<vec.at(i))
         mayor1=vec.at(i);
      if (mayor2<vec.at(j))
         mayor2=vec.at(j);
    }
  }

  else
  {
    for (int i=0, j=vec.size()-1; i<=(vec.size()/2)+1&&j>=vec.size()/2; i++,j--)
    {
      if (mayor1<vec.at(i))
         mayor1=vec.at(i);
      if (mayor2<vec.at(j))
         mayor2=vec.at(j);
    }
  }

  
  for (auto i=vec.begin(); i!=vec.end(); i++)
  {
    cout<<*i<<" ";
  }

  cout<<"\nEl mayor numero posible es: "<<mayor1*mayor2<<endl;
  
  
  return 0;
}
