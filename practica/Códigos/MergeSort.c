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

void merge(int *array, int p, int q, int r);
void merge_sort(int *array, int p, int r);

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
	printf("MERGESORT con %d datos", n);
	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	
	//******************************************************************	
	//							Algoritmo
	//******************************************************************
	
	merge_sort(A, 0, n-1);
	
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

void merge(int *array, int p, int q, int r){

    // Declaracion de variables
    int i, j, k;
    int n_1 = (q - p) + 1;
    int n_2 = (r - q);
    int *L, *R;

    // Asignacion de memoria
    L = (int*)malloc(n_1 * sizeof(int));
    R = (int*)malloc(n_2 * sizeof(int));

    // Copia de datos del arreglo A en los subarreglos L y R
    for (i = 0; i < n_1; i++)
    {
        L[i] = *(array + p + i);
    }

    for (j = 0; j < n_2; j++)
    {
        R[j] = *(array + q + j + 1);
    }

    i = 0;
    j = 0;

    // Fusión de datos respetando el valor minimos entre dos arreglos
    for (k = p; k < r + 1; k++){
    
        if (i == n_1){
        
            *(array + k) = *(R + j);
            j =  j+ 1;
        }
        
        else if(j == n_2){
        
            *(array + k) = *(L + i);
            i = i + 1;
        
        }else{
        
            if (*(L + i) <= *(R + j)){
            
                *(array + k) = *(L + i);
                i = i + 1;
            
            }else{
            
                *(array + k) = *(R + j);
                j = j + 1;
            }
        }
    }
}

void merge_sort(int *array, int p, int r){
    
    if (p < r){
    
        // Dividir el problema en subproblemas
        int q = (p + r)/2;
        
        // Resolver el problema de manera recursiva hasta llegar a una solucion trivial
        merge_sort(array, p, q);
        merge_sort(array, q + 1, r);
        
        // Fusion de resultados parciales
        merge(array, p, q, r);
    }
}

