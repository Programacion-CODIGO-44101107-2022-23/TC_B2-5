/*Ejercicio 4 cooperativo 4*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;

    double x, suma;
    int n, i;

	
	do
	{
		system("cls||clear");
		printf("Nombre\n");
		printf("=================================\n\n");



        printf ("\nIntroduce un numero real entre -1 y +1: ");
        scanf (" %lf", &x);
        if (x <= -1 || x >= +1)
            printf ("\nValor no valido, debe estar entre -1 y +1");
        else
        {
            printf ("\nIntroduce un numero entero positivo: ");
            scanf (" %d", &n);
            if (n <= 0)
                printf ("\nError, tiene que ser entero positivo mayor que 0");
            else 
            {
                suma = 0;
                for (i=1; i<=n; i++)
                {
                    if (i % 2 != 0)
                        suma = suma + pow(x, i) / i;
                    else 
                        suma = suma - pow(x, i) / i;
                }
                printf ("\nS(x) = %.15lf", suma);
            }
        }

		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}