#include "Interaccion.h"
#include <stdlib.h>
#include "freeglut.h"
#include "ETSIDI.h"


void Interaccion::rebotee(Esfera &e, Pared plat)
{
	Vector2D dir;
	float dif = plat.distancia(e.posicion, &dir) - e.radio;
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = e.velocidad;
		e.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
		e.posicion = e.posicion - dir * dif;

	}
}

void Interaccion::rebote(Hombre &h, Caja c)
{
 float xmax=c.suelo.limite2.x;
 float xmin=c.suelo.limite1.x;
 if(h.posicion.x>xmax)h.posicion.x=xmax;
 if(h.posicion.x<xmin)h.posicion.x=xmin;
} 

void Interaccion::Rebote(Esfera& e, Caja c)
{
	Interaccion::rebotee(e, c.suelo);
	Interaccion::rebotee(e, c.techo);
	Interaccion::rebotee(e, c.pared_izq);
	Interaccion::rebotee(e, c.pared_dcha);
}

void Interaccion::choque(cursor &c, piezas& p)
{
	float drch, izq, arriba, abajo;
	float refizq, refdrch, refarriba, refabajo;
	float horizontal, vertical;
	int i;
	float dist;

	for (i = 0; i < p.numcoches; i++)
	{
		horizontal = p.coches[i].pos.x;
		vertical = p.coches[i].pos.y;
		if (p.coches[i].orientacion == 1 && p.coches[i].tamaño == 2)
		{
			izq = p.coches[i].pos.x - 2.5;  // Hitbox del coche
			drch = p.coches[i].pos.x + p.coches[i].radio / 2.0;
			arriba = p.coches[i].pos.y + p.coches[i].radio / 2.0;
			abajo = p.coches[i].pos.y - p.coches[i].radio / 2.0;
			refizq = izq + 1.5;
			refdrch = drch - 1.5;
			refabajo = abajo;
			refarriba = arriba;
		}

		if (p.coches[i].orientacion == 1 && p.coches[i].tamaño == 3)
		{
			izq = p.coches[i].pos.x - 4.5;  // Hitbox del coche
			drch = p.coches[i].pos.x + p.coches[i].radio / 2.0;
			arriba = p.coches[i].pos.y + p.coches[i].radio / 2.0;
			abajo = p.coches[i].pos.y - p.coches[i].radio / 2.0;
			refizq = izq + 1.5;
			refdrch = drch - 1.5;
			refabajo = abajo;
			refarriba = arriba;
		}

		if (p.coches[i].orientacion == 2 && p.coches[i].tamaño == 2)
		{
			izq = p.coches[i].pos.x - p.coches[i].radio / 2.0;  // Hitbox del coche
			drch = p.coches[i].pos.x + p.coches[i].radio / 2.0;
			arriba = p.coches[i].pos.y + p.coches[i].radio / 2.0;
			abajo = p.coches[i].pos.y - 2.5;
			refarriba = arriba - 1.5;
			refabajo = abajo + 1.5;
			refizq = izq;
			refdrch = drch;
		}

		if (p.coches[i].orientacion == 2 && p.coches[i].tamaño == 3)
		{
			izq = p.coches[i].pos.x - p.coches[i].radio / 2.0;  // Hitbox del coche
			drch = p.coches[i].pos.x + p.coches[i].radio / 2.0;
			arriba = p.coches[i].pos.y + p.coches[i].radio / 2.0;
			abajo = p.coches[i].pos.y - 4.5;
			refarriba = arriba - 1.5;
			refabajo = abajo + 1.5;
			refizq = izq;
			refdrch = drch;
		}

		if (c.pos.x <= drch && c.pos.x >= izq && c.pos.y <= arriba && c.pos.y >= abajo && c.t1 == 0 && c.t == 1) //fijamos que coche movemos
		{
			c.t1 = 1;
			p.coches[i].t1 = 1;
			
		}

		if (c.pos.x <= drch && c.pos.x >= izq && c.pos.y <= arriba && c.pos.y >= abajo && c.t == 1 && p.coches[i].p == 0 && p.coches[i].t1 == 1)
		{

			p.coches[i].flag = 1;
			
		}
		if (p.coches[i].flag == 1)
		{

			if (c.pos.x <= refizq || c.pos.x >= refdrch) //avanzamos en eje x
			{
				p.coches[i].p = 1;
				p.coches[i].flag = 0;
				
			}
			if (c.pos.y <= refabajo || c.pos.y >= refarriba) //avanzamos en eje y
			{
				p.coches[i].p = 2;
				p.coches[i].flag = 0;
			}
		}

		

		if (c.t == 0) p.coches[i].flag = 0;
		if (p.coches[i].p == 1 && p.coches[i].orientacion == 1 && p.coches[i].tamaño == 2)
		{
			
			p.coches[i].pos.x = c.pos.x + 1;

		}
		if (p.coches[i].p == 1 && p.coches[i].orientacion == 1 && p.coches[i].tamaño == 3)
		{
			p.coches[i].pos.x = c.pos.x + 2;

		}

		/*if (p.coches[i].p == 1 && p.coches[i].orientacion == 2)	p.coches[i].pos.x = c.pos.x;*/
		if (p.coches[i].p == 2 && p.coches[i].orientacion == 2 && p.coches[i].tamaño == 2)
		{
			p.coches[i].pos.y = c.pos.y + 1;

		}
		if (p.coches[i].p == 2 && p.coches[i].orientacion == 2 && p.coches[i].tamaño == 3)
		{
			p.coches[i].pos.y = c.pos.y + 2;

		}

		/*if (p.coches[i].p == 2 && p.coches[i].orientacion == 1)	p.coches[i].pos.y = c.pos.y;*/
		if (c.up == 1)
		{
			p.coches[i].pos.x = p.coches[i].x;
			p.coches[i].pos.y = p.coches[i].y;
		}
	}
}




