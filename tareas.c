#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tareas.h"
#include "colors.h"

Nodo* crearNodo(Tarea n) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if(nuevo != NULL) {
        nuevo->dato = n;
        nuevo->ant = NULL;
        nuevo->sig = NULL;
    }
    return nuevo;
}

void insertarFinal(Nodo **cab, Tarea n) {
    Nodo *nuevo = crearNodo(n);
    if(nuevo == NULL) return;

    if(*cab == NULL) {
        *cab = nuevo;
        return;
    }

    Nodo *aux = *cab;
    while(aux->sig != NULL)
        aux = aux->sig;

    aux->sig = nuevo;
    nuevo->ant = aux;
}

Nodo* buscarPorCodigo(Nodo *cab, int codigo) {
    Nodo *aux = cab;
    while(aux != NULL) {
        if(aux->dato.codigo == codigo)
            return aux;
        aux = aux->sig;
    }
    return NULL;
}

void registrarTarea(Nodo **cab) {
    Tarea nueva;

    printf(WHITE"Codigo: "RESET);
    scanf("%d", &nueva.codigo);

    if(buscarPorCodigo(*cab, nueva.codigo) != NULL) {
        printf(RED"Error: Codigo repetido\n"RESET);
        return;
    }

    printf(WHITE"Titulo: "RESET);
    scanf(" %[^\n]", nueva.titulo);
    printf(WHITE"Responsable: "RESET);
    scanf(" %[^\n]", nueva.responsable);
    printf(WHITE"Prioridad (Alta/Media/Baja): "RESET);
    scanf("%s", nueva.prioridad);
    strcpy(nueva.estado, "Pendiente");

    insertarFinal(cab, nueva);
    printf(GREEN"Tarea registrada correctamente\n"RESET);
}

void eliminarNodo(Nodo **cab, int codigo) {
    Nodo *aux = buscarPorCodigo(*cab, codigo);

    if(aux == NULL) {
        printf(RED"No existe el codigo\n"RESET);
        return;
    }

    if(aux->ant == NULL && aux->sig == NULL) {
        *cab = NULL; // Único nodo
    } else if(aux->ant == NULL) {
        *cab = aux->sig; // Primer nodo
        (*cab)->ant = NULL;
    } else if(aux->sig == NULL) {
        aux->ant->sig = NULL; // Último nodo
    } else {
        aux->ant->sig = aux->sig; // Nodo intermedio
        aux->sig->ant = aux->ant;
    }

    free(aux);
}

void eliminarTarea(Nodo **cab) {
    int codigo;
    printf(GRAY"Codigo a eliminar: "RESET);
    scanf("%d", &codigo);
    
    Nodo *aux = buscarPorCodigo(*cab, codigo);
    if(aux != NULL) {
        eliminarNodo(cab, codigo);
        printf(ORANGE"Tarea eliminada\n"RESET);
    } else {
        printf(RED"No encontrada\n"RESET);
    }
}

void liberarLista(Nodo **cab) {
    Nodo *aux;
    while(*cab != NULL) {
        aux = *cab;
        *cab = (*cab)->sig;
        free(aux);
    }
}