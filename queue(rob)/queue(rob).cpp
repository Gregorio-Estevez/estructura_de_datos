// Este programa realiza una simulación de cómo funciona una estrutura de datos, en este caso la estructura Queue. 
// La cual se conoce como (FIFO) First In First Out, el primer dato en entrar es el primero en salir.

#include <iostream>
#include <stdlib.h> // new
#include <Windows.h> // Para incluir los colores de letra (solo por gusto). 
#include <string> // Para incluir la función getline
#include <cstdlib> // Para incluir el ("pause") y hacer una pausa al programa.

using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); // Esto permite utilizar el SetConsoleTextAttribute, el cual establece los atributos de color de letra.
string z;

struct Nodos // Estructura del nodo, contiene su valor y un puntero al siguiente.
{
    int valor;
    Nodos* siguiente;
};

void Agregar(Nodos*&, Nodos*&, int); // Prototipos
bool vacia(Nodos*);
void menu(Nodos*&, Nodos*&, int&);
void Prioridad(Nodos*&, Nodos*&, int&, int&);

void Agregar(Nodos*& frente, Nodos*& fin, int dato) // Las variables pasan por referencia porque va a ir cambiando y el valor que el usuario introducirá.
{
    char b; // Variable utilizada para preguntar si el usuario desea introducir otro valor antes de volver al menú.
    int prioridad;
    bool validar; // Variable utilizada para validación de entrada. 
    system("cls"); // Borrar consola
    do // Bucle en el cual se le piden valores al usuario y se valida la entrada. Se acaba cuando el usuario diga que no desea introducir más valores.
    {
        try
        {
            validar = true; // La variable será verdadera siempre y cuando el usuario no introduzca un string. 
            cout << "Introduza el valor que desea en la cola: " << endl;
            cin >> dato;
            cout << "Ingrese la prioridad del valor que introdujo: " << endl;
            cin >> prioridad; system("cls");
            Prioridad(frente, fin, prioridad, dato);
            cout << "Desea agregar otro? (s/n)" << endl;
            cin >> b;
            system("cls"); // Borrar consola
            Nodos* nuevonodo = new Nodos(); // Crear espacio para nuevo nodo.
            nuevonodo->valor = dato; // El nuevo nodo lo asignamos al valor que introduce el usuario.
            nuevonodo->siguiente = NULL; // Hacer que el puntero apunte al siguiente.

            if (vacia(frente)) // Si la cola está vacía se iguala frente al nuevo nodo.
            {
                frente = nuevonodo; // A frente se le asigna el nuevo nodo.
            }
            else
            {
                fin->siguiente = nuevonodo; // Si no está vacía se iguala fin al nuevo nodo.
            }
            fin = nuevonodo; // Si la cola está vacía igualmente se debe igualar fin al nuevo nodo.
        }
        catch (ios_base::failure) // Clase que define una excepción, en este caso cuando se introduce un string.
        {
            validar = false;
            SetConsoleTextAttribute(color, 4); // Cambiar color a rojo
            cout << "Este valor no corresponde al tipo" << endl;
            SetConsoleTextAttribute(color, 7); // Devolver color consola a blanco
            system("pause"); // Hacer una pausa al programa.
            system("cls"); // Borrar consola
            cin.clear(); // Para eliminar la letra que introduce el usuario.
            getline(cin, z); // Función que se utiliza para leer un string, la z representa un string.
        }
    } while (validar == false || b == 's' || b == 'S');
    menu(frente, fin, dato);
}

void Eliminar(Nodos*& frente, Nodos*& fin, int& dato)
{
    dato = frente->valor; // Obtener el valor del nodo y que el frente apunte a él.
    Nodos* aux = frente; // Crear variable auxiliar y asignarle el frente
    if (frente == fin)
    {
        frente = NULL;
        fin = NULL;
    }
    else
    {
        frente = frente->siguiente;
    }
    delete aux;

    system("cls"); // Borrar consola.
    SetConsoleTextAttribute(color, 4); // Cambiar color a rojo
    cout << "Nodo " << dato << " eliminado" << endl;
    SetConsoleTextAttribute(color, 7); // Devolver color consola a blanco
    system("pause"); system("cls"); // Pausa del programa y borrar consola.
    menu(frente, fin, dato);
}

