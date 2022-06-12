
//Tablero.cpp

#include "Tablero.h"

Tablero::Tablero()
{
    f = 8;
    c = 8;

    M = new char* [f];
    for (int i = 0; i < f; i++)
        M[i] = new char[c];

    r1.setPosicion(0, 4);
    r2.setPosicion(7, 3);

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == r2.posx && j == r2.posy)
                M[i][j] = 'N';
            else if (i == r1.posx && j == r1.posy)
                M[i][j] = 'B';
            else
                M[i][j] = '_';
        }
    }
}

Tablero::~Tablero()
{
    for (int i = 0; i < f; i++)
        delete[] M[i];
    delete[] M;
}


void Tablero::actualizar()
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == r2.posx && j == r2.posy)
                M[i][j] = 'N';
            else if (i == r1.posx && j == r1.posy)
                M[i][j] = 'B';
            else
                M[i][j] = '_';
        }
    }
}

bool Tablero::validarMovimiento(int x, int y)
{
    if (x > 9 || x < 0 || y > 9 || y < 0)
        return false;
    return true;
}


bool Tablero::reinasAtaque()
{
    if (r1.posx == r2.posx || r1.posy == r2.posy)
        return true;
    if (r1.posx + r2.posy == r2.posx + r1.posy)
        return true;
    if (r1.posx + r1.posy == r2.posx + r2.posy)
        return true;
    return false;
}

void Tablero::moverReinas(int x, int y, int x2, int y2)
{
    if (validarMovimiento(x, y) && validarMovimiento(x2, y2))
    {
        r1.setPosicion(x, y);
        r2.setPosicion(x2, y2);
    }
    else
        std::cerr << "Movimiento no valido!\n";
}

const void Tablero::mostrar()
{
    actualizar();

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}