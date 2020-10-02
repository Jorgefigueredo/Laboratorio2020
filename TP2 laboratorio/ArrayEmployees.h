#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

/** \brief indica que todas las posiciones del arry estan vacios.
 *
 * \param Employee listaDeEmpleados[] recibe un array del tipo "Employee".
 * \param int size recibe el tamaño del array .
 * \return int resultado regresa 1 si esta todo correcto o -1 si el tamaño del array ingresado es invalido.
 *
 */
int initEmployees(Employee[], int);
/** \brief agrega a la lista de empleados los valores ingresados en otra funcion
 *
 * \param Employee ListaDeEmpleados[]  un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array.
 * \param int id del empleado.
 * \param char[] nombre del empleado.
 * \param char[] apellido del empleado.
 * \param float sueldo del empleado.
 * \param int sector del empleado.
 * \return int retorna -1 si no hay espacio o esta mal el tamaño del array o 1 si todo bien.
 *
 */
int addEmployee(Employee[], int, int, char[], char[], float, int);
/** \brief el usuario ingresa un id y decide que desea cambiarle a un empleado que puede ser nombre , apellido, sector, sueldo.
 *
 * \param Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array.
 * \param int el id del empleado que desea cambiar.
 * \return int retorna -1 si no hay espacio, no encuentra al empleado o esta mal el tamaño del array o 1 si todo bien.
 *
 */
int findEmployeeById(Employee[], int, int);
/** \brief  el usuario ingresa un id y decide eliminar  a un empleado.
 *
 * \param Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array.
 * \param int el id del empleado que desea eliminar.
 * \return int int retorna -1 si no hay espacio, no encuentra al empleado o esta mal el tamaño del array o 1 si todo bien.
 *
 */
int removeEmployee(Employee[], int, int);
/** \brief ordena los elementos del array lista de empleados en descendente o ascendente.
 *
 * \param Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array.
 * \param int order 1 ascendente 0 descendente
 * \return int 0;
 *
 */
int sortEmployees(Employee[], int, int);
/** \brief Imprime la lista de empleados ocupados.
 *
 * \param Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array.
 * \return int 0;
 *
 */
int printEmployees(Employee[], int);
/** \brief Menu despegable donde el usuario eligue que ingresar
 *
 * \param Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array.
 * \return void
 *
 */
void mainMenu(Employee[], int);
/** \brief El usuario crea y carga variables de cada empleado 1 por uno.
 *
 * \param Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array.
 * \return void
 *
 */
void loadEmployee(Employee[], int);
/** \brief Busca el primer lugar vacio para usar y completar los datos del usuario
 *
 * \param Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array.
 * \return int index regrasa -1 si no hay mas lugar en el array o 1 si encontro espacio.
 *
 */
int getNextEmployeeFreeSlot(Employee[], int);
/** \brief El usuario ingresa un id por pantalla para modificar o remover un usuario
 *
 * \param Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array.
 * \param int optionMenu para saber si el usario quiere modificar o eliminar 2 modificar 3 eliminar.
 * \return void
 *
 */
void loadEmployeeId(Employee[], int, int );
/** \brief Menu de la opcion 4 informar.
 *
 * \param Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array.
 * \return void
 *
 */
void inforMenu(Employee[], int);
/** \brief El usuario ingresa 1 o 0 depedendiendo si quiere ordenar el array de forma descendiente o ascendente.
 *
 * \param Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array
 * \return void
 *
 */
void loadOrder(Employee[], int );
/** \brief Cuenta la cantidad de empleados cargados en total.
 *
 * \param Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array
 * \return int contadorDeEmpleados devuelve el el total de empleados cargados.
 *
 */
int employeeCount(Employee[], int);
/** \brief Suma el salario de todos los empleados cargados.
 *
 * \param  Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array
 * \return float salarySum devuelve el total de salarios sumados.
 *
 */
float employeeSalarySum(Employee[], int);
/** \brief Imprime el total de sueldos de todos los empleados. el promedio y quienes superan el promedio.
 *
 * \param  Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array
 * \return void
 *
 */
void inforSalary(Employee[], int);
/** \brief Cuenta cuantos superan el promedio de sueldo.
 *
 * \param Employee ListaDeEmpleados[] un array listaDeEmpleados del tipo "Employee".
 * \param int size el tamaño del array
 * \param float promedyTotal el promedio de sueldo de todos los empleados.
 * \return int countMaxPromedyEmployee el total de empleados que superan el promedio de sueldo.
 *
 */
int countEmployeeMaxPromedy(Employee[], int, float);





