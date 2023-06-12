#include <stdio.h>

#define MAX 20

typedef struct
{
    float x;
    float y;
}TipoPunto2D;

typedef TipoPunto2D TipoVector[MAX];

typedef struct
{
    int n;
    TipoVector v;
}TipoPoligono;

void escribirPoligono (TipoPoligono poli)
{
    int i;

    printf ("\n\nPoligono:");
    printf ("\nNumero de puntos: %d", poli.n);
    for (i=0;i<poli.n; i++)
        printf ("\n(%f, %f)", poli.v[i].x, poli.v[i].y);
}

void escribirFichero (char nombreFichero[50])
{
    FILE *f;
    TipoPoligono poli;
    char tecla;

    f = fopen (nombreFichero, "rb");
    fread (&poli, sizeof(TipoPoligono), 1, f);
    tecla = 's';
    while (!feof(f) && tecla!='F')
    {
        escribirPoligono (poli);
        printf ("\n\nPulsa cualquier tecla para continuar o F para terminar...");
        scanf ("%c", &tecla);
        fflush (stdin);
        fread (&poli, sizeof(TipoPoligono), 1, f);
    }
    fclose (f);
}

int main ()
{

}