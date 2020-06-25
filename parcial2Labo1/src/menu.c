/*
 * menu.c
 *
 *  Created on: May 7, 2020
 *      Author: juliana
 */

#include "menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

#include "utn.h"

int menu() {
	int option;
	printf("\n*************************M E N U*************************\n");
	printf("1 - Charge file's data from data.csv (text mode) \n");
	printf("2 - Sort by ARTICULO\n");
	printf("3 - List\n");
	printf("4 - Reports\n");
	printf("5 - Save data in file data.cvs(text mode)\n");
	printf("6 - Exit\n");

	option = validInt("Option:\n");
	while (option < 0 || option > 10) {
		option = validInt("\nWrong number. try again");
	}
	__fpurge(stdin);

	printf("\nChosen option: %d\n", option);
	return option;
}

int menuOne() {
	int option;
	printf("\n******\n");
	printf("1 - \n");
	printf("2 - \n");
	printf("3 - \n");
	printf("4 - \n");
	option = validInt("Option:\n");
	while (option < 0 || option > 4) {
		option = validInt("\nWrong number. Try againg\n");
	}

	printf("\nChosen option: %d\n", option);
	return option;
}

int menuTwo() {
	int option;
	printf("\n*******SORT*******\n");
	printf("\n  1 - Articulo orden ascendente \n");
	printf("\n  2 - Articulo orden descendente\n");
	printf("\n  3 - ID orden ascendente\n");
	printf("\n  4 - ID orden descendente\n");
	option = validInt("Option:\n");
	__fpurge(stdin);
	while (option < 0 || option > 8) {
		option = validInt("\nWrong number. Try againg\n");
	}
	printf("\nChosen option: %d\n", option);
	return option;
}

int menuThree() {
	int option;

	option = validInt("\n1 - Ascending order- \n2 - Descending order");
	__fpurge(stdin);
	while (option != 1 && option != 2) {
		option = validInt("\nWrong number. Try againg\n");
	}

	printf("\nChosen option: %d\n", option);
	return option;
}

int menuFour() {
	int option;
	printf("\n***Enter the report you want to see****\n");
	printf("  Total units sold\n");
	printf("  Sales over $10000\n");
	printf("  Sales over $20000\n");
	printf("  Total TVs and LCD sold\n");
	option = validInt("Option:\n");
	__fpurge(stdin);
	while (option < 0 || option > 8) {
		option = validInt("\nWrong number. Try againg\n");
	}
	printf("\nChosen option: %d\n", option);
	return option;
}
