#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicio.h"



int mostrarServicios(eServicio servicios[], int tam)
{
    int error = 1;
    int flag = 0;
    if(servicios!= NULL && tam > 0)
    {
        system("cls");
        printf(" ID            Servicios        Precios   \n");
        printf("---------------------------------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(servicios[i].id != 0)
            {
                mostrarServicio(servicios[i],tam);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay Servicios en la lista");
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}

void mostrarServicio(eServicio unServicio, int t)
{
    printf(" %d   %15s   %10d\n",unServicio.id,unServicio.descripcion,unServicio.precio);
}


int validarIdServicio(eServicio servicios[],int tamS,int idServicios)
{
    int error=1;
    if(idServicios>=20000 && idServicios<=20002)
    {
        error=0;

    }

    return error;
}

int obtenerDescripcionServicio(eServicio servicios[], int tamS,int id, char descripcionServicio[])
{
    int error=1;
    if(servicios!=NULL&&tamS>0)
    {   //printf("entro 1");
        for(int i=0; i<tamS; i++)
        {   //printf("entro 2");
            if(servicios[i].id==id)
            {   printf("entro 3");
                strcpy(descripcionServicio,servicios[i].descripcion);
                error=0;
                break;
            }
        }
    }
    return error;
}
