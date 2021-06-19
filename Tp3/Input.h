#ifndef INPUT_H_
#define INPUT_H_

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define VACIO -1
#define OCUPADO 0
#define TAM_BUFFER 200

int GetInt(int* numero);
float GetFloat(char* MSJ, char* MSJ_ERROR);
char GetChar(char* letra, char* MSJ, char* MSJ_ERROR);
int GetString(char* cadena, char* MSJ, char* MSJ_ERROR, int TAM);
int GetName(char* CADENA, char* MSJ, char* MSJ_ERROR, int TAM);

int GetIntConRango(int* numero, char* MSJ, char* MSJ_ERROR, int RANGO_MIN, int RANGO_MAX);
float GetFloatConRango(char* MSJ, char* MSJ_ERROR, float RANGO_MIN, float RANGO_MAX);

int ValidarInt(char* numero);
int ValidarFloat(char* numero);
int ValidacionPar(int);
int ValidarAlfanumerico(char* cadena, int tam);
int isName (char* cadena, int len);
int isChar (char* cadena);

float CalcularPromedio(int, int);
int SumaAntecesores(int);
int SumarDosNumero(int, int);
void MostrarFlotante(float);
#endif /* INPUT_H_ */
