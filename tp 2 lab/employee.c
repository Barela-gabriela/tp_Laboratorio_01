#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "utn.h"

int pedirOpcionMenu()
{
    int opcion;
    printf("\t ******MENU DE OPERACIONES******\n\t ------------------------------\n\t|  1 .ALTA                     |\n\t|  2 .MODIFICAR                |\n\t|  3 .BAJA                     |\n\t|  4 .INFORMAR                 |\n\t|  5 .SALIR                    |\n\t|  6 .CARGAR                   |\n\t ------------------------------\n\nElija una opcion: \t");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
int mostrarEmpleado(eDirectorio agenda[], int indice)
{
    int retorno= FALSO;
    if(agenda!=NULL)
    {
         if(agenda[indice].isEmpty ==0)
         {
            printf("%d\t    %s\t    %s\t    %f\t    %d \n",agenda[indice].id, agenda[indice].nombre, agenda[indice].apellido, agenda[indice].salario, agenda[indice].sector);
            retorno= VACIO;
         }

    }
    return retorno;
}
static int generarId()
{
    static int id=0;

    id++;

    return id;
}

int inicializarEmpleado(eDirectorio agenda[],int cambiar)
{
    int retorno=-1;
    int i;

    if(agenda!= NULL && cambiar>0)
    {
        for(i=0;i<cambiar;i++)
        {
            agenda[i].isEmpty=1;
        }
        retorno= VACIO;
    }
    return retorno;
}
int buscarLugarLibre(eDirectorio agenda[], int cambiar)
{
    int i;
    int retorno=FALSO;

    if(agenda!=NULL)
    {
        for(i=0; i<cambiar;i++)
        {
            if(agenda[i].isEmpty==1)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int agregarEmpleado(eDirectorio agenda[],int cambiar,int id,int sector,char nombre[],char apellido[],float salario)
{
    eDirectorio auxDirectorio;
    int lugarFree=buscarLugarLibre(agenda,cambiar);
    int retorno= FALSO;

    if(agenda !=NULL)
    {
        if(lugarFree!=FALSO)
        {
            if(nombre!=NULL && apellido!=NULL && salario > 0)
            {
                strcpy(auxDirectorio.nombre,nombre);
                strcpy(auxDirectorio.apellido,apellido);
                auxDirectorio.id=generarId();
                auxDirectorio.salario=salario;
                auxDirectorio.sector=sector;
                auxDirectorio.isEmpty=VACIO;
                agenda[lugarFree]=auxDirectorio;
                retorno=VACIO;
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
    return retorno;
}
int buscarId(eDirectorio agenda[], int cambiar, int id)
{
    int retorno=FALSO;
    int i;

    if(agenda!=NULL)
    {
        for(i=VACIO; i<cambiar;i++)
        {
            if(agenda[i].id == id && agenda[i].isEmpty == 0)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int editarEmpleado(eDirectorio agenda[], int cambiar,int id)
{
    int modificar;
    int retorno= FALSO;
    int indice;
    int nuevoSector;
    float nuevoSalario;
    char nuevoNombre[50];
    char nuevoApellido[50];
    char seguir= 'n';

    printf("Ingrese el numero ID:\n");
    scanf("%d", &id);
    indice=buscarId(agenda, cambiar,id);
    if(indice!=NULL)
    {
        if(indice>=VACIO)
        {
            do
            {
                printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");
                mostrarEmpleado(agenda,indice);
                printf("\n\nElija la opcion que desea modificar:\n1. Nombre\n2. Apellido\n3. Salario\n4. Sector\n");
                scanf("%d", &modificar);
                switch(modificar)
                {
                    case 1:
                        getValidString("Ingrese nombre:\n","Error, vuelva a intentar:", nuevoNombre);
                        strcpy(agenda[indice].nombre, nuevoNombre);
                            break;
                    case 2:
                        getValidString("Ingrese apellido:\n","Error, vuelva a intentar:", nuevoApellido);
                        strcpy(agenda[indice].apellido, nuevoApellido);
                            break;
                    case 3:
                        nuevoSalario=getValidFloat("Ingrese salario\n","Error, vuelva a intentar:\n",0,1000000);
                        agenda[indice].salario=nuevoSalario;
                            break;
                    case 4:
                        nuevoSector=getValidInt("Ingrese sector:\n","Error, vuelva a intentar",0,200);
                        agenda[indice].sector=nuevoSector;
                            break;
                    default:
                        printf("Dato incorrecto\n");
                }
                printf("Continuar? s/n \n :");
                fflush(stdin);
                scanf("%c",&seguir);
                system("pause");
                system("cls");
            }while(seguir== 's' || seguir == 'S');
        }else if(indice < VACIO)
        {
            printf("No existe ese numero de ID\n");
        }
        retorno=VACIO;
    }
    return retorno;
}
int eliminarEmpleado(eDirectorio agenda[], int cambiar,int id)
{
    int indice;
    int i;
    int retorno=FALSO;

    if(agenda!=NULL)
    {
        printf("\n Ingrese el numero id que desea eliminar: ");
        scanf("%d",&id);
        indice=buscarId(agenda, cambiar, id);

        if (agenda[indice].isEmpty==VACIO)
        {
            printf("ID\t*****NOMBRE\t*****APELLIDO\t*****SALARIO\t*****SECTOR\n");

            mostrarEmpleado(agenda, indice);
        }
        for(i=VACIO;i<cambiar;i++)
        {
            if(indice >= VACIO)
            {
                printf("\nEl empleado fue eliminado exitosamente\n");
                agenda[indice].isEmpty= OCUPADO;
                    break;
            }else
            {
                printf("\n No existe ese numero id\n");
                    break;
            }
            retorno=VACIO;
        }
    }
    return retorno;
}
int promedioSalario(eDirectorio agenda[], int cambiar)
{
    float promedio;
    float sumaPromedios=VACIO;
    int i;
    int retorno=FALSO;
    int contador=VACIO;
    int contadorSuperanPromedio;
    if(agenda!=NULL)
    {
        for(i=VACIO;i<cambiar;i++)
        {
            if(agenda[i].isEmpty == VACIO)
            {
                sumaPromedios=sumaPromedios + agenda[i].salario;
                contador++;
                sumaPromedios=promedio/contador;
            }
        }
        for( i=VACIO; i<cambiar;i++)
        {
            if(agenda[i].isEmpty== VACIO)
            {
                if(agenda[i].salario>sumaPromedios)
                {
                    contadorSuperanPromedio ++;
                }
            }
        }
        printf("La suma es %.3f --- El promedio es %f --- los que superan el salario promedio son %d\n",promedio,sumaPromedios,contadorSuperanPromedio);
        retorno=VACIO;
    }
    return retorno;
}
int imprimirEmpleados(eDirectorio agenda[], int cambiar)
{
    int i;
    int retorno=FALSO;
    if(agenda!=NULL)
    {
        printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");
        for(i=VACIO; i<cambiar;i++)
        {
            if(agenda[i].isEmpty == VACIO)
            {
                mostrarEmpleado(agenda, i);
                retorno= VACIO;
            }
        }
    }
    return retorno;
}
int ordenarEmpleados(eDirectorio agenda[], int cambiar)
{
    eDirectorio auxDirectorio;
    int i;
    int j;
    int retorno=FALSO;
    int opcion;
    imprimirEmpleados(agenda,cambiar);
    if(agenda!=NULL)
    {
        printf("\n1.Ordenar alfabeticamente  de manera ascendente\n2.Ordenar alfabeticamente  de manera descendenten3.Total y promedio de los salarios, y cuantos empleados superan el salario promedio\nElija la opcion :\n");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            for(i=VACIO;i<cambiar-OCUPADO;i++)
            {
                for(j=i+OCUPADO;j<cambiar;j++)
                {
                    if(strcmp(agenda[j].apellido,agenda[i].apellido)<VACIO)
                    {
                        auxDirectorio=agenda[i];
                        agenda[i]=agenda[j];
                        agenda[j]=auxDirectorio;
                    }else if(strcmp(agenda[j].apellido,agenda[i].apellido)==VACIO && agenda[j].sector<agenda[i].sector)
                    {
                        auxDirectorio=agenda[i];
                        agenda[i]=agenda[j];
                        agenda[j]=auxDirectorio;
                    }
                }
            }
            printf("\n*******************  Cargado con exito  *******************\n");
                break;
        case 2:
            for(i=VACIO;i<cambiar-OCUPADO;i++)
            {
                for(j=i+OCUPADO;j<cambiar;j++)
                {
                    if(strcmp(agenda[i].apellido,agenda[j].apellido)<VACIO)
                    {
                        auxDirectorio=agenda[i];
                        agenda[i]=agenda[j];
                        agenda[j]=auxDirectorio;
                    }else if(strcmp(agenda[i].apellido,agenda[j].apellido)==VACIO && agenda[j].sector>agenda[i].sector)
                    {
                        auxDirectorio=agenda[i];
                        agenda[i]=agenda[j];
                        agenda[j]=auxDirectorio;
                    }
                }
            }
                printf("\n*******************  Cargado con exito  *******************\n");
                    break;
        case 3:
                promedioSalario(agenda,cambiar);
                printf("\n*******************  Cargado con exito  *******************\n");
                    break;
                default:
                printf("\n*******************  Warning  *******************\nDatos incorrectos!\nIngrese nuevamente los datos\nMuchas Gracias!\n");
                    break;
        }
        retorno=VACIO;
    }
    return retorno;
}
