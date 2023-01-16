#include<iostream>
#include<stdlib.h>

using namespace std;

int seondary() {
	int arreglo[4];

	cout << sizeof(int)<<"\n";
	cout << sizeof(string) << "\n";
	cout << sizeof(arreglo) << "\n";
	cout << sizeof(arreglo) / sizeof(int) << "\n";
	
	return 0;
}