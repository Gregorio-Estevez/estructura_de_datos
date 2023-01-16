// Ejercicio.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <process.h>
using namespace std;

int validation (int n)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		system("cls");
		cout << "Coloco un valor invalido, favor volver a intentarlo.";
		cin >> n;
	}
	return n;
}

bool ParNumber(int n)
{
	if (n % 2 == 0 && n != 0)
	{
		return true;
	}
	return false;
}

void load(int values[]) {
	for (int i = 0; i < 25; i++)
	{
		
		cout << values[i] << " ";
	}
}

int main()
{
	int numbers[25];
	int pares[25];
	int result = 0;
	int mayor = 0;
	int valor;
	int i = 0;
	int* s = numbers;

	cout << "Bienvenido en el programa que suma los numeros que inserte, tiene un limite de 25. Si se quiere detener coloque un 0 y presione enter."<<"\n";
	
	do
	{
		cout <<i+1<<". Coloque un numero y presione enter: ";
		cin >> valor;
		numbers[i] = validation(valor);
		result += numbers[i];
		if (ParNumber(numbers[i]))
		{
			pares[i] = numbers[i];
		}
		if (i >0 && mayor < numbers[i])
		{
			mayor = numbers[i];
		}
		i++;

	} while (valor != 0 && i < 25);

	cout << "Mayor: " << mayor<<"\n";
	cout << "Suma: " << result << "\n";
	cout << "Numeros pares: ", load(pares);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
