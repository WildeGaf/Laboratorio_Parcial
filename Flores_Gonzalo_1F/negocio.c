#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "negocio.h"


int MenuJuegos(){
    int opcionElegida;
    printf ("*******Menu Juegos******\n");
    printf ("\n1- Ingrese uno para dar de alta un juego");
    printf ("\n2- Ingrese dos para modificar los datos de un juego");
    printf ("\n3- Ingrese tres para dar de baja un juego");
    printf ("\n4- Ingrese cuatro para Imprimir de forma ordenada");
    printf ("\n\nIngrese el numero: ");
    getInt(&opcionElegida);
    return opcionElegida;
}

void inicializarJuego(eJuegos* lista,int len){
    int i;
    for (i=0;i<len;i++){
        lista[i].isEmpty = 0;
    }
}

int primerEspacioligre(eJuegos* lista, int len){
int i,retorno;
retorno = -1;
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 0){
            retorno = i;
            break;
        }
    }
return retorno;
}

int findJuego(eJuegos* lista, int len,int codigo){
    int retorno = -1;
    int i;
    for (i=0;i<len;i++){
        if(lista[i].codigoJuego == codigo){
            retorno = i;
            break;
        }
    }
return retorno;
}

int addJuego(eJuegos* lista, int len,int* altaBanderaJuego){
    int r,retorno = -1;
    int importeJuego,validar;
    char descripcion[51];
    r = primerEspacioligre(lista,len);
    if (r != -1){
        do{
        printf("Ingrese la descripcion: ");
        getString(descripcion);
        validar = strlen(descripcion);
        }while(validar>51 || validar <0);
        do{
            printf("Ingrese el importe del juego: ");
            getInt(&importeJuego);
        }while(importeJuego<0);
        strcpy(lista[r].descripcion,descripcion);
        lista[r].importe = importeJuego;
        lista[r].isEmpty = 1;
        lista[r].codigoJuego = r;
        retorno = 0;
        *altaBanderaJuego = 1;
    }
    else{
        printf("No hay espacio disponible");
    }
    return retorno;
}

void modificarJuego(eJuegos* lista,int len){
    int auxCodigoJuego,validar,auxImporteJuego,validarJuego,opcionElegida;
    char auxDescripcion[51];
    printf("Ingrese el codigo del libro que desea modificar del registro");
    getInt(&auxCodigoJuego);
    validarJuego = findJuego(lista,len,auxCodigoJuego);
    if (validarJuego == -1){
        printf("No se ha encontrado el codigo ingresado");
    }
    else {
        printf("1-Modificar descripcion");
        printf("\n2-Modificar importe");
        printf ("\n\nIngrese el numero: ");
        getInt(&opcionElegida);
        switch (opcionElegida){
            case 1:
                do{
                printf("Ingrese la nueva descripcion");
                getString(auxDescripcion);
                validar = strlen(auxDescripcion);
                }while(validar>51 || validar <0);
            break;
            case 2:
            do{
            printf("Ingrese el nuevo importe");
            getInt(&auxImporteJuego);
            }while(auxImporteJuego<0);
            lista[validarJuego].importe = auxImporteJuego;
            break;
            default:
            printf("Error al seleccion una opcion");
            break;
        }

    }
}

void ordenarJuegos(eJuegos* lista, int len){
 eJuegos AuxLista;
 int i,j;
        for (i=0;i<len;i++){
            if (lista[i].isEmpty == 1){
                for(j=i+1;j<len;j++){
                   if (lista[j].isEmpty == 1){
                        if(lista[i].importe > lista[j].importe)
                        {
                            AuxLista = lista[i];
                            lista[i] = lista[j];
                            lista[j] = AuxLista;
                        }
                        else{
                            if(lista[i].importe == lista[j].importe){
                                if(strcmp(lista[i].descripcion,lista[j].descripcion)>1) {
                                    AuxLista = lista[i];
                                    lista[i] = lista[j];
                                    lista[j] = AuxLista;
                                }
                            }
                        }
                    }
                }
            }
        }
}

