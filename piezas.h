#pragma once
#include "coche.h"
#include "Vector2D.h"
class piezas
{
public:
	piezas();
	void dibuja();
	void lee();
	coche coches[20];
	int nivel, lvl = 1;
	int señal = 0, sig = 1;
	int fin = 0;
	int start = 0;
	int reset = 0;
	int colision = 0;
	int numcoches = 0;
	char n;
};

