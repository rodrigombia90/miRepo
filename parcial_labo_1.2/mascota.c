#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipo.h"
#include "mascota.h"
#include "input.h"

int modificarMascota(eMascota mascotas[], int tam_masc, eColor color[],int tam_col, eTipo tipo[], int tam_tipos )
{
    int error = 1;
    int idModi;
    int indice;
    char confirma;
    int seleccion;
    int idEdadModi;
    int idTipoModi;

    if(mascotas != NULL && tam_masc > 0)
    {
        system("cls");
        printf("    ***Modificar Mascota***\n");
        mostrarMascotas(mascotas,tam_masc,color,tam_col,tipo,tam_tipos);
        printf("Ingrese opcion para modificar\n");
        printf("1_ Tipo\n");
        printf("2_ Edad\n\n");
        printf("Ingrese opcion: ");
        scanf("%d",&seleccion);
        if(seleccion==1)
        {
            //modifica tipo
            printf("Ingrese el ID para modificar Tipo de Mascota: ");
            scanf("%d", &idModi);
            indice = buscarMascota(mascotas,tam_masc,idModi);
            if( indice == -1)
            {
                printf("No existe esa Mascota.\n");
            }
            else
            {
                mostrarMascota(mascotas[indice],color,tipo,tam_col,tam_tipos);
                printf("\nIngrese nuevo ID de Tipo: ");
                scanf("%d",&idTipoModi);
                printf("Confirma modificacion?");
                fflush(stdin);
                scanf("%c", &confirma);
                if (confirma == 's')
                {
                    mascotas[indice].idTipo= idTipoModi;
                    error = 0;
                }
                else
                {
                    error = 2;
                }
            }
        }
        else if (seleccion==2)
        {
            //modifica tipo
            printf("Ingrese el ID para modificar la Edad de Mascota: ");
            scanf("%d", &idModi);
            indice = buscarMascota(mascotas,tam_masc,idModi);
            if( indice == -1)
            {
                printf("No existe esa Mascota.\n");
            }
            else
            {
                mostrarMascota(mascotas[indice],color,tipo,tam_col,tam_tipos);
                printf("\nIngrese nueva Edad: ");
                scanf("%d",&idEdadModi);
                printf("Confirma modificacion?");
                fflush(stdin);
                scanf("%c", &confirma);
                if (confirma == 's')
                {
                    mascotas[indice].edad= idEdadModi;
                    error = 0;
                }
                else
                {
                    error = 2;
                }
            }
        }
    }
    return error;
}