void Interaccion::choque2(piezas& car, cursor& c)
{
	float drch, izq, arriba, abajo;
	int i, j;
	for (i = 0; i < car.numcoches; i++)
	{
		if (car.coches[i].orientacion == 1 && car.coches[i].tamaño == 2)
		{
			car.coches[i].limites[0] = car.coches[i].pos.x - 2.5;                       //izq
			car.coches[i].limites[1] = car.coches[i].pos.x + car.coches[i].radio / 2.0; //drch
			car.coches[i].limites[2] = car.coches[i].pos.y + car.coches[i].radio / 2.0; //arriba
			car.coches[i].limites[3] = car.coches[i].pos.y - car.coches[i].radio / 2.0; //abajo
		}
		if (car.coches[i].orientacion == 1 && car.coches[i].tamaño == 3)
		{
			car.coches[i].limites[0] = car.coches[i].pos.x - 4.5;                       //izq
			car.coches[i].limites[1] = car.coches[i].pos.x + car.coches[i].radio / 2.0; //drch
			car.coches[i].limites[2] = car.coches[i].pos.y + car.coches[i].radio / 2.0; //arriba
			car.coches[i].limites[3] = car.coches[i].pos.y - car.coches[i].radio / 2.0; //abajo
		}
		if (car.coches[i].orientacion == 2 && car.coches[i].tamaño == 2)
		{
			car.coches[i].limites[0] = car.coches[i].pos.x - car.coches[i].radio / 2.0; //izq
			car.coches[i].limites[1] = car.coches[i].pos.x + car.coches[i].radio / 2.0; //drch
			car.coches[i].limites[2] = car.coches[i].pos.y + car.coches[i].radio / 2.0; //arriba
			car.coches[i].limites[3] = car.coches[i].pos.y - 2.5;                       //abajo
		}
		if (car.coches[i].orientacion == 2 && car.coches[i].tamaño == 3)
		{
			car.coches[i].limites[0] = car.coches[i].pos.x - car.coches[i].radio / 2.0; //izq
			car.coches[i].limites[1] = car.coches[i].pos.x + car.coches[i].radio / 2.0; //drch
			car.coches[i].limites[2] = car.coches[i].pos.y + car.coches[i].radio / 2.0; //arriba
			car.coches[i].limites[3] = car.coches[i].pos.y - 4.5;                       //abajo
		}

		for (j = 0; j < car.numcoches; j++)
		{
			if (j != i)
			{
				if (car.coches[i].orientacion == 1)
				{
				
					if (car.coches[i].limites[0] <= car.coches[j].limites[1] && car.coches[i].limites[1] >= car.coches[j].limites[0] && car.coches[i].limites[2] <= car.coches[j].limites[2] && car.coches[i].limites[3] >= car.coches[j].limites[3])
					{
						car.coches[i].pos.x = car.coches[i].x;
						car.coches[i].pos.y = car.coches[i].y;
						c.t = 0;
						c.t1 = 0;
						car.coches[i].p = 0;
						car.coches[i].t1 = 0;
						car.coches[j].p = 0;
						car.coches[j].t1 = 0;
						c.up = 1;
						ETSIDI::play("sonidos/choque.mp3");
					}
				}
				if (car.coches[i].orientacion == 2)
				{

					if (car.coches[i].limites[0] <= car.coches[j].limites[1] && car.coches[i].limites[1] >= car.coches[j].limites[0] && car.coches[i].limites[2] >= car.coches[j].limites[3] && car.coches[i].limites[3] <= car.coches[j].limites[2])
					{
						car.coches[i].pos.x = car.coches[i].x;
						car.coches[i].pos.y = car.coches[i].y;
						c.t = 0;
						c.t1 = 0;
						car.coches[i].p = 0;
						car.coches[i].t1 = 0;
						car.coches[j].p = 0;
						car.coches[j].t1 = 0;
						c.up = 1;
						ETSIDI::play("sonidos/choque.mp3");
					}
				}
			}
		}

	}
	
	
}

