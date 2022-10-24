# !/bin/bash
# Autor: 
# Script para automatizar pruebas de tiempo

#Creamos un arreglo con las pruebas a realizar
PRUEBAS=(1000 2000 3000 4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 800000 900000 1000000 1500000 2000000)
#PRUEBAS=(1000 2000 3000 4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 800000 900000 1000000 1500000 2000000)#


#Cambiamos a la carpeta donde se encuentran los códigos
#En caso de que no esté, crear una carpeta llamada "Códigos" y meter los códigos
cd Códigos

#Extraemos todos los archivos
ALL_FILES=$(ls)

#Hacemos un ciclo for para recorrer cada elemento
for ITEM in $ALL_FILES; do
FILE=$ITEM

#Filtramos los archivos, ya que podemos tener .h o.c pero necesitamos los .c y no debe ser tampoco tiempo.c
if [[ $FILE == *.c && $FILE != tiempo.c ]]; then

	#Comenzamos a generar las pruebas con los datos
	gcc $FILE tiempo.c -o ordenamientos
	
	#Recorremos el arreglo de las pruebas
	for PRUEBA in ${PRUEBAS[*]}; do
	./ordenamientos $PRUEBA < numeros10millones.txt >> Resultados.txt
	 sudo sync && sudo sysctl -w vm.drop_caches=3 #Limpiamos la memoria caché
	
	done
fi

done





