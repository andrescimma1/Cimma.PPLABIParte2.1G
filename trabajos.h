#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

#include "notebooks.h"
#include "servicios.h"

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
void altaTrabajo(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eTrabajo arrayTrabajos[], int lentra);
void listarTrabajo(eTrabajo pTrabajo, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser);
void listarTrabajos(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser);
void trabajosAUnaNote(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser);

#endif // TRABAJOS_H_INCLUDED
