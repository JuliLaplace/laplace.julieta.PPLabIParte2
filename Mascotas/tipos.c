#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include"colores.h"
#include "menu.h"
#include"tipos.h"



int cargarDescTipo(int id, eTipos tipos[], int tamTip, char nombre[]){
    int cargarOk=0;
    if(tipos!=NULL && tamTip>0 && nombre!=0 && id>=1000 && id<=1004){
        for (int i=0; i<tamTip; i++){
            if(tipos[i].id==id){
                strcpy(nombre, tipos[i].descripcion);
                cargarOk=1;
                break;

            }
        }
    }


    return cargarOk;
}

int mostrarTipos(eTipos tipos[] , int tamTip){
    int mostrarTipos=0;
    if(tipos!=NULL && tamTip>0){
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("          TIPOS          \n");
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("ID           DESCRIPCION\n");
                        printf("-------------------------------------------------------------------------------------------\n");
            for(int i = 0; i<tamTip; i++){
                mostrarTipo(tipos[i]);

            }


    }
    return mostrarTipos;
}


void mostrarTipo(eTipos tipos){
    printf("%d      %10s\n", tipos.id , tipos.descripcion);
}
