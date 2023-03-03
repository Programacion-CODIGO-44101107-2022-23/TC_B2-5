/* Ejercicio 4 */

#include <stdio.h>

int main()
{
    int edad;

    printf("Por favor, introduzca su edad: ");
    scanf(" %d", &edad);
    printf("\nPara una edad de %d años\n",edad);
    printf("una lectura adecuada puede ser: ");
    if(edad>60)
        printf("\"La historia de Roma\"\n");
    else if(edad>40)
            printf("El nombre de la rosa\n");
        else if(edad>18)
                printf("Fundamentos de Programacion\n");
            else if(edad>15)
                    printf("Aventuras en los mares del sur\n");
                else if(edad>10)
                        printf("Harry Potter\n");
                    else printf("Cuentos\n");
    printf("\n\nPulse una tecla para finalizar");
    int getc();
    return 0;
}