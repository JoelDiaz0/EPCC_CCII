//Escriba una función arePrimeFactors que tome un número entero n y un vector de números enteros, que devuelva true
//si los números en el vector son todos primos y su producto es n.

#include <iostream>
#include <vector>
using namespace std;

bool arePrimeFactors(vector <int>,int);
bool arePrime(int);

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

    if (arePrimeFactors(vec,num))
        cout<<num<<" si es un factor primo\n";
    else
        cout<<num<<" no es un factor primo\n";

    return 0;
}

bool arePrime(int x)
{
    int c = 0;

    for (int i = 1; i < x+1; i++)
    {
        if (x%i == 0)
          c++;
    }

    if (c == 2)
      return true;
    return false;
}

bool arePrimeFactors(vector <int> v,int x)
{
    int multi = 1;

    for (int i = 0; i < v.size(); i++)
    {
        if (arePrime(v.at(i)) == false)
           return false;
    }
        
    for (int i = 0; i < v.size(); i++)
        multi *= v.at(i);

    if (x == multi)
        return true;

    return false;
}