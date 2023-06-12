#include <stdio.h>
#include <math.h>

#define MAX 10

typedef struct
{
    int dia;
    int mes;
    int anio;
}TipoFecha;

typedef struct
{
    int hora;
    int minuto;
    int segundo;
}TipoTiempo;

typedef float TipoSensores [MAX];

typedef struct
{
    TipoFecha fecha;
    TipoTiempo tiempo;
    TipoSensores sensores;
}TipoMedida;

int menu ();
void comprobarcaldera (char *nombrefichero);
void coeficientecorrelacion (char *nombrefichero);
void ajustarsensores (char *nombrefichero);

int main ()
{
    int opcion;

    do
    {
        opcion = menu ();
        switch (opcion)
        {
            case 1:
                comprobarcaldera ("datossensores.dat");
                break;
            case 2:
                coeficientecorrelacion ("datossensores.dat");
                break;
            case 3:
                ajustarsensores ("datossensores.dat");
                break;
        }
    }while (opcion != 0);
}

int menu ()
{
    int opcion;

    printf ("\n\nMenu principal");
    printf ("\n1. Calcular valor maximo, minimo y medio de la temperatura");
    printf ("\n   de la caldera");
    printf ("\n2. Coeficiente de correlacion para los sensores 5 y 7");
    printf ("\n3. Ajustar medidas de los sensores 3 y 5");
    printf ("\n0. Salir");
    printf ("\nIntroduce opcion: ");
    scanf ("%d", &opcion);
    return opcion;
}

void comprobarcaldera (char *nombrefichero)
{
    FILE *f;
    TipoMedida medida;
    int cont;
    float sum, med, max, min, desvia;

    f = fopen (nombrefichero, "rb");
    fread (&medida, sizeof(TipoMedida), 1, f);
    cont = 0;
    sum = 0;
    while (!feof(f))
    {
        if (cont == 0)
        {
            max = medida.sensores[4];
            min = medida.sensores[4];
        }
        else
        {
            if (medida.sensores[4] > max)
                max = medida.sensores[4];
            else
            {
                if (medida.sensores[4] < min)
                    min = medida.sensores[4];
            }
        }
        cont ++;
        sum = sum + medida.sensores[4];
        fread (&medida, sizeof(TipoMedida), 1, f);
    }
    if (cont == 0)
        printf ("\nNo hay datos");
    else
    {
        printf ("\nTemperatura maxima: %f", max);
        printf ("\nTemperatura minima: %f", min);
        med = sum / cont;
        printf ("\nTemperatura media: %f", med);
        sum = 0;
        fseek (f, 0, SEEK_SET); //rewind (f);
        fread (&medida, sizeof(TipoMedida), 1, f);
        while (!feof(f))
        {
            sum = sum + (fabs(med-medida.sensores[4]));
            fread (&medida, sizeof(TipoMedida), 1, f);
        }
        desvia = sum / cont;
        printf ("\nDesviacion tipica: %f", desvia);
    }
    fclose (f);
}

void coeficientecorrelacion (char *nombrefichero)
{
    FILE *f;
    TipoMedida medida;
    int cont;
    float x, y, sumx, sumy, sumx2, sumy2, sumxy, r;

    f = fopen (nombrefichero, "rb");
    fread (&medida, sizeof(TipoMedida), 1, f);
    cont = 0;
    sumx = 0;
    sumy = 0;
    sumx2 = 0;
    sumy2 = 0;
    sumxy = 0;
    while (!feof(f))
    {
        x = medida.sensores[4];
        y = medida.sensores[6];
        cont++;
        sumx = sumx + x;
        sumy = sumy + y;
        sumx2 = sumx2 + x*x;
        sumy2 = sumy2 + y*y;
        sumxy = sumxy + x*y;
        fread (&medida, sizeof(TipoMedida), 1, f);
    }
    if (cont == 0)
        printf ("\nNo hay datos");
    else
    {
        r = (cont*sumxy - sumx*sumy) /
                sqrt((cont*sumx2-sumx*sumx)+(cont*sumy2-sumy*sumy));
        printf ("\nEl coeficiente de correlacion es: %f", r);
    }
    fclose (f);
}

void ajustarsensores (char *nombrefichero)
{
    FILE *f;
    TipoMedida medida;
    int cont;
    float x, y, sumx, sumy, sumx2, sumxy, xmed, ymed, a, b;

    f = fopen (nombrefichero, "rb");
    fread (&medida, sizeof(TipoMedida), 1, f);
    cont = 0;
    sumx = 0;
    sumy = 0;
    sumx2 = 0;
    sumxy = 0;
    while (!feof(f))
    {
        x = medida.sensores[4];
        y = medida.sensores[2];
        cont++;
        sumx = sumx + x;
        sumy = sumy + y;
        sumx2 = sumx2 + x*x;
        sumxy = sumxy + x*y;
        fread (&medida, sizeof(TipoMedida), 1, f);
    }
    if (cont == 0)
        printf ("\nNo hay datos");
    else
    {
        xmed = sumx / cont;
        ymed = sumy / cont;
        b = (cont*sumxy - sumx*sumy) / (cont*sumx2 - sumx*sumx);
        a = ymed - b * xmed;
        printf ("\nLos valores de la resta son:");
        printf ("\nsensor3 = %f + %f * sensor5", a, b);
    }
    fclose (f);
}
