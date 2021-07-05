#ifndef NEXO_H_
#define NEXO_H_
#include "eTrabajo.h"
#include "eServicio.h"
#include "MiBiblioteca.h"
#include "eBicicleta.h"
#include "eFormaPago.h"

typedef struct
{
	int id;
	char descripcion[TAM_AUX];
	char bancarizado[TAM_AUX];
	char numOperacion[TAM_AUX];
	int contador;
	float acumulador;
	int contadorFormaDePago;
	int isEmpty;
}eAuxiliar;

/**
 * @fn eTrabajo PedirDatos(eServicio[], int)
 * @brief Pide todos los datos de trabajo y servicio
 *
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @return el trabajo y servicios cargados
 */
eTrabajo PedirDatos(eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP, int idTrabajoIncremental);

/**
 * @fn int DarAlta(eTrabajo[], int, eServicio[], int)
 * @brief Si hay espacio en el array pide el ingreso de datos para cargarlos
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @return 1 si se cargaron con exito los datos del trabajo o 0 si no hay espacio en el array
 */
int DarAltaTrabajo(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP, int idTrabajoIncremental);

/**
 * @fn int DarBaja(eTrabajo[], int, eServicio[], int)
 * @brief Si hay datos cargados te muestra un listado de los trabajos para darle de baja
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @return 1 si se dio de baja un trabajo o 0 si no hay datos de trabajo cargados
 */
int DarBajaTrabajo(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB);

/**
 * @fn int ModificarTrabajo(eTrabajo[], int, eServicio[], int)
 * @brief Se ingresa un id donde si es valido permite en un submeno modificar datos del trabajo
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @return 1 si la modificacion fue exitosa o 0 si no hay datos para modificar
 */
int ModificarTrabajo(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB);

/**
 * @fn void MostrarUnTrabajo(eTrabajo, eServicio[], int)
 * @brief Muestra un trabajo
 *
 * @param trabajo
 * @param listaS
 * @param tamS
 */
int MostrarUnTrabajo(eTrabajo trabajo, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB);

/**
 * @fn int MostrarTrabajos(eTrabajo[], int, eServicio[], int)
 * @brief Si hay datos de trabajos cargados muestra un listado de todos
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @return 1 si los datos se mostraron o 0 si no hay datos para mostrar
 */
int MostrarTrabajos(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB);


/**
 * @fn void MostrarUnServicioPrestado(eAuxiliar)
 * @brief Muestra un servicio prestado
 *
 * @param listaAux
 */
void MostrarUnServicioPrestado(eAuxiliar listaAux);

/**
 * @fn int MostrarServiciosPrestados(eAuxiliar[], eTrabajo[], int, eServicio[], int)
 * @brief Muestra una lista de todos los servicios prestados
 *
 * @param listaAux
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @return
 */
int MostrarServiciosPrestados(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);

/**
 * @fn void InicializarAxuliar(eAuxiliar[], eTrabajo[], int, eServicio[], int)
 * @brief Inicializa la estructura auxiliar;
 *
 * @param auxiliar
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 */
int InicializarAxuliar(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);

/**
 * @fn void ContadorAcumuladorAxuliar(eAuxiliar[], eTrabajo[], int, eServicio[], int)
 * @brief Cuenta los trabajos realizados y acumula los precios por cada uno
 *
 * @param auxiliar
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 */
int ContadorAcumuladorAxuliar(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);

/**
 * @fn void OrdenarPorFecha(eTrabajo[], int, eBicicleta[], int)
 * @brief Ordena la lista de trabajos por fecha y ante igualdad de fecha por marca
 *
 * @param listaT
 * @param tamT
 * @param listaB
 * @param tamB
 */
void OrdenarPorFecha(eTrabajo listaT[], int tamT, eBicicleta listaB[], int tamB);

/**
 * @fn void OrdenarPorMarca(eTrabajo[], int, eBicicleta[], int)
 * @brief Ordena la lista de trabajos por marca de bicicleta
 *
 * @param listaT
 * @param tamT
 * @param listaB
 * @param tamB
 */
void OrdenarPorMarca(eTrabajo listaT[], int tamT, eBicicleta listaB[], int tamB);

/**
 * @fn int ServicioConMasTrabajosRealizado(eTrabajo[], int, eServicio[], int)
 * @brief
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @return
 */
int ServicioConMasTrabajosRealizado(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);

/**
 * @fn void ListaBicicletasPorServicio(eTrabajo[], int, eServicio[], int, eBicicleta[], int)
 * @brief Muestra una lista de bicicles por cada servicio
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @return 1 si puede mostrar la lista 0 si no pudo
 */
int ListaBicicletasPorServicio(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB);


/**
 * @fn int BicicletasRojasEligidasPorUsiario(eTrabajo[], int, eServicio[], int, eBicicleta[], int)
 * @brief
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @return 1 si pudo contar una bicicleta 0 si no pudo
 */
int BicicletasRojasEligidasPorUsiario(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB);

/**
 * @fn int MostrarUnTrabajOConFormaDePago(eTrabajo, eServicio[], int, eBicicleta[], int, eFormaPago[], int)
 * @brief Muestra un trabajo con su respectiva forma de pago
 *
 * @param trabajo
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @param listaP
 * @param tamP
 * @return 1 si se puede mostrar un trabajo 0 si no pudo
 */
int MostrarUnTrabajOConFormaDePago(eTrabajo trabajo, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP);

/**
 * @fn int ListaTrabajosConFormaDePago(eTrabajo[], int, eServicio[], int, eBicicleta[], int, eFormaPago[], int)
 * @brief Muestra toda la lista de trabajos todos los datos, incluyendo servicios, bicicletaas y forma de pago
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @param listaP
 * @param tamP
 * @return 1 si puede mostrar un trabajo 0 si no pudo
 */
int ListaTrabajosConFormaDePago(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP);

/**
 * @fn int ListaFormaDePagoMasUtilizada(eTrabajo[], int, eServicio[], int, eBicicleta[], int, eFormaPago[], int)
 * @brief
 *
 * @param listaT
 * @param tamT
 * @param listaS
 * @param tamS
 * @param listaB
 * @param tamB
 * @param listaP
 * @param tamP
 * @return
 */
int ListaFormaDePagoMasUtilizada(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP);

/**
 * @fn int InicializarAxuliarFormaDePaga(eAuxiliar[], eTrabajo[], int, eFormaPago[], int)
 * @brief Inicializa el auxiliar de la forma de pago
 *
 * @param auxiliar
 * @param listaT
 * @param tamT
 * @param listaP
 * @param tamP
 * @return 1 si pude inicializar los datos 0 si no pudo
 */
int InicializarAxuliarFormaDePaga(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eFormaPago listaP[], int tamP);

/**
 * @fn void ContadorAuxiliarFormaDePaga(eAuxiliar[], eTrabajo[], int, eFormaPago[], int)
 * @brief cuenta y acumula la cantidad de formas de pago que se utilizan
 *
 * @param auxiliar
 * @param listaT
 * @param tamT
 * @param listaP
 * @param tamP
 */
void ContadorAuxiliarFormaDePaga(eAuxiliar auxiliar[], eTrabajo listaT[], int tamT, eFormaPago listaP[], int tamP);
#endif /* NEXO_H_ */
