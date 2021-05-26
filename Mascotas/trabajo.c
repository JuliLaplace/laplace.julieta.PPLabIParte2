#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include"trabajo.h"
#include "mascotas.h"
#include"servicios.h"
#include "validaciones.h"
#include"clientes.h"

int inicializarTrabajos(eTrabajo lista[], int tam){
    int inicializarOk=0;
    if(lista!=NULL && tam>0){
        for (int i=0; i<tam; i++){
            lista[i].isEmpty=1;
        }
        inicializarOk=1;
    }
    return inicializarOk;
}

int altaTrabajo(eTrabajo lista[], int tam, eMascota mascota[], int tamMasc, eColor colores[], int tamCol, eTipos tipos[], int tamTip, eServicio servicios[],int tamSer, eClientes clientes[], int tamCli, int* pId){
    int altaOk;
    eTrabajo aux;
    int idMascota;
    int indiceTrabajo;
    int idServicio;
    int indiceMascota;
    int flagAlta=0;

    system ("cls");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("                                   Alta Trabajos\n");
    printf("-------------------------------------------------------------------------------------------\n");

    if(lista!=NULL && tam>0 && pId!=NULL){
        indiceTrabajo = buscarLibreTrabajo(lista, tam);

        if(indiceTrabajo==-1){

            altaOk=0;

        }else{

            printf("ID: %d\n", *pId);

                    printf("\n");
                    mostrarMascotas(mascota, tamMasc, colores, tamCol, tipos, tamTip, clientes, tamCli);

                       if(utn_getNumero(&idMascota,"Ingrese ID de su mascota: ", "ID invalido. ",100,110,5)==0){
                             printf("-------------------------------------------------------------------------------------------\n");
                            printf("ID correctamente cargado.\n");
                             printf("-------------------------------------------------------------------------------------------\n\n");
                        } else {
                            printf("Error en la carga.\n");
                            flagAlta=1;
                           printf("-------------------------------------------------------------------------------------------\n");
                    }


                    indiceMascota = buscarMascota(mascota, tam, idMascota);

                    if(indiceMascota==-1){
                        printf("El ID ingresado no existe. ID ingresado: %d\n", idMascota);
                        flagAlta=1;
                         printf("-------------------------------------------------------------------------------------------\n\n");
                    } else {
                        printf("El id ingresado es el siguiente: %d. \n", idMascota);
                        printf("Pertenece a: \n");

                        mostrarMascota(mascota[indiceMascota], colores, tamCol, tipos, tamTip, clientes, tamCli);

                    }





                    /////////Servicios
                    printf("\n");
                    mostrarServicios(servicios, tamSer);

                    if(utn_getNumero(&idServicio,"Ingrese ID del servicio que desea para su mascota: ", "ID invalido. ",2000,2002,5)==0){
                      printf("ID correctamente cargado.\n");
                       printf("-------------------------------------------------------------------------------------------\n\n");
                    } else {
                        printf("Error en la carga.\n");
                        flagAlta=1;
                    }


                     //////////////FECHA

                    //printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
                     if(utn_getNumero(&aux.fIngreso.dia,"Ingrese dia: ", "Dia invalido. ",1,31,5)==0){
                      printf("Dia correctamente cargado.\n");
                       printf("-------------------------------------------------------------------------------------------\n\n");
                    } else {
                        printf("Error en la carga.\n");
                        flagAlta=1;
                    }
                    if(utn_getNumero(&aux.fIngreso.mes,"Ingrese mes: ", "Mes invalido. ",1,12,5)==0){
                      printf("Mes correctamente cargado.\n");
                       printf("-------------------------------------------------------------------------------------------\n\n");
                    } else {
                        printf("Error en la carga.\n");
                        flagAlta=1;
                    }

                    if(utn_getNumero(&aux.fIngreso.anio,"Ingrese anio (desde 2010 hasta actualidad): ", "Anio invalido. ",2010,2021,5)==0){
                      printf("Anio correctamente cargado.\n");
                       printf("-------------------------------------------------------------------------------------------\n\n");
                    } else {
                        printf("Error en la carga.\n");
                        flagAlta=1;
                    }

                     printf("-------------------------------------------------------------------------------------------\n\n");

                    //////////ID
                if(flagAlta){
                        printf("Error en carga de datos. Vuelva a intentarlo.\n");
                        altaOk=0;
                }else{
                    aux.id = *pId; //le asigno el valor establecido en el main
                    (*pId)++; //lo incremento y lo mando al main con el valor cambiado para proximo id

                    aux.idMascota =idMascota;
                    aux.idServicio = idServicio;
                    lista[indiceTrabajo] = aux;
                    lista[indiceTrabajo].isEmpty=0; //cambio a 0 para que sepa que esta ocupado

                    altaOk=1;
                }
            }
        }

    return altaOk;
 }

 int buscarLibreTrabajo(eTrabajo lista[], int tam){
    int indice=-1;
    if(lista!=NULL && tam>0){
        for(int i = 0; i<tam; i++){
            if(lista[i].isEmpty){
                indice=i;
                break;
            }
        }
    }
    return indice;

}


int mostrarTrabajos(eTrabajo trabajos[] , int tamTrab, eServicio servicios[], int tamS, eMascota mascotas[], int tamM){
    int mostrarTrabajos=0;
    int flag=0;


    if(trabajos!=NULL && tamTrab>0){
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("                                  TRABAJOS          \n");
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("ID Trabajo        Fecha            Servicio          Mascota\n");
                        printf("-------------------------------------------------------------------------------------------\n");
            for(int i = 0; i<tamTrab; i++){
                    if(trabajos[i].isEmpty==0){
                        mostrarTrabajo(trabajos[i], servicios, tamS, mascotas, tamM);
                        printf("\n");
                        flag=1;
                    }
            }

            if(flag){ //marca que nunca se entro al for, y no hay empleados
                mostrarTrabajos=1;
            }else{
                 printf("No hay trabajos realizados a mascotas que mostrar\n");
                mostrarTrabajos=0;

            }


    }
    return mostrarTrabajos;
}


void mostrarTrabajo(eTrabajo trabajo, eServicio servicio[], int tamS, eMascota mascota[], int tamM){
    char descripcionServicio[20];
    char descripcionMascota[20];

    cargarDescServicio(trabajo.idServicio, servicio, tamS, descripcionServicio);
    cargarDescMascota(trabajo.idMascota, mascota, tamM, descripcionMascota);

    printf("%d          %02d/%02d/%d    %15s  %15s\n", trabajo.id, trabajo.fIngreso.dia, trabajo.fIngreso.mes, trabajo.fIngreso.anio, descripcionServicio, descripcionMascota);
}


int mostrarFechas(eTrabajo trabajos[], int tamT){
    int mostrarOk=0;
    int flag=0;


    if(trabajos!=NULL && tamT>0){
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("                         FECHAS          \n");
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("Fecha\n");
                        printf("-------------------------------------------------------------------------------------------\n");
            for(int i = 0; i<tamT; i++){
                    if(trabajos[i].isEmpty==0){
                        mostrarFecha(trabajos[i], tamT);
                        printf("\n");
                        flag=1;
                    }
            }

            if(flag){ //marca que nunca se entro al for, y no hay empleados
                mostrarOk=1;
            }else{
                 printf("No hay fechas que mostrar\n");
                mostrarOk=0;

            }


    }
    return mostrarOk;
}

void mostrarFecha(eTrabajo trabajo, int tam){


    printf("%02d/%02d/%d\n", trabajo.fIngreso.dia, trabajo.fIngreso.mes, trabajo.fIngreso.anio);
}


