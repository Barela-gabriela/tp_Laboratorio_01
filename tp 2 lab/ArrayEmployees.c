#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

int askMenuOption()
{
    int option;
    printf("\t ******MENU DE OPERACIONES******\n\t ------------------------------\n\t|  1 .ALTA                     |\n\t|  2 .MODIFICAR                |\n\t|  3 .BAJA                     |\n\t|  4 .INFORMAR                 |\n\t|  5 .SALIR                    |\n\t|  6 .CARGAR                   |\n\t ------------------------------\n\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

int employeeExist(Employee* list, int len)
{
    int existEmployee = -1;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            existEmployee = 0;
            break;
        }
    }

    return existEmployee;
}

int printEmployee(Employee* list, int indice)
{
    int myReturn= -1;
    if(list!=NULL)
    {
         if(list[indice].isEmpty ==0)
         {
            printf("%d\t    %s\t    %s\t    %.3f\t    %d \n",list[indice].id, list[indice].name, list[indice].lastName, list[indice].salary, list[indice].sector);
            myReturn= 0;
         }

    }
    return myReturn;
}
static int generarId()
{
    static int id=0;

    id++;

    return id;
}

int initEmployees(Employee* list,int len)
{
    int myReturn=-1;
    int i;

    if(list!= NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=VACIO;
        }
        myReturn= 0;
    }
    return myReturn;
}
int findFreeSpace(Employee* list, int len)
{
    int i;
    int myReturn=-1;

    if(list!=NULL)
    {
        for(i=0; i<len;i++)
        {
            if(list[i].isEmpty==VACIO)
            {
                myReturn=i;
                break;
            }
        }
    }
    return myReturn;
}
int addEmployee(Employee* list,int len,int id,int sector,char name[],char lastName[],float salary)
{
    Employee auxarrayEmployees;
    int FreeSpace=findFreeSpace(list,len);
    int myReturn= -1;

    if(list !=NULL)
    {
        if(FreeSpace!=-1)
        {
            if(name!=NULL && lastName!=NULL && salary > 0)
            {
                strcpy(auxarrayEmployees.name,name);
                strcpy(auxarrayEmployees.lastName,lastName);
                auxarrayEmployees.id=generarId();
                auxarrayEmployees.salary=salary;
                auxarrayEmployees.sector=sector;
                auxarrayEmployees.isEmpty=OCUPADO;
                list[FreeSpace]=auxarrayEmployees;
                myReturn=0;
            }else
            {
                printf("\n*******************  Warning  *******************\nDatos incorrectos!\nVuelva a ingresar nombre, apellido y salario \nIngrese nuevamente los datos\nMuchas Gracias!\n");
            }
        }else
        {
            printf("\n*******************  Warning  *******************\nYa no hay lugar disponible\n");
            system("pause");
        }
    }
    system("cls");
    return myReturn;
}
int findEmployeeById(Employee* list, int len, int id)
{
    int myReturn=-1;
    int i;

    if(list!=NULL)
    {
        for(i=0; i<len;i++)
        {
            if(list[i].id == id && list[i].isEmpty == OCUPADO)
            {
                myReturn=i;
                break;
            }
        }
    }
    return myReturn;
}
int modifyEmployee(Employee* list, int len,int id)
{
    int option;
    int myReturn= -1;
    int index;
    int newSector;
    float newSalary;
    char newName[50];
    char newLastName[50];
    char continuee= 'n';

    printf("Ingrese el numero ID: ");
    scanf("%d", &id);
    index=findEmployeeById(list, len,id);
    if(list!=NULL)
    {
        if(index>=0)
        {
            do
            {
                printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");
                printEmployee(list,index);
                printf("\n\nElija la opcion que desea modificar:\n1. Nombre\n2. Apellido\n3. Salario\n4. Sector\n");
                scanf("%d", &option);
                switch(option)
                {
                    case 1:
                        getValidString("Ingrese nombre: ","Error, vuelva a intentar:", newName);
                        strcpy(list[index].name, newName);
                            break;
                    case 2:
                        getValidString("Ingrese apellido: ","Error, vuelva a intentar:", newLastName);
                        strcpy(list[index].lastName, newLastName);
                            break;
                    case 3:
                        newSalary=getValidFloat("Ingrese salario ","Error, vuelva a intentar:\n",0,1000000);
                        list[index].salary=newSalary;
                            break;
                    case 4:
                        newSector=getValidInt("Ingrese sector: ","Error, vuelva a intentar",0,200);
                        list[index].sector=newSector;
                            break;
                    default:
                        printf("Dato incorrecto\n");
                }
                printf("Continuar? s/n : ");
                fflush(stdin);
                scanf("%c",&continuee);
                system("pause");
                system("cls");
            }while(continuee== 's' || continuee == 'S');
        }else if(index < 0)
        {
            printf("No existe ese numero de ID\n");
        }
        myReturn=0;
    }
    return myReturn;
}
int removeEmployee(Employee* list, int len,int id)
{
    int index;
    int i;
    int myReturn=-1;

    if(list!=NULL)
    {
        printf("\n Ingrese el numero id que desea eliminar: ");
        scanf("%d",&id);
        index=findEmployeeById(list, len, id);

        if (list[index].isEmpty==OCUPADO)
        {
            printf("ID\t*****NOMBRE\t*****APELLIDO\t*****SALARIO\t*****SECTOR\n");

            printEmployee(list, index);
        }
        for(i=1;i<len;i++)
        {
            if(index != VACIO)
            {
                printf("\nEl empleado fue eliminado exitosamente\n");
                list[index].isEmpty= VACIO;
                    break;
            }else
            {
                printf("\n No existe ese numero id\n");
                    break;
            }
            myReturn=0;
        }
    }
    return myReturn;
}

