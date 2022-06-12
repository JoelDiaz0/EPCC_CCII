//Robot.h

#pragma once
#include <iostream>

class Robot
{
public:
	Robot();
	Robot(std::string ins, int x, int y);
	~Robot();
	void instrucciones(std::string ins);
	const void mostrar();
private:
	void convertir_minus(std::string&);
	void convertir_mayus(std::string&);
private:
	const std::string orientacion[4] = { "norte","este","sur","oeste" };
	std::string direccion;
	int x, y;
};



