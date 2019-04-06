#include <stdio.h>
#include <stdlib.h>
#include "calcu.h"

int main()
{
    float numeroUno=0;
    float numeroDos=0;
    float suma=0;
    float resta=0;
    float dividir=0;
    float multiplicar=0;
    int factorialResultadoUno;
    int factorialResultadoDos;
    int banderaUno=0;
    int banderaDos=0;
    int menu;
    int operaciones;

    char continuar='s';

    do
    {
        menu=pedirOpcionMenu("\t MENU DE OPERACIONES\n1 .INGRESAR PRIMER OPERANDO\n2 .INGRESAR SEGUNDO OPERANDO\n3 .CALCULAR OPERACIONES\n4 .INFORMAR\n5 .SALIR\nElija una opcion: \t");

        switch(menu)
        {

        case 1:
            printf("Ingrese un numero:\n");
            scanf("%f", &numeroUno);
            banderaUno=1;
            break;

        case 2:
            printf("Ingrese otro numero\n");
            scanf("%f", &numeroDos);
            banderaDos=1;
            break;

        case 3:
             if(banderaUno==1 && banderaDos==1)
             {
                suma= funSuma(numeroUno,numeroDos);
                resta= funResta(numeroUno,numeroDos);
                dividir= funDividir(numeroUno,numeroDos);
                multiplicar= funMultiplicar(numeroUno,numeroDos);
                factorialResultadoUno= funFactorialUno(numeroUno);
                factorialResultadoDos= funFactorialDos(numeroDos);
                printf("\nCalculando la operacion\n");
             }
             else
             {
                 printf("\nERROR!!!\tIngrese un Numero\n");
             }
             break;

        case 4:
                if(numeroDos==0)
                {
                    printf("AVISO: No se puede dividir por 0\n");
                }
                else
                    {
                        printf("Division: %.2f\n",dividir);
                    }
                if (numeroUno<0)
                {
                    printf("AVISO: No se puede realizar el factorial de un numero negativo. \n");
                }
                else
                    {
                printf("Factorial del Primer numero: %.2f\n",factorialResultadoUno);
                    }

                if (numeroDos<0)
                {
                    printf("AVISO: No se puede realizar el factorial de un numero negativo. \n");
                }
                else
                    {
                printf("Factorial del Segundo numero: %.2f\n",factorialResultadoDos);
                    }
                printf("Suma: %.2f\n",suma);
                printf("Resta: %.2f\n",resta);
                printf("Multiplicacion: %.2f\n",multiplicar);

            break;

        case 5:
            continuar='n';
            break;
        default:
            printf("Opcion incorrecta\n");
            break;
        }
        system("pause");
        system("cls");

    }
    while(continuar=='s');

    return 0;
}
