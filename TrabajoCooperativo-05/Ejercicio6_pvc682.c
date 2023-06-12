/*Ejercicio 6 cooperativo 5*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;
  	// Variables 

    int n, suma, i, j;

	
	do
	{
		system("cls||clear");
		printf("nombre\n");
		printf("==========================\n\n");

		// Solucion


        do
        {
            printf ("\nIntroduce un numero natural menor de 20: ");
            scanf (" %d", &n);
        } while (n <= 0 || n >= 20);

        //tendría que calcular el numero por el que voy a empezar a escribir
        //en la fila 1 hay 1 numero, en la fila 2 hay 2 numeros, .....
        //el total de numeros es: 1+2+3+....+n
        //puedo hacer esta cuenta con un bucle for o puedo utilizar la formula
        //que existe para esa progresion aritmetica: n * (n+1) / 2
        suma = 0;
        for (i=1; i<=n; i++)
        {
            suma = suma + i;
        }

        //ahora escribo el triangulo empezando por suma y restando de 1 en 1
        //cada vez que escribo
        //tengo tantas lineas como n
        for (i=1; i<=n; i++)
        {
            //escribir asteriscos de cada linea
            for (j=1; j<=i; j++)
            {
                printf ("%3d ", suma);
                suma--;
            }
            printf ("\n");
        }



		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}