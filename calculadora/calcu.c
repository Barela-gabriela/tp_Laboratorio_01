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
int funFactorial(float numeroUno)
{
    int fact=1;
    for(int i=1;i<=numeroUno;i++)///toma los valores de uno en adelante
    {
        fact =fact *i;
    }
    return fact;
}
