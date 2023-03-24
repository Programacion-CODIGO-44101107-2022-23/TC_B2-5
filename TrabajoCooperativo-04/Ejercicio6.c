/*Ejercicio 6 cooperativo 4*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;
  	
    int t, suma, n, suma2;
    double tmedia, desv;

	
	do
	{
		system("cls||clear");
		printf("Nombre\n");
		printf("=================================\n\n");

	

        printf ("\nIntroduce un valor: ");
        scanf (" %d", &t);

        suma = 0;
        n = 0;
        suma2 = 0;

        while (t != -99)
        {
            if (t >= -50 && t <= +50)
            {
                suma = suma + t;
                n++;
                suma2 = suma2 + t*t; // + pow(t,2)
            }

            printf ("\nIntroduce un valor: ");
            scanf (" %d", &t);
        }
        printf ("\nNo de datos validos: %d", n);
        if (n != 0)
        {
            tmedia = (double) suma / n;
            desv = sqrt((suma2 - n*tmedia*tmedia) / n);
            printf ("\nTemperatura Media: %.2lf", tmedia);
            printf ("\nDesviacion tipica: %.2lf", desv);
        }
        


		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}