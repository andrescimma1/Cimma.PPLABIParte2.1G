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


void altaTrabajo(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eTrabajo arrayTrabajos[], int lentra);
void listarTrabajo(eTrabajo pTrabajo, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser);
void listarTrabajos(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser);

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
                                       {1, "ASDQE4", 1000, 5001, 25000, 1},
                                       {4, "DQE4a2", 1002, 5002, 60000, 1},
                                       {5, "WEDSA3", 1000, 5000, 43000, 1},
                                       {6, "ESQEs4", 1003, 5003, 74000, 1}
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

        }

    }while(seguir == 's');

    return 0;
}





/** \brief Da de alta un trabajo
 *
 * \param int idNot, idServicio;
 * \param int indice, i, j;
 * \return No devuelve nada.
 *
 */
void altaTrabajo(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eTrabajo arrayTrabajos[], int lentra)
{
    int idNot;
    int idServicio;
    int indice;
    int i, j;

    indice = buscarTrabajoLibre(arrayTrabajos, lentra);

    if(indice != -1)
    {
        listarNotebooks(arrayNotebooks, len, arrayMarcas, lenmar, arrayTipos, lentip);
        printf("Ingrese el ID de la notebook que desea asignarle un trabajo: ");
        scanf("%d", &idNot);
        for(i=0; i<len; i++)
        {
            if(arrayNotebooks[i].id == idNot)
            {
                arrayTrabajos[indice].idNotebook = idNot;
            }
        }

        listarServicios(arrayServicios, lenser);
        printf("Ingrese la ID del servicio deseado: ");
        scanf("%d", &idServicio);
        for(j=0; j<lenser; j++)
        {
            if(arrayServicios[j].id == idServicio)
            {
                arrayTrabajos[indice].idServicio = idServicio;
            }
        }

        printf("Ingrese dia: ");
        scanf("%d", &arrayTrabajos[indice].fecha.dia);
        printf("Ingrese mes: ");
        scanf("%d", &arrayTrabajos[indice].fecha.mes);
        printf("Ingrese anio: ");
        scanf("%d", &arrayTrabajos[indice].fecha.anio);

        arrayTrabajos[indice].ocupado = 1;

        printf("Trabajo asignado con exito!\n\n");
    }
}


void listarTrabajo(eTrabajo pTrabajo, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser)
{
    int i;

    printf("ID TRABAJO: %d\n", pTrabajo.id);

    for(i=0; i<len; i++)
    {
        if(pTrabajo.idNotebook == arrayNotebooks[i].id && pTrabajo.ocupado == 1)
        {
            printf("Notebook: ");
            listarNotebook(arrayNotebooks[i], arrayMarcas, lenmar, arrayTipos, lentip);
        }
    }

    for(i=0; i<lenser; i++)
    {
        if(pTrabajo.idServicio == arrayServicios[i].id && pTrabajo.ocupado == 1)
        {
            printf("Servicio asignado: %d    %10s   %d", arrayServicios[i].id, arrayServicios[i].descripcion, arrayServicios[i].precio);
        }
    }

    printf("\nFecha: %d/%d/%d\n", pTrabajo.fecha.dia, pTrabajo.fecha.mes, pTrabajo.fecha.anio);
    printf("_____________________________________________________\n");

}



void listarTrabajos(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser)
{
    int i;
    int indice = -1;

    printf("*** LISTADO DE TRABAJOS ***\n");

    for(i=0; i<lentra; i++)
    {
        if(arrayTrabajos[i].ocupado == 1)
        {
            listarTrabajo(arrayTrabajos[i], arrayNotebooks, len, arrayMarcas, lenmar, arrayTipos, lentip, arrayServicios, lenser);
            indice = 0;
        }
    }

    if(indice == -1)
    {
        printf("No hay trabajos que mostrar\n");
    }
}
