#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

void registrarLibro(Nodo **biblioteca);

int main()
{
    Nodo *biblioteca = NULL;

    int opcion;

    do
    {
        printf("\n============================");
        printf("\n      BIBLIOTECA");
        printf("\n============================");
        printf("\n1. Registrar libro");
        printf("\n2. Mostrar libros");
        printf("\n3. Eliminar libro");
        printf("\n4. Salir");
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                registrarLibro(&biblioteca);
                break;

            case 2:
                mostrarAdelante(biblioteca);
                break;

            case 3:
            {
                int codigo;

                printf("\nCodigo a eliminar: ");
                scanf("%d",&codigo);

                eliminarNodo(&biblioteca,codigo);

                break;
            }

            case 4:
                printf("\nFin del programa...\n");
                break;

            default:
                printf("\nOpcion invalida\n");
        }

    }while(opcion != 4);

    liberarLista(&biblioteca);

    return 0;
}

void registrarLibro(Nodo **biblioteca)
{
    Libro *t;

    printf("\nCodigo: ");
    scanf("%d",&t->codigo);

    getchar();

    printf("Titulo: ");
    fgets(t->titulo,100,stdin);
    t->titulo[strcspn(t->titulo,"\n")] = '\0';

    printf("Autor: ");
    fgets(t->autor,50,stdin);
    t->autor[strcspn(t->autor,"\n")] = '\0';

    insertarFinal(biblioteca,*t);

    printf("\nTarea registrada.\n");
}