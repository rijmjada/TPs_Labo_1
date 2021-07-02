#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"


int menu()
{

    int opcionMenu;

    system("cls");
    printf("          MENU DE OPCIONES\n\n");
    printf("1- ALTAS\n");
    printf("2- BAJAS\n");
    printf("3- MODIFICACIONES\n");
    printf("4- INFORMES\n");
    printf("5- SALIR\n");
    printf("\n SELECCIONE UNA OPCION : ");

    fflush(stdin);
    scanf("%d",&opcionMenu);

    return opcionMenu;
}

int initEmployees(eEmployee unEmpleado[], int len)
{
    int i;
    for(i=0;i < len;i++)
    {
        unEmpleado[i].isEmpty = 1;
    }
    return 0;
}

int cargarEmpleado(eEmployee unEmpleado[], int len, int id)
{
    system("cls");
    int retorno = -1;
    int flag = 0;
    char name[24];
    char lastName[24];
    float salary;
    int sector;
    if(unEmpleado != NULL)
    {
        getString(name,"Ingrese nombre(s) empleado (24 caracteres maximo): \n\n","\nEl dato ingresado es erroneo.\n",3,24,5);
        getString(lastName,"Ingrese apellido(s) empleado (24 caracteres maximo):\n\n","\nEl dato ingresado es erroneo.\n",3,24,5);
        utn_getNumero(&sector,"Ingrese sector : ","\nEl dato ingresado es erroneo. \n\n",1,5,5);
        getFloatx(&salary,"\nIngrese salario: ","\nERROR, debe ingresar un numero",1.0,10000000.0,2);

        flag = 1;
    }
    if(flag)
    {
        if(addEmployee(unEmpleado,len,id,name,lastName,salary,sector))
        {
            printf("adddd\n");

            retorno  = 1;
        }

    }

    return retorno;
}

int addEmployee(eEmployee unEmpleado[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int todoOk = -1;

     for(int i = 0;i < len;i++){
        if(unEmpleado[i].isEmpty == 1){

            unEmpleado[i].isEmpty = 0;
            unEmpleado[i].id = id;
            unEmpleado[i].salary = salary;
            unEmpleado[i].sector = sector;
            strcpy(unEmpleado[i].name, name);
            strcpy(unEmpleado[i].lastName, lastName);

            todoOk = 1;
            break;
        }
        else{
            printf("No hay lugar para cargar al empleado!\n");
        }
     }

    return todoOk;
}

int buscarEspacioLibre(eEmployee unEmpleado[], int len)
{

    int lugarLibreArray = -1;
    for(int i=0; i<len; i++)
    {

        if(unEmpleado[i].isEmpty)
        {
            lugarLibreArray = i; // devuelve la posicion libre
            break;
        }
    }

    return lugarLibreArray;
}

int findEmployeeById(eEmployee unEmpleado[], int len, int id)
{

    int index = -1;

    if(unEmpleado != NULL && len > 0)
    {

        for(int i = 0; i < len; i++)
        {
            if(unEmpleado[i].id == id)
            {
                index = i;
                break;
            }
        }

    }

    return index;
}

int removeEmployee(eEmployee unEmpleado[], int len, int id)
{

    int todoOk = -1;
    if(unEmpleado != NULL && len > 0 && id >0 && id <=1000)
    {

        for(int i = 0; i < len; i++)
        {
            if(unEmpleado[i].id == id)
            {
                unEmpleado[i].isEmpty = 1;
                return todoOk = 1;
                break;
            }
        }

    }

    return todoOk;
}


int sortEmployees(eEmployee unEmpleado[], int len, int order)
{

    eEmployee auxEmpleado;
    int todoOk = -1;

    for(int i=0; i<len-1; i ++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(order)
            {
                if(unEmpleado[i].sector > unEmpleado[j].sector || unEmpleado[i].sector == unEmpleado[j].sector || unEmpleado[i].lastName > unEmpleado[j].lastName)
                {
                    auxEmpleado = unEmpleado[i];
                    unEmpleado[i]=unEmpleado[j];
                    unEmpleado[j]=auxEmpleado;

                    todoOk = 1;
                }
            }
            else if(order == 2)
            {
                if(unEmpleado[i].sector < unEmpleado[j].sector || unEmpleado[i].sector == unEmpleado[j].sector || unEmpleado[i].lastName < unEmpleado[j].lastName)
                {

                    auxEmpleado = unEmpleado[i];
                    unEmpleado[i]=unEmpleado[j];
                    unEmpleado[j]=auxEmpleado;

                    todoOk = 1;
                }
            }
            else
            {
                printf("No ingreso una opcion valida\n");
            }


        }
    }

    return todoOk;
}





int modificarDatosEmpleado(eEmployee unEmpleado[], int tam){

    int retorno = -1;
    int bufferId;
    int bufferIndex;
    int select;

    if(unEmpleado != NULL && tam >=0){

        printf("Ingrese el legajo : \n");
        utn_getNumero(&bufferId,"Ingrese ID a del empleado a modificar: ","ERROR, ingrese un ID valido.\n",1,10000,5);

        bufferIndex = findEmployeeById(unEmpleado,tam,bufferId);
        printf("Usted Ingreso el Id : %d\n",bufferIndex);

        if(bufferId == -1){printf("No existe un empleado con ese ID.\n");}

        else{

            printf("Cual campo del empleado desea modificar?\n");
            printf("1-Nombre\n");
            printf("2-Apellido\n");
            printf("3-Salario\n");
            printf("4-Sector\n");
            utn_getNumero(&select,"","ERROR, ingrese un ID valido.\n",1,4,5);

            switch(select){

                case 1:
                    getString(unEmpleado[bufferId].name,"Ingrese nombre(s) empleado (24 caracteres maximo): \n\n","\nEl dato ingresado es erroneo.\n",3,24,5);
                    break;
                case 2:
                    getString(unEmpleado[bufferId].lastName,"Ingrese nombre(s) empleado (24 caracteres maximo): \n\n","\nEl dato ingresado es erroneo.\n",3,24,5);
                    break;
                case 3:
                    getFloatx(&unEmpleado[bufferId].salary,"\nIngrese salario: ","\nERROR, debe ingresar un numero",1.0,10000000.0,2);
                    break;
                case 4:
                    utn_getNumero(&unEmpleado[bufferId].sector,"Ingrese sector : ","\nEl dato ingresado es erroneo. \n\n",1,5,5);
                    break;

            }
        }
    }
    system("pause");
    return retorno;
}



