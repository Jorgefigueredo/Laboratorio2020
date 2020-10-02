#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    Employee listaDeEmpleados[TAM];


    int r = initEmployees(listaDeEmpleados, TAM);
    if(r==0)
    {
        mainMenu(listaDeEmpleados, TAM);
    }
    //InicializarIsEmpty(listaDeEmpleados, TAM);
    //MenuPrincipal(listaDeEmpleados, TAM);
}
