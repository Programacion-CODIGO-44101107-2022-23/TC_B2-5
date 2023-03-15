
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;

    int n, i, suma;

	
	do
	{
		system("cls||clear");
		printf("Nombre\n");
		printf("=================================\n\n");


        printf ("\nIntroduce el valor limite: ");
        scanf (" %d", &n);
        suma = 0;
        for (i=0; i<=n; i++)
        {
            if (i % 2 != 0 && i % 3 == 0)
                suma = suma + i;
        }
        printf ("\nLa suma de los impares multiplos de 3 [0, %d]     %d", n, suma);



		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}