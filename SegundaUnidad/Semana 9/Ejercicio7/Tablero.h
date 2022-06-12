//Tablero.h

#pragma once
#include <iostream>
#include "Reina.h"
using std::cout;
using std::endl;

class Tablero
{
public:
	Tablero();
	~Tablero();
	bool reinasAtaque();
	void moverReinas(int x, int y, int x2, int y2);
	const void mostrar();
private:
	bool validarMovimiento(int x, int y);
	void actualizar();
private:
	char** M, f, c;
	Reina r1, r2;
};


