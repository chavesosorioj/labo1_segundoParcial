/*
 * sale.c
 *
 *  Created on: Jun 18, 2020
 *      Author: juliana
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "Controller.h"
#include "LinkedList.h"
#include "sale.h"
#include "utn.h"

Sale* sale_new() {
	Sale *this;

	this = (Sale*)malloc(sizeof(Sale));	// CAMBIAR SETERS

	if (this != NULL) {
		sale_setId(this, 0);
		sale_setDate(this, " ");
		sale_setProduct(this, " ");
		sale_setCuantity(this, 0);
		sale_setPriceUnit(this, 0);
		sale_setCuit(this, " ");
	}
	else
	{
		sale_delete(this);
		printf("there is no memory\n");
	}
	return this;
}
Sale* sale_newParametros(char *idStr, char *dateStr, char *productStr,
		char *cuantityStr, char* priceUnitStr, char* cuitStr) {
	Sale *auxSale;
	Sale* ret=NULL;
	auxSale = sale_new();

	int auxId;
	int auxCuantity;
	float auxPriceUnit;

	if (auxSale!= NULL && idStr != NULL && dateStr != NULL
			&& productStr != NULL && cuantityStr != NULL && priceUnitStr != NULL && cuitStr != NULL) {

		auxId = atoi(idStr);
		auxCuantity = atoi(cuantityStr);
		auxPriceUnit= atof(priceUnitStr);
		if (!sale_setId(auxSale, auxId) && !sale_setDate(auxSale, dateStr)
				&& !sale_setProduct(auxSale, productStr)
				&& !sale_setCuantity(auxSale, auxCuantity)
				&& !sale_setPriceUnit(auxSale, auxPriceUnit)
				&& !sale_setCuit(auxSale, cuitStr)
				) {
				ret = auxSale;
		} else {
			printf("esta liberando Sale\n");
			sale_delete(auxSale);
		}
	}
	return ret;
}
void sale_delete(Sale *this) {
	if (this != NULL) {
		free(this);
	}
}

int sale_setId(Sale *this, int id) {
	int ret = -1;
	if (this != NULL && id > 0) {
		this->id = id;
		ret = 0;
	}
	return ret;
}
int sale_getId(Sale *this, int *id) {
	int ret = -1;
	if (this != NULL) {
		*id = this->id;
		ret = 0;
	}
	return ret;
}
int sale_setDate(Sale *this, char *date) {
	int ret = -1;
	if (this != NULL && date !=NULL) {
		strcpy(this->date,date);
		ret = 0;
	}
	return ret;
}

int sale_getDate(Sale *this, char *date) {
	int ret = -1;
	if (this != NULL) {
		strcpy(date, this->date);
		ret = 0;
	}
	return ret;
}

int sale_setProduct(Sale *this, char *product) {
	int ret = -1;
	if (this != NULL && product != NULL) {
		strcpy(this->product, product);
		ret = 0;
	}
	return ret;
}
int sale_getProduct(Sale *this, char *product) {
	int ret = -1;

	if (this != NULL) {
		strcpy(product, this->product);
		ret = 0;
	}
	return ret;
}

int sale_setCuantity(Sale *this, int cuantity) {
	int ret = -1;
	if (this != NULL && cuantity > 0) {
		this->cuantity= cuantity;
		ret = 0;
	}
	return ret;
}
int sale_getCuantity(Sale *this, int *cuantity) {
	int ret = -1;
	if (this != NULL) {
		*cuantity = this->cuantity;
		ret = 0;
	}
	return ret;
}

int sale_setPriceUnit(Sale *this, float price) {
	int ret = -1;
	if (this != NULL && price>0) {
		this->priceUnit=price;
		ret = 0;
	}
	return ret;
}
int sale_getPriceUnit(Sale *this, float *price) {
	int ret = -1;
	if (this != NULL) {
		*price=this->priceUnit;
		ret = 0;
	}
	return ret;
}

int sale_setCuit(Sale *this, char* cuit) {
	int ret = -1;
	if (this != NULL && cuit !=NULL) {
		strcpy(this->cuit,cuit);
		ret = 0;
	}
	return ret;
}
int sale_getCuit(Sale *this, char *cuit) {
	int ret = -1;
	if (this != NULL) {
		strcpy(cuit,this->cuit);
		ret = 0;
	}
	return ret;
}
/*
int sale_orderByName(void *aux1, void *aux2) {
	int ret = 0;
	Sale *s1 = NULL;
	Sale *s2 = NULL;
	char name1[200];
	char name2[200];
	if (aux1 != NULL && aux2 != NULL) {
		s1 = (Sale*) aux1;
		s2 = (Sale*) aux2;
		sale_getName(s1, name1);
		sale_getName(s2, name2);
		if (strcmp(name1, name2) > 0) {
			ret = 1;
		} else if (strcmp(name1, name2) < 0) {
			ret = -1;
		}
	}
	return ret;
}
int sale_orderById(void *aux1, void *aux2) {
	int ret = 0;
	Sale *s1 = NULL;
	Sale *s2 = NULL;
	int id1;
	int id2;
	if (aux1 != NULL && aux2 != NULL) {
		s1 = (Sale*) aux1;
		s2 = (Sale*) aux2;
		sale_getId(s1, &id1);
		sale_getId(s2, &id2);
		if (id1 > id2) {
			ret = 1;
		} else if (id1 < id2) {
			ret = -1;
		}
	}
	return ret;
}
*/
/*
void* soldMap(void *auxS) {
	Sale *sale = NULL;
	int auxDay;
	int auxCuant;
	int price;
	int auxAmount;
	sale = (Sale*) auxS;
	if (auxS != NULL) {
		sale_getDayInt(auxS, &auxDay);
		sale_getCuantity(auxS, &auxCuant);

		if (auxDay <=1 || auxDay <=3) {
			price = 240;
		} else {
			price = 350;
		}
		if (auxCuant > 3) {
			price -= (price * 0.10);
		}
		auxAmount = price * auxCuant;
		sale_setAmount(sale, auxAmount);
	}
	return auxS;
*/

int unidadesTotales(void* auxS)
{
	int ret=-1;
	Sale* sale=NULL;
	int  auxId;

	if(auxS !=NULL)
	{
		sale= (Sale*)auxS;
		sale_getId(sale, &auxId);
		ret=0;
	}
	return ret;
}

int mayoresDiezMil(void* auxS)
{
	int ret=-1;
	Sale* sale=NULL;
	float  auxPrice;

	if(auxS !=NULL)
	{
		sale= (Sale*)auxS;
		sale_getPriceUnit(sale, &auxPrice);
		if(auxPrice >= 10000)
			ret=0;
	}
	return ret;
}
int mayoresVeinteMil(void* auxS)
{
	int ret=-1;
	Sale* sale=NULL;
	float  auxPrice;

	if(auxS !=NULL)
	{
		sale= (Sale*)auxS;
		sale_getPriceUnit(sale, &auxPrice);
		if(auxPrice >= 20000)
			ret=0;
	}
	return ret;
}
int cuantTv(void* auxS)
{
	int ret=-1;
	Sale* sale=NULL;
	char auxProd[100];

	if(auxS !=NULL)
	{
		sale= (Sale*)auxS;
		sale_getProduct(sale, auxProd);
		if(strcmp(auxProd,"LCD_TV")==0){
			ret=0;
		}
	}
	return ret;
}
