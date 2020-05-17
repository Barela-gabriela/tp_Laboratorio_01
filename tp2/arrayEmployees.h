#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#include "loadData.h"

typedef struct
{
    int id;
    int idSector;
    int isEmpty;
    char name[50];
    char lastName[50];
    float salary;
}employees;
typedef struct
{
    int id;
    char descripcion[20];
}eSector;

#endif // ARRAYEMPLOYEES_H_INCLUDED
int askMenuOption();
int addEmployees(int id,employees arrays[],int tam,eSector sectors[], int tamSec,char name[],char lastName[],float salary,int sector);
///int addEmployees(int id,char name,char lastName,float salary,int sector,employees arrays[],int tam,eSector sectors[],int tamSec);

int findFreespace(employees arrays[],int tam);
int findEmployeeById(int id, employees arrays[],int tam);

void initEmployees(employees arrays[], int tam);
void loadEmployees(employees arrays[]);

void printEmployee(employees x, eSector sectors[], int tamSec);
void printEmployees(employees arrays[], int tam, eSector sectors[], int tamSec);
void printSector(eSector sectors[], int tamSec);

void loadDescription(char descripcion[],int id,eSector sectors[],int tam);
void removeEmployees(employees arrays[], int tam,eSector sectors[], int tamSec);

void modifyEmployee(employees arrays[], int tam,eSector sectors[], int tamSec);

void sortEmployeesByLastName(employees arrays[],int tam,eSector sectors[],int tamSec);
void sortEmployeesByLastNameD(employees arrays[],int tam,eSector sectors[],int tamSec);
void sortEmployeesBySalary(employees arrays[],int tam);
