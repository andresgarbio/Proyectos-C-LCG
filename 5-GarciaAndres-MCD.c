#include <stdio.h>

/*Diccionario de variables:
 * 
 * Programa Principal:
 * 
 * divisores_menor[]: arreglo en el que se almacenan los divisores del nuemro con valor absoluto mas pequeño
 * pila_comun[]: arreglo en el que se almacenan los divisores compartidos de dos numeros
 * tamano_pila_menor: tamano del arreglo divisores_menor
 * tamano_pila_comun: tamano del arreglo pila_comun
 * M: numero introducido por usuario
 * N: numero introducido por usuario
 * menor: numero introducido por usuario con menor VALOR ABSOLUTO
 * mayor: numero introducido por usuario con mayor VALOR ABSOLUTO
 * 
 * checar_divisores:
 * i: contador para recorrer la pila menor
 * 
 * generar_divisores:
 * 
 * numero: numero del que se quieren sacar divisores
 * divisor: contador que se usa para buscar divisores de numero
 * 
 * imprimir_pila_comun:
 * 
 * i: contador para recorrer pila comun
 * MCD: Maximo comun divisor donde se almacena el producto de pila comun
 * 
 */

/*este metodo recorre cada factor dentro del arreglo de factores del numero menor
 * si un factor tambien es factor del numero mayor lo alamacena en una pila de factores comunes
 * y se divide mayor/factor para no guardar varias veces un mismo factor*/
int checar_divisores(int pila_comun[], int divisores_menor[], int tamano_pila_menor, int mayor){

	int i, tamano_pila_comun;
	
	for(i = 0 ; i < tamano_pila_menor ; i++){
		if((mayor % divisores_menor[i]) == 0){
			pila_comun[tamano_pila_comun++] = divisores_menor[i];
			mayor = mayor / divisores_menor[i];
		}	
	}return(tamano_pila_comun);
}

/* para esta funcion decidi usar el metodo que los seres humanso usamos para sacar MCD
 * aunque es un metodo antropocentrico, y recursivo, creo que es eficiente*/
int generar_divisores(int numero, int tamano_pila_menor, int divisores_menor[]){

	int divisor;
	
	/* se buscan divisores de un numero, si se encuentran se almacenan
	 * hasta llegar a una condicion de paro*/	
	for(divisor = 2; divisor <= numero ; divisor++){
		/* condicion de paro en caso de numero llegar a 2, 
		 * toma el 2 y lo guarda*/	
		if(divisor == numero){
			divisores_menor[tamano_pila_menor++] = numero;
			return(tamano_pila_menor);
		/* condicion de paro en caso de que el ultimo factor sea numero primo grande, 
		 * (como un numero no puede tener un divisor mas grande que su mitad)
		 * esto no aplica a numeros primos pequeños 
		 * si numero llega 3,  se genera una recursividad nivel fibonacci catastrofica */
		}else if (divisor == numero / 2 ){
			divisores_menor[tamano_pila_menor++] = numero;
			return(tamano_pila_menor);
		/* si se encuentra un divisor, se divide el numero entre divisor 
		 * y se vuelve a buscar divisor para el cociente
		 * hasta que se llega a un primo (condicion paro)
		 * como lo hacemos los seres humanos */
		}else if((numero % divisor) == 0){
			divisores_menor[tamano_pila_menor++] = divisor; 
			tamano_pila_menor = generar_divisores(numero/divisor, tamano_pila_menor, divisores_menor);
			return(tamano_pila_menor);
		}
	}return(tamano_pila_menor);
}

/* Se recorre la pila comun, multiplicando MCD por cada factor
 * al final se imprime MCD, el producto de todos */
void imprimir_pila_comun(int pila_comun[], int tamano_pila_comun){
	
	int i, MCD;
	
	MCD = 1;
	
	for(i = 0 ; i < tamano_pila_comun ; i++){
		MCD *= pila_comun[i];
	}printf("Tu Maximo Comun Divisor es:\n%d\n", MCD);
	if(MCD == 1){
		printf("Que lastima, tus numeros no tienen factores en comun \n");	
	}
}

int main(){
	
	int divisores_menor[10000], pila_comun[10000], tamano_pila_menor, M, N, menor, mayor, tamano_pila_comun; 
	
	/*se inicializan los valores a usarse y lso tamaños de pilas */
	
	menor = 0;
	mayor = 0;
	tamano_pila_menor = 0;
	tamano_pila_comun = 0;
	
	printf("Bienvenido al BUSCADOR de MAXIMO COMUN DIVISOR\nIngresa tu primer numero ENTERO M\n");
	scanf("%d",&M);
	/*candado anti-errores*/
	while(M > 20000 || M < (-20000) || M == 0){
		printf("Solo en el rango ENTEROS de -20000 a 20000\n");
		scanf("%d", &M);
	/* saca valor absoluto de M */	
	}M = (M < 0)? M * -1 : M ;
	printf("Ingresa tu segundo numero ENTERO N\n");
	scanf("%d",&N);
	/*candado anti-errores*/
	while(N > 20000 || N < (-20000) || N == 0){
		printf("Solo en el rango ENTEROS de -20000 a 20000\n");
		scanf("%d", &N);
	/* saca valor absoluto de N */		
	}N = (N < 0)? N * -1 : N ;
	/* sacan el menor y mayor de los dos numeros*/	
	menor = (M > N) ? N : M;
	mayor = (M == menor) ? N : M;
	tamano_pila_menor = generar_divisores(menor, tamano_pila_menor, divisores_menor);
	tamano_pila_comun = checar_divisores(pila_comun, divisores_menor, tamano_pila_menor, mayor);
	imprimir_pila_comun(pila_comun, tamano_pila_comun);
	
	
	return(0);
}
