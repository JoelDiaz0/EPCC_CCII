#pragma once
#include <iostream>
#include <vector>
#include "Ficha.h"

class Domino
{
public:
	Domino();
	~Domino();
	void generar_manual(int c,int m1, int m2, int m3, int m4, int m5, int m6);
	void generar_n_fichas(int cantidad);
	void agrupar();
	bool agrupacion_valida();
	const void mostrar();
private:
	bool no_repetir(std::vector<int>& v1, int x);
	char comprovar(Ficha& f1, Ficha& f2);
	bool comprovar2(Ficha& f1, Ficha& f2);
	void generar_fichas();
private:
	int cantidad_Max{};
	int cantidad{};
	Ficha* ftotal, * f1;
};



