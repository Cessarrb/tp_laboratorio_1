#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/**********************************************************************************
 *
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
**********************************************************************************/


int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();

    setbuf(stdout, NULL);

    do
    {
    	option=controller_Menu();
    	switch(option)
        {
            case 1:
            	ll_clear(listaEmpleados);
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                	printf("Carga exitosa de linked list.\n");
                }
                else
                {
                	printf("Ocurrio un problema");
                }
                break;
            case 2:
            	ll_clear(listaEmpleados);
            	if(controller_loadFromBinary("data.bin", listaEmpleados))
				{
					printf("Carga exitosa de linked list.\n");
				}
            	else
            	{
            		printf("Ocurrio un problema");
            	}
            	break;
            case 3:
            	if(controller_addEmployee(listaEmpleados))
            	{
            		printf("Alta exitosa! No olvide guardar los datos antes de cargarlos.\n");
            	}
            	else
            	{
            		printf("Ocurrio un problema.\n");
            	}
                break;
            case 4:
            	switch(controller_editEmployee(listaEmpleados))
				{
					case -1:
						printf("Modificacion cancelada.\n");
						break;
					case 0:
						printf("Primero tiene que cargar la nomina de empleados\n");
						break;
					case 1:
						printf("Modificacion exitosa! No olvide guardar los cambios antes de cargarlos\n");
						break;
				}
				break;
            case 5:
            	switch(controller_removeEmployee(listaEmpleados))
            	{
            		case -1:
						printf("Baja cancelada.\n");
						break;
            		case 0:
            			printf("Primero tiene que cargar la nomina de empleados\n");
            			break;
            		case 1:
            			printf("Baja exitosa! No olvide guardar los cambios antes de cargarlos.\n");
            			break;
            	}
                break;
            case 6:
            	if(!controller_ListEmployee(listaEmpleados))
            	{
            		printf("Primero tiene que cargar la nomina de empleados\n");
            	}
                break;
            case 7:
            	switch(controller_sortEmployee(listaEmpleados))
				{
					case -1:
						printf("Ordenamiento cancelado.\n");
						break;
					case 0:
						printf("Primero tiene que cargar la nomina de empleados\n");
						break;
					case 1:
						printf("Ordenamiento exitoso!\n");
						break;
				}
				break;
            case 8:
            	if(controller_saveAsText("data.csv", listaEmpleados))
				{
            		printf("Datos guardados con exitos!\n");
				}
            	else
            	{
            		printf("Primero tiene que cargar la nomina de empleados\n");
            	}
            	break;
            case 9:
            	if(controller_saveAsBinary("data.bin", listaEmpleados))
            	{
            		printf("Datos guardados con exitos!\n");
            	}
            	else
            	{
            		printf("Primero tiene que cargar la nomina de empleados\n");
            	}
            	break;
        }
    }while(option != 10);

	ll_deleteLinkedList(listaEmpleados);

    return 0;
}
