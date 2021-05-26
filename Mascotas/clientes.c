#include"clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int cargarNombreCliente(int id, eClientes lista[], int tamCli, char nombre[]){
    int cargarOk=0;
    if(lista!=NULL && tamCli>0 && nombre!=0 && id>=2000 && id<=2004){
        for (int i=0; i<tamCli; i++){
            if(lista[i].id==id){
                strcpy(nombre, lista[i].nombreCliente);
                cargarOk=1;
                break;

            }
        }
    }


    return cargarOk;
}






int mostrarClientes(eClientes lista[] , int tamCli){
    int todoOk=0;
    if(lista!=NULL && tamCli>0){
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("          CLIENTES          \n");
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("ID           NOMBRE       SEXO\n");
                        printf("-------------------------------------------------------------------------------------------\n");
            for(int i = 0; i<tamCli; i++){
                mostrarCliente(lista[i]);
                todoOk=1;
            }


    }
    return todoOk;
}


void mostrarCliente (eClientes cliente){
    printf("%d      %10s     %c\n", cliente.id, cliente.nombreCliente, cliente.sexo);
}
