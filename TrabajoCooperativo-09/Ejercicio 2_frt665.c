#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXEL 3

typedef int tipomatriz[MAXEL][MAXEL];

void leermatriz (tipomatriz m);
void escribirmatriz (tipomatriz m);
void premultiplicarmatrices (tipomatriz a, tipomatriz b);

int main()
{
    char c;


    tipomatriz a, b;


    do
    {
        system("cls");
        printf("Ejercicio 2\n");
        printf("===========\n\n");


        printf ("\nPRIMERA MATRIZ");
        leermatriz (a);
        printf ("\nSEGUNDA MATRIZ");
        leermatriz (b);

        printf ("\nMatriz primera");
        escribirmatriz (a);
        printf ("\nMatriz segunda");
        escribirmatriz (b);

        premultiplicarmatrices (a, b);
        printf ("\nA <- B . A");
        escribirmatriz(a);



        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }
    while (c!='N');
    return 0;
}


void leermatriz (tipomatriz m)
{
    int i, j;

    for (i=0; i<MAXEL; i++)
    {
        for (j=0; j<MAXEL; j++)
        {
            printf ("\nIntroduce un numero: ");
            scanf (" %d", &m[i][j]);
        }
    }
}

void escribirmatriz (tipomatriz m)
{
    int i, j;

    printf ("\n");
    for (i=0; i<MAXEL; i++)
    {
        for (j=0; j<MAXEL; j++)
        {
            printf (" %5d", m[i][j]);
        }
        printf ("\n");
    }
}

void premultiplicarmatrices (tipomatriz a, tipomatriz b)
{
    int i, j, suma, k;
    tipomatriz mprod;

    for (i=0; i<MAXEL; i++)
    {
        for (j=0; j<MAXEL; j++)
        {
            suma = 0;
            for (k=0; k<MAXEL; k++)
            {
                suma = suma + b[i][k] * a[k][j];
            }
            mprod[i][j] = suma;
        }
    }

    for (i=0; i<MAXEL; i++)
    {
        for (j=0; j<MAXEL; j++)
        {
            a[i][j] = mprod[i][j];
        }
    }
}