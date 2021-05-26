#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED


typedef struct{
    int id;
    char nombreCliente[20];
    char sexo;
}eClientes;

#endif // CLIENTES_H_INCLUDED


/** \brief funcion que carga el nombre del clilente segun su ID
 *
 * \param id int numero entero (id) a buscar.
 * \param lista[] eCliente array de clientes
 * \param tamCli int tamanio de array clientes
 * \param nombre[] char de nombre del cliente
 * \return int retorna 1 si pudo guardar el nombre del cliente seleccionado o 0 si no pudo realizarlo.
 *
 */
int cargarNombreCliente(int id, eClientes lista[], int tamCli, char nombre[]);



/** \brief Funcion que imprime el array de clientes
 *
 * \param lista[] eClientes array de clientes
 * \param tamCli int tamanio de array clientes
 * \return int retorna 1 si pudo imprimir clientes, o 0 si no pudo realizarlo
 *
 */
int mostrarClientes(eClientes lista[] , int tamCli);

/** \brief Funcion que imprime un solo cliente
 *
 * \param cliente eClientes lista de clientes
 * \return void no tiene retorno
 *
 */
void mostrarCliente(eClientes cliente);
