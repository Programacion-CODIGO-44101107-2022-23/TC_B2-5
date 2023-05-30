#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


#define MAXEL 3
#define PI 3.14159


typedef struct
{
    char tipo;
    union
    {
        struct
        {
            double tx;
            double ty;
        };
        struct
        {
            double angulo;
        };
        struct
        {
            double sx;
            double sy;
        };
    };
}tipotransformacion;

typedef double tipomatriz[MAXEL][MAXEL];


void leertransformacion (tipotransformacion *t);
void construirmatriz (tipotransformacion t, tipomatriz m);
void escribirmatriz (tipomatriz m);


int main(){
    char c;


    tipotransformacion t;
    tipomatriz m;




    do{ system("cls");
        printf("Ejercicio 2\n");
        printf("===========\n\n");



        leertransformacion (&t);
        construirmatriz (t, m);
        escribirmatriz (m);






        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }while (c!='N');
    return 0;
}

void leertransformacion (tipotransformacion *t)
{
    do
    {
        printf ("\nTipo de transformacion:");
        printf ("\nT - traslacion");
        printf ("\nR - rotacion");
        printf ("\nE - escalado");
        printf ("\nIntroduce tipo (T, R, E): ");
        scanf (" %c", &t->tipo);
        t->tipo = toupper (t->tipo);
    }while (t->tipo != 'T' && t->tipo != 'R' && t->tipo != 'E');
    switch (t->tipo)
    {
    case 'T':
        printf ("\nIntroduce traslacion horizontal y vertical: ");
        scanf (" %lf %lf", &t->tx, &t->ty);
        break;
    case 'R':
        printf ("\nIntroduce angulo en grados: ");
        scanf (" %lf", &t->angulo);
        break;
    case 'E':
        printf ("\nIntroduce escalado en eje X e Y: ");
        scanf (" %lf %lf", &t->sx, &t->sy);
        break;
    }
}

void construirmatriz (tipotransformacion t, tipomatriz m)
{
    double r;

    switch (t.tipo)
    {
    case 'T':
        m[0][0] = 1;
        m[0][1] = 0;
        m[0][2] = t.tx;
        m[1][0] = 0;
        m[1][1] = 1;
        m[1][2] = t.ty;
        break;
    case 'R':
        r = t.angulo * PI / 180;
        m[0][0] = cos(r);
        m[0][1] = -sin(r);
        m[0][2] = 0;
        m[1][0] = sin(r);
        m[1][1] = cos(r);
        m[1][2] = 0;
        break;
    case 'E':
        m[0][0] = t.sx;
        m[0][1] = 0;
        m[0][2] = 0;
        m[1][0] = 0;
        m[1][1] = t.sy;
        m[1][2] = 0;
        break;
    }
    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = 1;
}

void escribirmatriz (tipomatriz m)
{
    int i, j;

    printf ("\nMatriz\n\n");
    for (i=0; i<MAXEL; i++)
    {
        for (j=0; j<MAXEL; j++)
        {
            printf (" %8.2lf", m[i][j]);
        }
        printf("\n");
    }
}