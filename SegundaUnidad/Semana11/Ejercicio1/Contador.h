#pragma once

class Contador
{
public:	
	Contador();
	Contador(int cont);
	~Contador();
	int valor();
	int num_Contadores();
public:
	Contador& operator++();
	Contador operator++(int);
private:
	int cont{};
	static unsigned int num_conta;
};



