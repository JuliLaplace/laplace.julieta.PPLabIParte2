#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED


typedef struct{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

#endif // SERVICIOS_H_INCLUDED


/** \brief Funcion que carga la descripcion de los servicios cargados en el array Servicios, segun su id
 *
 * \param id int numero (id) del servicio a cargar su descripcion
 * \param servicios[] eServicio array de servicios
 * \param tamServ int cantidad de servicios
 * \param descripcion[] char descripcion a cargar segun id seleccionado
 * \return int retorna 1 si logro cargar la descripcion, o 0 si no pudo realizarlo
 *
 */
int cargarDescServicio(int id, eServicio servicios[], int tamServ, char descripcion[]);

/** \brief Funcion que imprime todos los servicios pertenecientes al array Servicios
 *
 * \param servicios[] eServicio array servicios
 * \param tamSer int total de servicios cargados
 * \return int retorna 1 si pudo imprimir los servicios y sus elementos, o 0 si no logro imprimirlos.
 *
 */
int mostrarServicios(eServicio servicios[] , int tamSer);

/** \brief funcion que imprime un servicio perteneciente al array de servicios
 *
 * \param servicio eServicio array servicios
 * \return void no tiene retorno
 *
 */
void mostrarServicio(eServicio servicio);

