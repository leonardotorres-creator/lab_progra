#include <stdio.h>
#include <string.h>
#include "estadisticas.h"
#include "colors.h"

void mostrarEstadisticas(Nodo *cab) {
    int p = 0, ep = 0, f = 0, total = 0;
    Nodo *aux = cab;

    while(aux != NULL) {
        if(strcmp(aux->dato.estado, "Pendiente") == 0) p++;
        else if(strcmp(aux->dato.estado, "En Progreso") == 0) ep++;
        else if(strcmp(aux->dato.estado, "Finalizada") == 0) f++;
        
        total++;
        aux = aux->sig;
    }

    printf(BLUE"\n=== ESTADISTICAS ===\n");
    printf("Total tareas: %d\n", total);
    printf("Pendientes: %d\n", p);
    printf("En Progreso: %d\n", ep);
    printf("Finalizadas: %d\n"RESET, f);

    if(total > 0)
        printf(GREEN"Completado: %.2f%%\n"RESET, (f * 100.0)/total);
}