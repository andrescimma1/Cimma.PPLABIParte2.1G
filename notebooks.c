#include "notebooks.h"



/** \brief Inicializa las id de las notebooks
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void inicializarNotebooks(eNotebook arrayNotebooks[], int tamnot)
{
    int i;
    for(i=0; i<tamnot; i++)
    {
        if(arrayNotebooks[i].ocupado != 1)
        {
            arrayNotebooks[i].ocupado = 0;
        }
    }
}



/** \brief Busca un espacio libre
 *
 * \param int i;
 * \param int indice = -1;
 * \return indice;
 *
 */
int buscarLibre(eNotebook arrayNotebooks[], int tamnot)
{
    int i;
    int indice = -1;

    for(i=0; i<tamnot; i++)
    {
        if(arrayNotebooks[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


void listarNotebook(eNotebook pNotebook, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip)
{
    int i;
    char marcaEncontrada[20];
    char tipoEncontrado[20];

    for(i=0; i<lenmar; i++)
    {
        if(pNotebook.idMarca == arrayMarcas[i].id && pNotebook.ocupado == 1)
        {
            strcpy(marcaEncontrada, arrayMarcas[i].descripcion);
        }
    }

    for(i=0; i<lentip; i++)
    {
        if(pNotebook.idTipo == arrayTipos[i].id && pNotebook.ocupado == 1)
        {
            strcpy(tipoEncontrado, arrayTipos[i].descripcion);
        }
    }

    printf("%d     %7s    %7s    %7s   %d\n", pNotebook.id, pNotebook.modelo, marcaEncontrada, tipoEncontrado, pNotebook.precio);
}



void ordenarPorMarcaYprecio(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip)
{
    int i, j, k;
    char marca1Encontrada[20];
    char marca2Encontrada[20];
    int auxID;
    char auxModelo[20];
    int auxIDMarca;
    int auxIDTipo;
    int auxPrecio;
    int indice = -1;

    for(i=0; i<len; i++)
    {
        for(k=i+1; k<len; k++)
        {
            for(j=0; j<lenmar; j++)
            {
                if(arrayNotebooks[i].ocupado == 1 && arrayNotebooks[i].idMarca == arrayMarcas[j].id)
                {
                    strcpy(marca1Encontrada, arrayMarcas[j].descripcion);
                    indice = 0;
                }

                if(arrayNotebooks[k].ocupado == 1 && arrayNotebooks[k].idMarca == arrayMarcas[j].id && indice == 0)
                {
                    strcpy(marca2Encontrada, arrayMarcas[j].descripcion);
                    indice = -1;
                    if(strcmp(marca1Encontrada, marca2Encontrada) > 1)
                    {
                        auxID = arrayNotebooks[i].id;
                        arrayNotebooks[i].id = arrayNotebooks[k].id;
                        arrayNotebooks[k].id = auxID;
                        strcpy(auxModelo, arrayNotebooks[i].modelo);
                        strcpy(arrayNotebooks[i].modelo, arrayNotebooks[k].modelo);
                        strcpy(arrayNotebooks[k].modelo, auxModelo);
                        auxIDMarca = arrayNotebooks[i].idMarca;
                        arrayNotebooks[i].idMarca = arrayNotebooks[k].idMarca;
                        arrayNotebooks[k].idMarca = auxIDMarca;
                        auxIDTipo = arrayNotebooks[i].idTipo;
                        arrayNotebooks[i].idTipo = arrayNotebooks[k].idTipo;
                        arrayNotebooks[k].idTipo = auxIDTipo;
                        auxPrecio = arrayNotebooks[i].precio;
                        arrayNotebooks[i].precio = arrayNotebooks[k].precio;
                        arrayNotebooks[k].precio = auxPrecio;
                    }
                    else if(strcmp(marca1Encontrada, marca2Encontrada) < 1)
                    {
                        auxID = arrayNotebooks[k].id;
                        arrayNotebooks[k].id = arrayNotebooks[i].id;
                        arrayNotebooks[i].id = auxID;
                        strcpy(auxModelo, arrayNotebooks[k].modelo);
                        strcpy(arrayNotebooks[k].modelo, arrayNotebooks[i].modelo);
                        strcpy(arrayNotebooks[i].modelo, auxModelo);
                        auxIDMarca = arrayNotebooks[k].idMarca;
                        arrayNotebooks[k].idMarca = arrayNotebooks[i].idMarca;
                        arrayNotebooks[i].idMarca = auxIDMarca;
                        auxIDTipo = arrayNotebooks[k].idTipo;
                        arrayNotebooks[k].idTipo = arrayNotebooks[i].idTipo;
                        arrayNotebooks[i].idTipo = auxIDTipo;
                        auxPrecio = arrayNotebooks[k].precio;
                        arrayNotebooks[k].precio = arrayNotebooks[i].precio;
                        arrayNotebooks[i].precio = auxPrecio;
                    }
                    else if(strcmp(marca1Encontrada, marca2Encontrada) == 0)
                    {
                        if(arrayNotebooks[i].precio > arrayNotebooks[k].precio)
                        {
                            auxID = arrayNotebooks[i].id;
                            arrayNotebooks[i].id = arrayNotebooks[k].id;
                            arrayNotebooks[k].id = auxID;
                            strcpy(auxModelo, arrayNotebooks[i].modelo);
                            strcpy(arrayNotebooks[i].modelo, arrayNotebooks[k].modelo);
                            strcpy(arrayNotebooks[k].modelo, auxModelo);
                            auxIDMarca = arrayNotebooks[i].idMarca;
                            arrayNotebooks[i].idMarca = arrayNotebooks[k].idMarca;
                            arrayNotebooks[k].idMarca = auxIDMarca;
                            auxIDTipo = arrayNotebooks[i].idTipo;
                            arrayNotebooks[i].idTipo = arrayNotebooks[k].idTipo;
                            arrayNotebooks[k].idTipo = auxIDTipo;
                            auxPrecio = arrayNotebooks[i].precio;
                            arrayNotebooks[i].precio = arrayNotebooks[k].precio;
                            arrayNotebooks[k].precio = auxPrecio;
                        }
                        else if(arrayNotebooks[i].precio < arrayNotebooks[k].precio)
                        {
                            auxID = arrayNotebooks[k].id;
                            arrayNotebooks[k].id = arrayNotebooks[i].id;
                            arrayNotebooks[i].id = auxID;
                            strcpy(auxModelo, arrayNotebooks[k].modelo);
                            strcpy(arrayNotebooks[k].modelo, arrayNotebooks[i].modelo);
                            strcpy(arrayNotebooks[i].modelo, auxModelo);
                            auxIDMarca = arrayNotebooks[k].idMarca;
                            arrayNotebooks[k].idMarca = arrayNotebooks[i].idMarca;
                            arrayNotebooks[i].idMarca = auxIDMarca;
                            auxIDTipo = arrayNotebooks[k].idTipo;
                            arrayNotebooks[k].idTipo = arrayNotebooks[i].idTipo;
                            arrayNotebooks[i].idTipo = auxIDTipo;
                            auxPrecio = arrayNotebooks[k].precio;
                            arrayNotebooks[k].precio = arrayNotebooks[i].precio;
                            arrayNotebooks[i].precio = auxPrecio;
                        }
                    }
                }
            }
        }

    }


}




/** \brief Muestra una lista con todas las notebooks.
 *
 * \param int i;
 * \param int indice = -1;
 * \return Devuelve -1 si no se encontraron notebooks, o devuelve 0 si se encontraron.
 *
 */
int listarNotebooks(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip)
{
    int i;
    int indice = -1;

    system("cls");

    ordenarPorMarcaYprecio(arrayNotebooks, len, arrayMarcas, lenmar, arrayTipos, lentip);

    printf("Listado de notebooks\n");
    printf("_______________________________________________\n");
    printf("ID     MODELO     MARCA     TIPO     PRECIO    \n");

    for(i=0; i<len; i++)
    {
        if(arrayNotebooks[i].ocupado == 1)
        {
            listarNotebook(arrayNotebooks[i], arrayMarcas, lenmar, arrayTipos, lentip);
            indice = 0;
        }
    }

    if(indice == -1)
    {
        printf("\nNo hay notebooks que mostrar\n\n");
    }

    printf("\n\n");

    return indice;
}





/** \brief Da de alta una notebook, pidiendole al usuario: modelo, marca, tipo y precio
 *
 * \param int indice;
 * \param
 * \return No devuelve nada.
 *
 */
void altaNotebook(eNotebook arrayNotebooks[], int tamnot, eMarca arrayMarcas[], int tammar, eTipo arrayTipos[], int tamtip)
{
    int indice;

    system("cls");

    indice = buscarLibre(arrayNotebooks, tamnot);

    if(indice == -1)
    {
        printf("No hay espacio libre\n\n");
    }
    else
    {
        printf("Ingrese ID de la notebook: ");
        scanf("%d", &arrayNotebooks[indice].id);

        printf("Ingrese modelo: ");
        fflush(stdin);
        gets(arrayNotebooks[indice].modelo);

        listarMarcas(arrayMarcas, tammar);
        printf("Ingrese ID de la marca: ");
        scanf("%d", &arrayNotebooks[indice].idMarca);

        listarTipos(arrayTipos, tamtip);
        printf("Ingrese ID del tipo: ");
        scanf("%d", &arrayNotebooks[indice].idTipo);

        printf("Ingrese el precio de la notebook: ");
        scanf("%d", &arrayNotebooks[indice].precio);

        arrayNotebooks[indice].ocupado = 1;
    }
}




/** \brief Menú de opciones, toma la opcion digitada por el usuario y la retorna para usarla en el switch
 *
 * \param char opcion;
 * \param
 * \return opcion;
 *
 */
int menu()
{
    char opcion;

    printf("*** MENU DE OPCIONES ***\n");
    printf("A. ALTA NOTEBOOK\n");
    printf("B. MODIFICAR NOTEBOOK\n");
    printf("C. BAJA NOTEBOOK\n");
    printf("D. LISTAR NOTEBOOKS\n");
    printf("E. LISTAR MARCAS\n");
    printf("F. LISTAR TIPOS\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. ALTA TRABAJO\n");
    printf("I. LISTAR TRABAJOS\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void modificarNotebook(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip)
{
    int i;
    int idnot;

    listarNotebooks(arrayNotebooks, len, arrayMarcas, lenmar, arrayTipos, lentip);
    printf("\n\n Ingrese la ID de la notebook que desea modificar: ");
    scanf("%d", &idnot);

    for(i=0; i<len; i++)
    {
        if(idnot == arrayNotebooks[i].id && arrayNotebooks[i].ocupado == 1)
        {
            switch(submenu())
            {
                case 1: printf("Ingrese el nuevo precio: ");
                        scanf("%d", &arrayNotebooks[i].precio);
                        printf("\nPrecio guardado con exito!");
                        system("pause");
                        break;

                case 2: listarTipos(arrayTipos, lentip);
                        printf("\nIngrese el ID del nuevo tipo: ");
                        scanf("%d", &arrayNotebooks[i].idTipo);
                        system("pause");
                        break;
                default: printf("\n\nOpcion incorrecta");
                         system("pause");
                         break;
            }
        }
    }

}


/** \brief Menú que permite elegir lo que se desea modificar de la notebook
 *
 * \param int opcion;
 * \param
 * \return opcion;
 *
 */
int submenu()
{
    int opcion;

    printf("\n\n*** ¿QUE DESEA MODIFICAR? ***\n");
    printf("1. Precio\n");
    printf("2. Tipo\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}




/** \brief Pide al usuario la id a dar de baja y realiza una baja lógica
 *
 * \param int idNot, i;
 * \param char opcion;
 * \return No devuelve nada.
 *
 */
void bajaNotebook(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip)
{
    int idNot;
    int i;
    char opcion;

    listarNotebooks(arrayNotebooks, len, arrayMarcas, lenmar, arrayTipos, lentip);

    printf("\nIngrese el ID de la notebook a dar de baja: ");
    scanf("%d", &idNot);

    for(i=0; i<len; i++)
    {
        if(idNot == arrayNotebooks[i].id && arrayNotebooks[i].ocupado == 1)
        {
            printf("Seguro? s/n: ");
            fflush(stdin);
            scanf("%c", &opcion);

            if(opcion == 's')
            {
                arrayNotebooks[i].ocupado = 0;
                printf("\nNotebook dada de baja con exito!\n");
            }
            else
            {
                printf("\nNo se ha completado la operacion\n");
            }
        }
    }
}
