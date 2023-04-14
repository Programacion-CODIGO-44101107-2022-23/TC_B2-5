/*Ejercicio 3 cooperativo 5*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>



int main()
{
    
    char c;


    double xizq, xder, fxizq, fxder, e, xmed, fxmed;
    char fin, fin2;
    int cont;


    
    do
    {
        system("cls");
        printf("ESCRIBIR AQUI EL TITULO DEL PROGRAMA\n");
        printf("====================================\n\n");
        


        fin = 'n';
        while (fin == 'n')
        {
            
            do
            {
                printf ("\nIntroduce valores del intervalo (iguales para fin): ");
                scanf (" %lf %lf", &xizq, &xder);
            } while (xizq > xder);

            
            if (xizq == xder)
                fin = 's';
            else 
            {
                
                fxizq = pow(xizq, 5) - pow(xizq, 4) + pow(xizq, 3) - 3;
                fxder = pow(xder, 5) - pow(xder, 4) + pow(xder, 3) - 3;
                
                
                if (fxizq * fxder >= 0)
                    printf ("\nNo cumplen el teorema de Bolzano");
                else 
                {
                   
                    printf ("\nIntroduce precision: ");
                    scanf (" %lf", &e);

                    
                    fin2 = 'n';
                   
                    cont = 0;
                    while (fin2 == 'n')
                    {
                        xmed = (xder + xizq) / 2;
                        fxmed = pow(xmed, 5) - pow(xmed, 4) + pow(xmed, 3) - 3;
                        cont++;
                        if (xder - xizq < e)
                            fin2 = 's';
                        else 
                        {
                            if (fxmed == 0)
                                fin2 = 's';
                            else 
                            {
                                if (fxizq * fxmed < 0)
                                {
                                    xder = xmed;
                                    fxder = fxmed;
                                }
                                else 
                                {
                                    xizq = xmed;
                                    fxizq = fxmed;
                                }
                            }
                        }
                    }
                    printf ("\nRaiz = %.15lf  f(x) = %.15lf  N iteraciones: %d", xmed, fxmed, cont);
                }
                
            }
            
        }





        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getchar());
    }
    while (c!='N');
    return 0;
}