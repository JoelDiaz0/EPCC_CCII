#include <iostream>
#include <bitset>
using namespace std;
 
bitset<700001> Primes;
void Sieve(int n)
{
    Primes[0] = 1;
    for (int i = 3; i*i <= n; i += 2) 
    {
        if (Primes[i / 2] == 0) 
        {
            for (int j = 3 * i; j <= n; j += 2 * i)
                Primes[j / 2] = 1;
        }
    }
}
int main()
{
    int n;
    cout<<"Hasta que numero quiere buscar numeros primos?: "; cin>>n;

    Sieve(n);
    for (int i = 1; i <= n; i++) 
    {
        if (i == 2)
            cout << i << ' ';
        else if (i % 2 == 1 && Primes[i / 2] == 0)
            cout << i << ' ';
    }
    return 0;
}