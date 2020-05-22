#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int ocupado;
}eTrabajo;

void inicializarTrabajos(eTrabajo arrayTrabajos[], int lentra);
int buscarTrabajoLibre(eTrabajo arrayTrabajos[], int lentra);

#endif // TRABAJOS_H_INCLUDED
