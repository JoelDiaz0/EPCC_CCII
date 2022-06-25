#include "Racional.h"

Racional::Racional()
{
	x_num = 0;
	y_den = 1;
}

Racional::Racional(int x_num, int y_den)
{
	if (y_den == 0)
	{
		this->x_num = 0;
		this->y_den = 1;
		throw std::runtime_error("El denominador no puede ser 0!");
	}
	else if (!coprimos(x_num,y_den))
	{
		this->x_num = 0;
		this->y_den = 1;
		throw std::invalid_argument("No son coprimos!");
	}
	else
	{
		this->y_den = y_den;
		this->x_num = x_num;
	}
}

Racional::Racional(const Racional& copia)
{
	x_num = copia.x_num;
	y_den = copia.y_den;
}

Racional::~Racional()
{

}

double Racional::valor_aproximado()
{
	double result = (x_num * 1.0) / (y_den * 1.0);
	return result;
}

bool Racional::coprimos(int x_num, int y_den)
{
	std::vector<int> v1, v2, v3;

	divisores(v1, x_num);
	divisores(v2, y_den);

	std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));

	if (v3.empty())
		return true;
	return false;
}

void Racional::divisores(std::vector<int>& v1, int num)
{
	for (int x = 2; x <= num; x++)
	{
		if (num % x == 0)
			v1.push_back(x);
	}
}

Racional& Racional::operator=(const Racional& r1)
{
	if (this != &r1)
	{
		x_num = r1.x_num;
		y_den = r1.y_den;
	}
	return *this;
}

Racional& Racional::operator+=(const Racional& r1)
{
	x_num += r1.x_num;
	y_den += r1.y_den;
	return *this;
}

Racional& Racional::operator-=(const Racional& r1)
{
	x_num -= r1.x_num;
	y_den -= r1.y_den;
	return *this;
}

Racional& Racional::operator*=(const Racional& r1)
{
	x_num *= r1.x_num;
	y_den *= r1.y_den;
	return *this;
}

Racional& Racional::operator/=(const Racional& r1)
{
	x_num /= r1.x_num;
	y_den /= r1.y_den;
	return *this;
}

std::istream& operator>>(std::istream& i, Racional& r1)
{
	std::cout << "Ingrese el numerador: "; i >> r1.x_num;
	std::cout << "\nIngrese el denominador: "; i >> r1.y_den;

	if (!r1.coprimos(r1.x_num, r1.y_den))
	{
		std::cerr << "No son Coprimos!\n";
		exit(1);
	}

	else if (r1.y_den == 0)
	{
		std::cerr << "El denominador no puede ser 0!\n";
		exit(1);
	}

	i.ignore();
	return i;
}


std::ostream& operator<<(std::ostream& o, Racional& r1)
{
	o << r1.x_num << "/" << r1.y_den;
	return o;
}