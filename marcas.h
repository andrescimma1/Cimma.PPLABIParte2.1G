#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;

void listarMarcas(eMarca arrayMarcas[], int lenmar);

#endif // MARCAS_H_INCLUDED
