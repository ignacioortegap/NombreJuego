#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "coche.h"
#include "cursor.h"
#include "tablero.h"
#include "piezas.h"
class Interaccion
{
public:
	static void rebote(Hombre& h, Caja c);
	static void Rebote(Esfera& e, Caja c);
	static void rebotee(Esfera &e, Pared plat);
	static void choque(cursor &c, piezas& p);
	static void choque2(piezas& car, cursor& c);
	static void limites(tablero& t, piezas& p);
	static void centrado(tablero& t, piezas& p);
	static void encasillado(tablero& t, piezas& p);
	static void resetCasillas(tablero& t);
};
