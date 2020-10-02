#include <string.h>
#include "ArrayEmployees.h"
#include <ctype.h>

int initEmployees(Employee listaDeEmpleados[], int size)
{
    int resultado = 0;

    if(size>0)
    {
        for(int i = 0; i<size; i++)
        {
            listaDeEmpleados[i].isEmpty = 1;
        }
    }
    else
    {
        resultado = -1;
        printf("ERROR: Tamano de lista invalido.");
    }
    return resultado;
}

void mainMenu(Employee listaDeEmpleados[], int size)
{
    char auxOpcionMenuPrincipal;
    int opcionMenuPrincipal;
    int auxIsEmpty;
    int employeeFlag = 0;

    do
    {
        system("cls");
        printf("MENU PRINCIPAL\n\n");
        printf("1) Dar de alta un empleado\n");
        printf("2) Modificar un empleado\n");
        printf("3) Dar de baja un empleado\n");
        printf("4) Informar\n");
        printf("5) Salir\n");
        printf("\nElija una opcion: ");
        scanf("%1s", &auxOpcionMenuPrincipal);

        opcionMenuPrincipal = validationRangeNumbers(auxOpcionMenuPrincipal, 1, 5);
        switch (opcionMenuPrincipal)
        {
            case 1:
                system("cls");
                auxIsEmpty = getNextEmployeeFreeSlot(listaDeEmpleados, size);
                if(auxIsEmpty != -1)
                {
                    loadEmployee(listaDeEmpleados, size);
                    printf("\nEmpleado cargado con exito.");
                }
                else
                {
                    printf("ERROR: La lista de empleados esta completa.");
                }
                employeeFlag = 1;
                getch();
                break;

            case 2:
                system("cls");
                if(employeeFlag == 1)
                {
                    loadEmployeeId(listaDeEmpleados, size, opcionMenuPrincipal);
                }
                else
                {
                    printf("ERROR: Primero debe cargar al menos un empleado.");
                }
                getch();
                break;

            case 3:
                system("cls");
                if(employeeFlag == 1)
                {
                    loadEmployeeId(listaDeEmpleados, size, opcionMenuPrincipal);
                    //printEmployees(listaDeEmpleados, size);
                }
                else
                {
                    printf("ERROR: Primero debe cargar al menos un empleado.");
                }
                getch();
                break;

            case 4:
                system("cls");
                if(employeeFlag == 1)
                {
                    inforMenu(listaDeEmpleados, size);
                }
                else
                {
                    printf("ERROR: Primero debe cargar al menos un empleado.");
                }
                getch();

                break;
        }
    }while (opcionMenuPrincipal != 5);

}

void loadEmployee(Employee listaDeEmpleados[], int size)
{
    char name[51];
    char lastname[51];
    float salary;
    int sector;
    char retry;

    do
    {
        int id = getNextEmployeeFreeSlot(listaDeEmpleados, size);
        if(id != -1)
        {
            printf("CARGA DE EMPLEADO\n");
            printf("\nPrimer nombre: ");
            fflush(stdin);
            scanf("%s", name);

            printf("\nApellido: ");
            fflush(stdin);
            scanf("%s", lastname);

            printf("\nSalario: $");
            scanf("%f", &salary);

            printf("\nSector: ");
            scanf("%d", &sector);

            id = id + 1; //correccion primer Id
            int r = addEmployee(listaDeEmpleados, size, id, name, lastname, salary, sector);
            if(r!=0)
            {
                printf("ERROR: Ocurrio un error al intentar agregar un empleado.");
            }
        }
        else
        {
            printf("\nERROR: No hay mas lugar disponible.");
        }

        printf("\nDesea agregar otro empleado? [S/N]");
        scanf("%s", &retry);
        while(retry != 'S' && retry != 's' && retry != 'N' && retry != 'n')
        {
            printf("ERROR: Opcion no valida. Por favor, ingrese S si desea agregar un nuevo empleado o N para volver al menu principal.\n");
            scanf("%s", &retry);
        }
    }while (retry == 'S' || retry == 's');

}

int addEmployee(Employee listaDeEmpleados[], int size, int id, char name[], char lastname[], float salary, int sector)
{
    int i = getNextEmployeeFreeSlot(listaDeEmpleados, size);
    listaDeEmpleados[i].id = id;
    strcpy(listaDeEmpleados[i].name, name);
    strcpy(listaDeEmpleados[i].lastName, lastname);
    listaDeEmpleados[i].salary = salary;
    listaDeEmpleados[i].sector = sector;
    listaDeEmpleados[i].isEmpty = 0;

    return 0;
}

