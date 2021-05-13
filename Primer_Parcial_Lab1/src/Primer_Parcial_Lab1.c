/*
 ============================================================================
 Name        : Primer_Parcial_Lab1.c
 Author      : Juan Sueldo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Contribuyente.h"
#include "Recaudaciones.h"

int main()
{
    setbuf(stdout, NULL);

	int opcion;
	int flagAlta = 0;
	int flagAtlaR = 0;
	int contIdContribuyente = 1000;
	int contIdRecaudaciones = 1000;


	eContribuyente arrayContribuyentes[MAX];
	eRecaudacion arrayRecaudadores [CANT];


    eContribuyente_inicializar(arrayContribuyentes, MAX);
    eRecaudacion_inicializar(arrayRecaudadores, CANT);


	do
	{
		utn_menu(&opcion, "\nMenu\n1. ALTA COTRIBUYENTE \n4. ALTA RECAUDADACIONES\n10. Salir \n Ingrese:", "\nNO ES VALIDO\n", 1, 10,10);

		switch (opcion)
		{

		case 1:
			if (eContribuyente_alta(arrayContribuyentes, MAX, &contIdContribuyente)==0)
			{
				printf("\nALTA EXITOSA\n");
				flagAlta = 1;
			}
			else
			{
				printf("\nERROR. SIN ESPACIO PARA ALMACENAR");
			}
			system("pause");
			break;
		case 2:

			system("pause");
			break;
		case 3:

			system("pause");
			break;
		case 4:
			if(flagAlta == 1)
			{
			if (eRecaudacion_alta(arrayRecaudadores, CANT, &contIdRecaudaciones)==0)
			{
				printf("\nALTA EXITOSA\n");
				flagAlta = 1;
			}
			else
			{
				printf("\nERROR. SIN ESPACIO PARA ALMACENAR");
			}
			}
			system("pause");
			break;
		case 5:

			 break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		}
	} while (opcion != 10);

	puts("\nFIN.");

	return 0;
}


