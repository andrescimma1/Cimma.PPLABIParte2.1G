#ifndef NOTEBOOKS_H_INCLUDED
#define NOTEBOOKS_H_INCLUDED

#include "marcas.h"
#include "tipos.h"
#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int precio;
    int ocupado;
    int idCliente;
}eNotebook;

void inicializarNotebooks(eNotebook arrayNotebooks[], int tamnot);
int buscarLibre(eNotebook arrayNotebooks[], int tamnot);
void listarNotebook(eNotebook pNotebook, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eCliente arrayClientes[], int tamcli);
void ordenarPorMarcaYprecio(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip);
int listarNotebooks(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eCliente arrayClientes[], int tamcli);
int generarId(eNotebook arrayNotebooks[], int tamnot);
void altaNotebook(eNotebook arrayNotebooks[], int tamnot, eMarca arrayMarcas[], int tammar, eTipo arrayTipos[], int tamtip, eCliente arrayClientes[], int tamcli);
int menu();
void modificarNotebook(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eCliente arrayClientes[], int tamcli);
int submenu();
void bajaNotebook(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eCliente arrayClientes[], int tamcli);
void mostrarNotebooksPorTipoSeleccionado(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eCliente arrayClientes[], int tamcli);
void mostrarNotebooksPorMarcaSeleccionada(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eCliente arrayClientes[], int tamcli);
void informarLaOLasNotebooksMasBaratas(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eCliente arrayClientes[], int tamcli);
void separarPorMarca(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eCliente arrayClientes[], int tamcli);
void mostrarNotebooksPorTipoYMarca(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eCliente arrayClientes[], int tamcli);
void mostrarLaOLasMarcasMasElegidas(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar);



#endif // NOTEBOOKS_H_INCLUDED
