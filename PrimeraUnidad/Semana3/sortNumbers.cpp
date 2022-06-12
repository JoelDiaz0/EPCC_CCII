//Your job is to write a program that reads integers from the standard input, 
//sorts them into ascending order, and then prints the sorted numbers, one per line.


#include <iostream>
#include <vector>
using namespace std;

void mostrar(vector <int>);

int main()
{
  int aux, num;

  vector <int> vec;

  do
  {
    cout<<"Ingrese numeros al vector y finalize el proceso ingresando '0': "; cin>>num;
    if (num!=0)
      vec.push_back(num);
  } while (num!=0);
  
  cout<<"***INICIAL***\n";
  mostrar(vec);
  
  for (int i=0; i<vec.size(); i++)
  {
    for (int j=i+1; j<vec.size(); j++)
    {
      if (vec.at(i)<vec.at(j))
      {
        aux=vec.at(i);
        vec.at(i)=vec.at(j);
        vec.at(j)=aux;
      }
    }   
  }

  cout<<"***DESCENDENTE***\n";
  mostrar(vec);

  return 0;
}

void mostrar(vector <int> v)
{
  for (auto i=v.begin(); i!=v.end(); i++)
  {
    cout<<*i<<" "<<endl;
  }
}

