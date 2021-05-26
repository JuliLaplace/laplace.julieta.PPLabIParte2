#include "informes.h"
#include <stdio.h>
#include <stdlib.h>
#include"validaciones.h"


int listarMascotasColor(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli ){

int listarOk;
int idColor;
int flag=0;
char descColor[20];

    system("cls");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("                    Lista de mascotas por color         \n");
    printf("-------------------------------------------------------------------------------------------\n");
    mostrarColores(colores, tamC);
    printf("-------------------------------------------------------------------------------------------\n");

    if(colores!= NULL && tamC>0 && mascotas!=NULL && tam>0){
    }

        if(utn_getNumero(&idColor,"Ingrese ID del color a elegir: ", "ID invalido.  ",5000,5004,5)==0){
                      printf("ID correctamente cargado.\n");
                       printf("-------------------------------------------------------------------------------------------\n");
                    } else {
                        printf("Error en la carga.\n");
                        flag=0;
                    }
            cargarDescColor(idColor, colores, tamC,descColor);
            printf("\n\n");
            printf("-------------------------------------------------------------------------------------------\n");
            printf("                         Listado de Mascotas por color: %s\n         \n", descColor);
            printf("-------------------------------------------------------------------------------------------\n");
            printf("ID        Nombre       Edad        Color      Tipo        Cliente\n");
            printf("-------------------------------------------------------------------------------------------\n");

        for (int i =0; i<tam; i++){
            if(mascotas[i].isEmpty==0 && mascotas[i].idColor==idColor){
                mostrarMascota(mascotas[i], colores, tamC, tipos, tamTip, clientes, tamCli);
                flag=1;
            }
            listarOk=1;
        }
        if(flag==0){
            printf("No hay mascotas que mostrar en el color seleccionado.\n\n");
            listarOk=0;
        }
          return listarOk;
    }



int listarMascotasTipo(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli ){

int listarOk;
int idTipo;
int flag=0;
char descTipo[20];

    system("cls");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("                    Lista de mascotas por Tipo         \n");
    printf("-------------------------------------------------------------------------------------------\n");
    mostrarTipos(tipos, tamTip);
    printf("-------------------------------------------------------------------------------------------\n");

    if(colores!= NULL && mascotas!= NULL && clientes!= NULL && tipos!= NULL &&tamC>0 && tam>0 && tamCli>0 && tamTip>0){


        if(utn_getNumero(&idTipo,"Ingrese ID del tipo a elegir: ", "ID invalido.  ",1000,1004,5)==0){
                      printf("ID correctamente cargado.\n");
                       printf("-------------------------------------------------------------------------------------------\n");
                    } else {
                        printf("Error en la carga.\n");
                        flag=0;
                    }
            cargarDescTipo(idTipo, tipos, tamTip, descTipo);
            printf("\n\n");
            printf("-------------------------------------------------------------------------------------------\n");
            printf("                         Listado de Mascotas por tipo: %s\n         \n", descTipo);
            printf("-------------------------------------------------------------------------------------------\n");
            printf("ID        Nombre       Edad     Color           Tipo        Cliente\n");
            printf("-------------------------------------------------------------------------------------------\n");

        for (int i =0; i<tam; i++){
            if(mascotas[i].isEmpty==0 && mascotas[i].idTipo==idTipo){
                mostrarMascota(mascotas[i], colores, tamC, tipos, tamTip, clientes, tamCli);
                flag=1;
            }
            listarOk=1;
        }
        if(flag==0){
            printf("No hay mascotas que mostrar en el tipo seleccionado.\n\n");
            listarOk=0;
        }
    }
return listarOk;
}

