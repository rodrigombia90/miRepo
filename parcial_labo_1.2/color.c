#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"

int mostrarColores(eColor color[], int tam)
{
    int error = 1;
    int flag = 0;
    if(color!= NULL && tam > 0)
    {
        system("cls");
        printf(" ID      Color     \n");
        printf("-------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(color[i].id != 0)
            {
                mostrarColor(color[i],tam);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay Mascotas en la lista");
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}

void mostrarColor(eColor unColor, int t)
{
    printf(" %d   %s \n",unColor.id,unColor.nombreColor);
}


int obtenerDescripcionColor(eColor colores[], int tam,int id_col, char descripcionColor[])
{
    int error=1;
    if(colores!=NULL&&tam>0 &&id_col>=1000&&descripcionColor!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(colores[i].id==id_col)
            {
                strcpy(descripcionColor,colores[i].nombreColor);
                error=0;
                break;
            }
        }
    }
    return error;
}
