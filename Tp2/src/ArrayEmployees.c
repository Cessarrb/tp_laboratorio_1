#include "ArrayEmployees.h"

int Menu()
{
    int opcion;

    printf("\n\t***************\n");
    printf("  \t*     MENU    *");
    printf("\n\t***************\n");
    printf("1. ALTA\n");
    printf("2. MODIFICACION\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. SALIR\n");
    opcion=GetIntConRango("Elija una opcion: ", "Error", 1, 5);

    return opcion;
}

Employee GetData(int idIncremental)
{
	Employee employee;

	printf("Id otorgado: %d\n", idIncremental);
	GetName(employee.name, "Ingrese su nombre: ", "Error", 51);
	GetName(employee.lastName, "Ingrese su apellido: ", "Error", 51);
	employee.salary=GetFloatConRango("Ingrese su salario: ", "Error", 1, 500000);
	employee.sector=GetIntConRango("Ingrese su sector: ", "Error", 1, 400000);

	employee.isEmpty=OCUPADO;

	return employee;
}

void HardcodeDataEmployee(Employee lista[], int tam)
{
    int i;
    Employee listaHard[]={{1, "Cesar", "Algañaras", 250, 8, OCUPADO},{2, "Julio", "Diaz", 4574, 1, OCUPADO},
						{3, "Juan", "Fernandez", 400, 2, OCUPADO},{4, "Emilio", "Diaz", 350, 2, OCUPADO}};

    for(i=0;i<tam;i++)
    {
    	lista[i]=listaHard[i];
    }
}

void InitEmployees(Employee lista[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		lista[i].isEmpty = VACIO;
	}
}

int SearchFree(Employee lista[], int tam)
{
	int i;
	int index;
	index = -1;

	for(i=0;i<tam;i++)
	{
		if(lista[i].isEmpty==VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

int FindEmployeeById(Employee lista[], int tam, int id)
{
    int i;
    int rtn;

    rtn=-1;

    if (lista!=NULL && tam>0)
	{
		for (i=0;i<tam;i++)
		{
			if (lista[i].id==id && lista[i].isEmpty==OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}

    return rtn;
}

int AddEmployee(Employee lista[], int tam, int idIncremental)
{
    int i;
    int rtn=0;

    i=SearchFree(lista, tam);

    if(i!=-1)
    {
    	lista[i]=GetData(idIncremental);
    	lista[i].id=idIncremental;
    	rtn=1;
    }
    return rtn;
}

int RemoveEmployee(Employee lista[], int tam)
{
    int id;
    int index;
    char respuesta;
    int rtn =0;
    int flag =0;

    if(PrintEmployees(lista, tam))
    {
    	flag=1;
    }

    if(flag)
    {
    	 id=GetInt("Ingrese el ID del id que desea dar de baja: ", "Error");
		 index=FindEmployeeById(lista, tam, id);
		 while(index==-1)
		 {
			 printf("Error. ");
			 id=GetInt("Ingrese el ID del empleado que desea dar de baja: ", "Error");
			 flag++;
			 if(flag==6)//Hago uso de la bandera como un contador para romper el while por varios intentos fallidos
			 {
				 rtn=2;
				 break;
			 }
		 }
		 if(flag!=6)
		 {
			 respuesta=GetChar("Esta seguro que desea dar de baja al empleado? Ingrese [S] para continuar o [N] para cancelar: ", "Error");
			 respuesta=tolower(respuesta);
			 rtn=3;
			 if(respuesta=='s')
			 {
				 lista[index].isEmpty=VACIO;
				 rtn=1;
			 }
		 }
    }

    return rtn;
}

int ModifyEmployee(Employee lista[], int tam)
{
    int id;
    char respuesta;
    int opcion;
    int flag=0;
    int rtn=0;
    int index;

    if(PrintEmployees(lista, tam))
	{
		flag=1;
	}

    if(flag)
    {
		id=GetInt("Ingrese el ID del empleado que desea modificar: ", "Error");
		index=FindEmployeeById(lista, tam, id);
		while(index==-1)
		{
			printf("Error. ");
			id=GetInt("Ingrese el ID del empleado que desea modificar: ", "Error");
			flag++;
			if(flag==6)//Hago uso de la bandera como un contador para romper el while por varios intentos fallidos
			{
				rtn=2;
				break;
			}
		}
		if(flag!=6)
		 {
			 respuesta=GetChar("Esta seguro que desea modificar un empleado? Ingrese [S] para continuar o [N] para cancelar: ", "Error");
			 respuesta=tolower(respuesta);
			 rtn=3;
			 if(respuesta=='s')
			 {
					printf("1-NOMBRE\n");
					printf("2-APELLIDO\n");
					printf("3-SALARIO\n");
					printf("4-SECTOR\n");
					opcion=GetFloatConRango("Ingrese una opcion: ", "Error", 1, 4);
					switch(opcion)
					{
						case 1:
							GetName(lista[index].name, "Ingrese el nuevo nombre: ", "Error", 51);
							rtn=1;
							break;
						case 2:
							GetName(lista[index].name, "Ingrese el nuevo apellido: ", "Error", 51);
							rtn=1;
							break;
						case 3:
							GetFloatConRango("Ingrese el nuevo salario: ", "Error", 1, 500000);
							rtn=1;
							break;
						case 4:
							GetIntConRango("Ingrese el nuevo sector: ", "Error", 1, 400000);
							rtn=1;
							break;
					}
			 }
		 }
    }
	return rtn;
}

void PrintOneEmployee(Employee employee)
{
	printf("%4d %20s %20s %15.2f %12d\n", employee.id, employee.name, employee.lastName, employee.salary, employee.sector);
}

int PrintEmployees(Employee lista[], int tam)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	int encabezado = 0;

	if (lista != NULL && tam>0)
	{
		for (i=0;i<tam;i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				if(encabezado==0)
				{
					printf("%4s %20s %20s %15s %12s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
					encabezado++;
				}

				PrintOneEmployee(lista[i]);
				cantidad++;
			}
		}
	}

	if(cantidad>0)
	{
		rtn = 1;
	}

	return rtn;
}

int OrderEmployees(Employee lista[], int tam)
{
    int i;
    int j;
    int rtn=0;
    int opcion;
    char respuesta;
    Employee auxiliar;

    respuesta=GetChar("Desea filtrar por orden alfabetico los apellidos?: [S] para continuar [N] para omitir: ", "Error");
    respuesta=tolower(respuesta);
    if(respuesta=='s')
    {
    	printf("Elija el orden alfabetico\n");
		printf("1-Ordenamiento A-Z\n");
		printf("2-Ordenamiento Z-A\n");
		opcion=GetIntConRango("Ingrese una opcion: ", "Error", 1, 2);

		if(opcion==1)
		{
			for(i=0;i<tam-1;i++)
			{
				for(j=i+1;j<tam;j++)
				{
					if(strcmp(lista[i].lastName, lista[j].lastName)>0)
					{
						auxiliar=lista[i];
						lista[i]=lista[j];
						lista[j]=auxiliar;
					}
					if(strcmp(lista[i].lastName, lista[j].lastName)==0)
					{
						if(lista[i].sector>lista[j].sector)
						{
							auxiliar=lista[i];
							lista[i]=lista[j];
							lista[j]=auxiliar;
						}
					}
				}
			}
		}
		else
		{
			for(i=0;i<tam-1;i++)
			{
				for(j=i+1;j<tam;j++)
				{
					if(strcmp(lista[i].lastName, lista[j].lastName)<0)
					{
						auxiliar=lista[i];
						lista[i]=lista[j];
						lista[j]=auxiliar;
					}
					if(strcmp(lista[i].lastName, lista[j].lastName)==0)
					{
						if(lista[i].sector>lista[j].sector)
						{
							auxiliar=lista[i];
							lista[i]=lista[j];
							lista[j]=auxiliar;
						}
					}
				}
			}
		}

		rtn=1;
    }

    return rtn;
}

float AccumulatorSalary(Employee lista[], int tam)
{
    int i;
    float acumuladorSalario;

    acumuladorSalario=0;

    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
        	acumuladorSalario+=lista[i].salary;
        }
    }

    return acumuladorSalario;
}

float AverageSalary(Employee lista[],int tam)
{
    int i;
    float promedioSalario;

    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
        	promedioSalario=(float)AccumulatorSalary(lista, tam)/AccountantEmployees(lista, tam);
        }
    }

    return promedioSalario;
}