int getNextEmployeeFreeSlot(Employee listaDeEmpleados[], int size)
{
    int index;
    int i;
    index = -1; //si manda -1 es que no hay lugar

    for(i=0; i<size; i++)
    {
        if(listaDeEmpleados[i].isEmpty == 1)
        {
            index = i;//si manda 1 es que haylugar
            break;
        }
    }

    return index;
}

int printEmployees(Employee listaDeEmpleados[], int size)
{
    printf("\n Id | Nombre | Apellido | Salario | Sector");
    for(int i=0; i<size; i++)
    {
        if(listaDeEmpleados[i].isEmpty == 0)
        {
            printf("\n %d | %s | %s | $%.2f | %d",
                   listaDeEmpleados[i].id,
                   listaDeEmpleados[i].name,
                   listaDeEmpleados[i].lastName,
                   listaDeEmpleados[i].salary,
                   listaDeEmpleados[i].sector);
        }
    }
    return 0;
}

void loadEmployeeId(Employee listaDeEmpleados[], int size, int optionMenu)
{
    int id;
    int r;
    do
    {
        system("cls");
        printf("MODIFICAR EMPLEADO\n");
        printf("\nIngrese el ID del empleado que quiera buscar: ");
        scanf("%d", &id);
        if(optionMenu==2)
        {
            r = findEmployeeById(listaDeEmpleados, size, id);

        }
        else
        {

          r = removeEmployee(listaDeEmpleados, size , id);
        }
    } while(r != -1);
}

int findEmployeeById(Employee listaDeEmpleados[], int size, int id)
{
    int response = 0;
    char retry;
    int optionToUpdate;
    char newName[51];
    char newLastname[51];
    float newSalary;
    int newSector;

    if(id>0)
    {
        id=id-1;
        if(listaDeEmpleados[id].isEmpty == 0)
        {
            printf("\nDatos de empleado encontrado:\n");
            printf("\n Id | Nombre | Apellido | Salario | Sector");
            printf("\n %d | %s | %s | $%.2f | %d\n",
                   listaDeEmpleados[id].id,
                   listaDeEmpleados[id].name,
                   listaDeEmpleados[id].lastName,
                   listaDeEmpleados[id].salary,
                   listaDeEmpleados[id].sector);
            printf("\nIngrese la opcion que desea modificar");
            printf("\n1) Nombre"
                   "\n2) Apellido"
                   "\n3) Salario"
                   "\n4) Sector\n");
            scanf("%d", &optionToUpdate);

            while (optionToUpdate < 0 || optionToUpdate > 4) //Validacion de opcion elegida.
            {
                printf("\nERROR: Opcion no valida. Por favor, ingrese un valor entre 1 y 4.\n");
                scanf("%1d", &optionToUpdate);
            };

            switch(optionToUpdate)
            {
            case 1:
                printf("Ingrese el nuevo nombre: ");
                fflush(stdin);
                scanf("%s", newName);
                strcpy(listaDeEmpleados[id].name, newName);
                break;
            case 2:
                printf("Ingrese el nuevo apellido: ");
                fflush(stdin);
                scanf("%s", newLastname);
                strcpy(listaDeEmpleados[id].lastName, newLastname);
                break;
            case 3:
                printf("Ingrese el nuevo salario: ");
                scanf("%f", &newSalary);
                listaDeEmpleados[id].salary = newSalary;
                break;
            case 4:
                printf("Ingrese el nuevo sector: ");
                scanf("%d", &newSector);
                listaDeEmpleados[id].sector = newSector;
                break;
            }
            printf("\nEmpleado actualizado correctamente.");
            response = -1;
        }
        else
        {
            printf("ERROR: El ID ingresado no corresponde a ningun empleado registrado.");
            response = -1;
        }
    }
    else
    {
        printf("ERROR: ID invalido.");
        response = -1;
    }

    if(response==-1)
    {
        printf("\nDesea seguir buscando? [S/N]");
        scanf("%s", &retry);

        while (retry != 'S' && retry != 's' && retry != 'N' && retry != 'n') //Validacion de opcion elegida.
        {
            printf("\nERROR: Opcion no valida. Por favor, ingrese S si desea hacer una nueva busqueda o N para volver al menu principal.\n");
            scanf("%s", &retry);
        };

        if(retry == 'S' || retry == 's')
        {
            response = 0;
        }
        else
        {
            response = -1;
        }
    }

    return response;
}

