#include <stdio.h>

/*Diccionario de variables:
 * 
 * RED[][]: arreglo global donde se almacenan las conecciones de la red
 * 
 * Programa Principal:
 * 
 * nodos_totales: alamacena la cantidad de nodos en la red, funciona como tope de RED[][]
 * respuesta: almacena la respuesta del usuario 
 * nodo: contador que indica cual nodo debe ser analizado y/o impreso
 * grados: contador que indica las conexiones directas de nodo
 * coeficiente_clustering: almacena el resultado de generar_coeficiente_clustering
 * 
 * generar_conexiones1:
 * 
 * nodo1: contador que le indica al usuario un nodo x que puede ser "emisor" de conexion
 * nodo2: contador que le indica al usuario un nodo y que puede ser "receptor" de conexion
 * 
 * generar_conexiones2:
 * 
 * nodo: contador que aumenta al generar conexiones hasta que se llega al limite dado por "conexiones"
 * conexiones: valor dado el usuario que indica el numero de iteraciones para generar conexiones
 * conectadode: contador que le indica al usuario un nodo x que puede ser "emisor" de conexion
 * conectadoa: contador que le indica al usuario un nodo y que puede ser "receptor" de conexion
 * 
 * conseguir_grados:
 * 
 * grados: contador que almacena el numero de vecinos de un nodo
 * vecino: contador usado para recorrer RED[][] 
 * 
 * generar_coeficiente_clustering:
 * 
 * vecino: contador usado para recorrer RED[][]
 * vecino_indirecto: contador para recorrer RED[][]
 * vecindades: acumulador para almacenar vecindades entre nodos vecinos de el nodo en cuestion
 * vecindades_decimal: version float de a variable vecindades
 * grados_decimal: version float de la variable grados
 * coeficiente_clustering: variable donde se almacena el coeficiente de clustering
 */

int RED[1000][1000];

/*SI la red esta muy conectada, nimodo, lo mejor sera especificar si existen o no todas las conexiones posibles de la red 
 * una por una se le pide al usuario que indique cada conexion posible*/
void generar_conexiones1(int nodos_totales){
	
	int nodo1, nodo2;
	
	for(nodo1 = 0, nodo2 = 0; nodo1 < nodos_totales ; nodo1++){
		/*al igualar nodo2 a nodo 1, recorremos solo la mitad inferior izquierda de la matriz y nos ahorramos tener que especificar 
		 * dos veces la misma conexion*/
		for(nodo2 = nodo1 ; nodo2 < nodos_totales ; nodo2++){
			printf("Si los nodos estan conectados inserta 1 (o cualquier caracter)\n");
			printf("Si no estan conectados inserta 0\nNodo %d esta conectado a %d ?\n", nodo1, nodo2);
			/*se almacena la conexion en las dos cordenadas de la matriz que describen esa conexion*/
			scanf("%d", &RED[nodo1][nodo2]);	
			RED[nodo2][nodo1] = RED[nodo1][nodo2];
		}		
	}
}
/*Si la red tiene pocas conexiones, el usuario las puede contar, luego las ingresa y
 * asi solo tiene que describir las conexiones que hay en ves de tener que especificar si existen o no
 * de entre todas las conexiones posibles*/
 
void generar_conexiones2(int nodos_totales){
		
	int nodo, conexiones, conectadode, conectadoa;
		
	printf("Cuantas conexiones tiene tu red?\n");
	scanf("%d", &conexiones);
	/*candado anti-errores*/
	while(conexiones < 0 ){
			printf("No existen conexiones negativas\n");
			scanf("%d", &conexiones);
	/*para cada nodo conectado, se especifica con cual esta conectado*/
	}for(nodo = 0 ; nodo < conexiones ; nodo++){
		printf("Inserta un nodo que este conectado\n");
		scanf("%d", &conectadode);
		/*candado anti-errores*/
		while(conectadode < 0 || conectadode >= nodos_totales ){
			printf("Ese nodo no existe en tu red, ingresa uno que si\n");
			scanf("%d", &conectadode);
		}printf("A que nodo esta conectado?\n");
		scanf("%d", &conectadoa);
		/*candado anti-errores*/
		while(conectadoa < 0 || conectadoa >= nodos_totales ){
			printf("Ese nodo no existe en tu red, ingresa uno que si\n");
			scanf("%d", &conectadoa);
		/*se almacena la conexion en las dos cordenadas de la matriz que describen esa conexion*/
		}RED[conectadode][conectadoa] = 1;	
		RED[conectadoa][conectadode] = 1;
	}
}


/*esta funcion recorre una columna de la matriz, (el nodo) y examina si tiene vecinos (si hay conexion entre nodo y "vecino"
 * si si son vecinos, incrementa grados, almacenando la cantidad*/

