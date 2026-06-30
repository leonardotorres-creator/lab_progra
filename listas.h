#ifndef LISTA_H
#define LISTA_H

typedef struct
{
    int codigo;
    char titulo[100];
    char autor[50];
} Libro;

typedef struct Nodo
{
    Libro dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
} Nodo;

Nodo* crearNodo(Libro t);

void insertarInicio(Nodo **cab, Libro t);
void insertarFinal(Nodo **cab, Libro t);

Nodo* buscarPorCodigo(Nodo *cab, int codigo);

void eliminarNodo(Nodo **cab, int codigo);

void mostrarAdelante(Nodo *cab);
void mostrarAtras(Nodo *cab);

void liberarLista(Nodo **cab);

void moverEntreListas(Nodo **origen,Nodo **destino,int codigo);

#endif