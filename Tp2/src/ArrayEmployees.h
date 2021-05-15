#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include "MiBiblioteca.h"

struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

/**
 * @fn int Menu()
 * @brief Muestra el menu de opciones
 *
 * @return el entero de la opcion elegida
 */
int Menu();

/**
 * @fn Employee GetData(int)
 * @brief Pide los datos al usuario
 *
 * @param idIncremental
 * @return Los datos ingresados
 */
Employee GetData(int idIncremental);

/**
 * @fn void HardcodeDataEmployee(Employee[], int)
 * @brief Carga empleados al array
 *
 * @param lista
 * @param tam
 */
void HardcodeDataEmployee(Employee lista[], int tam);

/**
 * @fn void initEmployees(Employee[], int)
 * @brief Inicializa los empleazos en 0
 *
 * @param lista
 * @param tam
 */
void InitEmployees(Employee lista[], int tam);

/**
 * @fn int SearchFree(Employee[], int)
 * @brief Busca que haya un lugar libre en el array
 *
 * @param lista
 * @param tam
 * @return el indice donde esta libre
 */
int SearchFree(Employee lista[], int tam);

/**
 * @fn int FindEmployeeById(Employee[], int, int)
 * @brief Busca un empleado por id
 *
 * @param lista
 * @param tam
 * @param id
 * @return el indice donde coincida el id
 */
int FindEmployeeById(Employee lista[], int tam, int id);

/**
 * @fn int AddEmployee(Employee[], int, int)
 * @brief Da de alta un empleado
 *
 * @param lista
 * @param tam
 * @param idIncremental
 * @return 0 si no hay espacio para cargar datos, 1 si se dio de alta el empleado
 */
int AddEmployee(Employee lista[], int tam, int idIncremental);

/**
 * @fn int RemoveEmployee(Employee[], int)
 * @brief Da de baja un empleado
 *
 * @param lista
 * @param tam
 * @return 0 si no hay datos cargados, 1 si se dio de baja, 2 si excede el ingreso de ID
 */
int RemoveEmployee(Employee lista[], int tam);

/**
 * @fn int ModifyEmployee(Employee[], int)
 * @brief Modifica los datos del usario
 *
 * @param lista
 * @param tam
 * @return 0 si no hay datos cargados, 1 si se dio de baja, 2 si excede el ingreso de ID
 */
int ModifyEmployee(Employee lista[], int tam);


/**
 * @fn int OrderEmployees(Employee[], int)
 * @brief Ordena la lista de empleados por un filtro que elije el usuario
 *
 * @param lista
 * @param tam
 * @return 0 si no se ordena la lista, 1 Si se ordeno
 */
int OrderEmployees(Employee lista[], int tam);

/**
 * @fn void PrintOneEmployee(Employee)
 * @brief Imprime los dato de un empleado
 *
 * @param employee
 */
void PrintOneEmployee(Employee employee);

/**
 * @fn int PrintEmployees(Employee[], int)
 * @brief Imprime una lista con todos los datos cargados de empleados
 *
 * @param lista
 * @param tam
 * @return 0 si no hay datos para imprimir, 1 si imprimio los datos
 */
int PrintEmployees(Employee lista[], int tam);

/**
 * @fn float AccumulatorSalary(Employee[], int)
 * @brief acumula todos los salarios cargados
 *
 * @param lista
 * @param tam
 * @return El salario acumulado
 */
float AccumulatorSalary(Employee lista[], int tam);


/**
 * @fn float AverageSalary(Employee[], int)
 * @brief calcula el salario promedio
 *
 * @param lista
 * @param tam
 * @return el salario promedio
 */
float AverageSalary(Employee lista[],int tam);

/**
 * @fn int AccountantEmployees(Employee[], int)
 * @brief Cuenta los empleados cargados
 *
 * @param lista
 * @param tam
 * @return La cantidad de empleados cargados
 */
int AccountantEmployees(Employee lista[], int tam);

/**
 * @fn int HigherAverageSalary(Employee[], int)
 * @brief Cuanta los empleados que tienen un salario mayor al promedio
 *
 * @param lista
 * @param tam
 * @return La cantidad de empleados
 */
int HigherAverageSalary(Employee lista[],int tam);

/**
 * @fn int Report(Employee[], int)
 * @brief Imprime la lista de empleados ordenados alfabeticamente, el salario total, salario promedio
 * y los que superan el promedio
 *
 * @param lista
 * @param tam
 * @return 0 si no hay datos cargados, 1 si los hay
 */
int Report(Employee lista[],int tam);
#endif /* ARRAYEMPLOYEES_H_ */
