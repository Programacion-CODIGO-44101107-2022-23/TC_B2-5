/* Ejercicio 3  */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	int a, b;
	char operacion, c;

	do{ 
		printf("Vamos a realizar una operacion aritmetica simple:\n\n");
		printf("Introduzca el primer valor con que vamos a operar: ");
		scanf(" %d",&a);
		printf("Introduzca el segundo valor con que vamos a operar: ");
		scanf(" %d",&b);
		printf("\n");
		printf("Introduzca + para sumar, - para restar o * para multiplicar: ");
		scanf(" %c",&operacion);
		switch(operacion){
		case '+': printf("El resultado es: %d\n", a+b);
			      break;
		case '-': printf("El resultado es: %d\n", a-b);
                  break;
		case '*': printf("El resultado es: %d\n", a*b);
                  break;
		default:  printf("Operacion incorrecta\n");
		          break;
		}
		printf("\nDesea efectuar una nueva operacion (S/N)? ");
	              scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}