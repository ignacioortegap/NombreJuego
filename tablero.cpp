#include "tablero.h"
tablero::tablero()
{
	int i, j = 0, k, x = -5, y = -5;
	for (i = 0; i < 6; i++)
	{
		for (k = 0; k < 6; k++)
		{
			casillas[j].setCen(x, y);
			y++;
			y++;
			if (i % 2)
			{
				if (j % 2)
				{
					casillas[j].setColor(255, 0, 255);
				}
				else casillas[j].setColor(0, 255, 255);
			}
			else 
			{
				if (j % 2)
				{
					casillas[j].setColor(0, 255, 255);
				}
				else casillas[j].setColor(255, 0, 255);
			}
			j++;
			
		}
		y = -5;
		x++;
		x++;
	}
	for (i = 0; i < 36; i++)
	{
		casillas[i].vertices();

	}

}
void tablero::dibuja()
{
	int i;
	for (i = 0; i < 36; i++)
	{
		casillas[i].pos = i;
		casillas[i].dibuja();
	}
	
}