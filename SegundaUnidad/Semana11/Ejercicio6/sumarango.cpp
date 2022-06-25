#include <iostream>

using std::cout;
using std::endl;

template<typename T>
T sumaRango(const T* array, int begin, int end, T opc = 0);

int main()
{
    const int tam = 10;
    int* array = new int[tam];

    for (int i = 0; i < tam; i++)
        array[i] = i+1;

    for (int i = 0; i < tam; i++)
        cout << array[i] << " ";

    cout << "\nLa suma desde la posicion 2 a la 5 es: " << sumaRango(array,2,5);

    cout << "\nLa suma desde la posicion 4 a la 6 con valor inicial 10 es: " << sumaRango(array,4,6,10);

    delete [] array;
    return 0;
}

template<typename T>
T sumaRango(const T* array, int begin, int end, T opc)
{
    T sum = array[begin] + opc;

    for (int i = begin + 1; i <= end; i++)
        sum += array[i]; 
    
    return sum;
}
