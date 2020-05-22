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
