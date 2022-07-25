#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;

int main()
{

	LinkedList* lista_1 = new LinkedList;
	LinkedList* lista_2 = new LinkedList;

	for (int i = 1; i <= 10; i++)
	{
		if (i % 2 != 0)
		{
			lista_1->insert(i);
			continue;
		}
		lista_2->insert(i);
	}

	cout << "Lista1: ";
	lista_1->mostrar();
	cout << endl;

	cout << "Lista2: ";
	lista_2->mostrar();
	cout << endl << endl;

	lista_1 = lista_2;

	cout << "Asignando Lista2 a Lista1\n\n";

	cout << "Lista1: ";
	lista_1->mostrar();
	cout << endl;

	cout << "Lista2: ";
	lista_2->mostrar();
	cout << endl;

	delete lista_1, lista_2;
}



