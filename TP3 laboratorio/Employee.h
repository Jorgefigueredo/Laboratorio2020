#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
int employee_delete(Employee* empleado);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_CompareByName(Employee* e1, Employee* e2);
int employee_CompareById(Employee* e1, Employee* e2);


int employee_editEmployee(LinkedList* pArrayListEmployee);
int employee_editNombre(LinkedList* pArrayListEmployee,int index);
int employee_editHoras(LinkedList* pArrayListEmployee,int index);
int employee_editSueldo(LinkedList* pArrayListEmployee,int index);
int employee_addEmployee(LinkedList* pArrayListEmployee);
int employee_sortEmployee(LinkedList* pArrayListEmployee);
int employees_list(LinkedList* pArrayListEmployee);
int employee_removeEmployee(LinkedList* pArrayListEmployee);


#endif
