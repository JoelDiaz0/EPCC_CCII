#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

class Racional
{
public:
	Racional();
	Racional(int x_num, int y_num);
	~Racional();
	double valor_aproximado();

public:
	Racional& operator=(const Racional& r1);
	Racional& operator+=(const Racional& r1);
	Racional& operator-=(const Racional& r1);
	Racional& operator*=(const Racional& r1);
	Racional& operator/=(const Racional& r1);

	friend std::istream& operator>>(std::istream& i, Racional& r1);
	friend std::ostream& operator<<(std::ostream& o, Racional& r2);

private:
	bool coprimos(int x_num, int y_den);
	void divisores(std::vector<int>&, int num);
	int x_num{}, y_den{};
};

