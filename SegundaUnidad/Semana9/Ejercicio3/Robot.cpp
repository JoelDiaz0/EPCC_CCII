#include "Robot.h"
#include <random>
#include <sstream>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<>rand_digits(0,9);
std::uniform_int_distribution<>rand_ascii(65, 90);

//std::uniform_int_distribution<char>rand_ascii('a','z'); 
//static_assert failed: invalid template argument for uniform_int_distribution


Robot::Robot()
{
	nombre = "00000";
}

Robot::~Robot()
{
}

const void Robot::mostrar()
{
	std::cout << nombre << std::endl;
}

void Robot::generar_nombre_aleatorio()
{
	std::stringstream ss;
	char aux[2];
	aux[0] = rand_ascii(gen);
	aux[1] = rand_ascii(gen);

	ss << aux[0] << aux[1] << rand_digits(gen) << rand_digits(gen) << rand_digits(gen);
	nombre = ss.str();
}

std::string Robot::get_nombre()
{
	return nombre;
}


