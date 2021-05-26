#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];////char descripcion antes
}eColor;


#endif // COLORES_H_INCLUDED

/** \brief funcion que carga la descripcion de cada color segun su ID
 *
 * \param id int numero entero (id) a buscar.
 * \param colores[] eColor array de colores
 * \param tamCol int tamanio de colores
 * \param nombre[] char descripcion del color
 * \return int retorna 1 si pudo guardar la descripcion del color seleccionado o 0 si no pudo realizarlo.
 *
 */
int cargarDescColor(int id, eColor colores[], int tamCol, char nombre[]);


/** \brief Funcion que muestra todos los colores pertenecientes al programa
 *
 * \param colores[] eColor array de colores
 * \param tamCol int tamanio de colores
 * \return int retorna 1 si pudo ser impresa la lista, 0 si no pudo realizar la impresion.
 *
 */
int mostrarColores(eColor colores[] , int tamCol);


/** \brief Funcion que imprime un color
 *
 * \param color eColor array de colores
 * \return void no tiene retorno
 *
 */
void mostrarColor(eColor color);