int removeEmployee(Employee listaDeEmpleados[], int size, int id)
{
    int response = 0;
    char retry;

    if(id>0)
    {
        id=id-1;
        if(listaDeEmpleados[id].isEmpty == 0)
        {
            printf("\nDatos de empleado encontrado:\n");
            printf("\n Id | Nombre | Apellido | Salario | Sector");
            printf("\n %d | %s | %s | $%.2f | %d\n",
                   listaDeEmpleados[id].id,
                   listaDeEmpleados[id].name,
                   listaDeEmpleados[id].lastName,
                   listaDeEmpleados[id].salary,
                   listaDeEmpleados[id].sector);

        printf("\nSeguro que desea eliminar el empleado? [S/N]");
        scanf("%s", &retry);

            while (retry != 'S' && retry != 's' && retry != 'N' && retry != 'n') //Validacion de opcion elegida.
            {
                printf("\nERROR: Opcion no valida. Por favor, ingrese S si para eliminar o N para no eliminar.\n");
                scanf("%s", &retry);
            };

                if(retry == 'S' || retry == 's')
                    {
                        listaDeEmpleados[id].isEmpty =1;
                        response = -1;
                    }
                else
                    {
                        response = -1;
                    }
        }
        else
        {
            printf("ERROR: El ID ingresado no corresponde a ningun empleado registrado.");
            response = -1;
        }
    }
    else
    {
        printf("ERROR: ID invalido.");
        response = -1;
    }

    if(response==-1)
    {
        printf("\nDesea seguir buscando? [S/N]");
        scanf("%s", &retry);

        while (retry != 'S' && retry != 's' && retry != 'N' && retry != 'n') //Validacion de opcion elegida.
        {
            printf("\nERROR: Opcion no valida. Por favor, ingrese S si desea hacer una nueva busqueda o N para volver al menu principal.\n");
            scanf("%s", &retry);
        };

        if(retry == 'S' || retry == 's')
        {
            response = 0;
        }
        else
        {
            response = -1;
        }
    }

    return response;

}

void inforMenu(Employee listaDeEmpleados[], int size)
{
    char opcionMenuInformar;
 do
    {


    printf("\nQue desea hacer\n");
    printf("\n1- Lista de Empleados ordenados alfabeticamente por apellido y sector. \n"
           "2- Total, promedio de salarios y cuantos superan ese promedio\n"
           "3- Volver.\n");

        scanf("%1s", &opcionMenuInformar);

        opcionMenuInformar =validationRangeNumbers(opcionMenuInformar, 1, 3);

     //Switch opcionMenuInformar

        switch(opcionMenuInformar)
        {
            case 1:

                    loadOrder(listaDeEmpleados, size);

                break;

            case 2:
                inforSalary(listaDeEmpleados, size );
                break;

        }
    } while(opcionMenuInformar != 3);


}

void loadOrder(Employee listaDeEmpleados[], int size)
{
    int order;
    int r;
    do
    {
        system("cls");
        printf("Ingrese 1 si quiere ordenar de manera ascendente o 0 si quiero ordenar de forma descendente\n");

        scanf("%d", &order);

        r = sortEmployees(listaDeEmpleados, size, order);
    } while(r != -1);
}

