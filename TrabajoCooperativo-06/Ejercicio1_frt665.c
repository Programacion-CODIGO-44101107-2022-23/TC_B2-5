/*Ejercicio 1 cooperativo 6*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

void leercartesianas (double *x, double *y, double *z);
void calcularesfericas (double x, double y, double z, double *r, double *a1, double *a2);

int main()
{
	char c; 

    double x, y, z, r, a1, a2;

	
	do
	{
		system("cls||clear");
		printf("Ejercicio 1\n");
		printf("=====================\n\n");


        leercartesianas (&x, &y, &z);
        calcularesfericas (x, y, z, &r, &a1, &a2);
        printf ("\nLas coordenadas esfericas son: (%.2lf, %.2lf, %.2lf)", r, a1, a2);


		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}

void leercartesianas (double *x, double *y, double *z)
{
    printf ("\nIntroduce coordenadas cartesianas:");
    printf ("\nX = ");
    scanf (" %lf", &*x);
    printf ("\nY = ");
    scanf (" %lf", &*y);
    printf ("\nZ = ");
    scanf (" %lf", &*z);    
}

void calcularesfericas (double x, double y, double z, double *r, double *a1, double *a2)
{
    *r = sqrt(x*x + y*y + z*z);
    if (x == 0 && y == 0 && z == 0)
    {
        *a1 = 0;
        *a2 = 0;
    }
    else 
    {
        if (z > 0)
            *a1 = atan (sqrt(x*x + y*y) / z);
        else 
        {
            if (z == 0)
                *a1 = PI / 2;
            else 
                *a1 = PI + atan (sqrt(x*x + y*y) / z);
        }
        *a1 = *a1 * 180 / PI;
        if (x > 0)
        {
            if (y >= 0)
                *a2 = atan (y / x);
            else 
                *a2 = 2 * PI + atan(y / x);
        }
        else 
        {
            if (x == 0)
            {
                if (y == 0)
                    *a2 = 0;
                else 
                {
                    if (y > 0)
                        *a2 = PI / 2;
                    else 
                        *a2 = - PI / 2;
                }
            }
            else 
                *a2 = PI + atan (y/x);
        }
        *a2 = *a2 * 180 / PI;
    }
}