int conseguir_grados(int nodo, int nodos_totales){

	int grados, vecino;
	
	grados = 0;
	
	for(vecino = 0; vecino < nodos_totales; vecino++){
		if(RED[nodo][vecino]){
			grados++;
			/*si el nodo esta conectado a si mismo, aparte de incrementarse una vez por ser vecinos
			 * se incrementa otra vez*/
			if(nodo == vecino ){
				grados++;
			}
		}
	}return(grados);
}
/*esta funcion genera las variables y lleva a cabo las operaciones necesarias para 
 * generar el coeficiente de clustering*/

float generar_coeficiente_clustering(int nodo, int grados, int nodos_totales){
	
	int vecindades, vecino, vecino_indirecto;
	float coeficiente_clustering, grados_decimal, vecindades_decimal;
	
	vecino_indirecto = 0;
	vecindades = 0;
	
	/*Aquis se usa una estructura de dos fors 
	 * el primer for revisa si nuestro nodo a analizar tiene vecinos
	 * si tiene un vecino se ativa el segundo for
	 * el segundo for revisa si nuestro vecino tiene otros vecinos
	 * si el vecino tiene vecinos (vecinos_indirectos)
	 * y esos vecinos indirectos tambien son vecinos de nodo
	 * se incrementa vecindades*/
	 
	for(vecino = 0; vecino < nodos_totales; vecino++){
		/*las conexiones con si mismo (loops) no se toman en cuenta*/
		if(RED[nodo][vecino] && nodo != vecino){
			for(vecino_indirecto = vecino + 1; vecino_indirecto < nodos_totales; vecino_indirecto++){
				/*el nodo puede aparecer como vecino de su vecino, este caso no se toma en cuenta*/
				if(RED[vecino][vecino_indirecto] && vecino_indirecto != nodo){
					if(RED[nodo][vecino_indirecto]){
					vecindades++;
					}
				}
			}			
		}
	}
	/*se convierten las variables necesarias a float para hacer el cociente*/
	grados_decimal = (float) grados;
	vecindades_decimal = (float) vecindades;
	
		if(grados_decimal > 1){
			coeficiente_clustering = ((2 * vecindades_decimal) / (grados_decimal * (grados_decimal - 1))); 
			/*para evitar divisiones indeterminadas, si un nodo tiene un grado o menos automatiamente se regresa
		 * coeficiente de clustering 0, este problema se resuelve en Programa Principal*/
		 }else{
			coeficiente_clustering = 0;
		}
	return(coeficiente_clustering);
}

/*programa principal donde se consiguen las variables principales y se llama a las funciones*/

int main(){
	
	int nodos_totales, respuesta, nodo, grados; 
	float coeficiente_clustering;
	
	printf("Bienvenid@ al ANALIZADOR DE REDES!\n");
	printf("Para usar este programa necesitas renombrar tus nodos\n");
	printf("ponles numeros empezando por '0', luego '1' , luego '2'...\n");
	printf("Cuantos nodos tiene tu red?\n");
	scanf("%d", &nodos_totales);
	/*candado anti-errores*/
	while(nodos_totales <= 0 ){
		printf("Cuantos nodos tiene tu red\n");
		scanf("%d", &nodos_totales);
	/*Se le pregunta al usuario si su red esta conectada 
	 * para asi saber cual es la manera mas facil de llenar la red*/
	}printf("Vamos a especificar las conexiones de tu red\nTu red esta muy conectada? responde 1 = si, 0 = no\n");
	scanf("%d", &respuesta);
	/*candado anti-errores*/
	while(respuesta != 0 && respuesta != 1){
		printf("Tu red esta muy conectada? responde 1 = si, 0 = no\n");
		scanf("%d", &respuesta);
	}if(respuesta == 1){
		generar_conexiones1(nodos_totales);
	}else if(respuesta == 0){
		generar_conexiones2(nodos_totales);
	/*ya que estan hechas las interacciones de la red, se analizan (llamando funciones)
	 * e imprimen las caracteristicas de cada nodo*/
	}printf("Aqui va el ANALISIS:\n");	
	for( nodo = 0 ; nodo < nodos_totales ; nodo++){
		printf("Nodo %d \n", nodo);
		grados = conseguir_grados(nodo, nodos_totales);
		printf("tiene %d grados\n", grados);
		coeficiente_clustering = generar_coeficiente_clustering(nodo,grados,nodos_totales);
		printf("Su coeficiente de clustering es: ");
		/*nos saltamos la traba aritmetica, y en vez de analizar coeficiente de clustering
		 * analizamos directamente los grados de un nodo, si tiene grado 0, no tiene vecinos y por ende 
		 * un coef clustering indeterminado*/
		if(grados < 2){
			printf("Coeficiente de clustering indeterminado\n");
		}else{
			printf("%f\n", coeficiente_clustering);
		}	
	}

return(0);
}


