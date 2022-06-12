//Ficha.h

#pragma once
#include <iostream>

class Ficha
{
public:
	friend class Domino;
	Ficha();
	~Ficha();	
private:
	void invertir();
	void generar_valor(int num1, int num2);
private:
	int num1{}, num2{};
};



