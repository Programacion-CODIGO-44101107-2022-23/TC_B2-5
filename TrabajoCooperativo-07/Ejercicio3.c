/*Ejercicio 3 cooperativo 7*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>



void leerrecta (double *xa, double *ya, double *za, double *xb,
                double *yb, double *zb);
void calcularvector (double xa, double ya, double za, double xb,
                     double yb, double zb, double *x, double *y, double *z);
void productovectorial (double ux, double uy, double uz, double vx,
                        double vy, double vz, double *nx, double *ny,
                        double *nz);
double distanciaparalela(double wx, double wy, double wz, double vx,
                         double vy, double vz);
double calculardistancia (double nx, double ny, double nz, double x1,
                          double y1, double z1, double x3, double y3,
                          double z3);

int main(){
    char c;


    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, ux, uy, uz,
            vx, vy, vz, nx, ny, nz, wx, wy, wz, d;



    do{ system("cls");
        printf("Ejercicio 3\n");
        printf("===================\n\n");
        


        printf ("\nPrimera recta:");
        leerrecta (&x1, &y1, &z1, &x2, &y2, &z2); 
        printf ("\nSegunda recta:");
        leerrecta (&x3, &y3, &z3, &x4, &y4, &z4);
        calcularvector (x1, y1, z1, x2, y2, z2, &ux, &uy, &uz); 
        calcularvector (x3, y3, z3, x4, y4, z4, &vx, &vy, &vz);
        productovectorial (ux, uy, uz, vx, vy, vz, &nx, &ny, &nz); 
        calcularvector(x3, y3, z3, x1, y1, z1, &wx, &wy, &wz);
        if (nx == 0 && ny == 0 && nz == 0)
        {
            d = distanciaparalela(wx, wy, wz, vx, vy, vz); 
            printf ("\nDistancia minima es: %.2lf", d);
            if (d  == 0)
                printf ("\nCoincidentes");
            else
                printf ("\nParalelas");
        }
        else
        {
            //d = calculardistancia(wx, wy, wz, nx, ny, nz);
            d = calculardistancia (nx, ny, nz, x1, y1, z1, x3, y3, z3); 
            printf ("\nDistancia minima es: %.2lf", d);
            if (d == 0)
                printf ("\nSecantes");
            else
                printf ("\nSe cruzan");
        }






        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }while (c!='N');
    return 0;
}

void leerrecta (double *xa, double *ya, double *za, double *xb,
                double *yb, double *zb)
{
    printf ("\nIntroduce los dos puntos que definen la recta:");
    printf ("\nIntroduce coordenadas del primer punto:");
    scanf (" %lf %lf %lf", &*xa, &*ya, &*za);
    printf ("\nIntroduce coordenadas del segundo punto:");
    scanf (" %lf %lf %lf", &*xb, &*yb, &*zb);
}

void calcularvector (double xa, double ya, double za, double xb,
                     double yb, double zb, double *x, double *y, double *z)
{
    *x = xb - xa;
    *y = yb - ya;
    *z = zb - za;
}

void productovectorial (double ux, double uy, double uz, double vx,
                        double vy, double vz, double *nx, double *ny,
                        double *nz)
{
    *nx = uy * vz - uz * vy;
    *ny = uz * vx - ux * vz;
    *nz = ux * vy - uy * vx;
}

double distanciaparalela(double wx, double wy, double wz, double vx,
                         double vy, double vz)
{
    double dx, dy, dz, md, mv, d;

    productovectorial(wx, wy, wz, vx, vy, vz, &dx, &dy, &dz);
    md = sqrt(dx*dx + dy*dy + dz*dz);
    mv = sqrt(vx*vx + vy*vy + vz*vz);
    d = md / mv;
    return d;
}

