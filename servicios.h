#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

void listarServicios(eServicio arrayServicios[], int lenser);

#endif // SERVICIOS_H_INCLUDED
