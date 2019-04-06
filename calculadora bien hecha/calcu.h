#ifndef CALCU_H_INCLUDED
#define CALCU_H_INCLUDED

int pedirOpcionMenu(char texto[]);

float funSuma(float,float);
/** \brief para realizar sumas entre 2 numeros
 *
 * \param registro un numero
 * \param registro otro numero
 * \return retorna la direccion suma
 *
 */

float funResta(float,float);
/** \brief para realizar la resta entre 2 numeros
 *
 * \param registro un numero
 * \param registro otro numero
 * \return retorna a la direccion resta
 *
 */

float funMultiplicar(float,float);
/** \brief para realizar la multiplicacion entre 2 numeros
 *
 * \param registro un numero
 * \param registro otro numero
 * \return retorna la direccion multiplicar
 *
 */
float funDividir(float,float);
/** \brief para realizar la division entre 2 numeros
 *
 * \param registro un numero
 * \param registro otro numero
 * \return retorna la direccion dividir
 *
 */
int funFactorialUno(float);
/** \brief funcion para hallar el factorial de numeroUno
 *
 * \param ingreso el primer numero
 * \param
 * \return retorna a la direccion factorialUno
 *
 */


int funFactorialDos(float);
/** \brief funcion para hallar el factorial de numeroDos
 *
 * \param ingreso el segundo numero
 * \param
 * \return retorna a la direccion factorialDos
 *
 */

#endif // CALCU_H_INCLUDED