void BajaJuego(eJuegos* lista, int len){
    int juegoIdEncontrado;
    int auxCodigoJuego;
    printf("Ingrese el codigo del libro que desea eliminar del registro");
    getInt(&auxCodigoJuego);
    juegoIdEncontrado = findJuego(lista,len,auxCodigoJuego);
    if (juegoIdEncontrado == -1){
        printf("Ese codigo no se encuentra en el registro");
    }
    else{
    lista[juegoIdEncontrado].isEmpty = 0;
    }
}

void imprimirListaJuegos(eJuegos* lista,int len){
    int i;
    ordenarJuegos(lista,len);
    for (i=0;i<len;i++){
        //if (lista[i].isEmpty == 1){
            printf ("\n La descripcion es: %s",lista[i].descripcion);
            printf ("\n El importe es: %d",lista[i].importe);
            printf ("\n El codigo es: %d\n\n",lista[i].codigoJuego);
        //}
    }
}

/***************************************************************************/


int menuClientes(){
    int opcionElegida;
    printf ("*******Menu Clientes******\n");
    printf ("\n1- Ingrese uno para dar de alta un cliente");
    printf ("\n2- Ingrese dos para modificar los datos de un cliente");
    printf ("\n3- Ingrese tres para dar de baja un cliente");
    printf ("\n4- Ingrese cuatro para listar los clientes");
    printf ("\n\nIngrese el numero: ");
    getInt(&opcionElegida);
    return opcionElegida;
}

void inicializarCliente(eCliente* lista,int len){
    int i;
    for (i=0;i<len;i++){
        lista[i].isEmpty = 0;
    }
}

int primerEspacioCliente(eCliente* lista, int len){
int i,retorno;
retorno = -1;
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 0){
            retorno = i;
            break;
        }
    }
return retorno;
}

void addCliente(eCliente* lista, int len,int *altaBanderaCliente){
    int r,cantidad;
    char auxNombre[51], auxApellido[51],auxDomicilio[51];
    char auxTelefono[51];
    r = primerEspacioCliente(lista,len);
    if (r != -1){
        do{
            printf("Ingrese el apellido del cliente");
            getSringLetras(auxApellido);
            cantidad = strlen(auxApellido);
        }while(cantidad>51 || cantidad<0);
        do{
            printf("Ingrese el nombre del cliente");
            getSringLetras(auxNombre);
            cantidad = strlen(auxNombre);
        }while(cantidad>51 || cantidad<0);
        do{
            printf("Ingrese el domicilio del cliente");
            getString(auxDomicilio);
            cantidad = strlen(auxDomicilio);
        }while(cantidad>51 || cantidad<0);
        do{
            printf("Ingrese el telefono del cliente");
            getString(auxTelefono);
            cantidad = strlen(auxTelefono);
        }while(cantidad>21 || cantidad<0);
        strcpy(lista[r].apellido,auxApellido);
        strcpy(lista[r].nombre,auxNombre);
        strcpy(lista[r].domicilio,auxDomicilio);
        strcpy(lista[r].telefono,auxTelefono);
        lista[r].codigoCliente = r;
        lista[r].isEmpty = 1;
        *altaBanderaCliente = 1;
    }else{
    printf("No hay espacio disponble");
    }
}

int findCliente(eCliente* lista, int len,int codigo){
    int retorno = -1;
    int i;
    for (i=0;i<len;i++){
        if(lista[i].codigoCliente == codigo){
            retorno = i;
            break;
        }
    }
return retorno;
}

