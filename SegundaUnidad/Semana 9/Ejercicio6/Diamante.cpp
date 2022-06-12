//Diamante.cpp

#include <sstream>
#include "Diamante.h"
using std::cout;
using std::endl;

Diamante::Diamante()
{
	this->letra = 'A';
}

Diamante::Diamante(char letra)
{
	if (validar_letra(letra))
		this->letra = letra;
	else
	{
		cout << "No ingreso una letra" << endl;
		this->letra = 'A';
	}
}

Diamante::~Diamante()
{
}

bool Diamante::validar_letra(char& l)
{
	l = towupper(l);
	if (l > 90 || l < 65)
		return false;
	return true;
}

void Diamante::setLetra(char letra)
{
	if (validar_letra(letra))
		this->letra = letra;
	else
	{
		cout << "No ingreso una letra" << endl;
		this->letra = 'A';
	}
}

std::string Diamante::generarDiamante()
{
	std::string diamante;
	std::stringstream ss;
	int num_asteriscos = letra - 65;
	int asteriscos_centro = 0;

	char i = 65;

	while (i <= letra)
	{ 
		for (int j = 0; j < num_asteriscos; j++)
			ss << "*";
		if (asteriscos_centro > 0)
		{
			ss << i;
			for (int j = 0; j < asteriscos_centro; j++)
				ss << "*";
			ss << i;
			asteriscos_centro++;
		}
		else
			ss << i;
		for (int j = 0; j < num_asteriscos; j++)
			ss << "*";

		ss << "\n";
		num_asteriscos--;
		asteriscos_centro++;
		i++;
	}

	i -= 2;
	num_asteriscos = 1;
	asteriscos_centro -= 4;

	while (i >= 'A')
	{
		for (int j = 0; j < num_asteriscos; j++)
			ss << "*";
		if (asteriscos_centro > 0)
		{
			ss << i;
			for (int j = 0; j < asteriscos_centro; j++)
				ss << "*";
			ss << i;
			asteriscos_centro--;
		}
		else
			ss << i;
		for (int j = 0; j < num_asteriscos; j++)
			ss << "*";

		ss << "\n";
		num_asteriscos++;
		asteriscos_centro--;
		i--;
	}

	diamante = ss.str();
	return diamante;
}

const void Diamante::mostrar()
{
	cout << generarDiamante();
}