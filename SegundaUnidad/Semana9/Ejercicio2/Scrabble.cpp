//Scrabble.cpp

#include "Scrabble.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<>rand_digits(97,122);

//std::uniform_int_distribution<char>rand_ascii('a','z'); 
//static_assert failed: invalid template argument for uniform_int_distribution

Scrabble::Scrabble()
{
	f1 = new Ficha[7];
	nombre = "Anonimo";
}

Scrabble::~Scrabble()
{
	delete[] f1;
}

void Scrabble::setName(std::string nombre)
{
	this->nombre = nombre;
}

void Scrabble::generarFichasAleatorias()
{
	char aux;
	for (int i = 0; i < 7; i++)
	{
		aux = rand_digits(gen);
		f1[i].letra = aux;
		f1[i].valor = i;
	}
}

const void Scrabble::mostrarFichas()
{
	std::cout << "Nombre: " << nombre << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << "Letra " << i + 1 <<": "<<"'"<< f1[i].letra << "' Valor: " << f1[i].valor << std::endl;
}


