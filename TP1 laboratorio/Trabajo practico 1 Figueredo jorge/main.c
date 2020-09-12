#include "funciones.h"
#include <stdlib.h>

int main()
{
    int opcion;
    int primerOperando;
    int segundoOperando;
    int suma;
    int resta;
    float division;
    int resultado;
    int multiplicacion;
    int factorialPrimerOperando;
    int factorialSegundoOperando;
    int banderaPrimeroOperando;
    int banderaSegundoOperando;



    banderaPrimeroOperando = 0;
    banderaSegundoOperando = 0;


    printf("Bienvenido a la calculadora!");



    do
    {
        if(banderaPrimeroOperando==0)
        {
            printf("\n1. Ingresar primer operando. (A=X)");
        }
        else
        {
            printf("\n1. Ingresar primer operando. (A=%d)" , primerOperando);
        }


        if(banderaSegundoOperando==0)
        {
            printf("\n2. Ingresar segundo operando. (B=Y)");
        }
        else
        {
            printf("\n2. Ingresar segundo operando. (B=%d)" , segundoOperando);
        }
        printf("\n3. Calcular las operaciones.\n");
        printf("4. Informar resultados.\n");
        printf("5. Salir.\n");
        printf("\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                    printf("\nIngrese su primer numero: ");
                    scanf("%d", &primerOperando);
                    banderaPrimeroOperando=1;

                break;
            case 2:
                printf("\nIngrese su segundo numero: ");
                scanf("%d", &segundoOperando);
                banderaSegundoOperando=1;
                break;
            case 3:

                printf("\n Calculando la suma (%d + %d)" , primerOperando, segundoOperando);
                printf("\n Calculando la resta (%d - %d)" , primerOperando, segundoOperando);
                printf("\n Calculando la division (%d / %d)" , primerOperando, segundoOperando);
                printf("\n Calculando la multiplicacion (%d * %d)" , primerOperando, segundoOperando);
                printf("\n Calculando el factorial de (%d!)" , primerOperando);
                printf("\n Calculando el factorial de (%d!)\n" , segundoOperando);
                printf("\n Ingrese 4 para mostrar los resultados.\n");

                suma = SumarNumeros(primerOperando , segundoOperando);
                resta = RestarNumeros (primerOperando , segundoOperando);
                division = DividirNumeros (primerOperando , segundoOperando);
                multiplicacion = MulplicarNumeros (primerOperando , segundoOperando);
                factorialPrimerOperando= CalcularFactorial(primerOperando);
                factorialSegundoOperando= CalcularFactorial (segundoOperando);
                break;
            case 4:
                printf("\nEl resultado de %d+%d es: %d", primerOperando, segundoOperando, suma);
                printf("\nEl resultado de %d-%d es: %d", primerOperando, segundoOperando, resta);
                if(segundoOperando == 0 )
                {
                    printf("No se puede dividir por cero\n");
                }
                else
                {
                    printf("\nEl resultado de %d/%d es: %.2f", primerOperando, segundoOperando,  division);
                }


                printf("\nEl resultado de %d*%d es: %d ", primerOperando, segundoOperando, multiplicacion);

                printf("\nEl factorial de %d es: %d  " , primerOperando, factorialPrimerOperando);
                printf("\nEl factorial de %d es: %d  \n" , segundoOperando, factorialSegundoOperando);
                break;
            case 5:
                printf("Gracias por usar nuestra calculadora");
                break;
        }
    }while(opcion!=5);

    return 0;
}
