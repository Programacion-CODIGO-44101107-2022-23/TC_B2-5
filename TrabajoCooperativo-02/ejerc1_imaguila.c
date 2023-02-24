/*
 * @authors imaguila
 * @project TC1 Ejercicio 1 (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-XX
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>




int main(){
	char c;

	do{ system("cls||clear");
			printf("\n");
			printf("======\n\n");


			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			scanf(" %c",&c);
	}while ((c!='N') && (c!='n'));
	return 0;
}