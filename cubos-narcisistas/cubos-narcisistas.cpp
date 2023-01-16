/*
Crear un programa un progama que muestre los cubos narcisistas 

cubos-narcisistas.cpp

PARTICIPANTES:
Francisco Taveras  -  1107975
Gregorio Estevez   -  1106269
Guillermo Jorge    -  1107266
Mario lora         -  1106278

Fecha de realizacion:  12/11/2022
Fecha de presentacion: 21/11/2022
*/

#include <iostream>
#include <cmath>
using namespace std;

bool narcisista(int n)
{
    int digito = 0;
    int copy = n;
    int suma = 0;

    while (copy > 0)
    {
        digito = copy % 10;
        copy /= 10;
        suma += pow(digito,3);
    }
    if (suma == n)
    {
        return true;
    }
    return false;
}

int main()
{
    for (int i = 100; i < 1000; i++)
    {
        if (narcisista(i))
        {
            cout << i << " Es un cubo narcisista\n";
        }
    }
    cout << "\n\nGracias!\n";
}