/*Ejercicio 1 cooperativo 7*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>




void leerpunto (double *x, double *y);

char soncolineales (double x1, double y1, double x2, double y2, double x3, double y3);

void calcularcirculo (double x1, double y1, double x2, double y2, double x3, double y3,
                      double *xc, double *yc, double *r);
int main(){
    char c;


    double x1, y1, x2, y2, x3, y3, xc, yc, r;
    char coli;


    do{ system("cls");
        printf("Ejercicio 1\n");
        printf("=======================\n\n");



        printf ("\nPrimer punto");
        leerpunto (&x1, &y1);
        printf ("\nSegundo punto");
        leerpunto (&x2, &y2);
        printf ("\nTercer punto");
        leerpunto (&x3, &y3);
        coli = soncolineales (x1, y1, x2, y2, x3, y3);
        if (coli == 's')
            printf ("\nSon colineales");
        else
        {
            calcularcirculo (x1, y1, x2, y2, x3, y3, &xc, &yc, &r);
            printf ("\nCentro: (%.2lf, %.2lf) y radio: %.2lf", xc, yc, r);
        }




        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }while (c!='N');
    return 0;
}

void leerpunto (double *x, double *y)
{
    printf ("\nIntroduce coordenada x: ");
    scanf (" %lf", &*x);
    printf ("\nIntroduce coordenada y: ");
    scanf (" %lf", &*y);
}

char soncolineales (double x1, double y1, double x2, double y2, double x3, double y3)
{
    double v1x, v1y, v2x, v2y, p;
    char c;

    v1x = x1 - x2;
    v1y = y1 - y2;
    v2x = x3 - x2;
    v2y = y3 - y2;
    p = v1x * v2y - v1y * v2x;
    if (p == 0)
        c = 's';
    else
        c = 'n';
    return c;
}

void calcularcirculo (double x1, double y1, double x2, double y2, double x3, double y3,
                      double *xc, double *yc, double *r)
{
    *xc = ((y1-y3) * (y1-y2) * (y2-y3) + (y1-y3) * (x1*x1 - x2*x2) - (y1-y2) * (x1*x1 - x3*x3))
            / (2 * (y1-y3) * (x1-x2) - 2 * (y1-y2) * (x1-x3));
    *yc = ((x1-x3) * (x1-x2) * (x2-x3) + (x1-x3) * (y1*y1 - y2*y2) - (x1-x2) * (y1*y1 - y3*y3))
            / (2 * (x1-x3) * (y1-y2) - 2 * (x1-x2) * (y1-y3));
    *r = sqrt( pow(x1-(*xc), 2) + pow(y1-(*yc), 2));
}