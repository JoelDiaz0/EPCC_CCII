#pragma once

class Cuadratico
{
public:
	Cuadratico();
	Cuadratico(const Cuadratico& copia);
	Cuadratico(float a, float b, float c);
	~Cuadratico();
	float calcular_fx(float x);
public:
	Cuadratico& operator=(const Cuadratico& c1);

private:
	float a{}, b{}, c{};
};



