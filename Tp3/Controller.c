#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "parser.h"
#include "controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	FILE* pFile = NULL;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			if(parser_EmployeeFromText(pFile, pArrayListEmployee))
			{
				fclose(pFile);
				rtn=1;
			}
		}
	}

    return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
	int rtn = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* pFile;
		pFile = fopen(path, "rb");
		if(pFile != NULL)
		{
			if(parser_EmployeeFromBinary(pFile, pArrayListEmployee))
			{
				fclose(pFile);
				rtn=1;
			}
		}
	}

    return rtn;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;

	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int validHs;
	int validNombre;
	int validSueldo;
	int rtn=0;

	pEmployee=employee_new();

	if(pArrayListEmployee!=NULL && pEmployee !=NULL)
	{
		validNombre=GetName(nombre, "Ingrese su nombre: ", "Error", 128);
		validHs=GetIntConRango(&horasTrabajadas, "Ingrese las horas trabajadas: ", "Error", 1, 500);
		validSueldo=GetIntConRango(&sueldo, "Ingrese su sueldo: ", "Error", 1, 500000);
		id=controller_readId(pArrayListEmployee, "id.bat")+1;
		if(validNombre && validHs && validSueldo)
		{
				employee_setId(pEmployee, id);
				employee_setNombre(pEmployee, nombre);
				employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
				employee_setSueldo(pEmployee, sueldo);

				ll_add(pArrayListEmployee,pEmployee);

				rtn=1;
		}
	}

	return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmployeeAux;
	int idModify;
	int len;
	int rtn=0;
	char confirmacion;
	int opcion;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;
	int indexEmployee;

	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && len>0)
	{
		employee_printEmployees(pArrayListEmployee);
		if(!GetIntConRango(&idModify, "Ingrese el ID que desea modificar: ", "Error", 1, len))
		{
			printf("Demasiados intentos.");
			rtn=2;
		}
		indexEmployee=employee_BuscarEmpleadoPorId(pArrayListEmployee, idModify);
			if(indexEmployee!=-1)
			{
				pEmployeeAux = (Employee*) ll_get(pArrayListEmployee, indexEmployee);
				employee_printEmployee(pArrayListEmployee, indexEmployee);
				GetChar(&confirmacion, "Esta seguro desea modificar este empleado? ingrese [S] para confirmar [N] para salir: ", "Error");
				confirmacion = tolower(confirmacion);
				rtn=-1;
				if(confirmacion=='s')
				{
					do
					{
						opcion=subMenuModificar();
						switch(opcion)
						{
							case 1:
								if(GetString(auxNombre, "Ingrese el nuevo nombre: ", "Error", 128))
								{
									employee_setNombre(pEmployeeAux, auxNombre);
									printf("NOMBRE MODIFICADO!\n");
									rtn=1;
								}
								break;
							case 2:
								if(GetIntConRango(&auxHorasTrabajadas, "Ingrese las nuevas horas trabajadas: ", "Error", 1, 500))
								{
									employee_setHorasTrabajadas(pEmployeeAux, auxHorasTrabajadas);
									printf("HORAS TRABAJADAS MODIFICADAS!\n");
									rtn=1;
								}
								break;
							case 3:
								if(GetIntConRango(&auxSueldo, "Ingrese el nuevo sueldo: ", "Error", 1, 500000))
								{
									employee_setSueldo(pEmployeeAux, auxSueldo);
									printf("SUELDO MODIFICADO!\n");
									rtn=1;
								}
								break;
						}
					}while(opcion!=4);
				}
			}
	}

    return rtn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int indexEmployee;
	int idDelete;
	int len;
	int rtn=0;
	char opcion;

	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && len>0)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(!GetIntConRango(&idDelete, "Ingrese el id del empleado que desea dar de baja: ", "Error", 1, 5000))
		{
			printf("Demasiados intentos.");
			rtn=2;
		}
		indexEmployee=employee_BuscarEmpleadoPorId(pArrayListEmployee, idDelete);
			if(indexEmployee!=-1)
			{
				employee_printEmployee(pArrayListEmployee, indexEmployee);
				GetChar(&opcion, "Esta seguro desea dar de baja este empleado? ingrese [S] para confirmar [N] para salir: ", "Error");
				opcion = tolower(opcion);
				rtn=-1;
				if(opcion=='s')
				{
					ll_remove(pArrayListEmployee, indexEmployee);
					rtn=1;
				}
			}
	}

	return rtn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=0;

	if(employee_printEmployees(pArrayListEmployee))
	{
		rtn=1;
	}

	return rtn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int opcion;
	int opcionSubmenu;
	int rtn=0;
	int isEmpty;

	isEmpty = ll_isEmpty(pArrayListEmployee);


	if(pArrayListEmployee != NULL && isEmpty!=1)
	{
		do
		{
			opcion=subMenuOrden();
			switch(opcion)
			{
				case 1:
					opcionSubmenu=opcionOrden();
					ll_sort(pArrayListEmployee, employee_OrdenarPorId, opcionSubmenu);
					if(opcionSubmenu==3)
					{
						rtn=-1;
					}
					else
					{
						rtn=1;
					}
					opcion=5;
					break;
				case 2:
					opcionSubmenu=opcionOrden();
					ll_sort(pArrayListEmployee, employee_OrdenarPorNombre, opcionSubmenu);
					if(opcionSubmenu==3)
					{
						rtn=-1;
					}
					else
					{
						rtn=1;
					}
					opcion=5;
					break;
				case 3:
					opcionSubmenu=opcionOrden();
					ll_sort(pArrayListEmployee, employee_OrdenarPorHorasTrabajadas, opcionSubmenu);
					if(opcionSubmenu==3)
					{
						rtn=-1;
					}
					else
					{
						rtn=1;
					}
					opcion=5;
					break;
				case 4:
					opcionSubmenu=opcionOrden();
					ll_sort(pArrayListEmployee, employee_OrdenarPorSueldo, opcionSubmenu);
					if(opcionSubmenu!=3)
					{
						rtn=1;
					}
					else
					{
						rtn=-1;
					}
					opcion=5;
					break;
				case 5:
					rtn=-1;
					break;
			}
		}while(opcion!=5);
	}

    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	int auxId;
	char auxNombre[100];
	int auxHorasTrabajadas;
	int auxSueldo;
	int rtn=0;
	FILE* pFile;
	Employee* pEmployee;
	int len;

	len = ll_len(pArrayListEmployee);

	if(path != NULL && pArrayListEmployee != NULL && len > 0)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
			for(i=0;i<len;i++)
			{
				pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
				if(employee_getId(pEmployee, &auxId) &&
					employee_getNombre(pEmployee, auxNombre) &&
					employee_getHorasTrabajadas(pEmployee, &auxHorasTrabajadas) &&
					employee_getSueldo(pEmployee, &auxSueldo))
				{
					fprintf(pFile, "%d, %s, %d, %d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
					rtn=1;
				}
			}
			fclose(pFile);
			controller_writeId(pArrayListEmployee, "id.bat");
		}
	}
    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* pEmployeeAux;
	int rtn = 0;
	int i;
	int len;

	len = ll_len(pArrayListEmployee);

	if(path != NULL && pArrayListEmployee != NULL && len > 0)
	{
		pFile = fopen(path, "wb");
		if(pFile != NULL)
		{
			rtn=-1;
			for(i=0;i<len;i++)
			{
				pEmployeeAux = (Employee*)ll_get(pArrayListEmployee, i);
				fwrite(pEmployeeAux, sizeof(Employee), 1, pFile);
			}
			rtn=1;
		}
		fclose(pFile);
		controller_writeId(pArrayListEmployee, "id.bat");
	}


    return rtn;
}

