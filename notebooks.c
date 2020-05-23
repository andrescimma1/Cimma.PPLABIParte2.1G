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

    printf("%d     %7s    %7s    %7s   %d    %d    %10s    %c\n", pNotebook.id, pNotebook.modelo, marcaEncontrada, tipoEncontrado, pNotebook.precio, pNotebook.cliente.id, pNotebook.cliente.nombre, pNotebook.cliente.sexo);
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
    int auxIDcliente;
    char auxNombre[20];
    char auxSexo;
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
                        auxIDcliente = arrayNotebooks[i].cliente.id;
                        arrayNotebooks[i].cliente.id = arrayNotebooks[k].cliente.id;
                        arrayNotebooks[k].cliente.id = auxIDcliente;
                        strcpy(auxNombre, arrayNotebooks[i].cliente.nombre);
                        strcpy(arrayNotebooks[i].cliente.nombre, arrayNotebooks[k].cliente.nombre);
                        strcpy(arrayNotebooks[k].cliente.nombre, auxNombre);
                        auxSexo = arrayNotebooks[i].cliente.sexo;
                        arrayNotebooks[i].cliente.sexo = arrayNotebooks[k].cliente.sexo;
                        arrayNotebooks[k].cliente.sexo = auxSexo;

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
                        auxIDcliente = arrayNotebooks[k].cliente.id;
                        arrayNotebooks[k].cliente.id = arrayNotebooks[i].cliente.id;
                        arrayNotebooks[i].cliente.id = auxIDcliente;
                        strcpy(auxNombre, arrayNotebooks[k].cliente.nombre);
                        strcpy(arrayNotebooks[k].cliente.nombre, arrayNotebooks[i].cliente.nombre);
                        strcpy(arrayNotebooks[i].cliente.nombre, auxNombre);
                        auxSexo = arrayNotebooks[k].cliente.sexo;
                        arrayNotebooks[k].cliente.sexo = arrayNotebooks[i].cliente.sexo;
                        arrayNotebooks[i].cliente.sexo = auxSexo;
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
                            auxIDcliente = arrayNotebooks[i].cliente.id;
                            arrayNotebooks[i].cliente.id = arrayNotebooks[k].cliente.id;
                            arrayNotebooks[k].cliente.id = auxIDcliente;
                            strcpy(auxNombre, arrayNotebooks[i].cliente.nombre);
                            strcpy(arrayNotebooks[i].cliente.nombre, arrayNotebooks[k].cliente.nombre);
                            strcpy(arrayNotebooks[k].cliente.nombre, auxNombre);
                            auxSexo = arrayNotebooks[i].cliente.sexo;
                            arrayNotebooks[i].cliente.sexo = arrayNotebooks[k].cliente.sexo;
                            arrayNotebooks[k].cliente.sexo = auxSexo;
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
                            auxIDcliente = arrayNotebooks[k].cliente.id;
                            arrayNotebooks[k].cliente.id = arrayNotebooks[i].cliente.id;
                            arrayNotebooks[i].cliente.id = auxIDcliente;
                            strcpy(auxNombre, arrayNotebooks[k].cliente.nombre);
                            strcpy(arrayNotebooks[k].cliente.nombre, arrayNotebooks[i].cliente.nombre);
                            strcpy(arrayNotebooks[i].cliente.nombre, auxNombre);
                            auxSexo = arrayNotebooks[k].cliente.sexo;
                            arrayNotebooks[k].cliente.sexo = arrayNotebooks[i].cliente.sexo;
                            arrayNotebooks[i].cliente.sexo = auxSexo;
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
    printf("_______________________________________________________________________________\n");
    printf("ID     MODELO     MARCA     TIPO     PRECIO      IDCLIENTE     NOMBRE      SEXO\n");

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

        arrayNotebooks[indice].cliente.id = arrayNotebooks[indice].id;

        printf("Ingrese el nombre del cliente: ");
        fflush(stdin);
        gets(arrayNotebooks[indice].cliente.nombre);

        printf("Ingrese el sexo del cliente: ");
        scanf("%c", &arrayNotebooks[indice].cliente.sexo);

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
    printf("1. Mostrar las notebooks del tipo seleccionado por el usuario.\n");
    printf("2. Mostrar notebooks de una marca seleccionada.\n");
    printf("3. Informar la o las notebooks mas baratas\n");
    printf("4. Mostrar un listado de las notebooks separadas por marca.\n");
    printf("5. Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa marca.\n");
    printf("6. Mostrar la o las marcas mas elegidas por los clientes.\n\n");
    printf("7. Pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma.\n");

    printf("\n");



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




