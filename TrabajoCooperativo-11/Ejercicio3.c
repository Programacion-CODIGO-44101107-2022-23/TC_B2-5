#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 5


typedef char cadena10[11];

typedef struct
{
    double largo;
    double ancho;
    cadena10 color;
}tipopieza;

typedef tipopieza tipovector[MAX];

typedef struct
{
    int n;
    tipovector v;
}tipoconjuntopiezas;

int menu ();
void insertarpieza (tipoconjuntopiezas *conj);
void leerpieza (tipopieza *pieza);
void listarpiezas (tipoconjuntopiezas conj);
void escribirpieza (tipopieza pieza);
double calculararea (tipopieza pieza);
void eliminarpiezas (tipoconjuntopiezas *conj);
void desplazar (tipoconjuntopiezas *conj, int i);
void listarcolor (tipoconjuntopiezas conj);
void calcularmenor (tipoconjuntopiezas conj);
void listadoarea (tipoconjuntopiezas conj);
void ordenararea (tipoconjuntopiezas *conj);
void listadoladomayor (tipoconjuntopiezas conj);
void ordenarladomayor (tipoconjuntopiezas *conj);
double ladomayor (tipopieza pieza);

int main ()
{
    int opcion;
    tipoconjuntopiezas conj;

    conj.n = 0;
    do
    {
        opcion = menu ();
        switch (opcion)
        {
            case 1: insertarpieza (&conj);
                    break;
            case 2: listarpiezas (conj);
                    break;
            case 3: eliminarpiezas (&conj);
                    break;
            case 4: listarcolor (conj);
                    break;
            case 5: calcularmenor (conj);
                    break;
            case 6: listadoarea (conj);
                    break;
            case 7: listadoladomayor (conj);
                    break;
            case 0: printf ("\n\nFIN DEL PROGRAMA");
                    break;
            default: printf ("\nOpcion no valida");
                    break;
        }
    }while (opcion != 0);
    return 0;
}

int menu ()
{
    int opcion;

    printf ("\n\nMENU PRINCIPAL");
    printf ("\n1. Insertar pieza");
    printf ("\n2. Listado piezas registradas");
    printf ("\n3. Eliminar piezas no cuadradas");
    printf ("\n4. Total de piezas por color");
    printf ("\n5. Calcular pieza con menor superficie");
    printf ("\n6. Listado decreciente por area");
    printf ("\n7. Listado descendente por longitud del lado mayor");
    printf ("\n0. Salir");
    printf ("\n\nIntroduce opcion: ");
    scanf (" %d", &opcion);
    return opcion;
}

void insertarpieza (tipoconjuntopiezas *conj)
{
    if (conj->n == MAX)
        printf ("\nNo caben mas piezas");
    else
    {
        leerpieza (&conj->v[conj->n]);
        conj->n ++;
    }
}

void leerpieza (tipopieza *pieza)
{
    printf ("\nIntroduce largo: ");
    scanf (" %lf", &pieza->largo);
    printf ("\nIntroduce ancho: ");
    scanf (" %lf", &pieza->ancho);
    printf ("\nIntroduce color: ");
    scanf (" %s", pieza->color);
}

void listarpiezas (tipoconjuntopiezas conj)
{
    int i;
    double area, suma;

    if (conj.n == 0)
        printf ("\nNo hay piezas que listar");
    else
    {
        suma = 0;
        printf ("\nLISTADO DE PIEZAS");
        for (i=0; i<conj.n; i++)
        {
            escribirpieza (conj.v[i]);
            area = calculararea (conj.v[i]);
            printf ("\nArea: %lf", area);
            suma = suma + area;
        }
        printf ("\n\nTotal de piezas registradas: %d", conj.n);
        printf ("\nTotal de superficie: %lf", suma);
    }
}

void escribirpieza (tipopieza pieza)
{
    printf ("\n\nLargo: %lf", pieza.largo);
    printf ("\nAncho: %lf", pieza.ancho);
    printf ("\nColor: %s", pieza.color);
}

double calculararea (tipopieza pieza)
{
    return pieza.largo * pieza.ancho;
}

void eliminarpiezas (tipoconjuntopiezas *conj)
{
    double super, area;
    int i;

    if (conj->n == 0)
        printf ("\nNo hay piezas que eliminar");
    else
    {
        printf ("\nIntroduce valor de la superficie: ");
        scanf (" %lf", &super);
        i = 0;
        while (i < conj->n)
        {
            area = calculararea(conj->v[i]);
            if (conj->v[i].largo != conj->v[i].ancho &&
                    area < super)
            {
                desplazar (conj, i);
                conj->n--;
            }
            else
                i++;
        }
    }
}

