//Ficha.cpp

#include "Ficha.h"

Ficha::Ficha()
{
	num1 = 0; 
	num2 = 0;
}

Ficha::~Ficha()
{

}

void Ficha::generar_valor(int num1, int num2)
{
	this->num1 = num1;
	this->num2 = num2;
}

void Ficha::invertir()
{
	int aux;
	aux = num1;
	num1 = num2;
	num2 = aux;
}