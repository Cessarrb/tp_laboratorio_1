#include "Employee.h"


Employee* employee_new()
{
	Employee*  pEmployee;

	pEmployee = (Employee*) calloc(sizeof(Employee), 1);

	return pEmployee;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmployee;
	pEmployee = employee_new();

	if(pEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		employee_setId(pEmployee, atoi(idStr));
		employee_setNombre(pEmployee, nombreStr);
		employee_setHorasTrabajadas(pEmployee, atoi(horasTrabajadasStr));
		employee_setSueldo(pEmployee, atoi(sueldoStr));
	}

	return pEmployee;
}

int employee_delete(Employee* this)
{
	int rtn=0;
	if(this != NULL)
	{
		free(this);
		rtn=1;
	}

	return rtn;
}

int employee_setId(Employee* this, int id)
{
	int rtn=0;

	if(this != NULL && id>0)
	{
		this->id=id;
		rtn=1;
	}

	return rtn;
}

int employee_getId(Employee* this, int* id)
{
	int rtn=0;

	if(this != NULL && id != NULL)
	{
		*id=this->id;
		rtn=1;
	}

	return rtn;
}
int employee_setNombre(Employee* this, char* nombre)
{
	int rtn=0;

	if(this != NULL && strlen(nombre)>0)
	{
		strcpy(this->nombre, nombre);
		rtn=1;
	}

	return rtn;
}
int employee_getNombre(Employee* this, char* nombre)
{
	int rtn=0;

	if(this != NULL && strlen(nombre)>0)
	{
		strcpy(nombre, this->nombre);
		rtn=1;
	}

	return rtn;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int rtn=0;

	if(this != NULL && horasTrabajadas>0)
	{
		this->horasTrabajadas=horasTrabajadas;
		rtn=1;
	}

	return rtn;

}
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int rtn=0;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		rtn=1;
	}

	return rtn;
}

int employee_setSueldo(Employee* this, int sueldo)
{
	int rtn=0;

	if(this != NULL && sueldo>0)
	{
		this->sueldo=sueldo;
		rtn=1;
	}

	return rtn;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int rtn=0;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo=this->sueldo;
		rtn=1;
	}

	return rtn;
}

int employee_printEmployees(LinkedList* pArrayListEmployee)
{
	Employee* pEmployeeAux;
	int i;
	int id;
	char nombre[4096];
	int horasTrabajadas;
	int sueldo;
	int rtn=0;

	if(pArrayListEmployee != NULL)
	{

		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			if(i==0)
			{
				printf("##==============================================##\n");
				printf("||%4s || %15s || %7s || %7s ||\n", "ID", "NOMBRE", "HORAS", "SUELDO");
				printf("##==============================================##\n");
			}

			pEmployeeAux = (Employee*)ll_get(pArrayListEmployee, i);

			if(pEmployeeAux != NULL && pEmployeeAux != 0)
			{
				employee_getId(pEmployeeAux, &id);
				employee_getNombre(pEmployeeAux, nombre);
				employee_getHorasTrabajadas(pEmployeeAux, &horasTrabajadas);
				employee_getSueldo(pEmployeeAux, &sueldo);
			}
			printf("||%4d || %15s || %7d || %7d ||\n", id, nombre, horasTrabajadas, sueldo);
			rtn=1;
		}
		if(rtn==1)
		{
			printf("##==============================================##\n");
		}
	}

	return rtn;
}

int employee_ultimoId(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int largo;
	int auxId;
	int ultimoId = 0;

	largo = ll_len(pArrayListEmployee);

	if (pArrayListEmployee != NULL)
	{
		for(int i = 0; i < largo; i++)
		{
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &auxId);

			if(i==0 || auxId > ultimoId)
			{
				ultimoId = auxId;
			}
		}
	}
	return ultimoId;

}

int employee_OrdenarPorNombre(void* employeeUno, void* employeeDos)
{
	int rtn=0;
	char nombreUno[50];
	char nombreDos[50];

	employee_getNombre(employeeUno, nombreUno);
	employee_getNombre(employeeDos, nombreDos);

	if(employeeUno != NULL && employeeDos != NULL)
	{
		if(strcmp(nombreUno, nombreDos)>0)
		{
			rtn=1;
		}
		else
		{
			if(strcmp(nombreUno, nombreDos)<0)
			{
				rtn=-1;
			}
		}
	}

	return rtn;
}

int employee_OrdenarPorId(void* employeeUno, void* employeeDos)
{
	int rtn=0;
	int idUno;
	int idDos;

	employee_getId(employeeUno, &idUno);
	employee_getId(employeeDos, &idDos);

	if(employeeUno != NULL && employeeDos != NULL)
	{
		if(idUno > idDos)
		{
			rtn=1;
		}
		else
		{
			if(idUno < idDos)
			{
				rtn=-1;
			}
		}
	}

	return rtn;
}

int employee_OrdenarPorHorasTrabajadas(void* employeeUno, void* employeeDos)
{
	int rtn=0;
	int horasUno;
	int horasDos;

	employee_getHorasTrabajadas(employeeUno, &horasUno);
	employee_getHorasTrabajadas(employeeDos, &horasDos);

	if(employeeUno != NULL && employeeDos != NULL)
	{
		if(horasUno > horasDos)
		{
			rtn=1;
		}
		else
		{
			if(horasUno < horasDos)
			{
				rtn=-1;
			}
		}
	}

	return rtn;
}

int employee_OrdenarPorSueldo(void* employeeUno, void* employeeDos)
{
	int rtn=0;
	int sueldoUno;
	int sueldoDos;

	employee_getSueldo(employeeUno, &sueldoUno);
	employee_getSueldo(employeeDos, &sueldoDos);

	if(employeeUno != NULL && employeeDos != NULL)
	{
		if(sueldoUno > sueldoDos)
		{
			rtn=1;
		}
		else
		{
			if(sueldoUno < sueldoDos)
			{
				rtn=-1;
			}
		}
	}

	return rtn;
}

int employee_BuscarEmpleadoPorId(LinkedList* pArrayListEmployee, int* id)
{
	Employee* pEmployeeAux;
	int len;
	int i;
	int auxId;
	int rtn=-1;

	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && id != NULL)
	{
		for(i=0;i<len;i++)
		{
			pEmployeeAux = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmployeeAux, &auxId);
			if(*id == auxId && pEmployeeAux != NULL)
			{
				rtn=i;
				break;
			}
		}
	}

	return rtn;
}

