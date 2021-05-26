#include "tipos.h"
#include "colores.h"
#include"mascotas.h"
#include"servicios.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;  //pk
    int idMascota;
    int idServicio;
    eFecha fIngreso;
    int isEmpty;


}eTrabajo;

#endif // TRABAJO_H_INCLUDED


/** \brief Funcion que busca un lugar (indice) libre en array trabajos.
 *
 * \param lista[] eTrabajo array trabajos
 * \param tam int tamanio array trabajos
 * \return int retorna -1 si no logro encontrar un indice libre en array, o retorna el numero de indice donde el array tiene un lugar libre.
 *
 */
int buscarLibreTrabajo(eTrabajo lista[], int tam);

/** \brief Funcion que da de alta un trabajo y sus datos correspondientes, segun el usuario
 *
 * \param lista[] eTrabajo array trabajo
 * \param tam int tamanio array trabajo
 * \param mascota[] eMascota array mascotas
 * \param tamMasc int tamanio array mascotas
 * \param colores[] eColor array colores
 * \param tamCol int tamanio array colores
 * \param tipos[] eTipos array tipos
 * \param tamTip int tamanio array tipos
 * \param servicios[] eServicio array servicios
 * \param tamSer int tamanio array servicios
  * \param clientes[] eClientes array clientes
 * \param tamCli int tamanio array clientes
 * \param pId int* puntero a id (pata cargar id autoincremental) de trabajos
 * \return int retorna 1 si pudo dar de alta un trabajo, o 0 si no logro dar de alta un trabajo.
 *
 */
int altaTrabajo(eTrabajo lista[], int tam, eMascota mascota[], int tamMasc, eColor colores[], int tamCol, eTipos tipos[], int tamTip, eServicio servicios[],int tamSer, eClientes clientes[], int tamCli, int* pId);

/** \brief Funcion que inicializa todo el array de eTrabajos
 *
 * \param lista[] eTrabajo array trabajos
 * \param tam int tamanio array trabajos
 * \return int retorna 1 si inicializo el array, o 0 si no logro inicializarlo.
 *
 */
int inicializarTrabajos(eTrabajo lista[], int tam);

/** \brief Funcion que imprime solo un trabajo y sus componentes
 *
 * \param trabajo eTrabajo array trabajo
 * \param servicio[] eServicio array servicios
 * \param tamS int tamanio array servicios
 * \param mascota[] eMascota array mascotas
 * \param tamM int tamanio array mascotas
 * \return void no tiene retorno
 *
 */
void mostrarTrabajo(eTrabajo trabajo, eServicio servicio[], int tamS, eMascota mascota[], int tamM);

/** \brief Funcion que imprime los trabajos almacenados en el array Trabajos y sus componentes
 *
 * \param trabajos[] eTrabajo array trabajos
 * \param tamTrab int tamanio array trabajo
 * \param servicios[] eServicio array servicios
 * \param tamS int tamanio array servicio
 * \param mascotas[] eMascota array mascotas
 * \param tamM int tamanio array mascotas
 * \return int retorna 1 si logro imprimir la lista de trabajos y sus componentes, o 0 si no lo imprimio.
 *
 */
int mostrarTrabajos(eTrabajo trabajos[] , int tamTrab, eServicio servicios[], int tamS, eMascota mascotas[], int tamM);

/** \brief Funcion que muestra todas las fechas cargadas en array trabajos
 *
 * \param trabajos[] eTrabajo array trabajos
 * \param tamT int tamanio array trabajos
 * \return int retorna 1 si pudo imprimir las fechas o  si no pudo realizarlo
 *
 */
int mostrarFechas(eTrabajo trabajos[], int tamT);
/** \brief funcion que imprime una sola fecha del array trabajos
 *
 * \param trabajo eTrabajo array trabajo
 * \param tam int tamanio array trabajo
 * \return void no tiene retorno
 *
 */
void mostrarFecha(eTrabajo trabajo, int tam);
