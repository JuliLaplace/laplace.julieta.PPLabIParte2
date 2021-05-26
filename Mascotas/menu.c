#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include "menu.h"
#include"validaciones.h"


char menu(){
    char opcion;

        system("cls");
        printf("-----------------------------------------------------------------------------\n");
        printf("-----------------------------AMB MASCOTAS------------------------------------\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("A. Alta mascota.\n");
        printf("B. Modificar mascota.\n");
        printf("C. Baja mascota.\n");
        printf("D. Listar mascotas.\n");
        printf("E. Listar tipos. \n");
        printf("F. Listar colores. \n");
        printf("G. Listar servicios.\n");
        printf("H. Alta trabajo.\n");
        printf("I. Listar trabajos.\n");
        printf("J. Informes.\n");
        printf("K. Salir.\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("Ingrese la opcion deseada: ");
        fflush(stdin);
        scanf("%c", &opcion);
        printf("-----------------------------------------------------------------------------\n");
        opcion = toupper(opcion);
        return opcion;
}

int subMenuModificar(){
int opcion;
            printf("-----------------------------------------------------------------------------\n");
            printf("1) Tipo.\n");
            printf("2) Edad.\n");
            printf("-----------------------------------------------------------------------------\n");

              if(utn_getNumero(&opcion,"Ingrese de las opciones anteriores, cual desea modificar: ", "Opcion invalida. ",1,2,3)==0){
                      printf("Opcion correcta.\n");
                    } else {
                        printf("Error en la carga.\n");
                    }


return opcion;

}

int subMenuInformes(){
int opcion;

 printf("-----------------------------------------------------------------------------\n");
            printf("Elija la opcion con la que desea realizar un informe: \n");
            printf("1) Mostrar mascotas por color seleccionado por usuario.\n");
            printf("2) Mostrar mascotas de un tipo seleccionado.\n");
            printf("3) Informar la/las mascotas de menor edad.\n");
            printf("4) Listar mascotas separadas por tipos.\n");
            printf("5) Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo.\n");
            printf("6) Mostrar el o los colores con mas cantidad de mascotas.\n");
            printf("7) Pedir una mascota y mostrar todos los trabajos que se le hicieron a la misma..\n");
            printf("8) Pedir una mascota e informar la suma de los importes de los servicios que se le hicieron a la misma.\n");
            printf("9) Pedir un servicio y mostrar las mascotas a las que se les realizo ese servicio y la fecha..\n");
            printf("10) Pedir una fecha y mostrar todos los servicios realizados en la misma..\n");
            printf("-----------------------------------------------------------------------------\n");
            if(utn_getNumero(&opcion,"Ingrese de las opciones anteriores, cual desea: ", "Opcion invalida. ",1,10,3)==0){
                      printf("Opcion correcta.\n");
                    } else {
                        printf("Error en la carga.\n");
                    }


return opcion;
}

