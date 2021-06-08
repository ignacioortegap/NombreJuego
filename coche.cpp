#include "coche.h"
#include "casilla.h"
#include "tablero.h"
#include <stdlib.h>
#include "ETSIDI.h"
#include "freeglut.h"


void coche::dibuja()
{
	if (orientacion == 1)
	{
		if (tamaño == 2)
		{
			
			if (principal == 1)
			{
				SpriteSequence sprite{ "imagenes/car.png", 1 };
				sprite.setCenter(0.75, 1.4);
				sprite.setSize(1.5, 3);
				sprite.setAngle(-90);
				glTranslatef(pos.x - 1, pos.y, 0);
				glColor3ub(color.r, color.g, color.b);
				
				glTranslatef(0, 0, 0.6);
				sprite.draw();
				glTranslatef(0, 0, -0.6);
				glTranslatef(-pos.x + 1, -pos.y, 0);
			}
				
			
			else
			{
				
				SpriteSequence sprite{ "imagenes/car2.png", 1 };

				sprite.setCenter(0.75, 1.4);
				sprite.setSize(1.5, 3);
				sprite.setAngle(-90);
				glTranslatef(pos.x - 1, pos.y, 0);
				glColor3ub(color.r, color.g, color.b);
				
				glTranslatef(0, 0, 0.6);
				sprite.draw();
				glTranslatef(0, 0, -0.6);
				glTranslatef(-pos.x + 1, -pos.y, 0);
			}

			glTranslatef(pos.x, pos.y, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(-pos.x, -pos.y, 0);

			glTranslatef(pos.x - 1, pos.y, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(-pos.x + 1, -pos.y, 0);

			glTranslatef(pos.x - 2, pos.y, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(-pos.x + 2, -pos.y, 0);


		}
		if (tamaño == 3)
		{
			SpriteSequence sprite{ "imagenes/car6.png", 1 };

			sprite.setCenter(0.75, 3.4);
			sprite.setSize(1.5, 5);
			sprite.setAngle(-90);
			glTranslatef(pos.x, pos.y, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(-pos.x, -pos.y, 0);

			glTranslatef(pos.x - 1, pos.y, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(0, 0, 0.6);
			sprite.draw();
			glTranslatef(0, 0, -0.6);
			glTranslatef(-pos.x + 1, -pos.y, 0);

			glTranslatef(pos.x - 2, pos.y, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(-pos.x + 2, -pos.y, 0);

			glTranslatef(pos.x - 3, pos.y, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(-pos.x + 3, -pos.y, 0);

			glTranslatef(pos.x - 4, pos.y, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(-pos.x + 4, -pos.y, 0);
		}
	}
	if (orientacion == 2)
	{
		if (tamaño == 2)
		{
			SpriteSequence sprite{ "imagenes/car3.png", 1 };

			sprite.setCenter(0.75, 1.4);
			sprite.setSize(1.5, 3);

			glTranslatef(pos.x, pos.y, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(-pos.x, -pos.y, 0);

			glTranslatef(pos.x, pos.y - 1, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(0, 0, 0.6);
			sprite.draw();
			glTranslatef(0, 0, -0.6);
			glTranslatef(-pos.x, -pos.y + 1, 0);

			glTranslatef(pos.x, pos.y - 2, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(-pos.x, -pos.y + 2, 0);
		}
		if (tamaño == 3)
		{
			SpriteSequence sprite{ "imagenes/car7.png", 1 };

			sprite.setCenter(0.75, 3.4);
			sprite.setSize(1.5, 5);

			glTranslatef(pos.x, pos.y, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(-pos.x, -pos.y, 0);

			glTranslatef(pos.x, pos.y - 1, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(0, 0, 0.6);
			sprite.draw();
			glTranslatef(0, 0, -0.6);
			glTranslatef(-pos.x, -pos.y + 1, 0);

			glTranslatef(pos.x, pos.y - 2, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(-pos.x, -pos.y + 2, 0);

			glTranslatef(pos.x, pos.y - 3, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(-pos.x, -pos.y + 3, 0);

			glTranslatef(pos.x, pos.y - 4, 0);
			glColor3ub(color.r, color.g, color.b);
			
			glTranslatef(-pos.x, -pos.y + 4, 0);
		}
	}
	
}

void coche::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void coche::setTamaño(int t)
{
	tamaño = t;
}

void coche::setRad(float r)
{
	radio = r;
}
void coche::setColor(int r, int v, int a)
{
	color.r = r;
	color.g = v;
	color.b = a;
}
void coche::setOrientacion(int o)
{
	orientacion = o;
}