void modificarCliente(eCliente* lista,int len){
    int auxCodigoCliente,respuesta,clienteEncontrado;
    int cantidad;
    char auxNombreCliente[51], auxApellidoCliente[51];
    char auxDomicilioCliente[51], auxTelefonoCliente[51];

    printf("Ingrese el codigo del cliente que desea modificar");
    getInt(&auxCodigoCliente);
    clienteEncontrado = findCliente(lista,len,auxCodigoCliente);
    if (clienteEncontrado != -1){
        printf("Submenu modificacion de registro del cliente");
        printf("\n1- ingrese 1 para modificar el apellido");
        printf("\n2- ingrese 2 para modificar el nombre");
        printf("\n3- ingrese 3 para modificar el domiciolio");
        printf("\n4- ingrese 4 para modificar el telefono");
        printf ("\n\nIngrese el numero: ");
        getInt(&respuesta);
        switch(respuesta){
        case 1:
            do{
                printf("Ingrese el apellido a modificar: ");
                getSringLetras(auxApellidoCliente);
                cantidad = strlen(auxApellidoCliente);
            }while(cantidad>51 || cantidad<0);
            strcpy(lista[clienteEncontrado].apellido,auxApellidoCliente);
        case 2:
            do{
                printf("Ingrese el nombre a modificar: ");
                getSringLetras(auxNombreCliente);
                cantidad = strlen(auxNombreCliente);
            }while(cantidad>51 || cantidad<0);
            strcpy(lista[clienteEncontrado].nombre,auxNombreCliente);
        case 3:
            do{
                printf("Ingrese el domicilio a modificar: ");
                getString(auxDomicilioCliente);
                cantidad = strlen(auxDomicilioCliente);
            }while(cantidad>51 || cantidad<0);
            strcpy(lista[clienteEncontrado].domicilio,auxDomicilioCliente);
        case 4:
            do{
                printf("Ingrese el telefono a modificar: ");
                getString(auxTelefonoCliente);
                cantidad = strlen(auxTelefonoCliente);
            }while(cantidad>51 || cantidad<0);
            strcpy(lista[clienteEncontrado].telefono,auxTelefonoCliente);
        }
    }else{
        printf("No se encuentran los datos de este cliente");
    }
}

void bajaCliente(eCliente* lista,int len){
    int auxCodigo,encontrado;
    printf("Ingrese el codigo del cliente que desea eliminar del registro");
    getInt(&auxCodigo);
    encontrado = findCliente(lista,len,auxCodigo);
    if (encontrado != -1){
        lista[encontrado].isEmpty = 0;
    }else{
    printf("No se encuentra en el registro");
    }
}

void ordenarClientes(eCliente* lista, int len){
 eCliente AuxLista;
 int i,j;
        for (i=0;i<len;i++){
            for(j=i+1;j<len;j++){
                    if(strcmp(lista[i].apellido,lista[j].apellido)>0){
                        AuxLista = lista[i];
                        lista[i] = lista[j];
                        lista[j] = AuxLista;
                    }
                    else{
                        if (strcmp(lista[i].apellido,lista[j].apellido)==0){
                            if(strcmp(lista[i].nombre,lista[j].nombre)>0){
                                AuxLista = lista[i];
                                lista[i] = lista[j];
                                lista[j] = AuxLista;
                            }
                        }
                    }
            }
        }
}

void imprimirListaClientes(eCliente* lista,int len){
    int i;
    ordenarClientes(lista,len);
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 1){
            printf ("\n Apellido del cliente: %s",lista[i].apellido);
            printf ("\n Nombre del cliente: %s",lista[i].nombre);
            printf ("\n Direccion del cliente: %s",lista[i].domicilio);
            printf ("\n Telefono del cliente: %s",lista[i].telefono);
            printf ("\n Codigo del cliente: %d\n\n",lista[i].codigoCliente);
        }
    }
}

/* void ordenarInsercion(eCliente* lista,int len){
int i,j,test;
char aux[51];
for (i=1; i<len; i++);
    j = i - 1;
    test = strcmp(lista[j].apellido,lista[i]Apellido)>0
    while (test > 1){
    lista[j+1]=lista[j];
    j--;
    //lista[j+1] = ;
    }
}
*/

/*********************************************************************************/

void inicializarAlquiler(eAlquiler* lista,int len){
    int i;
    for (i=0;i<len;i++){
        lista[i].isEmpty = 0;
    }
}

int primerEspacioAlquiler(eAlquiler* lista,int len){
    int i,retorno = -1;
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 0){
            retorno = i;
        break;
        }
    }
return retorno;
}

