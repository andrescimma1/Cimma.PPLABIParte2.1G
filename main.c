#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebooks.h"
#include "marcas.h"
#include "tipos.h"
#include "servicios.h"
#include "trabajos.h"

#define TAMNOT 10
#define TAMMAR 4
#define TAMTIP 4
#define TAMSER 4
#define TAMTRA 10



int main()
{
    char seguir = 's';

    eMarca arrayMarcas[] = {
                           {1000, "Compaq"},
                           {1001, "Asus"},
                           {1002, "Acer"},
                           {1003, "HP"}
                           };
    eTipo arrayTipos[] = {
                            {5000, "Gamer"},
                            {5001, "Disenio"},
                            {5002, "Ultrabook"},
                            {5003, "Normalita"}
                            };

    eServicio arrayServicios[] = {
                                 {20000, "Bateria", 250},
                                 {20001, "Antivirus", 300},
                                 {20002, "Actualizacion", 400},
                                 {20003, "Fuente", 600}
                                 };
    eNotebook arrayNotebooks[TAMNOT] = {
                                       {1, "ASDQE4", 1000, 5001, 25000, 1, {1, "Andres", 'm'}},
                                       {4, "DQE4a2", 1002, 5002, 60000, 1, {4, "Claudia", 'f'}},
                                       {5, "WEDSA3", 1000, 5000, 43000, 1, {5, "Daniela", 'f'}},
                                       {6, "ESQEs4", 1003, 5003, 74000, 1, {6, "Pablo", 'm'}}
                                       };
    inicializarNotebooks(arrayNotebooks, TAMNOT);
    eTrabajo arrayTrabajos[TAMTRA];
    inicializarTrabajos(arrayTrabajos, TAMTRA);

    do
    {
        switch(menu())
        {
            case 'A': altaNotebook(arrayNotebooks, TAMNOT, arrayMarcas, TAMMAR, arrayTipos, TAMTIP);
                    system("pause");
                    break;
            case 'B': modificarNotebook(arrayNotebooks, TAMNOT, arrayMarcas, TAMMAR, arrayTipos, TAMTIP);
                    system("pause");
                    break;
            case 'C': bajaNotebook(arrayNotebooks, TAMNOT, arrayMarcas, TAMMAR, arrayTipos, TAMTIP);
                    system("pause");
                    break;
            case 'D': listarNotebooks(arrayNotebooks, TAMNOT, arrayMarcas, TAMMAR, arrayTipos, TAMTIP);
                    system("pause");
                    break;
            case 'E': listarMarcas(arrayMarcas, TAMMAR);
                    system("pause");
                    break;
            case 'F': listarTipos(arrayTipos, TAMTIP);
                    system("pause");
                    break;
            case 'G': listarServicios(arrayServicios, TAMSER);
                    system("pause");
                    break;
            case 'H': altaTrabajo(arrayNotebooks, TAMNOT, arrayMarcas, TAMMAR, arrayTipos, TAMTIP, arrayServicios, TAMSER, arrayTrabajos, TAMTRA);
                    system("pause");
                    break;
            case 'I': listarTrabajos(arrayTrabajos, TAMTRA, arrayNotebooks, TAMNOT, arrayMarcas, TAMMAR, arrayTipos, TAMTIP, arrayServicios, TAMSER);
                    system("pause");
                    break;
            case '1': mostrarNotebooksPorTipoSeleccionado(arrayNotebooks, TAMNOT, arrayMarcas, TAMMAR, arrayTipos, TAMTIP);
                    system("pause");
                    break;
            case '2': mostrarNotebooksPorMarcaSeleccionada(arrayNotebooks, TAMNOT, arrayMarcas, TAMMAR, arrayTipos, TAMTIP);
                    system("pause");
                    break;
            case '3': informarLaOLasNotebooksMasBaratas(arrayNotebooks, TAMNOT, arrayMarcas, TAMMAR, arrayTipos, TAMTIP);
                    system("pause");
                    break;
            //case '4':
            case '5': mostrarNotebooksPorTipoYMarca(arrayNotebooks, TAMNOT, arrayMarcas, TAMMAR, arrayTipos, TAMTIP);
                    system("pause");
                    break;
            case '6': mostrarLaOLasMarcasMasElegidas(arrayNotebooks, TAMNOT, arrayMarcas, TAMMAR);
                    system("pause");
                    break;

        }

    }while(seguir == 's');

    return 0;
}



