/* Ejercicio 3 cooperativo 4 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;

    int n, fac, i;

	
	do
	{
		system("cls||clear");
		printf("Nombre\n");
		printf("=================================\n\n");


        printf ("\nIntroduce numero para calular el factorial: ");
        scanf (" %d", &n);
        if (n < 0)
            printf ("\nNo existe el factorial de un numero negativo");
        else 
        {
            fac = 1;
            for (i=n; i>=1; i--)
            {
                fac = fac * i;
            }
            printf ("\n%d! = %d", n, fac);
        }


		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}