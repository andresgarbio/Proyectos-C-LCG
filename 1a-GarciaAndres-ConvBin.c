#include <stdio.h>

/*Diccionario de variables:
 * i: contador multiproposito reciblable
 * decimal: acumulador que almacena el producto de la conversion y al final se imprime
 * binario[]: arreglo en el que se almacenan los digitos que el usuario inserta
 */
 
int i, decimal, binario[16];

int main(){
	
	decimal = 0;
	
	puts("Bienvenido al CONVERTIDOR BINARIO A DECIMAL!");
	puts("Introduce tu numero binario de IZQUIERDA A DERECHA tecleando 1 o 0:");
	puts("SOLO NUMEROS PORFAVOR!");
	for(i = 0 ; i < 16; i++){
		printf("Ingresa el %d° digito \n",i+1);
		scanf("%d", &binario[i]); 
		/* candado anti-errores */
		while((binario[i] != 1) && (binario[i] != 0)){
			printf("Solo puedes insertar 1 o 0 \n");
			scanf("%d", &binario[i]);
		/* aqui, se recorre a la izquierda el digito binario dependiendo de el valor
		 * que tiene en el numero binario del usuario... cada nuevo 
		 * valor se almacena en decimal usando un "or" binario */
		}decimal |= (binario[i] << (15 - i));
	}printf ("Tu numero decimal es: \n%d\n", decimal) ; 
return(0);
}

