/*Ejercicio 4 cooperativo 5*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;
  	// Variables 

    int numtramos, i, distancia, tiempo, sumdistancia, sumtiempo, velocidadmedia,
        velocidadmax, velocidad, tramomax;

	
	do
	{
		system("cls||clear");
		printf("nombre\n");
		printf("=================================\n\n");

		// Solucion

        //lo primero que tengo que hacer es leer el numero de tramos
        //que tiene que ser un numero entero positivo
        do
        {
            printf ("\nIntroduce numero de tramos: ");
            scanf (" %d", &numtramos);
        } while (numtramos <= 0);

        //para cada uno de los tramos tengo que leer la distancia recorrida y el tiempo empleado
        //necesito una suma de distancias y una suma de tiempos para poder calcular al final
        //la velocidad media
        //para calcular la velocidad maxima por tramo, tengo que calcular para cada tramo
        //su velocidad (distancia/tiempo) y compararla con la que suponia velocidad maxima
        //que tiene que estar inicializada a un valor muy pequeño para que siempre haya 
        //algun valor mas grande
        //otra posibilidad es inicializarlo al primer valor calculado
        sumdistancia = 0;
        sumtiempo = 0;
        velocidadmax = 0;
        for (i=1; i<=numtramos; i++)
        {
            printf ("\n\nTramo: %d", i);
            printf ("\nIntroduce distancia recorrida (m): ");
            scanf (" %d", &distancia);
            printf ("\nIntroduce tiempo empleado (sg): ");
            scanf (" %d", &tiempo);
            sumdistancia = sumdistancia + distancia;
            sumtiempo = sumtiempo + tiempo;
            velocidad = distancia / tiempo;
            if (velocidad > velocidadmax)
            {
                velocidadmax = velocidad;
                tramomax = i;
            }
        }
        velocidadmedia = sumdistancia / sumtiempo;
        printf ("\n\nVelocidad media trayectoria: %d m/sg", velocidadmedia);
        printf ("\n\nTramo %d -- velocidad maxima por tramo: %d m/sg", tramomax, velocidadmax);


		printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}