#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Genericas.h"
#include "Menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{

    LinkedList* listaEmpleados = ll_newLinkedList();
    int flag = 0;

    do
    {
        switch(menuPrincipal())
        {

        case 1:
            if(controller_loadFromText("data.csv",listaEmpleados)==1)
            {
                printf("\nArchivo 'data.csv' cargado correctamente.\n");
                flag = 1;
            }
            else
            {
                printf("\nNo se pudo cargar el archivo 'data.csv'.\n");
            }
            break;

        case 2:
            if(controller_loadFromBinary("data.bin",listaEmpleados)==1)
            {
                printf("\nArchivo 'data.bin' cargado correctamente.\n");
                flag = 1;
            }
            else
            {
                printf("\nNo se pudo cargar el archivo 'data.bin'.\n");
            }
            break;

        case 3:
            if(flag)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }
            break;

        case 4:
            if(flag)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }
            break;

        case 5:
            if(flag)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }
            break;

        case 6:
            if(flag)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }
            break;

        case 7:
              if(flag)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }
            break;
        case 8:
                if(flag)
            {
                controller_saveAsText("data.csv",listaEmpleados);
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }
            break;

        case 9:
                if(flag)
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
            }
            else
            {
                printf("\nPrimero debe cargar un archivo.\n");
            }
            break;

        case 10:
            exit(1);
            break;
        default:
            system("cls");
            printf("\nNo ingreso una opcion valida.\n\n");
            break;
        }
        system ("pause");
    }
    while(1);


    return 0;
}

