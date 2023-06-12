/* ejercicio 1 cooperativo 3 */


#include <stdio.h>

int main () 
{
    int t1, t2, t3;

    printf ("\nIntroduce la primera temperatura: ");
    scanf (" %d", &t1);
    printf ("\nIntroduce la segunda temperatura: ");
    scanf (" %d", &t2);
    printf ("\nIntroduce la tercera temperatura: ");
    scanf (" %d", &t3);

  
    if (t1 == t2 && t1 == t3)
        printf ("\nLas tres temperaturas son iguales");
    else 
    {
        if (t1 == t2 && t1 != t3)
            printf ("\nHay dos temperaturas iguales: primera y segunda");
        else 
        {
            if (t1 == t3 && t1 != t2)
                printf ("\nHay dos temperaturas iguales: primera y tercera");
            else 
            {
                if (t2 == t3 && t2 != t1)
                    printf ("\nHay dos temperaturas iguales: segunda y tercera");
                else 
                    printf ("\nLas tres temperaturas son distintas");
            }
        }
    }

   

    return 0;
}