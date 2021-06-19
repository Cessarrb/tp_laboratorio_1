#include "Input.h"

int GetInt(int* numero)
{
	int rtn=0;
   	char buffer[TAM_BUFFER];

   	if(numero != NULL)
   	{
   		fflush(stdin);
		fgets(buffer, TAM_BUFFER, stdin);
		if(ValidarInt(buffer))
		{
			*numero=atoi(buffer);
			rtn=1;
		}
   	}

    return rtn;
}


int GetIntConRango(int* numero, char* MSJ, char* MSJ_ERROR, int RANGO_MIN, int RANGO_MAX)
{
	int rtn=0;
	int reintentos=5;
	int indexNumero;
	if(	MSJ != NULL && 	MSJ_ERROR != NULL && numero != NULL && RANGO_MAX >= RANGO_MIN)
	{
		do
		{
			printf("%s", MSJ);
			if(GetInt(&indexNumero) && indexNumero >= RANGO_MIN && indexNumero <= RANGO_MAX)
			{
				*numero = indexNumero;
				rtn= 1;
				break;
			}
			reintentos--;
			printf("%s. ", MSJ_ERROR);
		}while(reintentos >=0);
		if(reintentos<=0)
		{
			printf("\n");
		}
	}

	return rtn;
}

int ValidarInt(char* numero)
{
	int i;
	int rtn=0;

	if(numero != NULL)
	{
		for (i=0;i<strlen(numero);i++)
		{
			if(isdigit(numero[i]))
			{
				rtn=1;
				break;
			}
		}
	}

    return rtn;
}

float GetFloat(char* MSJ, char* MSJ_ERROR)
{
	float numero;
	char buffer[TAM_BUFFER];


	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(ValidarFloat(buffer)==0)
	{
		printf("%s. %s", MSJ_ERROR, MSJ);
		fflush(stdin);
		gets(buffer);
	}

	numero=atof(buffer);

	return numero;
}

float GetFloatConRango(char* MSJ, char* MSJ_ERROR, float RANGO_MIN, float RANGO_MAX)
{
	float indexNumero;

	indexNumero=GetFloat(MSJ, MSJ_ERROR);

	while(indexNumero<RANGO_MIN || indexNumero>RANGO_MAX)
	{
		printf("Error, numero fuera de rango, minimo: %f o maximo: %f\n", RANGO_MIN, RANGO_MAX);
		indexNumero=GetFloat(MSJ, MSJ_ERROR);
	}

	return indexNumero;
}

int ValidarFloat(char* numero)
{
	int i;
	int rtn=1;
	int contadorPuntos;

	contadorPuntos=0;

	if(numero !=NULL)
	{
		for (i=0;i<strlen(numero);i++)
		{
			if(i==0 && (numero[i]=='+' || numero[i]=='-'))
			{
				continue;
			}
				if(numero[i]<'0' || numero[i]>'9')
				{
					if(numero[i] == '.' && contadorPuntos==0)
					{
						contadorPuntos++;
					}
					else
					{
						rtn=0;
						break;
					}
				}
		}
	}
    return rtn;
}

char GetChar(char* letra, char* MSJ, char* MSJ_ERROR)
{
	char buffer[TAM_BUFFER];
	int rtn=0;

    printf("%s", MSJ);
    fflush(stdin);
    gets(buffer);

    while(isChar(buffer)!=1 || strlen(buffer)>1)
    {
        printf("%s, %s", MSJ_ERROR, MSJ);
        fflush(stdin);
        gets(buffer);
    }

    *letra=buffer[0];
    rtn=1;

    return rtn;
}

int GetString(char* CADENA, char* MSJ, char* MSJ_ERROR, int TAM)
{
	int rtn = 0;
	char buffer[TAM_BUFFER];
	int reintentos = 5;

	if(CADENA != NULL && MSJ != NULL && MSJ_ERROR != NULL)
	{

		do{
			printf("%s", MSJ);
			fflush(stdin);
			gets(buffer);
			if(ValidarAlfanumerico(CADENA, TAM))
			{
				strcpy(CADENA, buffer);
				rtn=1;
				break;
			}
			printf("%s. ", MSJ_ERROR);
			reintentos--;
		}while(reintentos>=0);

		if(reintentos<=0)
		{
			printf("\n");
		}
	}

	return rtn;
}

int GetName(char* CADENA, char* MSJ, char* MSJ_ERROR, int TAM)
{
	int rtn = 0;
	char buffer[TAM_BUFFER];
	int reintentos = 5;

	if(CADENA != NULL && MSJ != NULL && MSJ_ERROR != NULL)
	{
		do{
			printf("%s", MSJ);
			fflush(stdin);
			gets(buffer);
			if(isName(buffer, TAM) && strlen(buffer)!=0)
			{
				strcpy(CADENA, buffer);
				rtn=1;
				break;
			}
			else
			{
				printf("%s. ", MSJ_ERROR);
				reintentos--;
			}
		}while(reintentos>=0);

		if(reintentos<=0)
		{
			printf("\n");
		}
	}

	return rtn;
}

int isName (char* cadena, int len)
{
    int rtn = 1;
    int i;

    if(cadena != NULL && strlen(cadena)<len)
    {
		for (i=0;i<=len&&cadena[i] != '\0';i++)
		{
			if((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
			{
				rtn = 0;
				break;
			}
		}
    }
    return rtn;
}

int VerificarNumero(int numero)
{
    int verificacion;

    if(numero>0 || numero<0)
    {
        verificacion=1;
    }
    else
	{
		verificacion=0;
	}

    return verificacion;
}

float CalcularPromedio(int numero, int otroNumero)
{
    float promedio;

    promedio=(float)numero/otroNumero;

    return promedio;
}

int SumaAntecesores(int numero)
{
    int i;
    int suma;

    suma=0;

    for(i=numero;i<2;i++)
    {
        suma=suma+i;
    }

    return suma;
}

int isChar (char* cadena)
{
	int i=0;
	int rtn=0 ;
	if(cadena != NULL)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(cadena[i] >='A' && cadena[i] <='z')
			{
				continue;
			}
			if(cadena[i]>='0' && cadena[i]<='9')
			{
				break;
			}

		}
		if(cadena[i]=='\0')
		{
			rtn=1;
		}
	}
		return rtn;
}

int ValidarAlfanumerico(char* cadena, int tam)
{
	int rtn=1;
	int i;
	for (i=0;i<=tam&&cadena[i] !='\0';i++)
	{
		if	((cadena[i] < 'a' || cadena[i] > 'z') &&
			(cadena[i] < 'A' || cadena[i] > 'Z') &&
			(cadena[i] <'0' || cadena[i]>'9')&&
			cadena[i]!=' ')
		{
			rtn = 0;
			break;
		}
	}

	return rtn;
}

int SumarDosNumero(int numero, int otroNumero)
{
	int sumar;

	sumar=numero+otroNumero;

	return sumar;
}

int ValidacionPar(int numero)
{
    int resultado;

    if(numero%2==0)
    {
        resultado=1;
    }
    else
    {
        resultado=0;
    }

    return resultado;
}

void MostrarFlotante(float numero)
{
    printf("el numero ingresado es %f", numero);
}



