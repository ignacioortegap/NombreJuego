#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "stdio.h"
#include "coche.h"
#include "ETSIDI.h"

void Mundo::rotarOjo()
{
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(0, 0, 20,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	/*esfera.dibuja();
	caja.Dibuja();
	hombre.dibuja();
	disparo.dibuja();
	plataforma.setColor(255, 255, 255);
	plataforma.dibuja();
	bonus.dibuja();
	*/

	//cursor.dibuja();
	tablero.dibuja();
	piezas.dibuja();
	glDisable(GL_LIGHTING);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Mundo::mueve()
{
	
	piezas.lee();
	
	if (piezas.start == 1)
	{
		if (piezas.reset == 1)
		{
			Interaccion::resetCasillas(tablero);

			Interaccion::encasillado(tablero, piezas);
			

			Interaccion::centrado(tablero, piezas);
			
			piezas.reset = 0;
			piezas.colision = 1;
		}
		
		

		Interaccion::limites(tablero, piezas);


		Interaccion::centrado(tablero, piezas);

		Interaccion::encasillado(tablero, piezas);
		

		Interaccion::choque(cursor, piezas);
		

		if (piezas.colision == 1)
			Interaccion::choque2(piezas, cursor);
	}
	

	
	
	/*hombre.mueve(0.025f);
	esfera.mueve(0.025f);
	bonus.mueve(0.025f);
	disparo.mueve(0.025f);
	Interaccion::rebote(hombre,caja); 
	Interaccion::Rebote(esfera, caja);
	Interaccion::rebotee(esfera, plataforma);
	*/
}

void Mundo::Raton(int x, int y)
{
	cursor.referencia(x, y);
}

void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

	
	//ETSIDI::playMusica("sonidos/musica.corte.mp3", true);

	

	/*esfera.setPos(2, 4);
	esfera.setVel(5, 15);
	esfera.setRad(1.5);
	esfera.setColor(0, 255, 255);
	bonus.setPos(5, 5);
	bonus.setLado(0.5);
	disparo.setPos(-5.0f, 0.0f);
	plataforma.setLim(-5.0f, 9.0f, 5.0f, 9.0f);*/
	

}

void Mundo::tecla(unsigned char key)
{

}
void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.setVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.setVel(5.0f, 0.0f);
		break;
	}
}

void Mundo::click(int button, int state)
{
	int i;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		cursor.t = 1;
		cursor.up = 0;
		
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		cursor.t = 0;
		cursor.t1 = 0;
		cursor.c = 0;
		cursor.c1 = 0;
		

		for (i = 0; i < 20; i++)
		{
			piezas.coches[i].p = 0;
			piezas.coches[i].t1 = 0;
		}
		

		cursor.up = 1;

		if (piezas.señal == 1)
		{
			piezas.sig = 1;
			piezas.start = 0;
			piezas.señal = 0;
		}

	}

	printf("%d", tablero.ocupado[3]);
}