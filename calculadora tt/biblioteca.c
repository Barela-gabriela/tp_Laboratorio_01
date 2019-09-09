#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
int pedirOpcionMenu(char texto[])
{
        int opcion;

        printf("%s", texto);
        scanf("%d", &opcion);

    return opcion;
}
