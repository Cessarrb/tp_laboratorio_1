#include <stdio.h>
#include <stdlib.h>

/**
 * @fn float IngresarNumero(char[])
 * @brief Pide el ingrese de un numero
 *
 * @param Un char para que el mensaje de pedir numero sea distinto para A y para B
 * @return El numero ingresado.
 */
float IngresarNumero(char[]);

/**
 * @fn float SacarSuma(float, float)
 * @brief Suma dos numeros que recibe como parametro
 *
 * @param Primer numero a sumar
 * @param Segundo numero a sumar
 * @return Resultado de la suma
 */
float SacarSuma(float, float);

/**
 * @fn float SacarResta(float, float)
 * @brief Resta dos numeros que recibe como parametro
 *
 * @param Primer numero a restar
 * @param Segundo numero a restar
 * @return Resultado de la resta
 */
float SacarResta(float, float);

/**
 * @fn float SacarMultiplicacion(float, float)
 * @brief Multiplica  dos numeros que recibe como parametro
 *
 * @param Primer numero a multiplicar
 * @param Segundo numero a multiplicar
 * @return Resultado de la multiplicacion
 */
float SacarMultiplicacion (float, float);

/**
 * @fn float SacarDivision(float, float)
 * @brief Divide dos numeros que recibe como parametro
 *
 * @param Primer numero a dividir
 * @param Segundo numero a dividir
 * @return Resultado de la division
 */
float SacarDivision(float ,float);

/**
 * @fn void MostrarDivision(float, float)
 * @brief Muestra el resultado de la division validando que el segundo numero ingresadp 'B' no sea 0, de lo contrario muestra un error.
 *
 * @param Segundo numero ingresado 'B'
 * @param Resultado de la division
 */
void MostrarDivision(float , float);

/**
 * @fn float SacarFactorial(float)
 * @brief Saca el favtorial del numero que recibe como parametro
 *
 * @param El numero en general, puede ser A como B
 * @return Resultado del numero factoreado
 */
float SacarFactorial(float);

/**
 * @fn void MostrarFactorial(float, float)
 * @brief Muestra el resultado del numero factoreado validando que no se haya ingresado un numero negativo, mayor al limite impuesto y con decimales
 *
 * @param El numero en general, puede ser A como B
 * @param Resultado del numero factoreado
 */
void MostrarFactorial(float, float);

/**
 * @fn int ValidarDecimal(float)
 * @brief Valida que el numero que recibe como parametro no sea un decimal
 *
 * @param El numero en negeral, puede ser A como B
 * @return 1 en caso de que sea entero, 0 si es decimal
 */
int ValidarDecimal(float);

/**
 * @fn int Menu(float, float)
 * @brief Muestra las opciones del menu donde el usuario puede elegir que opcion ingresar
 *
 * @param Primer numero a calcular
 * @param Segundo numero a calcular
 * @return La opcion ingresada
 */
int Menu(float, float);

/**
 * @fn void MostrarResultado(int, float, float, float, float, float, float, float, float)
 * @brief
 *
 * @param Valor de la bandera del case 3
 * @param Resultado de la suma
 * @param Resultado de la resta
 * @param Resultado de la multiplicacion
 * @param Resultado de la division
 * @param Numero A ingresado
 * @param Numero B ingresado
 * @param Resultado del numero factoreado en A
 * @param Resultado del numero factoreado en B
 */
void MostrarResultado(int, float, float, float, float, float, float, float, float);
