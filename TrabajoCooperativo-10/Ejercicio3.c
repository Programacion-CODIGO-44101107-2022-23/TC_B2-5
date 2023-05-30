#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


#define PI 3.14159


typedef struct
{
    char tipo;
    union
    {
        struct
        {
            double radio;
        };
        struct
        {
            double base;
            double altura;
        };
        struct
        {
            double a;
            double b;
            double c;
        };
    };
}tipofigura;


void leerfigura (tipofigura *f);
void calculararea (tipofigura f);


int main(){
    char c;

    char cadena[20];

    tipofigura f;
    int n;


    strcpy (cadena, "Stop: '1' peligro");

    do{ system("cls");
        printf("Ejercicio 3\n");
        printf("===========\n\n");



        leerfigura (&f);
        calculararea (f);






        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }while (c!='N');
    return 0;
}

void leerfigura (tipofigura *f)
{
    do
    {
        printf ("\nTipo de figura:");
        printf ("\nC - circulo");
        printf ("\nR - rectangulo");
        printf ("\nT - triangulo");
        printf ("\nIntroduce tipo (C, R, T): ");
        scanf (" %c", &f->tipo);
        f->tipo = toupper (f->tipo);
    }while (f->tipo != 'C' && f->tipo != 'R' && f->tipo != 'T');
    switch (f->tipo)
    {
    case 'C':
        printf ("\nIntroduce radio del circulo: ");
        scanf (" %lf", &f->radio);
        break;
    case 'R':
        printf ("\nIntroduce base y altura del rectangulo: ");
        scanf (" %lf %lf", &f->base, &f->altura);
        break;
    case 'T':
        printf ("\nIntroduce la longitud de los 3 lados: ");
        scanf (" %lf %lf %lf", &f->a, &f->b, &f->c);
        break;
    }
}

void calculararea (tipofigura f)
{
    double area, s;

    switch (f.tipo)
    {
    case 'C':
        if (f.radio <= 0)
            printf ("\nCirculo no valido");
        else
        {
            area = PI * f.radio * f.radio;
            printf ("\nEl area del circulo es: %.2lf", area);
        }
        break;
    case 'R':
        if (f.base <= 0 || f.altura <= 0)
            printf ("\nRectangulo no valido");
        else
        {
            area = f.base * f.altura;
            printf ("\nEl area del rectangulo es: %.2lf", area);
        }
        break;
    case 'T':
        if (f.a >= f.b+f.c || f.b >= f.a+f.c || f.c >= f.a+f.b)
            printf ("\nTriangulo no valido");
        else
        {
            s = (f.a + f.b + f.c) / 2;
            area  = sqrt(s * (s-f.a) * (s-f.b) * (s-f.c));
            printf ("\nEl area del triangulo es: %.2lf", area);
        }
        break;
    }
}