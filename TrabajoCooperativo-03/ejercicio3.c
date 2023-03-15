/* Ejercicio 3 cooperativo 3 */
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main ()
{
    double x, y, r, angulo;

    printf ("\nIntroduce coordenadas cartesianas");
    printf ("\nIntroduce x: ");
    scanf (" %lf", &x);
    printf ("\nIntroduce y: ");
    scanf (" %lf", &y);

  
    if (x > 0)
    {
        if (y >= 0)
            angulo = atan(y / x);
        else
            angulo = atan(y/x) + 2 * PI;
    }
    else 
    {
        if (x == 0)
        {
            if (y == 0)
                angulo = 0;
            else 
            {
                if (y > 0)
                    angulo = PI / 2;
                else
                    angulo = 3 * PI / 2;
            }
        }
        else 
            angulo = atan (y/x) + PI;
    }
    
    angulo = angulo * 180 / PI;
    printf ("\n\nLas coordenadas polares son: (%.2lf, %.0lf)", r, angulo);
    

    return 0;
}
