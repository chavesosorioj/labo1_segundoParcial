/*
 * sale.h
 *
 *  Created on: Jun 18, 2020
 *      Author: juliana
 */

#ifndef SALE_H_
#define SALE_H_
#define TAM_NAME 50

typedef struct {
	int id;
	char date[20];
	char product[100];
	int cuantity;
	float priceUnit;
	char cuit[50];
} Sale;
#include "LinkedList.h"

Sale* sale_new();
Sale* sale_newParametros(char *idStr, char *dateStr, char *productStr,
		char *cuantityStr, char* priceUnitStr, char* cuitStr);
void sale_delete(Sale *this);
int sale_setId(Sale *this, int id);
int sale_getId(Sale *this, int *id);

int sale_setProduct(Sale *this, char *product);
int sale_getProduct(Sale *this, char *product);

int sale_setPriceUnit(Sale *this, float price);
int sale_getPriceUnit(Sale *this, float *price);

int sale_setCuit(Sale *this, char* cuit);
int sale_getCuit(Sale *this, char *cuit);

int sale_setCuantity(Sale *this, int cuantity);
int sale_getCuantity(Sale *this, int *cuantity);

int sale_setDate(Sale *this, char *date);
int sale_getDate(Sale *this, char *date);

//int sale_orderByName(void *aux1, void *aux2);
//int sale_orderById(void *aux1, void *aux2);
//void* soldMap(void *auxS);

int unidadesTotales(void* auxS);
int mayoresDiezMil(void* auxS);
int mayoresVeinteMil(void* auxS);
int cuantTv(void* auxS);
#endif /* SALE_H_ */
