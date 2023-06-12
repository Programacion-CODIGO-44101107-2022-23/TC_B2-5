/* Ejercicio 5 cooperativo 3 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;
  
    int g1, m1, s1, g2, m2, s2, tot1, tot2, tot, g, m, s;


	
	do
	{
		system("cls||clear");
		printf("nombre\n");
		printf("=================================\n\n");

        printf ("\nIntroduce datos del primer angulo:");
        printf ("\nIntroduce grados: ");
        scanf (" %d", &g1);
        printf ("\nIntroduce minutos: ");
        scanf (" %d", &m1);
        printf ("\nIntroduce segundos: ");
        scanf (" %d", &s1);

        printf ("\nIntroduce datos del segundo angulo:");
        printf ("\nIntroduce grados: ");
        scanf (" %d", &g2);
        printf ("\nIntroduce minutos: ");
        scanf (" %d", &m2);
        printf ("\nIntroduce segundos: ");
        scanf (" %d", &s2);

        s = s1 + s2;
        if (s >= 60)
        {
            m = m1 + m2 + 1;
            s = s - 60;
        }
        else 
            m = m1 + m2;
        if (m >= 60)
        {
            g = g1 + g2 + 1;
            m = m - 60;
        }
        else 
            g = g1 + g2;
        if (g >= 360)
            g = g - 360;

        printf ("\n%do %d\' %d\" + %do %d\' %d\" = %do %d\' %d\"", g1, m1, s1, g2, m2, s2, g, m, s);




		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}