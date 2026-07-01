#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tareas.h"
#include "kanban.h"
#include "estadisticas.h"
#include "colors.h"

// Prototipos locales
void buscarPorCodigoMain(Nodo *cab);
void buscarPorResponsableMain(Nodo *cab);
void guardarEnArchivo(Nodo *cab);
void cargarDesdeArchivo(Nodo **cab);

int main() {
    Nodo *lista = NULL;
    int op;

    cargarDesdeArchivo(&lista);

    do {
        printf(YELLOW"\n===== MENU =====\n");
        printf("1. Registrar tarea\n");
        printf("2. Mostrar Kanban\n");
        printf("3. Buscar por codigo\n");
        printf("4. Buscar por responsable\n");
        printf("5. Cambiar estado\n");
        printf("6. Eliminar tarea\n");
        printf("7. Estadisticas\n");
        printf("0. Salir\n");
        printf("Opcion: "RESET);
        scanf("%d", &op);

        switch(op) {
            case 1: 
                registrarTarea(&lista); 
                guardarEnArchivo(lista);
                break;
            case 2: 
                mostrarKanban(lista); 
                break;
            case 3: 
                buscarPorCodigoMain(lista); 
                break;
            case 4: 
                buscarPorResponsableMain(lista); 
                break;
            case 5: 
                cambiarEstado(lista); 
                guardarEnArchivo(lista);
                break;
            case 6: 
                eliminarTarea(&lista); 
                guardarEnArchivo(lista);
                break;
            case 7: 
                mostrarEstadisticas(lista); 
                break;
        }

    } while(op != 0);

    // Guardado final y liberación de memoria RAM
    guardarEnArchivo(lista);
    liberarLista(&lista);

    return 0;
}

// ================= FUNCIONES I/O =================

void cargarDesdeArchivo(Nodo **cab) {
    FILE *archivo = fopen("tareas.txt", "r");
    if (archivo == NULL) return; // Si no existe aún, iniciamos vacío
    
    Tarea t;
    // Utilizamos un formato estricto para evitar leer comas como datos
    while (fscanf(archivo, "%d,%[^,],%[^,],%[^,],%[^\n]\n", &t.codigo, t.titulo, t.responsable, t.prioridad, t.estado) != EOF) {
        insertarFinal(cab, t);
    }
    fclose(archivo);
}

void guardarEnArchivo(Nodo *cab) {
    FILE *archivo = fopen("tareas.txt", "w");
    if (archivo == NULL) {
        printf(RED"Error al abrir archivo para guardar\n"RESET);
        return;
    }

    Nodo *aux = cab;
    while(aux != NULL) {
        fprintf(archivo, "%d,%s,%s,%s,%s\n",
            aux->dato.codigo,
            aux->dato.titulo,
            aux->dato.responsable,
            aux->dato.prioridad,
            aux->dato.estado);
        aux = aux->sig;
    }

    fclose(archivo);
}

// ================= BUSQUEDAS =================

void buscarPorCodigoMain(Nodo *cab) {
    int codigo;

    printf(BLUE"Codigo: "RESET);
    scanf("%d", &codigo);

    Nodo *aux = buscarPorCodigo(cab, codigo);
    if(aux != NULL) {
        printf(GREEN"\nEncontrada:\n"RESET);
        printf(BLUE"%d - %s - %s - %s - %s\n"RESET,
            aux->dato.codigo, aux->dato.titulo,
            aux->dato.responsable, aux->dato.prioridad,
            aux->dato.estado);
    } else {
        printf(RED"No encontrada\n"RESET);
    }
}

void buscarPorResponsableMain(Nodo *cab) {
    char nombre[50];
    int encontrado = 0;

    printf(BLUE"Responsable: "RESET);
    scanf(" %[^\n]", nombre);

    Nodo *aux = cab;
    while(aux != NULL) {
        if(strcmp(aux->dato.responsable, nombre) == 0) {
            printf("[%d] %s (%s)\n",
                aux->dato.codigo, aux->dato.titulo, aux->dato.estado);
            encontrado = 1;
        }
        aux = aux->sig;
    }

    if(!encontrado)
        printf(RED"No hay tareas para ese responsable\n"RESET);
}