//Reina.cpp

#include "Reina.h"

Reina::Reina()
{
	posx = 0;
	posy = 0;
}

Reina::~Reina()
{

}

void Reina::setPosicion(int posx, int posy)
{
	if (posx < 8 || posx >= 0 || posy < 8 || posy >= 0)
	{
		this->posx = posx;
		this->posy = posy;
	}
	else
	{
		this->posx = 0;
		this->posy = 0;
	}
}