/* Ejercicio 5 */
#include <stdio.h>

int main(){
	char nombre[30];

	printf("Pruebas de formatos de salida\n");
	printf("=============================\n");
	printf("\nDiferentes formatos de salida para el texto:\n\n");
	printf("%s\n", "Esta es una linea de texto de prueba");
	printf("%50s\n", "Esta es una linea de texto de prueba");
	printf("%-50s\n", "Esta es una linea de texto de prueba");
	printf("%-50.10s\n", "Esta es una linea de texto de prueba");
	printf("\nDiferentes formatos de salida para numeros enteros:\n");
	printf("\n1)\n%d\n%d\n%d\n%d\n",8,1234,23,12000);
	printf("\n2)\n%10d\n%10d\n%10d\n%10d\n",8,1234,23,12000);
	printf("\nDiferentes formatos de salida para numeros reales:\n");
	printf("\n1)\n%f\n%f\n%f\n",123.89,-4.0,2345.8999);
	printf("\n2)\n%15f\n%15f\n%15f\n",123.89,-4.0,2345.8999);
	printf("\n3)\n%15.2f\n%15.2f\n%15.2f\n",123.89,-4.0,2345.8999);
	printf("\n\nPulse una tecla para finalizar");
	getchar();
	return 0;
}

