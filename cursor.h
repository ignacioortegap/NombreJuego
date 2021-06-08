#pragma once
#include "Vector2D.h"
class cursor
{
public:
	Vector2D pos;
	void referencia(int x, int y);
	void dibuja();
	int t = 0,t1 = 0;
	int c = 0,c1 = 0;
	int ref;
	int up = 0;
	int flag = 0;
};

