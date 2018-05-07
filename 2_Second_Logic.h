/**********************************************************************
    Instituto Tecnológico de Costa Rica
    Estructuras de Datos IC-2001
    I Semestre 2018
    Profesora: Samanta Ramijan Carmiol
    Carnet: 
    	   2017120035
	Alumno: 
		Bryan Pérez Rojas
	Proyecto: Algoritmo de Huffman
**********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int exist_file(char *direccion);
void read_File (char *filePath);



int caracter[256];
char cadena[512];
// Funcion que calcula la frecuencia de cada caracter en el archivo, recibira la ubicacion del archivo
void calculate_Frecuency(char *filePath){
   int i, caracteres_dif = 0;
   fflush(stdout);

   FILE *fptr;

   //Abre el archivo e ingresa todos los caracteres contenidos en el txt en una cadena
   fptr = fopen(filePath, "r");
   fscanf(fptr,"%[^EOF]", cadena);

   //En este for lo que hara es incrementar las apariciones de los caracteres, y claramente
   //ingresar las letras que no estan aun
   for (i = 0; cadena[i] != '\0'; i++)
      caracter[(unsigned char) cadena[i]]++;

   //En este otro for lo que hace es contabilizar la cantidad de los distintos caracteres que aparecieron
   for (i = 0; i < 256; i++)
      if (caracter[i] > 0)
         caracteres_dif++;

   //Aqui mostrara esta informacion que se acaba de obtener acerca de las apariciones, caracteres y frecuencias
   printf ("Hay %d caracteres diferentes.\n", caracteres_dif);
   printf ("Son:\n\n");
   for (i = 0 ; i < 256; i++)
      if (caracter[i] > 0){
         printf ("caracter[%c] = %d\n", i, caracter[i]);
      }

   printf ("\n\n");
   //Cierra el archivo
   fclose(fptr);

   getchar();
   getchar();
}


//Esta funcion lo que hace es verificar que el archivo que se indica
// realmente exista en la ubicacion que se indico y retornara un 1 
// en caso de que no exista y un 0 en caso contrario.
int exist_file(char *direccion){
		FILE *origen;
		char ruta[1024]="";
		strcpy(ruta,direccion);
		origen = fopen(ruta,"r");
		if (origen==NULL){
			fclose(origen);
			return 1;
		}
		else
		{
			fclose(origen);
			return 0;
		}
}
//La siguiente funcion es para la lectura de los archivos en la cual se lee
// el archivo completamente y se imprime todo el contenido de este, ademas llamada a la
// funcion de calcular frecuencia
void read_File (char *filePath){
	FILE *info;
	int letter;
	//A continuacion abre el archivo txt
	info = fopen(filePath, "rt");
	//Aqui empezara a imprimir el texto del archivo
	printf("El texto en el archivo elegido es: \n");
	while ((letter = fgetc (info))!=EOF){
		if (letter == '\n'){
			printf("\n");
		}
		else{
			putchar (letter);
		}
	}printf("\n");
	// llamada a la siguiente funcion
	calculate_Frecuency(filePath);
}