void Dequeue(Nodos*& frente, Nodos*& fin, int& dato)
{
    dato = frente->valor; // Obtener el valor del nodo y que el frente apunte a él.
    Nodos* aux = frente; // Crear variable auxiliar y asignarle el frente.
    if (frente == fin) // Si están apuntando al mismo nodo hacer que sean null para poder dejar la aux sola.
    {
        fin = NULL;
        frente = NULL; // Se igualan a NULL para poder dejar la aux sola y así dejarla sola.
    }
    else
    {
        frente = frente->siguiente; // Si hay más de un nodo hacemos que frente pase al siguiente para que quede la aux sola.
    }
    delete aux; // Borrar la variable auxiliar que está apuntando al nodo.
}
void DisplayQueue(Nodos*& frente, Nodos*& fin)
{
    int dato = frente -> valor; // Variable que contiene los valores del usuario.
    bool on = true;
    system("cls"); // Borrar consola
    while (on) // Bucle que imprimirá los valores del usuario.
    {
       // Se llama al método Dequeue para que vaya eliminando los valores luego de que se impriman.
        if (frente->siguiente != NULL)
        {
            cout << dato << ", "; // Los valores se imprimirán con una coma hasta el penúltimo valor.
            frente = frente->siguiente;
            dato = frente->valor;
        }
        else
        { // Cuando solo queda un valor en la cola este se imprime con un punto.
            cout << dato << ".";
            on = false;
        }
    }
    system("pause"); system("cls"); //Pausa del programa y borrar consola.
    menu(frente, fin, dato); // Vuelta al menú.
}

bool vacia(Nodos* frente)
{
    return(frente == NULL) ? true : false; // Método que retorna verdadero si la cola está vacía.
}

void menu(Nodos*& frente, Nodos*& fin, int& dato)
{
    int Menu; // Variable en la cual el usuario elije que opción del menú desea ejecutar.
    bool validar;
    cin.exceptions(istream::failbit); // Si se obtiene una letra donde va un número es un failbit, esto se usa en el catch.

    try
    {
        validar = true;
        cout << "\n\n\n\n\n\n  Simulador de Cola\n\n" << endl;
        SetConsoleTextAttribute(color, 2); cout << " 1.   Enqueue\n" << endl; // el número 2 hace referencia al verde.
        SetConsoleTextAttribute(color, 4); cout << " 2.   Dequeue\n" << endl;// el número 4 hace referencia al rojo.
        SetConsoleTextAttribute(color, 6); cout << " 3.   Display\n" << endl;// el número 6 hace referencia al amarillo.
        SetConsoleTextAttribute(color, 3); cout << " 4.   Salir\n" << endl;// el número 3 hace referencia al azul.
        SetConsoleTextAttribute(color, 7); cout << "\nEscoja que desea ejecutar (1-4): ";
        cin >> Menu;
    }
    catch (ios_base::failure)
    {
        validar = false;
        SetConsoleTextAttribute(color, 4); // Cambiar color a rojo
        cout << "Este valor no corresponde al tipo" << endl;
        SetConsoleTextAttribute(color, 7); // Devolver color consola a blanco
        system("pause"); // Hacer una pausa al programa.
        system("cls"); // Borrar consola
        cin.clear(); // Para eliminar la letra que introduce el usuario.
        getline(cin, z); // Función que se utiliza para leer un string.
    }
    switch (Menu)
    {
    case 1:
        Agregar(frente, fin, dato);
        break;

    case 2:
        if (fin == NULL) // Si la cola está vacía se imprime EmptyStack
        {
            system("cls");
            cout << "Empty Queue" << endl;
            system("pause"); system("cls");
            menu(frente, fin, dato);
        }
        else
        {
            Eliminar(frente, fin, dato);
        }
        break;

    case 3:
        if (fin == NULL) // Si la cola está vacía se imprime EmptyStack
        {
            system("cls");
            cout << "Empty Queue" << endl;
            system("pause");
            system("cls");
            menu(frente, fin, dato);
        }
        else
        {
            DisplayQueue(frente, fin);
        }
        break;

    case 4:
        exit(0); // Salir del programa.

    default: // Si se introduce un valor que no va en el menú se borra la consola y se vuelve al menú.
        system("cls");
        menu(frente, fin, dato);
    }
}

void Prioridad(Nodos*& frente, Nodos*& fin, int& prioridad, int& dato)
{
    int ipc = -1;
    Nodos* Aux = new Nodos();
    Nodos* nuevonodo = new Nodos();

    while (Aux != NULL && prioridad < ipc)
    {
        Aux = Aux->siguiente;
        ipc++;
    }
    if (prioridad == ipc)
    {
        nuevonodo->valor = dato;
        nuevonodo->siguiente = Aux;
        if (prioridad != 0)
        {
            Aux->siguiente = nuevonodo;
        }
    }
}

int main()
{
    int dato; // Variable en la cual se guardarán los valores del usuario.
    Nodos* frente = NULL; // La cola estará vacía hasta que el usuario introduzca valores.
    Nodos* fin = NULL;
    menu(frente, fin, dato); // Ir al menú del programa.
}