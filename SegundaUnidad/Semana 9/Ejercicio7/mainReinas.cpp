//mainReinas.cpp

#include <iostream>
#include "Tablero.h"

int main()
{
    Tablero* t1 = new Tablero;

    t1->moverReinas(2, 3, 5, 6);
    t1->mostrar();

    if (t1->reinasAtaque())
        cout << "Se pueden atacar\n";
    else
        cout << "No se pueden atacar\n";

    delete t1;
    return 0;
}

