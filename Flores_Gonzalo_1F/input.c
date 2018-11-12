#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

int menuInformes(){
    int opcion;
    printf ("*******Menu Informes******\n");
    printf ("\n1- Ingrese uno para imprimir el promedio y total de juegos alquilados");
    printf ("\n2- Ingrese dos para imprimir la cantidad de juegos que no superan el importe del promedio del punto A");
    printf ("\n3- Ingrese tres para imprimir todos los clientes que alquilaron un juego determinado");
    printf ("\n4- Ingrese cuatro para imprimir todos los juegos que fueron alquilados por un cliente determinado");
    printf ("\n5- Ingrese cinco para imprimir los juegos menos alquilados");
    printf ("\n6- Ingrese seis para imprimir los clientes que realizaron mas alquileres");
    printf ("\n7- Ingrese siete para imprimir todos los juegos alquilados en una fecha determinada");
    printf ("\n8- Ingrese ocho para imprimir todos los clientes que realizaron al menos un alquiler en una fecha determinada");
    printf ("\n9- Ingrese nueve para imprimir todos los juegos ordenados por importe (Burbujeo)");
    printf ("\n10- Ingrese dies para imprimir todos los clientes ordenados por apellido(Incersion)");
    printf ("\n11- Ingrese once para salir al menu principal");
    printf ("\nOpcion elegida: ");
    getInt(&opcion);
    return opcion;
}

int menuPrincipal(){
    int opcion;
    printf ("*******Menu Inicial******\n");
    printf ("\n1- Ingrese uno para acceder al menu de juegos");
    printf ("\n2- Ingrese dos para acceder al menu de clientes");
    printf ("\n3- Ingrese tres para dar de alta un alquiler");
    printf ("\n4- Ingrese cuatro para acceder al menu de informes");
    printf ("\n5- Para salir del programa");
    printf ("\n\nIngrese el numero: ");
    getInt(&opcion);
    return opcion;
}

/**************ENTRADA DE DATOS*****************/

void getInt(int* puntero){
    int numero;
    scanf("%d",&numero);
    *puntero = numero;
}

void getFloat(float* puntero){
    float numero;
    scanf ("%f",&numero);
    *puntero = numero;
}

void getChar(char* mensaje){
    char letra;
    fflush(stdin);
    scanf("%c",&letra);
    *mensaje = letra;

}

int getString(char* input){
scanf("%s",input);
return 0;
}

/**************VALIDACION DE DATOS*****************/

int esNumerico(char str[]){
    int i=0;
    while(str[i] != '\0' ){
        if(str[i]<'0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[]){
    int i=0;
    while(str[i] != '\0'){
        if ((str[i] != ' ') &&
            (str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z')){
            return 0;}
        i++;
    }
    return 1;
}

int esAlfaNumerico(char str[]){
    int i=0;
     while(str[i] != '\0'){
        if ((str[i] != ' ') &&
            (str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < '0' || str[i] > '9'))
        return 0;
    }
    return 1;
}

int esTelefono(char str[]){
    int i = 0;
    int contadorGuiones = 0;
    while (str[i] != '\0'){
        if ((str[i] != ' ') && (str[i] != '-') &&
            (str[i] < '0' || str[i] > '9')){
            return 0;}
        if (str[i] == '-'){
            contadorGuiones++;
        }
        i++;
    }
    if (contadorGuiones==1){
        return 1;
    }
    return 0;
}

int getSringLetras(char input[]){
    char aux[256];
    getString(aux);
    if (esSoloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
