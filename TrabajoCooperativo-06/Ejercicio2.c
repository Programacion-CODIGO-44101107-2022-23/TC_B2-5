/*Ejercicio 2 cooperativo 6*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void leerecuacion (double *a, double *b, double *c);
void resolverecuacion (double a1, double b1, double c1, double a2, double b2, 
                        double c2, char *codigo, double *x, double *y);
void escribirsolucion (char codigo, double x, double y);

int main()
{
	char c;

    double a1, b1, c1, a2, b2, c2, x, y;
    char codigo;

	
	do
	{
		system("cls||clear");
		printf("Ejercicio 2\n");
		printf("================\n\n");


        printf ("\nSistema de dos ecuaciones con dos incognitas");
        printf ("\nEcuaciones del tipo: ax + by + c = 0");
        printf ("\nIntroduce datos de la primera ecuacion");
        leerecuacion (&a1, &b1, &c1);
        printf ("\nIntroduce datos de la segunda ecuacion");
        leerecuacion (&a2, &b2, &c2);

        resolverecuacion (a1, b1, c1, a2, b2, c2, &codigo, &x, &y);

        escribirsolucion (codigo, x, y);
        


		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}

void leerecuacion (double *a, double *b, double *c)
{
    printf ("\nIntroduce termino de x: ");
    scanf (" %lf", &*a);
    printf ("\nIntroduce termino de y: ");
    scanf (" %lf", &*b);
    printf ("\nIntroduce termino independiente: ");
    scanf (" %lf", &*c);
}

void resolverecuacion (double a1, double b1, double c1, double a2, double b2, 
                        double c2, char *codigo, double *x, double *y)
{
    if (a1==0 && b1==0 && c1==0 && a2==0 && b2==0 && c2==0)
        *codigo = '0';
    else 
    {
        if (a1 * b2 - a2 * b1 == 0)
        {
            if (a1/a2 == b1/b2 && a1/a2 == c1/c2)
                *codigo = 'M';
            else 
                *codigo = 'I';
        }
        else 
        {
            *codigo = 'C';
            *y = ((a2*c1 / a1) - c2) / (b2 - (a2*b1 / a1));
            if (a1 == 0)
                *x = (-c2 - b2*(*y)) / a2;
            else 
                *x = (-c1 - b1*(*y)) / a1;
        }
    }
}

void escribirsolucion (char codigo, double x, double y)
{
    switch (codigo)
    {
        case '0': printf ("\nIgualdades 0 = 0");
                  break;
        case 'I': printf ("\nSistema incompatible");
                  break;
        case 'M': printf ("\nSistema compatible indeterminado");
                  break;
        case 'C': printf ("\nSistema compatible determinado");
                  printf ("\nSolucion: x = %.2lf   y = %.2lf", x, y);
                  break;
    }
}