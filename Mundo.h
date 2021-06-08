#pragma once
#include "Pared.h"
#include "Caja.h"
#include "Esfera.h"
#include "Hombre.h"
#include "Disparo.h"
#include "Bonus.h"
#include "Interaccion.h"
#include "cursor.h"
#include "coche.h"
#include "casilla.h"
#include "tablero.h"
#include "piezas.h"
class Mundo
{
public:
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char key);
	void Raton(int x, int y);
	void click(int button, int state);
private:

	float x_ojo;
	float y_ojo;
	float z_ojo;

	coche coche, coche2;
	piezas piezas;
	cursor cursor;
	Disparo disparo;
	Esfera esfera;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	Pared plataforma;
	tablero tablero;
};
