#ifndef TAREAS_H
#define TAREAS_H

typedef struct {
    int codigo;
    char titulo[100];
    char responsable[50];
    char prioridad[10];
    char estado[20];
} Tarea;

// Funciones
void registrarTarea(Tarea tareas[], int *n);
void eliminarTarea(Tarea tareas[], int *n);

#endif