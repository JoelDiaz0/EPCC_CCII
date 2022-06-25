#include <iostream>
#include "Racional.h"
using std::cout;
using std::endl;

int main()
{
	Racional c1(8, 9), c2(17, 7), c3(12, 19), c4; //Coprimos

	try
	{
		Racional c5(8, 12), c6(12, 0);  //No Coprimos, denominador 0
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}


	cout << "Ingrese un valor racional coprimo: (29,5) "; std::cin >> c4;

	cout << "c1 = " << c1 << endl;

	c1 += c2;

	cout << "Despues de c1+=c2 " << c1 << endl;

	c1 -= c4;

	cout << "Despues de c1-=c4 " << c1 << endl;

	c1 *= c3;

	cout << "Despues de c1*=c3 " << c1 << endl;

	c1 /= c2;

	cout << "Despues de c1/=c4 " << c1 << endl;

	c1 = c3;

	cout << "Despues de c1=c3 " << c1 <<" valor aproximado: " << c1.valor_aproximado() << endl;

	return 0;
}


