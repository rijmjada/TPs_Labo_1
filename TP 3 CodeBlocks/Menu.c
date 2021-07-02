
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Genericas.h"

int menuPrincipal(){
    int usuario  = -1;

    system("cls");
    printf("**Menu Principal**\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir.\n");

    fflush(stdin);
    scanf("%d",&usuario);

    return usuario;
}

int menuOrdenar(){
    int option;

    printf("1)Ordenar por id.\n");
    printf("2)Ordenar por nombre.\n");
    printf("3)Ordenar por horas trabajadas.\n");
    printf("4)Ordenar por sueldo.\n");
    printf("5)Salir.\n");
    getInt(&option,"Elija opcion: ","Error.\n",1,5,3);

    return option;
}

int menuTipoOrden(){
    int option;
    system("cls");
    printf("1)Ascendente.\n");
    printf("2)Descendente.\n");
    getInt(&option,"Elija opcion: ","Error.\n",1,2,3);

    return option;
}

int menuModificacion(){
    int usuario;

    printf("**Menu Modificacion**\n\n");

    printf("1)Modificar nombre.\n");
    printf("2)Modificar horas.\n");
    printf("3)Modificar sueldo.\n");
    getInt(&usuario,"Elija opcion <1/3>: ","Error. Reingrese\n",1,3,3);

    return usuario;
}