int buscarMascota(eMascota mascotas[],int tam, int id)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(mascotas[i].id == id && mascotas[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int bajaMascota(eMascota mascotas[], int tam_masc, eColor color[],int tam_col, eTipo tipo[], int tam_tipos )
{
    int error=0;
    int idBaja;
    int baja;
    char confirma;
    if(mascotas!=NULL && tam_masc >0)
    {
        system("cls");
        printf("***Baja de Mascotas***");
        mostrarMascotas(mascotas,tam_masc,color,tam_col,tipo,tam_tipos);
        printf("Ingrese ID: ");
        scanf("%d",&idBaja);

        baja=buscarMascota(mascotas,tam_masc,idBaja);
        if(baja ==-1)
        {
            printf("no existe ese id\n\n");
        }
        else
        {
            mostrarMascota(mascotas[idBaja],color,tipo,tam_col,tam_tipos);
            //importante poner [idBaja] ese es el indice que hay
            //que borrar
            printf("Confirma borrado?: ");
            fflush(stdin);
            tolower(scanf("%c",&confirma));
            if(confirma=='s')
            {
                mascotas[idBaja].isEmpty=1;
                error=0;
            }
            else
            {
                printf("La baja se ha cancelado por le usuario");
            }
        }
    }
    return error;
}

int altaMascota(eColor color[], eTipo tipo[], eMascota mascotas[],int tamM,int id)
{
    int error=1;
    int indice;
    //int digit;
    eMascota nuevaMascota;
    int auxiliarIdMascota;
    if(mascotas!=NULL && tamM > 0 && id > 0)
    {
        system("cls");
        printf("***ALTA DE MASCOTAS***\n\n");
        indice = buscarLibre(mascotas, tamM);
        if(indice == -1)
        {
            printf("El sistema esta completo.\n\n");
        }
        else
        {
            nuevaMascota.id = id;
            nuevaMascota.isEmpty = 0;
            mostrarTipos(tipo,tamM);
            fflush(stdin);
            utn_getNumero(&nuevaMascota.idTipo,"ingrese ID: ","\nerror, ingrese ID valido\n", 1000,1005,5);
            fflush(stdin);
            utn_getNombre(&nuevaMascota.nombre,10,"\n\ningrese nombre: ","\nerror, reingres nombre con letras\n",5);
            fflush(stdin);
            mostrarColores(color,tamM);
            utn_getNumero(&nuevaMascota.idColor,"ingrese ID: ","\nerror, ingrese ID valido\n", 5000,5005,5);
            fflush(stdin);
            utn_getNumero(&nuevaMascota.edad,"ingrese edad : ","\nerror, ingrese edad valido\n", 0,20,5);
            fflush(stdin);
            mascotas[indice] = nuevaMascota;
            error = 0;
        }
    }
    return error;
}


int buscarLibre(eMascota mascotas[], int tam) //////para dar de alta
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(mascotas[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int mostrarMascotas(eMascota Mascotas[], int tam_masc, eColor colores[],int tam_col,eTipo tipos[], int tam_tipos)
{
    int error = 1;
    int flag = 0;
    if(Mascotas!= NULL && tam_masc > 0)
    {
        system("cls");
        printf(" ID      Color     Especie        Nombre    Edad\n");
        printf("--------------------------------------------------\n\n");
        ordenarMascotas(Mascotas,tipos,tam_masc,tam_tipos);
        for(int i=0; i<tam_masc; i++)
        {
            if(Mascotas[i].isEmpty == 0)
            {
                mostrarMascota(Mascotas[i],colores,tipos,tam_col,tam_tipos);
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

void mostrarMascota(eMascota unaMascota, eColor color[], eTipo tipo[], int tam_col, int tam_tipos)
{
    char nombreColor[15];
    char nombreMarca[15];
    if(obtenerDescripcionColor(color,tam_col,unaMascota.idColor,nombreColor)==0 &&
            obtenerDescripcionTipo(tipo,tam_tipos,unaMascota.idTipo,nombreMarca)==0)
    {
        printf(" %d  %10s  %10s  %12s  %5d\n", unaMascota.id, nombreColor, nombreMarca, unaMascota.nombre, unaMascota.edad);
    }
}


int inicializarMascotas(eMascota mascotas[], int tam)
{
    int error = 1;
    if (mascotas!=NULL && tam > 0)
    {
        for(int i=5; i<tam; i++)
        {
            mascotas[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int ordenarMascotas(eMascota mascotas[], eTipo tipos[],int tamM, int tamT)
{
    int error = 1;
    eMascota auxMascota;
    char mascotaI[20];
    char mascotaJ[20];
    if(mascotas!=NULL && tamM>0)
    {
        for(int i=0; i-tamM -1; i++)
        {
            for(int j=i+1; j<tamM; j++)
            {
                obtenerDescripcionMascota(mascotas,tamM,mascotas[i].nombre,mascotaI);
                obtenerDescripcionMascota(mascotas,tamM,mascotas[j].nombre,mascotaJ);
                if((strcmp(mascotaI,mascotaJ)>0) ||
                (strcmp(mascotaI,mascotaJ)<0))
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
            }
        }
        error = 0;
    }

    return error;


}

int obtenerDescripcionMascota(eMascota mascotas[], int tamM,int id, char nombre[])
{
    int error=1;
    if(mascotas!=NULL&&tamM>0 &&id>=1000&&nombre!=NULL)
    {
        for(int i=0; i<tamM; i++)
        {
            if(mascotas[i].id==id)
            {
                strcpy(nombre,mascotas[i].nombre);
                error=0;
                break;
            }
        }
    }
    return error;
}


int obtenerIdMascota(eMascota mascotas[], int tamM,int id, int idMascota)
{
    int error=1;
    if(mascotas!=NULL&&tamM>0)
    {
        for(int i=0; i<tamM; i++)
        {
            if(mascotas[i].id==id && mascotas[i].isEmpty==1)
            {
                idMascota=mascotas[i].id;
                error=0;
                break;
            }
        }
    }
    return error;
}

