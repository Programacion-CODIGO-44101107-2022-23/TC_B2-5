#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXEL 5

typedef int tipomatriz[MAXEL][MAXEL];

void leermatriz (tipomatriz m, int *f, int *c);
void escribirmatriz (tipomatriz m, int f, int c);
void sumarmatrices (tipomatriz m1, tipomatriz m2, int f1, int c1, tipomatriz msuma);
void multiplicarmatrices (tipomatriz m1, tipomatriz m2, int f1, int c1, int c2, tipomatriz mprod);

int main()
{
    char c;


    tipomatriz m1, m2, msuma, mprod;
    int f1, c1, f2, c2;


    do
    {
        system("cls");
        printf("Ejercicio 1\n");
        printf("===========\n\n");


        printf ("\nPRIMERA MATRIZ");
        leermatriz (m1, &f1, &c1);
        printf ("\nSEGUNDA MATRIZ");
        leermatriz (m2, &f2, &c2);

        printf ("\nMatriz primera (%dx%d):", f1, c1);
        escribirmatriz (m1, f1, c1);
        printf ("\nMatriz segunda (%dx%d):", f2, c2);
        escribirmatriz (m2, f2, c2);

        if (f1 != f2 || c1 != c2)
            printf ("\nSuma de matrices: no se pueden sumar");
        else 
        {
            sumarmatrices (m1, m2, f1, c1, msuma);
            printf ("\nSuma de matrices:");
            escribirmatriz(msuma, f1, c1);
        }


        if (c1 != f2)
            printf ("\nProducto de matrices: no se pueden multiplicar");
        else 
        {
            multiplicarmatrices (m1, m2, f1, c1, c2, mprod);
            printf ("\nProducto de matrices:");
            escribirmatriz(mprod, f1, c2);
        }



        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }
    while (c!='N');
    return 0;
}


void leermatriz (tipomatriz m, int *f, int *c)
{
    int i, j;

    do 
    {
        printf ("\nIntroduce numero de filas (1..%d): ", MAXEL);
        scanf (" %d", &*f);
    }while (*f < 1 || *f > MAXEL);
    do 
    {
        printf ("\nIntroduce numero de columnas (1..%d): ", MAXEL);
        scanf (" %d", &*c);
    }while (*c < 1 || *c > MAXEL);
    for (i=0; i<*f; i++)
    {
        for (j=0; j<*c; j++)
        {
            printf ("\nIntroduce un numero: ");
            scanf (" %d", &m[i][j]);
        }
    }
}

void escribirmatriz (tipomatriz m, int f, int c)
{
    int i, j;

    printf ("\n");
    for (i=0; i<f; i++)
    {
        for (j=0; j<c; j++)
        {
            printf (" %5d", m[i][j]);
        }
        printf ("\n");
    }
}

void sumarmatrices (tipomatriz m1, tipomatriz m2, int f1, int c1, tipomatriz msuma)
{
    int i, j;

    for (i=0; i<f1; i++)
    {
        for (j=0; j<c1; j++)
        {
            msuma[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void multiplicarmatrices (tipomatriz m1, tipomatriz m2, int f1, int c1, int c2, tipomatriz mprod)
{
    int i, j, suma, k;

    for (i=0; i<f1; i++)
    {
        for (j=0; j<c2; j++)
        {
            suma = 0;
            for (k=0; k<c1; k++)
            {
                suma = suma + m1[i][k] * m2[k][j];
            }
            mprod[i][j] = suma;
        }
    }
}