#include <stdio.h>

/*Diccionario de variables:
 * i: contador reciclable usado para recorrer a decimal
 * decimal:variable decimal que introduce el usuario
 * digito: valor de un digito binario de decimal
 * significancia: bandera que se activa cuando un digito ya es significante
 * binario[]: arreglo en el que se almacenan los digitos binarios de decimal
 */

int i, decimal, digito, significancia, binario[16];

int main(){

	significancia = 0;
	digito = 0;

	printf("Bienvenido al CONVERTIDOR DECIMAL A BINARIO!\n");
	printf("Introduce tu numero decimal (de 0 a 65535) \n");
	scanf("%d", &decimal);
	/* candado anti errores */
	while(decimal > 65535 || decimal < 0 ){
		printf("solo de 0 65535\n");
		scanf("%d", &decimal);
	}for(i = 16; i ; i--){
		/*se recorre decimal, para que asi
		 * el digito binario de interes quede en la posicion en la que vale 1 */
		digito = decimal >> (i - 1);
		/*se usa & para limpiar digitos de digitos indeseados a la izquierda del primer digito 1  */
		digito &= 1;
		binario[16 - i] = digito;
	}printf("Tu numero binario es:\n");
	for(i = 0 ; i < 16; i++){
		/* si el numero binario tiene 0s a la izquierda, este inconveniente se arregla
		 * con una bandera que se active cuando empiecen los digitos significantes */
		if((int)binario[i]){
			significancia = 1;	
		}if(significancia){
			printf("%d", (int)binario[i]);	
		}/* debido a la bandera significancia, si decimal es  == 0 no se imprime nada
		*este if else lidia con ese caso */
	}if(decimal == 0){
		printf("0\n");
	}printf("\n");
return(0);
}
