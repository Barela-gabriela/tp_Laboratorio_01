#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "loadData.h"
int askMenuOption()
{
    int option;
    printf("\t ******MENU DE OPERACIONES******\n\t ------------------------------\n\t|  1 .ALTA                     |\n\t|  2 .MODIFICAR                |\n\t|  3 .BAJA                     |\n\t|  4 .INFORMAR                 |\n\t|  5 .SALIR                    |\n\t|  6 .LISTAR EMPLEADOS         |\n\t ------------------------------\n\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}
void printEmployee(employees x, eSector sectors[], int tamSec)
{
    char descriptionSector[20];
    loadDescription(descriptionSector,x.idSector,sectors,tamSec);///copia la cadena que queremos mostrar

    printf("%d   %10s %10s     %6.2f    %10s\n",x.id,x.name,x.lastName,x.salary,descriptionSector);
}
void printEmployees(employees arrays[], int tam, eSector sectors[], int tamSec)
{
    int i;
    int flag=0;
    printf("\tLista de empleados\n\n");
    printf("ID    NOMBRE   APELLIDO      SUELDO     SECTOR\n");
    for(i=0;i<tam;i++)
    {
        if(arrays[i].isEmpty==0)
        {
            printEmployee(arrays[i],sectors,tamSec);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay empleados que mostrar");
    }
}
void loadDescription(char descripcion[],int id,eSector sectors[],int tam)
{
    int i;

    for(i=0;i<tam;i++)///recorro secotres
    {
        if(sectors[i].id==id)///busco el id de sectores
        {
            strcpy(descripcion, sectors[i].descripcion);///copio la descripcion a l parametro
        }
    }
}
void initEmployees(employees arrays[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        arrays[i].isEmpty=1;///si esta vacio 1=verdadero 0=flaso
    }
}
int findFreespace(employees arrays[],int tam)
{
    int index=-1;///asi empieza desde 0
    int i;
    for(i=0;i<tam;i++)
    {
        if(arrays[i].isEmpty==1)///si esta abierto detecta el lugar vacio
        {
            index=i;
            break;
        }
    }
    return index;
}
int findEmployeeById(int id, employees arrays[],int tam)
{
    int index=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(arrays[i].id==id && arrays[i].isEmpty==0)///detecta si existe el alumno por id
        {
            index=i;
            break;
        }
    }
    return index;

}

int addEmployees(int id,employees arrays[],int tam,eSector sectors[], int tamSec,char name[],char lastName[],float salary,int sector)
{
    employees auxEmployes;

    int index=findFreespace(arrays,tam);///devuelve el indice -1
    int exist;///aca guardo el id

    system("cls");
    printf("\nAlta empleados\n");
    if(index==-1)///hay lugar?
    {
        printf("\nSistema Completao\n");
    }
    else
    {
        exist = findEmployeeById(id,arrays,tam);

        if(exist !=-1)///el id ya esta?, es decis los compara los ID
        {
            printf("\nYa existe un empleado con ese id");
        }
        else
        {
            auxEmployes.id=id;
            strcpy(auxEmployes.name,name);
            strcpy(auxEmployes.lastName,lastName);
            auxEmployes.salary=salary;
            auxEmployes.idSector=sector;
            auxEmployes.isEmpty=0;
            arrays[index]=auxEmployes;///copio vector con empleado nuevo
        }
    }
    return 0;
}
void removeEmployees(employees arrays[], int tam,eSector sectors[], int tamSec)
{
    int index;
    int id;
    char confirm;
    system("cls");

    printf("Baja Empleado");
    printf("\nIngrese ID: ");

    scanf("%d",&id);

    index=findEmployeeById(id,arrays,tam);

    if(index==-1)
    {
        printf("\nNo hay registro de un empleado con el id: %d",id);
    }
    else
    {
        printEmployee(arrays[index],sectors,tamSec);
        printf("\nConfirma Baja?(s/n)");
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm== 's')
        {
            arrays[index].isEmpty=1;
            printf("\nSe a realizado la baja con exito");
        }
        else
        {
            printf("\nSe ha cancelado la operacion");
        }
    }
}
void modifyEmployee(employees arrays[],int tam, eSector sectors[],int tamSec)
{
    int options;
    int id;
    int index;
    char confirm;
    float newSalary;
    char newName[20];
    char newLastName[20];
    int newSector;
    printf("Modificar empleados");
    printf("\nIngrese Id:");
    scanf("%d",&id);

    index =findEmployeeById(id,arrays,tam);

    if(index==-1)
    {
        printf("\nNo hay registro de un empleado con el id: %d",id);
    }
    else
    {
        printEmployee(arrays[index],sectors,tamSec);

        printf("\nModificar empleado?(s/n)");
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm== 's')
        {
            printf("\nQue desa modificar?");
            printf("\n1.Nombre");
            printf("\n2.Apellido");
            printf("\n3.Sueldo");
            printf("\n4.Sector\n\n");
            scanf("%d",&options);
            switch(options)
            {
            case 1:
                printf("\nIngrese nuevo nombre: ");
                fflush(stdin);
                gets(newName);

                strcpy(arrays[index].name,newName);
                break;
            case 2:
                printf("\nIngrese nuevo apellido: ");
                fflush(stdin);
                gets(newLastName);

                strcpy(arrays[index].lastName,newLastName);
                break;
            case 3:
                printf("\nIngrese nuevo sueldo: ");
                scanf("%f",&newSalary);

                arrays[index].salary=newSalary;
                break;
            case 4:
                printf("\nSeleccione nuevo sector");
                printSector(sectors,tamSec);
                scanf("%d",&newSector);
                arrays[index].idSector=newSector;
                break;
            }

            printf("\nSe a realizado la modificacion con exito\n");
        }
        else
        {
            printf("\nSe ha cancelado la operacion");
        }
    }
}

