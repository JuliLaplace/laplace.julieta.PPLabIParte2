#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include"colores.h"
#include "menu.h"



int cargarDescColor(int id, eColor colores[], int tamCol, char nombre[]){
    int cargarOk=0;
    if(colores!=NULL && tamCol>0 && nombre!=0 && id>=5000 && id<=5004){
        for (int i=0; i<tamCol; i++){
            if(colores[i].id==id){
                strcpy(nombre, colores[i].nombreColor);
                cargarOk=1;
                break;

            }
        }
    }


    return cargarOk;
}

int mostrarColores(eColor colores[] , int tamCol){
    int mostrarColores=0;
    if(colores!=NULL && tamCol>0){
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("          COLORES          \n");
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("ID           DESCRIPCION\n");
                        printf("-------------------------------------------------------------------------------------------\n");
            for(int i = 0; i<tamCol; i++){
                mostrarColor(colores[i]);
                mostrarColores=1;
            }


    }
    return mostrarColores;
}


void mostrarColor (eColor color){
    printf("%d      %10s\n", color.id, color.nombreColor);
}




