//maindomino.cpp

#include <iostream>
#include "Domino.h"

int main()
{
    Domino* d1 = new Domino();
    Domino* d2 = new Domino();

    d1->generar_n_fichas(7); //Genera la cantidad indicada con fichas aleatorias
    d1->mostrar();

    std::cout << "\n\n";
  
    d1->agrupar();
    d1->mostrar();

    if (d1->agrupacion_valida())
        std::cout << "Agrupacion valida\n";
    else
        std::cout << "Agrupacion no valida\n\n";

    d2->generar_manual(3, 2, 1, 2, 3, 1, 3);
    d2->mostrar();
    d2->agrupar();
    d2->mostrar();

    if (d2->agrupacion_valida())
        std::cout << "Agrupacion valida\n";
    else
        std::cout << "Agrupacion no valida\n";

    delete d1;
    return 0;
}

