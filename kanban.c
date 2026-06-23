#include <stdio.h>
#include <string.h>
#include "kanban.h"

void mostrarKanban(Tarea tareas[], int *n) {
    int i;
    FILE *archivo = fopen("tareas.txt", "r");
    
    if (archivo == NULL) {
        printf("Error: El archivo tareas.txt no existe o no se pudo abrir.\n");
        return;
    }

    *n = 0; // Reiniciar el contador de tareas

// Ahora usamos comas para separar los campos y los juegos de caracteres [^,]
    while (fscanf(archivo, "%d,%[^,],%[^,],%[^,],%s\n", &tareas[*n].codigo, tareas[*n].titulo, tareas[*n].responsable, tareas[*n].prioridad, tareas[*n].estado) != EOF) {
        (*n)++;
    }

    printf("\n===== PENDIENTES =====\n");
    for(i = 0; i < *n; i++) {
        if(strcmp(tareas[i].estado, "Pendiente") == 0)
            printf("[%d] %s\n", tareas[i].codigo, tareas[i].titulo);
    }

    printf("\n===== EN PROGRESO =====\n");
    for(i = 0; i < *n; i++) {
        if(strcmp(tareas[i].estado, "En Progreso") == 0)
            printf("[%d] %s\n", tareas[i].codigo, tareas[i].titulo);
    }

    printf("\n===== FINALIZADAS =====\n");
    for(i = 0; i < *n; i++) {
        if(strcmp(tareas[i].estado, "Finalizada") == 0)
            printf("[%d] %s\n", tareas[i].codigo, tareas[i].titulo);
    }

    fclose (archivo);
}

void cambiarEstado(Tarea tareas[], int n) {
    int codigo, i, op;

    printf("Codigo de tarea: ");
    scanf("%d", &codigo);

    for(i = 0; i < n; i++) {
        if(tareas[i].codigo == codigo) {

            printf("1. Pendiente\n2. En Progreso\n3. Finalizada\n");
            printf("Nuevo estado: ");
            scanf("%d", &op);

            if(op == 1)
                strcpy(tareas[i].estado, "Pendiente");
            else if(op == 2)
                strcpy(tareas[i].estado, "En Progreso");
            else if(op == 3)
                strcpy(tareas[i].estado, "Finalizada");
            else {
                printf("Opcion invalida\n");
                return;
            }

            printf("Estado actualizado\n");
            return;
        }
    }

    printf("Tarea no encontrada\n");
}