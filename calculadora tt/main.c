#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
int main()
{
    float numUno;
    float numDos;
    float suma = 0;
    float resta = 0;
    float multiplicacion = 0;
    float division = 0;
    float factorial;

    int opciones;
    int flag=0;
    int menu;

    char continuar;

    do
        {
            menu=pedirOpcionMenu("\t ******MENU DE OPERACIONES******\n\t ------------------------------\n\t|  1 .INGRESAR PRIMER OPERANDO |\n\t|  2 .INGRESAR SEGUNDO OPERANDO|\n\t|  3 .CALCULAR OPERACIONES     |\n\t|  4 .INFORMAR                 |\n\t|  5 .SALIR                    |\n\t ------------------------------\n\nElija una opcion: \t");
            switch(opciones)
            {
               // case 1:
            }
        }while(continuar=='s');


    return 0;
}
//printf("\n");
