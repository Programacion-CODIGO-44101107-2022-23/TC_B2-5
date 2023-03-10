/* ejercicio 2 cooperativo 2 */

#include <stdio.h>

int main ()
{
    int c, f;

    printf ("Introduce el valor de la temperatura en grados celsius: ");
    scanf (" %d", &c);
    f = 9 * c / 5 + 32;
    printf ("\nLa temperatura en grados fahrenheit es: %d", f);

    return 0;
}