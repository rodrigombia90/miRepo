#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED
#include "color.h"
#include "tipo.h"

typedef struct //auto/tiene isEmpty
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    eColor idColorN;
    int isEmpty;// 1 esta vacia 0 esta llena
} eMascota;

#endif // MASCOTA_H_INCLUDED


int altaMascota(eColor color[], eTipo tipo[], eMascota mascotas[],int tam,int id);
int buscarMascota(eMascota mascotas[],int tam, int id);
int modificarMascota(eMascota mascotas[], int tam_masc, eColor color[],int tam_col, eTipo tipo[], int tam_tipos );
int buscarLibre(eMascota mascotas[], int tam);
int inicializarMascotas(eMascota mascotas[], int tam);
int validarIdMascota(eMascota mascotas[],int tamM,int idMascota);
int mostrarMascotas(eMascota Mascotas[], int tam_masc, eColor colores[],int tam_col,eTipo tipos[], int tam_tipos);
void mostrarMascota(eMascota unaMascota, eColor color[], eTipo tipo[], int tam_col, int tam_tipos);
int obtenerDescripcionMascota(eMascota mascotas[], int tamM,int id, char nombre[]);
int bajaMascota(eMascota mascotas[], int tam_masc, eColor color[],int tam_col, eTipo tipo[], int tam_tipos );
int buscarMascota(eMascota mascotas[],int tam, int id);
int modificarMascota(eMascota mascotas[], int tam_masc, eColor color[],int tam_col, eTipo tipo[], int tam_tipos );
int obtenerIdMascota(eMascota mascotas[], int tamM,int id, int idMascota);
