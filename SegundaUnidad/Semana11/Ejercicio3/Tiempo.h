#pragma once
#include <iostream>
using std::cout;
using std::endl;

class Tiempo
{
public:
	Tiempo();
	Tiempo(int horas, int minutos, int segundos);
	~Tiempo();
	void mostrar_formato_12_horas();
public:
	Tiempo& operator+(const Tiempo& t1);
	Tiempo& operator-(const Tiempo& t1);

	bool operator==(const Tiempo& t1) const;
	bool operator!=(const Tiempo& t1) const;
	bool operator<(const Tiempo& t1) const;
	bool operator>(const Tiempo& t1) const;
	bool operator<=(const Tiempo& t1) const;
	bool operator>=(const Tiempo& t1) const;
	
	friend std::ostream& operator<<(std::ostream& o,Tiempo& t1);
	friend std::istream& operator>>(std::istream& i,Tiempo& t1);

private:
	int horas{};
	int minutos{};
	int segundos{};
};



