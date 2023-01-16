// TorresVSReina.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
#include <windows.h>
using namespace std;


int CinValidator(string value);

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int fReina, cReina, fTorre1, cTorre1, fTorre2, cTorre2;
	bool validar;
	string validator;


	do {
		validar = true;
		system("cls");
		cout << "Ingrese la posicion de la Reina\n";
		cout << "En x: ";
		cin >> validator;
		fReina = CinValidator(validator);

		cout << "En y: ";
		cin >> validator;
		cReina = CinValidator(validator);
		cout << "\n\n";

		cout << "Ingrese la posicion de la primera Torre\n";
		cout << "En x: ";
		cin >> validator;
		fTorre1 = CinValidator(validator);
		cout << "En y: ";
		cin >> validator;
		cTorre1 = CinValidator(validator);
		cout << "\n\n";

		cout << "Ingrese la posicion de la segunda Torre\n";
		cout << "En x: ";
		cin >> validator;
		fTorre2 = CinValidator(validator);
		cout << "En y: ";
		cin >> validator;
		cTorre2 = CinValidator(validator);
		cout << "\n\n";

		if ((fReina == fTorre1 && cReina == cTorre1) || (fReina == fTorre2 && cReina == cTorre2) || (fTorre2 == fTorre1 && cTorre2 == cTorre1)) // Si la posicion de la Reina es igual a la Torre 1
		{
			cout << "La Reina y las torres no pueden estar en la misma posicion" << endl << endl;
			system("pause"); system("cls");
			validar = false;
		}


		if (fReina >= 9 || fReina <= 0 || cReina >= 9 || cReina <= 0 || cTorre1 >= 9 || cTorre1 <= 0 || fTorre1 >= 9 || fTorre1 <= 0 || cTorre2 >= 9 || cTorre2 <= 0 || fTorre2 >= 9 || fTorre2 <= 0) // Si el numero es mayor a 8 o menor que 0
		{
			cout << "El tablero tiene 8 casillas" << endl << endl;
			system("pause"); system("cls");
			validar = false;
		}


	} while (validar == false);

	cout << "\n" << "    1   2   3   4   5   6   7   8" << endl;
	cout << "  ---------------------------------" << endl;
	for (int filas = 1; filas < 9; filas++) // Bucle para imprimir las filas
	{
		cout << " " << filas << "|";

		for (int colum = 1; colum < 9; colum++) // Bucle para imprimir las columnas
		{
			if (colum == cReina && filas == fReina) { // Si la posicion de la reina coincide con la fila y colum.
				SetConsoleTextAttribute(h, 6);
				cout << " R ";
				SetConsoleTextAttribute(h, 7);
				cout << "|";
				continue; // sentencia que permite saltar a la siguiente iteracion de un bucle.
			}

			if (colum == cTorre1 && filas == fTorre1) { // Si la posicion de la Torre1 coincide con la fila y colum.
				SetConsoleTextAttribute(h, 1);
				cout << " T ";
				SetConsoleTextAttribute(h, 7);
				cout << "|";
				continue; // sentencia que permite saltar a la siguiente iteracion de un bucle.
			}

			if (colum == cTorre2 && filas == fTorre2) { // Si la posicion de la Torre2 coincide con la fila y colum.
				SetConsoleTextAttribute(h, 1);
				cout << " T ";
				SetConsoleTextAttribute(h, 7);
				cout << "|";
				continue; // sentencia que permite saltar a la siguiente iteracion de un bucle.
			}

			else if (filas == fReina || colum == cReina)
			{ // Si nos encontramos en la fila o columna de la Reina
				if (filas == fReina && colum == cTorre1 || colum == cTorre2)
				{ // Si estamos en la colunma de la Torre1 o Torre 2
					SetConsoleTextAttribute(h, 4);
					cout << " X ";
					SetConsoleTextAttribute(h, 7);
					cout << "|";
				}
				else if (colum == cReina && filas == fTorre1 || filas == fTorre2)
				{ // Si nos encontramos en la columna de la Reina y en la fila de alguna torre.
					SetConsoleTextAttribute(h, 4);
					cout << " X ";
					SetConsoleTextAttribute(h, 7);
					cout << "|";
				}
				else // De lo contrario
				{
					SetConsoleTextAttribute(h, 2);
					cout << " V ";
					SetConsoleTextAttribute(h, 7);
					cout << "|";
				}
			}

			else if ((filas + colum) == (fReina + cReina) || (filas - colum) == (fReina - cReina))
			{ // Para las diagonales
				if (filas == fReina && colum == cTorre1 || colum == cTorre2)
				{ // Si estamos en la fila de la reina y en colunma de la Torre1 o Torre 2
					SetConsoleTextAttribute(h, 4);
					cout << " X ";
					SetConsoleTextAttribute(h, 7);
					cout << "|";
				}
				else if (colum == cReina && filas == fTorre1 || filas == fTorre2)
				{ // Si nos encontramos en la columna de la Reina y en la fila de alguna torre.
					SetConsoleTextAttribute(h, 4);
					cout << " X ";
					SetConsoleTextAttribute(h, 7);
					cout << "|";
				}
				else if ((filas + colum) == (fReina + cReina) && filas == fTorre1 || filas == fTorre2)
				{ // Si nos encontramos en la fila de una torre en la diagonal de izq a derecha hacia arriba.
					SetConsoleTextAttribute(h, 4);
					cout << " X ";
					SetConsoleTextAttribute(h, 7);
					cout << "|";
				}
				else if ((filas - colum) == (fReina - cReina) && filas == fTorre1 || filas == fTorre2)
				{ // Si nos encontramos en la fila de una torre en la diagonal de izq a derecha hacia abajo.
					SetConsoleTextAttribute(h, 4);
					cout << " X ";
					SetConsoleTextAttribute(h, 7);
					cout << "|";
				}
				else if ((filas - colum) == (fReina - cReina) && colum == cTorre1 || colum == cTorre2)
				{ // Si nos encontramos en la colum de una torre en la diagonal de izq a derecha hacia abajo.
					SetConsoleTextAttribute(h, 4);
					cout << " X ";
					SetConsoleTextAttribute(h, 7);
					cout << "|";
				}
				else if ((filas + colum) == (fReina + cReina) && colum == cTorre1 || colum == cTorre2)
				{ // Si nos encontramos en la colum de una torre en la diagonal de izq a derecha hacia arriba.
					SetConsoleTextAttribute(h, 4);
					cout << " X ";
					SetConsoleTextAttribute(h, 7);
					cout << "|";
				}
				else // Si no choca, es V.
				{
					SetConsoleTextAttribute(h, 2);
					cout << " V ";
					SetConsoleTextAttribute(h, 7);
					cout << "|";
				}
			}

			else if ((filas + colum) % 2 == 0)
			{ // Luego de validar que no vaya ningun mov, se coloca un espacio tomando el residuo de la suma de colum si es par.
				cout << "   |";
			}
			else
			{ // Si es impar.
				cout << "   |";
			}
		}
		cout << "   " << endl;
		cout << " ----------------------------------" << endl;
	}
}

int CinValidator(string value) //metodo para validar que el usuario coloque solo numeros
{
	for (int i = 0; value[i] != '\0'; i++)
	{
		if (!isdigit(value[i]))
		{
			cout << "\nValor invalido!!\nSolo se aceptan numero enteros\n\nFavor volverlo a colocar y presione enter: ";
			cin >> value;
			i = 0;
		}
	}
	return stoi(value);
}