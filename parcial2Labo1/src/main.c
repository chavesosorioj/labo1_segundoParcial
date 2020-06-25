/*
 ============================================================================
 Name        : parcial2Labo1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "articulo.h"
#include "menu.h"
#include "parser.h"
#include "report.h"
#define ARTICULOS "Datos_SP_LABO1.csv"
#define ART_MAPEADOS "mapeados.csv"
int main(void) {

	LinkedList *articulosLimp = ll_newLinkedList();
	LinkedList *articuloDescuentos = NULL;
	int option;

	do {
		option = menu();
		switch (option) {
		case 1:
			if (controller_loadFromText(ARTICULOS, articulosLimp) == 0) {
				articuloDescuentos = ll_map(articulosLimp, artMap);
				}
			break;
		case 2:
			controller_sort(articuloDescuentos);
			break;
		case 3:
			controller_List(articuloDescuentos);
			break;
		case 4:
			controller_listReport(articuloDescuentos);
			break;
		case 5:
			controller_saveAsText(ART_MAPEADOS, articuloDescuentos);
			break;
		case 6:
			ll_deleteLinkedList(articulosLimp);
			ll_deleteLinkedList(articuloDescuentos);
			break;
		}
	} while (option != 6);

	return EXIT_SUCCESS;
}
