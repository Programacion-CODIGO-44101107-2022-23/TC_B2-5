/*Ejercicio 2 cooperativo4*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;

    double base, pot;
    int exponente, i;
	
	do
	{
		system("cls||clear");
		printf("Nombre\n");
		printf("=================================\n\n");

        printf ("\nIntroduce un numero real para la base: ");
        scanf (" %lf", &base);
        printf ("\nIntroduce un numero entero para el exponente: ");
        scanf (" %d", &exponente);

        if (base == 0 && exponente == 0)
            printf ("\nIndeterminacion");
        else 
        {
            if (base == 0 && exponente < 0)
                printf ("\nInfinito");
            else 
            {
                pot = 1;
                for (i=1; i<=abs(exponente); i++)
                {
                    pot = pot * base;
                }
                if (exponente < 0)
                    pot = 1 / pot;
                printf ("\nLa potencia es: %.3lf", pot);
            }
        }



		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}