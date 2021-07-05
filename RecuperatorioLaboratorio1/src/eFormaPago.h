#ifndef EFORMAPAGO_H_
#define EFORMAPAGO_H_
#include "MiBiblioteca.h"

typedef struct
{
	int idFormaDePago;
	char descripcionPago[30];
	char bancarizado[30];
	char numOperacion[30];
	int isEmpty;
}eFormaPago;

int BuscarPagoPorId(eFormaPago listaP[], int tamP, int id);

void HardcodeoDatosFormaPago(eFormaPago listaP[], int tamP);

void MostrarUnaFormaDePago(eFormaPago pago);

int MostrarFormasDePago(eFormaPago listaP[], int tamP);

#endif /* EFORMAPAGO_H_ */
