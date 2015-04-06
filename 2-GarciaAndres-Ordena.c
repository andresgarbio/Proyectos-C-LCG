#include <stdio.h>

/*Diccionario de variables:
 * 
 * numeros:cantidad de numeros a ordenar y tope del arreglo lista
 * i: contador reciclable que recorre lista
 * comp: variable que se usa para ordenar hasta el inicio de lista
 * lista[]: arreglo donde se guardan numeros ordenados
 * muleta: muleta que ayuda a intercambiar valores de dos numeros 
 * 
 */

int numeros, i, comp, lista[10000], muleta;

int main(){
	printf ("Bienvenido al ORDENADOR DE NUMEROS ENTEROS\nCuantos numeros quieres ordenar? (no mas de 10,000)\n");
	scanf("%d", &numeros);
	/* candado anti-errores*/
	while((numeros>10000) || (numeros < 1)){
		printf("Solo pueden ordenarse de 1 a 10000 numeros\n");
		scanf("%d", &numeros);
	/* for para recorrer y llenar lista con valores */
	}for(i = 0; i < numeros; i++){
		comp = i;	
		printf("Ingresa tu %d° numero\n(-20,000 a -20,000)\n", i + 1 );
		scanf("%d", &lista[i]);
		/*candado anti-errores*/
		while((lista[i] > 20000) || (lista[i] < -20000)){
			printf("Rango de (-20,000 a -20,000)\n");
			scanf("%d", &lista[i]);
		/*este while compara el numero ingresado con el anterior en lista, 
		 * si es menor los intercambia y sigue comparando con numero
		 * anterior en lista hasta que el numero ingresado este en su lugar
		 * comp sirve como un indice que cambia para poder comparar hasta el inicio, 
		 * y se reinicializa para cada nuevo valor*/
		}while(lista[comp] < lista[comp - 1] && comp ){
			muleta = lista[comp];
			lista[comp] = lista[comp - 1];
			lista[comp - 1] = muleta;
			comp--;
		}
		/*imprime la lista para el ususario*/
	}printf("Aqui estan tus numeros ordenados:\n");
	for(i = 0 ; i < numeros ; i++){
		printf("%d ",(int)lista[i]);
	}printf("\n");
return(0);
}
