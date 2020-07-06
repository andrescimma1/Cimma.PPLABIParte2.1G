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
int generarIdTrabajo(eTrabajo arrayTrabajos[], int tamtra);
void altaTrabajo(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eTrabajo arrayTrabajos[], int lentra, eCliente arrayClientes[], int tamcli);
void listarTrabajo(eTrabajo pTrabajo, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eCliente arrayClientes[], int tamcli);
void listarTrabajos(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eCliente arrayClientes[], int tamcli);
void trabajosAUnaNote(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eCliente arrayClientes[], int tamcli);
void sumaDeServiciosAUnaNote(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eCliente arrayClientes[], int tamcli);
void pedirServicio(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eCliente arrayClientes[], int tamcli);
void pedirFecha(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eCliente arrayClientes[], int tamcli);

#endif // TRABAJOS_H_INCLUDED
