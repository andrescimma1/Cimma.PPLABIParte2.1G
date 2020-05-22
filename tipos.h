#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;


void listarTipos(eTipo arrayTipos[], int lentip);

#endif // TIPOS_H_INCLUDED
