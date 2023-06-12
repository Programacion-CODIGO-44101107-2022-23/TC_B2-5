/* Ejercicio 2 del Trabajo cooperativo 1 */
#include <stdio.h>
int main(){
    char nombre[30];
    char apellidos[30];
    printf("Por favor, introduzca su nombre: ");
    scanf(" %[^\n]s",nombre);
    printf("Por favor, introduzca su apellidos: ");
    scanf(" %[^\n]s",apellidos);
    printf("\n\nSaludos D. %s %s", nombre, apellidos);
    printf("\nBienvenido al fantastico mundo de la programacion");
    printf("\n\nPulse una tecla para finalizar");
    getchar();
    return 0;
}