#include <stdio.h>
#include <string.h>

#define MAXALUMNOS 10
#define MAXPARCIALES 5

typedef char TipoCadena20[21];
typedef float TipoParciales[MAXPARCIALES];
typedef struct
{
    TipoCadena20 nombre;
    TipoCadena20 apellidos;
    TipoParciales parciales;
    float media;
}TipoAlumno;
typedef TipoAlumno TipoVector[MAXALUMNOS];

void leerdatosfichero (char *nombrefichero, TipoVector vector,
        int *numalum, int *numparciales);
int menu ();
void leerdatosalumno (TipoVector vector, int *numalum, int numparciales);
int buscaralumno (TipoVector vector, int numalum, TipoCadena20 nom, TipoCadena20 ape);
void leercalificaciones(TipoVector vector, int numalum, int *numparciales);
void consultaralumno (TipoVector vector, int numalum, int numparciales);
void escribiralumno (TipoAlumno alu, int numparciales);
void listadoalumnos (TipoVector vector, int numalum, int numparciales);
void notasfinalesalumno (TipoVector vector, int numalum, int numparciales);
void notasfinalesparcial (TipoVector vector, int numalum, int numparciales);
void guardardatosfichero (char *nombrefichero, TipoVector vector,
        int numalum);

int main ()
{
    int numalum, numparciales, opcion;
    TipoVector vector;

    leerdatosfichero ("alumnos.dat", vector, &numalum, &numparciales);
    do
    {
        opcion = menu ();
        switch (opcion)
        {
            case 1:
                leerdatosalumno (vector, &numalum, numparciales);
                break;
            case 2:
                leercalificaciones(vector, numalum, &numparciales);
                break;
            case 3:
                consultaralumno (vector, numalum, numparciales);
                break;
            case 4:
                listadoalumnos (vector, numalum, numparciales);
                break;
            case 5:
                notasfinalesalumno (vector, numalum, numparciales);
                notasfinalesparcial (vector, numalum, numparciales);
                break;
        }
    }while (opcion != 0);
    guardardatosfichero ("alumnos.dat", vector, numalum);
}

void leerdatosfichero (char *nombrefichero, TipoVector vector,
        int *numalum, int *numparciales)
{
    FILE *f;
    int encon;

    *numalum = 0;
    *numparciales = 0;
    f = fopen (nombrefichero, "rb");
    if (f == NULL)
        return;
    fread (&vector[*numalum], sizeof(TipoAlumno), 1, f);
    while (!feof (f))
    {
        *numalum = *numalum + 1;
        fread (&vector[*numalum], sizeof(TipoAlumno), 1, f);
    }
    fclose (f);
    encon = 0;
    while (*numparciales<MAXPARCIALES && !encon)
    {
        if (vector[0].parciales[*numparciales] == -2)
            encon = 1;
        else
            *numparciales = *numparciales + 1;
    }
}

int menu ()
{
    int opcion;

    printf ("\nMenu principal");
    printf ("\n1. Insertar los datos de un nuevo alumno");
    printf ("\n2. Leer calificaciones examenes parciales");
    printf ("\n3. Consultar los datos de un alumno");
    printf ("\n4. Listado secuencial de calificaciones");
    printf ("\n5. Calificacion final");
    printf ("\n0. Salir");
    printf ("\nIntroduce opcion: ");
    scanf ("%d", &opcion);
    return opcion;
}

void leerdatosalumno (TipoVector vector, int *numalum, int numparciales)
{
    TipoCadena20 nom, ape;
    int pos, i;

    if (*numalum == MAXALUMNOS)
        printf ("\nNo se pueden registrar mas alumnos");
    else
    {
        printf ("\nIntroduce nombre: ");
        scanf ("%s", nom);
        printf ("\nIntroduce apellidos: ");
        scanf ("%s", ape);
        pos = buscaralumno (vector, *numalum, nom, ape);
        if (pos != -1)
            printf ("\nError, ese alumno ya existe");
        else
        {
            strcpy (vector[*numalum].nombre, nom);
            strcpy (vector[*numalum].apellidos, ape);
            for (i=0; i<numparciales; i++)
                vector[*numalum].parciales[i] = -1;
            for (i=numparciales; i<MAXPARCIALES; i++)
                vector[*numalum].parciales[i] = -2;
            *numalum = *numalum + 1;
        }
    }
}

