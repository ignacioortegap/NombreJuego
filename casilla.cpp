#include "casilla.h"
#include <stdlib.h>
#include "freeglut.h"
#include "ETSIDI.h"
void casilla::setCen(float x, float y)
{
	centro.x = x;
	centro.y = y;
}
void casilla::dibuja()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/road13.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3d(-10, 10, -0.1);
	glTexCoord2d(1, 1); glVertex3d(10, 10, -0.1);
	glTexCoord2d(1, 0); glVertex3d(10, -10, -0.1);
	glTexCoord2d(0, 0); glVertex3d(-10, -10, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	if (pos == 5)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/road2.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(A.x, A.y, 0);
		glTexCoord2d(1, 1); glVertex3d(B.x, B.y, 0);
		glTexCoord2d(1, 0); glVertex3d(D.x, D.y, 0);
		glTexCoord2d(0, 0); glVertex3d(C.x, C.y, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (pos == 0)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/road3.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(A.x, A.y, 0);
		glTexCoord2d(1, 1); glVertex3d(B.x, B.y, 0);
		glTexCoord2d(1, 0); glVertex3d(D.x, D.y, 0);
		glTexCoord2d(0, 0); glVertex3d(C.x, C.y, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (pos == 35)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/road7.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(A.x, A.y, 0);
		glTexCoord2d(1, 1); glVertex3d(B.x, B.y, 0);
		glTexCoord2d(1, 0); glVertex3d(D.x, D.y, 0);
		glTexCoord2d(0, 0); glVertex3d(C.x, C.y, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (pos == 30)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/road6.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(A.x, A.y, 0);
		glTexCoord2d(1, 1); glVertex3d(B.x, B.y, 0);
		glTexCoord2d(1, 0); glVertex3d(D.x, D.y, 0);
		glTexCoord2d(0, 0); glVertex3d(C.x, C.y, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (centro.x > -4 && centro.x < 4 && centro.y > -4 && centro.y < 4)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/road.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(A.x, A.y, 0);
		glTexCoord2d(1, 1); glVertex3d(B.x, B.y, 0);
		glTexCoord2d(1, 0); glVertex3d(D.x, D.y, 0);
		glTexCoord2d(0, 0); glVertex3d(C.x, C.y, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (centro.x > -6 && centro.x < -4 && centro.y > -4 && centro.y < 4)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/road8.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(A.x, A.y, 0);
		glTexCoord2d(1, 1); glVertex3d(B.x, B.y, 0);
		glTexCoord2d(1, 0); glVertex3d(D.x, D.y, 0);
		glTexCoord2d(0, 0); glVertex3d(C.x, C.y, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (centro.x > 4 && centro.x < 6 && centro.y > -4 && centro.y < 4 && pos != 33)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/road9.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(A.x, A.y, 0);
		glTexCoord2d(1, 1); glVertex3d(B.x, B.y, 0);
		glTexCoord2d(1, 0); glVertex3d(D.x, D.y, 0);
		glTexCoord2d(0, 0); glVertex3d(C.x, C.y, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (pos == 33)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/road11.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(A.x, A.y, 0);
		glTexCoord2d(1, 1); glVertex3d(B.x, B.y, 0);
		glTexCoord2d(1, 0); glVertex3d(D.x, D.y, 0);
		glTexCoord2d(0, 0); glVertex3d(C.x, C.y, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D); 

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/road12.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(A.x + 2, A.y, 0);
		glTexCoord2d(1, 1); glVertex3d(B.x + 2, B.y, 0);
		glTexCoord2d(1, 0); glVertex3d(D.x + 2, D.y, 0);
		glTexCoord2d(0, 0); glVertex3d(C.x + 2, C.y, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		
	}
	if (centro.x > -4 && centro.x < 4 && centro.y > 4 && centro.y < 6)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/road5.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(A.x, A.y, 0);
		glTexCoord2d(1, 1); glVertex3d(B.x, B.y, 0);
		glTexCoord2d(1, 0); glVertex3d(D.x, D.y, 0);
		glTexCoord2d(0, 0); glVertex3d(C.x, C.y, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (centro.x > -4 && centro.x < 4 && centro.y > -6 && centro.y < -4)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/road10.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3d(A.x, A.y, 0);
		glTexCoord2d(1, 1); glVertex3d(B.x, B.y, 0);
		glTexCoord2d(1, 0); glVertex3d(D.x, D.y, 0);
		glTexCoord2d(0, 0); glVertex3d(C.x, C.y, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}

	/*glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex3d(A.x, A.y, 0);
	glVertex3d(B.x, B.y, 0);
	glVertex3d(D.x, D.y, 0);
	glVertex3d(C.x, C.y, 0);
	glColor3ub(255, 255, 255);
	glEnd();
	glEnable(GL_LIGHTING);*/
}
void casilla::vertices()
{
	A.x = centro.x - 1;               //A   //B
	A.y = centro.y + 1;
	B.x = centro.x + 1;               //C   //D
	B.y = centro.y + 1;
	C.x = centro.x - 1;
	C.y = centro.y - 1;
	D.x = centro.x + 1;
	D.y = centro.y - 1;
}
void casilla::setColor(int r, int v, int a)
{
	color.r = r;
	color.g = v;
	color.b = a;
}