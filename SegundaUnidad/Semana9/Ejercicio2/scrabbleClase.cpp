//scrabbleClase.cpp

#include <iostream>
#include "Scrabble.h"

int main()
{
    const std::string Nombres[] = {"Mario","Andre","Arturo","Joel","Veronica"};
    Scrabble* Jugadores = new Scrabble[5];
   
    for (int i = 0; i < 5; i++)
    {
        Jugadores[i].setName(Nombres[i]);
        Jugadores[i].generarFichasAleatorias();
        Jugadores[i].mostrarFichas();
    }

    delete [] Jugadores;
    return 0;
}

