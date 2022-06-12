//Ficha.h

#pragma once
#include <iostream>

class Ficha
{
public:
	friend class Scrabble;
	Ficha();
	Ficha(char letra, int valor);
	~Ficha();
private:
	void convertir_minus(char& L);
	bool validarLetra(char& L);
private:
	char letra;
	int valor;
};



