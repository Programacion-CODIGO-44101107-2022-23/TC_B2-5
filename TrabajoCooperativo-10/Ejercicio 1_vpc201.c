#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


typedef struct 
{
    int hor;
    int min;
    int seg;
    int cen;
}tipotiempo;


void leertiempo (tipotiempo *t);
void calculartranscurrido (tipotiempo ini, tipotiempo fin, tipotiempo *res);

int main()
{
    char c;


    tipotiempo ini, fin, res;


    do
    {
        system("cls");
        printf("Ejercicio 1\n");
        printf("===========\n\n");



        printf ("\nIntroduce el registro inicial de tiempo:");
        leertiempo (&ini);
        printf ("\nIntroduce el registro final de tiempo:");
        leertiempo (&fin);
        calculartranscurrido (ini, fin, &res);
        printf ("\nTiempo transcurrido: %02d:%02d:%02d.%02d", res.hor, res.min, res.seg, res.cen);




        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }
    while (c!='N');
    return 0;
}


void leertiempo (tipotiempo *t)
{
    do
    {
        printf ("\nIntroduce hora: ");
        scanf (" %d", &t->hor);
    } while (t->hor < 0 || t->hor >= 24);
    do
    {
        printf ("\nIntroduce minuto: ");
        scanf (" %d", &t->min);
    } while (t->min < 0 || t->min >= 60);
    do
    {
        printf ("\nIntroduce segundo: ");
        scanf (" %d", &t->seg);
    } while (t->seg < 0 || t->seg >= 60);
    do
    {
        printf ("\nIntroduce centesima: ");
        scanf (" %d", &t->cen);
    } while (t->cen < 0 || t->cen >= 100);
}

void calculartranscurrido (tipotiempo ini, tipotiempo fin, tipotiempo *res)
{
    int n1, n2, n3;

    n1 = ini.cen + ini.seg * 100 + ini.min * 60 * 100 + ini.hor * 60 * 60 * 100;
    n2 = fin.cen + fin.seg * 100 + fin.min * 60 * 100 + fin.hor * 60 * 60 * 100;
    n3 = n2 - n1;
    if (n3 < 0)
        n3 = 24 * 60 * 60 * 100 + n3;
    res->cen = n3 % 100;
    n3 = n3 / 100;
    res->seg = n3 % 60;
    n3 = n3 / 60;
    res->min = n3 % 60;
    res->hor = n3 / 60;
}