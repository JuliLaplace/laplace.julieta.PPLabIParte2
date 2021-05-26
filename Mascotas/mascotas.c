#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "colores.h"
#include"tipos.h"
#include"menu.h"
#include "validaciones.h"
#include"clientes.h"
#include<string.h>


int inicializarMascotas(eMascota lista[], int tam){
    int inicializarOk=0;
    if(lista!=NULL && tam>0){
        for (int i=0; i<tam; i++){
            lista[i].isEmpty=1;
        }
        inicializarOk=1;
    }
    return inicializarOk;
}

int altaMascota(eMascota lista[], int tam, eColor colores[], int tamCol, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli, int* pId){
    int altaOk;
    eMascota aux;
    int idColor;
    int idTipo;
    int indice;
    int idCliente;
    int flagCarga=0;

    system ("cls");
     printf("-------------------------------------------------------------------------------------------\n");
    printf("                                Alta mascota\n");
     printf("-------------------------------------------------------------------------------------------\n");

    if(lista!=NULL && tam>0 && pId!=NULL){
        indice = buscarLibre(lista, tam);
        if(indice==-1){

            altaOk=0;

        }else{

            printf("ID: %d\n", *pId);
            ////////////////NOMBRE
                    printf("Ingrese nombre de la mascota: ");
                    fflush(stdin);
                    gets(aux.nombre);
                    while(strlen(aux.nombre)>20 || !arrayLetras(aux.nombre)){
                        printf("Error en carga de nombre. Ingrese nombre valido de mascota: ");
                        fflush(stdin);
                        gets(aux.nombre);
                    }
                     printf("Nombre correctamente cargado.\n");
                      printf("-------------------------------------------------------------------------------------------\n");
            //////////////EDAD
                    if(utn_getNumero(&aux.edad,"Ingrese edad de su mascota: ", "Edad invalida. ",0,30,3)==0){
                      printf("Edad correctamente cargada.\n");
                    } else {
                        printf("Error en la carga.\n");
                        flagCarga=1;
                    }

            /////////colores

                    printf("\n");
                    mostrarColores(colores, tamCol);
                    printf("-------------------------------------------------------------------------------------------\n");
                    if(utn_getNumero(&idColor,"Ingrese ID del color de su mascota: ", "ID invalido.  ",5000,5004,5)==0){
                      printf("ID correctamente cargado.\n");
                       printf("-------------------------------------------------------------------------------------------\n");
                    } else {
                        printf("Error en la carga.\n");
                        flagCarga=1;
                    }


            /////////tipos

                    printf("\n");
                    mostrarTipos(tipos, tamTip);
                     printf("-------------------------------------------------------------------------------------------\n");
                     if(utn_getNumero(&idTipo,"Ingrese ID del tipo de su mascota: ", "ID invalido. ",1000,1004,5)==0){
                      printf("ID correctamente cargado.\n");
                       printf("-------------------------------------------------------------------------------------------\n");
                    } else {
                        printf("Error en la carga.\n");
                        flagCarga=1;
                    }

            //cliente
                    printf("\n");
                    mostrarClientes(clientes, tamCli);
                     printf("-------------------------------------------------------------------------------------------\n");
                     if(utn_getNumero(&idCliente,"Ingrese ID peteneciente al dueño de la mascota: ", "ID invalido. ",2000,2004,5)==0){
                      printf("ID correctamente cargado.\n");
                       printf("-------------------------------------------------------------------------------------------\n");
                    } else {
                        printf("Error en la carga.\n");
                        flagCarga=1;
                    }


            //////////LEGAJO
            if(flagCarga){
                printf("Error en carga de datos. Vuelva a intentarlo.\n");
                altaOk=0;
            }else{

                    aux.id = *pId; //le asigno el valor establecido en el main
                    (*pId)++; //lo incremento y lo mando al main con el valor cambiado para proximo id

                    aux.idColor =idColor;
                    aux.idTipo = idTipo;
                    aux.idCliente = idCliente;
                    lista[indice] = aux;
                    lista[indice].isEmpty=0; //cambio a 0 para que sepa que esta ocupado

                    altaOk=1;
                }
            }
        }

    return altaOk;
 }

 int buscarLibre(eMascota lista[], int tam){
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

int buscarMascota(eMascota lista[], int tam, int id){

    int indiceMascota=-1;
    if(lista!= NULL && tam>0){
     for (int i=0; i<tam; i++){
        if(lista[i].id == id && lista[i].isEmpty ==0){
            indiceMascota=i;
            break;
                }
        }

    }
    return indiceMascota;
}

int bajaMascota (eMascota lista[], int tam, eColor colores[], int tamCol, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli){
    int bajaOk=0;
    int id;
    int indiceMascota;
    char confirma;

    system("cls");
    printf("-----------------------------------------------------------------------------\n");
    printf("                           Baja Mascota          \n");
    printf("-----------------------------------------------------------------------------\n");
     if(lista!=NULL && tam>0){
        indiceMascota = buscarMascota(lista, tam, id);
        mostrarMascotas(lista, tam, colores, tamCol, tipos, tamTip, clientes, tamCli);
        printf("-----------------------------------------------------------\n");
        if(utn_getNumero(&id,"Ingrese ID de su mascota: ", "ID invalido. ",100,110,5)==0){
            printf("ID correctamente cargado.\n");
            } else {
                printf("Error en la carga.\n");
                    }

        indiceMascota = buscarMascota(lista, tam, id);

        if(indiceMascota==-1){
            printf("El ID ingresado no existe. ID ingresado: %d\n", id);
        } else {
            printf("El id ingresado es el siguiente: %d. \n", id);
            printf("Pertenece a: \n");
            mostrarMascota(lista[indiceMascota], colores, tamCol, tipos, tamTip, clientes, tamCli);
            printf("Desea dar de baja mascota? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's'){
                lista[indiceMascota].isEmpty=1;
                bajaOk=1;
            }else{
                printf("Baja cancelada.\n");
            }

        }


     }
    return bajaOk;
}


void mostrarMascota(eMascota lista, eColor colores[], int tamCol, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli){
    char descripcionColor[20];
    char descripcionTipo[20];
    char nombreCliente[20];
    cargarDescColor(lista.idColor, colores, tamCol, descripcionColor);
    cargarDescTipo(lista.idTipo, tipos, tamTip, descripcionTipo);
    cargarNombreCliente(lista.idCliente, clientes, tamCli, nombreCliente);
        printf("%d   %10s       %2d   %10s    %10s       %10s\n", lista.id, lista.nombre, lista.edad, descripcionColor, descripcionTipo, nombreCliente);
    printf("-------------------------------------------------------------------------------------------\n");
}


int mostrarMascotas(eMascota lista[], int tam , eColor colores[], int tamCol, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli){

    int mostrarOk;
    int flag=0;//bandera para saber si se entro al if de isEmpty
    if(lista!=NULL && tam>0){
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("                                MASCOTAS          \n");
                        printf("-------------------------------------------------------------------------------------------\n");
                        printf("ID        Nombre       Edad       Color         Tipo         Cliente\n");
                        printf("-------------------------------------------------------------------------------------------\n");
            for(int i = 0; i<tam; i++){
                if(lista[i].isEmpty==0){

                        mostrarMascota(lista[i], colores, tamCol, tipos, tamTip, clientes, tamCli);
                        printf("\n");
                        flag=1;
                }

            }
            if(flag){
                mostrarOk=1;
            }else{
                 printf("No hay mascotas que mostrar\n");
                mostrarOk=0;

            }

    }
    return mostrarOk;
}


int modificarMascota(eMascota lista[], int tam,eColor color[], int tamCol, eTipos tipos[], int tamTip, eClientes clientes[], int tamCli){
    int modificarOk=0;
    int id;
    int indiceMascota;
    eMascota aux;


    system("cls");
    printf("-----------------------------------------------------------------------------\n");
    printf("                          Modificar Mascota          \n");
    printf("-----------------------------------------------------------------------------\n");
     if(lista!=NULL && tam>0){

        indiceMascota = buscarMascota(lista, tam, id);
        mostrarMascotas(lista, tam,color, tamCol, tipos, tamTip, clientes, tamCli);

         printf("-----------------------------------------------------------\n");
        if(utn_getNumero(&id,"Ingrese ID de la mascota a modificar: ", "ID invalido. ",100,110,5)==0){
            printf("ID correctamente cargado.\n");
        } else {
            printf("Error en la carga.\n");
                }


        indiceMascota = buscarMascota(lista, tam, id);

        if(indiceMascota==-1){
            printf("-----------------------------------------------------------------------------\n");
            printf("El ID ingresado no existe. ID ingresado: %d\n", id);
        } else {
            printf("El ID ingresado es el siguiente: %d. \n", id);
            printf("Pertenece a: \n");
            mostrarMascota(lista[indiceMascota],color, tamCol, tipos, tamTip, clientes, tamCli);
            printf("\n");
            printf("-----------------------------------------------------------------------------\n");

            switch(subMenuModificar()){

                case 1:
                    mostrarTipos(tipos, tamTip);
                     if(utn_getNumero(&aux.idTipo,"Ingrese nuevo ID tipo: ", "ID invalido. ",1000,1004,5)==0){
                      printf("ID correctamente cargado.\n");
                    } else {
                        printf("Error en la carga.\n");
                    }

                    lista[indiceMascota].idTipo = aux.idTipo;
                    modificarOk=1;
                    break;

                case 2:

                    if(utn_getNumero(&aux.edad,"Ingrese nueva edad de su mascota: ", "Edad invalida. Reingrese edad de su mascota: ",0,30,3)==0){
                      printf("Edad correctamente cargada.\n");
                    } else {
                        printf("Error en la carga.\n");
                    }

                    lista[indiceMascota].edad = aux.edad;
                    modificarOk=1;
                    break;

                default:
                    printf("Dato invalido.\n");
                    break;
            }



        }


     }




    return modificarOk;
}

int ordenarMascotas(eMascota lista[], int tam, eColor colores[], int tamCol, eTipos tipos[], int tamTip){
    int ordenarOk=0;
    int flag=0;//controla si se entro al if se isEmpty o no
    eMascota aux;

    if(lista!=NULL && tam>0){
            system("cls");
             for(int i=0; i<tam-1; i++){
                for(int j=i+1; j<tam; j++){
                        if(lista[i].isEmpty==0){
                            if(lista[i].idTipo > lista[j].idTipo){  //si quisiera ordenar por nombre: strcmp(lista[i].nombre, lista[j].nombre)>0

                                aux = lista[i];
                                lista[i] = lista[j];
                                lista[j] = aux;
                        }else if(lista[i].idTipo == lista[j].idTipo && (strcmp(lista[i].nombre, lista[j].nombre)>0)){
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                        }
                        flag=1;//se entro al isEmpty
                }

            }
        }
       if(flag){
        ordenarOk=1;
       }else{
        ordenarOk=0;
       }

    }
    return ordenarOk;
}

int cargarDescMascota(int id, eMascota mascotas[], int tamM, char nombre[]){
    int cargarOk=0;
    if(mascotas!=NULL && tamM>0 && nombre!=NULL && id>=100){
        for (int i=0; i<tamM; i++){
            if(mascotas[i].id==id){
                strcpy(nombre, mascotas[i].nombre);
                cargarOk=1;
                break;

            }
        }
    }


    return cargarOk;
}

