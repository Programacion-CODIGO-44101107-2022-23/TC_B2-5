#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define NF 3
#define NC 3

typedef double tipoimagen[NF][NC];

void leerimagen (tipoimagen m);
void escribirimagen (tipoimagen m);
double calcularpolucionmedia (tipoimagen m);
void escribirsuperiores (tipoimagen m, double media);

int main()
{
    char c;


    tipoimagen m;
    double media;


    do
    {
        system("cls");
        printf("Ejercicio 3\n");
        printf("===========\n\n");


        leerimagen (m);
        
        escribirimagen (m);

        media = calcularpolucionmedia (m);
        printf ("\nPolucion media: %.3lf", media);
        escribirsuperiores (m, media);



        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }
    while (c!='N');
    return 0;
}


void leerimagen (tipoimagen m)
{
    int i, j;

    for (i=0; i<NF; i++)
    {
        for (j=0; j<NC; j++)
        {
            do
            {
                printf ("\nIntroduce un valor de polucion (entre 0 y 1): ");
                scanf (" %lf", &m[i][j]);
            } while (m[i][j] < 0 || m[i][j] > 1);
        }
    }
}

void escribirimagen (tipoimagen m)
{
    int i, j;

    printf ("\nDatos de Entrada:\n");
    printf ("   ");
    for (j=0; j<NC; j++)
    {
        printf (" %5d", j+1);
    }
    printf ("\n");

    for (i=0; i<NF; i++)
    {
        printf ("%3d", i+1);
        for (j=0; j<NC; j++)
        {
            printf (" %.3lf", m[i][j]);
        }
        printf ("\n");
    }
}


double calcularpolucionmedia (tipoimagen m)
{
    int i, j;
    double suma, media;

    suma = 0;
    for (i=0; i<NF; i++)
    {
        for (j=0; j<NC; j++)
        {
            suma = suma + m[i][j];
        }
    }
    media = suma / (NF * NC);
    return media;
}

void escribirsuperiores (tipoimagen m, double media)
{
    double valor;
    int i, j;

    valor = media + 0.25 * media;
    printf ("\nPixeles con polucion superior al 25%% de la media (%.3lf): ", valor);
    printf ("\n\t");
    for (i=0; i<NF; i++)
    {
        for (j=0; j<NC; j++)
        {
            if (m[i][j] > valor)
                printf ("(%d,%d)  ", i+1, j+1);
        }
    }
}