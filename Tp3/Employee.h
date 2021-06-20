#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "input.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);

int employee_delete(Employee* this);
int employee_ultimoId(LinkedList* pArrayListEmployee, int* maxId);
int employee_BuscarEmpleadoPorId(LinkedList* pArrayListEmployee, int id);

int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);

int employee_setNombre(Employee* this, char* nombre);
int employee_getNombre(Employee* this, char* nombre);

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);

int employee_setSueldo(Employee* this, int sueldo);
int employee_getSueldo(Employee* this, int* sueldo);

int employee_printEmployee(LinkedList* pArrayListEmployee, int index);
int employee_printEmployees(LinkedList* pArrayListEmployee);

int employee_OrdenarPorNombre(void* employeeUno, void* employeeDos);
int employee_OrdenarPorId(void* employeeUno, void* employeeDos);
int employee_OrdenarPorHorasTrabajadas(void* employeeUno, void* employeeDos);
int employee_OrdenarPorSueldo(void* employeeUno, void* employeeDos);

#endif // employee_H_INCLUDED