int sortEmployees(Employee listaDeEmpleados[], int size, int order)
{





    int response = 0;
    int i;
    int j;
    Employee auxLastName;
    Employee auxSector;

    if(order == 1)
    {
         for(i=0;i<size-1;i++)
        {
            for(j=i+1; j<size; j++)
            {
                    if(listaDeEmpleados[i].sector == listaDeEmpleados[j].sector)
                    {
                            if(strcmp(listaDeEmpleados[i].lastName, listaDeEmpleados[j].lastName)<0 && listaDeEmpleados[i].isEmpty != 1)
                            {
                                auxLastName = listaDeEmpleados[i];
                                listaDeEmpleados[i] = listaDeEmpleados[j];
                                listaDeEmpleados[j] = auxLastName;
                            }
                    }

            }
        }
        for(i=0;i<size-1;i++)
        {
        for(j=i+1; j<size; j++)
        {
            if(listaDeEmpleados[i].sector == listaDeEmpleados[j].sector)
            {

                if(strcmp(listaDeEmpleados[i].lastName, listaDeEmpleados[j].lastName)<0 && listaDeEmpleados[i].isEmpty != 1)
                {
                    auxSector = listaDeEmpleados[i];
                    listaDeEmpleados[i] = listaDeEmpleados[j];
                    listaDeEmpleados[j] = auxSector;
                }

            }

        }

    }
        printEmployees(listaDeEmpleados, size);
        response= -1;

    }else
    {

        for(i=0;i<size-1;i++)
        {
            for(j=i+1; j<size; j++)
            {
                    if(listaDeEmpleados[i].sector == listaDeEmpleados[j].sector)
                    {
                            if(strcmp(listaDeEmpleados[i].lastName, listaDeEmpleados[j].lastName)>0 &&  listaDeEmpleados[i].isEmpty != 1)
                            {
                                auxLastName = listaDeEmpleados[i];
                                listaDeEmpleados[i] = listaDeEmpleados[j];
                                listaDeEmpleados[j] = auxLastName;
                            }
                    }

            }
        }

        for(i=0;i<size-1;i++)
        {
        for(j=i+1; j<size; j++)
        {
            if(listaDeEmpleados[i].sector == listaDeEmpleados[j].sector)
            {

                if(strcmp(listaDeEmpleados[i].lastName, listaDeEmpleados[j].lastName)<0 && listaDeEmpleados[i].isEmpty != 1)
                {
                    auxSector = listaDeEmpleados[i];
                    listaDeEmpleados[i] = listaDeEmpleados[j];
                    listaDeEmpleados[j] = auxSector;
                }

            }

        }

    }
    printEmployees(listaDeEmpleados, size);
    response=-1;
    }


 return response;

}

int employeeCount(Employee listaDeEmpleados[], int size)
{
    int contadorDeEmpleados;

    contadorDeEmpleados = 0;

    for(int i=0 ; i<size ; i++)
    {
        if(listaDeEmpleados[i].isEmpty == 0)
        {
            contadorDeEmpleados++;
        }
    }

    return contadorDeEmpleados;
}

float employeeSalarySum(Employee listaDeEmpleados[], int size)
{
    float salarySum;

    salarySum = 0;

    for(int i=0 ; i<size ; i++)
    {
        if(listaDeEmpleados[i].isEmpty == 0)
        {
            salarySum = listaDeEmpleados[i].salary + salarySum;
        }
    }

    return salarySum;
}

void inforSalary(Employee listaDeEmpleados[], int size)
{
    float salarySumTotal;
    int countEmployeeTotal;
    float promedySalary;
    int countMaxPromedyEmployee;

    salarySumTotal = employeeSalarySum(listaDeEmpleados, size);
    countEmployeeTotal = employeeCount(listaDeEmpleados, size);

    promedySalary = (float) salarySumTotal / countEmployeeTotal;

    countMaxPromedyEmployee = countEmployeeMaxPromedy(listaDeEmpleados, size, promedySalary);

    printf("\nTotal de sueldo de todos los empleados: $%.2f\nPromedio total de los salarios de todos los empleados: %.2f \nLa cantidad de Empleados que superan el sueldo promedio son: %d\n"
           , salarySumTotal,  promedySalary , countMaxPromedyEmployee);

}

int countEmployeeMaxPromedy(Employee listaDeEmpleados[], int size, float promedyTotal)
{
    int countMaxPromedyEmployee;

    countMaxPromedyEmployee = 0;
    for(int i=0 ; i<size ; i++)
    {
        if(listaDeEmpleados[i].isEmpty == 0)
        {
            if(listaDeEmpleados[i].salary > promedyTotal)
            {
                countMaxPromedyEmployee ++;
            }
        }
    }
    return countMaxPromedyEmployee;
}

int validationRangeNumbers(char inputChar, int rangeOne, int rangeTwo)
{
    int auxNumber;

    while(!isdigit(inputChar))
    {
        printf("\nERROR: Solo se permiten digitos. Por favor, ingrese un valor entre %d y %d.\n" , rangeOne, rangeTwo);
        scanf("%1s", &inputChar);
    }

    auxNumber = atoi(&inputChar);
    while(auxNumber < rangeOne || auxNumber > rangeTwo) //Validacion de opcion elegida.
    {
        printf("\nERROR: Opcion no valida. Por favor, ingrese un valor entre %d y %d.\n" , rangeOne, rangeTwo);
        scanf("\n%1d", &auxNumber);
    };
    return auxNumber;
}

