#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"
#include "Genericas.h"


Employee* employee_new()
{
    Employee* auxiliar = (Employee*) malloc(sizeof(Employee));

    if(auxiliar != NULL)
    {
        auxiliar->id = 0;
        strcpy(auxiliar->nombre," ");
        auxiliar->horasTrabajadas = 0;
        auxiliar->sueldo = 0;
    }
    return auxiliar;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmpParam = employee_new();

    if(nuevoEmpParam!=NULL)
    {
        if(employee_setId(nuevoEmpParam,atoi(idStr))
                &&employee_setNombre(nuevoEmpParam,nombreStr)
                &&employee_setHorasTrabajadas(nuevoEmpParam,atoi(horasTrabajadasStr))
                &&employee_setSueldo(nuevoEmpParam,atoi(sueldoStr)) == 0)
        {
            employee_delete(nuevoEmpParam);
        }
    }
    return nuevoEmpParam;
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this,int id)
{
   int todoOk = 0;
    static int IdMaximo = -1;

    if(this != NULL)
    {
        if(id < 0)
        {
            IdMaximo++;
            this->id = IdMaximo;
        }
        else
        {
            if(id>IdMaximo)
            {
                this->id = id;
                IdMaximo = id;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
   int todoOk = 0;
    if(this!=NULL && nombre !=NULL && strlen(nombre)>=3)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = ERROR;
    if(this != NULL && horasTrabajadas >=0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = ALLOK;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = ERROR;
    if(this != NULL)
    {
        this->sueldo = sueldo;
        retorno = ALLOK;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = ERROR;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = ALLOK;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = ERROR;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = ALLOK;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = ERROR;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = ALLOK;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = ERROR;

    if( this != NULL && sueldo != NULL )
    {
        *sueldo = this->sueldo;
    }
    return retorno;
}
//------------------------------------------------------------[Imprimir por pantalla------------------------------------------------------------------------------------//

int mostrarPorReferencia(Employee* lista)
{
    int retorno = ERROR;
    int idScope;
    char nombreScope[20];
    int hsScope;
    int salaryScope;

    if(lista != NULL && employee_getId(lista,&idScope) &&
            employee_getNombre(lista,nombreScope)&&
            employee_getHorasTrabajadas(lista,&hsScope)&&
            employee_getSueldo(lista,&salaryScope))
    {
        printf("\n%d   \t%s \t%d   \t$%d"
               ,idScope
               ,nombreScope
               ,hsScope
               ,salaryScope);

        retorno = ALLOK;
    }

    return retorno;
}

int mostrarUnEmp(Employee* auxEmployee)
{
    int todoOk = 0;
    if(auxEmployee!=NULL)
    {
        printf(" | %5d | %15s | %10d | %10d |\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarEmpleados(Employee** lista,int tam)
{
    int retorno = ERROR;
    if(lista != NULL && tam >=0)
    {
        printf("\nId \tNombre \tHoras  \tSueldo");
        for(int i=0; i<tam; i++)
        {
            mostrarPorReferencia (*(lista + i));
        }
        printf("\n\n");
        retorno = ALLOK;
    }
    if(!retorno)
    {
        printf("No se pudo mostar la lista!\n");
    }
    return retorno;
}


/** \brief Ordenamiento por ID.
 *
 * \param employee1 void* Puntero a void.
 * \param employee2 void* Puntero a void.
 * \return int Retorna [-1] si el primero es mayor al segundo.
 * \return int Retorna [1] si el segundo es mayor al primero.
 * \return int Retorna [0] si son iguales.
 *
 */
int employee_compararId(void* employee1,void* employee2)
{
    int retorno;

    //debo castear cada employee, debido a que es un puntero a void.
    Employee* emp1 = (Employee*) employee1;
    Employee* emp2 = (Employee*) employee2;

    if(emp1->id > emp2->id)
    {
        retorno = -1; //si el primero es mayor al segundo.
    }
    else if(emp1->id < emp2->id)
    {
        retorno = 1;
    }
    else
    {
        //son iguales
        retorno = 0;
    }

    return retorno;
}

/** \brief Ordenamiento por nombre.
 *
 * \param employee1 void* Puntero a void.
 * \param employee2 void* Puntero a void.
 * \return int Retorna [-1] si el primero es mayor al segundo.
 * \return int Retorna [1] si el segundo es mayor al primero.
 * \return int Retorna [0] si son iguales.
 *
 */
int employee_compararNombre(void* employee1,void* employee2)
{
    int retorno;

    Employee* emp1 = (Employee*) employee1;
    Employee* emp2 = (Employee*) employee2;

    if(strcmp(emp1->nombre,emp2->nombre)>0)//Si uso strcmpi aparece un warning por implicit declaration...
    {
        retorno = -1;
    }
    else if(strcmp(emp1->nombre,emp2->nombre)<0)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/** \brief Ordenamiento por horas trabajadas.
 *
 * \param employee1 void* Puntero a void.
 * \param employee2 void* Puntero a void.
 * \return int Retorna [-1] si el primero es mayor al segundo.
 * \return int Retorna [1] si el segundo es mayor al primero.
 * \return int Retorna [0] si son iguales.
 *
 */
int employee_compararHoras(void* employee1,void* employee2)
{
    int retorno;

    Employee* emp1 = (Employee*) employee1;
    Employee* emp2 = (Employee*) employee2;

    if(emp1->horasTrabajadas > emp2->horasTrabajadas)
    {
        retorno = -1;
    }
    else if(emp1->horasTrabajadas < emp2->horasTrabajadas)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/** \brief Ordenamiento por sueldo.
 *
 * \param employee1 void* Puntero a void.
 * \param employee2 void* Puntero a void.
 * \return int Retorna [-1] si el primero es mayor al segundo.
 * \return int Retorna [1] si el segundo es mayor al primero.
 * \return int Retorna [0] si son iguales.
 *
 */
int employee_compararSalario(void* employee1,void* employee2)
{
    int retorno;

    Employee* emp1 = (Employee*) employee1;
    Employee* emp2 = (Employee*) employee2;

    if(emp1->sueldo > emp2->sueldo)
    {
        retorno = -1;
    }
    else if(emp1->sueldo < emp2->sueldo)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}




