/*Ejercicio 6 cooperativo 6*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


#define PI 3.14159
#define PRECISION 1e-3


void leerdatos (double *a, double *x);
void meterenintervalo (double *x, double p);
double calcularangulo (double a, double x);
double calculary (double a, double fi);

int main()
{
    char c;


    double a, x, p, fi, y;


    do
    {
        system("cls");
        printf("Ejercicio 6\n");
        printf("===============\n\n");


        leerdatos (&a, &x);
        p = 2 * PI * a;
        meterenintervalo (&x, p); 
        fi = calcularangulo (a, x);
        y = calculary (a, fi);
        printf ("\ny = %.3lf", y);




        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }
    while (c!='N');
    return 0;
}


void leerdatos (double *a, double *x)
{
    printf ("\nIntroduce el valor del radio: ");
    scanf (" %lf", &*a);
    printf ("\nIntroduce el valor de x: ");
    scanf (" %lf", &*x);
}

void meterenintervalo (double *x, double p)
{
    if (*x > p)
    {
        while (*x > p)
        {
            *x = *x - p;
        }
    }
    if (*x < 0)
    {
        while (*x < 0)
        {
            *x = *x + p;
        }
    }
}

double calcularangulo (double a, double x)
{
    double fi;

    fi = 0;
    while (x >= a * (fi - sin(fi)))
    {
        fi = fi + PRECISION;
    }
    return fi - PRECISION;
}

double calculary (double a, double fi)
{


    return a * (1 - cos(fi));
}