//Scrabble.h

#pragma once
#include <iostream>
#include "Ficha.h"

class Scrabble
{
public:
	Scrabble();
	~Scrabble();
	void generarFichasAleatorias();
	void setName(std::string nombre);
	const void mostrarFichas();
private:
	std::string nombre;
	Ficha* f1;
};



