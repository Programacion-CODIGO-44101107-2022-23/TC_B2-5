#include <stdio.h>

typedef char tipocadena [12];
typedef struct
{
    tipocadena nif;
    long ncontador;
    float lecturaanterior;
}tipocliente;

typedef struct 
{
    long ncontador;
    float lecturaactual;
}tipolectura;

void generar (char *nomficcliente, char *nomficlectura);

int main ()
{
    generar ("clientes.dat", "lecturas.dat");
}

void generar (char *nomficcliente, char *nomficlectura)
{
    FILE *fcli, *flec, *fcon, *ferr;
    tipocliente cli;
    tipolectura lec;
    float consumo;

    fcli = fopen (nomficcliente, "rb");
    flec = fopen (nomficlectura, "rb");
    fcon = fopen ("consumos.txt", "w");
    ferr = fopen ("errores.txt", "w");
    fread (&cli, sizeof (tipocliente), 1, fcli);
    fread (&lec, sizeof (tipolectura), 1, flec);
    while (!feof(fcli) && !feof(flec))
    {
        if (cli.ncontador < lec.ncontador)
        {
            fprintf (fcon, "nº contador: %ld  consumo: 0 kWh\n",
                    cli.ncontador);
            fread (&cli, sizeof (tipocliente), 1, fcli);
        }
        else
        {
            if (cli.ncontador > lec.ncontador)
            {
                fprintf (ferr, "nº contador: %ld no existe\n",
                    lec.ncontador);
                fread (&lec, sizeof (tipolectura), 1, flec);
            }
            else
            {
                consumo = lec.lecturaactual - cli.lecturaanterior;
                fprintf (fcon, "nº contador: %ld  consumo: %4.2f kWh\n",
                    cli.ncontador, consumo);
                fread (&cli, sizeof (tipocliente), 1, fcli);
                fread (&lec, sizeof (tipolectura), 1, flec);
            }
        }
    }
    while (!feof(fcli))
    {
        fprintf (fcon, "nº contador: %ld  consumo: 0 kWh\n",
                cli.ncontador);
        fread (&cli, sizeof (tipocliente), 1, fcli);
    }
    while (!feof(flec))
    {
        fprintf (ferr, "nº contador: %ld no existe\n",
            lec.ncontador);
        fread (&lec, sizeof (tipolectura), 1, flec);
    }
    fclose (fcli);
    fclose (flec);
    fclose (fcon);
    fclose (ferr);
}