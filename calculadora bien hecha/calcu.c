#include "calcu.h"
int pedirOpcionMenu(char texto[])
{
        int opcion;

        printf("%s", texto);//asigna un parametro porue se copia el valor del texto se copia en la variable
        scanf("%d", &opcion);

    return opcion;
}
float funSuma(float numeroUno, float numeroDos)
{
    float suma;
    suma=numeroUno+numeroDos;
    return suma;
}
float funResta(float numeroUno, float numeroDos)
{
    float resta;
    resta=numeroUno-numeroDos;
    return resta;
}
float funMultiplicar(float numeroUno, float numeroDos)
{
    float multiplicar;
    multiplicar=numeroUno*numeroDos;
    return multiplicar;
}
float funDividir(float numeroUno, float numeroDos)
{
    float dividir;
    dividir= numeroUno/numeroDos;
    return dividir;
}
int funFactorialUno(float numeroUno)
{
    int i;
    float factorialResultadoUno=1;
    for (i= 1; i <= numeroUno; i++)
    factorialResultadoUno = factorialResultadoUno * i;
    return factorialResultadoUno;
}
int funFactorialDos(float numeroDos)
{
    int i;
    int factorialResultadoDos=1;
    for (i= 1; i <= numeroDos; i++)
    factorialResultadoDos = factorialResultadoDos * i;
    return factorialResultadoDos;
}
