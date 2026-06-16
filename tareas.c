#include <stdio.h>
#include <string.h>
#include "tareas.h"

void registrarTarea(Tarea tareas[], int *n) {
    int codigo, i;

    printf("Codigo: ");
    scanf("%d", &codigo);

    for(i = 0; i < *n; i++) {
        if(tareas[i].codigo == codigo) {
            printf("Error: Codigo repetido\n");
            return;
        }
    }

    tareas[*n].codigo = codigo;

    printf("Titulo: ");
    scanf(" %[^\n]", tareas[*n].titulo);

    printf("Responsable: ");
    scanf(" %[^\n]", tareas[*n].responsable);

    printf("Prioridad (Alta/Media/Baja): ");
    scanf("%s", tareas[*n].prioridad);

    strcpy(tareas[*n].estado, "Pendiente");

    (*n)++;

    printf("Tarea registrada correctamente\n");
}

void eliminarTarea(Tarea tareas[], int *n) {
    int codigo, i, j;

    printf("Codigo a eliminar: ");
    scanf("%d", &codigo);

    for(i = 0; i < *n; i++) {
        if(tareas[i].codigo == codigo) {

            for(j = i; j < *n - 1; j++) {
                tareas[j] = tareas[j + 1];
            }

            (*n)--;

            printf("Tarea eliminada\n");
            return;
        }
    }

    printf("No encontrada\n");
}