void loadEmployees(employees arrays[])
{
    int loadsId[]={1000,1001,1002,1003,1004,1005,1006,1007,1008,1009};
    char loadnames[][20]={"Patricio","BoB","Bob","Elvis","Carla","Lucia","Merida","Manuel","Lautaro","Leonel"};
    char loadLastNames[][20]={"Estrella","Esponja","Marley","Presley","Perez","Diaz","Grey","Lopez","Malarza","Messi"};
    float loadSalarys[]={10000,20000,15000,8000,11000,40000,35000,28000,9000,57000};
    int loadSector[]={1,2,3,4,1,2,3,4,1,2};
    int i;
    for(i=0;i<10;i++)
    {
        arrays[i].id=loadsId[i];
        strcpy(arrays[i].name,loadnames[i]);
        strcpy(arrays[i].lastName,loadLastNames[i]);
        arrays[i].salary=loadSalarys[i];
        arrays[i].idSector=loadSector[i];
        arrays[i].isEmpty=0;
    }
}

void sortEmployeesByLastName(employees arrays[],int tam,eSector sectors[],int tamSec)
{
    employees auxEmployees;
    int i;
    for(i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(strcmp(arrays[i].lastName,arrays[j].lastName)<0)
            {
                auxEmployees=arrays[i];
                arrays[i]=arrays[j];
                arrays[j]=auxEmployees;
            }
            else  if(strcmp(arrays[i].lastName,arrays[j].lastName)==0 && arrays[i].idSector==arrays[j].idSector)
            {
                auxEmployees=arrays[i];
                arrays[i]=arrays[j];
                arrays[j]=auxEmployees;
            }
        }
    }
}
void sortEmployeesByLastNameD(employees arrays[],int tam,eSector sectors[],int tamSec)
{
        employees auxEmployees;
    int i;
    for(i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(strcmp(arrays[i].lastName,arrays[j].lastName)>0)
            {
                auxEmployees=arrays[i];
                arrays[i]=arrays[j];
                arrays[j]=auxEmployees;
            }
            else  if(strcmp(arrays[i].lastName,arrays[j].lastName)==0 && arrays[i].idSector==arrays[j].idSector)
            {
                auxEmployees=arrays[i];
                arrays[i]=arrays[j];
                arrays[j]=auxEmployees;
            }
        }
    }
}
void sortEmployeesBySalary(employees arrays[],int tam)
{
    float average=0;
    int averageCounter=0;
    float totalSalary=0;
    int employeeAccountant=0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(arrays[i].isEmpty==0)
        {
            totalSalary = arrays[i].salary + totalSalary;
            employeeAccountant++;
        }

    }
        average=totalSalary/employeeAccountant;

        for(i=0; i<tam; i++)
        {
            if(arrays[i].salary>average&&arrays[i].isEmpty==0)
            {
                averageCounter++;
            }
        }
    printf("cantidad total de empleados: %d",employeeAccountant);
    printf("\nEl total de los salarios es: %.2f\n",totalSalary);
    printf("El promedio de los salarios es: %.2f\n",average);
    printf("La cantidad de empleados que superan el promedio es: %d\n", averageCounter);

}
void printSector(eSector sectors[],int tamSec)
{
    int i;
    printf("Sectores\n\n");
    printf("ID    SECTOR\n");
    for(i=0;i<tamSec;i++)
    {
         printf("%d   %10s\n",sectors[i].id,sectors[i].descripcion);
    }
}
