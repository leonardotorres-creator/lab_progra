#include <stdio.h>
#include <string.h>
#include "tareas.h"
#include "kanban.h"
#include "estadisticas.h"

// Prototipos extra
void buscarPorCodigo(Tarea tareas[], int n);
void buscarPorResponsable(Tarea tareas[], int n);

int main() {
    Tarea tareas[100];
    int n = 0;
    int op;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Registrar tarea\n");
        printf("2. Mostrar Kanban\n");
        printf("3. Buscar por codigo\n");
        printf("4. Buscar por responsable\n");
        printf("5. Cambiar estado\n");
        printf("6. Eliminar tarea\n");
        printf("7. Estadisticas\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);

        switch(op) {
            case 1: registrarTarea(tareas, &n); break;
            case 2: mostrarKanban(tareas, n); break;
            case 3: buscarPorCodigo(tareas, n); break;
            case 4: buscarPorResponsable(tareas, n); break;
            case 5: cambiarEstado(tareas, n); break;
            case 6: eliminarTarea(tareas, &n); break;
            case 7: mostrarEstadisticas(tareas, n); break;
        }

    } while(op != 0);

    return 0;
}

// FUNCIONES DE BUSQUEDA

void buscarPorCodigo(Tarea tareas[], int n) {
    int codigo, i;

    printf("Codigo: ");
    scanf("%d", &codigo);

    for(i = 0; i < n; i++) {
        if(tareas[i].codigo == codigo) {
            printf("\nEncontrada:\n");
            printf("%d - %s - %s - %s - %s\n",
                tareas[i].codigo,
                tareas[i].titulo,
                tareas[i].responsable,
                tareas[i].prioridad,
                tareas[i].estado);
            return;
        }
    }

    printf("No encontrada\n");
}

void buscarPorResponsable(Tarea tareas[], int n) {
    char nombre[50];
    int i, encontrado = 0;

    printf("Responsable: ");
    scanf(" %[^\n]", nombre);

    for(i = 0; i < n; i++) {
        if(strcmp(tareas[i].responsable, nombre) == 0) {
            printf("[%d] %s (%s)\n",
                tareas[i].codigo,
                tareas[i].titulo,
                tareas[i].estado);
            encontrado = 1;
        }
    }

    if(!encontrado)
        printf("No hay tareas para ese responsable\n");
}