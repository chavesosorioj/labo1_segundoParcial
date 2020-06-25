#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "articulo.h"

int parser_FromText(FILE *pFile, LinkedList *pArray) {
	int ret = -1;
	char buffer[5][100];
	int r;
	eArticulo *auxArticulo;

	if (pFile != NULL && pArray != NULL) {
		fscanf(
				pFile,                                        //lectura fantasma
				"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],
				buffer[2], buffer[3], buffer[4]);

		do {
			r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],
					buffer[1], buffer[2], buffer[3], buffer[4]);
			if (r != 5)
			{
				printf("\nError while trying to read the file\n");
			}
			else
			{
				auxArticulo = articulo_newParametros(buffer[0], buffer[1],buffer[2], buffer[3], buffer[4], "0");
				if (auxArticulo != NULL)
				{
					ll_add(pArray, auxArticulo);
				}
			}
		} while (!feof(pFile));
		ret = 0;
	}
	else {
		printf("Error\n");
	}
	return ret;
}
/*
int parser_FromBinary(FILE *pFile, LinkedList *pArray) {
	int ret = -1;
	//Employee *auxEmp;
	int r;

	if (pFile != NULL && pArray!= NULL) {
		do {
		//	auxEmp = employee_new();
	//		r = fread(auxEmp, sizeof(auxEmp), 1, pFile);
			if (r != 1) {
				printf("\nError while trying to read the file");
			} else {
		//		ll_add(pArray, auxEmp);
				ret = 0;
			}
		} while (!feof(pFile));
	} else {
		printf("\nError");
	}

	return ret;
}
*/
