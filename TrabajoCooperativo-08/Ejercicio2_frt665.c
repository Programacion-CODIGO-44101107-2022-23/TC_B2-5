#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 1000

typedef int tipoarray[MAX];

void inicializar (tipoarray a);
void hacercriba (tipoarray a); 
void escribirprimos (tipoarray a); 

int main()
{
    char c;


    tipoarray a;


    do
    {
        system("cls");
        printf("Ejercicio 2\n");
        printf("===========\n\n");


        inicializar (a);
        hacercriba (a);
        escribirprimos (a);





        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }
    while (c!='N');
    return 0;
}

void inicializar (tipoarray a)
{
    int i;

    for (i=0; i<MAX; i++)
    {
        a[i] = i+1;
    }
}

void hacercriba (tipoarray a)
{
    int i, k;

    for (i=1; i<=sqrt(MAX)+1; i++)
    {
        if (a[i] != 0)
        {
            for (k=i+a[i]; k<MAX; k=k+a[i])
                a[k] = 0;
        }
    }
}

void escribirprimos (tipoarray a)
{
    int i, cont;

    printf ("\nNumeros primos entre 1 y %d:\n", MAX);
    cont = 0;
    for (i=0; i<MAX; i++)
    {
        if (a[i] != 0)
        {
            printf (" %7d", a[i]);
            cont++;
            if (cont % 7 == 0)
                printf ("\n");
        }
    }
}