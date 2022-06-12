#pragma once
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

template<typename type>
class Histograma
{
public:
	Histograma(std::vector<type>& v);
	~Histograma();
	void calcularIntervalo(int intervalo);
	std::vector<type> retornarIntervalo();

	const void mostrar_elementos();
	const void mostrar_intervalo();
private:
	int intervalo{};
	std::vector<type> v1, inter;
};



