//Robot.cpp

#include "Robot.h"

Robot::Robot()
{
	x = 0;
	y = 0;
	direccion = orientacion[0];
}

Robot::Robot(std::string direccion, int x, int y)
{
	bool c = false;
	this->x = x;
	this->y = y;

	convertir_minus(direccion);

	for (int i = 0; i < 4; i++)
	{
		if (direccion == orientacion[i])
		{
			this->direccion = direccion;
			c = true;
		}	
	}
	if (!c)
		this->direccion = orientacion[0];
}

Robot::~Robot()
{
}

void Robot::convertir_minus(std::string& palabra)
{
	for (int i = 0; i < palabra.length(); i++)
		palabra[i] = tolower(palabra[i]);
}

void Robot::convertir_mayus(std::string& palabra)
{
	for (int i = 0; i < palabra.length(); i++)
		palabra[i] = towupper(palabra[i]);
}

void Robot::instrucciones(std::string ins)
{
	convertir_mayus(ins);
	int ori, invalido = 0;

	for (int i = 0; i < 4; i++)
	{
		if (direccion == orientacion[i])
			ori = i;
	}

	for (int i = 0; i < ins.length(); i++)
	{
		if (ins[i] == 'D')
		{
			if (ori == 3)
				ori = 0;
			else
				ori++;
			direccion = orientacion[ori];
		}
		else if (ins[i] == 'I')
		{
			if (ori == 0)
				ori = 3;
			else
				ori--;
			direccion = orientacion[ori];
		}
		else if (ins[i] == 'A')
		{
			if (direccion == orientacion[0])
				y++;
			else if (direccion == orientacion[1])
				x++;
			else if (direccion == orientacion[2])
				y--;
			else
				x--;
		}
		else
			invalido++;
	}

	if (invalido > 0)
		std::cout << "Se ingreso " << invalido << " accion invalida!\n";
}

const void Robot::mostrar()
{
	std::cout << "Direccion: " << direccion << " Eje: (" << x << "," << y <<")" << std::endl;
}

