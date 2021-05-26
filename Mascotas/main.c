#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "menu.h"
#include "tipos.h"
#include "colores.h"
#include"mascotas.h"
#include"servicios.h"
#include"trabajo.h"
#include"informes.h"


#define TAMMASC 10
#define TAMCOL 5
#define TAMTIP 5
#define TAMSER 3
#define TAMTRAB 5
#define TAMCLI 5

int main(){

    eTipos tipos[TAMTIP]={
        {1000, "Ave"},
        {1001, "Perro"},
       {1002, "Gato"},
        {1003, "Roedor"},
        {1004, "Pez"},
    };
     eColor colores[TAMCOL]={
        {5000, "Negro"},
        {5001, "Blanco"},
       {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"},
    };

    eServicio servicios[TAMSER]={
         {2000, "Corte", 250},
        {2001, "Desparasitado", 300},
       {2002, "Castrado", 400},
    };

    eClientes clientes[TAMCLI]={
        {2000, "Julieta", 'f'},
        {2001, "Andres", 'm'},
        {2002, "Matias", 'm'},
        {2003, "Adriana", 'f'},
        {2004, "Florencia", 'f'},
    };

    int idMascota = 100;
    int idTrabajos = 3003;
    eMascota mascotas[TAMMASC];
    eTrabajo trabajos [TAMTRAB];
    int flagAltaMascota=0;
    char salir = 'n';

    inicializarMascotas(mascotas, TAMMASC);
    inicializarTrabajos(trabajos, TAMTRAB);


    do{

        switch(menu()){
        case 'A':
            if(altaMascota(mascotas, TAMMASC, colores, TAMCOL, tipos, TAMTIP, clientes, TAMCLI, &idMascota)){

                printf("                            Alta exitosa.\n");

                 printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
                flagAltaMascota=1;
            }else{
                printf("                No hay lugar para agregar mascotas.\n");
                 printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
            system("pause");
            break;
        case 'B':
            if(flagAltaMascota && modificarMascota(mascotas, TAMMASC, colores, TAMCOL, tipos, TAMTIP, clientes, TAMCLI)){

                printf("                            Modificacion exitosa.\n");
                 printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            } else if (flagAltaMascota==0){

                printf("                    Primero de de alta una mascota.\n");
                 printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }

            system("pause");
            break;
        case 'C':
            if(flagAltaMascota && bajaMascota(mascotas, TAMMASC, colores, TAMCOL, tipos, TAMTIP, clientes, TAMCLI)){
                printf("                        Baja exitosa.\n");
                 printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");

            } else if(flagAltaMascota==0){
                 printf("                       Primero de de alta una mascota.\n");
                printf("-------------------------------------------------------------------------------------------\n");
                 printf("\n");
            }

            system("pause");
            break;
        case 'D':

            if(flagAltaMascota && ordenarMascotas(mascotas, TAMMASC, colores, TAMCOL, tipos, TAMTIP)){
                system("cls");
                mostrarMascotas(mascotas, TAMMASC, colores, TAMCOL, tipos, TAMTIP, clientes, TAMCLI);
            }else if(flagAltaMascota==0){
                printf("                        Primero de de alta una mascota.\n");
                 printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }

            system("pause");
            break;
        case 'E':
            system("cls");
            if(flagAltaMascota && mostrarTipos(tipos, TAMTIP)){

                    mostrarTipos(tipos, TAMTIP);
                    printf("Tipos listados.\n");
                     printf("-------------------------------------------------------------------------------------------\n");
                    printf("\n");
            } else if(flagAltaMascota==0){
                 printf("-------------------------------------------------------------------------------------------\n");
                printf("                        Primero de de alta una mascota.\n");
                printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");

            }
            system("pause");
            break;
        case 'F':
            system("cls");
            if(flagAltaMascota && mostrarColores(colores, TAMCOL)){

                    printf("                            Colores listados.\n");
                    printf("-------------------------------------------------------------------------------------------\n");
                    printf("\n");
            } else if(flagAltaMascota==0){
                 printf("-------------------------------------------------------------------------------------------\n");
                printf("                        Primero de de alta una mascota.\n");
                 printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
            system("pause");
            break;
        case 'G':
            system("cls");
            if(flagAltaMascota && mostrarServicios(servicios, TAMSER)){

                    mostrarServicios(servicios, TAMSER);
                     printf("-------------------------------------------------------------------------------------------\n");
                    printf("                           Servicios listados.\n");
                     printf("-------------------------------------------------------------------------------------------\n");
                    printf("\n");
            } else if(flagAltaMascota==0){
                 printf("-------------------------------------------------------------------------------------------\n");
                printf("                        Primero de de alta una mascota.\n");
                 printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
            system("pause");
            break;
        case 'H':
               if(flagAltaMascota && altaTrabajo(trabajos, TAMTRAB, mascotas, TAMMASC, colores, TAMCOL, tipos, TAMTIP, servicios, TAMSER, clientes, TAMCLI, &idTrabajos)){
                    printf("                        Alta trabajos exitoso.\n");
                     printf("-------------------------------------------------------------------------------------------\n");
                    printf("\n");
                }else if(flagAltaMascota==0){
                    printf("                    Primero de de alta una mascota.\n");
                     printf("-------------------------------------------------------------------------------------------\n");
                    printf("\n");
                }
            system("pause");
            break;
        case 'I':
            if(flagAltaMascota && mostrarTrabajos(trabajos, TAMTRAB, servicios, TAMSER, mascotas, TAMMASC)){
                    system("cls");
                mostrarTrabajos(trabajos, TAMTRAB, servicios, TAMSER, mascotas, TAMMASC);

                printf("                        Trabajos listados.\n");
                 printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }else if(flagAltaMascota==0){
                printf("                Primero de de alta un empleado.\n");
                 printf("-------------------------------------------------------------------------------------------\n");
                printf("\n");
            }
            system("pause");
            break;
        case 'J':
             if(flagAltaMascota){
                    system("cls");
                    printf("-----------------------------------------------------------------------------\n");
                    printf("                            Informes.\n");
                    switch(subMenuInformes()){
                    case 1:
                        if(listarMascotasColor(mascotas, TAMMASC, colores,TAMCOL, tipos, TAMTIP, clientes, TAMCLI)){
                            printf("-----------------------------------------------------------------------------\n");
                            printf("                    Listar mascotas por color exitoso.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        } else {
                            printf("-----------------------------------------------------------------------------\n");
                            printf("                    No se pudo listar mascotas por color.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        }

                        break;
                    case 2:
                        system("cls");
                        if(listarMascotasTipo(mascotas, TAMMASC, colores, TAMCOL, tipos, TAMTIP, clientes, TAMCLI)){
                              printf("-----------------------------------------------------------------------------\n");
                            printf("                        Listar mascotas por tipo exitoso.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        } else {
                          printf("-----------------------------------------------------------------------------\n");
                            printf("                        Error en listar Mascotas.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        }

                        break;
                    case 3:
                        system("cls");

                            printf("-----------------------------------------------------------------------------\n");
                            printf("                        Listar mascotas con menor edad.\n\n");
                            printf("-----------------------------------------------------------------------------\n");

                        break;
                    case 4:
                        if(listarPorTipos(tipos, TAMTIP, mascotas, TAMMASC, colores,TAMCOL,clientes, TAMCLI)){
                            printf("-----------------------------------------------------------------------------\n");
                            printf("                       Listado de mascotas por tipo exitoso.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        } else{
                            printf("-----------------------------------------------------------------------------\n");
                            printf("                      Error en listar tipos de mascota.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        }

                        break;
                    case 5:
                        if(listarMascotasTipoColor(mascotas, TAMMASC, colores, TAMCOL, tipos, TAMTIP, clientes, TAMCLI)){
                            printf("-----------------------------------------------------------------------------\n");
                            printf("                      Listado de mascotas por tipo y color exitoso.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        } else{
                            printf("-----------------------------------------------------------------------------\n");
                            printf("                      Error en listar mascotas por tipo y color.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        }
                        break;
                    case 6:
                            printf("-----------------------------------------------------------------------------\n");
                            printf("                        Listar color con mas cantidad de mascotas.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        break;
                    case 7:
                         if(listarTrabajosPorMascota(mascotas, TAMMASC, colores, TAMCOL, tipos, TAMTIP, clientes, TAMCLI, trabajos, TAMTRAB, servicios, TAMSER)){

                            printf("-----------------------------------------------------------------------------\n");
                            printf("             Listar trabajos por mascota exitoso.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        } else{
                            printf("-----------------------------------------------------------------------------\n");
                            printf("                      Error en listar trabajos por mascota.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        }
                        break;
                    case 8:
                            printf("-----------------------------------------------------------------------------\n");
                            printf("                      Suma de importes de servicios mascotas.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        break;
                    case 9:
                         if(listarMascotasPorServicios(mascotas, TAMMASC, colores, TAMCOL, tipos, TAMTIP, clientes, TAMCLI, trabajos, TAMTRAB, servicios, TAMSER)){

                            printf("-----------------------------------------------------------------------------\n");
                            printf("             Listar servicios por mascota exitoso.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        } else{
                            printf("-----------------------------------------------------------------------------\n");
                            printf("                      Error en listar servicios por mascota.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        }
                        break;
                    case 10:
                        if(totalListarServiciosFecha(servicios, TAMSER, trabajos, TAMTRAB)){

                            printf("-----------------------------------------------------------------------------\n");
                            printf("             Listar cantidad de servicios realizador por fecha exitoso.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        } else{
                            printf("-----------------------------------------------------------------------------\n");
                            printf("                      Error en listar servicios por fecha.\n\n");
                            printf("-----------------------------------------------------------------------------\n");
                        }
                        break;
                    }
            }else if(flagAltaMascota==0){
               printf("                 Primero de de alta una mascota.\n\n");
                printf("-----------------------------------------------------------------------------\n");
            }

            system("pause");
            break;
        case 'K':
             salir = 's';
            break;


        default:
            printf("El valor ingresado no es valido.\n");
             printf("-------------------------------------------------------------------------------------------\n");
            printf("\n");
            system("pause");
        }



    } while(salir == 'n');
    return 0;
}
