#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "servicio.h"
#include "mascota.h"
#include "color.h"
#include "tipo.h"

typedef struct //trabajo
{
    int id;
    int idMascota;
    int idServicio;
    int isEmpty;
    eFecha fecha;
    eMascota bichito;
} eTrabajo;

#endif // TRABAJO_H_INCLUDED

int mostrarTrabajos(eTrabajo trabajos[], int tamT, eServicio servicios[],int tamS,eMascota mascotas[],int tamM);
void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamS,eMascota mascotas[],int tamM);
int buscarTrabajoLibre(eTrabajo trabajos[], int tamT);
int inicializarTrabajos(eTrabajo trabajos[], int tamT);
int altaTrabajo(eTrabajo trabajos[],int tamT, eServicio servicios[],int tamS, eMascota mascotas[],int tamM,eColor colores[],int tamC,eTipo tipos[],int tamTipo, int id);
