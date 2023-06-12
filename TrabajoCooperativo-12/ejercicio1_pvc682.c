#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>



#define NOMBRE "zz.txt"

int main(){
   
    char c;



    int n, i, j, aste, espa;
    FILE *fich;



   
    do{ system("cls");
        printf("programa fvpa\n");
        printf("=============\n\n");
       

        fich = fopen (NOMBRE, "w");

        do
        {
            printf ("\nIntroduce numero positivo: ");
            scanf (" %d", &n);
        }while (n <= 0);
        if (n % 2 == 0)
        {
            for (i=1; i<=n; i++)
            {
                for (j=1; j<=i; j++)
                {
                    printf ("* ");
                    fprintf (fich, "* ");
                }
                printf ("\n");
                fprintf (fich, "\n");
            }
        }
        else
        {
            aste = 1;
            espa = (n-1) / 2;
            for (i=1; i<=n; i++)
            {
                for (j=1; j<=espa; j++)
                {
                    printf ("  ");
                    fprintf (fich, "  ");
                }
                for (j=1; j<=aste; j++)
                {
                    printf ("* ");
                    fprintf (fich, "* ");
                }
                printf ("\n");
                fprintf (fich, "\n");
                if (i > n/2)
                {
                    aste = aste - 2;
                    espa++;
                }
                else
                {
                    aste = aste + 2;
                    espa--;
                }
            }
        }


        fclose (fich);




        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }while (c!='N');
    return 0;
}