#include "funciones.h"


int SumarNumeros (int primerOperando, int segundoOperando)
{
        int suma;
        suma = primerOperando + segundoOperando;
        return suma;
}


int RestarNumeros (int primerOperando, int segundoOperando)
{
        int resta;
        resta = primerOperando - segundoOperando;
        return resta;
}


int MulplicarNumeros (int primerOperando, int segundoOperando)
{
        int multiplicacion;
        multiplicacion = primerOperando * segundoOperando;
        return multiplicacion;
}

float DividirNumeros (int primerOperando, int segundoOperando)
{
    int division;
    division = (float) primerOperando / segundoOperando;
    return division;
}

int CalcularFactorial(int numero)
{
    int resultado;

    if(numero == 0)
    {
        resultado = 1;
    }
    else
    {
         resultado = numero * CalcularFactorial(numero - 1);
    }

    return resultado;

}