/** \brief Pide al usuario el ID del tipo deseado, y muestra las notebooks con ese tipo.
 *
 * \param int indice = -1;
 * \param int idTipo, i, j;
 * \return No devuelve nada.
 *
 */
void mostrarNotebooksPorTipoSeleccionado(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip)
{
    int indice = -1;
    int idTipo;
    int i, j;

    listarTipos(arrayTipos, lentip);

    printf("Ingrese el ID del tipo: ");
    scanf("%d", &idTipo);

    for(i=0; i<len; i++)
    {
        if(arrayNotebooks[i].ocupado == 1)
        {
            for(j=0; j<lentip; j++)
            {
                if(arrayTipos[j].id == idTipo && arrayNotebooks[i].idTipo == idTipo)
                {
                    listarNotebook(arrayNotebooks[i], arrayMarcas, lenmar, arrayTipos, lentip);
                    indice = 0;
                }
            }
        }
    }

    if(indice == -1)
    {
        printf("No hay notebooks de ese tipo\n\n");
    }

}




/** \brief Pide al usuario el ID de la marca deseada, y muestra las notebooks con esa marca.
 *
 * \param int indice = -1;
 * \param int idTipo, i, j;
 * \return No devuelve nada.
 *
 */
void mostrarNotebooksPorMarcaSeleccionada(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip)
{
    int indice = -1;
    int idMarca;
    int i, j;

    listarMarcas(arrayMarcas, lenmar);

    printf("Ingrese el ID de la marca: ");
    scanf("%d", &idMarca);

    for(i=0; i<len; i++)
    {
        if(arrayNotebooks[i].ocupado == 1)
        {
            for(j=0; j<lenmar; j++)
            {
                if(arrayMarcas[j].id == idMarca && arrayNotebooks[i].idMarca == idMarca)
                {
                    listarNotebook(arrayNotebooks[i], arrayMarcas, lenmar, arrayTipos, lentip);
                    indice = 0;
                }
            }
        }
    }

    if(indice == -1)
    {
        printf("No hay notebooks de esa marca\n\n");
    }

}



/** \brief Recorre las notebooks y compara cual tiene menor precio, y almacena la posicion del array en una variable.
 *
 * \param int i, j, minimoPosicionArray;
 * \param int flag = 0;
 * \return No devuelve nada.
 *
 */
void informarLaOLasNotebooksMasBaratas(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip)
{
    int i, j;
    int minimoPosicionArray;
    int flag = 0;

    for(i=0; i<len ;i++)
    {
        if(arrayNotebooks[i].ocupado == 1)
        {
            for(j=i+1; j<len; j++)
            {
                if(arrayNotebooks[j].ocupado == 1)
                {
                    if(arrayNotebooks[i].precio < arrayNotebooks[j].precio && arrayNotebooks[i].precio < minimoPosicionArray)
                    {
                        minimoPosicionArray = i;
                        flag = 1;
                    }
                    else if(arrayNotebooks[i].precio > arrayNotebooks[j].precio && arrayNotebooks[j].precio < minimoPosicionArray)
                    {
                        minimoPosicionArray = j;
                        flag = 1;
                    }

                }
            }
        }
    }

    if(flag == 1)
    {
        listarNotebook(arrayNotebooks[minimoPosicionArray], arrayMarcas, lenmar, arrayTipos, lentip);
    }
    else
    {
        printf("No hay notebooks para comparar\n\n");
    }
}



/** \brief Recorre las notebooks y las separa por marca
 *
 * \param int i;
 * \param
 * \return No devuelve nada.
 *
 */
void separarPorMarca(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip)
{
    int i;

    printf("*** NOTEBOOKS SEPARADAS POR MARCA ***\n\n");
    for(i=0; i<len; i++)
    {
        if(arrayNotebooks[i].ocupado == 1)
        {
            if(arrayNotebooks[i].idMarca == 1000)
            {
                listarNotebook(arrayNotebooks[i], arrayMarcas, lenmar, arrayTipos, lentip);
            }
        }
    }

    printf("\n");

    for(i=0; i<len; i++)
    {
        if(arrayNotebooks[i].ocupado == 1)
        {
            if(arrayNotebooks[i].idMarca == 1001)
            {
                listarNotebook(arrayNotebooks[i], arrayMarcas, lenmar, arrayTipos, lentip);
            }
        }
    }
    printf("\n");


    for(i=0; i<len; i++)
    {
        if(arrayNotebooks[i].ocupado == 1)
        {
            if(arrayNotebooks[i].idMarca == 1002)
            {
                listarNotebook(arrayNotebooks[i], arrayMarcas, lenmar, arrayTipos, lentip);
            }
        }
    }
    printf("\n");

    for(i=0; i<len; i++)
    {
        if(arrayNotebooks[i].ocupado == 1)
        {
            if(arrayNotebooks[i].idMarca == 1003)
            {
                listarNotebook(arrayNotebooks[i], arrayMarcas, lenmar, arrayTipos, lentip);
            }
        }
    }
}



