/*
 * articulo.h
 *
 *  Created on: Jun 25, 2020
 *      Author: juliana
 */

#ifndef ARTICULO_H_
#define ARTICULO_H_
#define TAM 200
typedef struct{
	int id;
	char idC[TAM];
}eRubro;

typedef struct{
	int id;
	char articulo[TAM];
	char medida[TAM];
	int precio;
	eRubro rubroId;
	int descuento;
}eArticulo;

eArticulo* articulo_new();
eArticulo* articulo_newParametros(char *idStr, char *articuloStr, char *medidaStr, char *precioStr,
		char* rubroUnitStr, char* descuentoStr);
void articulo_delete(eArticulo* this);
int articulo_setId(eArticulo *this, int id);
int articulo_getId(eArticulo *this, int *id);
int articulo_setArticulo(eArticulo *this, char *articulo);
int articulo_getArticulo(eArticulo *this, char *articulo);
int articulo_setPrice(eArticulo*this, int precio);
int articulo_getPrice(eArticulo*this, int *precio);
int articulo_getMedida(eArticulo *this, char *medida);
int articulo_setMedida(eArticulo *this, char *medida);
int articulo_setRubro(eArticulo *this, int rubro);
int articulo_setRubro(eArticulo*this, int rubro);
int setRubroLetter(eArticulo*this, int rubro);
int articulo_setRubroChar(eArticulo*this, char *rubro);
int articulo_getRubroC(eArticulo *this, char *rubro);
int articulo_getRubroI(eArticulo *this, int *rubro);
int articulo_setDescuento(eArticulo *this, int descuento);
int articulo_getDescuento(eArticulo *this, int *descuento);
int articulo_orderByArticulo(void *aux1, void *aux2);
int articulo_orderById(void *aux1, void *aux2);
void* artMap(void *auxS);
int mayoresCien(void* auxS);
int cantidadRubroUno(void* auxS);
#endif /* ARTICULO_H_ */
