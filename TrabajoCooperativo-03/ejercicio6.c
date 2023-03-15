/*Ejercicio 6 cooperativo 3*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;

    int x1, y1, z1, x2, y2, z2, x, y, z, p;
    char operacion;

	
	do
	{
		system("cls||clear");
		printf("nombre\n");
		printf("=================================\n\n");

        printf ("\nIntroduce datos del primer vector:");
        printf ("\nIntroduce valor x: ");
        scanf (" %d", &x1);
        printf ("\nIntroduce valor y: ");
        scanf (" %d", &y1);
        printf ("\nIntroduce valor z: ");
        scanf (" %d", &z1);
        
        printf ("\nIntroduce datos del segundo vector:");
        printf ("\nIntroduce valor x: ");
        scanf (" %d", &x2);
        printf ("\nIntroduce valor y: ");
        scanf (" %d", &y2);
        printf ("\nIntroduce valor z: ");
        scanf (" %d", &z2);

        printf ("\nOperaciones: + para suma, - para resta, . producto escalar, x producto vectorial");
        printf ("\nIntroduce operacion: ");
        scanf (" %c", &operacion);

        switch (operacion)
        {
            case '+': 
                x = x1 + x2;
                y = y1 + y2;
                z = z1 + z2;
                printf ("\n(%d, %d, %d) + (%d, %d, %d) = (%d, %d, %d)", x1, y1, z1, x2, y2, z2, x, y , z);
                break;
            case '-': 
                x = x1 - x2;
                y = y1 - y2;
                z = z1 - z2;
                printf ("\n(%d, %d, %d) - (%d, %d, %d) = (%d, %d, %d)", x1, y1, z1, x2, y2, z2, x, y , z);
                break;
            case '.': 
                p = x1*x2 + y1*y2 + z1*z2;
                printf ("\n(%d, %d, %d) + (%d, %d, %d) = %d", x1, y1, z1, x2, y2, z2, p);
                break;
            case 'x': 
                x = y1*z2 - y2*z1;
                y = z1*x2 - z2*x1;  // - (x1*z2 - x2*z1)
                z = x1*y2 - x2*y1;
                printf ("\n(%d, %d, %d) x (%d, %d, %d) = (%d, %d, %d)", x1, y1, z1, x2, y2, z2, x, y , z);
                break;
            default:
                printf ("\nOperacion no valida");
                break;
        }



		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}