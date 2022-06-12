//Ficha.cpp

#include "Ficha.h"

Ficha::Ficha()
{
	letra = 'a';
	valor = 0;
}

Ficha::Ficha(char letra, int valor)
{
	if (validarLetra(letra))
		this->letra = letra;
	else
		this->letra = 'a';
	this->valor = valor;
}

Ficha::~Ficha()
{
}

void Ficha::convertir_minus(char& L)
{
	L = std::tolower(L);
}

bool Ficha::validarLetra(char& L)
{
	//Uso de codigo ascii para aegurarse de que la variable letra, solo pueda contener letras
	convertir_minus(L);

	for (int i = 97; i < 123; i++)
	{
		if (i == L)
			return true;
	}
	return false;
}

