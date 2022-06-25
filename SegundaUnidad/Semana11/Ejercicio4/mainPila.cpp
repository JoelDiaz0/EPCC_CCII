#include <iostream>
#include "Pila.h"
using std::cout;
using std::endl;

int main()
{
	Pila<int> p1(6); //Se inicializa una Pila con tamaño 6

	p1.push(12);
	p1.push(22);
	p1.push(4);
	p1.push(7);
	p1.push(2);

	cout << "Muestra el ultimo elemento: "; p1.top();

	cout << "\nSe retorna el ultimo elemento y luego se elimina: " << p1.pop() << endl;

	cout << "Muestra el ultimo elemento: "; p1.top();

	cout << endl << endl;

	p1.push(31);
	p1.push(60);

	try
	{
		p1.push(27); //Se intenta ingresar un elemento a una pila llena
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	if (p1.full())
		cout << "PILA LLENA\n";
	else
		cout << "PILA NO LLENA\n";

	p1.clear();

	cout << "Se eliminaron todos los elementos de la pila\n";

	try
	{
		cout << p1.pop(); //Se intenta retornar un elemento de una pila vacia
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	if (p1.empty())
		cout << "PILA VACIA\n";
	else
		cout << "PILA NO VACIA\n";

	return 0;
}
	


