#include "ArrayEmployees.h"
#define TL 4

int main(void)
{
	setbuf(stdout, NULL);

	Employee lista[TL];
	int idIncremental;
	int opcion;

	idIncremental = 1;

	HardcodeDataEmployee(lista, TL);
	//InitEmployees(lista, TL);

	do
	{
		opcion=Menu();

		switch(opcion)
		{
			case 1:
				if(AddEmployee(lista, TL, idIncremental))
				{
					idIncremental+=1;
					printf("Carga exitosa!");
				}
				else
				{
					printf("No hay espacio.");
				}
				break;
			case 2:
				switch(ModifyEmployee(lista, TL))
				{
					case 0:
						printf("No hay datos cargados.\n");
						break;
					case 1:
						printf("Modificacion exitosa!\n");
						break;
					case 2:
						printf("Supero el limite de intentos para ingresar un ID, se regresara al menu principal.\n");
						break;
				}
				break;
			case 3:
				switch(RemoveEmployee(lista, TL))
				{
					case 0:
						printf("No hay datos cargados.\n");
						break;
					case 1:
						printf("Baja exitosa!\n");
						break;
					case 2:
						printf("Supero el limite de intentos para ingresar un ID, se regresara al menu principal.\n");
						break;
				}
				break;
			case 4:
				if(Report(lista, TL)!=1)
				{
					printf("No hay datos cargados.");
				}

				break;
		}
	}while(opcion!=5);

	return EXIT_SUCCESS;
}