int buscaralumno (TipoVector vector, int numalum, TipoCadena20 nom, TipoCadena20 ape)
{
    int i, encon;

    i = 0;
    encon = 0;
    while (i<numalum && !encon)
    {
        if (strcmp(vector[i].nombre, nom)==0 &&
                strcmp(vector[i].apellidos, ape)==0)
            encon = 1;
        else
            i++;
    }
    if (encon)
        return i;
    else
        return -1;
}

void leercalificaciones(TipoVector vector, int numalum, int *numparciales)
{
    int i;

    if (*numparciales == MAXPARCIALES)
        printf ("\nNo se pueden leer mas notas parciales");
    else
    {
        if (numalum == 0)
            printf ("\nNo hay alumnos, no se pueden leer notas");
        else
        {
            printf ("\nNotas del parcial: %d ", (*numparciales+1));
            for (i=0; i<numalum; i++)
            {
                printf ("\nAlumno: %s %s", vector[i].nombre, vector[i].apellidos);
                printf ("\nIntroduce nota (-1 para no presentado): ");
                scanf ("%f", &vector[i].parciales[*numparciales]);
            }
            *numparciales = *numparciales + 1;
        }
    }
}

void consultaralumno (TipoVector vector, int numalum, int numparciales)
{
    TipoCadena20 nom, ape;
    int pos, i;

    if (numalum == 0)
        printf ("\nNo hay alumnos");
    else
    {
        printf ("\nIntroduce nombre: ");
        scanf ("%s", nom);
        printf ("\nIntroduce apellidos: ");
        scanf ("%s", ape);
        pos = buscaralumno (vector, numalum, nom, ape);
        if (pos == -1)
            printf ("\nError, ese alumno NO existe");
        else
            escribiralumno (vector[pos], numparciales);
    }
}

void escribiralumno (TipoAlumno alu, int numparciales)
{
    int i;

    printf ("\n\nNombre: %s", alu.nombre);
    printf ("\nApellidos: %s", alu.apellidos);
    printf ("\nNotas de los parciales: ");
    for (i=0; i<numparciales; i++)
        printf ("\nParcial: %d  Nota: %f", (i+1), alu.parciales[i]);
}

void listadoalumnos (TipoVector vector, int numalum, int numparciales)
{
    int i;
    char seguir;

    if (numalum == 0)
        printf ("\nNo hay alumnos");
    else
    {
        i = 0;
        seguir = 'S';
        while (i<numalum && seguir!='T')
        {
            escribiralumno (vector[i], numparciales);
            i++;
            if (i % 5 == 0)
            {
                printf ("\n\nDesea continuar (T para fin): ");
                fflush (stdin);
                scanf ("%c", &seguir);
            }
        }
    }
}

void notasfinalesalumno (TipoVector vector, int numalum, int numparciales)
{
    int i, j, cont;
    float sum;

    for (i=0; i<numalum; i++)
    {
        cont = 0;
        sum = 0;
        for (j=0; j<numparciales; j++)
        {
            if (vector[i].parciales[j] != -1)
            {
                sum = sum + vector[i].parciales[j];
                cont++;
            }
            if (cont == numparciales)
            {
                vector[i].media = sum / cont;
                escribiralumno (vector[i], numparciales);
                printf ("\nNota Media: %f", vector[i].media);
            }
        }

    }
}

void notasfinalesparcial (TipoVector vector, int numalum, int numparciales)
{
    int i, j, cont;
    float sum, med;

    for (j=0; j<numparciales; j++)
    {
        cont = 0;
        sum = 0;
        for (i=0; i<numalum; i++)
        {
            if (vector[i].parciales[j] != -1)
            {
                sum = sum + vector[i].parciales[j];
                cont++;
            }
            if (cont == 0)
                printf ("\nNo se presento ningun alumno al parcial %d",
                        (i+1));
            else
            {
                med = sum / cont;
                printf ("\nParcial: %d Nota Media: %f", (i+1), med);
            }
        }
    }
}

void guardardatosfichero (char *nombrefichero, TipoVector vector,
        int numalum)
{
    FILE *f;
    int i;

    f = fopen (nombrefichero, "wb");
    for (i=0; i<numalum; i++)
        fwrite (&vector[i], sizeof(TipoAlumno), 1, f);
    fclose (f);
}