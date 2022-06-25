#include <iostream>
#include "Cuadratico.h"
using std::cout;
using std::endl;

int main()
{
	Cuadratico c1(10,5.2,19.4);

	cout << c1.calcular_fx(2) << endl;

	Cuadratico c2;

	cout << c2.calcular_fx(21.5) << endl;

	c2 = c1;

	cout << c2.calcular_fx(2) << endl;

	Cuadratico c3(c1);

	cout << c3.calcular_fx(2) << endl;

	return 0;
}
	


