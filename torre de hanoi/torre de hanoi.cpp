/*
Realizar un programa C++ que simule la torre de hanoi.

PARTICIPANTES:
Francisco Taveras  -  1107975
Gregorio Estevez   -  1106269
Guillermo Jorge    -  1107266
Mario lora         -  1106278

Fecha de realizacion:  16/1/2023
Fecha de presentacion: 16/1/2023

*/

#include <iostream>
#include <cmath>          
#include <windows.h>    
#include <string>

using namespace std;

int disco = 0, Jugadas = 0;
char Columna1 = 'A', Columna2 = 'B', Columna3 = 'C';
int num = 0;
string validator="";



void Movimientos(int disco, char Columna1, char Columna2, char Columna3)
{
	if (disco == 1)//Cuando disco sea igual a 1, entonces imprimira el mensaje de que disco va de la torre A hacia la torre C
	{
		cout << "Mover disco " << disco << " de la torre ";
		cout << Columna1;
		cout << " Hasta la torre ";
		cout << Columna3 << endl;
	}
	else//En caso de que no sea igual a 1
	{
		Movimientos(disco - 1, Columna1, Columna3, Columna2);//Llaama nuevamente a la funcion pero con los parametros distintos, disco le restara uno, y los valores de la columna 2 y 3 se intercambian
		cout << "Mover disco " << disco << " de la torre ";
		cout << Columna1;
		cout << " Hasta la torre ";
		cout << Columna3 << endl;//Luego de salir de la funcion,imprime el mensaje siguiente

		Movimientos(disco - 1, Columna2, Columna1, Columna3);//Luego vuelve a llamar la funcion, pero los valores de columna 2 y 1 cambian esta vez
	}
}

int CinValidator(string n)
{
	cin >> n;

	for (int i = 0; n[i] != '\0'; i++)
	{
		if (!isdigit(n[i]) || stoi(n) < 1)
		{
			cout << "\nValor invalido!!\nSolo se aceptan numero enteros y mayores que 0\n\nFavor volverlo a colocar y presione enter: ";
			cin >> n;
			i = 0;
		}
	}

	return stoi(n);
}

void ProcesoHanoi()
{
	if (disco < 13)
	{
		Movimientos(disco, Columna1, Columna2, Columna3);
		Jugadas = pow(2, disco) - 1;
		cout << "\nLas jugadas realizadas correctamente con " << disco << " discos es de: ";
		cout << Jugadas << " jugadas" << endl;
	}
	else
	{
		cout << "\nLa cantidad es muy elevada. Presione enter para continuar." << endl;
	}
}
void menu() {//Interfaz del programa

	system("cls");
	cout << "=========  Programa de Torre de Hanoi  =========\n\n";
	cout << "================================================\n";
	cout << "==              [1] Jugar                     ==\n";
	cout << "==              [2] Reglas                    ==\n";
	cout << "==              [3] Salir                     ==\n";
	cout << "================================================\n";

	cout << "\nDigite su opcion y luego presione enter: ";

}
int main()
{
	bool sentinel = true;

	do {

		menu();
		
		switch (CinValidator(validator))
		{
		case 1:
			cout << "Introduzca el total de disco que desea tener y presione enter: ";

			num = CinValidator(validator);
			disco = num;

			cout << endl;
			ProcesoHanoi();
			system("PAUSE");
			break;
		case 2:

			cout << "\nMandato:\n\nRealizar un programa C++ que permita resolver el problema de las Torres de Hanoi\n\nINSTRUCCIONES:\n\nConsiste en trasladar una cantidad x de anillos desde una torre A a una torre B.\n\nPresione cualquier tecla para continuar\n";
			system("PAUSE");
			break;
		case 3:
			cout << "Saliendo...." << endl;//Mensaje de respuesta
			sentinel = false;//esperando interacion para salir
			break;
		}
	} while (sentinel);
	return 0;
}