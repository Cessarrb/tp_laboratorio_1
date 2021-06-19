#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	Employee* pEmployeeAux;
	int rtn = 0;
	char id[200];
	char nombre[200];
	char horasTrabajadas[200];
	char sueldo[200];


	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		//Forzamos lectura de la primer linea del archivo ya que esta contiene los encabezados
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo)==4)
			{
				pEmployeeAux=employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				if(pEmployeeAux != NULL)
				{
					ll_add(pArrayListEmployee, pEmployeeAux);
					rtn=1;
				}
			}
		}while(!feof(pFile));
	}

	return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	Employee* pEmployee;

	if(pFile != NULL && pArrayListEmployee !=NULL)
	{
		do
		{
			pEmployee = employee_new();

			if(pEmployee != NULL)
			{
				rtn=-1;
				if(fread(pEmployee, sizeof(Employee), 1, pFile))
				{
					ll_add(pArrayListEmployee, pEmployee);
					rtn=1;
				}
			}
		}while(!feof(pFile));
	}
    return rtn;
}
