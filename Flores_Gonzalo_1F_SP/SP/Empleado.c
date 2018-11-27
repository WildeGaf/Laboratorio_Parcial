#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "controller.h"
#include "input.h"

Employee* employee_new(){
    Employee* persona = malloc(sizeof(Employee));
    return persona;
}

int menu(){
    int opcion;
    printf("\nIngrese 1 para cargar los datos del archivo");
    printf("\nIngrese 2 para listar los empleados");
    printf("\nIngrese 3 para calcular el sueldo de los empleados");
    printf("\nIngrese 4 para guardar en archivo de texto");
    printf("\nIngrese 5 para guardar en archivo binario");
    printf("\nIngrese 6 para salir");
    getInt(&opcion);
    return opcion;
}

Employee* employee_newParametros(char *var1, char *var2, char *var3)
{
    int idAux, horasAux;
    Employee* p = employee_new();
    idAux = atoi(var1);
    horasAux = atoi(var3);
    employee_setId(p, idAux);
    employee_setNombre(p, var2);
    employee_setHorasTrabajadas(p, horasAux);
    return p;
}


/********FUNCIONES SET***********/

void employee_setId(Employee* this, int id)
{
    if(id > 0)
        this->id = id;
}

void employee_setNombre(Employee* this, char* nombre)
{
    if(nombre[0] != '\0')
    strncpy(this->nombre, nombre, sizeof(this->nombre));
}

void employee_setSueldo(Employee* this, int sueldo)
{
    if(sueldo > 0)
        this->sueldo = sueldo;
}

void employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    if(horasTrabajadas > 0)
        this->horasTrabajadas = horasTrabajadas;
}


/**********************************************************/

int employee_getId(Employee* this)
{
    return this->id;
}

char * employee_getNombre(Employee* this)
{
    return this->nombre;
}

int employee_getSueldo(Employee* this)
{
    return this->sueldo;
}

int employee_getHorasTrabajadas(Employee* this)
{
    return this->horasTrabajadas;
}

void em_calcularSueldo(void* p)
{

}
