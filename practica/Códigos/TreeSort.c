//*****************************************************************
//Equipo: Los zetas, conformado por:
// 1. Arcos Salazar Julio César
// 2. Díaz Hernández Emilio
// 3. González Manzano Leonardo
// 4. Brandón
//Curso: Analisis de algoritmos
//Septiembre 2022
//ESCOM-IPN
//Medicion de tiempo del algoritmo de ordenamiento por arbol binario de busqueda
//Compilacion: "gcc TreeSort.c tiempo.c  -o ordenamientos"
//Ejecucion: "./ordenamientos n <numeros10millones.txt >>resultados,txt" (Linux y MAC OS)
//*****************************************************************


//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//*****************************************************************
//DECLARACION DE ESTRUCTURAS
//*****************************************************************
struct arbol
{
    int numero; //Dato 
    struct arbol *nodo_izq; //Hijo izquierdo
    struct arbol *nodo_der; //Hijo Derecho
};

//*****************************************************************
//DECLARACION DE FUNCIONES
//*****************************************************************
struct arbol *insertarNumeros(struct arbol *a, int num);
struct arbol *crearArbol(struct arbol *a);
void InOrden(struct arbol *a, int *arreglo);
void imprimirTiempos(double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1);

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int posicion = 0; //Variable Global para ir almacenando en el arreglo los numeros ordenados

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main(int narg, char **varg)
{
	//******************************************************************	
	//						Variables del main
	//******************************************************************
    int n, *numeros;
    double utime0,stime0,wtime0,utime1,stime1,wtime1;  
    
    //Crear el arbol binario
    struct arbol *a;
    a = crearArbol(a);

	//******************************************************************	
	//			Recepcion y decodificacion de los argumentos
	//******************************************************************
	//Si no se introducen exactamente 2 argumentos, termina con la ejecución
    if (narg != 2)
    {
        exit(1);
    }
    //Tomar el segundo argumento como tamanio del algoritmo
    n = atoi(varg[1]);

	//******************************************************************	
	//			Creación y asignación del arreglo dinámico
	//******************************************************************
	//Asignación de memoria dinámica
    numeros = malloc(sizeof(int) * (n));
    if (numeros == NULL)
    {
        exit(1);
    }

    //Lee los números mandados como argumento y los almacena en el arreglo
    for (int i = 0; i < n; i++)
        scanf("%d", &numeros[i]);
        
        // Imprimimos el algoritmo que se está procesando así como los datos
	printf("TREESORT con %d datos", n);

	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);

	//******************************************************************	
	//							Algoritmo
	//******************************************************************
    for (int j = 0; j < n; j++)
        a = insertarNumeros(a, numeros[j]);

    InOrden(a, numeros);
    
	//******************************************************************	
	//					Evaluar los tiempos de ejecucion 
	//******************************************************************
    uswtime(&utime1, &stime1, &wtime1);
    //******************************************************************	
	//				Impresion de resultados de medición
	//******************************************************************
	imprimirTiempos(utime0, stime0, wtime0,utime1, stime1, wtime1);
	
	// Limpiamos la memoria
	free(numeros);

	exit (0);
}

//************************************************************************
//DEFINICION DE FUNCIONES 
//************************************************************************


//Funcion que recibe una estructura arbol y el numero entero a insertar en el arbol ABB
struct arbol *insertarNumeros(struct arbol *a, int num)
{
    if (a == NULL)
    {
        struct arbol *aux = NULL;
        aux = (struct arbol *)malloc(sizeof(struct arbol));
        aux->nodo_izq = NULL;
        aux->nodo_der = NULL;
        aux->numero = num;

        return aux;
    }

    if (num < (a->numero))
        a->nodo_izq = insertarNumeros(a->nodo_izq, num);
    else
        a->nodo_der = insertarNumeros(a->nodo_der, num);

    return a;
}


//Funcion que recibe una estructura arbol y regresa un estructura arbol iniciada en nulo
struct arbol *crearArbol(struct arbol *a)
{
    a = NULL;
    return a;
}



//Funcion que recibe una estructura de arbolo binario y el arreglo de enteros donde se van almacenar los numeros ordenados
void InOrden(struct arbol *a, int *arreglo)
{
    if (a != NULL)
    {
        InOrden(a->nodo_izq, arreglo);
        *(arreglo + posicion) = a->numero;
        posicion++;
        InOrden(a->nodo_der, arreglo);
    }
}


