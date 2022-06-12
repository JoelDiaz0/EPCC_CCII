//Reina.h

#pragma once

class Reina
{
public:
	friend class Tablero;
	Reina();
	~Reina();
	void setPosicion(int posx, int posy);
private:
	int posx{}, posy{};
};



