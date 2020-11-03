#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"




	/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char a[128];
	char b[128];
	char c[128];
	char d[128];
	int cantidadLeida;
	int flag=0;
	int titulo=1;
	Employee* auxiliar=NULL;

	if(pFile!=NULL&&pArrayListEmployee!=NULL)
	{
		do
		{

				cantidadLeida=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",a,b,c,d);

				if(cantidadLeida==4&&strlen(a)<128&&strlen(b)<128&&strlen(c)<128&&strlen(d)<128&&titulo!=1)
				{
					auxiliar=employee_newParametros(a,b,c,d);
					if(auxiliar!=NULL)
					{
						ll_add(pArrayListEmployee,auxiliar);
						flag=1;
					}
					else
					{
						employee_delete(auxiliar);
					}
				}
				else
				{
					titulo=0;
				}
		}while(!feof(pFile));
	}



    return flag;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int titulo=1;
	Employee* auxiliar;

	if(pFile!=NULL&&pArrayListEmployee!=NULL)
	{
		do
		{
			auxiliar=employee_new();
			if(auxiliar!=NULL)
			{
				if(titulo!=1)
				{
					if(fread(auxiliar,sizeof(Employee),1,pFile))
					{
						ll_add(pArrayListEmployee,auxiliar);
						retorno=1;
					}
					else
					{
						employee_delete(auxiliar);
					}
				}
				else
				{
					titulo=0;
				}
			}

		}while(!feof(pFile));
	}

    return retorno;
}
