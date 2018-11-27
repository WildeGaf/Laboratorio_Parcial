#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
}Employee;

void employee_setId(Employee* this,int id);
int employee_getId(Employee* this);

void employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this);

void employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this);

void employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this);

Employee* employee_newParametros(char *var1, char *var2, char *var3);

void em_calcularSueldo(void* p);
int menu();

#endif // EMPLEADO_H_INCLUDED
