#include "colores.h"

#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];////char descripcion antes
}eTipos;


#endif // TIPOS_H_INCLUDED


/** \brief Funcion que carga la descripcion de un tipo segun id ingresado
 *
 * \param id int numero(id) de tipo a cargar descripcion
 * \param tipos[] eTipos array tipos
 * \param tamTip int tamanio tipos
 * \param nombre[] char nombre de tipo segun id cargado.
 * \return int retorna 1 si logro cargar el nombre del tipo segun id, o 0 si no logro cargarlo.
 *
 */
int cargarDescTipo(int id, eTipos tipos[], int tamTip, char nombre[]);


 /** \brief  Funcion que imprime todos los campos pertenecientes al array tipos
  *
  * \param tipos[] eTipos arrya tipos
  * \param tamTip int tamanio array tipos
  * \return int retorna 1 si logro imprimir, o 0 si no logro imprimir el array y sus datos
  *
  */
 int mostrarTipos(eTipos tipos[] , int tamTip);



/** \brief Funcion que muestra solo un tipo y su caracteristica
 *
 * \param tipos eTipos array tipo
 * \return void no tiene retorno
 *
 */
void mostrarTipo(eTipos tipos);