int printEmployees(Employee* list, int len)
{
    int i;
    int myReturn=-1;
    if(list!=NULL)
    {
        printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");
        for(i=0; i<len;i++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
                printEmployee(list, i);
                myReturn= 0;
            }
        }
    }
    return myReturn;
}

int sortEmployees(Employee* list, int len, int order)
{

    Employee auxarrayEmployees;
    int myReturn=-1;

    switch(order)

    {

    case 1://ascendente

        for(int i =0 ; i<len-1 ; i ++)
        {
            for(int j= i+1 ; j<len; j++)
            {
                if(strcmp(list[j].lastName,list[i].lastName)<0)
                {
                    auxarrayEmployees = list[i];
                    list[i] = list[j];
                    list[j] = auxarrayEmployees;
                }
                else if(strcmp(list[j].lastName,list[i].lastName) ==0 && list[i].sector>list[j].sector)
                {
                    auxarrayEmployees = list[i];
                    list[i] = list[j];
                    list[j] = auxarrayEmployees;
                }


            }

            myReturn=0;
        }

        system("cls");
        printf("EMPLEADOS ORDENADOS ASCENDENTEMENTE\n\n");
        printEmployees(list,len);

        break;
    case 2://descendente

        for(int i =0 ; i<len-1 ; i ++)
        {
            for(int j= i+1 ; j<len; j++)
            {
                if(strcmp(list[j].lastName,list[i].lastName)>0)
                {
                    auxarrayEmployees = list[i];
                    list[i] = list[j];
                    list[j] = auxarrayEmployees;
                }
                else if(strcmp(list[j].lastName,list[i].lastName) ==0 && list[i].sector<list[j].sector)
                {
                    auxarrayEmployees = list[i];
                    list[i] = list[j];
                    list[j] = auxarrayEmployees;
                }

            }

            myReturn=0;

        }


        system("cls");
        printf("EMPLEADOS ORDENADOS DESCENDENTEMENTE\n\n");
        printEmployees(list,len);

        break;
    }

    return myReturn;
}


void menuReport(Employee* list, int len)
{
    int option;
    int order;

    do
    {

        system("cls");
        printf("  *** INFORMES ***\n\n");
        printf("1- Ordenar por apellido y sector\n");
        printf("2- Total y promedio de los salarios\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)

        {
        case 1:
            fflush(stdin);
            order = getValidInt("Ingrese el orden <1-Ascendente_2-Descendente>","ERROR ingrese el orden nuevamente <1-2>",1,2);

            sortEmployees(list,len,order);
            break;
        case 2:
            findSalaryMax(list,len);
            break;
        case 3:
            printf("\nREGRESANDO AL MENU PRINCIPAL\n");
            break;
        default:
            printf("\nERROR! Por favor ingrese una opcion valida <1-7>\n");
            break;
        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(option!=3);
}

void findSalaryMax(Employee* list, int len)
{
    float averageSalary=0;
    int overAverageCounter=0;
    float totalSalary=0;
    int employeeQuantity=0;
    int i;
    int flag=0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {

            totalSalary = list[i].salary + totalSalary;

            employeeQuantity++;

            flag=1;
        }
    }

    if(flag==1)
    {
        averageSalary=totalSalary/employeeQuantity;

        for(i=0; i<len; i++)
        {
            if(list[i].salary>averageSalary&&list[i].isEmpty==0)
            {
                overAverageCounter++;
            }
        }
    }


    printf("\nEl total de los salarios es: %.3f\n",totalSalary);
    printf("El promedio de los salarios es: %.3f\n",averageSalary);
    printf("La cantidad de empleados que superan el promedio es: %d\n", overAverageCounter);

}
