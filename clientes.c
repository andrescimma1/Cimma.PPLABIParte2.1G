#include "clientes.h"

int generarIdCliente(eCliente arrayClientes[], int tamcli)
{
    int id, maximo, flag = 0;

    for(int i=0; i<tamcli; i++)
    {
        if(flag == 0 && arrayClientes[i].ocupado == 1)
        {
            maximo = arrayClientes[i].id;
            flag = 1;
        }
        else
        {
            if(maximo < arrayClientes[i].id && arrayClientes[i].ocupado == 1)
            {
                maximo = arrayClientes[i].id;
            }
        }
    }

    id = maximo + 1;

    return id;
}

int buscarClienteLibre(eCliente arrayClientes[], int tamcli)
{
    int i;
    int indice = -1;

    for(i=0; i<tamcli; i++)
    {
        if(arrayClientes[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


void mostrarClientes(eCliente arrayClientes[], int tamcli)
{
    printf("Clientes\n\n");
    printf("ID    Nombre     Sexo\n");
    printf("---------------------\n");


    for(int i=0; i<tamcli; i++)
    {
        if(arrayClientes[i].ocupado == 1)
        {
            printf("%d    %13s    %c\n", arrayClientes[i].id, arrayClientes[i].nombre, arrayClientes[i].sexo);
        }
    }

}
