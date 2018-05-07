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
#include "2_Second_Logic.h"

//A continuacion estan las distintas funciones que existen en este archivo .h
//Se implemento en 2 archivos .h para tener mas orden y evitar el excesi de codigo en 1 solo archivo
void menu();
void showAbout();
void insertTxt();
void showHelp();

void menu (){
	int option = 0;
		while(option!=5){
			system ("clear");
		    printf("--------------------------------------------------------------------\n");
		    printf("|                                                                  |\n");
		    printf("|                         MENU PRINCIPAL                           |\n");
		    printf("--------------------------------------------------------------------\n");
		    printf("|               1. Huffmanize                                      |\n");
		    printf("|               2. De - Huffmanize                                 |\n");
		    printf("|               3. About                                           |\n");
		    printf("|               4. Help                                            |\n");
		    printf("--------------------------------------------------------------------\n");
		    printf("|               5. Exit                                            |\n");
		    printf("--------------------------------------------------------------------\n");
		   	printf("Select the option: ");
		    scanf("%i",&option);
		    if (option==1){
				insertTxt ();
			} else if(option==2) {
				printf ("El proceso de descompresion no se puede realizar\n");
				getchar();
   				getchar();
			} else if(option==3) {
				showAbout();
			} else if(option==4) {
				showHelp();
				printf("Option 4");
			}
		}	
}
/*
En la siguiente funcion lo que se hara es solicitar al usuario
la ubicacion donde se encuentra el archivo txt que se desea comprimir y 
ademas imprime la ruta que fue escrita por el usuario
En caso de que no se encuentre este archivo txt, el programa procedera a indicarlo
*/
void insertTxt(){
	char newFile [60];
	printf ("\nPor favor ingrese la ruta del archivo: \n");
	scanf ("%s", newFile);
	//A continuacion imprime la ruta que se eligio
	printf ("La ruta que eligio es: %s\n", newFile);
	/*En el siguiente if lo que hara es llamar a la funcion que comprueba si este archivo existe
	  En caso de que no exista mostrara un mensaje, caso contrario enseñara un mensaje y ademas
	  Llamara a la funcion de leer el archivo, que se encuentra en el otro archivo .h
	*/
	if (exist_file(newFile)!=0){
		printf("\nEl archivo indicado no existe en la ruta indicada...\n");
	}
	else{
		printf("\n¡Archivo encontrado!\n\n");
		read_File (newFile);
	}

}



/*
La siguiente funcion lo que hara es simplemente desplegar informacion
acerca de del programa, institucion, curso, objetivo, lenguaje y nombre y carne del estudiante
que lo desarrollo
*/
void showAbout (){
	system ("clear");
	    printf ("\n\t\t*****************************************************************\n");
	    printf ("\t\t*\t\tooooooooooooo oooooooooooo   .oooooo.   \t*\n");
	    printf ("\t\t*\t\t8'   888   `8 `888'     `8  d8P'  `Y8b  \t*\n");
	    printf ("\t\t*\t\t     888       888         888          \t*\n");
	    printf ("\t\t*\t\t     888       888oooo8    888          \t*\n");
	    printf ("\t\t*\t\t     888       888    ""     888        \t\t*\n");
	    printf ("\t\t*\t\t     888       888       o `88b    ooo  \t*\n");
	    printf ("\t\t*\t\t    o888o     o888ooooood8  `Y8bood8P'  \t*\n");
	    printf ("\t\t*****************************************************************\n");
	    printf ("\t\t*****************************************************************\n");
	    printf ("\t\t*Objetivo:\t\t\t\t\t\t\t*\n");
	    printf ("\t\t*\tHuffman Compressor\t\t\t\t\t*\n");
	    printf ("\t\t*Lenguaje utilizado:\t\t\t\t\t\t*\n");
	    printf ("\t\t*\t\t C \t\t\t\t\t\t*\n");
	    printf ("\t\t*Curso:\t\t\t\t\t\t\t\t*\n");
	    printf ("\t\t*\tEstructuras de Datos\t\t\t\t\t*\n");
	    printf ("\t\t*Desarrollador: \t\t\t\t\t\t*\n");
	    printf ("\t\t*\t Bryan Perez Rojas - 2017120035\t\t\t\t*\n");
	    printf ("\t\t*****************************************************************\n\n");
	    getchar();
   		getchar();
}



/*
La siguiente funcion lo que hara es mostrar los comandos disponibles para el programa, estos comandos
no se pueden utilizar tal cual, ya que para eso se diseño un menu especial en el cual se puede
navegar por medio de los numeros que son respectivos a cada opcion
*/
void showHelp (){
	system ("clear");
	printf ("\n\t*************************************************************************\n");
	    printf ("\t*\t\t\tLos comandos disponibles son \t\t\t*\n");
	    printf ("\t*1. Huffmanize\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*\tGenera un archivo con extensión .huff\t\t\t\t*\n");
	    printf ("\t*Parametros: \t\t\t\t\t\t\t\t*\n");
	    printf ("\t*\t1. file_path\t\t\t\t\t\t\t*\n");
	    printf ("\t*\t\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*2. De-Huffmanize\t\t\t\t\t\t\t*\n");
	    printf ("\t*\tGenera un archivo con extension .txt y posee la descoficacion\t*\n");
	    printf ("\t*Parametros: \t\t\t\t\t\t\t\t*\n");
	    printf ("\t*\t1. file_path\t\t\t\t\t\t\t*\n");
	    printf ("\t*\t\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*3. help\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*\tDespliega los comandos que pueden ser utilizados en el programa\t*\n");
	    printf ("\t*\t\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*4. about\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*\tDespliega informacion relevante sobre el programa \t\t*\n");
	    printf ("\t*************************************************************************\n\n");
	    getchar();
   		getchar();
}