#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>

int arrayLetras(char palabra[]){
    int arrayOk=1;
    for(int i = 0; palabra[i] != '\0'; i++)
    {
        if((palabra[i] != ' ') && (palabra[i] < 'a' || palabra[i] > 'z') && (palabra[i] < 'A' || palabra[i] > 'Z'))
        {
            arrayOk= 0;
        }
    }
    return arrayOk;
}




int esNumerico(char str[])
{
    int i=0;
    int retorno = 1;
    if (str != NULL && strlen (str) > 0){
        while (str[i] != '\0' ){
            if (str[i] < '0' || str[i] > '9' ){
                retorno = 0;
                break ;
            }
            i++;
        }
}
return retorno;
}


int getInt(int * pResultado){
    int ret=-1;
    char buffer[64];
    scanf( "%s" ,buffer);
    if (esNumerico(buffer)){
        *pResultado = atoi(buffer);
        ret=1;
    }
    return ret;
}




int utn_getNumero( int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos){
    int ret;
    int num;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
        while (reintentos>0){
            printf(mensaje);
            if (getInt(&num)==1){
                if (num<=maximo && num>=minimo)
                break ;
            }

            fflush(stdin);
            reintentos--;
            printf(mensajeError);
        }
        if (reintentos==0){
            ret=-1;
        }
        else{
            ret=0;
            *pResultado = num;
        }
}
return ret;
}

