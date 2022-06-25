#include "Pila.h"

template<typename type>
Pila<type>::Pila()
{
	this->tam = 10;
}

template<typename type>
Pila<type>::Pila(int tam)
{
	if (tam < 0)
	{
		std::cerr << "El tamanio debe ser positivo!\n";
		exit(1);
	}
	else
		this->tam = tam;
}

template<typename type>
Pila<type>::~Pila()
{
}

template<typename type>
void Pila<type>::top()
{
	std::cout << pilaDeque.top();
}

template<typename type>
type Pila<type>::pop()
{
	if (empty())
	{
		throw std::runtime_error("Pila vacia! (throw)\n");
	}
	else
	{
		int aux = pilaDeque.top();
		pilaDeque.pop();
		return aux;
	}
}

template<typename type>
void Pila<type>::push(type dato)
{
	if (full())
		throw std::runtime_error("Pila llena! (throw)\n");
	else
		pilaDeque.push(dato);
}

template<typename type>
void Pila<type>::clear()
{
	while (!empty())
		pilaDeque.pop();
}

template<typename type>
int Pila<type>::size()
{
	return pilaDeque.size();
}

template<typename type>
bool Pila<type>::full()
{
	if (pilaDeque.size() >= tam)
		return true;
	return false;
}

template<typename type>
bool Pila<type>::empty()
{
	return pilaDeque.empty();
}