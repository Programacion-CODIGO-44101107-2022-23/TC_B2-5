/* ejercicio 2 cooperativo 3 */


#include <stdio.h>


int main () 
{
    float v, t;

    int x=8, y=9;


    printf ("\nIntroduce voltaje entre 5 y 10 voltios: ");
    scanf (" %f", &v);
    if (v < 5 || v > 10)
        printf ("\nERROR");
    else 
    {
        t = 30 * v - 180;
        printf ("\nLa temperatura es %.1f grados ", t);
    }

    return 0;
}