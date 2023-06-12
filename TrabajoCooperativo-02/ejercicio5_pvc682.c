/* ejercicio 5 cooperativo 2 */


#include <stdio.h>


int main ()
{
    float m, r, w, i, l;

    printf ("Introduce el valor de la masa de cada esfera en Kg: ");
    scanf (" %f", &m);
    printf ("Introduce la longitud del brazo en metros: ");
    scanf (" %f", &r);
    printf ("Introduce la velocidad angular en rad/sg: ");
    scanf (" %f", &w);
    i = 2 * m * (r * r);
    l = i * w;
    printf ("\n\nEl momento de inercia es: %.3f Kg*m2", i);
    printf ("\nEl momento angular es: %.3f Kg*m2/sg", l);

    getchar();
    return 0;
}