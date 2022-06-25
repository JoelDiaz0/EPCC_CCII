#include "Cuadratico.h"

Cuadratico::Cuadratico()
{
	a = b = c = 0.f;
}

Cuadratico::Cuadratico(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

Cuadratico::Cuadratico(const Cuadratico& copia)
{
	this->a = copia.a;
	this->b = copia.b;
	this->c = copia.c;
}

Cuadratico::~Cuadratico()
{
}

float Cuadratico::calcular_fx(float x)
{
	return a * x * x + b * x + c;
}

Cuadratico& Cuadratico::operator=(const Cuadratico& c1)
{
	if (this != &c1)
	{
		a = c1.a;
		b = c1.b;
		c = c1.c;
	}
	return *this;
}