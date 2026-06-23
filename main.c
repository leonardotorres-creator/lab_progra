#include <stdio.h>
#include "tareas.h"
#include "kanban.h"
#include "estadisticas.h"
#include "archivo.h"

int main() {
    Tarea tareas[100];
    int n = 0, opc;

    cargarTareas(tareas, &n);

    do {
        printf("\n1. Registrar\n2. Mostrar Kanban\n3. Cambiar Estado\n4. Eliminar\n5. Estadisticas\n6. Salir\n");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                registrarTarea(tareas, &n);
                guardarTareas(tareas, n);
                break;
            case 2:
                mostrarKanban(tareas, n);
                break;
            case 3:
                cambiarEstado(tareas, n);
                guardarTareas(tareas, n);
                break;
            case 4:
                eliminarTarea(tareas, &n);
                guardarTareas(tareas, n);
                break;
            case 5:
                mostrarEstadisticas(tareas, n);
                break;
        }
    } while (opc != 6);

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