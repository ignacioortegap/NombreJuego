#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;
class coche
{
public:
	
	void dibuja();
	void setPos(float x, float y);
	void setRad(float r);
	void setOrientacion(int o);
	void setTamaño(int t);
	Vector2D pos;
	float limites[4]; // izquierda, derecha, arriba, abajo
	float radio;
	float t = 0,t1 = 0;
	int flag = 0;
	int p = 0;
	int orientacion;
	int tamaño = 2;
	int principal = 0;
	int cas = 0;
	float x = pos.x, y = pos.y;
	void setColor(int r, int v, int a);
	ColorRGB color;
};

