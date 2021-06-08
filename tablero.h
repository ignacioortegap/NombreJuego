#pragma once
#include "casilla.h"
#include "ColorRGB.h"
class tablero
{
public:
	tablero();
	void dibuja();
	casilla casillas[36];
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	int ocupado[36];
};

