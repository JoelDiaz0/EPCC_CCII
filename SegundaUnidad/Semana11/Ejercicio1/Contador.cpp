#include "Contador.h"

unsigned int Contador::num_conta = 0;

Contador::Contador()
{
	cont = 0;
	num_conta++;
}

Contador::Contador(int cont)
{
	this->cont = cont;
	num_conta++;
}

Contador::~Contador()
{
	num_conta--;
}

Contador& Contador::operator++()
{
	this->cont++;
	return *this;
}

Contador Contador::operator++(int)
{
	int aux = this->cont;
	++* this;
	return aux;
}

int Contador::valor()
{
	return this->cont;
}

int Contador::num_Contadores()
{
	return this->num_conta;
}