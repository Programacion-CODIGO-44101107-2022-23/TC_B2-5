#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>



#define MAXELE 100
#define NOMBRE "zz2.txt"



typedef double tipovector[MAXELE];



int menu();
void inicializarvector (tipovector x, tipovector y, int *n);
void insertarpunto (tipovector x, tipovector y, int *n);
void listarpuntos (tipovector x, tipovector y, int n);
void eliminarpunto (tipovector x, tipovector y, int *n);
void imprimirecuacion (tipovector x, tipovector y, int n);
void grabararchivo (tipovector x, tipovector y, int n);


int main(){
   

    int opcion, n;
    tipovector x, y;

   
    inicializarvector(x, y, &n);
    do
    {
        opcion = menu();
        switch (opcion)
        {
        case 1:
            insertarpunto (x, y, &n);
            break;
        case 2:
            listarpuntos (x, y, n);
            break;
        case 3:
            eliminarpunto (x, y, &n);
            break;
        case 4:
            imprimirecuacion (x, y, n);
            break;
        case 0:
            printf ("\n\nFin del programa");
            break;
        default:
            printf ("\nError, opcion no valida");
            break;
        }
    }while (opcion != 0);
    grabararchivo(x, y, n);
    return 0;
}


void inicializarvector (tipovector x, tipovector y, int *n)
{
    FILE *f;

    *n = 0;
    f = fopen (NOMBRE, "r");
    if (f != NULL)
    {
        fscanf (f, " %lf", &x[*n]);
        while ( ! feof (f))
        {
            fscanf (f, " %lf", &y[*n]);
            (*n) ++;
            fscanf (f, " %lf", &x[*n]);
        }
        fclose(f);
    }
}


int menu()
{
    int opcion;

    printf ("\n\nMenu principal");
    printf ("\n1. Insertar un nuevo punto experimental");
    printf ("\n2. Imprimir en pantalla un listado numerado de puntos");
    printf ("\n3. Eliminar un punto del conjunto de datos dado su numero de orden");
    printf ("\n4. Imprimir ecuacion de la recta de regresion y coeficiente de correlacion");
    printf ("\n0. Finalizar programa");
    printf ("\n\nIntroduce opcion: ");
    scanf (" %d", &opcion);
    return opcion;
}


void insertarpunto (tipovector x, tipovector y, int *n)
{
    if (*n == MAXELE)
        printf ("\nNo se pueden insertar mas puntos");
    else
    {
        printf ("\nx = ");
        scanf (" %lf", &x[*n]);
        printf ("\ny = ");
        scanf (" %lf", &y[*n]);
        *n = *n + 1; // o si lleva asterisco hay que poner parentesis (*n)++;
    }
}

void listarpuntos (tipovector x, tipovector y, int n)
{
    int i;

    if (n == 0)
        printf ("\nNo hay puntos");
    else
    {
        printf ("\n\nListado de puntos:");
        for (i=0; i<n; i++)
        {
            printf ("\n%d.- (%.2lf, %.2lf)", i+1, x[i], y[i]);
        }
    }
}


void eliminarpunto (tipovector x, tipovector y, int *n)
{
    int npunto, i;

    if (*n == 0)
        printf ("\nNo hay puntos que eliminar");
    else
    {
        do
        {
            printf ("\nIntroduce numero de punto a borrar (1..%d): ", *n);
            scanf (" %d", &npunto);
        }while (npunto < 1 || npunto > *n);
        for (i=npunto-1; i<*n-1; i++)
        {
            x[i] = x[i+1];
            y[i] = y[i+1];
        }
        *n = *n - 1;
    }
}


void imprimirecuacion (tipovector x, tipovector y, int n)
{
    double sumaxy, sumax, sumay, sumax2, sumay2, b, xmed, ymed, a, r;
    int i;

    if (n == 0)
        printf ("\nNingún punto introducido");
    else
    {
        if (n == 1)
            printf ("\nSolo hay un punto experimental");
        else
        {
            sumaxy = 0;
            sumax = 0;
            sumay = 0;
            sumax2 = 0;
            sumay2 = 0;
            for (i=0; i<n; i++)
            {
                sumaxy = sumaxy + x[i] * y[i];
                sumax = sumax + x[i];
                sumay = sumay + y[i];
                sumax2 = sumax2 + x[i] * x[i];
                sumay2 = sumay2 + y[i] * y[i];
            }
            if (n*sumax2 - sumax*sumax == 0)
                printf ("\nx = %.2lf", x[0]);
            else
            {
                b = (n*sumaxy - sumax*sumay) / (n*sumax2 - sumax*sumax);
                xmed = sumax / n;
                ymed = sumay / n;
                a = ymed - b*xmed;
                printf ("\ny = %.2lf + %.2lf * x", a, b);
            }
            if ((n*sumax2 - sumax*sumax) * (n*sumay2 - sumay*sumay) == 0)
                printf ("\nr indeterminado");
            else
            {
                r = (n*sumaxy - sumax*sumay) /
                    sqrt((n*sumax2 - sumax*sumax) * (n*sumay2 - sumay*sumay));
                printf ("\nr = %.2lf", r);
            }
        }
    }
}


void grabararchivo (tipovector x, tipovector y, int n)
{
    FILE *f;
    int i;

    f = fopen (NOMBRE, "w");
    for (i=0; i<n; i++)
    {
        fprintf(f, "%.2lf %.2lf\n", x[i], y[i]);
    }
    fclose(f);
}