void addAlquiler(eCliente* listaC,int lenC,eJuegos* listaJ,int lenJ,eAlquiler* listaA,int lenA){
    int i,j,bandera = 0;
    int auxCodigoJuego,auxCodigoCliente;
    int auxAnio,auxMes,auxDia;
    for (i=0;i<lenJ;i++){
        if (listaJ[i].isEmpty == 1){
            printf("\nDescripcion: %s",listaJ[i].descripcion);
            printf("\nCodigo Del juego: %d\n\n",listaJ[i].codigoJuego);
        }
    }
    do{
        printf("Ingrese el codigo del juego: ");
        getInt(&auxCodigoJuego);
        for (i=0;i<lenJ;i++){
            if(auxCodigoJuego == listaJ[i].codigoJuego){
                bandera = 1;
            }
        }
    }while(bandera != 1);
    for (i=0;i<lenC;i++){
        if (listaC[i].isEmpty == 1){
            printf("\nNombre: %s",listaC[i].nombre);
            printf("\nApellido: %s",listaC[i].apellido);
            printf("\nCodigo Del cliente: %d\n\n",listaC[i].codigoCliente);
        }
    }
    j = primerEspacioAlquiler(listaA,lenA);
    bandera = 0;
    do{
        printf("Ingrese el codigo del cliente: ");
        getInt(&auxCodigoCliente);
        for (i=0;i<lenC;i++){
            if(auxCodigoCliente == listaC[i].codigoCliente){
                bandera = 1;
            }
        }
    }while(bandera!=1);
    do{
        printf ("\n\nEl anio debe estar entre 2000 y 2500, el mes entre 0 y 12 y los dias entre 0 y 31");
        printf("\nIngrese el anio: ");
        getInt(&auxAnio);
        printf("\nIngrese el mes: ");
        getInt(&auxMes);
        printf("\nIngrese el dia: ");
        getInt(&auxDia);
    }while((auxAnio<2000 || auxAnio >2500) || (auxMes < 0 || auxMes > 12) || (auxDia < 0 || auxDia > 31));
    listaA[j].codigoCliente = auxCodigoCliente;
    listaA[j].codigoJuegos = auxCodigoJuego;
    listaA[j].codigoAlquiler = j;
    listaA[j].fecha.anio = auxAnio;
    listaA[j].fecha.mes = auxMes;
    listaA[j].fecha.dia = auxDia;
    listaA[j].isEmpty = 1;
    imprimirListaAlquileres(listaA,lenA);
}

void imprimirListaAlquileres(eAlquiler* listaA,int lenA){
    int i;
    printf("Lista de alquileres\n\n");
    for (i=0;i<lenA;i++){
        if (listaA[i].isEmpty == 1){
            printf("\nCodigo del cliente: %d",listaA[i].codigoCliente);
            printf("\nCodigo del juego: %d",listaA[i].codigoJuegos);
            printf("\nCodigo del alquiler: %d",listaA[i].codigoAlquiler);
            printf("\nAnio: %d \t mes: %d \t dia: %d\n",listaA[i].fecha.anio,listaA[i].fecha.mes,listaA[i].fecha.dia);
        }
    }
    system("pause");
    system("cls");
}


/*********************************************************************************/

//Punto A y B
void promedioJuegosAlquilados(eJuegos* listaJ,int lenJ,eAlquiler* listaA,int lenA){
    int i,j,promedio,auxCodigo,contador=0,total=0;
    for (i=0;i<lenA;i++){
        if (listaA[i].isEmpty == 1){
            auxCodigo = listaA[i].codigoJuegos;
            for (j=0;j<lenJ;j++){
                if (listaJ[j].isEmpty==1 && listaJ[j].codigoJuego == auxCodigo){
                    total = total + listaJ[j].importe;
                    contador++;
                }
            }
        }
    }
    promedio = total/contador;
    printf("\nEl promedio de los juegos alquilados es de :$ %d",promedio);
    printf("\nEl total de los juegos alquilados es de :$ %d",total);
    printf ("\n\n Los juegos que no superan el promedio son: \n");
    for (i=0;i<lenJ;i++){
        if (listaJ[i].importe < promedio){
            printf("Descripcion: %s",listaJ[i].descripcion);
            printf("Importe: %d",listaJ[i].importe);
        }

    }
}