int listarPorTipos(eTipos tipos[], int tamTip, eMascota mascotas[], int tamM, eColor colores[], int tamCol, eClientes clientes[], int tamCli){
    int listarOk=0;
    int flag;

    if(tipos!=NULL && tamTip>0 && mascotas!=NULL && tamM>0){

        for(int t=0; t<tamTip; t++){

            printf("-------------------------------------------------------------------------------------------\n");
            printf("                             Tipo %s          \n", tipos[t].descripcion);
            printf("-------------------------------------------------------------------------------------------\n");
            printf("ID        Nombre       Edad     Color           Tipo        Cliente\n");
            printf("-------------------------------------------------------------------------------------------\n");
            flag=0;
            for(int m=0; m<tamM; m++){
                if(mascotas[m].idTipo == tipos[t].id && mascotas[m].isEmpty==0){
                    mostrarMascota(mascotas[m], colores, tamCol, tipos, tamTip, clientes, tamCli);
                    flag=1;
                    listarOk=1;
                }
            }
             if(flag==0){
                printf("No se encuentran mascotas con el tipo seleccionado.\n\n");
                }
            printf("\n\n");
        }

    }

    return listarOk;
}

int listarMascotasTipoColor(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli ){

int listarOk;
int idTipo;
int idColor;
int flag=0;
char descTipo[20];
char descColor[20];

    system("cls");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("                    Lista de mascotas por Tipo y Color        \n");
    printf("-------------------------------------------------------------------------------------------\n");


    if(colores!= NULL && mascotas!= NULL && clientes!= NULL && tipos!= NULL &&tamC>0 && tam>0 && tamCli>0 && tamTip>0){
        mostrarTipos(tipos, tamTip);
        printf("-------------------------------------------------------------------------------------------\n");

        if(utn_getNumero(&idTipo,"Ingrese ID del tipo a elegir: ", "ID invalido.  ",1000,1004,5)==0){
                      printf("ID correctamente cargado.\n");
                       printf("-------------------------------------------------------------------------------------------\n");
                    } else {
                        printf("Error en la carga.\n");
                        flag=0;
                    }
        mostrarColores(colores, tamC);
        printf("-------------------------------------------------------------------------------------------\n");
        if(utn_getNumero(&idColor,"Ingrese ID del color a elegir: ", "ID invalido.  ",5000,5004,5)==0){
                      printf("ID correctamente cargado.\n");
                       printf("-------------------------------------------------------------------------------------------\n");
                    } else {
                        printf("Error en la carga.\n");
                        flag=0;
                    }
            cargarDescColor(idColor, colores, tamC,descColor);
            cargarDescTipo(idTipo, tipos, tamTip, descTipo);

            printf("\n\n");
            printf("-------------------------------------------------------------------------------------------\n");
            printf("                         Listado de Mascotas por tipo %s y color %s\n         \n", descTipo, descColor);
            printf("-------------------------------------------------------------------------------------------\n");
            printf("ID        Nombre       Edad     Color           Tipo        Cliente\n");
            printf("-------------------------------------------------------------------------------------------\n");

        for (int i =0; i<tam; i++){
            if(mascotas[i].isEmpty==0 && mascotas[i].idTipo==idTipo && mascotas[i].idColor == idColor){
                mostrarMascota(mascotas[i], colores, tamC, tipos, tamTip, clientes, tamCli);
                flag=1;
            }
            listarOk=1;
        }
        if(flag==0){
            printf("No hay mascotas que mostrar en el tipo y color seleccionado.\n\n");
            listarOk=0;
        }
    }
return listarOk;
}



int listarTrabajosPorMascota(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer){

int listarOk;
int idMascota;
int flag=0;
char nombreMascota[20];

    system("cls");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("                    Lista de trabajos segun mascota seleccionada         \n");
    printf("-------------------------------------------------------------------------------------------\n");
    mostrarMascotas(mascotas, tam, colores, tamC, tipos, tamTip, clientes, tamCli);
    printf("-------------------------------------------------------------------------------------------\n");

    if(mascotas!= NULL && tam>0 && colores!=NULL && tamC>0 && tipos!=NULL && tamTip>0 && clientes!=NULL && tamCli>0){
    }

        if(utn_getNumero(&idMascota,"Ingrese ID de mascota: ", "ID invalido.  ",100,1010,5)==0){
                      printf("ID correctamente cargado.\n");
                       printf("-------------------------------------------------------------------------------------------\n");
                    } else {
                        printf("Error en la carga.\n");
                        flag=0;
                    }
            cargarDescMascota(idMascota, mascotas, tam, nombreMascota);
            printf("\n\n");
            printf("-------------------------------------------------------------------------------------------\n");
            printf("                         Listado de trabajos de mascota: %s\n         \n", nombreMascota);
            printf("-------------------------------------------------------------------------------------------\n");
            printf("ID Trabajo        Fecha            Servicio          Mascota\n");
            printf("-------------------------------------------------------------------------------------------\n");

        for (int i =0; i<tam; i++){
            if(trabajos[i].isEmpty==0 && trabajos[i].idMascota==idMascota){
                mostrarTrabajo(trabajos[i],servicios, tamSer, mascotas, tam);

                flag=1;
            }
            listarOk=1;
        }
        if(flag==0){
            printf("No hay trabajos que mostrar en la mascota seleccionada.\n\n");
            listarOk=0;
        }
          return listarOk;
    }



