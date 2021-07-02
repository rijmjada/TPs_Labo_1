#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "ArrayEmployees.h"

typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

//Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
//(isEmpty) en TRUE en todas las posiciones del array.
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(eEmployee unEmpleado[], int len);

//Busca un empleado recibiendo como parámetro de búsqueda su Id.
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(eEmployee unEmpleado[], int len, int id);

//Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(eEmployee unEmpleado[], int len, int id);

//Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(eEmployee unEmpleado[], int len, int order);

//Imprime el array de empleados de forma encolumnada.
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/




int menu();

int cargarEmpleado(eEmployee unEmpleado[], int len,int id);
int buscarEspacioLibre(eEmployee unEmpleado[], int len);
int addEmployee(eEmployee unEmpleado[], int len, int id, char name[],char lastName[],float salary,int sector);
int modificarDatosEmpleado(eEmployee unEmpleado[], int tam);




#endif // ARRAYEMPLOYEES_H_INCLUDED
