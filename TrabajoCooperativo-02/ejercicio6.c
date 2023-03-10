/* ejercicio 6 cooperativo 2 */


#include <stdio.h>


int main ()
{
    int europre, centpre, europag, centpag, precio, pagado, centimos, cantidad;

    printf ("\nPrecio del producto");
    printf ("\nIntroduce euros: ");
    scanf (" %d", &europre);
    printf ("\nIntroduce centimos: ");
    scanf (" %d", &centpre);

    printf ("\nImporte pagado");
    printf ("\nIntroduce euros: ");
    scanf (" %d", &europag);
    printf ("\nIntroduce centimos: ");
    scanf (" %d", &centpag);

    precio = europre * 100 + centpre;
    pagado = europag * 100 + centpag;
    centimos = pagado - precio; 

    //billetes de 500
    cantidad = centimos / 50000;
    centimos = centimos % 50000; 
    printf ("\n\nB500 euros: %d", cantidad);
    
    //billetes de 200
    cantidad = centimos / 20000;
    centimos = centimos % 20000;
    printf ("\nB200 euros: %d", cantidad);
    
    //billetes de 100
    cantidad = centimos / 10000;
    centimos = centimos % 10000;
    printf ("\nB100 euros: %d", cantidad);
    
    //billetes de 50
    cantidad = centimos / 5000;
    centimos = centimos % 5000;
    printf ("\nB50 euros: %d", cantidad);
    
    //billetes de 20
    cantidad = centimos / 2000;
    centimos = centimos % 2000;
    printf ("\nB20 euros: %d", cantidad);
    
    //billetes de 10
    cantidad = centimos / 1000;
    centimos = centimos % 1000;
    printf ("\nB10 euros: %d", cantidad);
    
    //billetes de 5
    cantidad = centimos / 500;
    centimos = centimos % 500;
    printf ("\nB5 euros: %d", cantidad);
    
    //monedas de 2 euros
    cantidad = centimos / 200;
    centimos = centimos % 200;
    printf ("\nM2 euros: %d", cantidad);
    
    //monedas de 1 euro
    cantidad = centimos / 100;
    centimos = centimos % 100;
    printf ("\nM1 euro: %d", cantidad);
    
    //monedas de 50 centimos
    cantidad = centimos / 50;
    centimos = centimos % 50;
    printf ("\nM50 centimos: %d", cantidad);
    
    //monedas de 20 centimos
    cantidad = centimos / 20;
    centimos = centimos % 20;
    printf ("\nM20 centimos: %d", cantidad);
    
    //monedas de 10 centimos
    cantidad = centimos / 10;
    centimos = centimos % 10;
    printf ("\nM10 centimos: %d", cantidad);
    
    //monedas de 5 centimos
    cantidad = centimos / 5;
    centimos = centimos % 5;
    printf ("\nM5 centimos: %d", cantidad);
    
    //monedas de 2 centimos
    cantidad = centimos / 2;
    centimos = centimos % 2;
    printf ("\nM2 centimos: %d", cantidad);
    printf ("\nM1 centimos: %d", centimos);    
    
    return 0;
}