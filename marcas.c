#include "marcas.h"

/** \brief Hace un listado de todas las marcas
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void listarMarcas(eMarca arrayMarcas[], int lenmar)
{
    int i;

    printf("*** LISTADO DE MARCAS ***\n");
    for(i=0; i<lenmar; i++)
    {
        printf("%d      %s\n", arrayMarcas[i].id, arrayMarcas[i].descripcion);
    }
    printf("\n");
}
