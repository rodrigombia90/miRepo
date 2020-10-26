#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipo.h"

void mostrarTipo(eTipo unTipo, int t)
{
    printf(" %d   %s \n",unTipo.id,unTipo.descripcion);
}


int mostrarTipos(eTipo mascotas[], int tam)
{
    int error = 1;
    int flag = 0;
    if(mascotas!= NULL && tam > 0)
    {
        system("cls");
        printf(" ID     Especie     \n");
        printf("-------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(mascotas[i].id != 0)
            {
                mostrarTipo(mascotas[i],tam);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay Mascotas en la lista");
        }
        printf("\n");

        error = 0;
    }
    return error;
}


int obtenerDescripcionTipo(eTipo tipos[], int tam, int id_mar, char descripcionMarca[])
{
    int error=1;
    if(tipos!=NULL&&tam>0 &&id_mar>=1000&&descripcionMarca!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id==id_mar)
            {
                strcpy(descripcionMarca,tipos[i].descripcion);
                error=0;
                break;
            }
        }
    }
    return error;
}
