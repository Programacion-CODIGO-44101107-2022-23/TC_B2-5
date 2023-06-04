#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


#define MAX 60
#define NOTAS 5


typedef char cadena20[21];

typedef struct
{
    cadena20 nom;
    cadena20 ape1;
    cadena20 ape2;
}tipoidentificacion;

typedef double tiponotas[NOTAS];

typedef struct
{
    tipoidentificacion id;
    tiponotas notas;
}tipoalumno;

typedef tipoalumno tipovector[MAX];


int menu();
void insertaralumno (tipovector v, int *nalu);
void leeridentificacion (tipoidentificacion *iden);
int buscaralumno (tipovector v, int nalu, tipoidentificacion iden);
void insertarcalificacion (tipovector v, int nalu, int *npar);
void consultaindividual (tipovector v, int nalu, int npar);
void escribiralumno (tipoalumno alu, int nparc);
void listadosecuencial (tipovector v, int nalu, int npar);
void calificacionfinal (tipovector v, int nalu, int npar);
double calcularmedia (tiponotas notas, int npar);
void clasificacion (tipovector v, int nalu, int npar);
void ordenaralfabetico (tipovector v, int nalu);
void ordenarpornotafinal (tipovector v, int nalu, int npar);

int main(){

    int opcion, nalu, npar;
    tipovector v;


    nalu = 0;
    npar = 0;
    do
    {
        opcion = menu();
        switch (opcion)
        {
        case 1: insertaralumno (v, &nalu);
            break;
        case 2: insertarcalificacion (v, nalu, &npar);
            break;
        case 3: consultaindividual (v, nalu, npar);
            break;
        case 4: listadosecuencial (v, nalu, npar);
            break;
        case 5: calificacionfinal (v, nalu, npar);
            break;
        case 6: clasificacion(v, nalu, npar);
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
    printf ("\n1. Insertar un nuevo alumno");
    printf ("\n2. Insertar examen parcial");
    printf ("\n3. Consulta individual de calificaciones");
    printf ("\n4. Listado secuencial de calificaciones");
    printf ("\n5. Listado de calificacion final");
    printf ("\n6. Clasificacion");
    printf ("\n0. Finalizar programa");
    printf ("\n\nIntroduce opcion: ");
    scanf (" %d", &opcion);
    return opcion;
}

void insertaralumno (tipovector v, int *nalu)
{
    tipoidentificacion iden;
    int pos, j;

    if (*nalu == MAX)
        printf ("\nNo se pueden insertar más alumnos");
    else
    {
        leeridentificacion (&iden);
        pos = buscaralumno (v, *nalu, iden);
        if (pos != -1)
            printf ("\nEse alumno ya esta registrado");
        else
        {
            strcpy (v[*nalu].id.nom, iden.nom);
            strcpy (v[*nalu].id.ape1, iden.ape1);
            strcpy (v[*nalu].id.ape2, iden.ape2);
            for (j=0; j<NOTAS; j++)
            {
                v[*nalu].notas[j] = -1;
            }
            (*nalu) ++;
        }
    }
}

void leeridentificacion (tipoidentificacion *iden)
{
    printf ("\nIntroduce el nombre: ");
    fflush (stdin);
    gets (iden->nom);
    printf ("\nIntroduce el primer apellido: ");
    fflush (stdin);
    gets (iden->ape1);
    printf ("\nIntroduce el segundo apellido: ");
    fflush (stdin);
    gets (iden->ape2);
}

int buscaralumno (tipovector v, int nalu, tipoidentificacion iden)
{
    int i;
    char encon;

    i = 0;
    encon = 'n';
    while (i < nalu && encon == 'n')
    {
        if (strcmp(v[i].id.nom, iden.nom) == 0 && strcmp(v[i].id.ape1, iden.ape1) == 0
                    && strcmp(v[i].id.ape2, iden.ape2) == 0)
            encon = 's';
        else
            i++;
    }
    if (encon == 's')
        return i;
    else
        return -1;
}

void insertarcalificacion (tipovector v, int nalu, int *npar)
{
    int i;
    double n;

    if (nalu == 0)
        printf ("\nNo hay alumnos para insertar calificaciones");
    else
    {
        if (*npar == NOTAS)
            printf ("\nNo se pueden introducir mas calificaciones");
        else
        {
            printf ("\nExamen parcial numero %d", *npar+1);
            for (i=0; i<nalu; i++)
            {
                do
                {
                    printf ("\nAlumno: %s %s, %s", v[i].id.ape1, v[i].id.ape2, v[i].id.nom);
                    printf ("\nIntroduce nota (0..10 o -1 para no presentado): ");
                    scanf (" %lf", &n);
                }while (n != -1 && (n < 0 || n > 10));
                v[i].notas[*npar] = n;
            }
            (*npar) ++;
        }
    }
}

void consultaindividual (tipovector v, int nalu, int npar)
{
    tipoidentificacion iden;
    int pos;

    if (nalu == 0)
        printf ("\nNo hay alumnos para consultar");
    else
    {
        printf ("\nIntroduce nombre: ");
        fflush (stdin);
        gets(iden.nom);
        printf ("\nIntroduce primer apellido: ");
        fflush (stdin);
        gets(iden.ape1);
        printf ("\nIntroduce segundo apellido: ");
        fflush (stdin);
        gets(iden.ape2);
        pos = buscaralumno(v, nalu, iden);
        if (pos == -1)
            printf ("\nEse alumno no existe");
        else
            escribiralumno (v[pos], npar);
    }
}

void escribiralumno (tipoalumno alu, int npar)
{
    int i;

    printf ("\n\nAlumno: %s %s, %s", alu.id.ape1, alu.id.ape2,
                        alu.id.nom);
    for (i=0; i<npar; i++)
    {
        printf ("\nNota %d: ", i+1);
        if (alu.notas[i] != -1)
            printf ("%.2lf", alu.notas[i]);
    }
}

void listadosecuencial (tipovector v, int nalu, int npar)
{
    int i;

    if (nalu == 0)
        printf ("\nNo hay alumnos que listar");
    else
    {
        printf ("\nListado de notas");
        for (i=0; i<nalu; i++)
        {
            escribiralumno(v[i], npar);
        }
    }
}

void calificacionfinal (tipovector v, int nalu, int npar)
{
    int i;
    double med;

    if (nalu == 0)
        printf ("\nNo hay alumnos que listar");
    else
    {
        if (npar == 0)
            printf ("\nNo hay notas de parciales");
        else
        {
            printf ("\nListado de calificaciones finales");
            for (i=0; i<nalu; i++)
            {
                med = calcularmedia (v[i].notas, npar);
                if (med != -1)
                {
                    printf ("\n\nAlumno: %s %s, %s",
                            v[i].id.ape1, v[i].id.ape2, v[i].id.nom);
                    printf ("\nNota final: %.2lf", med);
                }
            }
        }
    }
}

double calcularmedia (tiponotas notas, int npar)
{
    double suma;
    int i, cont;

    suma = 0;
    cont = 0;
    for (i=0; i<npar; i++)
    {
        if (notas[i] != -1)
        {
            suma = suma + notas[i];
            cont++;
        }
    }
    if (cont < npar)
        return - 1;
    else
        return suma / cont;
}

void clasificacion (tipovector v, int nalu, int npar)
{
    int opcion, i;
    double media;

    if (nalu == 0)
        printf ("\nNo hay alumnos que listar");
    else
    {
        if (npar == 0)
            printf ("\nNo hay notas que listar");
        else
        {
            do
            {
                printf ("\n\nTipos de listados");
                printf ("\n1. Listar calificaciones por orden alfabetico");
                printf ("\n2. Listar calificaciones decrecientes por nota final");
                printf ("\nIntroduce opcion (1 o 2): ");
                scanf (" %d", &opcion);
            }while (opcion != 1 && opcion != 2);
            if (opcion == 1)
                ordenaralfabetico (v, nalu);
            else
                ordenarpornotafinal (v, nalu, npar);
            printf ("\n\nListado ordenado");
            for (i=0; i<nalu; i++)
            {
                escribiralumno(v[i], npar);
                media = calcularmedia(v[i].notas, npar);
                if (opcion == 2 && media != -1)
                    printf ("\nNota media: %.2lf", media);
            }
        }
    }
}

void ordenaralfabetico (tipovector v, int nalu)
{
    int i, j;
    tipoalumno aux;

    for (i=1; i<nalu; i++)
    {
        for (j=nalu-1; j>=i; j--)
        {
            if (strcmp(v[j].id.ape1, v[j-1].id.ape1) < 0 ||
                    (strcmp(v[j].id.ape1, v[j-1].id.ape1) == 0 &&
                         strcmp(v[j].id.ape2, v[j-1].id.ape2) < 0) ||
                    (strcmp(v[j].id.ape1, v[j-1].id.ape1) == 0 &&
                         strcmp(v[j].id.ape2, v[j-1].id.ape2) == 0 &&
                         strcmp(v[j].id.nom, v[j-1].id.nom) < 0))
            {
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }
    }
}

void ordenarpornotafinal (tipovector v, int nalu, int npar)
{
    int i, j;
    tipoalumno aux;
    double medj, medjmenos1;

    for (i=1; i<nalu; i++)
    {
        for (j=nalu-1; j>=i; j--)
        {
            medj = calcularmedia(v[j].notas, npar);
            medjmenos1 = calcularmedia(v[j-1].notas, npar);
            if (medj > medjmenos1)
            {
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }
    }
}