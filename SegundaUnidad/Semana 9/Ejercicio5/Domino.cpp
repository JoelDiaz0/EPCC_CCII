//Domino.cpp

#include "Domino.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<>rand_digits(0, 27);

Domino::Domino()
{
	cantidad_Max = 28;
	ftotal = new Ficha[cantidad_Max];
	generar_fichas();
}

Domino::~Domino()
{
	delete[] f1, ftotal;
}

void Domino::generar_fichas()
{
	int aux_cant{ 0 }, num1{ 0 }, num2{ 0 }, c{ 7 };

	while (aux_cant < cantidad_Max)
	{
		for (int i = 0; i < c; i++)
		{
			if (aux_cant == cantidad_Max)
				break;
			ftotal[aux_cant].generar_valor(num1, num2+i);
			aux_cant++;
		}
		num1++;
		num2++;
		c--;
	}
}

bool Domino::no_repetir(std::vector<int>& v1, int x)
{
	if (v1.empty())
		return true;
	for (auto u : v1)
	{
		if (u == x)
			return false;
	}
	return true;
}

char Domino::comprovar(Ficha& f1, Ficha& f2)
{
	if (f1.num2 == f2.num1)
		return 'A';
	if (f1.num1 == f2.num2)
		return 'B';
	if (f1.num1 == f2.num1)
		return 'C';
	if (f2.num2 == f2.num2)
		return 'D';
	return 'F';
}

bool Domino::comprovar2(Ficha& f1, Ficha& f2)
{
	if (f1.num2 == f2.num1)
		return true;
	return false;
}

void Domino::generar_n_fichas(int cantidad)
{
	if (cantidad < 1 || cantidad > 28)
	{
		std::cerr << "Error, ingreso un valor negativo o mayor a 28!\n";
		exit(1);
	}
	this->cantidad = cantidad;

	f1 = new Ficha[cantidad];
	std::vector<int> v1;

	int aux_cant{ 0 }, c{ 0 };

	while (aux_cant < cantidad)
	{
		for (int j = 0; j < 28; j++)
		{
			if (j == rand_digits(gen) && no_repetir(v1, j))
			{
				if (aux_cant == cantidad)
					break;
				f1[aux_cant].generar_valor(ftotal[j].num1, ftotal[j].num2);
				aux_cant++;
				v1.push_back(j);
			}
		}
	}
}

void Domino::agrupar()
{
	Ficha aux;
	for (int i = 0; i < cantidad - 1; i++)
	{
		for (int j = i + 1; j < cantidad; j++)
		{
			if (comprovar(f1[i], f1[j]) == 'A' && comprovar2(f1[i],f1[i+1]) == false)
			{
				aux.num1 = f1[i + 1].num1;
				aux.num2 = f1[i + 1].num2;

				f1[i + 1].num1 = f1[j].num1;
				f1[i + 1].num2 = f1[j].num2;

				f1[j].num1 = aux.num1;
				f1[j].num2 = aux.num2;
			}
			else if (comprovar(f1[i], f1[j]) == 'B' && comprovar2(f1[i], f1[i + 1]) == false)
			{
				aux.num1 = f1[i + 1].num1;
				aux.num2 = f1[i + 1].num2;

				f1[i].invertir();
				f1[j].invertir();

				f1[i + 1].num1 = f1[j].num1;
				f1[i + 1].num2 = f1[j].num2;

				f1[j].num1 = aux.num1;
				f1[j].num2 = aux.num2;
			}
			else if (comprovar(f1[i], f1[j]) == 'C' && comprovar2(f1[i], f1[i + 1]) == false)
			{
				aux.num1 = f1[i + 1].num1;
				aux.num2 = f1[i + 1].num2;

				f1[i].invertir();

				f1[i + 1].num1 = f1[j].num1;
				f1[i + 1].num2 = f1[j].num2;

				f1[j].num1 = aux.num1;
				f1[j].num2 = aux.num2;
			}
			else if (comprovar(f1[i], f1[j]) == 'D' && comprovar2(f1[i],f1[i+1]) == false)
			{
				aux.num1 = f1[i + 1].num1;
				aux.num2 = f1[i + 1].num2;

				f1[j].invertir();

				f1[i + 1].num1 = f1[j].num1;
				f1[i + 1].num2 = f1[j].num2;

				f1[j].num1 = aux.num1;
				f1[j].num2 = aux.num2;
			}
		}
	}
}

bool Domino::agrupacion_valida()
{
	for (int i = 0; i < cantidad-1; i++)
	{
		if (comprovar2(f1[i], f1[i + 1]) == false)
			return false;	
	}
	if (f1[0].num1 != f1[cantidad].num2)
		return false;
	return true;
}

const void Domino::mostrar()
{
	for (int i = 0; i < cantidad; i++)
		std::cout << "[" << f1[i].num1 << "|" << f1[i].num2 << "]" << " ";
	std::cout << "\n";
}

void Domino::generar_manual(int c, int m1, int m2, int m3, int m4, int m5, int m6)
{
	cantidad = c;
	f1 = new Ficha[cantidad];
	f1[0].generar_valor(m1, m2);
	f1[1].generar_valor(m3, m4);
	f1[2].generar_valor(m5, m6);
}