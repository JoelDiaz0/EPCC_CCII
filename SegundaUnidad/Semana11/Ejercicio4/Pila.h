#pragma once
#include <iostream>
#include <stack>

template<typename type>
class Pila
{
public:
	Pila();
	Pila(int tam);
	~Pila();
	void top();
	type pop();
	void push(type dato);
	void clear();
	int size();
	bool full();
	bool empty();

private:
	std::stack<type> pilaDeque;
	int tam{};
};





