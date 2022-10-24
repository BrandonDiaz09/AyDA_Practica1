//*****************************************************************
//Equipo: Los zetas, conformado por:
// 1. Arcos Salazar Julio Cesar
// 2. Diaz Hernandez Emilio
// 3. Gonzalez Manzano Leonardo
// 4. Brandon
//Curso: Analisis de algoritmos
//Septiembre 2022
//ESCOM-IPN
//Medicion de tiempo del algoritmo de ordenamiento por Shell
//Compilacion: "gcc Shell.c tiempo.c  -o ordenamientos"
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
void Shell(int *A,int n);

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
	int *A; //Puntero que se usar� para crear el arreglo din�mico
	int n; //Determina la longitud del arreglo
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	
	//******************************************************************	
	//			Recepcion y decodificacion de los argumentos
	//******************************************************************
	//Si no se introducen exactamente 2 argumentos, termina con la ejecuci�n
	if (argc!=2){
		exit(1);
	} 
	//Tomar el segundo argumento como tamano del algoritmo
	else{
		n=atoi(argv[1]);
	}
	
	//******************************************************************	
	//			Creaci�n y asignaci�n del arreglo din�mico
	//******************************************************************
	//Asignaci�n de memoria din�mica
	A=malloc(n*sizeof(int));
	//Lee los n�meros mandados como argumento y los almacena en el arreglo
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	// Imprimimos el algoritmo que se está procesando así como los datos
	printf("SHELL con %d datos", n);
	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	
	//******************************************************************	
	//							Algoritmo
	//******************************************************************
	Shell(A,n);
	
	//******************************************************************	
	//					Evaluar los tiempos de ejecucion 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	//******************************************************************	
	//				Impresion de resultados de medici�n
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

//Funcion del algoritmo de ordenamiento por burbuja optimizada 1
void Shell(int *A,int n){
	//******************************************************************	
	//						Variables del algoritmo
	//******************************************************************
	int i,j,k; //Variables para hacer las iteraciones necesarias
	int temp; //Variable auxiliar para guardar temporalmente el contenido de un �ndice del arreglo
	
	//******************************************************************	
	//						Ordenamiento
	//******************************************************************
	k=n/2;
	while(k>=1){
		j=1;
		while(j!=0){
			j=0;
			for(i=k;i<=n-1;i++){
				if(A[i-k]>A[i]){
					temp=A[i];
					A[i]=A[i-k];
					A[i-k]=temp;
					j=j+1;
				}
			}
		}
		k=k/2;
	}
}

