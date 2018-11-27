#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "controller.h"
#include "input.h"

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);

int main()
{
    char doc[51];
    int opcion;
    printf("\nIngrese el archivo a abrir: ");
    getString(doc);
    LinkedList* listaEmpleados = ll_newLinkedList();;
    opcion = menu();
    do{
        switch (opcion){
        case 1:
            controller_loadFromText(doc,listaEmpleados);
            break;
        case 2:
            controller_ListEmployee(listaEmpleados);
            break;
        case 3:
            ll_map(listaEmpleados);
            break;
        case 4:
            controller_saveAsText("info.csv",listaEmpleados);
            break;
        case 5:
            controller_saveAsBinary("info.dat",listaEmpleados);
            break;
        case 6:
            printf("\n\nAh salido del programa");
            break;
        }
        opcion = menu();
    }while(opcion != 6);
    return 0;
}
