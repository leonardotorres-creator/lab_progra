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