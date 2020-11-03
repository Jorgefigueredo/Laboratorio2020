#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
    setbuf(stdout,NULL);
    int mainOption;
    int flag=0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    if(listaEmpleados!=NULL)
    {
        do{
                        system("cls");
                printf("********Menu de opciones**********\n");

                printf("1-Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
                printf("2-Cargar los datos de los empleados desde el archivo data.bin(modo binario)\n");
                printf("3-Alta de empleado\n");
                printf("4-Modificar datos de empleado\n");
                printf("5-Baja de empleado\n");
                printf("6-Listar empleados\n");
                printf("7-Ordenar empleados\n");
                printf("8-Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
                printf("9-Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
                printf("10-Salir\n");
                printf("Ingrese la opcion: ");
                fflush(stdin);
                scanf("%d",&mainOption);

            switch(mainOption)
            {
                case 1:
                    if(flag==0)
                    {
                    	controller_loadFromText("data.csv",listaEmpleados);
                    	flag=1;
                    }
                    else
                    {
                    	if(flag==1)
                    	{
                    		printf("Ya se cargaron los datos en texto\n");
                    	}
                    	else
                    	{
                    		printf("Los datos ya se cargaron como binario\n");
                    	}
                    }

                    break;
                case 2:
                	if(flag==0)
                	{
                		controller_loadFromBinary("data.bin", listaEmpleados);
                		flag=2;
                	}
                	else
                	{
                		if(flag==2)
                		{
                			printf("Ya se cargaron los datos en binario\n");
                		}
                		else
                		{
                			printf("Los datos ya se cargaron como texto\n");
                		}
                	}

                	break;
                case 3:
                	controller_addEmployee(listaEmpleados);
                	break;
                case 4:
                	controller_editEmployee(listaEmpleados);
                	break;
                case 5:
                	controller_removeEmployee(listaEmpleados);
                	break;
                case 6:
                	employees_list(listaEmpleados);
                	break;
                case 7:
                	controller_sortEmployee(listaEmpleados);
                	break;
                case 8:
                	if(controller_saveAsText("data.csv",listaEmpleados))
                	{
                		printf("Cargado con exito\n");
                	}
                	else
                	{
                		printf("No se pudo cargar\n");
                	}
                	break;
                case 9:
                	if(controller_saveAsBinary("data.bin",listaEmpleados))
					{
                		printf("Cargado con exito\n");
					}
                	else
                	{
                		printf("No se pudo cargar\n");
                	}
                	break;
                case 10:
                	break;
                default:
                	printf("Opcion invalida\n");
                	break;
            }
            system("pause");
        }while(mainOption != 10);
    }
    else
    {
    	printf("No se pudo asignar memoria disponible\n");
    	exit(EXIT_FAILURE);
    }

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}






