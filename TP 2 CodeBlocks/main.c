#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

#include "ArrayEmployees.h"
#include "funciones.h"


int printEmployees(eEmployee* unEmpleado, int len);
void printEmployee(eEmployee unEmpleado);
int main()
{
    eEmployee unEmpleado[TAM];              //unEmpleado Array de la estructura eEmployee
    initEmployees(unEmpleado,TAM);          //Llamado a la funcion initEmployees
    int id = 1;
    int order;
    char exit = 'n';

    do{
        switch(menu()){

        case 1:
            if(cargarEmpleado(unEmpleado,TAM,id)){
                printf("Carga exitosa!\n");
                system("pause");
                id++;
            }
            else{
               printf("Hubo un error!\n");
            }
            break;

        case 2:
             printf(" %d %10s %10s %2.f %d %d \n",unEmpleado[0].id,unEmpleado[0].name,unEmpleado[0].lastName,unEmpleado[0].salary,unEmpleado[0].sector,unEmpleado[0].isEmpty);
           system("pause");
            break;

        case 3:
            printEmployees(unEmpleado,TAM);
            system("pause");
            break;

        case 4:/*
            printf("  Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n");
            printf("  Ingrese : \n1-Listado ascendente\n2-Listado descendete.\n");
            fflush(stdin);
            scanf("%d",&order);
            sortEmployees(unEmpleado,TAM,order);
            system("pause")
*/
            break;

        case 5:
            printf("Confirma que desea salir? s/n\n");
            fflush(stdin);
            scanf("%c",&exit);
            break;
        default:
            printf("No ingreso una opcion valida\n");
            break;

        }//switch
    }
    while(exit == 'n');


    return 0;

}


int printEmployees(eEmployee* unEmpleado, int len)
{

    int i;
    printf("%8s %20s %20s %10s %8s\n", "Id",
                                       "Nombre",
                                       "Apellido",
                                       "Salario",
                                       "Sector");

    for(i = 0; i < len; i++)
    {
          if(unEmpleado[i].isEmpty == 1)
            {
                printEmployee(unEmpleado[i]);

            }

    }

    return 0;
}

void printEmployee(eEmployee unEmpleado)
{
    printf("%8d %20s %20s %10.2f %8d\n", unEmpleado.id,
                                           unEmpleado.name,
                                           unEmpleado.lastName,
                                           unEmpleado.salary,
                                           unEmpleado.sector);
}
