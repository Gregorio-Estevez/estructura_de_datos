/*
Crear un programa un progama que muestre los cubos narcisistas

cubos-narcisistas.cpp

PARTICIPANTES:
Francisco Taveras  -  1107975
Gregorio Estevez   -  1106269
Guillermo Jorge    -  1107266
Mario lora         -  1106278
Reinaldo Cabrera   -  1085502

Fecha de realizacion:  12/11/2022
Fecha de presentacion: 21/11/2022
*/

#include <iostream>
#include <cmath>
using namespace std;


int main()
{

    int i; //Es el contador de numeros del 100 al 999
    int suma; // Variable donde se ejecuta la suma de los digitos del numero
    int k,// iterador
        num,// Variable que utilizo para separar los digitos del numero
        dn;// "Digito Narcisista" es para almacenar el digito para luego sumarlo

    for (i = 100; i < 1000; i++) //este for es para que recorra los numeros del 100 al 999
    {
        int* digits = new int[3]; // Se declara un puntero que un new array cada ciclo
        num = i;//Almaceno el numero del 100 al 999 correspondiente en num
        k = 0;// el iterador del while comienza en 0
        suma = 0; // la suma es 0 porque todavia no se ha acumulado nada
        while (num >= 10) {   // Este while hace que el numero correspondiente (el cual al principio siempre sera mayor que 10),
                              // sea dividido en sus 3 digitos por separado

            digits[k] = num % 10; // Esta operacion siempre nos da el ultimo digito del numero, es decir si el numero es 354, este sacaria el 4 y lo almacena en un array
                                  // el array en donde se almacena es el array que se creo ligado al puntero
            num /= 10; // tomando como ejemplo el 354, cuando pasa por esta operacion este se divide entre 10 pero solo recoge su parte entera,
                       // es decir que seria ahora 35
            k++; // el iterador sube para recorrer el array
        }
        digits[k] = num; // al final siempre te quedara un numero que es menor que 10, lo que rompera el ciclo, y ese ultimo numero sera el ultimo digito


        for (int j = 0; j < 3; j++) // ciclo para hacer la elevacion al cubo y la suma
        {
            dn = digits[j];
            suma += pow(dn, 3.0);

        }
        if (i == suma) { // si la suma del cubo de sus digitos es igual al numero entonces si es un cubo narcisista
            cout << i << " es narcisista\n";
        }

        delete[] digits; // Cada vez que se hace una iteracion en el ciclo principal se crea un array vinculado al pointer
                         // Para poder cambiar los valores del array cada vez que se evalue un numero, se elimina el array
                         // y al principio del for se crea otro
    }
}



