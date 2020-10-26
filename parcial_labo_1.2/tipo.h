#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED


typedef struct //tipo
{
    int id;
    char descripcion[20];
} eTipo;


#endif // TIPO_H_INCLUDED

int mostrarTipos(eTipo mascotas[], int tam);
void mostrarTipo(eTipo unTipo, int t);
int obtenerDescripcionTipo(eTipo tipos[], int tam,int id, char descripcionMarca[]);