int listarMascotasPorServicios(eMascota mascotas[], int tam, eColor colores[], int tamC, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamSer){

int listarOk;
int idServicio;
int flag=0;
char descripcionServicio[20];

    system("cls");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("                    Lista de Mascotas segun servicio         \n");
    printf("-------------------------------------------------------------------------------------------\n");
    mostrarServicios(servicios, tamSer);
    printf("-------------------------------------------------------------------------------------------\n");

    if(mascotas!= NULL && tam>0 && colores!=NULL && tamC>0 && tipos!=NULL && tamTip>0 && clientes!=NULL && tamCli>0 && servicios!=NULL && tamSer>0){
    }

        if(utn_getNumero(&idServicio,"Ingrese ID de servicio a consultar: ", "ID invalido.  ",100,1010,5)==0){
                      printf("ID correctamente cargado.\n");
                       printf("-------------------------------------------------------------------------------------------\n");
                    } else {
                        printf("Error en la carga.\n");
                        flag=0;
                    }
            cargarDescServicio(idServicio, servicios, tamSer, descripcionServicio);
            printf("\n\n");
            printf("-------------------------------------------------------------------------------------------\n");
            printf("                         Listado de Mascotas de servicio: %s\n         \n", descripcionServicio);
            printf("-------------------------------------------------------------------------------------------\n");
            printf("ID        Nombre       Edad       Color         Tipo         Cliente\n");
            printf("-------------------------------------------------------------------------------------------\n");

        for (int i =0; i<tam; i++){
            if(mascotas[i].isEmpty==0 && trabajos[i].idServicio == idServicio){
                mostrarMascota(mascotas[i], colores, tamC, tipos, tamTip, clientes, tamCli);

                flag=1;
            }
            listarOk=1;
        }
        if(flag==0){
            printf("No hay servicios que mostrar en la mascota seleccionada.\n\n");
            listarOk=0;
        }
          return listarOk;
    }


int totalListarServiciosFecha( eServicio servicios[], int tamSer, eTrabajo trabajos[], int tamTrab){
    int todoOk=0;
    eFecha fechaBuscada;
    int contador;

    if(servicios!=NULL && tamSer>0 && trabajos!=NULL && tamTrab>0)
    {
        mostrarFechas(trabajos, tamTrab);
        printf("Ingrese la fecha que quiere visualizar(dd/mm/aaaa): ");
        scanf("%d/%d/%d",&fechaBuscada.dia,&fechaBuscada.mes,&fechaBuscada.anio);
        printf("\n");

        for(int s=0; s<tamSer; s++)
        {
            contador=0;
            for(int t=0; t<tamTrab; t++)
            {
                if(servicios[s].id == trabajos[t].idServicio && trabajos[t].isEmpty==0 && comparaFechas(fechaBuscada,trabajos[t].fIngreso))
                {
                    contador++;
                }
            }
            printf("En la fecha ingresada se registraron: %d  %s\n",contador,servicios[s].descripcion);
        }
        printf("\n");
        todoOk=1;
    }
    return todoOk;
}

int comparaFechas(eFecha f1, eFecha f2){
    int esIgual = 0;
    if(f1.dia == f2.dia && f1.mes == f2.mes && f1.anio == f2.anio)
    {
        esIgual = 1;
    }
    return esIgual;
}

