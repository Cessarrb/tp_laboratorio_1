#include "Funciones.h"

float IngresarNumero (char MSJ[])
{
    float numero;
    printf("%s", MSJ);
    scanf ("%f", &numero);
    return numero;
}

float SacarSuma (float numeroA,float numeroB)
{
    float resultado;
    resultado = numeroA + numeroB;
    return resultado;
}

float SacarResta (float numeroA,float numeroB)
{
    float resultado;
    resultado = numeroA - numeroB;
    return resultado;
}

float SacarMultiplicacion (float numeroA,float numeroB)
{
    float resultado;
    resultado = numeroA * numeroB;
    return resultado;
}

float SacarDivision (float numeroA,float numeroB)
{

    float resultado;
    if(numeroB!=0)
    {
        resultado = (float)numeroA /numeroB;
    }

    return resultado;
}

void MostrarDivision(float numeroB, float resultadoDivision)
{

	if(numeroB!=0)
	{
		printf("Resultado de la division es: %.2f\n", resultadoDivision);
	}
	else
	{
		printf("No se puede dividir por 0\n");
	}

}

float SacarFactorial (float numero)
{
    int i;
    float resultado;

    resultado=1;

    if (numero>1)
    {
        for (i=numero;i>1;i--)
        {
            resultado = resultado*i;
        }
    }
    else
    {
    	if(numero==0 || numero==1)
    	{
    		resultado=1;
    	}
    }

    return resultado;
}

void MostrarFactorial(float numero, float resultadoFactorial)
{
	int index;

	index=ValidarDecimal(numero);

	if(numero>-1 && numero<35 && index==1)
	{
		printf("El factorial de %.2f es: %.2f\n",numero, resultadoFactorial);
	}
	else
	{
		if(numero<0)
		{
			printf("No se puede aplicar el factorial del valor %.2f porque es un numero negativo\n", numero);
		}
		else
		{
			if(numero>34)
			{
				printf("No se puede aplicar el factorial del valor %.2f porque su resultado es muy grande, maximo 34\n", numero);
			}
			else
			{
				if(index==0)
				{
					printf("No se puede aplicar el factorial del valor %.2f porque es un numero con decimal\n", numero);
				}
			}
		}
	}
}

int ValidarDecimal(float numero)
{
	int entero;
	int rtn;

	rtn=0; //Es decimal

	    entero=numero;

	    if(numero-entero==0)
	    {
	    	rtn=1; //Es entero
	    }

	    return rtn;
}

int Menu(float numeroA, float numeroB)
{
	int opcion;

	printf("\n\t\t***************\n");
    printf("\n\t\t* CALCULADORA *\n");
    printf("\n\t\t***************\n");
    printf("\n  1- Ingresar 1er operando (A=%.2f)", numeroA);
    printf("\n  2- Ingresar 2do operando (B=%.2f)", numeroB);
    printf("\n  3- Calcular todas la operaciones");
    printf("\n\ta- Calcular la suma (A+B)");
    printf("\n\tb- Calcular la resta (A-B)");
    printf("\n\tc- Calcular la division (A/B)");
    printf("\n\td- Calcular la multiplicacion (A*B)");
    printf("\n\te- Calcular el factorial (A!)");
    printf("\n  4- Informar resultados");
    printf("\n  5- Salir\n");
    printf("\n  Elija una opcion (1-5): ");
    scanf("%d", &opcion);

    return opcion;
}

void MostrarResultado(int flag3, float resultadoSuma, float resultadoResta, float resultadoMultiplicacion,
					  float resultadoDivision, float numeroA, float numeroB,
					  float resultadoFactorialA, float resultadoFactorialB)
{
	if(flag3==1)
	{
		printf("\nResultado de la suma es: %.2f\n", resultadoSuma);
		printf("Resultado de la resta es: %.2f\n", resultadoResta);
		printf("Resultado de la multiplicacion: %.2f\n", resultadoMultiplicacion);
		MostrarDivision(numeroB, resultadoDivision);
		MostrarFactorial(numeroA, resultadoFactorialA);
		MostrarFactorial(numeroB, resultadoFactorialB);
	}
	else
	{
		printf("Error, primero calcule las operaciones con la opcion '3' y despues ingrese '4' para mostrar resultados");
	}

}
