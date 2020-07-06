#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int ocupado;
}eCliente;

int generarIdCliente(eCliente arrayClientes[], int tamcli);
int buscarClienteLibre(eCliente arrayClientes[], int tamcli);
void mostrarClientes(eCliente arrayClientes[], int tamcli);

#endif // CLIENTES_H_INCLUDED
