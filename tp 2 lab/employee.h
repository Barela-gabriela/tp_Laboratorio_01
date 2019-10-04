#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#define OCUPADO 1
#define VACIO 0
#define FALSO -1
typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    float salario;
    int sector;
    int isEmpty;

}eDirectorio;

int pedirOpcionMenu();
int inicializarEmpleado(eDirectorio agenda[], int cambiar);///
int buscarLugarLibre(eDirectorio agenda[], int cambiar);
int agregarEmpleado(eDirectorio agenda[],int cambiar,int id,int sector,char nombre[],char apellido[],float salario);///
int buscarId(eDirectorio agenda[], int cambiar, int id);///
int editarEmpleado(eDirectorio agenda[], int cambiar,int id);///
int mostrarEmpleado(eDirectorio agenda[],int indice);///
int eliminarEmpleado(eDirectorio agenda[], int cambiar,int id);///
int promedioSalario(eDirectorio agenda[], int cambiar);///
int imprimirEmpleados(eDirectorio agenda[], int cambiar);///
int ordenarEmpleados(eDirectorio agenda[], int cambiar);///
#endif // EMPLOYEE_H_INCLUDED
