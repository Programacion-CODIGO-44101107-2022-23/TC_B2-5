/*Ejercicio 5 cooperativo 6*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void leerdatos (double *p, double *h, double *a, double *e, double *t);
double leerx();
void meterenintervalo (double *x, double p);
double funciony (double x, double p, double h, double a, double e, double t);

int main()
{
	char c;


    double p, h, a, e, t, x, y;
	
	do
	{
		system("cls||clear");
		printf("Ejercicio 5\n");
		printf("==============\n\n");


        leerdatos (&p, &h, &a, &e, &t);
        x = leerx();
        meterenintervalo (&x, p);
        y = funciony (x, p, h, a, e, t);
        printf ("\ny = %lf", y);


		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}


void leerdatos (double *p, double *h, double *a, double *e, double *t)
{
    printf ("\nIntroduce el valor del periodo: ");
    scanf (" %lf", &*p);
    printf ("\nIntroduce el valor de la altura: ");
    scanf (" %lf", &*h);
    printf ("\nIntroduce el valor del ancho: ");
    scanf (" %lf", &*a);
    printf ("\nIntroduce el valor del ancho del escalon: ");
    scanf (" %lf", &*e);
    printf ("\nIntroduce el valor del desfase: ");
    scanf (" %lf", &*t);
}

double leerx()
{
    double x;

    printf ("\nIntroduce el valor de x: ");
    scanf (" %lf", &x);
    return x;
}

void meterenintervalo (double *x, double p)
{
    if (*x < 0)
    {
        while (*x < 0)
        {
            *x = *x + p;
        }
    }
    else 
    {
        if (*x > p)
        {
            while (*x > p)
            {
                *x = *x - p;
            }
        }
    }
}

double funciony (double x, double p, double h, double a, double e, double t)
{
    double y;

    if (x <= a/2+t)
        y = h;
    else 
    {
        if (x <= a/2+t+e)
            y = (-h * (x - a/2 - t)) / e + h;
        else 
        {
            if (x <= p - (a/2-t) - e)
                y = 0;
            else 
            {
                if (x <= p - (a/2-t))
                    y = h * (x - p + a/2 - t + e) / e;
                else 
                    y = h;
            }
        }
    }
    return y;
}