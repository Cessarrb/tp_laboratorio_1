/******************************************************************************
Tp1 Calculadora
Cesar Omar Algañaras

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int main()
{
	setbuf(stdout, NULL);

    float numeroA;
    float numeroB;
    int opcion;
    int flag3;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    float resultadoFactorialA;
    float resultadoFactorialB;

    numeroA=0;
    numeroB=0;
    flag3=0; //Inicializado la bandera en 0 para que al momento de que el usuario ingrese 4 le tire un mensaje de error.

    do
    {
        opcion=Menu(numeroA, numeroB);

        switch(opcion)
        {
            case 1:
                numeroA=IngresarNumero("Ingrese el 1er operando: ");
                system("cls");
            break;
            case 2:
                numeroB=IngresarNumero("Ingrese el 2do operando: ");
                system("cls");
                break;
            case 3:
            	flag3=1; //Si ingresa la opcion 3, esta funcion cambia la bandera al valor 1.
                resultadoSuma=SacarSuma (numeroA, numeroB);
                resultadoResta=SacarResta (numeroA, numeroB);
                resultadoMultiplicacion=SacarMultiplicacion (numeroA, numeroB);
                resultadoDivision=SacarDivision (numeroA, numeroB);
                resultadoFactorialA=SacarFactorial(numeroA);
                resultadoFactorialB=SacarFactorial(numeroB);
                system("cls");
                printf("SE CALCULARON TODAS LAS OPERACIONES PARA A=%.2f Y B=%.2f \n", numeroA, numeroB);
                break;
            case 4:
            	MostrarResultado(flag3, resultadoSuma, resultadoResta, resultadoMultiplicacion,
								 resultadoDivision, numeroA, numeroB,
								 resultadoFactorialA, resultadoFactorialB);
            	flag3=0; //Reinicion el valor de la bandera a 0 para que vuelva a pedir que primero calcule los datos ingresando 3
            	printf("\n");
            	system("pause");
            	system("cls");
                break;
        }
    }while(opcion!=5);


    return 0;
}
