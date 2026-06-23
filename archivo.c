#include <stdio.h>
#include "archivo.h"

void guardarTareas(Tarea tareas[], int n) {
    FILE *f = fopen("tareas.txt", "w");

    if (f == NULL) {
        printf("Error al guardar archivo\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%d;%s;%s;%d\n",
                tareas[i].codigo,
                tareas[i].titulo,
                tareas[i].responsable,
                tareas[i].estado);
    }

    fclose(f);
}

void cargarTareas(Tarea tareas[], int *n) {
    FILE *f = fopen("tareas.txt", "r");

    if (f == NULL) {
        *n = 0;
        return;
    }

    *n = 0;

    while (fscanf(f, "%d;%[^;];%[^;];%d\n",
                  &tareas[*n].codigo,
                  tareas[*n].titulo,
                  tareas[*n].responsable,
                  &tareas[*n].estado) != EOF) {
        (*n)++;
    }

    fclose(f);
}