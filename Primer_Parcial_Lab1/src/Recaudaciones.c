#include "Recaudaciones.h"

int eRecaudacion_inicializar (eRecaudacion arrayRecaudacion[],int tam)
{
	int i;
	int rtn = -1;
	if(arrayRecaudacion != NULL && tam >0)
	{

		for (i = 0; i < tam; ++i)
		{
			strcpy(arrayRecaudacion[i].mes," ");
			arrayRecaudacion[i].idTipo = 0;
			arrayRecaudacion[i].idRecaudacion = 0;
			arrayRecaudacion[i].idEstado = 0;
			arrayRecaudacion[i].importe = 0;
			arrayRecaudacion[i].isEmpty=1;
		}
		rtn = 0;
	}
	return rtn;
}
int eTipo_inicializar (eTipo arrayTipo[],int cant)
{
	int i;
	int rtn = -1;
	if(arrayTipo != NULL && cant >0)
	{

		for (i = 0; i < cant; ++i)
		{
			arrayTipo[i].idTipo = 0;
			strcpy(arrayTipo[i].descripcion," ");
		}
		rtn = 0;
	}
	return rtn;
}
int eEstado_inicializar (eEstado arrayEstado[],int cant)
{
	int i;
	int rtn = -1;
	if(arrayEstado != NULL && cant >0)
	{

		for (i = 0; i < cant; ++i)
		{
			arrayEstado[i].idEstado = 0;
			strcpy(arrayEstado[i].detalle," ");
		}
		rtn = 0;
	}
	return rtn;
}
int eRecaudacion_obtenerNombre (eTipo arrayTipo[],int cant,int tipo,char detalle[20])
{
	int rtn = -1;
	int i;
	if(arrayTipo != NULL && cant > 0 && (isdigit(tipo)) == 0  && detalle != NULL)
	{
		for (i = 0; i < cant; i++)
		{
			if(arrayTipo[i].idTipo == tipo)
			{
				if(arrayTipo[i].idTipo== 1)
				{
				strcpy(detalle,"ARBA");
				rtn = 0;
				break;
				}
				if(arrayTipo[i].idTipo== 2)
				{
					strcpy(detalle,"IIBB");
					rtn = 0;
				break;
				}
				if(arrayTipo[i].idTipo== 3)
				{
					strcpy(detalle,"GANANCIAS");
					rtn = 0;
				break;
				}

			}
		}
	}

	return rtn;
}
int eRecaudacion_obtenerEstado (eEstado arrayEstado[],int cant,int tipo,char detalle[20])
{
	int rtn = -1;
	int i;
	if(arrayEstado != NULL && cant > 0 && (isdigit(tipo)) == 0  && detalle != NULL)
	{
		for (i = 0; i < cant; i++)
		{
			if(arrayEstado[i].idEstado == tipo)
			{
				if(arrayEstado[i].idEstado == 1)
				{
				strcpy(detalle,"REFINANCIAR");
				rtn = 0;
				break;
				}
				if(arrayEstado[i].idEstado== 2)
				{
					strcpy(detalle,"SALDADO");
					rtn = 0;
				break;
				}

			}
		}
	}

	return rtn;
}
int eRecaudacion_buscarLibre (eRecaudacion arrayRecaudacion[],int tam)
{
	int ret;
	int i;
	ret = -1;
	if(arrayRecaudacion != NULL && tam > 0)
	{
		for (i = 0; i < tam; ++i)
		{
			if(arrayRecaudacion[i].isEmpty==1)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}
int eRecaudacion_buscarId (eRecaudacion arrayRecaudacion[],int tam,int id)
{
	int rtn = -1;
	int i;

	if (arrayRecaudacion != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (arrayRecaudacion[i].idRecaudacion == id && arrayRecaudacion[i].isEmpty == 0) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
eRecaudacion eRecaudacion_cargarPantalla (void)
{
	eRecaudacion auxiliar;

		if((utn_getString(auxiliar.mes,30,"\nINGRESE EL MES: ","\nERROR. INGRESE EL MES: ",1,3)) != 0)
		{
			printf("\nERROR NO SE INGRESO EL NOMBRE");
		}
		if(utn_getNumero(&auxiliar.idTipo,"\nINGRESE EL TIPO [1] ARBA [2] IIBB [3] GANANCIAS: ","\nERROR.INGRESE EL TIPO [1] ARBA [2] IIBB [3] GANANCIAS:",1,3,3) != 0)
		{
			printf("\n ERROR NO SE INGRESO EL TIPO");
		}
		if(utn_getFloat(&auxiliar.importe,"\nINGRESE EL IMPORTE [DEL 100 AL 9999999]; ","\nERROR. INGRESE EL IMPORTE [DEL 100 AL 9999999]; ",100,999999,3) !=0)
		{
			printf("\nERROR NO SE INGRESO EL IMPORTE");
		}
	return auxiliar;
}
int eRecaudacion_alta (eRecaudacion arrayRecaudacion[], int tam, int *pIdContador)
{
	int rtn = -1;
	eRecaudacion auxRecaudacion;

	int index = eRecaudacion_buscarLibre (arrayRecaudacion, tam);

	if (index != -1)
	{

		auxRecaudacion = eRecaudacion_cargarPantalla();

		auxRecaudacion.isEmpty = 0;
		rtn = 0;
	}
	if(rtn == 0)
	{
		(*pIdContador)++;
		auxRecaudacion.idRecaudacion = *pIdContador;
		arrayRecaudacion[index] = auxRecaudacion;
	}


	return rtn;
}
void eRecaudacion_mostrarUno (eRecaudacion arrayRecaudacion[],int tamanio, eTipo arrayTipo[], int cant)
{
	char detalle[30];
	eRecaudacion_obtenerNombre (arrayTipo,cant,arrayRecaudacion[tamanio].idTipo,detalle);
	utn_getMayusMin (arrayRecaudacion[tamanio].mes, MAX_CHARS_CADENAS);
	printf("\n%5d       %15s        "
			,arrayRecaudacion[tamanio].idRecaudacion
			,detalle);
}
