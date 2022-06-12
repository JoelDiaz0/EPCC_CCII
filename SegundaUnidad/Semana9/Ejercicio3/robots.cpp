//robots.cpp
#include <iostream>
#include "Robot.h"

bool comprovar_nombre_unico(Robot*&);

int main()
{
	Robot* r1 = new Robot[100];

	std::cout << "Primer Nombre\n\n";
	for (int i = 0; i < 100; i++)
	{
		r1[i].generar_nombre_aleatorio();
		r1[i].mostrar();
	}

	if (comprovar_nombre_unico(r1))
		std::cout << "No se repite ningun nombre\n";
	else
		std::cout << "Se repitio\n";


	std::cout << "\n\nNombre Reseteado\n\n";
	for (int i = 0; i < 100; i++)
	{
		r1[i].generar_nombre_aleatorio();
		r1[i].mostrar();
	}

	if (comprovar_nombre_unico(r1))
		std::cout << "No se repite ningun nombre\n";
	else
		std::cout << "Se repitio\n";

	delete[] r1;
    return 0;
}

bool comprovar_nombre_unico(Robot*& r)
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = i+1; j < 100; j++)
		{
			if (r[i].get_nombre() == r[j].get_nombre())
				return false;
		}
	}
	return true;
}