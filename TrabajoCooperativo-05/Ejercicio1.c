/*Ejercicio 1 cooperativo 5*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>





int main()
{
    
    char c;


    double x1, y1, xk, yk, xkmas1, ykmas1, suma, sumx, sumy, a, xcent, ycent;
    int n, i;


    do
    {
       
        printf("Centroide\n");
        printf("===========\n\n");


        do
        {
            printf ("\nIntroduce el numero de lados del poligono (mayor o igual a 3): ");
            scanf (" %d", &n);
        } while (n < 3);
        printf ("\nIntroduce coordenadas x,y del primer punto: ");
        scanf (" %lf %lf", &x1, &y1);
        
        xk = x1;
        yk = y1;
      
        suma = 0;
        sumx = 0;
        sumy = 0;
       
        for (i=2; i<=n; i++)
        {
            printf ("\nIntroduce coordenadas x,y del siguiente punto: ");
            scanf (" %lf %lf", &xkmas1, &ykmas1);

            suma = suma + (xk * ykmas1 - xkmas1 * yk);
            sumx = sumx + ((xkmas1 + xk) * (xk * ykmas1 - xkmas1 * yk));
            sumy = sumy + ((ykmas1 + yk) * (xk * ykmas1 - xkmas1 * yk));

            
            xk = xkmas1;
            yk = ykmas1;
        }
    
        suma = suma + (xk * y1 - x1 * yk);
        sumx = sumx + ((x1 + xk) * (xk * y1 - x1 * yk));
        sumy = sumy + ((y1 + yk) * (xk * y1 - x1 * yk));

        a = suma / 2;
        xcent = sumx / (6*a);
        ycent = sumy / (6*a);

        printf ("\nCentroide = (%.3lf, %.3lf)", xcent, ycent);



        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }
    while (c!='N');
    return 0;
}

