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
    // Definir lista de empleados
    LinkedList* listaEmpleados = NULL;
    if (listaEmpleados == NULL){
        listaEmpleados = malloc(sizeof(LinkedList));
    }
    opcion = menu();
    do{
        switch (opcion){
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
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
        opcion = menu();
        }
    }while(opcion == 6);
    return 0;
}
