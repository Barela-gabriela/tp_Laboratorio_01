#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ELEMENTS  1000
#include "ArrayEmployees.h"
#include "utn.h"


int main()
{
   // int flag=VACIO;
    char continuar= 's';
    Employee arrayEmployees[ELEMENTS ];
    initEmployees(arrayEmployees,ELEMENTS );
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
        switch(askMenuOption())
        {
            case 1:
                //flag=OCUPADO;
                lugarLibre=findFreeSpace(arrayEmployees,ELEMENTS );
                if (lugarLibre != -1)
                {
                    printf("ID = %d\n",lugarLibre);
                    getValidString("Ingrese nombre:", "Error, ingrese nuevamente:", nombre);
                    getValidString("Ingrese apellido:", "Error, ingrese nuevamente:", apellido);
                    salario=getValidFloat("Ingrese salario:\n","Error, no valido\n", 0, 1000000);
                    sector=getValidInt("Ingrese sector:\n","Error, no valido\n", 1, 20);
                    addEmployee(arrayEmployees, ELEMENTS , lugarLibre, sector, nombre, apellido, salario);
                }else
                {
                    printf("No se ha encontrado lugar libre.\n");

                }
                        break;
            case 2:
                if(employeeExist(arrayEmployees,ELEMENTS)==-1)
                {
                    printf("No existen datos que mostrar\n");
                }else
                {
                    modifyEmployee(arrayEmployees,ELEMENTS ,lugarLibre);
                }

                        break;
            case 3:
                if(employeeExist(arrayEmployees,ELEMENTS)==-1)
                {
                    printf("No hay datos que mostrar\n");
                }else
                {
                    removeEmployee(arrayEmployees,ELEMENTS ,arrayEmployees[ELEMENTS ].id);
                }

                        break;
            case 4:
                if(employeeExist(arrayEmployees,ELEMENTS)==-1)
                {
                    printf("No hay datos que mostrar\n");
                }else
                {
                     menuReport(arrayEmployees,ELEMENTS );

                }

                        break;
            case 5:
                continuar='n';
                printf("*******************  Finish  *******************\n");
             break;
            default:
                printf("\n*******************  Warning  *******************\nEl caracter no es correspondiente a las opciones (<1-6>)\nIngrese nuevamente una opcion valida\nMuchas Gracias!\n");
            break;
            case 6:
                //flag=OCUPADO;
                addEmployee(arrayEmployees, ELEMENTS , 25, 101, "Nancy", "Gutierrez", 20000);
                addEmployee(arrayEmployees, ELEMENTS , 22, 102, "Camila", "Cabello", 14000);
                addEmployee(arrayEmployees, ELEMENTS , 22, 103, "Ariana", "Grande", 12000);
                addEmployee(arrayEmployees, ELEMENTS , 83, 104, "Carmen", "Da Rocha", 12000);
                addEmployee(arrayEmployees, ELEMENTS , 5,105,"Javier", "Lopez", 30000);
                addEmployee(arrayEmployees, ELEMENTS , 11,106,"Marx", "Weber", 56000);
                addEmployee(arrayEmployees, ELEMENTS , 1,107,"Richard", "Anderson", 50000);
                addEmployee(arrayEmployees, ELEMENTS , 15,108,"Pancho", "Cruz", 15000);
                addEmployee(arrayEmployees, ELEMENTS , 23,109,"Julian", "Suarez", 22000);

                 printf("\n*******************  Cargado con exito  *******************\n");

            break;

        }
        fflush(stdin);
        system("pause");
        system("cls");

    }while(continuar=='s');
    return 0;
}
