//histogramaTemplate.cpp

#include <iostream>
#include <vector>
#include "Histograma.h"

int main()
{
    std::vector<int> myvector = { 10,2,9,7,5,6,1,8,8,4 };
    Histograma<int> h1(myvector);

    h1.calcularIntervalo(5);
    h1.mostrar_elementos();
    h1.mostrar_intervalo();

    return 0;
}

