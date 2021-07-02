#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define ERROR -1
#define ALLOK 1
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

//--------------------------------------------------[EXTRAS]-------------------------------------------------------//

int mostrarPorReferencia(Employee* lista);
int mostrarEmpleados(Employee** lista,int tam);
int mostrarUnEmp(Employee* this);


int employee_compararSalario(void* employee1,void* employee2);
int employee_compararHoras(void* employee1,void* employee2);
int employee_compararNombre(void* employee1,void* employee2);
int employee_compararId(void* employee1,void* employee2);


//-----------------------------------------------------------------------------------------------------------------//




#endif // employee_H_INCLUDED
