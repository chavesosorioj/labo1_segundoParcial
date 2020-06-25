/*
 * report.c
 *
 *  Created on: Jun 23, 2020
 *      Author: juliana
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Controller.h"
#include "articulo.h"


int reports(LinkedList *this, int *precio, int *cantidad) {
	int ret = -1;
	int auxPrecio;
	int auxCantidad;
	if (this != NULL) {
		ret = 0;
		auxPrecio = ll_count(this, mayoresCien);
		if (auxPrecio != -1) {
			*precio = auxPrecio;
		}
		auxCantidad = ll_count(this, cantidadRubroUno);
		if (auxCantidad != -1) {
			*cantidad = auxCantidad;
		}
	}

	return ret;
}
