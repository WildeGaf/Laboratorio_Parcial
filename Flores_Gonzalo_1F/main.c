#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "negocio.h"
#define CANTJ 20
#define CANTC 100
#define CANTA 2000

int main()
{
    eCliente listaJ[CANTJ];
    eCliente listaC[CANTC];
    eAlquiler listaA[CANTA];
    int altaBanderaCliente = 1, altaBanderaJuego = 1;
    int opcionElegida,respuesta;
    int i,auxCodigo,auxCliente;
    //int contado,max=0;
    inicializarAlquiler(listaA,CANTA);
    inicializarJuego(listaJ,CANTJ);
    inicializarCliente(listaC,CANTC);
    do{
        respuesta = menuPrincipal();
        if (respuesta == 1){
            system("cls");
            opcionElegida=MenuJuegos();
            switch (opcionElegida){
            case 1:
                system("cls");
                addJuego(listaJ,CANTJ,&altaBanderaJuego);
                break;
            case 2:
                system("cls");
                if (altaBanderaJuego != 0){
                modificarJuego(listaJ,CANTJ);
                }
                else{
                    printf("Aun no se ingresaron datos");
                }
                break;
            case 3:
                system("cls");
                if (altaBanderaJuego != 0){
                    BajaJuego(listaJ,CANTJ);
                }else{
                    printf("Aun no se ingresaron datos");
                }
                break;
            case 4:
                system("cls");
                if (altaBanderaJuego != 0){
                    imprimirListaJuegos(listaJ,CANTJ);

                }else{
                    printf("Aun no se ingresaron datos");
                }
                system("pause");
                break;
            }
        }
        if (respuesta == 2){
            opcionElegida = menuClientes();
            switch (opcionElegida){
                case 1:
                    system("cls");
                    addCliente(listaC,CANTC,&altaBanderaCliente);
                break;
                case 2:
                    system("cls");
                    if (altaBanderaCliente != 0){
                        modificarCliente(listaC,CANTC);
                    }else{
                        printf("Aun no se ingresaron datos");
                    }
                break;
                case 3:
                    system("cls");
                    if (altaBanderaCliente != 0){
                        bajaCliente(listaC,CANTC);
                    }else{
                        printf("Aun no se ingresaron datos");
                    }

                break;
                case 4:
                    system("cls");
                    if (altaBanderaCliente != 0){
                        imprimirListaClientes(listaC,CANTC);
                    }else{
                        printf("Aun no se ingresaron datos");
                    }
                break;
            }
        }
       if (respuesta == 3){
            if (altaBanderaCliente==1 && altaBanderaJuego == 1){
                addAlquiler(listaC,CANTC,listaJ,CANTJ,listaA,CANTA);
            }else{
            printf("Faltan datos de clientes o juegos");
            }
       }
        if (respuesta == 4){
            system("cls");
            opcionElegida = menuInformes();
            switch (opcionElegida){
            case 1:
                promedioJuegosAlquilados(listaJ,CANTJ,listaA,CANTA);
                break;
            case 2:
                system("cls");
                promedioJuegosAlquilados(listaJ,CANTJ,listaA,CANTA);
                break;
            case 3:
                system("cls");
                printf("Ingrese el codigo del juego: ");
                getInt(&auxCodigo);
                alquilerJuegoDeterminado(listaC,CANTC,listaA,CANTA,auxCodigo);
                break;
            case 4:
                system("cls");
                printf("Ingrese el codigo del cliente: ");
                getInt(&auxCliente);
                alquilerClienteDeterminado(listaJ,CANTJ,listaA,CANTA,auxCliente);
                break;
            case 5:
                system("cls");
                juegoMenosAlquilado(listaJ,CANTJ,listaA,CANTA);
                break;
            case 6:
                system("cls");
                clienteMasAlquileres(listaC,CANTC,listaA,CANTA);
                break;
            case 7:
                system("cls");
                juegoFechaDeterminada(listaJ,CANTJ ,listaA,CANTA);
                break;
            case 8:
                system("cls");
                clienteFechaDeterminada(listaC,CANTC,listaA,CANTA);
                break;
            case 9:
                system("cls");
                ordenarJuegosInforme(listaJ,CANTJ);
                break;
            case 10:
                OrdenarClientesInsercion(listaC,CANTC);
                system("pause");
                system("cls");
                break;
            case 11:
                system("cls");
                break;
            }
        }
    }while(respuesta != 5);

    return 0;
}
