//Escriba una función arePrimeFactors que tome un número entero n y un vector de números enteros,
//que devuelva true si los números en el vector son todos primos y su producto es n.

#include <iostream>
#include <vector>
using namespace std;

bool areFactors(vector <int>,int);

int main()
{
    int num;
    vector <int> vec;

    do
    {
        cout<<"Ingrese numeros y termine el proceso con '0': "; cin>>num;
        if (num != 0)
          vec.push_back(num);
    } while (num != 0);

    cout<<"Ingrese otro numero: "; cin>>num;

    cout<<"\n\n***MOSTRANDO VECTOR***\n\n";
    for (auto i = vec.begin(); i != vec.end(); i++)
       cout<<*i<<" ";
    cout<<endl<<endl;

    if (areFactors(vec,num))
       cout<<num<<" es factor de los numeros ingresados en el vector\n";
    else
       cout<<num<<" no es factor de los numero ingresados en el vector\n";

    return 0;
}

bool areFactors(vector <int> v,int n)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v.at(i)%n != 0)
          return false;
    }
    return true;
}