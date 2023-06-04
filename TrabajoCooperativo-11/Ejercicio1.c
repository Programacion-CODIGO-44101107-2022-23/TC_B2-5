#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


#define MAX 200


typedef char cadena30[31];

typedef struct
{
    double densidad;
    int dureza;
    double rt;
    double me;
}tipopro;

typedef struct
{
    cadena30 material;
    cadena30 fabricante;
    tipopro propiedades;
}tipoexperimento;

typedef tipoexperimento tipovector[MAX];


int menu();
void insertarexperimento (tipovector v, int *n);
void leerexperimento (tipoexperimento *e);
void listarexperimentos (tipovector v, int n);
void escribirexperimento (tipoexperimento e);
void modificarmaterial (tipovector v, int n);
void eliminarexperimento (tipovector v, int *n);
void listadoporfabricante (tipovector v, int n);
void clasificacion (tipovector v, int n);
void ordenarpordensidad (tipovector v, int n);
void ordenarpormaterialfabricante (tipovector v, int n);

int main(){

    int opcion, n;
    tipovector v;

    n = 0;
    do
    {
        opcion = menu();
        switch (opcion)
        {
        case 1:
            insertarexperimento (v, &n);
            break;
        case 2:
            listarexperimentos (v, n);
            break;
        case 3:
            modificarmaterial (v, n);
            break;
        case 4:
            eliminarexperimento (v, &n);
            break;
        case 5:
            listadoporfabricante (v, n);
            break;
        case 6:
            clasificacion (v, n);
            break;
        case 0:
            printf ("\n\nFin del programa");
            break;
        default:
            printf ("\nError, opcion no valida");
            break;
        }
    }while (opcion != 0);
    return 0;
}

int menu()
{
    int opcion;

    printf ("\n\nMenu principal");
    printf ("\n1. Insertar un nuevo experimento");
    printf ("\n2. Listar en pantalla todos los experimentos de uno en uno");
    printf ("\n3. Modificar el nombre de un material en todos los experimentos");
    printf ("\n4. Eliminar un experimento dado un material");
    printf ("\n5. Listado por fabricante");
    printf ("\n6. Clasificacion");
    printf ("\n0. Finalizar programa");
    printf ("\n\nIntroduce opcion: ");
    scanf (" %d", &opcion);
    return opcion;
}

void insertarexperimento (tipovector v, int *n)
{

    if (*n == MAX)
        printf ("\nNo se pueden insertar mas experimentos");
    else
    {
        leerexperimento (&v[*n]);
        *n = *n + 1;
        printf ("\nExperimento almacenado");
    }
}

void leerexperimento (tipoexperimento *e)
{
    printf ("\nIntroduce material: ");
    //scanf (" %[^\n]s", e->material);
    fflush(stdin);
    gets(e->material);
    printf ("\nIntroduce fabricante: ");
    //scanf (" %[^\n]s", e->fabricante);
    fflush(stdin);
    gets(e->fabricante);
    printf ("\nIntroduce densidad en Kg/m3: ");
    scanf (" %lf", &e->propiedades.densidad);
    do
    {
        printf ("\nIntroduce dureza (escala 1..10): ");
        scanf (" %d", &e->propiedades.dureza);
    }while (e->propiedades.dureza < 1 || e->propiedades.dureza > 10);
    printf ("\nIntroduce resistencia a la traccion (Mpa): ");
    scanf (" %lf", &e->propiedades.rt);
    printf ("\nIntroduce modulo de elasticidad (Mpa): ");
    scanf (" %lf", &e->propiedades.me);
}

void listarexperimentos (tipovector v, int n)
{
    int i;
    char seguir;

    if (n == 0)
        printf ("\nNo hay experimentos que listar");
    else
    {
        i = 0;
        seguir = 'S';
        while (i < n && seguir == 'S')
        {
            escribirexperimento (v[i]);
            i++;
            do
            {
                printf ("\nQuieres seguir con el listado (S/N): ");
                scanf (" %c", &seguir);
                seguir = toupper(seguir);
            }while (seguir != 'S' && seguir != 'N');
        }
    }
}

void escribirexperimento (tipoexperimento e)
{
    printf ("\n\nMaterial: %s", e.material);
    printf ("\nFabricante: %s", e.fabricante);
    printf ("\nPropiedades:");
    printf ("\n  Densidad: %.2lf Kg/m3", e.propiedades.densidad);
    printf ("\n  Dureza: %d", e.propiedades.dureza);
    printf ("\n  Resistencia a la traccion: %.2lf Mpa", e.propiedades.rt);
    printf ("\n  Modulo de elasticidad: %.2lf Mpa", e.propiedades.me);
}

