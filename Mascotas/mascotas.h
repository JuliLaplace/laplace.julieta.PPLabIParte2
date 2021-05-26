#include"colores.h"
#include"tipos.h"
#include "clientes.h"
#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED



typedef struct{
    int id;  //pk
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int idCliente;
    int isEmpty;

}eMascota;

#endif // MASCOTAS_H_INCLUDED


/** \brief Funcion que inicializa el array de mascotas
 *
 * \param lista[] eMascotas array de mascotas a inicializar
 * \param tam int tamaño del array mascotas
 * \return int retorna 1 si pudo ser incializada o 0 si no pudo ser inicializada
 *
 */
int inicializarMascotas(eMascota lista[], int tam);

/** \brief Funcion que permite la carga datos de una mascota por el usuario
 *
 * \param lista[] eMascota array de mascotas
 * \param tam int tamanio de array de mascotas
 * \param colores[] eColor array de colores
 * \param tamCol int tamanio de array de colores
 * \param tipos[] eTipos array de tipos
 * \param tamTip int tamanio de array de tipos
 * \param pId int* puntero a id (para que se cargue de manera incremental) de mascota a cargar
 * \return int retorna 1 si pudo cargar los datos de la mascota o 0 si no logro realizar la carga.
 *
 */
int altaMascota(eMascota lista[], int tam, eColor colores[], int tamCol, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli, int* pId);


 /** \brief Funcion que busca lugar libre en array de mascotas
  *
  * \param lista[] eMascota array de mascotas
  * \param tam int tamanio de array de mascotas
  * \return int retorna -1 si no encontro lugar libre en el array, o el numero del indice donde esta libre el array
  *
  */
 int buscarLibre(eMascota lista[], int tam);





 /** \brief Funcion que busca mascota seleccionada por usuario
  *
  * \param lista[] eMascota array de mascotas
  * \param tam int tamanio de array de macotas
  * \param id int id de mascota elegida por usuario
  * \return int retorna -1 si no encontro el ID de la mascota seleccionada por el usuario, o retorna numero de indice donde se encuentra mascota en array
  *
  */
 int buscarMascota(eMascota lista[], int tam, int id);

 /** \brief Funcion que muestra una sola mascota, su color, su tipo.
  *
  * \param lista eMascota array de mascotas
  * \param colores[] eColor array de colores
  * \param tamCol int tamanio tamanio de array de colores
  * \param tipos[] eTipos array de tipos
  * \param tamTip int tamanio de array de tipos
  * \param cleintes[] eClientes array de clientes
  * \param tamCli int tamanio de array de clientes
  * \return void no tiene retorno alguno
  *
  */
  void mostrarMascota(eMascota lista, eColor colores[], int tamCol, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli);


 /** \brief funcion que muestra todas las mascotas cargadas en array MAscotas
  *
  * \param lista[] eMascota array mascotas
  * \param tam int tamanio array mascotas
  * \param colores[] eColor array colores
  * \param tamCol int tamanio array colores
  * \param tipos[] eTipos array tipos
  * \param tamTip int tamanio array tipos
    * \param clientes[] eCliente array clientes
  * \param tamCli int tamanio array clientes
  * \return int retorna 1 si logro imprimir lista de mascotas o 0 si no logro realizarlo.
  *
  */
 int mostrarMascotas(eMascota lista[], int tam , eColor colores[], int tamCol, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli);

 /** \brief Funcion que da de baja una mascota seleccionada por usuario
  *
  * \param lista[] eMascota array mascota
  * \param tam int tamanio array mascotas
  * \param colores[] eColor array colores
  * \param tamCol int tamanio array colores
  * \param tipos[] eTipos array tipos
  * \param tamTip int tamanio array tipos
   * \param clientes[] eClientes array clientes
  * \param tamCli int tamanio array clientes
  * \return int retorna 1 si logro dar de baja a la mascota seleccionada o 0 si no se pudo realizar la baja de la mascota
  *
  */
 int bajaMascota (eMascota lista[], int tam, eColor colores[], int tamCol, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli);

/** \brief Funcion que permite modificar un campo (dato) de la mascota seleccionada por el usuario
 *
 * \param lista[] eMascota array de mascotas
 * \param tam int tamanio de mascotas
 * \param color[] eColor array de colores
 * \param tamCol int tamanio array colores
 * \param tipos[] eTipos array tipos
 * \param tamTip int tamanio array tipos
 * \param clientes[] eCliente array clientes
 * \param tamCli int tamanio array clientes
 * \return int retorna 1 si logro realizarse la modificacion, o 0 si no pudo modificarse la mascota seleccionada
 *
 */
int modificarMascota(eMascota lista[], int tam,eColor color[], int tamCol, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli);

 /** \brief Funcion que ordena por tipo y por nombre (alfabeticamente) las mascotas cargadas en el array mascotas
  *
  * \param lista[] eMascota array mascotas
  * \param tam int tamanio array mascotas
  * \param colores[] eColor array colores
  * \param tamCol int tamanio array colores
  * \param tipos[] eTipos array tipos
  * \param tamTip int tamanio array tipos
  * \return int retorna 1 si logro ordenar el array de mascotas, o 0 si no logro ordenarlo.
  *
  */
 int ordenarMascotas(eMascota lista[], int tam, eColor colores[], int tamCol, eTipos tipos[], int tamTip);

 /** \brief Funcion que carga el nombre de una mascota
  *
  * \param id int id de mascota a cargar nombre
  * \param mascotas[] eMascota array mascotas
  * \param tamM int tamanio array mascotas
  * \param nombre[] char lugar donde se carga nombre de la mascota
  * \return int retorna 1 si logro cargar el nombre de la mascota segun el id indicado, o 0 si no logro realizarlo
  *
  */
 int cargarDescMascota(int id, eMascota mascotas[], int tamM, char nombre[]);
