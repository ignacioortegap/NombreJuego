#include "cursor.h"
#include "freeglut.h"
void cursor::referencia(int x, int y)
{
	pos.x = -9.52 + x / 42.0;
	pos.y = 7.14 + -y / 42.0;
}

void cursor::dibuja()
{
	glTranslatef(pos.x, pos.y, 0);
	glutSolidCube(0.1);
	glTranslatef(-pos.x, -pos.y, 0);
}