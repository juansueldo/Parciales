#include "Contribuyente.h"

int eContribuyente_inicializar (eContribuyente arrayContribuyentes[],int tam)
{
	int i;
	int rtn = -1;
	if(arrayContribuyentes != NULL && tam >0)
	{

		for (i = 0; i < tam; ++i)
		{
			strcpy(arrayContribuyentes[i].nombre," ");
			strcpy(arrayContribuyentes[i].apellido," ");
			strcpy(arrayContribuyentes[i].cuil," ");
			arrayContribuyentes[i].idContribuyente = 0;
			arrayContribuyentes[i].isEmpty=1;
		}
		rtn = 0;
	}
	return rtn;
}
int eContribuyente_buscarLibre (eContribuyente arrayContribuyentes[],int tam)
{
	int rtn;
	int i;
	rtn = -1;
	if(arrayContribuyentes != NULL && tam > 0)
	{
		for (i = 0; i < tam; ++i)
		{
			if(arrayContribuyentes[i].isEmpty==1)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}
int eContribuyente_buscarId (eContribuyente arrayContribuyentes[],int tam,int id)
{
	int rtn = -1;
	int i;

	if (arrayContribuyentes != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (arrayContribuyentes[i].idContribuyente == id && arrayContribuyentes[i].isEmpty == 0) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
eContribuyente eContribuyente_cargarPantalla (void)
{
	eContribuyente auxContribuyente;

		if((utn_getString(auxContribuyente.nombre,30,"\nINGRESE EL NOMBRE DEL CONTRIUBUYENTE: ","\nERROR. INGRESE EL NOMBRE DEL CONTRIUBUYENTE: ",1,3)) != 0)
		{
			printf("\nERROR. NO SE INGRESO EL NOMBRE DEL CONTRIBUYENTE");
		}
		if((utn_getString(auxContribuyente.apellido,30,"\nINGRESE EL APELLIDO DEL CONTRIUBUYENTE: ","\nERROR. INGRESE EL APELLIDO DEL CONTRIUBUYENTE: ",1,3)) != 0)
		{
			printf("\nERROR. NO SE INGRESO EL APELLIDO DEL CONTRIBUYENTE");
		}
		if(utn_getCuil(auxContribuyente.cuil,"\nINGRESE EL CUIL DEL CONTIBUYENTE","\nERROR. INGRESE EL CUIL DEL CONTIBUYENTE",3) != 0)
		{
			printf("\nERROR. NO SE INGRESO EL CUIL DEL CONTRIBUYENTE");
		}

	return auxContribuyente;
}
int eContribuyente_alta (eContribuyente arrayContribuyentes[], int tam, int *pIdContador)
{
	int rtn = -1;
	eContribuyente auxContribuyente;

	int index = eContribuyente_buscarLibre (arrayContribuyentes, tam);

	if (index != -1)
	{
		auxContribuyente = eContribuyente_cargarPantalla();

		auxContribuyente.isEmpty = 0;
		rtn = 0;
	}
	if(rtn == 0)
	{
		(*pIdContador)++;
		auxContribuyente.idContribuyente = *pIdContador;
		arrayContribuyentes[index] = auxContribuyente;
	}


	return rtn;
}

