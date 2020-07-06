#include "trabajos.h"

/** \brief Inicializa los trabajos poniendo el campo ocupado en 0
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void inicializarTrabajos(eTrabajo arrayTrabajos[], int lentra)
{
    int i;

    for(i=0; i<lentra; i++)
    {
        if(arrayTrabajos[i].ocupado != 1)
        {
            arrayTrabajos[i].ocupado = 0;
        }
    }
}



/** \brief Busca un trabajo libre
 *
 * \param int i;
 * \param int indice = -1;
 * \return Devuelve el indice;
 *
 */
int buscarTrabajoLibre(eTrabajo arrayTrabajos[], int lentra)
{
    int i;
    int indice = -1;

    for(i=0; i<lentra; i++)
    {
        if(arrayTrabajos[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int generarIdTrabajo(eTrabajo arrayTrabajos[], int tamtra)
{
    int id, maximo, flag = 0;

    for(int i=0; i<tamtra; i++)
    {
        if(flag == 0 && arrayTrabajos[i].ocupado == 1)
        {
            maximo = arrayTrabajos[i].id;
            flag = 1;
        }
        else
        {
            if(maximo < arrayTrabajos[i].id && arrayTrabajos[i].ocupado == 1)
            {
                maximo = arrayTrabajos[i].id;
            }
        }
    }

    id = maximo + 1;

    return id;
}


/** \brief Da de alta un trabajo
 *
 * \param int idNot, idServicio;
 * \param int indice, i, j;
 * \return No devuelve nada.
 *
 */
void altaTrabajo(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eTrabajo arrayTrabajos[], int lentra, eCliente arrayClientes[], int tamcli)
{
    int idNot;
    int idServicio;
    int indice;
    int i, j;

    indice = buscarTrabajoLibre(arrayTrabajos, lentra);

    if(indice != -1)
    {
        listarNotebooks(arrayNotebooks, len, arrayMarcas, lenmar, arrayTipos, lentip, arrayClientes, tamcli);

        printf("Ingrese el ID de la notebook que desea asignarle un trabajo: ");
        fflush(stdin);
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
        fflush(stdin);
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

        arrayTrabajos[indice].id = generarIdTrabajo(arrayTrabajos, lentra);

        arrayTrabajos[indice].ocupado = 1;

        printf("Trabajo asignado con exito!\n\n");
    }
}


void listarTrabajo(eTrabajo pTrabajo, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eCliente arrayClientes[], int tamcli)
{
    int i;

    printf("ID TRABAJO: %d\n", pTrabajo.id);

    for(i=0; i<len; i++)
    {
        if(pTrabajo.idNotebook == arrayNotebooks[i].id && pTrabajo.ocupado == 1)
        {
            printf("Notebook: ");
            listarNotebook(arrayNotebooks[i], arrayMarcas, lenmar, arrayTipos, lentip, arrayClientes, tamcli);
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



void listarTrabajos(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eCliente arrayClientes[], int tamcli)
{
    int i;
    int indice = -1;

    printf("*** LISTADO DE TRABAJOS ***\n");

    for(i=0; i<lentra; i++)
    {
        if(arrayTrabajos[i].ocupado == 1)
        {
            listarTrabajo(arrayTrabajos[i], arrayNotebooks, len, arrayMarcas, lenmar, arrayTipos, lentip, arrayServicios, lenser, arrayClientes, tamcli);
            indice = 0;
        }
    }

    if(indice == -1)
    {
        printf("No hay trabajos que mostrar\n");
    }
}





/** \brief Recorro los trabajos y busco que sea igual a la id de la notebook insertada.
 *
 * \param int idNote;
 * \param int i;
 * \return No devuelve nada.
 *
 */
void trabajosAUnaNote(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eCliente arrayClientes[], int tamcli)
{
    int idNote;
    int i;

    listarNotebooks(arrayNotebooks, len, arrayMarcas, lenmar, arrayTipos, lentip, arrayClientes, tamcli);

    printf("Ingrese la ID de una notebook: ");
    scanf("%d", &idNote);

    for(i=0; i<lentra; i++)
    {
        if(arrayTrabajos[i].ocupado == 1)
        {
            if(idNote == arrayTrabajos[i].idNotebook)
            {
                listarTrabajo(arrayTrabajos[i], arrayNotebooks, len, arrayMarcas, lenmar, arrayTipos, lentip, arrayServicios, lenser, arrayClientes, tamcli);
            }
        }
    }

}



void sumaDeServiciosAUnaNote(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eCliente arrayClientes[], int tamcli)
{
    int precio = 0;
    int idNote;
    int i;

    listarNotebooks(arrayNotebooks, len, arrayMarcas, lenmar, arrayTipos, lentip, arrayClientes, tamcli);

    printf("Ingrese la ID de una notebook: ");
    scanf("%d", &idNote);

    for(i=0; i<lentra; i++)
    {
        if(arrayTrabajos[i].ocupado == 1)
        {
            for(int j=0; j<lenser; j++)
            {
                if(arrayTrabajos[i].idServicio == arrayServicios[j].id && idNote == arrayTrabajos[i].idNotebook)
                {
                    precio += arrayServicios[j].precio;
                }
            }
        }
    }

    printf("La suma de los importes es: %d\n\n", precio);
}


void pedirServicio(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eCliente arrayClientes[], int tamcli)
{
    int idServicio;

    listarServicios(arrayServicios, lenser);

    printf("Ingrese el ID de un servicio: ");
    fflush(stdin);
    scanf("%d", &idServicio);

    printf("\n\n");

    for(int i=0; i<lentra; i++)
    {
        if(arrayTrabajos[i].ocupado == 1 && arrayTrabajos[i].idServicio == idServicio)
        {
            listarTrabajo(arrayTrabajos[i], arrayNotebooks, len, arrayMarcas, lenmar, arrayTipos, lentip, arrayServicios, lenser, arrayClientes, tamcli);
        }
    }
}


void pedirFecha(eTrabajo arrayTrabajos[], int lentra, eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip, eServicio arrayServicios[], int lenser, eCliente arrayClientes[], int tamcli)
{
    int dia, mes, anio;
    int todoOk = 0;

    printf("Ingrese el dia: ");
    fflush(stdin);
    scanf("%d", &dia);
    printf("Ingrese el mes: ");
    fflush(stdin);
    scanf("%d", &mes);
    printf("Ingrese el anio: ");
    fflush(stdin);
    scanf("%d", &anio);

    for(int i=0; i<lentra; i++)
    {
        if(arrayTrabajos[i].ocupado == 1 && arrayTrabajos[i].fecha.dia == dia && arrayTrabajos[i].fecha.mes == mes && arrayTrabajos[i].fecha.anio == anio)
        {
            for(int j=0; j<lenser; j++)
            {
                if(arrayServicios[j].id == arrayTrabajos[i].idServicio)
                {
                    listarTrabajo(arrayTrabajos[i], arrayNotebooks, len, arrayMarcas, lenmar, arrayTipos, lentip, arrayServicios, lenser, arrayClientes, tamcli);
                    todoOk = 1;
                }
            }
        }
    }

    if(todoOk == 0)
    {
        printf("No hay trabajos en esa fecha\n\n");
    }
}
