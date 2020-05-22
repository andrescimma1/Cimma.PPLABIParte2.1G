#include "tipos.h"

/** \brief Hace un listado de todos los tipos
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void listarTipos(eTipo arrayTipos[], int lentip)
{
    int i;

    printf("*** LISTADO DE TIPOS ***\n");
    for(i=0; i<lentip; i++)
    {
        printf("%d      %s\n", arrayTipos[i].id, arrayTipos[i].descripcion);
    }
    printf("\n");
}
