#include <iostream>
#include "Contador.h"
using std::endl;
using std::cout;

int main()
{
    Contador c1(15), c2(5), c3(3), c4;

    cout << "Cantidad de objetos Contador creados: " << c1.num_Contadores() << endl;
    
    Contador c5;

    cout << "Cantidad de objetos Contador creados: " << c2.num_Contadores() << endl;
    
    c1 = c2++;
    
    cout << "c1 = " << c1.valor() << endl;
    cout << "c2 = " << c2.valor() << endl;

    c1 = ++c3;

    cout << "c1 = " << c1.valor() << endl;
    cout << "c3 = " << c3.valor() << endl;

    Contador c6;

    cout << "Cantidad de objetos Contador creados: " << c2.num_Contadores() << endl;

    return 0;
}


