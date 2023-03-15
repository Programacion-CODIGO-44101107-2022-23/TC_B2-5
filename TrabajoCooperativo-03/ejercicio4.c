/* ejercicio 4 cooperativo 3 */

#include <stdio.h>


int main ()
{
    char parimpar;
    int resto, numero;

    printf ("\nPiensa un numero de una cifra...");
    printf ("\nEl numero es par o impar (p/i): ");
    scanf (" %c", &parimpar);
    printf ("\nIntroduce el resto de dividirlo por 5 (0..4): ");
    scanf (" %d", &resto);
    if (parimpar != 'p' && parimpar != 'i')
        printf ("\nError, tienes que indicar si es par (p) o impar (i)");
    else 
    {
        if (resto < 0 || resto > 4)
            printf ("\nError, el resto debe estar entre 0 y 4");
        else 
        {
            if (parimpar == 'p')
            {
                switch (resto)
                {
                    case 0:
                        numero = 0;
                        break;
                    case 1:
                        numero = 6;
                        break;
                    case 2:
                        numero = 2;
                        break;
                    case 3:
                        numero = 8;
                        break;
                    case 4:
                        numero = 4;
                        break;
                }
            }
            else 
            {
                switch (resto)
                {
                    case 0:
                        numero = 5;
                        break;
                    case 1:
                        numero = 1;
                        break;
                    case 2:
                        numero = 7;
                        break;
                    case 3:
                        numero = 3;
                        break;
                    case 4:
                        numero = 9;
                        break;
                }
            }
            printf ("\nEl numero que has pensado es: %d", numero);
        }
    }

    return 0;
}