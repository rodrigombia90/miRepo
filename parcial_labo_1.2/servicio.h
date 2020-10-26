#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct //servicio
{
    int id;
    char descripcion[20];
    int precio;
} eServicio;

#endif // SERVICIO_H_INCLUDED

int mostrarServicios(eServicio servicios[], int tam);
void mostrarServicio(eServicio unServicio, int t);
int obtenerDescripcionServicio(eServicio servicios[], int tamS,int id, char descripcionServicio[]);