int AccountantEmployees(Employee lista[], int tam)
{
    int i;
    int contadorEmpleados;

    contadorEmpleados=0;

    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
        	contadorEmpleados++;
        }
    }

    return contadorEmpleados;

}

int HigherAverageSalary(Employee lista[],int tam)
{
    int i;
    float promedioSalario;
    int salarioMayorAlPromedio;

    salarioMayorAlPromedio=0;

    promedioSalario = AverageSalary(lista, tam);

    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
        	if(lista[i].salary>promedioSalario)
        	{
        		salarioMayorAlPromedio++;
        	}
        }
    }

    return salarioMayorAlPromedio;
}

int Report(Employee lista[],int tam)
{
	int i;
	int rtn=0;
	int flag=0;
	float sumaSalarios;
	float promedioSalarios;
	int contadorSalarioMayor;

	for(i=0;i<tam;i++)
	{
		if(lista[i].isEmpty==OCUPADO)
		{
			flag=1;
		}
	}

	if(flag==1)
	{
		if(OrderEmployees(lista, tam))
		{
			PrintEmployees(lista, tam);
		}
		else
		{
			PrintEmployees(lista, tam);
		}

		sumaSalarios=AccumulatorSalary(lista, tam);
		promedioSalarios=AverageSalary(lista, tam);
		contadorSalarioMayor=HigherAverageSalary(lista, tam);

		printf("\nEL SALARIO TOTAL ES: %.2f\n", sumaSalarios);
		printf("EL PROMEDIO DE LOS SALARIO ES: %.2f\n", promedioSalarios);
		printf("LA CANTIDAD DE EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO ES: %d\n", contadorSalarioMayor);
		rtn=1;
	}

	return rtn;
}
