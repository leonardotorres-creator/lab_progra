#ifndef TAREAS_H
#define TAREAS_H

typedef struct {
    int codigo;
    char titulo[100];
    char responsable[50];
    char prioridad[10];
    char estado[20];
} Tarea;

typedef struct Nodo {
    Tarea dato;
    struct Nodo *ant;
    struct Nodo *sig;
} Nodo;

// Funciones principales
void registrarTarea(Nodo **cab);
void eliminarTarea(Nodo **cab);

// Utilidades de la lista doblemente enlazada
Nodo* crearNodo(Tarea n);
void insertarFinal(Nodo **cab, Tarea n);
Nodo* buscarPorCodigo(Nodo *cab, int codigo);
void eliminarNodo(Nodo **cab, int codigo);
void liberarLista(Nodo **cab);

#endif