void desplazar (tipoconjuntopiezas *conj, int i)
{
    int j;

    for (j=i; j<conj->n-1; j++)
    {
        conj->v[j].largo = conj->v[j+1].largo;
        conj->v[j].ancho = conj->v[j+1].ancho;
        strcpy (conj->v[j].color, conj->v[j+1].color);
    }
}

void listarcolor (tipoconjuntopiezas conj)
{
    int i, j, cont;
    char encon;

    if (conj.n == 0)
        printf ("\nNo hay piezas que listar");
    else
    {
        for (i=0; i<conj.n; i++)
        {
            j = i-1;
            encon = 'N';
            while (j >= 0 && encon == 'N')
            {
                if (strcmp (conj.v[i].color, conj.v[j].color) == 0)
                    encon = 'S';
                else
                    j--;
            }
            if (encon == 'N')
            {
                cont = 0;
                for (j=i; j<conj.n; j++)
                {
                    if (strcmp(conj.v[i].color, conj.v[j].color) == 0)
                        cont ++;
                }
                printf ("\nColor: %s  Numero piezas: %d",
                        conj.v[i].color, cont);
            }
        }
    }
}

void calcularmenor (tipoconjuntopiezas conj)
{
    double largo, ancho, areasuperar, area, areamin;
    int i, cont;
    tipopieza piezamin;

    if (conj.n == 0)
        printf ("\nNo hay piezas");
    else
    {
        printf ("\nIntroduce largo: ");
        scanf (" %lf", &largo);
        printf ("\nIntroduce ancho: ");
        scanf (" %lf", &ancho);

        cont = 0;
        for (i=0; i<conj.n; i++)
        {
            
            if (conj.v[i].largo <= largo &&
                    conj.v[i].ancho <= ancho)
            {
                if (cont == 0 || area < areamin)
                {
                    areamin = area;
                    piezamin.largo = conj.v[i].largo;
                    piezamin.ancho = conj.v[i].ancho;
                    strcpy (piezamin.color, conj.v[i].color);
                }
                cont++;
            }
        }
        if (cont == 0)
            printf ("\nNo hay piezas que cumplan esas caracteristicas");
        else
        {
            printf ("\nLa pieza mas pequeña que cumple es: ");
            escribirpieza (piezamin);
        }
    }
}

void listadoarea (tipoconjuntopiezas conj)
{
    int i;

    if (conj.n == 0)
        printf ("\nNo hay piezas que listar");
    else
    {
        ordenararea (&conj);
        printf ("\nLISTADO DECRECIENTE POR AREA");
        for (i=0; i<conj.n; i++)
            escribirpieza(conj.v[i]);
    }
}

void ordenararea (tipoconjuntopiezas *conj)
{
    int i, j;
    tipopieza aux;

    for (i=1; i<conj->n; i++)
    {
        for (j=0; j<conj->n-i; j++)
        {
            if (calculararea(conj->v[j]) < calculararea(conj->v[j+1]))
            {
                strcpy (aux.color, conj->v[j].color);
                aux.largo = conj->v[j].largo;
                aux.ancho = conj->v[j].ancho;
                strcpy (conj->v[j].color, conj->v[j+1].color);
                conj->v[j].largo = conj->v[j+1].largo;
                conj->v[j].ancho = conj->v[j+1].ancho;
                strcpy (conj->v[j+1].color, aux.color);
                conj->v[j+1].largo = aux.largo;
                conj->v[j+1].ancho = aux.ancho;
            }
        }
    }
}

void listadoladomayor (tipoconjuntopiezas conj)
{
    int i;

    if (conj.n == 0)
        printf ("\nNo hay piezas que listar");
    else
    {
        ordenarladomayor (&conj);
        printf ("\nLISTADO DECRECIENTE POR LADO MAYOR");
        for (i=0; i<conj.n; i++)
            escribirpieza(conj.v[i]);
    }
}

void ordenarladomayor (tipoconjuntopiezas *conj)
{
    int i, j;
    tipopieza aux;

    for (i=1; i<conj->n; i++)
    {
        for (j=0; j<conj->n-i; j++)
        {
            if (ladomayor(conj->v[j]) < ladomayor(conj->v[j+1]))
            {
                strcpy (aux.color, conj->v[j].color);
                aux.largo = conj->v[j].largo;
                aux.ancho = conj->v[j].ancho;
                strcpy (conj->v[j].color, conj->v[j+1].color);
                conj->v[j].largo = conj->v[j+1].largo;
                conj->v[j].ancho = conj->v[j+1].ancho;
                strcpy (conj->v[j+1].color, aux.color);
                conj->v[j+1].largo = aux.largo;
                conj->v[j+1].ancho = aux.ancho;
            }
        }
    }
}

double ladomayor (tipopieza pieza)
{
    if (pieza.largo > pieza.ancho)
        return pieza.largo;
    else
        return pieza.ancho;
}