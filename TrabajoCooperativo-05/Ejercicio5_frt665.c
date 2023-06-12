/*Ejercicio 5 cooperativo 5*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;
  	// Variables 

    int n, i, j, asteriscos, espacios;

	
	do
	{
		system("cls||clear");
		printf("nombre\n");
		printf("=====================\n\n");

		// Solucion

        do
        {
            printf ("\nIntroduce un numero natural menor de 20: ");
            scanf (" %d", &n);
        } while (n <= 0 || n >= 20);

        if (n % 2 == 0)
        {
            //el numero es par y escribo un triangulo rectangulo
            //tengo tantas lineas como n
            for (i=1; i<=n; i++)
            {
                //escribir asteriscos de cada linea
                for (j=1; j<=i; j++)
                {
                    printf ("*");
                }
                printf ("\n");
            }
        }
        else 
        {
            //el numero es impar y escribo un rombo
            //tengo que escribir tantas lineas como n
            //en la primera linea tengo 1 asterisco, luego 3, 5, .... (le sumo 2)
            //hasta que llego a la mitad y tengo que ir 5, 3, 1 (restando 2)
            //cuidado, los espacios a la izquierda SI hay que pintarlos
            //el numero de espacios por la izquierda en la primera linea es (n-1)/2
            //en cada linea se va reduciendo en 1, hasta que llega a la mitad y 
            //se va incrementando en 1
            asteriscos = 1;
            espacios = (n-1) / 2;
            for (i=1; i<=n; i++)
            {
                //escribo primero los espacios a la izquierda de la linea
                for (j=1; j<=espacios; j++)
                {
                    printf (" ");
                }
                //y luego escribo los asteriscos de la linea
                for (j=1; j<=asteriscos; j++)
                {
                    printf ("*");
                }
                printf ("\n");
                if (i <= n/2)
                {
                    asteriscos = asteriscos + 2;
                    espacios--;
                }
                else 
                {
                    asteriscos = asteriscos - 2;
                    espacios++;
                }
            }
        }
        


		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}