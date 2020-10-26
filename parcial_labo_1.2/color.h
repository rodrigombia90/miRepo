#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct //color
{
    int id;
    char nombreColor[20];
} eColor;

#endif // COLOR_H_INCLUDED

int mostrarColores(eColor color[], int tam);
void mostrarColor(eColor unColor, int t);
int obtenerDescripcionColor(eColor colores[], int tam,int id, char descripcionColor[]);
