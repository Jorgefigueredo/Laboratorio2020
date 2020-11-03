#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validacion.h"


Employee* employee_new()
{
	Employee* nuevoEmpleado=NULL;

	nuevoEmpleado=(Employee*)malloc(sizeof(Employee));

	if(nuevoEmpleado!=NULL)
	{
		nuevoEmpleado->id=0;
		nuevoEmpleado->sueldo=0;
		nuevoEmpleado->horasTrabajadas=0;
		strcpy(nuevoEmpleado->nombre,"");

	}
	return nuevoEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* nuevoEmpleadoParams=NULL;
	nuevoEmpleadoParams=employee_new();
	if(nuevoEmpleadoParams!=NULL)
	{
		if(!(employee_setId(nuevoEmpleadoParams,atoi(idStr))
			&&employee_setNombre(nuevoEmpleadoParams,nombreStr)
			&&employee_setHorasTrabajadas(nuevoEmpleadoParams,atoi(horasTrabajadasStr))
			&&employee_setSueldo(nuevoEmpleadoParams,atoi(sueldoStr))))
		{
			employee_delete(nuevoEmpleadoParams);
		}
	}
	else
	{
		employee_delete(nuevoEmpleadoParams);
	}

	return nuevoEmpleadoParams;
}

int employee_delete(Employee* empleado)
{
	int retorno=0;
	if(empleado!=NULL)
	{
		free(empleado);
		empleado=NULL;
		retorno=1;
	}

	return retorno;
}