void Interaccion::limites(tablero& t, piezas& p)
{
	int i;
	for (i = 0; i < p.numcoches; i++)
	{
		if (p.coches[i].principal == 0 && (p.coches[i].limites[0] <= -6 || p.coches[i].limites[1] >= 6 || p.coches[i].limites[3] <= -6 || p.coches[i].limites[2] >= 6))
		{
			p.coches[i].pos.x = p.coches[i].x;
			p.coches[i].pos.y = p.coches[i].y;
			p.coches[i].p = 0;
			p.coches[i].t1 = 0;
		}



		if (p.coches[i].principal == 1 && (p.coches[i].limites[0] <= -6 || p.coches[i].limites[3] <= -6 || p.coches[i].limites[2] >= 6))
		{
			p.coches[i].pos.x = p.coches[i].x;
			p.coches[i].pos.y = p.coches[i].y;
			p.coches[i].p = 0;
			p.coches[i].t1 = 0;
		}

		if (p.coches[i].principal == 1 && p.coches[i].pos.x >= 7)
		{
			p.señal = 1;
			p.start = 0;
			ETSIDI::play("sonidos/salida.mp3");
			
		}

		if (p.coches[i].principal == 1 && p.coches[i].pos.y >= 0 && p.coches[i].pos.y <= 2)
		{

		}
		else
		{
			if (p.coches[i].principal == 1 && (p.coches[i].limites[0] <= -6 || p.coches[i].limites[1] >= 6 || p.coches[i].limites[3] <= -6 || p.coches[i].limites[2] >= 6))
			{
				p.coches[i].pos.x = p.coches[i].x;
				p.coches[i].pos.y = p.coches[i].y;
				p.coches[i].p = 0;
				p.coches[i].t1 = 0;
			}
		}
	}
	
}

void Interaccion::centrado(tablero& t, piezas& p)
{
	int i,j,k;
	for (i = 0; i < 36; i++)
	{
		for (k = 0; k < p.numcoches; k++)
		{
			if (p.coches[k].pos.x >= t.casillas[i].A.x && p.coches[k].pos.x <= t.casillas[i].B.x && p.coches[k].pos.y >= t.casillas[i].C.y && p.coches[k].pos.y <= t.casillas[i].B.y && t.ocupado[i] == 0)
			{
				if (p.coches[k].tamaño == 2)  // tamaño del coche 2 casillas
				{
					if (p.coches[k].orientacion == 1 && i >= 6)
					{
						if (t.ocupado[i - 6] == 0)
						{
							p.coches[k].cas = i;
							t.ocupado[i] = 1;
							t.ocupado[i - 6] = 1;

						}

					}

					if (p.coches[k].orientacion == 1 && i > 6)
					{
						for (j = 0; j < 36; j++)
						{
							if (j == i || j == i - 6);
							else t.ocupado[j] = 0;
						}

					}
					if (p.coches[k].orientacion == 2 && i % 6 != 0)
					{

						if (t.ocupado[i - 1] == 0)
						{
							p.coches[k].cas = i;
							t.ocupado[i] = 1;
							t.ocupado[i - 1] = 1;
						}

					}
					if (p.coches[k].orientacion == 2 && i % 6 != 0)
					{
						for (j = 0; j < 36; j++)
						{
							if (j == i || j == i - 1);
							else t.ocupado[j] = 0;
						}

					}
				}
				if (p.coches[k].tamaño == 3)   // tamaño del camion 3 casillas
				{
					if (p.coches[k].orientacion == 1 && i > 11)
					{
						if (t.ocupado[i - 6] == 0 && t.ocupado[i - 12] == 0)
						{
							p.coches[k].cas = i;
							t.ocupado[i] = 1;
							t.ocupado[i - 6] = 1;
							t.ocupado[i - 12] = 1;

						}

					}

					if (p.coches[k].orientacion == 1 && i > 11)
					{
						for (j = 0; j < 36; j++)
						{
							if (j == i || j == i - 6 || j == i - 12);
							else t.ocupado[j] = 0;
						}

					}
					if (p.coches[k].orientacion == 2 && (i % 6 != 0 || i != 1 || i != 7 || i != 13 || i != 19 || i != 25 || i != 31))
					{

						if (t.ocupado[i - 1] == 0 && t.ocupado[i - 2] == 0)
						{
							p.coches[k].cas = i;
							t.ocupado[i] = 1;
							t.ocupado[i - 1] = 1;
							t.ocupado[i - 2] = 1;
						}

					}
					if (p.coches[k].orientacion == 2 && (i % 6 != 0 || i != 1 || i != 7 || i != 13 || i != 19 || i != 25 || i != 31))
					{
						for (j = 0; j < 36; j++)
						{
							if (j == i || j == i - 1 || j == i - 2);
							else t.ocupado[j] = 0;
						}

					}
				}



			}
		}
		
	}
	
}
void Interaccion::encasillado(tablero& t, piezas& p)
{
	int i, j;
	for (i = 0; i < 36; i++)
	{
		for (j = 0; j < p.numcoches; j++)
		{
			if (p.coches[j].cas == i)
			{
				p.coches[j].x = t.casillas[i].centro.x;
				p.coches[j].y = t.casillas[i].centro.y;
			}
		}
		
	}
}
void Interaccion::resetCasillas(tablero& t)
{
	int i;
	for (i = 0; i < 36; i++)
	{
		t.ocupado[i] = 0;
	}
}

