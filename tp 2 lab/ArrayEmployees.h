#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#define OCUPADO 0
#define VACIO 1
typedef struct
{
    int id;
    char name[51] ;
    char lastName[51] ;
    float salary;
    int sector;
    int isEmpty;

}Employee;

/** \brief Genera un menu para que el usuario elija una opcion
 *
 * \return int retorna la opcion
 *
 */
int askMenuOption();

/** \brief Funcion encargada de inicializar todos los elementos del array de empleados en un estado libre para cargar datos
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int recibe la cantidad de elementos en el array
 * \return int retorna -1 si hubo algun error y 0 si no hubo ningun error
 *
 */
int initEmployees(Employee* list, int len);
/** \brief Funcion encargada de buscar algun espacio libre en el array de empleados para cargar un nuevo dato
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int recibe la cantidad de elementos en el array
 * \return int Retorna la primera posicion libre que encuentra la funcion
 *
 */
int findFreeSpace(Employee* list, int len);
/** \brief Funcion encargada de añadir a los empleados en la estructura
 *
 * \param list Employee* Recibe un puntero al array de empleados
 * \param len int recibe la cantidad de elementos en el array
 * \param id int recibe el ID generado
 * \param name[] char recibe un array de caracteres para guardar el nombre del empleado
 * \param lastName[] char recibe un array de caracteres para guardar el apellido del empleado
 * \param salary float  Recibe una variable flotante para guardar el salario del empleado
 * \param sector int Recibe una variable entera para guardar el sector del empleado
 * \return int  Retorna -1 si hubo un error y 0 si el empleado fue cargado correctamente
 *
 */
int addEmployee(Employee* list,int len,int id,int sector,char name[],char lastName[],float salary);
/** \brief Funcion que busca al empleado por su numero de ID
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int recibe la cantidad de elementos en el array
 * \param int recibe el ID generado
 * \return int retorna la posicion del array donde se encuentra el ID generado
 *
 */
int findEmployeeById(Employee* list, int len, int id);
/** \brief Funcion encargada de buscar al empleado y modificarlo
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo un error y 0 si se pudo modificar correctamente al empleado
 *
 */
int modifyEmployee(Employee* list, int len,int id);
/** \brief Funcion encargada de mostrar a un empleado
 *
 * \param Employee Recibe un dato de tipo Employee
 * \return void La funcion no retorna nada
 *
 */
int printEmployee(Employee* list,int indice);
/** \brief Funcion encargada de dar de baja a un empleado
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int Recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo un error o 0 si se dio de baja exitosamente
 *
 */
int removeEmployee(Employee* list, int len,int id);
/** \brief Funcion encargada de mostrar el listado de todos los empleados
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo algun error y 0 si se pudieron mostrar los empleados correctamente
 *
 */
int printEmployees(Employee* list, int len);
/** \brief genera un menu para realizar los informes
 *
 * \param list Employee* Recibe un puntero al array de empleados
 * \param len int la cantidad de elementos en el array
 * \return void La funcion no retorna ningun parametro
 *
 */
void menuReport(Employee* list, int len);
/** \brief Funcion encargada de ordenar a los empleados ascendente o descendentemente por apellido y si los apellidos se repiren por sector
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int Recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo algun error y 0 si se pudieron ordenar los datos correctamente
 *
 */
int sortEmployees(Employee* list, int len, int order);
/** \brief Funcion encargada de calcular el total de los salarios,el promedio del salario de los empleados y mostrar cuantos empleados superan ese promedio
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int Recibe la cantidad de elementos en el array
 * \return void La funcion no retorna ningun parametro
 *
 */
void findSalaryMax(Employee* list, int len);

/** \brief Funcion encargada de validar si existe un empleado cargado en el array
 *
 * \param list Employee* Recibe un puntero al array de empleados
 * \param len int la cantidad de elementos en el array
 * \return int Retorna -1 si no hay empleados y 0 si encontro
 *
 */
int employeeExist(Employee* list, int len);


#endif // EMPLOYEE_H_INCLUDED
