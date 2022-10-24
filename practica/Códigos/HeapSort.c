//*****************************************************************
//Equipo: Los zetas, conformado por:
// 1. Arcos Salazar Julio C�sar
// 2. D�az Hern�ndez Emilio
// 3. Gonz�lez Manzano Leonardo
// 4. Brand�n
//Curso: Analisis de algoritmos
//Septiembre 2022
//ESCOM-IPN
//Medicion de tiempo del algoritmo de Heap sort
//Compilacion: "gcc HeapSort.c tiempo.c -o ordenamientos"
//Ejecucion: "./ordenamientos n <numeros10millones.txt >>resultados,txt" (Linux y MAC OS)
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

void swap(int *a, int *b);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

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
					
	int *A; 			//Puntero que se usar� para crear el arreglo din�mico
	int n; 				//Determina la longitud del arreglo
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
	
	// Imprimimos el algoritmo que se est� procesando as� como los datos
	printf("HEAPSORT con %d datos", n);
	
		
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	
	//******************************************************************	
	//							Algoritmo
	//******************************************************************	
	heapSort(A, n);
		
	//******************************************************************	
	//					Evaluar los tiempos de ejecucion 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
		
	//******************************************************************	
	//				Impresion de resultados de medici�n
	//******************************************************************
	imprimirTiempos(utime0, stime0, wtime0,utime1, stime1, wtime1);
	
	// Limpiamos la memoria
	free(A);
	
    return 0;
}

//************************************************************************
//DEFINICION DE FUNCIONES 
//************************************************************************
//Funcion del algoritmo de ordenamiento por HeapSort

// Function to swap the the position of two elements
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  // Main function to do heap sort
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }




