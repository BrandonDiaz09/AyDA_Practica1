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
int partition (int a[], int start, int end);
void quick(int a[], int start, int end);

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
	
	// Imprimimos el algoritmo que se está procesando así como los datos
	printf("QUICKSORT con %d datos", n);
	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	
	//******************************************************************	
	//							Algoritmo
	//******************************************************************
	
	quick(A, 0, n - 1);
	
	//******************************************************************	
	//					Evaluar los tiempos de ejecucion 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	//******************************************************************	
	//				Impresion de resultados de medición
	//******************************************************************
	imprimirTiempos(utime0, stime0, wtime0,utime1, stime1, wtime1);
	
	// Liberamos la memoria utilizada
	free(A);
	
	return 0;
}

//************************************************************************
//DEFINICION DE FUNCIONES 
//************************************************************************

//Funcion del algoritmo de ordenamiento quicksort

    /* function that consider last element as pivot,  
    place the pivot at its exact position, and place  
    smaller elements to left of pivot and greater  
    elements to right of pivot.  */  
    
int partition (int a[], int start, int end){  
        int pivot = a[end]; // pivot element  
        int i = (start - 1);  
      
        for (int j = start; j <= end - 1; j++)  
        {  
            // If current element is smaller than the pivot  
            if (a[j] < pivot)  
            {  
                i++; // increment index of smaller element  
                int t = a[i];  
                a[i] = a[j];  
                a[j] = t;  
            }  
        }  
        int t = a[i+1];  
        a[i+1] = a[end];  
        a[end] = t;  
        return (i + 1);  
    }  
      
/* function to implement quick sort */  
void quick(int a[], int start, int end){ /* a[] = array to be sorted, start = Starting index, end = Ending index */  
    
        if (start < end)  
        {  
            int p = partition(a, start, end); //p is the partitioning index  
            quick(a, start, p - 1);  
            quick(a, p + 1, end);  
        }  
    }  
      
    
