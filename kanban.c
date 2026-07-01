#include <stdio.h>
#include <string.h>
#include "kanban.h"
#include "colors.h"

void mostrarKanban(Nodo *cab) {
    Nodo *aux;

    printf(CYAN"\n===== PENDIENTES =====\n"RESET);
    aux = cab;
    while(aux != NULL) {
        if(strcmp(aux->dato.estado, "Pendiente") == 0)
            printf(GRAY"[%d] %s\n"RESET, aux->dato.codigo, aux->dato.titulo);
        aux = aux->sig;
    }

    printf(CYAN"\n===== EN PROGRESO =====\n"RESET);
    aux = cab;
    while(aux != NULL) {
        if(strcmp(aux->dato.estado, "En Progreso") == 0)
            printf(MAGENTA"[%d] %s\n"RESET, aux->dato.codigo, aux->dato.titulo);
        aux = aux->sig;
    }

    printf(CYAN"\n===== FINALIZADAS =====\n"RESET);
    aux = cab;
    while(aux != NULL) {
        if(strcmp(aux->dato.estado, "Finalizada") == 0)
            printf(GREEN"[%d] %s\n"RESET, aux->dato.codigo, aux->dato.titulo);
        aux = aux->sig;
    }
}

void cambiarEstado(Nodo *cab) {
    int codigo, op;

    printf(YELLOW"Codigo de tarea: "RESET);
    scanf("%d", &codigo);

    Nodo *aux = buscarPorCodigo(cab, codigo);
    if(aux != NULL) {
        printf(YELLOW"1. Pendiente\n2. En Progreso\n3. Finalizada\n"RESET);
        printf(YELLOW"Nuevo estado: "RESET);
        scanf("%d", &op);

        if(op == 1)
            strcpy(aux->dato.estado, "Pendiente");
        else if(op == 2)
            strcpy(aux->dato.estado, "En Progreso");
        else if(op == 3)
            strcpy(aux->dato.estado, "Finalizada");
        else {
            printf(RED"Opcion invalida\n"RESET);
            return;
        }

        printf(GREEN"Estado actualizado\n"RESET);
    } else {
        printf(RED"Tarea no encontrada\n"RESET);
    }
}