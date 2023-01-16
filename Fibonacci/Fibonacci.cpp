/*
Realizar un programa C++ que realice la secuencia de Fibonacci.

PARTICIPANTES:
Francisco Taveras  -  1107975
Gregorio Estevez   -  1106269
Guillermo Jorge    -  1107266
Mario lora         -  1106278

Fecha de realizacion:  15/12/2022
Fecha de presentacion: 19/12/2022

*/

#include <iostream>

using namespace std;

int main()
{
	int fibo[3] = {0,1,0};
	
	for (int i = 0; i < 50; i++)
	{
		cout <<fibo[0] << " ";
		fibo[2] = fibo[1];
		fibo[1] += fibo[0];
		fibo[0] = fibo[2];
	}
}
