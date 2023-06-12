/*Ejercicio 4 cooperativo 6*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



double leerx();
void meterenintervalo (double *x);
double funciony (double x);

int main()
{
	char c;


    double x, y;
	
	do
	{
		system("cls||clear");
		printf("Ejercicio 4\n");
		printf("==================\n\n");

		// Solucion

        x = leerx();
        meterenintervalo (&x);
        y = funciony (x);
        printf ("\ny = %.1lf", y);


		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}


double leerx()
{
    double x;

    printf ("\nIntroduce el valor de x: ");
    scanf (" %lf", &x);
    return x;
}

void meterenintervalo (double *x)
{
    if (*x < 0)
    {
        while (*x < 0)
        {
            *x = *x + 2;
        }
    }
    else 
    {
        if (*x > 2)
        {
            while (*x > 2)
            {
                *x = *x - 2;
            }
        }
    }
}

double funciony (double x)
{
    double y;

    if (x <= 1)
        y = x;
    else 
        y = 2 - x;
    return y;
}