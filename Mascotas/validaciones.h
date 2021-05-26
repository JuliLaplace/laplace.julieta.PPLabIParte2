#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED


/** \brief Funcion que verifica que una cadena de caracteres contenga solo caracteres alfabeticos
 *
 * \param palabra[] char cadena de caracteres a verificar
 * \return int retorna 0 si solo contiene letras, 0 si no son solo letras.
 *
 */
int arrayLetras(char palabra[]);


/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 0 si es númerico y 1 si no lo es
 *
 */
int esNumerico(char str[]);




/** \brief
 *
 * \param pResultado int*
 * \return int
 *
 */
int getInt(int* pResultado);

/** \brief Funcion que verifica si los datos ingresados son numericos.
 *
 * \param pResultado int* Puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto.
 * \param mensaje char* Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola.
 * \param mensajeError char* Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
 * \param minimo int Valor mínimo admitido.
 * \param maximo intValor máximo admitido (inclusive)
 * \param reintentos int cantidad de veces que el usuario puede reintentar ingresar un dato
 * \return int devuelde 0 si el valor ingresado es valido, 1 si no es valido.
 *
 */
int utn_getNumero( int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);



