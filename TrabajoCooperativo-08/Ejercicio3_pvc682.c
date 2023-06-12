#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXESTACIONES 100
#define MAXINDICE 500
#define MAXINTERVALOS 10
#define MAXASTERISCOS 40

typedef double tipoarray[MAXINTERVALOS];

void inicializar (tipoarray fa); 
void leerdatos (int num, tipoarray fa); 
void calcularfrelativas (tipoarray fa, int num, tipoarray fr); // 
void calcularfacumuladas (tipoarray fr, tipoarray fra); 
void escribirhistograma (tipoarray fa, tipoarray fr, tipoarray fra); 
void escribirasteriscos (double f); 

int main()
{
    char c;


    tipoarray fa, fr, fra;
    int num;


    do
    {
        system("cls");
        printf("Ejercicio 3\n");
        printf("===========\n\n");



        do
        {
            printf ("\nNumero de estaciones de medida: ");
            scanf (" %d", &num);
        } while (num <= 0 || num > MAXESTACIONES);
        inicializar (fa);
        leerdatos (num, fa);
        calcularfrelativas (fa, num, fr);
        calcularfacumuladas (fr, fra);
        escribirhistograma (fa, fr, fra);
        




        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }
    while (c!='N');
    return 0;
}

void inicializar (tipoarray fa)
{
    int i;

    for (i=0; i<MAXINTERVALOS; i++)
        fa[i] = 0;
}

void leerdatos (int num, tipoarray fa)
{
    int i, calidad, tamanio, pos;

    tamanio = MAXINDICE / MAXINTERVALOS;
    for (i=1; i<=num; i++)
    {
        do 
        {
            printf ("\nIntroduce indice de calidad del aire: ");
            scanf (" %d", &calidad);
        }while (calidad < 0 || calidad >= MAXINDICE);
        pos = calidad / tamanio;
        fa[pos] ++;
    }
}

void calcularfrelativas (tipoarray fa, int num, tipoarray fr)
{
    int i;

    for (i=0; i<MAXINTERVALOS; i++)
    {
        fr[i] = fa[i] / num;
    }
}

void calcularfacumuladas (tipoarray fr, tipoarray fra)
{
    int i;

    fra[0] = fr[0];
    for (i=1; i<MAXINTERVALOS; i++)
    {
        fra[i] = fra[i-1] + fr[i];
    }
}

void escribirhistograma (tipoarray fa, tipoarray fr, tipoarray fra)
{
    int i, tama, ini, fin;

    printf ("\nHISTOGRAMA DE FRECUENCIAS RELATIVAS ACUMULATIVAS");
    printf ("\n================================================");
    printf ("\n");
    printf ("\nIntervalo  FA     FR    FRA");
    tama = MAXINDICE / MAXINTERVALOS;
    ini = 0;
    for (i=0; i<MAXINTERVALOS; i++)
    {
        fin = ini + tama;
        printf ("\n[%3d-%3d) %3.0lf %6.3lf %6.3lf ", ini, fin, fa[i], fr[i], fra[i]);
        escribirasteriscos (fra[i]);
        ini = fin;
    }
}

void escribirasteriscos (double f)
{
    int n, i;

    n = (int) (f * MAXASTERISCOS);
    for (i=1; i<=n; i++)
        printf ("*");
}