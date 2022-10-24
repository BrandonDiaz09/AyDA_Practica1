//*****************************************************************
//Equipo: Los zetas, conformado por:
// 1. Arcos Salazar Julio Cesar
// 2. Diaz Hernandez Emilio
// 3. Gonzalez Manzano Leonardo
// 4. Brandon
//Curso: Analisis de algoritmos
//Septiembre 2022
//ESCOM-IPN
//Medicion de tiempo del algoritmo de ordenamiento por Burbuja Simple
//Compilacion: "gcc BurbujaSimple.c tiempo.c  -o ordenamientos"
//Ejecucion: "./ordenamientos n <numeros10millones.txt  >>Resultados.txt" (Linux y MAC OS)
//*****************************************************************


//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//*****************************************************************
//DECLARACION DE ESTRUCTURAS
//*****************************************************************

//*****************************************************************
//DECLARACION DE FUNCIONES
//*****************************************************************
void BurbujaSimple(int *,int);

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main(int argc, char const*argv[]){
	//******************************************************************	
	//						Variables del main
	//******************************************************************
	int *A; //Puntero que se usará para crear el arreglo dinámico
	int n; //Determina la longitud del arreglo
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	
	//******************************************************************	
	//			Recepcion y decodificacion de los argumentos
	//******************************************************************
	//Si no se introducen exactamente 2 argumentos, termina con la ejecución
	if (argc!=2){
		exit(1);
	} 
	//Tomar el segundo argumento como tamano del algoritmo
	else{
		n=atoi(argv[1]);
	}
	
	//******************************************************************	
	//			Creación y asignación del arreglo dinámico
	//******************************************************************
	//Asignación de memoria dinámica
	A=malloc(n*sizeof(int));
	//Lee los números mandados como argumento y los almacena en el arreglo
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	// Imprimimos el algoritmo que se estÃ¡ procesando asÃ­ como los datos
	printf("BURBUJA SIMPLE con %d datos", n);
	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	
	//******************************************************************	
	//							Algoritmo
	//******************************************************************
	BurbujaSimple(A,n);
	
	//******************************************************************	
	//					Evaluar los tiempos de ejecucion 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	//******************************************************************	
	//				Impresion de resultados de medición
	//******************************************************************
	imprimirTiempos(utime0, stime0, wtime0,utime1, stime1, wtime1);
	
	//******************************************************************	
	//				Liberar espacio en memoria
	//******************************************************************
	free(A);
	
	return 0;
}

//************************************************************************
//DEFINICION DE FUNCIONES 
//************************************************************************

//Funcion del algoritmo de ordenamiento por burbuja simple
void BurbujaSimple(int *A,int n){
	//******************************************************************	
	//						Variables del algoritmo
	//******************************************************************
	int i,j; //Variables para hacer las iteraciones necesarias
	int aux; //Variable auxiliar para guardar temporalmente el contenido de un índice del arreglo
	
	//******************************************************************	
	//						Ordenamiento
	//******************************************************************
	for(i=0;i<=n-2;i++){
		for(j=0;j<=n-2;j++){
			if(A[j]>A[j+1]){
				aux=A[j];
				A[j]=A[j+1];
				A[j+1]=aux;
			}
		}
	}
}