void modificarmaterial (tipovector v, int n)
{
    cadena30 mat1, mat2;
    int i, cont;

    if (n == 0)
        printf ("\nNo hay experimentos que modificar");
    else
    {
        printf ("\nIntroduce material a modificar: ");
        scanf (" %[^\n]s", mat1);
        printf ("\nIntroduce nuevo material: ");
        scanf (" %[^\n]s", mat2);
        cont = 0;
        for (i=0; i<n; i++)
        {
            if (strcmp (v[i].material, mat1) == 0)
            {
                strcpy (v[i].material, mat2);
                cont++;
            }
        }
        printf ("\nNumero de reemplazos: %d", cont);
    }
}

void eliminarexperimento (tipovector v, int *n)
{
    cadena30 mat;
    int i, j;
    char seguir, borrar;

    if (*n == 0)
        printf ("\nNo hay experimentos que eliminar");
    else
    {
        printf ("\nIntroduce nombre del material que quieres borrar: ");
        scanf (" %[^\n]s", mat);
        i = 0;
        seguir = 'S';
        while (i < *n && seguir == 'S')
        {
            if (strcmp (v[i].material, mat) != 0)
                i++;
            else
            {
                escribirexperimento(v[i]);
                do
                {
                    printf ("\nQuieres borrar este experimento (S/N): ");
                    scanf (" %c", &borrar);
                    borrar = toupper(borrar);
                }while (borrar != 'S' && borrar != 'N');
                if (borrar == 'N')
                    i++;
                else
                {
                    for (j=i+1; j<*n; j++)
                    {
                        strcpy (v[j-1].material, v[j].material);
                        strcpy (v[j-1].fabricante, v[j].fabricante);
                        v[j-1].propiedades = v[j].propiedades;
                    }
                    *n = *n - 1;
                }
                do
                {
                    printf ("\nQuieres seguir con el borrado (S/N): ");
                    scanf (" %c", &seguir);
                    seguir = toupper(seguir);
                }while (seguir != 'S' && seguir != 'N');
            }
        }
    }
}

void listadoporfabricante (tipovector v, int n)
{
    int i, j, cont;
    char encon;

    if (n == 0)
        printf ("\nNo hay experimentos ni fabricantes");
    else
    {
        printf ("\nListado por fabricante");
        for (i=0; i<n; i++)
        {
            j = i-1;
            encon = 'n';
            while (j>=0 && encon=='n')
            {
                if (strcmp(v[i].fabricante, v[j].fabricante) == 0)
                    encon = 's';
                else
                    j--;
            }
            if (encon == 'n')
            {
                cont = 0;
                for (j=i; j<n; j++)
                {
                    if (strcmp(v[i].fabricante, v[j].fabricante) == 0)
                        cont++;
                }
                printf ("\nFabricante: %s   Numero de experimentos: %d", v[i].fabricante, cont);
            }
        }
    }
}

void clasificacion (tipovector v, int n)
{
    int opcion, i;

    if (n == 0)
        printf ("\nNo hay experimentos que listar");
    else
    {
        do
        {
            printf ("\n\nTipos de listados");
            printf ("\n1. Listar experimentos decreciente por densidad");
            printf ("\n2. Listar experimentos por orden de material y fabricante");
            printf ("\nIntroduce opcion (1 o 2): ");
            scanf (" %d", &opcion);
        }while (opcion != 1 && opcion != 2);
        if (opcion == 1)
            ordenarpordensidad (v, n);
        else
            ordenarpormaterialfabricante (v, n);
        printf ("\n\nListado ordenado");
        for (i=0; i<n; i++)
        {
            escribirexperimento(v[i]);
        }
    }
}

void ordenarpordensidad (tipovector v, int n)
{
    int i, j;
    tipoexperimento aux;

    for (i=1; i<n; i++)
    {
        for (j=0; j<n-i; j++)
        {
            if (v[j].propiedades.densidad < v[j+1].propiedades.densidad)
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void ordenarpormaterialfabricante (tipovector v, int n)
{
    int i, j;
    tipoexperimento x;

    for (i=1; i<n; i++)
    {
        x = v[i];
        j = i-1;
        while (j>=0 && ((strcmp (x.material, v[j].material) < 0) ||
                        (strcmp (x.material, v[j].material) == 0 && strcmp (x.fabricante, v[j].fabricante) < 0)))
       {
           v[j+1] = v[j];
           j = j - 1;
       }
       v[j+1] = x;
    }
}