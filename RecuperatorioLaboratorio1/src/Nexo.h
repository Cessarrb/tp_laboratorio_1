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

void OrdenarPorFecha(eTrabajo listaT[], int tamT, eBicicleta listaB[], int tamB);

int OrdenarPorMarca(eTrabajo listaT[], int tamT, eBicicleta listaB[], int tamB, eServicio listaS[], int tamS);

int ServicioConMasTrabajosRealizado(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);

int DatosBicicleta(eTrabajo trabajo, eBicicleta listaB[], int tamB);

int MostrarDatosBicleta(eTrabajo listaT[], int tamT, eBicicleta listaB[], int tamB);

void ListaBicicletasPorServicio(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB);

int BicicletasRojasEligidasPorUsiario(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB);

int MostrarUnTrabajOConFormaDePago(eTrabajo trabajo, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP);

int ListaTrabajosConFormaDePago(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP);

int ListaFormaDePagoMasUtilizada(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eBicicleta listaB[], int tamB, eFormaPago listaP[], int tamP);
#endif /* NEXO_H_ */