int employee_setId(Employee* this,int id)
{
	int retorno=0;
	if(this!=NULL&&id>0)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=0;

	if(this!=NULL&&nombre!=NULL&&validarStringLetras(nombre,sizeof(nombre)))
	{
		strcpy(this->nombre,nombre);
		retorno=1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=0;
	if(this!=NULL&&horasTrabajadas>0)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=1;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=0;
	if(this!=NULL&&sueldo>0)
	{
		this->sueldo=sueldo;
		retorno=1;
	}
	return retorno;
}



int employee_getId(Employee* this,int* id)
{
	int retorno=0;
	if(this!=NULL&&id!=NULL)
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=0;
	if(this!=NULL&&nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=1;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=0;
	if(this!=NULL&&horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=1;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=0;
	if(this!=NULL&&sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=1;
	}
	return retorno;
}

int list_oneEmployee(LinkedList* pArrayListEmployee,int index)
{
	int retorno=0;
	char nombre[128];
	int id;
	int sueldo;
	int horas;
	Employee* auxiliar=NULL;

	if(pArrayListEmployee!=NULL&&index>=0)
	{
		auxiliar=(Employee*)ll_get(pArrayListEmployee,index);
		if(auxiliar!=NULL)
		{
			if(employee_getId(auxiliar,&id)
				&&employee_getNombre(auxiliar,nombre)
				&&employee_getHorasTrabajadas(auxiliar,&horas)
				&&employee_getSueldo(auxiliar,&sueldo))
			{
				printf("%6d  %16s  %6d  %15d\n",id,nombre,horas,sueldo);
				retorno=1;
			}
		}


	}

	return retorno;
}

int employees_list(LinkedList* pArrayListEmployee)
{

	int retorno=0;
	int tam;
	int flag;


	if(pArrayListEmployee!=NULL)
	{
		tam=ll_len(pArrayListEmployee);
		printf("%d\n",tam);
		retorno=1;
		printf("    ID            NOMBRE  HORASTRABAJADAS   SUELDO\n");
		for(int i=0;i<tam;i++)
		{
			flag=list_oneEmployee(pArrayListEmployee,i);
		}
	}


	if(!flag)
	{
		printf("No hay empleados que mostrar\n");
	}

    return retorno;
}

int employee_FindId (LinkedList* pArrayListEmployee, int id)
{
	int retorno=-1;
	int tam=ll_len(pArrayListEmployee);
	Employee* auxiliar;
	int idAux;

	if(pArrayListEmployee!=NULL&&id>0)
	{
		for(int i=0;i<tam;i++)
		{
			auxiliar=(Employee*)ll_get(pArrayListEmployee,i);
			if(auxiliar!=NULL)
			{
				employee_getId(auxiliar,&idAux);
				if(idAux==id)
				{
					retorno=i;
					break;
				}
			}

		}
	}
	return retorno;
}

int employee_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=0;

	Employee* nuevoEmpleado;
	char auxiliarnombre[128];
	int auxiliarid;
	int auxiliarhoras;
	int auxiliarsueldo;


	if(pArrayListEmployee!=NULL)
	{
		nuevoEmpleado=employee_new();

		if(getString(auxiliarnombre,sizeof(auxiliarnombre),"Ingrese nombre del empleado: ","Error, el nombre no es valido",1)
				&&getInt(&auxiliarid,"Ingrese ID: ","Error, el ID no es valido",1,1)
				&&getInt(&auxiliarhoras,"Ingrese horas trabajadas: ","Error, las horas son numeros enteros",0,1)
				&&getInt(&auxiliarsueldo,"Ingrese sueldo: ","Error, el sueldo es un numero entero",0,1))
		{
			if(employee_FindId(pArrayListEmployee,auxiliarid)!=-1)
			{
				printf("Ese ID ya se encuentra en la lista\n");
			}
			else
			{
				if(employee_setNombre(nuevoEmpleado,auxiliarnombre)
						&&employee_setId(nuevoEmpleado,auxiliarid)
						&&employee_setHorasTrabajadas(nuevoEmpleado,auxiliarhoras)
						&&employee_setSueldo(nuevoEmpleado,auxiliarsueldo))
				{
					ll_add(pArrayListEmployee,nuevoEmpleado);
					retorno=1;
				}
			}
		}
	}

	employee_delete(nuevoEmpleado);
	return retorno;
}

int employee_editEmployee(LinkedList* pArrayListEmployee)
{
	int idAux;
	int index;
	int opcion;
	int flag=0;
	Employee* auxiliar=NULL;
	if(pArrayListEmployee!=NULL)
	{
		employees_list(pArrayListEmployee);
		if(getInt(&idAux,"Ingrese ID del empleado a editar: ","Error, ID invalido, debe ser un numero entero",1,01))
		{
			index=employee_FindId(pArrayListEmployee,idAux);
			if(index!=-1)
			{
				printf("    ID            NOMBRE  HORASTRABAJADAS   SUELDO\n");
				list_oneEmployee(pArrayListEmployee,index);
				system("pause");
				auxiliar=ll_get(pArrayListEmployee,index);
				if(auxiliar!=NULL)
				{
					do{
                          system("cls");
                    printf("********Menu de opciones**********\n");

                    printf("1-Cambiar nombre\n");
                    printf("2-Cambiar horas trabajadas\n");
                    printf("3-Cambiar sueldo\n");
                    printf("0-Salir\n");
                    printf("Ingrese la opcion: ");
                    fflush(stdin);
                    scanf("%d",&opcion);




						switch(opcion)
						{
						case 1:
							if(employee_editNombre(pArrayListEmployee,index))
							{
								printf("Se cambio el nombre con exito\n");
								list_oneEmployee(pArrayListEmployee,index);
								system("pause");
								flag=1;
							}
							else
							{
								printf("Ha ocurrido un error, no se pudo cambiar el nombre\n");
							}
							break;
						case 2:
							if(employee_editHoras(pArrayListEmployee,index))
							{
								printf("Se cambiaron las horas de trabajo con exito\n");
								list_oneEmployee(pArrayListEmployee,index);
								system("pause");
								flag=1;
							}
							else
							{
								printf("Ha ocurrido un error, no se pudieron cambiar las horas\n");
							}
							break;
						case 3:
							if(employee_editSueldo(pArrayListEmployee,index))
							{
								printf("Se cambio el sueldoe con exito\n");
								list_oneEmployee(pArrayListEmployee,index);
								system("pause");
								flag=1;
							}
							else
							{
								printf("Ha ocurrido un error, no se pudo cambiar el sueldo\n");
							}
							break;
						case 0:
							break;
						default:
							printf("Opcion invalida\n");
							break;
						}

					}while(opcion!=0);
				}
			}
			else
			{
				printf("ID no encontrado en la lista\n");
			}
		}


	}

    return flag;
}




int employee_editNombre(LinkedList* pArrayListEmployee,int index)
{
	int retorno=0;
	char nombre[128];
	Employee* auxiliarN;

	auxiliarN=(Employee*)ll_get(pArrayListEmployee,index);
	if(auxiliarN!=NULL&&getString(nombre,sizeof(nombre),"Ingrese nombre del empleado: ","Error, el nombre no es valido",1))
	{
		employee_setNombre(auxiliarN,nombre);
		retorno=1;
	}

	return retorno;

}

int employee_editHoras(LinkedList* pArrayListEmployee,int index)
{
	int retorno=0;

	int horas;
	Employee* auxiliarH;

	auxiliarH=(Employee*)ll_get(pArrayListEmployee,index);
	if(auxiliarH!=NULL&&getInt(&horas,"Ingrese horas trabajadas: ","Error, las horas son numeros enteros",0,1))
	{
		employee_setHorasTrabajadas(auxiliarH,horas);
		retorno=1;
	}

	return retorno;

}

int employee_editSueldo(LinkedList* pArrayListEmployee,int index)
{
	int retorno=0;
	int sueldo;
	Employee* auxiliarS;

	auxiliarS=(Employee*)ll_get(pArrayListEmployee,index);
	if(auxiliarS!=NULL&&getInt(&sueldo,"Ingrese sueldo: ","Error, el sueldo es un numero entero",0,1))
	{
		employee_setSueldo(auxiliarS,sueldo);
		retorno=1;
	}

	return retorno;

}

int employee_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int idAux;
	int index;
	char conf='n';

	if(pArrayListEmployee!=NULL)
	{
		employees_list(pArrayListEmployee);
		if(getInt(&idAux,"Ingrese ID: ","Error, el ID no es valido",1,0))
		{
			index=employee_FindId(pArrayListEmployee,idAux);
			if(index!=-1)
			{
				printf("    ID            NOMBRE  HORASTRABAJADAS   SUELDO\n");
				list_oneEmployee(pArrayListEmployee,index);
				printf("Desea confirmar la baja? s para confirmar, cualquier letra para cancelar\n");
				scanf("%c",&conf);
				if(conf=='s')
				{
					ll_remove(pArrayListEmployee,index);
					retorno=1;
				}
				else
				{
					printf("Baja cancelada\n");
				}
			}
			else
			{
				printf("Ese ID no se encuentra en la lista\n");
			}
		}
	}


    return retorno;
}


int comparaPorID(void* pPersonA,void* pPersonB)
{
	int retorno;
	Employee* aux1;
	Employee* aux2;
	int id1;
	int id2;

	if(pPersonA!=NULL&&pPersonB!=NULL)
	{
		aux1=(Employee*)pPersonA;
		aux2=(Employee*)pPersonB;

		if(employee_getId(aux1,&id1)
		&&employee_getId(aux2,&id2))
		{
			if(id1 > id2)
			{
			 retorno=1;
			}
			else
			{
				if(id1 < id2)
				{
				 retorno=-1;
				}
				else
				{
					retorno=0;
				}
			}
		}

	}
	return retorno;
}

int comparaPorHoras(void* pPersonA,void* pPersonB)
{
	int retorno;
	Employee* aux1;
	Employee* aux2;
	int horas1;
	int horas2;

	if(pPersonA!=NULL&&pPersonB!=NULL)
	{
		aux1=(Employee*)pPersonA;
		aux2=(Employee*)pPersonB;

		if(employee_getHorasTrabajadas(aux1,&horas1)
		&&employee_getHorasTrabajadas(aux2,&horas2))
		{
			if(horas1 > horas2)
			{
			 retorno=1;
			}
			else
			{
				if(horas1 < horas2)
				{
				 retorno=-1;
				}
				else
				{
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

int comparaPorSueldo(void* pPersonA,void* pPersonB)
{
	int retorno;
	Employee* aux1;
	Employee* aux2;
	int sueldo1;
	int sueldo2;

	if(pPersonA!=NULL&&pPersonB!=NULL)
	{
		aux1=(Employee*)pPersonA;
		aux2=(Employee*)pPersonB;

		if(employee_getSueldo(aux1,&sueldo1)
		&&employee_getSueldo(aux2,&sueldo2))
		{
			if(sueldo1 > sueldo2)
			{
			 retorno=1;
			}
			else
			{
				if(sueldo1 < sueldo2)
				{
				 retorno=-1;
				}
				else
				{
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

int comparaPorNombre(void* pPersonA,void* pPersonB)
{
	int retorno;
	Employee* aux1;
	Employee* aux2;
	char nombre1[128];
	char nombre2[128];

	if(pPersonA!=NULL&&pPersonB!=NULL)
	{
		aux1=(Employee*)pPersonA;
		aux2=(Employee*)pPersonB;

		if(employee_getNombre(aux1,nombre1)
		&&employee_getNombre(aux2,nombre2))
		{
			if(strcmp(nombre1,nombre2)>0)
			{
				retorno=1;
			}
			else
			{
				if(strcmp(nombre1,nombre2)<0)
				{
					retorno=-1;
				}
				else
				{
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

int employee_sortEmployee(LinkedList* pArrayListEmployee)
{
		int retorno=0;
		int opcion;
		int orden;

		if(pArrayListEmployee!=NULL)
		{
                    printf("********Menu de opciones**********\n");

                        printf("1-Ordenar por nombre\n");
                        printf("2-Odenar por horas trabajadas\n");
                        printf("3-Ordenar por sueldo\n");
                        printf("4-Ordenar por ID\n");
                        printf("Ingrese la opcion: ");
                        fflush(stdin);
                        scanf("%d",&opcion);






					switch(opcion)
					{
					case 1:
					    printf("Ingrese el tipo de orden\n");
                        scanf("%d", &orden);
						ll_sort(pArrayListEmployee,comparaPorNombre,orden);
						retorno=1;
						break;
					case 2:
					    printf("Ingrese el tipo de orden\n");
                        scanf("%d", &orden);
						ll_sort(pArrayListEmployee,comparaPorHoras,orden);
						retorno=1;
						break;
					case 3:
					    printf("Ingrese el tipo de orden\n");
                        scanf("%d", &orden);
						ll_sort(pArrayListEmployee,comparaPorSueldo,orden);
						retorno=1;
						break;
					case 4:
					    printf("Ingrese el tipo de orden\n");
                        scanf("%d", &orden);
						ll_sort(pArrayListEmployee,comparaPorID,orden);
						retorno=1;
						break;
					default:
						printf("Opcion invalida\n");
						break;
					}

		}
	    return retorno;
}


