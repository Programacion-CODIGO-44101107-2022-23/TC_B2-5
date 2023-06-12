/* ejercicio 3 cooperativo 2*/

#include <stdio.h>


#define PI 3.14159
#define DENSIDAD 7.86


int main ()
{
    int a, b, h;
    double v, m;

    printf ("Introduce el valor del radio superior en cm: ");
    scanf (" %d", &a);
    printf ("Introduce el valor del radio inferior en cm: ");
    scanf (" %d", &b);
    printf ("Introduce el valor de la altura en cm: ");
    scanf (" %d", &h);

    v = PI * h * (a*a + a*b + b*b) / 3;
    m = v * DENSIDAD / 1000;
    printf ("\n\nLa masa son: %.3lf Kg", m);

    return 0;
}