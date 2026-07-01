
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

Nodo* crearNodo(Libro t)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));

    if(nuevo != NULL)
    {
        nuevo->dato = t;
        nuevo->anterior = NULL;
        nuevo->siguiente = NULL;
    }

    return nuevo;
}

void insertarInicio(Nodo **cab, Libro t)
{
    Nodo *nuevo = crearNodo(t);

    if(nuevo == NULL)
        return;

    nuevo->siguiente = *cab;

    if(*cab != NULL)
        (*cab)->anterior = nuevo;

    *cab = nuevo;
}

void insertarFinal(Nodo **cab, Libro t)
{
    Nodo *nuevo = crearNodo(t);

    if(nuevo == NULL)
        return;

    if(*cab == NULL)
    {
        *cab = nuevo;
        return;
    }

    Nodo *aux = *cab;

    while(aux->siguiente != NULL)
        aux = aux->siguiente;

    aux->siguiente = nuevo;
    nuevo->anterior = aux;
}

Nodo* buscarPorCodigo(Nodo *cab, int codigo)
{
    Nodo *aux = cab;

    while(aux != NULL)
    {
        if(aux->dato.codigo == codigo)
            return aux;

        aux = aux->siguiente;
    }

    return NULL;
}

void mostrarAdelante(Nodo *cab)
{
    Nodo *aux = cab;

    while(aux != NULL)
    {
        printf("\nCodigo: %d", aux->dato.codigo);
        printf("\nTitulo: %s", aux->dato.titulo);
        printf("\nAutor: %s", aux->dato.autor);

        aux = aux->siguiente;
    }
}

void mostrarAtras(Nodo *cab)
{
    if(cab == NULL)
        return;

    Nodo *aux = cab;

    while(aux->siguiente != NULL)
        aux = aux->siguiente;

    while(aux != NULL)
    {
        printf("\nCodigo: %d", aux->dato.codigo);
        printf("\nTitulo: %s", aux->dato.titulo);
        printf("\nAutor: %s", aux->dato.autor);

        aux = aux->anterior;
    }
}

void eliminarNodo(Nodo **cab, int codigo)
{
    Nodo *aux = buscarPorCodigo(*cab, codigo);

    if(aux == NULL)
    {
        printf("No existe el codigo\n");
        return;
    }

    /* único nodo */
    if(aux->anterior == NULL && aux->siguiente == NULL)
    {
        *cab = NULL;
    }

    /* primer nodo */
    else if(aux->anterior == NULL)
    {
        *cab = aux->siguiente;
        aux->siguiente->anterior = NULL;
    }

    /* último nodo */
    else if(aux->siguiente == NULL)
    {
        aux->anterior->siguiente = NULL;
    }

    /* nodo intermedio */
    else
    {
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
    }

    free(aux);
}

void liberarLista(Nodo **cab)
{
    Nodo *aux;

    while(*cab != NULL)
    {
        aux = *cab;
        *cab = (*cab)->siguiente;
        free(aux);
    }
}

void moverEntreListas(
        Nodo **origen,
        Nodo **destino,
        int codigo)
{
    Nodo *aux = buscarPorCodigo(*origen, codigo);

    if(aux == NULL)
        return;

    Libro t = aux->dato;

    eliminarNodo(origen, codigo);

    insertarFinal(destino, t);
}
