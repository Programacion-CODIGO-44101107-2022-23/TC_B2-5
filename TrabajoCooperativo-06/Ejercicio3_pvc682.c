/*Ejercicio 3 cooperativo 6*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void leerdatos (double *m, double *a, double *b, double *h);
char leertipoeje();
double calcularmomento (double m, double a, double b, double h, char eje);

int main()
{
	char c;

    double m, a, b, h, i;
    char eje;

	
	do
	{
		system("cls||clear");
		printf("Ejercicio 3\n");
		printf("===============\n\n");

		// Solucion

        printf ("\nMOMENTO DE INERCIA DE UN CILINDRO HUECO");
        leerdatos (&m, &a, &b, &h);
        eje = leertipoeje();
        i = calcularmomento (m, a, b, h, eje);
        printf ("\nEl momento de inercia es: %.3lf", i);


		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}


void leerdatos (double *m, double *a, double *b, double *h)
{
    printf ("\nIntroduce valor de la masa en kg: ");
    scanf (" %lf", &*m);
    //tengo que validar que el eje exterior sea mayor que el eje interior
    printf ("\nIntroduce valor del eje exterior en cm: ");
    scanf (" %lf", &*a);
    do
    {
        printf ("\nIntroduce valor del eje interior en cm (menor que el exterior): ");
        scanf (" %lf", &*b);
    } while (*b >= *a);
    printf ("\nIntroduce valor de la altura en cm: ");
    scanf (" %lf", &*h);
}

char leertipoeje()
{
    char eje;

    printf ("\nTipos de ejes");
    printf ("\nc - Eje del cilindro");
    printf ("\np - Eje perpendicular al eje del cilindro y que pasa por el centro de masa");
    printf ("\nd - Eje que coincide con el diametro en uno de los extreos");
    do
    {
        printf ("\nIntroduce tipo (c, p, d): ");
        scanf (" %c", &eje);
    } while (eje != 'c' && eje != 'p' && eje != 'd');
    return eje;
}

double calcularmomento (double m, double a, double b, double h, char eje)
{
    double i;


    switch (eje)
    {
        case 'c': i = m * (a*a + b*b) / 2;
                  break;
        case 'p': i = m * (3*a*a + 3*b*b + h*h) / 12;
                  break;
        case 'd': i = m * (3*a*a + 3*b*b + 4*h*h) / 12;
                  break;
    }
    i = i / 10000;
    return i;
}