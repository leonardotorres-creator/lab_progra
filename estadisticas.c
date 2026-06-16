#include <stdio.h>
#include <string.h>
#include "estadisticas.h"

void mostrarEstadisticas(Tarea tareas[], int n) {
    int p = 0, ep = 0, f = 0, i;

    for(i = 0; i < n; i++) {
        if(strcmp(tareas[i].estado, "Pendiente") == 0)
            p++;
        else if(strcmp(tareas[i].estado, "En Progreso") == 0)
            ep++;
        else if(strcmp(tareas[i].estado, "Finalizada") == 0)
            f++;
    }

    printf("\n=== ESTADISTICAS ===\n");
    printf("Total tareas: %d\n", n);
    printf("Pendientes: %d\n", p);
    printf("En Progreso: %d\n", ep);
    printf("Finalizadas: %d\n", f);

    if(n > 0)
        printf("Completado: %.2f%%\n", (f * 100.0)/n);
}