/** \brief Pide al usuario el id del tipo y de la marca y busca cuantas hay con esos valores.
 *
 * \param int idTipo, idMarca, cont = 0;
 * \param int i, j, k;
 * \return No devuelve nada.
 *
 */
void mostrarNotebooksPorTipoYMarca(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar, eTipo arrayTipos[], int lentip)
{
    int idTipo;
    int idMarca;
    int cont = 0;
    int i, j, k;

    listarTipos(arrayTipos, lentip);
    printf("Ingrese el ID del tipo: ");
    scanf("%d", &idTipo);

    listarMarcas(arrayMarcas, lenmar);
    printf("Ingrese el ID de la marca: ");
    scanf("%d", &idMarca);


    for(i=0; i<len; i++)
    {
        if(arrayNotebooks[i].ocupado == 1)
        {
            for(j=0; j<lentip; j++)
            {
                for(k=0; k<lenmar; k++)
                {
                    if(arrayNotebooks[i].idMarca == arrayMarcas[k].id && arrayNotebooks[i].idTipo == arrayTipos[j].id && arrayNotebooks[i].idMarca == idMarca && arrayNotebooks[i].idTipo == idTipo)
                    {
                        cont++;
                    }
                }
            }
        }
    }


    if(cont == 0)
    {
        printf("No hay notebooks de ese tipo y esa marca.\n\n");
    }
    else
    {
        printf("Hay %d notebook/s de ese tipo y de esa marca.\n\n", cont);
    }


}





/** \brief Busca la marca mas elegida mediante contadores, despues compara el tamaño de los contadores para saber cual es la marca mas elegida.
 *
 * \param int i, j;
 * \param int contCompaq = 0, contAsus = 0, contAcer = 0, contHP = 0;
 * \return No devuelve nada.
 *
 */
void mostrarLaOLasMarcasMasElegidas(eNotebook arrayNotebooks[], int len, eMarca arrayMarcas[], int lenmar)
{
    int i, j;
    int contCompaq = 0;
    int contAsus = 0;
    int contAcer = 0;
    int contHP = 0;

    for(i=0; i<len; i++)
    {
        if(arrayNotebooks[i].ocupado == 1)
        {
            for(j=0; j<lenmar; j++)
            {
                if(arrayNotebooks[i].idMarca == arrayMarcas[j].id && arrayNotebooks[i].idMarca == 1000)
                {
                    contCompaq++;
                    /*{1000, "Compaq"},
                           {1001, "Asus"},
                           {1002, "Acer"},
                           {1003, "HP"}*/
                }
                if(arrayNotebooks[i].idMarca == arrayMarcas[j].id && arrayNotebooks[i].idMarca == 1001)
                {
                    contAsus++;
                }
                if(arrayNotebooks[i].idMarca == arrayMarcas[j].id && arrayNotebooks[i].idMarca == 1002)
                {
                    contAcer++;
                }
                if(arrayNotebooks[i].idMarca == arrayMarcas[j].id && arrayNotebooks[i].idMarca == 1003)
                {
                    contHP++;
                }
            }
        }
    }


    if(contCompaq > contAcer && contCompaq > contAsus && contCompaq > contHP)
    {
        printf("Compaq es la marca mas elegida por los clientes.\n\n");
    }
    else if(contAcer > contCompaq && contAcer > contAsus && contAcer > contHP)
    {
        printf("Acer es la marca mas elegida por los clientes.\n\n");
    }
    else if(contAsus > contAcer && contAsus > contCompaq && contAsus > contHP)
    {
        printf("Asus es la marca mas elegida por los clientes.\n\n");
    }
    else if(contHP > contAcer && contHP > contAsus && contHP > contCompaq)
    {
        printf("HP es la marca mas elegida por los clientes.\n\n");
    }
    else
    {
        printf("No hay notebooks ingresadas.\n\n");
    }
}
