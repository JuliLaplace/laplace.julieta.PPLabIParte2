#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include"servicios.h"




int cargarDescServicio(int id, eServicio servicios[], int tamServ, char descripcion[]){
    int cargarOk=0;
    if(servicios!=NULL && tamServ>0 && descripcion!=NULL && id>=2000 && id<=2002){
        for (int i=0; i<tamServ; i++){
            if(servicios[i].id==id){
                strcpy(descripcion, servicios[i].descripcion);
                cargarOk=1;
                break;

            }
        }
    }


    return cargarOk;
}

int mostrarServicios(eServicio servicios[] , int tamSer){
    int mostrarServicios=0;
    if(servicios!=NULL && tamSer>0){
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("                                 SERVICIOS          \n");
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("ID           DESCRIPCION        PRECIO\n");
                        printf("-------------------------------------------------------------------------------------------\n");
            for(int i = 0; i<tamSer; i++){
                mostrarServicio(servicios[i]);
                printf("\n");
            }
            printf("-------------------------------------------------------------------------------------------\n");


    }
    return mostrarServicios;
}

void mostrarServicio(eServicio servicio){
    printf("%d     %15s           %d\n", servicio.id, servicio.descripcion, servicio.precio);
}

/*
int harcodearServcios(eServicio lista[], int tam, int cant){
    int cantidad=0;

    if(lista!= NULL && tam>0 && cant >0 && cant <tam){
        for (int i =0; i<cant; i++){
            lista[i].id = servicios[i].id
            strcpy(lista[i].descripcion, servicios[i].descripcion);
            lista[i].precio = servicios[i].precio;
            cantidad++;

        }
    }
    return cantidad;
}
*/
