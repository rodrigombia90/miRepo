#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascota.h"
#include "input.h"
#include "servicio.h"
#include "fecha.h"
#include "trabajo.h"

#define TAM_colores 6
#define TAM_mascotas 6
#define TAM_tipos 6
#define TAM_servicios 3
#define TAM_trabajos 50

//agregar estructura cliente
//una mascota tiene un dueño (cliente) y un cliente puede tener muchas mascotas
//harcodear clientes y cuando se da de alta a la mascota se le asigna el cliente


char menuOpciones();
int main()
{
    char seguir = 's';
    char confirma;
    eMascota mascotas[TAM_mascotas]=
    {
        {0000,"juancho",1000,5000,1,0},
        {0001,"Sauron",1001,5001,2,0},
        {0002,"Vader",1002,5002,3,0},
        {0003,"Pepe",1003,5003,1,0},
        {0004,"Frodo",1004,5004,2,0},
    };
    eTipo datosTipo [20]= {{1000,"Ave"},{1001,"Perro"},{1002,"Gato"},{1003,"Roedor"},{1004,"Pez"},};
    eColor datosColor [20]= { {5000,"Negro"}, {5001,"Blanco"}, {5002,"Gris"}, {5003,"Rojo"}, {5004,"Azul"},};
    eServicio datosServicio [20]= { {20000,"Corte",250},{20001,"Desparacitado",300},{20002,"Castrado",400}, };
    eTrabajo datosTrabajo[TAM_trabajos]=
    {
        {0000,0002,20002,5000,11/05/2020,0},
        {0001,0001,20000,5001,12/11/2020,0},
        {0002,0000,20001,5002,20/12/2020,0},
        {0003,0004,20001,5003,05/10/2020,0},
        {0004,0004,20002,5004,01/05/2020,0},
    };
    //eMascota mascotas[100];
    eTrabajo trabajos[20];
    int proximoIdMascotas=0005;
    int proximoIdTrabajo=0001;

        if(inicializarMascotas(mascotas, TAM_mascotas)==0 && inicializarTrabajos(trabajos,TAM_trabajos)==0)
        {
            printf("Inicializacion exitosa!");
        }
        else
        {
            printf("Ha ocurrido un problema al inicializar");
        }
    do
    {
        system("cls");
        switch(menuOpciones())
        {

        case 'a':
            if(altaMascota(datosColor,datosTipo,mascotas, TAM_mascotas, proximoIdMascotas) == 0)
            {
                proximoIdMascotas++;
                printf("ALTA EXITOSA!\n");
            }
            else
            {
                printf("Problema para realizar el alta\n\n");
            }
            break;
        case 'b':
            modificarMascota(mascotas,TAM_mascotas,datosColor,TAM_colores,datosTipo,TAM_tipos);
            break;
        case 'c':
            bajaMascota(mascotas,TAM_mascotas,datosColor,TAM_colores,datosTipo,TAM_tipos);
            break;
        case 'd':
            mostrarMascotas(mascotas,TAM_mascotas,datosColor,TAM_colores,datosTipo,TAM_tipos);
            break;
        case 'e':
            mostrarTipos(datosTipo,TAM_tipos);
            break;
        case 'f':
            mostrarColores(datosColor,TAM_colores);
            break;
        case 'g':
            mostrarServicios(datosServicio,TAM_servicios);
            break;
        case 'h':
            altaTrabajo(datosTrabajo,TAM_trabajos,datosServicio,TAM_servicios,mascotas,TAM_mascotas,datosColor,TAM_colores,datosTipo,TAM_tipos,proximoIdTrabajo);
            break;
        case 'i':
            mostrarTrabajos(datosTrabajo,TAM_trabajos,datosServicio,TAM_servicios,mascotas,TAM_mascotas);
            break;
        case 'j':

            break;
        case 'k':
            printf("Confirma salida? Ingrese s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("Opcion invalida!!!\n");
        }
        system("pause");
    }
    while( seguir == 's');
    return 0;
}

char menuOpciones()
{
    char opcion;
    printf("*** Bienvenido a la Veterinaria***\n\n");
    printf("a_ Alta de Mascota\n");
    printf("b_ Modificar Mascota\n");
    printf("c_ Baja Mascota\n");
    printf("d_ Listar Mascotas\n");
    printf("e_ Listar Tipos\n");
    printf("f_ Listar Colores\n");
    printf("g_ Listar Servicios\n");
    printf("h_ Alta Trabajo\n");
    printf("i_ Listar Trabajos\n");
    printf("j_ Listar Informes\n");
    printf("k_ Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;
}
/*
int listarInformes()
{
    if(mascotas != NULL && tam_masc > 0)
    {
        system("cls");
        printf("    ***Listar Informes***\n");
        printf("Ingrese opcion para elegir el informe\n");
        printf("1_ \n");
        printf("2_ Modificar Mascota\n");
        printf("3_ Baja Mascota\n");
        printf("4_ Listar Mascotas\n");
        printf("5_ Listar Tipos\n");
        printf("6_ Listar Colores\n");
        printf("7_ Listar Servicios\n");
        printf("8_ Alta Trabajo\n");
        printf("9_ Listar Trabajos\n");
        printf("10_ Listar Informes\n");
        printf("Ingrese opcion: ");
        scanf("%d",&seleccion);

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
*/
/*
int ordenarAutos(eMascota mascotas[], int tam_masc)
{
    int error = 1;
    eMascota auxAuto;

    if(mascotas!=NULL && tam_masc>0)
    {
        for(int i=0; i-tam_masc -1; i++)
        {
            for(int j=i+1; j<tam_masc; j++)
            {
                if((strcmp(mascotas[i].nombre, mascotas[j].nombre) >0) ||
                        (strcmp(mascotas[i].idTipo, mascotas[j].idTipo) >0))
                {
                    auxAuto = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxAuto;
                }
            }
        }
        error = 0;
    }

    return 0;

}




                if(strcmp(gente[i].nombre, gente[j].nombre) > 0 && criterio == 1)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                else if(strcmp(gente[i].nombre, gente[j].nombre) < 0 && criterio == 0)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }

                ///////////////////////////////// OTRA FORMA DE HACERLO //////////////////////
*/


