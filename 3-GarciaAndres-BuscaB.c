#include <stdio.h>

/*Diccionario de variables:
 * 
 * Programa Principal:
 * 
 * lista: arreglo en el que se ordenan y luego buscan los numeros
 * numeros: cantidad de numeros a ordenar y buscar, y tope del arreglo lista
 * limitesuperior: indice superior dinamico de la busqueda
 * limiteinferior:  indice inferor dinamico de la busqueda
 * busqueda: valor que el usuario ingresa para encontrarlo
 * encontrado:bandera que indica que se encontro el numero buscado
 * noencontrado: bandera que indica que el numero buscado no se encontro
 * mitad: indice a medio camnio entre liminferior y limsuperior
 * 
 * generar_lista:
 *  
 * i: contador reciclable que recorre lista
 * comp: variable que se usa para ordenar hasta el inicio de lista
 * muleta: muleta que ayuda a intercambiar valores de dos numeros 
 *
 */

/* este metodo (la totalidad del programa) 2 ordena los numeros
 * a medida que el usuario los mete*/
void generar_lista(int lista[], int numeros){
	
	int i, comp, muleta;
	
	comp = 0;
	muleta = 0;
    printf("numeros %d \n",numeros);
	for(i = 0; i < numeros; i++){
		comp = i;	
		printf("Ingresa tu %d° numero\n(-20,000 a -20,000)\n", i + 1 );
		scanf("%d", &lista[i]);
		while((lista[i] > 20000) || (lista[i] < -20000)){
			printf("Rango de (-20,000 a -20,000)\n");
			scanf("%d", &lista[i]);
		}while(lista[comp] < lista[comp - 1] && comp ){
			muleta = lista[comp];
			lista[comp] = lista[comp - 1];
			lista[comp - 1] = muleta;
			comp--;
		}
	}
}

/*la busqueda en lista ocurre en el programa principal*/

int main(){
	
	int limitesuperior, limiteinferior,  busqueda, encontrado, noencontrado, mitad, numeros , lista[10000]; 
	
	/*se inicializan las banderas que seran usadas en la busqueda*/
	encontrado = 0;
	noencontrado = 0;
	
	printf("Bienvenido al BUSCADOR DE NUMEROS ENTEROS\nQue numero buscas? (-20,000 a 20,000)\nSOLO INSERTA NUMEROS\n");
	scanf("%d", &busqueda);
	/* candado anti-errores */
	while((busqueda > 20000) || (busqueda < -20000)){
			printf("Rango de (-20,000 a -20,000)\n");
			scanf("%d ", &busqueda);
	}
	printf("Cuantos numeros tienes?\n");
	scanf("%d", &numeros);
	/* candado anti-errores */
	while((numeros > 10000) || (numeros < 1)){
		printf("Solo pueden ordenarse 10000 numeros\n");
		scanf("%d", &numeros);
	/* la funcion generar lista (programa 2) ordena lso numeros a medida que el usuario los mete*/
	}generar_lista(lista,numeros);
	/*se inicializan los indices para la busqueda*/
	limitesuperior = numeros -1;
	limiteinferior = 0;
	/* este while realiza la busqueda hasta que se activan las banderas de terminacion*/
	while(!(encontrado) && !(noencontrado)){
		mitad =((limitesuperior + limiteinferior) / 2 );
		mitad = (int) mitad;
		/*condicion de paro para busqueda: si el numero no esta, 
		 * el limite superior e inferior se igualaron en algun punto sin 
		 * haberlo encontrado */
		if(limitesuperior < limiteinferior){
			printf("Tu numero no esta\n");
			noencontrado = 1;
		/* si la busqueda es mas pequeña que la mitad entre los limites solo se busca en la mitad inferior del rango de busqueda*/
		}else if(busqueda < lista[mitad]){
			limitesuperior = mitad - 1;
		/* si la busqueda es mas grande que la mitad entre los limites solo se busca en la mitad superior del rango de busqueda*/
		}else if(busqueda > lista[mitad]){
			limiteinferior = mitad + 1;
		/* se llegara a un punto en que limitesuperior e inferior son iguales entre ellos y a mitad
		 * si la busqueda no esta en mitad, se realizara el while otra vez,
		 * se hara una comparacion que cambiara un limite, y los limites se pasaran entre ellos*/
		}else if(busqueda == lista[mitad]){
			printf("Tu numero se encuentra en el indice:\n%d\n", mitad);
			encontrado = 1;
		}
	}
	return(0);
}

