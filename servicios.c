#include "servicios.h"

/** \brief Recorre los servicios y los lista
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void listarServicios(eServicio arrayServicios[], int lenser)
{
    int i;

    printf("*** LISTADO DE SERVICIOS ***\n");
    for(i=0; i<lenser; i++)
    {
        printf("%d       %10s          %d\n", arrayServicios[i].id, arrayServicios[i].descripcion, arrayServicios[i].precio);
    }
}
