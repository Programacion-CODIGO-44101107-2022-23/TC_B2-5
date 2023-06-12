/*Ejercicio 5 cooperativo 4*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



#define MAXIMO 5

int main()
{
	char c;
  	

    double r, suma, rt;
    int cont;
    char fin;

	
	do
	{
		system("cls||clear");
		printf("nombre\n");
		printf("=================================\n\n");

		

        suma = 0;
        cont = 0;
        fin = 'n';
        while (fin == 'n')
        {
            printf ("\nIntroduce valor de la resistencia: ");
            scanf (" %lf", &r);
            if (r == 0)
                fin = 's';
            else 
            {
                if (r > 0)
                {
                    suma = suma + 1 / r;
                    cont++;
                    if (cont == MAXIMO)
                        fin = 's';
                }
                
            }
        }
        if (cont == 0)
            printf ("\nNo hay ninguna resistencia");
        else 
        {
            rt = 1 / suma;
            printf ("\nResistencia total: %.3lf", rt);
        }


		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}