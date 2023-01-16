/*
Realizar un programa C++ que simule un tablero de ajedrez donde existen 1 reina y 2 torres donde sean cuales movimientos son posibles para la reina sin ser comida.

PARTICIPANTES:
Francisco Taveras  -  1107975
Gregorio Estevez   -  1106269
Guillermo Jorge    -  1107266
Mario lora         -  1106278

Fecha de realizacion:  15/1/2023
Fecha de presentacion: 15/1/2023

*/
#include <iostream>
#include <process.h>
#include <string>

using namespace std;

int rX, rY, T1x, T1y, T2x, T2y,RX,RY;
int movType = 1;
char opt = 'Y';
char tablero[9][9];
string validator;

//prototipos
void Movimiento(int, int);
void ImprimirTablero();
void funMov(int, int);
void MovimientosReina();
void limpiarTablero();
int CinValidator(string value);
bool validatorPosition(int Px1, int Py1, int Px2, int Py2);

int main()
{
    do
    {
        cout << "EJERCICIO CLASICO DE UNA REINA Y DOS TORRES\n" << endl;
        bool validation;
        //Diseño del tablero
        tablero[0][1] = '1';
        tablero[0][2] = '2';
        tablero[0][3] = '3';
        tablero[0][4] = '4';
        tablero[0][5] = '5';
        tablero[0][6] = '6';
        tablero[0][7] = '7';
        tablero[0][8] = '8';

        tablero[1][0] = '1';
        tablero[2][0] = '2';
        tablero[3][0] = '3';
        tablero[4][0] = '4';
        tablero[5][0] = '5';
        tablero[6][0] = '6';
        tablero[7][0] = '7';
        tablero[8][0] = '8';

        cout << "Ingrese la fila donde se encuentra la reina: ";
        cin >> validator;
        rX = CinValidator(validator);
        RX = rX;

        cout << "\nIngrese la columna donde se encuentra la reina: ";
        cin >> validator;
        rY = CinValidator(validator);
        RY=rY;
        do
        {
            cout << "\nIngrese la fila donde se encuentra la torre 1: ";
            cin >> validator;
            T1x = CinValidator(validator);
            
            cout << "\nIngrese la columna donde se encuentra la torre 1: ";
            cin >> validator;
            T1y = CinValidator(validator);
        } while (validatorPosition(rX, rY,T1x,T1y));

        do
        {
            cout << "\nIngrese la fila donde se encuentra la torre 2: ";
            cin >> validator;
            T2x = CinValidator(validator);

            cout << "\nIngrese la columna donde se encuentra la torre 2: ";
            cin >> validator;
            T2y = CinValidator(validator);
        } while (validatorPosition(rX, rY, T2x, T2y) || validatorPosition(T1x, T1y, T2x, T2y));
        
        funMov(rX, rY);
        tablero[rX][rY] = 'R'; // Escritura en el tablero de la posición de la reina.
        tablero[T1x][T1y] = 'T'; // Escritura en el tablero de la posición de la torre 1.
        tablero[T2x][T2y] = 'T'; // Escritura en el tablero de la posición de la torre 2.

        ImprimirTablero();
        MovimientosReina();

        // Consulta al usuario para seguir realizando jugadas.
        cout << "\n\n¿Desea jugar nuevamente? (y/n): ";
        cin >> opt;
        system("cls");
        limpiarTablero();
        movType = 1;
    } while (toupper(opt) == 'Y');
}

int CinValidator(string value) //metodo para validar que el usuario coloque solo numeros
{
    for (int i = 0; value[i] != '\0'; i++)
    {
        if (!isdigit(value[i]) || stoi(value) > 8 || stoi(value) < 1)
        {
            cout << "\nValor invalido!!\nSolo se aceptan numero enteros y que sean del 1 al 8\n\nFavor volverlo a colocar y presione enter: ";
            cin >> value;
            i = 0;
        }
    }
    return stoi(value);
}

bool validatorPosition(int Px1, int Py1, int Px2, int Py2)
{
    if (Px1 == Px2 && Py1 == Py2)
    {
        cout << "No puedes tener dos piezas en la misma posicion, presione enter para continuar.";
        system("pause");
        return true;
    }
    return false;
}

// Función de movimiento
void Movimiento(int movX, int movY)
{
    // Si los movimientos exceden los límites del tablero, la función retorna
    if (movX < 1 || movX > 8 || movY < 1 || movY > 8)
        return;
    else if (movX == T1x || movX == T2x)// establecer jugada;
        tablero[movX][movY] = 'X';
    else if (movY == T1y || movY == T2y) // establecer jugada;
        tablero[movX][movY] = 'X';
    else
        tablero[movX][movY] = 'V';
}

// Función que determina el tipo de movimiento que se valida 
void funMov(int x, int y)
{
    if (movType == 1) // El tipo uno, es el movimiento horizontal
    {
        // Bucle para evaluar cada todos los movimientos en dirección horizonal
        for (int i = 1; i < 9; i++)
        {
            Movimiento(x, i);
        }
        movType += 1;
        funMov(x, y);
    }
    else if (movType == 2) // El tipo dos, es el movimiento vertical
    {
        for (int i = 1; i < 9; i++) // Bucle para evaluar cada todos los movimientos en dirección vectical
        {
            Movimiento(i, y);
        }
        movType += 1;
        funMov(x, y);
    }
    else if (movType == 3) // El tipo tres, es el movimiento diagnal, concerniente a la diagonal principal
    {
        for (int i = 1; i < 9; i++) // Bucle para evaluar cada todos los movimientos en dirección de la diagonal principal
        {
            if (i < x)
                Movimiento(x - i, y - i);
            if (i < 9)
                Movimiento(x + i, y + i);
        }
        movType += 1;
        funMov(x, y);
    }
    else // El tipo cuatro (de lo contrario), es el movimiento diagonal, concerniente a la diagonal secundaria
    {
        for (int i = 1; i < 9; i++) // Bucle para evaluar cada todos los movimientos en dirección de la diagonal secundaria
        {
            if (i < x)
                Movimiento(x + i, y - i);
            if (i < 9)
                Movimiento(x - i, y + i);
        }
    }
}

// Función imprimir tablero
void ImprimirTablero()
{
    // Impresión del tablero fila-columna
    for (int i = 0; i < 9; i++)
    {
        if (i == 0)
            cout << "\n___  ___  ___  ___  ___  ___  ___  ___  ___";
        cout << "\n";

        for (int j = 0; j < 9; j++)
        {
            // Si la casilla tiene una ficha, la omite
            if (tablero[i][j] == NULL)
                tablero[i][j] = ' ';
            cout << " " << tablero[i][j] << " | ";
        }
        cout << "\n___  ___  ___  ___  ___  ___  ___  ___  ___";
    }
}

// Funcion para ver los movimientos de la reina
void MovimientosReina()
{
    cout << "\n\nLa reina se puede mover a las posiciones: ";
    // Fors anidados que recorren todas las celdas del tablero
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            // Si la reina se puede mover a la casilla, la concatena a sus posibles soluciones
            if (tablero[i][j] == 'V')
                cout <<"(" <<tablero[0][j]<<", " << tablero[i][0] <<")" << " ";
        }
    }
}
// Función dedicada a limpiar el tablero, en caso de que se desee jugar nuevamente.
void limpiarTablero()
{
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            tablero[i][j] = NULL;
        }
    }
}
