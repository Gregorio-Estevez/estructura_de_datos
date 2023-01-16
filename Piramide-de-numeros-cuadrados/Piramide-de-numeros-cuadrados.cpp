/*
Realizar un programa que calcule con 10,000 bolas cuantas capas de una piramide se pueden formar y cuantas bolas van a sobrar.
Tomando en cuenta que cada capa estara formado con un numero de base cuadrada (1, 4, 9, 16...).

Piramide-de-numeros cuadrados.cpp

PARTICIPANTES:
Francisco Taveras  -  1107975
Gregorio Estevez   -  1106269
Guillermo Jorge    -  1107266
Mario lora         -  1106278

5/5

Fecha de realizacion:  08/11/2022
Fecha de presentacion: 21/11/2022
*/

#include <iostream>
#include <cmath>
#include <process.h> 

using namespace std;

int validatorCin(int n) // validador de entrada numerica.
{
    while (cin.fail() || n < 1)
    {
        cin.clear();
        cin.ignore();
        system("cls");
        cout << "valor invalido. vuelvalo a insertar (recuerde presionar enter despues de insertar la opcion): ";
        cin >> n;
    }
    system("cls");
    return n;
}

int main()
{
    int balls; //bolas para la piramide
    int layers = 0; // Esta son las capas de la piramide
    int square = 1;// Es la dimension de la capa 2x2, 3x3, 4x4,...

    cout << "Bienvenido al programa que indica las capas de una piramides de numeros de base cuadrada con bolas :>.";
    cout << "\n\nFavor indicar la cantidad de bolas que usara para formar su piramide \n(al colocar la cantidad favor presionar enter): ";
    cin >> balls;
    balls = validatorCin(balls);//Valida el input que tiene que ser entero

    while (balls >= pow(square, 2))//Mientras el numero de bolas introducidas >:) sea mayor o igual a la capacidad de bolas de cada capa
    {
        balls -= pow(square, 2); // se le va restando la capacidad de bolas de la capa correspondiente al numero de bolas >:)
        square++;// se pasa a la siguiente capa por llenar
        layers++;// y se llena la que se acaba de pasar
    }

    cout << "Su piramide tiene " << layers << " capas y te sobraron " << balls << " bolas.\n\n";
}
