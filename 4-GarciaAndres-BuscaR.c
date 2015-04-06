#include <stdio.h>

/*Diccionario de variables usadas :
 * 
 * Programa Principal:
 * 
 * numeros: cantidad de numeros a ordenar y tope del arreglo lista
 * busqueda: valor que el usuario ingresa para encontrar
 * lista[]:arreglo donde se guardan  buscan numeros
 * 
 * buscar:
 * 
 * limitesuperior: indice superior PARA INICIALIZAR la busqueda
 * limiteinferior:  indice inferor PARA INICIALIZAR la busqueda
 * busqueda: valor que el usuario ingresa para encontrar
 * 
 * buscar_recursivo:
 * 
 * limitesuperior: indice superior usado de manera dinamica de la busqueda
 * limiteinferior:  indice inferor usado de manera dinamica de la busqueda
 * mitad: indice a medio camnio entre liminferior y limsuperior
 * 
 * generar_lista:
 *  
 * i: contador reciclable que recorre lista
 * comp: variable que se usa para ordenar hasta el inicio de lista
 * muleta: muleta que ayuda a intercambiar valores de dos numeros 
 *
 */


void buscar(int lista[], int numeros , int busqueda){
	
	/*esta es la funcion recursiva en si, usa la misma tactica de buscar que se uso en programa 3, solo que en vez
	 * de iterar en un while usando banderas para indicar terminacion, se llama a si misma para volver a comparar limites
	 * hasta que las mismas condiciones de paro se cumplen, solo imprime y termina (por las estructuras de if else*/
	void buscar_recursivo(int limitesuperior, int limiteinferior, int busqueda){
		
		int mitad;
		
		mitad =((limitesuperior + limiteinferior) / 2 );
		mitad = (int) mitad;
		if(limitesuperior < limiteinferior){
			printf("Tu numero no esta\n");
		}else if(busqueda < lista[mitad]){
			limitesuperior = mitad - 1;
			buscar_recursivo(limitesuperior, limiteinferior, busqueda);
		}else if(busqueda > lista[mitad]){
			limiteinferior = mitad + 1;
			buscar_recursivo(limitesuperior, limiteinferior, busqueda);
		}else if(busqueda == lista[mitad]){
			printf("Tu numero se encuentra en el indice:\n%d\n", mitad);
		}
	}
	
/* esta funcion buscar) inicializa los limites para la busqueda, y empieza busqueda_recursiva,
 * se separaron las funciones porque la recursividad redefine los limites 
 * y como me gusta la compartamentalizacion, preferi inicializar limites aqui que en programa principal */	
int limitesuperior, limiteinferior;


	limitesuperior = 0;
	limiteinferior = 0;

	limitesuperior = numeros -1;
	limiteinferior = 0;
	buscar_recursivo(limitesuperior, limiteinferior, busqueda);
}	
	

/* funcion que ya se explico en programa 2*/
void generar_lista(int lista[], int numeros){
	
	int i, comp, muleta;
	
	comp = 0;
	muleta = 0;
	
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

/*Programa principal solo recibe datos de usuario y llama funciones*/
int main(){
	
	int numeros, busqueda,lista[10000]; 
	
	busqueda = 0;
	
	printf("Bienvenido al BUSCADOR DE NUMEROS ENTEROS\nQue numero buscas? (-20,000 a 20,000)\nSOLO INSERTA NUMEROS\n");
	scanf("%d", &busqueda);
	/*candado anti-errores*/
	while((busqueda > 20000) || (busqueda < -20000)){
			printf("Rango de (-20,000 a -20,000)\n");
			scanf("%d ", &busqueda);
	}
	printf("Cuantos numeros tienes?\n");
	scanf("%d", &numeros);
	/*candado anti-errores*/
	while((numeros > 10000) || (numeros < 1)){
		printf("Solo pueden ordenarse 10000 numeros\n");
		scanf("%d", &numeros);
	/* ordenamiento de numeros*/
	}generar_lista(lista,numeros);
	/* busqueda que contiene a busqueda recursiva dentro*/
	buscar(lista,numeros, busqueda);

	return(0);
}


