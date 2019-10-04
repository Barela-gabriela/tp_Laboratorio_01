#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000
#include "employee.h"
#include "utn.h"


int main()
{
    int flag=VACIO;
    char continuar= 's';
    eDirectorio directorio[TAM];
    inicializarEmpleado(directorio,TAM);
    char nombre[50];
    char apellido[50];
    float salario;
    int sector;
    int lugarLibre;

    printf("*******************  Buen dia!  *******************\n");
                system("pause");
                system("cls");
    do
    {
        switch(pedirOpcionMenu())
        {
            case 1:
                flag=OCUPADO;
                lugarLibre=buscarLugarLibre(directorio,TAM);
                if (lugarLibre != FALSO)
                {
                    printf("Lugar libre = %d\n",lugarLibre);
                    getValidString("Ingrese nombre:", "Error, ingrese nuevamente:", nombre);
                    getValidString("Ingrese apellido:", "Error, ingrese nuevamente:", apellido);
                    salario=getValidFloat("Ingrese salario:\n","Error, no valido\n", 0, 1000000);
                    sector=getValidInt("Ingrese sector:\n","Error, no valido\n", 0, 200);
                    addEmployee(directorio, TAM, lugarLibre,  nombre, apellido, salario, sector);
                }else
                {
                    printf("No se ha encontrado lugar libre.\n");
                    system("pause");
                    system("cls");
                }
                        break;
            case 2:
                if(flag==VACIO)
                {
                    printf("No existen datos que mostrar\n");
                }else
                {
                    editarEmpleado(directorio,TAM,lugarLibre);
                }
                    system("pause");
                    system("cls");
                        break;
            case 3:
                if(flag==VACIO)
                {
                    printf("No hay datos que mostrar\n");
                }else
                {
                    eliminarEmpleado(directorio,TAM,directorio[TAM].id);
                }
                    system("pause");
                    system("cls");
                        break;
            case 4:
                                if(flag==VACIO)
                {
                    printf("No hay datos que mostrar\n");
                }else
                {
                    ordenarEmpleados(directorio,TAM);
                }
                    system("pause");
                    system("cls");
                        break;
            case 5:
                continuar='n';
                printf("*******************  Finish  *******************\n");
             break;
            default:
                printf("\n*******************  Warning  *******************\nEl caracter no es correspondiente a las opciones (<1-6>)\nIngrese nuevamente una opcion valida\nMuchas Gracias!\n");
            break;
            case 6:
                flag=OCUPADO;
                agregarEmpleado(directorio, TAM, 1, "Nancy", "Gutierrez", 20000, 25);
                agregarEmpleado(directorio, TAM, 2, "Camila", "Cabello", 14000, 28);
                agregarEmpleado(directorio, TAM, 3, "Ariana", "Grande", 12000, 22);
                agregarEmpleado(directorio, TAM, 4, "Carmen", "Da Rocha", 12000, 83);
                agregarEmpleado(directorio, TAM, 5, "Javier", "Lopez", 30000, 5);
                agregarEmpleado(directorio, TAM, 6, "Marx", "Weber", 56000, 11);
                agregarEmpleado(directorio, TAM, 7, "Richard", "Anderson", 50000, 1);
                agregarEmpleado(directorio, TAM, 8, "Pancho", "Cruz", 15000, 15);
                agregarEmpleado(directorio, TAM, 9, "Julian", "Suarez", 22000, 23);
                 printf("\n*******************  Cargado con exito  *******************\n");
                system("pause");
                system("cls");
            break;

        }
        fflush(stdin);
        system("pause");
        system("cls");

    }while(continuar=='s');
    return 0;
}
