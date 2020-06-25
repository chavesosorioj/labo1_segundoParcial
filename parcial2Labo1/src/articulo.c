/*
 * articulo.c
 *
 *  Created on: Jun 25, 2020
 *      Author: juliana
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "articulo.h"
#include "Controller.h"
#include "LinkedList.h"
#include "utn.h"

eArticulo* articulo_new() {
	eArticulo *this;

	this = (eArticulo*)malloc(sizeof(eArticulo));

	if (this != NULL) {
		articulo_setId(this, 0);
		articulo_setArticulo(this, " ");
		articulo_setMedida(this, " ");
		articulo_setPrice(this, 0);
		articulo_setRubro(this, 0);
	}
	else
	{
		articulo_delete(this);
		printf("there is no memory\n");
	}
	return this;
}

eArticulo* articulo_newParametros(char *idStr, char *articuloStr, char *medidaStr, char *precioStr,
		char* rubroUnitStr, char* descuentoStr) {
	eArticulo *auxArticulo;
	eArticulo* ret=NULL;
	auxArticulo = articulo_new();

	int auxId;
	int auxPecio;
	int auxRubro;
	int auxDesc;

	if (auxArticulo!= NULL && idStr != NULL && articuloStr!= NULL
			&& precioStr!= NULL && medidaStr!= NULL && rubroUnitStr!= NULL && descuentoStr !=NULL) {

		auxId = atoi(idStr);
		auxPecio = atoi(precioStr);
		auxRubro= atoi(rubroUnitStr);
		auxDesc= atoi(descuentoStr);
		if (!articulo_setId(auxArticulo, auxId)
				&& !articulo_setArticulo(auxArticulo, articuloStr)
				&& !articulo_setMedida(auxArticulo, medidaStr)
				&& !articulo_setPrice(auxArticulo, auxPecio)
				&& !articulo_setRubro(auxArticulo, auxRubro)
				&& ! articulo_setDescuento(auxArticulo, auxDesc)
				) {
				ret = auxArticulo;
		} else {
			printf("esta liberando articulo\n");
			articulo_delete(auxArticulo);
		}
	}
	return ret;
}

void articulo_delete(eArticulo *this) {
	if (this != NULL) {
		free(this);
	}
}
int articulo_setId(eArticulo *this, int id) {
	int ret = -1;
	if (this != NULL && id > 0) {
		this->id = id;
		ret = 0;
	}
	return ret;
}
int articulo_getId(eArticulo *this, int *id) {
	int ret = -1;
	if (this != NULL) {
		*id = this->id;
		ret = 0;
	}
	return ret;
}
int articulo_setArticulo(eArticulo *this, char *articulo) {
	int ret = -1;
	if (this != NULL && articulo!= NULL) {
		strcpy(this->articulo, articulo);
		ret = 0;
	}
	return ret;
}
int articulo_getArticulo(eArticulo *this, char *articulo) {
	int ret = -1;

	if (this != NULL) {
		strcpy(articulo, this->articulo);
		ret = 0;
	}
	return ret;
}

int articulo_setPrice(eArticulo *this, int precio) {
	int ret = -1;
	if (this != NULL && precio > 0) {
		this->precio = precio;
		ret = 0;
	}
	return ret;
}
int articulo_getPrice(eArticulo *this, int *precio) {
	int ret = -1;
	if (this != NULL) {
		*precio = this->precio;
		ret = 0;
	}
	return ret;
}

int articulo_setMedida(eArticulo *this, char *medida) {
	int ret = -1;
	if (this != NULL && medida!= NULL) {
		strcpy(this->medida, medida);
		ret = 0;
	}
	return ret;
}
int articulo_getMedida(eArticulo *this, char *medida) {
	int ret = -1;

	if (this != NULL) {
		strcpy(medida, this->medida);
		ret = 0;
	}
	return ret;
}
int articulo_setRubro(eArticulo*this, int rubro) {
	int ret = -1;
	if (this != NULL && rubro >= 0) {
		this->rubroId.id = rubro;
		setRubroLetter(this, rubro);
		ret = 0;
	}
	return ret;
}

int setRubroLetter(eArticulo *this, int rubro) {
	int ret = -1;
	if (this != NULL) {
		ret = 0;
		switch (rubro) {
		case 0:
			articulo_setRubroChar(this, " ");
			break;
		case 1:
			articulo_setRubroChar(this, "CUIDADO DE ROPA");
			break;
		case 2:
			articulo_setRubroChar(this, "LIMPIEZA Y DESFINFECCION");
			break;
		case 3:
			articulo_setRubroChar(this, "CUIDADO PERSONAL E HIGIENE");
			break;
		case 4:
			articulo_setRubroChar(this, "CUIDADO DE AUTOMOTOR");
			break;
		}
	}
	return ret;
}
int articulo_setRubroChar(eArticulo*this, char *rubro) {
	int ret = -1;
	if (this != NULL && rubro != NULL) {
		strcpy(this->rubroId.idC, rubro);
		ret = 0;
	}
	return ret;
}
int articulo_getRubroC(eArticulo *this, char *rubro) {
	int ret = -1;

	if (this != NULL) {
		strcpy(rubro, this->rubroId.idC);
		ret = 0;
	}
	return ret;
}
int articulo_getRubroI(eArticulo *this, int *rubro) {
	int ret = -1;

	if (this != NULL) {
		*rubro = this->rubroId.id;
		ret = 0;
	}
	return ret;
}

int articulo_setDescuento(eArticulo *this, int descuento) {
	int ret = -1;
	if (this != NULL && descuento >= 0) {
		this->descuento = descuento;
		ret = 0;
	}
	return ret;
}
int articulo_getDescuento(eArticulo *this, int *descuento) {
	int ret = -1;
	if (this != NULL) {
		*descuento = this->descuento;
		ret = 0;
	}
	return ret;
}
int articulo_orderByArticulo(void *aux1, void *aux2) {
	int ret = 0;
	eArticulo *a1 = NULL;
	eArticulo *a2 = NULL;
	char articulo1[TAM];
	char articulo2[TAM];
	if (aux1 != NULL && aux2 != NULL) {
		a1 = (eArticulo*) aux1;
		a2 = (eArticulo*) aux2;
		articulo_getArticulo(a1, articulo1);
		articulo_getArticulo(a2, articulo2);
		if (strcmp(articulo1, articulo2) > 0) {
			ret = 1;
		} else if (strcmp(articulo1, articulo2) < 0) {
			ret = -1;
		}
	}
	return ret;
}
int articulo_orderById(void *aux1, void *aux2) {
	int ret = 0;
	eArticulo *a1 = NULL;
	eArticulo *a2 = NULL;
	int id1;
	int id2;
	if (aux1 != NULL && aux2 != NULL) {
		a1 = (eArticulo*) aux1;
		a2 = (eArticulo*) aux2;
		articulo_getId(a1, &id1);
		articulo_getId(a2, &id2);
		if (id1 > id2) {
			ret = 1;
		} else if (id1 < id2) {
			ret = -1;
		}
	}
	return ret;
}
void* artMap(void *auxS) {
	eArticulo *art = NULL;

	int precio;
	int rubro;
	int desc = 0;
	;
	art = (eArticulo*) auxS;
	if (auxS != NULL) {
		articulo_getPrice(art, &precio);
		articulo_getRubroI(art, &rubro);

		if (precio >= 120 && rubro == 1) {
			desc = precio * 0.20;
		} else if (precio <= 200 && rubro == 2) {
			desc = precio * 0.10;
		}

		articulo_setDescuento(auxS, desc);
	}
	return auxS;
}
int mayoresCien(void* auxS)
{
	int ret=-1;
	eArticulo* art=NULL;
	int  auxPrecio;

	if(auxS !=NULL)
	{
		art= (eArticulo*)auxS;
		articulo_getPrice(art, &auxPrecio);
		if(auxPrecio > 100)
			ret=0;
	}
	return ret;
}

int cantidadRubroUno(void* auxS)
{
	int ret=-1;
	eArticulo* art=NULL;
	int  auxRubro;

	if(auxS !=NULL)
	{
		art= (eArticulo*)auxS;
		articulo_getRubroI(art, &auxRubro);
		if(auxRubro == 1)
			ret=0;
	}
	return ret;
}
