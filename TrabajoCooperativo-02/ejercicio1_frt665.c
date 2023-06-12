/* ejercicio 1 cooperativo 2 */

#include <stdio.h>  

int main ()
{
    float w, r, /*aceleracion normal*/an;

    printf ("Introduce la velocidad angular en rad/seg: ");
    scanf (" %f", &w);
    printf ("Introduce el radio de la trayectoria en metros: ");
    scanf (" %f", &r);
    an = (w * w) * r;
    printf ("\n\nLa aceleracion normal o centripeta es: %10.2f\n\n", an);

    return 0;
}