int controller_Menu()
{
	int opcion;

	printf("\n\t***************\n");
	printf("  \t*     MENU    *");
	printf("\n\t***************\n");
	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
	printf("10. Salir\n");

	if(!GetIntConRango(&opcion, "Ingrese una opcion: ", "Error", 1, 10))
	{
		printf("Demasiados intentos incorrectos, se cerrara el programa.");
		opcion=10;
	}
	return opcion;
}

int controller_writeId(LinkedList* pArrayListEmployee, char* path)
{
	int retorno;
	int i;
	int len;
	Employee* empleado;
	FILE* pFile;

	retorno = -1;

	if(path != NULL)
	{
		len = ll_len(pArrayListEmployee);
		pFile = fopen(path,"wb");

		if(pFile != NULL)
		{
			for(i=0;i<len;i++)
			{
				empleado = (Employee*) ll_get(pArrayListEmployee, i);
				retorno = empleado->id;
			}
			fwrite(&retorno,sizeof(int),1,pFile); 
		}
		fclose(pFile);
	}
	return retorno;

}
int controller_readId(LinkedList* pArrayListEmployee, char* path)
{
	int retorno;
	int id;
	int isEmpty;
	FILE* pFile;

	retorno = -1;

		if(path != NULL)
		{
			pFile = fopen(path,"rb");

			if(pFile != NULL)
			{
				isEmpty = ll_isEmpty(pArrayListEmployee);
				if(isEmpty != 1)
				{
					fread(&id,sizeof(int),1,pFile);
					retorno = id;
				}
				else
				{
					retorno = 0;
				}
			}
			fclose(pFile);
		}
	
	return retorno;
}


int subMenuModificar()
{
	int opcion;

	printf("\n[MODIFICACION]\n\n");
	printf("1-Modificar nombre\n");
	printf("2-Modificar horas trabajadas\n");
	printf("3-Modificar sueldo\n");
	printf("4-Volver al menu\n");
	GetIntConRango(&opcion, "Ingrese una opcion: ", "Error", 1, 4);

	return opcion;
}

int subMenuOrden()
{
	int opcion;

    printf("1. Por id\n");
	printf("2. Por nombre\n");
    printf("3. Por horas trabajadas\n");
    printf("4. Por sueldo\n");
    printf("5. Volver\n");

	GetIntConRango(&opcion,"¿Por cual criterio desea ordenar?: ","ERROR", 1, 5);

	return opcion;
}

int opcionOrden()
{
	int opcionSubmenu;

	printf("1. Ascendente\n");
	printf("2. Descendente\n");
	printf("3. Volver\n");

	GetIntConRango(&opcionSubmenu, "¿Como lo desea ordenar?: ", "Error", 1, 3);

	if(opcionSubmenu==2)
	{
		opcionSubmenu=0;
	}

	return opcionSubmenu;
}
