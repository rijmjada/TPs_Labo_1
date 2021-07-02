#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Genericas.h"
#include "Menu.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    int retorno = ERROR;
    int controlCarga;
    f = fopen(path,"r");

    if(f!=NULL && pArrayListEmployee!=NULL)
    {

        controlCarga = parser_EmployeeFromText(f,pArrayListEmployee);
        if(controlCarga != -1)
        {
            retorno = ALLOK;
        }
    }

    fclose(f);
    return retorno;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    int retorno = ERROR;
    int controlCarga;
    f = fopen(path,"rb");

    if(f!=NULL && pArrayListEmployee!=NULL)
    {

        controlCarga = parser_EmployeeFromBinary(f,pArrayListEmployee);
        if(controlCarga != -1)
            retorno = ALLOK;
    }


    fclose(f);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret = ERROR;
    if(pArrayListEmployee != NULL)
    {
        char auxNombre[40];
        int auxHorasTrabajadas = 0;
        int auxSueldo = 0;
        Employee* auxEmple = employee_new();

        system("cls");

        if(auxEmple != NULL
                && getNombreOApellido(auxNombre,"\nIngrese nombre :\n","Error.\n",3,28,5)
                && getInt(&auxHorasTrabajadas,"\nIngrese horas trabajadas:\n","Error.\n",1,9999,5)
                && getInt(&auxSueldo,"\nIngrese sueldo:\n","Error.\n",1,250000,5))
        {
            employee_setId(auxEmple,-1);
            employee_setNombre(auxEmple,auxNombre);
            employee_setHorasTrabajadas(auxEmple,auxHorasTrabajadas);
            employee_setSueldo(auxEmple,auxSueldo);

            if(!ll_add(pArrayListEmployee,auxEmple))
            {
                printf("Alta exitosa!.\n");
                ret = ALLOK;
            }
            else
            {
                printf("Hubo un error en el alta!.\n");
            }
        }
    }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = ERROR;
    int idBuffer;
    Employee* auxEmp;
    int tam = ll_len(pArrayListEmployee);

    system("cls");
    printf("**Modificar datos empleado.**\n");

    if(pArrayListEmployee!=NULL)
    {
        getInt(&idBuffer,"\n**Ingrese ID a modificar:\n","Error.\n",1,1500,2);

        for(int i=0; i<tam; i++)
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee,i);

            if(auxEmp->id == idBuffer)
            {
                printf("      Id        Nombre          Horas      Sueldo   \n");

                mostrarPorReferencia(auxEmp);

                printf("  ----------------------------------------------------------\n");

                switch(menuModificacion())
                {
                case 1:
                    if(getNombreOApellido(auxEmp->nombre,"\nIngrese nuevo nombre:\n","Error.\n",3,40,5)!=-1)
                    {
                        retorno = ALLOK;
                        printf("\nCambios en nombre guardados.\n");
                    }
                    break;

                case 2:
                    if(getInt(&auxEmp->horasTrabajadas,"\nIngrese nuevas horas trabajadas:\n","Error.\n",1,99999,5)!=-1)
                    {
                        retorno = ALLOK;
                        printf("\nCambios en horas guardados.\n");
                    }
                    break;

                case 3:
                    if(getInt(&auxEmp->sueldo,"\nIngrese nuevo sueldo:\n","Error.\n",1,250000,5)!=-1)
                    {
                        retorno = ALLOK;
                        printf("\nCambios en sueldo guardados.\n");
                    }
                    break;

                case 4:
                    exit(1);
                    break;

                default:
                    printf("\nNo ingreso una opcion valida!.\n");
                }
            }
        }
    }
    if(retorno == -1)
    {
        printf("\nERROR!.\n");
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = ERROR;
    int idBuffer;
    int idNotFound = 1;
    Employee* auxEmp;
    int tam = ll_len(pArrayListEmployee);
    char confirma;

    system("cls");
    printf("**Baja Empleado.**\n");

    if(pArrayListEmployee!=NULL)
    {
        getInt(&idBuffer,"\n**Ingrese ID empleado: ","Error.\n",1,1500,5);

        for(int i=0; i<tam; i++)
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee,i);

            if(auxEmp->id == idBuffer)
            {
                idNotFound = -1;
                printf("      Id        Nombre          Horas      Sueldo   \n");

                mostrarUnEmp(auxEmp);

                printf("\n**confirma baja? (s/n): ");
                fflush(stdin);
                scanf("%c",&confirma);
                confirma = tolower(confirma);
                printf("\n");

                if(confirma == 's')
                {
                    if(!ll_remove(pArrayListEmployee,i))
                    {
                        printf("**Baja exitosa!.\n");
                        retorno = ALLOK;
                        break;
                    }
                    else
                    {
                        printf("\n**No se pudo eliminar al empleado.\n");
                        retorno = ALLOK;
                        //break;
                    }
                }
                else if(confirma == 'n')
                {
                    printf("\n**Bajar cancelada por el usuario\n");
                    break;
                }
                else
                {
                    printf("\n**No ingreso una opcion valida!.\n");
                    retorno = ALLOK;
                }
            }
        }
    }
    if(idNotFound == 1)
    {
        printf("\n**No ingreso un id Valido!.\n");
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ret = ERROR;
    int tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("      Id        Nombre          Horas      Sueldo   \n");
        printf(" ----------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            mostrarUnEmp((Employee*)ll_get(pArrayListEmployee,i));
            ret = ALLOK;
        }
    }

    if(ret == ERROR)
    {
        printf("ERROR.\n");
    }

    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = ERROR;

    system("cls");
    printf("**Ordenar Empleados**");
    printf("\n\n");
    switch(menuOrdenar())
    {
    case 1:
        switch(menuTipoOrden())
        {
        case 1:
            printf("\nEsto puede demorar unos minutos...");
            ll_sort(pArrayListEmployee,employee_compararId,0);
            retorno = ALLOK;
            printf("\nLista Ordenada por Id...\n");
            break;

        case 2:
            printf("\nEsto puede demorar unos minutos...");
            ll_sort(pArrayListEmployee,employee_compararId,1);
            retorno = ALLOK;
            printf("\nLista Ordenada por Id...\n");
            break;

        default:
            printf("\nOpcion no valida\n");
        }
        break;

    case 2:
        switch(menuTipoOrden())
        {
        case 1:
            printf("\nEsto puede demorar unos minutos...");;
            ll_sort(pArrayListEmployee,employee_compararNombre,0);
            retorno = ALLOK;
            printf("\nLista Ordenada por Nombre...\n");
            break;

        case 2:
            printf("\nEsto puede demorar unos minutos...");
            ll_sort(pArrayListEmployee,employee_compararNombre,1);
            retorno = ALLOK;
            printf("\nLista Ordenada por Nombre...\n");
            break;
        }
        break;

    case 3:
        switch(menuTipoOrden())
        {
        case 1:
            printf("\nEsto puede demorar unos minutos...");
            ll_sort(pArrayListEmployee,employee_compararHoras,0);
            retorno = ALLOK;
            printf("\nLista Ordenada por Horas Trabajadas...\n");
            break;

        case 2:
            printf("\nEsto puede demorar unos minutos...");
            ll_sort(pArrayListEmployee,employee_compararHoras,1);
            retorno = ALLOK;
            printf("\nLista Ordenada por Horas Trabajadas...\n");
            break;
        }
        break;

    case 4:
        switch(menuTipoOrden())
        {
        case 1:
            printf("\nEsto puede demorar unos minutos...");
            ll_sort(pArrayListEmployee,employee_compararSalario,0);
            retorno = ALLOK;
            printf("\nLista Ordenada por Sueldos...\n");
            break;

        case 2:
            printf("\nEsto puede demorar unos minutos...");
            ll_sort(pArrayListEmployee,employee_compararSalario,1);
            retorno = ALLOK;
            printf("\nLista Ordenada por Sueldos...\n");

            break;
        }
        break;

    case 5:
        retorno = ALLOK;
        break;

    default:
        printf("\nNo ingreso una opcion Valida\n");
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* Direecion de la ubicacion del archivo.
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [1] si se cargo correctamente - [-1] Si hubo un error.
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = ERROR;

    FILE* auxFile;
    int tam = ll_len(pArrayListEmployee);
    Employee* auxEmple;

    if(pArrayListEmployee!=NULL && tam>0 && path!=NULL)
    {
        auxFile = fopen(path,"w");

        if(auxFile==NULL)
        {
            printf("\nNo se pudo abrir el archivo.\n");
            system("pause");
            return retorno;
        }

        for(int i=0; i<tam; i++)
        {

            auxEmple = (Employee*)ll_get(pArrayListEmployee,i);

            if(auxEmple!=NULL)
            {
                fprintf(auxFile,"%d,%s,%d,%d\n",auxEmple->id,auxEmple->nombre,auxEmple->horasTrabajadas,auxEmple->sueldo);
                retorno = ALLOK;
            }
        }
        fclose(auxFile);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* Direecion de la ubicacion del archivo.
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [1] si se cargo correctamente - [-1] Si hubo un error.
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = ERROR;
    FILE* auxFile;
    int tam = ll_len(pArrayListEmployee);


    if(tam>0 && path!=NULL && pArrayListEmployee!=NULL)
    {
        auxFile = fopen(path,"wb");
        if(auxFile!=NULL)
        {
            for(int i=0; i<tam; i++)
            {
                fwrite(ll_get(pArrayListEmployee,i),sizeof(Employee),1,auxFile);
            }
        }

        fclose(auxFile);
        retorno = ALLOK;
    }
    return retorno;
}



