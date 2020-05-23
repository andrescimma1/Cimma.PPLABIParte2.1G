#ifndef NOTEBOOKS_H_INCLUDED
#define NOTEBOOKS_H_INCLUDED

#include "marcas.h"
#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
}eCliente;

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int precio;
    int ocupado;
    eCliente cliente;
}eNotebook;

void inicializarNotebooks(eNotebook arrayNotebooks[], int tamnot);
int buscarLibre(eNotebook arrayNotebooks[], int tamnot);
void listarNotebook(eNotebook pNotebook, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip);
void ordenarPorMarcaYprecio(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip);
int listarNotebooks(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip);
void altaNotebook(eNotebook arrayNotebooks[], int tamnot, eMarca arrayMarcas[], int tammar, eTipo arrayTipos[], int tamtip);
int menu();
void modificarNotebook(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip);
int submenu();
void bajaNotebook(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip);
void mostrarNotebooksPorTipoSeleccionado(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip);
void mostrarNotebooksPorMarcaSeleccionada(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip);
void informarLaOLasNotebooksMasBaratas(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip);
void separarPorMarca(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip);
void mostrarNotebooksPorTipoYMarca(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip);
void mostrarLaOLasMarcasMasElegidas(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar);



#endif // NOTEBOOKS_H_INCLUDED