//punto C
void alquilerJuegoDeterminado(eCliente* listaC,int lenC,eAlquiler* listaA,int lenA,int codigoJ){
    int j,i;
    for (i=0;i<lenA;i++){
        if (listaA[i].isEmpty == 1 && listaA[i].codigoJuegos == codigoJ){
            for (j=0;j<lenC;j++){
                if (listaC[j].isEmpty == 1){
                    if (listaC[j].codigoCliente == listaA[i].codigoCliente){
                    printf("\nApellido: %s",listaC[j].apellido);
                    printf("\nNombre: %s",listaC[j].nombre);
                    printf("\nCodigo: %d\n\n",listaC[j].codigoCliente);
                    }
                }
            }
        }
    }
}

//Punto D
void alquilerClienteDeterminado(eJuegos* listaJ,int lenJ,eAlquiler* listaA,int lenA,int codigoC){
int j,i;
    for (i=0;i<lenA;i++){
        if (listaA[i].isEmpty == 1 && listaA[i].codigoCliente == codigoC){
            for (j=0;j<lenJ;j++){
                if (listaJ[j].isEmpty == 1 && listaJ[j].codigoJuego == listaA[i].codigoJuegos){
                    printf("\nDescripcion: %s",listaJ[j].descripcion);
                    printf("\nImporte: %d",listaJ[j].importe);
                    printf("\nCodigo: %d\n\n",listaJ[j].codigoJuego);
                }
            }
        }
    }
}

//Punto E

void juegoMenosAlquilado(eJuegos* listaJ,int lenJ,eAlquiler* listaA,int lenA){
int i,j,min=0,bandera = 0;
int contador;
char* auxDesc;
    for (i=0;i<lenJ;i++){
            if (listaJ[i].isEmpty == 1){
                contador = 0;
                for(j=0;j<lenA;j++){
                    if (listaA[j].isEmpty == 1){
                        if (listaJ[i].codigoJuego == listaA[j].codigoJuegos){
                            contador++;
                        }
                    }
                }
            if((contador!=0 && contador < min) || (bandera == 0)){
                    min = contador;
                    bandera = 1;
                    strcpy(auxDesc,listaJ[i].descripcion);
            }
            }
    }
printf("\nEl juego menos alquilado es: %s",auxDesc);
}

//Punto F

void clienteMasAlquileres(eCliente* listaC,int lenC,eAlquiler* listaA,int lenA){
int i,j,max=0;
char* auxNombre;
char* auxApellido;
int contador;
int bandera = 0;
    for (i=0;i<lenC;i++){
        if (listaC[i].isEmpty == 1){
                contador = 0;
            for(j=0;j<lenA;j++){
                if (listaA[i].isEmpty == 1){
                    if (listaC[i].codigoCliente == listaA[j].codigoCliente){
                        contador++;
                    }
                }
            }
        if((contador!=0 && contador > max) || (bandera == 0)){
                    max = contador;
                    strcpy(auxApellido,listaC[i].apellido);
                    strcpy(auxNombre,listaC[i].nombre);
        }
        }
    }
printf("\nEl cliente que realizo mas alquileres es: %s %s",auxApellido,auxNombre);
}

//Punto G

void juegoFechaDeterminada(eJuegos* listaJ,int lenJ ,eAlquiler* listaA, int lenA){
    int i,j;
    int bandera = 0;
    int auxAnio,auxMes,auxDia;
    do{
        printf ("\n\nEl anio debe estar entre 2000 y 2500, el mes entre 0 y 12 y los dias entre 0 y 31");
        printf("\nIngrese el anio: ");
        getInt(&auxAnio);
        printf("\nIngrese el mes: ");
        getInt(&auxMes);
        printf("\nIngrese el dia: ");
        getInt(&auxDia);
    }while((auxAnio<2000 && auxAnio >2500) || (auxMes < 0 && auxMes >= 12) || (auxDia < 0 && auxDia >= 31));
    for (i=0;i<lenA;i++){
        if (listaA[i].isEmpty == 1){
            if ((listaA[i].fecha.anio == auxAnio)&&(listaA[i].fecha.mes == auxMes)&&(listaA[i].fecha.dia = auxDia)){
                for (j=0;j<lenJ;j++){
                    if (listaJ[j].isEmpty == 1){
                        if(listaA[i].codigoJuegos == listaJ[j].codigoJuego){
                            printf("\nDescripcion: %s",listaJ[j].descripcion);
                            printf("\nImporte: %d",listaJ[j].importe);
                            printf("\nCodigo: %d",listaJ[j].codigoJuego);
                            bandera = 1;
                        }
                    }
                }
            }
        }
    }
if (bandera == 0){
    printf("Juego no encontrado");
}
}

