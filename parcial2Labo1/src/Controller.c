#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "articulo.h"
#include "parser.h"
#include "report.h"
#include "utn.h"
#include "menu.h"

int controller_loadFromText(char *path, LinkedList *pArray) {
	int ret = -1;
	FILE *pFile;

	if (path != NULL && pArray != NULL) {

		pFile = fopen(path, "r");
		if (pFile != NULL) {

			parser_FromText(pFile, pArray);
			ret = 0;
		} else {
			printf("file is null\n");
		}
	} else {
		printf("\nThe file doesn't exit");
	}
	if ((fclose(pFile)) == -1) {
		printf("\nThe file could not be closed\n");
	} else {
		printf("\nFile closed successtully\n");
	}
	return ret;
}

int controller_List(LinkedList *pArray) {
	int ret = -1;
	eArticulo *bufferStuct = NULL;
	int i;
	int auxId;
	char auxArt[TAM];
	int auxPrecio;
	char auxMedida[TAM];
	char auxRubro[TAM];
	int auxDesc;

	if (pArray != NULL) {

		if (ll_len(pArray) == 0) {
			printf("The list is empty\n");
			free(bufferStuct);
		} else {
			printf("\nID  - ARTICULO     -     PRECIO  -  MEDIDA - RUBRO     -   DESCUENTO\n");
			for (i = 0; i < ll_len(pArray); i++) {
				bufferStuct = ll_get(pArray, i);
				if (bufferStuct != NULL) {
					if (!articulo_getId(bufferStuct, &auxId)
							&& !articulo_getArticulo(bufferStuct, auxArt)
							&& !articulo_getPrice(bufferStuct, &auxPrecio)
							&& !articulo_getMedida(bufferStuct, auxMedida)
							&& !articulo_getRubroC(bufferStuct, auxRubro)
							&& !articulo_getDescuento(bufferStuct, &auxDesc)
				) {

						printf("%d  - %s     -     %d  -  %s - %s     -   %d\n", auxId, auxArt,
								auxPrecio, auxMedida, auxRubro, auxDesc);
						ret = 0;
					}
				}
			}
		}
	}
	return ret;
}


int controller_sort(LinkedList *pArray) {
	int ret = -1;

	if (pArray != NULL) {
		switch (menuTwo()) {
		case 1:
			ll_sort(pArray, articulo_orderByArticulo, 1);
			break;
		case 2:
			ll_sort(pArray, articulo_orderByArticulo, 0);
			break;
		case 3:
			ll_sort(pArray,  articulo_orderById, 1);
			break;
		case 4:
			ll_sort(pArray,  articulo_orderById, 0);
			break;
		}
		ret = 0;
	}
	return ret;
}

int controller_listReport(LinkedList* pArray)
{
	int ret=-1;
	int auxPrecio;
	int auxCantidad;

	if(pArray!=NULL)
	{
		reports(pArray, &auxPrecio, &auxCantidad);

		printf("\nCantidad de articulos con precio mayor a $100: %d\n",auxPrecio);
		printf("Cantidad de ariculos del Rubro I - CUIDADO DE ROPA %d\n",auxCantidad);
		ret=0;
	}
	return ret;
}

int controller_saveAsText(char *path, LinkedList *pArray) {
	int ret = -1;
	FILE *pFile = NULL;
	eArticulo *auxArt = NULL;
	int leng;
	int i;
	int auxId;
	char auxArticulo[TAM];
	int auxPrecio;
	char auxMedida[TAM];
	char auxRubro[TAM];
	int auxDesc;

	if (path != NULL && pArray != NULL) {
		pFile = fopen(path, "w+");
		if (pFile != NULL) {

			leng = ll_len(pArray);
			fprintf(pFile,
					"ID_VENTA, ARTICULO, MEDIDA, PRECIO, RUBRO, DESCUENTO\n");
			for (i = 0; i < leng; i++) {
				auxArt = ll_get(pArray, i);
				if (auxArt != NULL) {
					if (!articulo_getId(auxArt, &auxId)
							&& !articulo_getArticulo(auxArt, auxArticulo)
							&& !articulo_getPrice(auxArt, &auxPrecio)
							&& !articulo_getMedida(auxArt, auxMedida)
							&& !articulo_getRubroC(auxArt, auxRubro)
							&& !articulo_getDescuento(auxArt, &auxDesc)) {
						fprintf(pFile, "%d,  %s,  %d, %s, %s, %d \n", auxId,
								auxArticulo, auxPrecio, auxMedida, auxRubro,
								auxDesc);
					} else {
						articulo_delete(auxArt);
					}
				}

			}
			ret = 0;
			printf("File saved successfully\n");
			if ((fclose(pFile)) == -1) {
				printf("The file could not be closed\n");
			} else {
				printf("File closed successtully\n");
				ret = 0;
			}
		} else {
			printf("File doesnt exits\n");
		}
	}
	return ret;
}

