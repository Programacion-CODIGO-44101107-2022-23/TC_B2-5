
/* ejercicio 4 cooperativo 2*/


#include <stdio.h>
#include <math.h>


int main ()
{
    int fx, fy, fz, ax, ay, az, ox, oy, oz, rx, ry, rz, mx, my, mz;
    double modulo, mux, muy, muz;

    printf ("Introduce componentes x, y, z de la fuerza: ");
    scanf (" %d %d %d", &fx, &fy, &fz);
    printf ("Introduce componentes x, y, z del punto de aplicacion: ");
    scanf (" %d %d %d", &ax, &ay, &az);
    printf ("Introduce componentes x, y, z del origen: ");
    scanf (" %d %d %d", &ox, &oy, &oz);
    rx = ax - ox;
    ry = ay - oy;
    rz = az - oz;
    mx = ry * fz - rz * fy;
    my = rz * fx - rx * fz;
    mz = rx * fy - ry * fx;
    printf ("\n\nEl momento de la fuerza es: (%d, %d, %d)", mx, my, mz);
    modulo = sqrt (mx*mx + my*my + mz*mz);
    printf ("\nEl modulo del momento es: %.2lf", modulo);
    mux = mx / modulo;
    muy = my / modulo;
    muz = mz / modulo;
    printf ("\nEl momento unitario es: (%.2lf, %.2lf, %.2lf)", mux, muy, muz);

    return 0;
}