//Punto H

void clienteFechaDeterminada(eCliente* listaC,int lenC ,eAlquiler* listaA, int lenA){
    int i,j;
    int bandera = 0;
    int auxAnio,auxMes,auxDia;
    do{
        printf ("\n\nEl anio debe estar entre 2000 y 2500, el mes entre 0 y 12 y los dias entre 0 y 31");
        printf("\nIngrese el anio: ");
        getInt(&auxAnio);
        printf("\nIngrese el mes: ");
        getInt(&auxMes);
        printf("\nIngrese el dia: ");
        getInt(&auxDia);
    }while((auxAnio<2000 && auxAnio >2500) || (auxMes < 0 && auxMes >= 12) || (auxDia < 0 && auxDia >= 31));
    for (i=0;i<lenA;i++){
        if (listaA[i].isEmpty == 1){
            if ((listaA[i].fecha.anio == auxAnio)&&(listaA[i].fecha.mes == auxMes)&&(listaA[i].fecha.dia = auxDia)){
                for (j=0;j<lenC;j++){
                    if (listaC[j].isEmpty == 1){
                        if(listaA[i].codigoCliente == listaC[j].codigoCliente){
                            printf("\nApellido: %s",listaC[j].apellido);
                            printf("\nNombre: %s",listaC[j].nombre);
                            printf("\nDomicilio: %s",listaC[j].domicilio);
                            printf("\nTelefono: %s",listaC[j].telefono);
                            bandera = 1;
                        }
                    }
                }
            }
        }
    }
if (bandera == 0){
    printf("Cliente no encontrado");
}
}



//Punto I

void ordenarJuegosInforme(eJuegos* lista, int len){
 eJuegos AuxLista;
 int i,j;
        for (i=0;i<len;i++){
            if (lista[i].isEmpty == 1){
                for(j=i+1;j<len;j++){
                   if (lista[j].isEmpty == 1){
                        if(lista[i].importe > lista[j].importe)
                        {
                            AuxLista = lista[i];
                            lista[i] = lista[j];
                            lista[j] = AuxLista;
                        }
                   }
                }
            }
        }
        for (i=0;i<len;i++){
        if (lista[i].isEmpty == 1){
            printf ("\n La descripcion es: %s",lista[i].descripcion);
            printf ("\n El importe es: %d",lista[i].importe);
            printf ("\n El codigo es: %d\n\n",lista[i].codigoJuego);
        }
    }
}


//Punto J


void OrdenarClientesInsercion(eCliente* listaC,int lenC){
    int i,pos;
    eCliente auxLista;
    clientesToupper(listaC,lenC);
    for (i=0;i<lenC;i++){
        pos = i;
        auxLista = listaC[i];
        if (listaC[i].isEmpty == 1){
            while ((pos > 0) && strcmp(auxLista.apellido,listaC[pos-1].apellido)<0){
                listaC[pos] = listaC[pos-1];
                pos--;
            }
            listaC[pos] = auxLista;
        }
    }
for (i=0;i<lenC;i++){
    printf("\n\nApellido: %s",listaC[i].apellido);
    printf("\nNombre: %s",listaC[i].nombre);
    printf("\nDomicilio: %s",listaC[i].domicilio);
    printf("\nTelefono: %s",listaC[i].telefono);
}
}

void clientesToupper(eCliente* listaC,int lenC){
    int i;
    for (i=0;i<lenC;i++){
        strupr(listaC[i].apellido);
    }
}
