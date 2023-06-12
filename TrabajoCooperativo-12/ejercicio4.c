#include <stdio.h>
#include <string.h>

typedef char TipoCadena50[51];

typedef struct
{
    TipoCadena50 asig;
    float nota;
}TipoCalificacion;

typedef struct
{
    TipoCadena50 nombre;
    TipoCalificacion cali;
}TipoAlumno;

void pasarATexto (TipoCadena50 nombreBinario, TipoCadena50 nombreTexto)
{
    FILE *ftexto, *fbinario;
    TipoAlumno alu;
    char cadena[250], numero[10];

    fbinario = fopen (nombreBinario, "rb");
    ftexto = fopen (nombreTexto, "w");
    fread (&alu, sizeof(TipoAlumno), 1, fbinario);
    while (!feof(fbinario))
    {
        strcpy (cadena, alu.nombre);
        strcat (cadena, " ");
        strcat (cadena, alu.cali.asig);
        strcat (cadena, " ");
        sprintf (numero, "%f", alu.cali.nota);
        strcat (cadena, numero);
        fputs (cadena, ftexto);
        fread (&alu, sizeof(TipoAlumno), 1, fbinario);
    }
    fclose (fbinario);
    fclose (ftexto);
}

int main ()
{

}