#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "mascota.h"
#include "color.h"
#include "tipo.h"

int inicializarTrabajos(eTrabajo trabajos[], int tamT)
{
    int error=1;
    if(trabajos!=NULL && tamT>0)
    {
        for (int i = 0; i < tamT; i++)
        {
            trabajos[i].isEmpty = 1;
            error=0;
        }
    }
    return error;
}

int buscarTrabajoLibre(eTrabajo trabajos[], int tamT)
{
    int indice = 1;
    for (int i = 0; i < tamT; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            indice= i;
            break;
        }
    }
    return indice;
}

void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamS, eMascota mascotas[],int tamM)
{
    char descServicio[20];
    char nombreMascota[20];// quedo en 1:01 clase 14
    //showDescriptionService(trabajo.idServicio, servicios, tamS, descServicio);
    if(obtenerDescripcionServicio(servicios,tamS,unTrabajo.idServicio,descServicio)==0)
    {
        printf("   %d          %s      %20s       %s \n", unTrabajo.id,
           unTrabajo.bichito.nombre,
           descServicio,
           nombreMascota);
    }
    else
    {
        printf("problema obtener descripcion del servicio");
    }


}

int mostrarTrabajos(eTrabajo trabajos[], int tamT, eServicio servicios[],int tamS,eMascota mascotas[],int tamM)
{
    int error = 1;
    int flag = 0;
    system("cls");
    if(trabajos!= NULL && tamS > 0 && trabajos->isEmpty ==0)
    {

        printf(" ID      Especie        Nombre      Servicio      Edad\n");
        printf("---------------------------------------------------\n\n");
        for(int i=0; i<tamT; i++)
        {
            if(trabajos[i].isEmpty == 1)
            {
                mostrarTrabajo(trabajos[i],servicios,tamS,mascotas,tamM);
                flag = 1;
            }
        }
        if( flag == 0)
        {
            printf("No hay Mascotas en la lista");
        }


        error = 0;
    }
    else{
        printf("\t\t***No se han ingresado trabajos***\n\n");
    }
    printf("\n\n");
    return error;
}


int altaTrabajo(eTrabajo trabajos[],int tamT, eServicio servicios[],int tamS, eMascota mascotas[],int tamM,eColor colores[],int tamC,eTipo tipos[],int tamTipo, int id)
{
    int error=1;
    int indice;
    //int digit;
    eTrabajo nuevoTrabajo;
    //int auxiliarIdMascota;
    if(trabajos!=NULL && tamT > 0 && id > 0)
    {
        system("cls");
        printf("***ALTA DE TRABAJOS***\n\n");
        indice = buscarTrabajoLibre(trabajos,tamT);
        if(indice == -1)
        {
            printf("El sistema esta completo.\n\n");
        }
        else
        {
            //aplicar validaciones a las cargas
            nuevoTrabajo.id = id;
            nuevoTrabajo.isEmpty = 0;
            mostrarMascotas(mascotas,tamM,colores,tamC,tipos,tamT);
            printf("\nIngrese ID de la Mascota: ");
            scanf("%d",&nuevoTrabajo.idMascota);
            //hacer funcion para ID mascota ingresada
            mostrarServicios(servicios,tamS);
            printf("Ingrese ID del servicio a realizar: ");
            scanf("%d",&nuevoTrabajo.idServicio);
            trabajos[indice] = nuevoTrabajo;

            error = 0;
        }
    }
    return error;
}


