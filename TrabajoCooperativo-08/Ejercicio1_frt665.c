#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

typedef double tipopolinomio[MAX+1];

void leerpolinomio (tipopolinomio p);
void escribirpolinomio (tipopolinomio p); 
void derivar (tipopolinomio p, tipopolinomio pder);

int main()
{
    char c;

    tipopolinomio p, pder;



    do
    {
        system("cls");
        printf("Ejercicio 1\n");
        printf("===========\n\n");
        


        leerpolinomio (p);  
        printf ("\nPolinomio original: ");
        escribirpolinomio (p); 
        derivar (p, pder); 
        printf ("\nPolinomio derivado: ");
        escribirpolinomio (pder);




        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }
    while (c!='N');
    return 0;
}


void leerpolinomio (tipopolinomio p)
{
    int i, grado;

    for (i=0; i<=MAX; i++)
    {
        p[i] = 0;
    }
    do
    {
        printf ("\nIntroduce grado del polinomio: ");
        scanf (" %d", &grado);
    } while (grado < 0 || grado > MAX);
    for (i=grado; i>=0; i--)
    {
        printf ("\nIntroduce el coeficiente de x^%d: ", i);
        scanf (" %lf", &p[i]);
    }
}

void escribirpolinomio (tipopolinomio p)
{
    int i, cont;

    cont = 0;
    for (i=MAX; i>=0; i--)
    {
        if (p[i] != 0)
        {
            /*if (p[i] > 0)
                printf ("+");*/
            printf ("%+.2lf x^%d ", p[i], i);
            cont++;
        }
    }
    if (cont == 0)
        printf ("0");
}

void derivar (tipopolinomio p, tipopolinomio pder)
{
    int i;

    for (i=1; i<=MAX; i++)
    {
        pder[i-1] = p[i] * i;
    }
    pder[MAX] = 0;
    
}