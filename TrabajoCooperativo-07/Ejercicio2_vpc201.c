/*Ejercicio 2 cooperativo 7*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


void leerfecha (int *d, int *m, int *a);

char esfechacorrecta (int d, int m, int a);

char esbisiesto (int a);

int calcularnumerodias (int d, int m, int a);

void escribirfecha (int d, int m, int a);

int main()
{
    char c;


    int d1, m1, a1, d2, m2, a2, num1, num2, num;

    do
    {
        system("cls");
        printf("Ejercicio 2\n");
        printf("================\n\n");


        printf ("\nFecha 1: ");
        leerfecha (&d1, &m1, &a1); 
        printf ("\nFecha 2: ");
        leerfecha (&d2, &m2, &a2);
        num1 = calcularnumerodias (d1, m1, a1);
        num2 = calcularnumerodias (d2, m2, a2);
        num = num2 - num1;
        printf ("\nFecha inicial: ");
        escribirfecha (d1, m1, a1); 
        printf ("\nFecha final: ");
        escribirfecha (d2, m2, a2);
        printf ("\nDias: %d", num);




        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }
    while (c!='N');
    return 0;
}


void leerfecha (int *d, int *m, int *a)
{
    char correcto;

    do
    {
        printf ("\nIntroduce anio: ");
        scanf (" %d", &*a);
        printf ("\nIntroduce mes: ");
        scanf (" %d", &*m);
        printf ("\nIntroduce dia: ");
        scanf (" %d", &*d);
        correcto = esfechacorrecta (*d, *m, *a); 
        if (correcto == 'n')
            printf ("\nFecha incorrecta, introducela de nuevo");
    } while (correcto == 'n');
    
}

char esfechacorrecta (int d, int m, int a)
{
    char correcto;

    correcto = 's';
    if (d < 1)
        correcto = 'n';
    else 
    {
        switch (m)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if (d > 31)
                    correcto = 'n';
                break;
            case 4: 
            case 6: 
            case 9: 
            case 11:
                if (d > 30)
                    correcto = 'n';
                break;
            case 2: 
                if (esbisiesto (a) == 's')
                {
                    if (d > 29)
                        correcto = 'n';
                }
                else 
                {
                    if (d > 28)
                        correcto = 'n';
                }
                break;
            default:
                correcto = 'n';
                break;
        }
    }
    return correcto;
}

char esbisiesto (int a)
{
    if (a % 4 != 0)
        return 'n';
    else 
    {
        if (a % 100 == 0 && a % 400 != 0)
            return 'n';
        else 
            return 's';
    }
}


int calcularnumerodias (int d, int m, int a)
{
    int i, suma;

    suma = 0;
    for (i=1; i<a; i++)
    {
        if (esbisiesto (i) == 's')
            suma = suma + 366;
        else 
            suma = suma + 365;
    }
    for (i=1; i<m; i++)
    {
        switch (i)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                suma = suma + 31;
                break;
            case 4: case 6: case 9: case 11:
                suma = suma + 30;
                break;
            case 2: 
                if (esbisiesto (a) == 's')
                    suma = suma + 29;
                else 
                    suma = suma + 28;
                break;
        }
    }
    suma = suma + d;
    return suma;
}

void escribirfecha (int d, int m, int a)
{
    printf ("%d-", d);
    switch (m)
    {
        case 1: printf ("Enero");
                break;
        case 2: printf ("Febrero");
                break;
        case 3: printf ("Marzo");
                break;
        case 4: printf ("Abril");
                break;
        case 5: printf ("Mayo");
                break;
        case 6: printf ("Junio");
                break;
        case 7: printf ("Julio");
                break;
        case 8: printf ("Agosto");
                break;
        case 9: printf ("Septiembre");
                break;
        case 10: printf ("Octubre");
                break;
        case 11: printf ("Noviembre");
                break;
        case 12: printf ("Diciembre");
                break;
    }

    printf ("-%d", a);
}