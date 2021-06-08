#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class casilla
{
public:
	void setCen(float x, float y);
	void vertices();
	void dibuja();
	int pos;
	Vector2D centro, A, B, C, D;
	void setColor(int r, int v, int a);
	ColorRGB color;
};
