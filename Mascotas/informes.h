#include"mascotas.h"
#include"trabajo.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


/** \brief Funcion que flitra mascotas por color seleccionado por usuario
 *
 * \param mascotas[] eMascota array mascotas
 * \param tam int tamanio array mascotas
 * \param colores[] eColor array colores
 * \param tamC int tamanio array colores
 * \param tipos[] eTipos array tipos
 * \param tamTip int tamanio array tipos
 * \param clientes[] eClientes array clientes
 * \param tamCli int tamanio array clientes
 * \return int retorna 1 si logro listarlo o 0 si no pudo realizarlo
 *
 */
int listarMascotasColor(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli );


/** \brief Funcion que lista las mascotas por seleccion de usuario (tipo)
 *
 * \param mascotas[] eMascota array mascotas
 * \param tam int tamanio array mascotas
 * \param colores[] eColor array colores
 * \param tamC int tamanio array colores
 * \param tipos[] eTipos array tipos
 * \param tamTip int tamanio array tipos
 * \param clientes[] eClientes array clientes
 * \param tamCli int tamanio array clientes
 * \return int retorna 1 si pudo imprimir la lista de mascotas por tipo o 0 si no pudo realizarlo
 *
 */
int listarMascotasTipo(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli);


/** \brief funcion que ordena por cada tipo de mascota su contenido
 *
 * \param tipos[] eTipos array tipos
 * \param tamTip int tamanio array tipos
 * \param mascotas[] eMascota array mascotas
 * \param tamM int tamanio array mascoas
 * \param colores[] eColor array colores
 * \param tamCol int tamanio array colores
 * \param clientes[] eClientes array clientes
 * \param tamCli int tamanio array clientes
 * \return int retorna 1 si logro imprimir la lista de tipos o 0 si no pudo realizarlo
 *
 */
int listarPorTipos(eTipos tipos[], int tamTip, eMascota mascotas[], int tamM, eColor colores[], int tamCol, eClientes clientes[], int tamCli);



/** \brief Funcion que lista los trabajos reaizados por mascota seleccionada
 *
 * \param mascotas[] eMascota array mascotas
 * \param tam int tamanio array mascotas
 * \param colores[] eColor array colores
 * \param tamC int tamanio array colores
 * \param tipos[] eTipos array tipos
 * \param tamTip int tamanio array tipos
 * \param clientes[] eClientes array clientes
 * \param tamCli int tamanio array clientes
 * \param trabajos[] eTrabajo array trabajos
 * \param tamT int tamanio array trabajos
 * \param servicios[] eServicio array servicios
 * \param tamSer int tamanio array servicios
 * \return int retorna 1 si logro imprimir la lista por trabajos de cada mascota o 0 si no logro realizarlo
 *
 */
int listarTrabajosPorMascota(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer);

/** \brief Funcion que lista las mascotas que se encuentran en servicio seleccionado por el usuario
 *
 * \param mascotas[] eMascota array mascotas
 * \param tam int tamanio array mascota
 * \param colores[] eColor array color
 * \param tamC int tamanio array color
 * \param tipos[] eTipos array tipos
 * \param tamTip int tamanio array tipos
 * \param clientes[] eClientes array clientes
 * \param tamCli int tamanio array clientes
 * \param trabajos[] eTrabajo array trabajos
 * \param tamT int tamanio array trabajos
 * \param servicios[] eServicio array servicios
 * \param tamSer int tamanio array servicios
 * \return int retorna 1 si logro imprimir la lista de mascotas por el servicio seleccionado, o 0 si no logro realizarlo.
 *
 */
int listarMascotasPorServicios(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer);
/** \brief Funcion que lista los servicios por fecha
 *
 * \param servicios[] eServicio array servicios
 * \param tamSer int tamanio array servicios
 * \param trabajos[] eTrabajo array trabajos
 * \param tamTrab int tamanio array trabajos
 * \return int retorna 1 si logrio imprimir los servcios por fecha, o 0 si no logro realizarlo
 *
 */
int totalListarServiciosFecha( eServicio servicios[], int tamSer, eTrabajo trabajos[], int tamTrab);

/** \brief Funcion que compaa dos fechas y su igualdad
 *
 * \param f1 eFecha primer array de fechas a coparar
 * \param f2 eFecha segundo array de fechas a comprarar
 * \return int retorna 1 si las fechas son iguales o 0 si son distintas
 *
 */
int comparaFechas(eFecha f1, eFecha f2);
/** \brief funcion que lista las mascotas por tipo y color seleccionado por usuario
 *
 * \param mascotas[] eMascota array mascotas
 * \param tam int tamanio array mascotas
 * \param colores[] eColor array colores
 * \param tamC int tamanio array colores
 * \param tipos[] eTipos array tipos
 * \param tamTip int tamanio array tipos
 * \param clientes[] eClientes array clientes
 * \param tamCli int tamanio array clientes
 * \return int retorna 1 si logro imprimir la lista o 0 si no logro imprimir
 *
 */
int listarMascotasTipoColor(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli);
