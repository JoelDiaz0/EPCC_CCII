//Diamante.h

#pragma once
#include <iostream>

class Diamante
{
public:
	Diamante();
	Diamante(char letra);
	~Diamante();

	std::string generarDiamante();
	void setLetra(char letra);
	const void mostrar();	
private:
	bool validar_letra(char& l);
private:
	char letra {};
};



