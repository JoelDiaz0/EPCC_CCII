#include "Histograma.h"

template<typename type>
Histograma<type>::Histograma(std::vector<type>& v)
{
	v1 = v;
	intervalo = 1;
}

template<typename type>
Histograma<type>::~Histograma()
{
}

template<typename type>
void Histograma<type>::calcularIntervalo(int intervalo)
{
	if (intervalo < 1 || intervalo > v1.size())
	{
		std::cerr << "Intervalo mayor que el total de elementos del vector, 0 o negativo!\n";
		exit(1);
	}
	this->intervalo = intervalo;

	int rango_min = 1;
	int rango_max = v1.size() / this->intervalo;
	int c = 0;

	for (int i = 0; i < this->intervalo; i++)
	{
		for (int j = 0; j < v1.size(); j++)
		{
			if (v1.at(j) >= rango_min && v1.at(j) <= rango_max)
				c++;
		}
		inter.push_back(c);
		rango_max += v1.size() / this->intervalo;
		rango_min += v1.size() / this->intervalo;
		c = 0;
	}
}

template<typename type>
std::vector<type> Histograma<type>::retornarIntervalo()
{
	return inter;
}

template<typename type>
const void Histograma<type>::mostrar_elementos()
{
	cout << "{";
	for (auto p : v1 )
		cout << p << ",";
	cout << "}" << endl << endl;
}

template<typename type>
const void Histograma<type>::mostrar_intervalo()
{
	cout << "{";
	for (auto p : inter)
		cout << p << ",";
	cout << "}" << endl << endl;
}