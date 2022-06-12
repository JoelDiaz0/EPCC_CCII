
//Robot.h

#pragma once
#include <iostream>

class Robot
{
public:
	Robot();
	~Robot();
	void generar_nombre_aleatorio();
	const void mostrar();
	std::string get_nombre();
private:
	std::string nombre;
};



