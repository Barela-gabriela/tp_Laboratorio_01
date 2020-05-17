#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayEmployees.h"
#include "loadData.h"

#define TAM 15
#define TAMSEC 4
int main()
{
    char confirm;
    char seguir='s';
    //int i;
    int nextId=1000;
    int options;
    int menu;

                char name[20];
                char lastName[20];
                int sector;
                float salary;
    employees arrays[TAM];
    eSector sectores[TAMSEC]={{1,"RRHH"},{2,"Ventas"},{3,"Sistemas"},{4,"Contable"}};
    initEmployees(arrays,TAM);
    loadEmployees(arrays);
    nextId +=10;
     do
    {
        switch(askMenuOption())
        {
            case 1:

                printf("Alta");
                printf("\nIngrese nombre: ");
                fflush(stdin);
                gets(name);

                printf("\nIngrese apellido: ");
                fflush(stdin);
                gets(lastName);

                printf("\nSelecciona el sector: ");
                printSector(sectores,TAMSEC);

                printf("\ningrese id del sector: ");
                scanf("%d",&sector);
                if(sector>0 && sector<5)
                {
                        printf("\nIngrese sueldo: ");
                        scanf("%f",&salary);

                if(addEmployees(nextId,arrays,TAM,sectores,TAMSEC,name,lastName,salary,sector))
                {
                    printf("\nCargado con exito\n\n");
                }
                nextId++;
                break;
                }
                else
                {
                    printf("Error\n");
                    break;
                }

            case 2:
                printf("Modificar\n");
                modifyEmployee(arrays,TAM,sectores,TAMSEC);
                break;
            case 3:
                printf("Baja\n");
                removeEmployees(arrays,TAM,sectores,TAMSEC);
                break;
            case 4:

                printf("Informar\n");
                printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
                printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
                scanf("%d",&options);
                switch(options)
                {
                case 1:
                  printf("\n1.Ordenar de manera acendente\n");
                  printf("\n2.Ordenar de manera descendente\n");
                  scanf("%d",&menu);
                  switch(menu)
                  {
                      case 1:
                          sortEmployeesByLastName(arrays,TAM,sectores,TAMSEC);
                          break;
                      case 2:
                          sortEmployeesByLastNameD(arrays,TAM,sectores,TAMSEC);
                          break;
                  }
                  break;
                case 2:
                   sortEmployeesBySalary(arrays,TAM);
                    break;
                }

                break;
            case 5:
                 printf("\nConfirma salida?\t");
                fflush(stdin);
                scanf("%c",&confirm);
                if(confirm=='s')
                {
                    seguir='n';
                }
                break;
            case 6:
                printf("Cargar");
                printEmployees(arrays,TAM,sectores,TAMSEC);
                break;
        }
        system("pause");
    }
    while(seguir=='s');
    return 0;
}
