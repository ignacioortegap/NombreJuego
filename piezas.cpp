#include "piezas.h"
#include "stdio.h"
piezas::piezas()
{
	int i;
	coches[0].setRad(1);
	coches[0].setColor(255, 0, 0);
	coches[0].principal = 1;

	for (i = 1; i < 20; i++)
	{
		coches[i].setRad(1);
		coches[i].setColor(0, 0, 255);
	}
	
}
void piezas::dibuja()
{
	int i;
	for (i = 0; i < numcoches; i++)
	{
		coches[i].dibuja();
	}
}

void piezas::lee()
{
	char datos[20];
	int i = 0;
	FILE* texto;

	
	
	
	if (sig == 1)
	{
		colision = 0;
		texto = fopen("./niveles/nivel.txt", "r");
		if (texto == NULL) printf("error");
		
		while (!feof(texto))
		{
			fflush(texto);
			fgets(datos, 20, texto);

			sscanf(datos, "%c", &n);
			printf("%c", n);

			if (n == 'n')
			{
				sscanf(datos, "%c %d", &n, &nivel);
				if (lvl == nivel)
				{
					sscanf(datos, "%c %d %d", &n, &nivel, &numcoches);
				}
				printf("%d \n", nivel);
				printf("%d \n", lvl);
			}
			if (n != 'n')
			{
				if (lvl == nivel)
				{
					sscanf(datos, "%f %f %d %d", &coches[i].pos.x, &coches[i].pos.y, &coches[i].tamaño, &coches[i].orientacion);
					puts(datos);
					printf("\n %f %f \n", coches[i].pos.x, coches[i].pos.y);
					i++;
					printf("%d \n", nivel);
				}
				
			}

		}
		fflush(texto);
		fclose(texto);
		i = 0;
		sig = 0;
		start = 1;
		reset = 1;
		lvl++;
		
	}
	
}
