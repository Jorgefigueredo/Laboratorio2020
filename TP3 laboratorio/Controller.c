#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* archivo;
	int retorno=0;


	if(path!=NULL&&pArrayListEmployee!=NULL)
	{
		archivo=fopen(path,"r");
		if(path!=NULL)
		{
			if(parser_EmployeeFromText(archivo,pArrayListEmployee))
			{
				retorno=1;
			}
		}
	}

	if(retorno)
	{
		printf("\nDatos cargados con exito\n");
	}

	fclose(archivo);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* archivo;
	int retorno=0;


	if(path!=NULL&&pArrayListEmployee!=NULL)
	{
		archivo=fopen(path,"rb");
		if(archivo!=NULL)
		{
			if(parser_EmployeeFromBinary(archivo,pArrayListEmployee))
			{
				retorno=1;
			}
		}
	}

	if(retorno)
	{
		printf("\nDatos cargados con exito\n");
	}

	fclose(archivo);
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
	int retorno=0;

	if(employee_addEmployee(pArrayListEmployee))
	{
		printf("Se ha aniadido con exito\n");
	}
	else
	{
		printf("No se pudo aniadir el empleado\n");
	}

    return retorno;
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

	int retorno=0;

	if(pArrayListEmployee!=NULL&&employee_editEmployee(pArrayListEmployee))
	{
		printf("Cambios guardados con exito\n");
		retorno=1;
	}
	else
	{
		printf("Los cambios no pudieron guardarse\n");
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
	int retorno=0;

	if(pArrayListEmployee!=NULL)
	{
		if(employee_removeEmployee(pArrayListEmployee))
		{
			printf("Dada de baja exitosamente\n");
		}
		else
		{
			printf("No se ha podido dar de baja\n");
		}
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
	int retorno=0;
	if(employees_list(pArrayListEmployee))
	{
		retorno=1;
	}

	return retorno;

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
	int retorno=0;

	if(pArrayListEmployee!=NULL)
	{
		if(employee_sortEmployee(pArrayListEmployee))
		{
			printf("Se ha ordenado con exito\n");
		}
		else
		{
			printf("No ha podido ordenarse\n");
		}
	}

	return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int tam=ll_len(pArrayListEmployee);
	FILE* archivo;
	Employee* auxiliar;
	char nombre[128];
	int id;
	int sueldo;
	int horas;

	if(path!=NULL&&pArrayListEmployee!=NULL)
	{
		archivo=fopen(path,"w");
		if(archivo!=NULL)
		{
			for(int i=0;i<tam;i++)
			{
				if(i==0)
				{
					fprintf(archivo,"id,nombre,horasTrabajadas,sueldo\n");
				}
				else
				{
					auxiliar=(Employee*)ll_get(pArrayListEmployee,i);
					if(auxiliar!=NULL)
					{
						if(employee_getId(auxiliar,&id)
							&&employee_getNombre(auxiliar,nombre)
							&&employee_getSueldo(auxiliar,&sueldo)
							&&employee_getHorasTrabajadas(auxiliar,&horas))
							{
								fprintf(archivo,"%d,%s,%d,%d\n",id,nombre,horas,sueldo);
							}
						retorno=1;
					}
				}
			}
		}
	}

	fclose(archivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	FILE* archivo;
	Employee* auxiliar;

	int tam=ll_len(pArrayListEmployee);

	if(path!=NULL&&pArrayListEmployee!=NULL)
	{
		archivo=fopen(path,"wb");
		if(archivo!=NULL)
		{
			for(int i=0;i<tam;i++)
			{

					auxiliar=(Employee*)ll_get(pArrayListEmployee,i);
					if(auxiliar!=NULL)
					{
						fwrite(auxiliar, sizeof(Employee), 1, archivo);
						retorno=1;
					}

			}
		}

	}
	fclose(archivo);
    return retorno;
}
