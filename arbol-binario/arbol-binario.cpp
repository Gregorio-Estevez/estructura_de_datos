// Arbol Binario.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include<string>
#include<process.h>

using namespace std;
/*
Realizar un programa C++ que simule un arbol binario de busqueda (ABB).

PARTICIPANTES:
Francisco Taveras  -  1107975
Gregorio Estevez   -  1106269
Guillermo Jorge    -  1107266
Mario lora         -  1106278

Fecha de realizacion:  15/12/2022
Fecha de presentacion: 19/12/2022

*/

// Estructura de nuestro nodo 
struct Nodo {
    int dato;
    Nodo* left;  // Puntero que apunta hacia la rama izquierda
    Nodo* right; // Puntero que apunta hacia la rama derecha
    Nodo* father; // Puntero que apunta hacia el padre de un nodo
};  

// PROTOTIPOS //

Nodo* arbol = NULL;
Nodo* father = NULL;
int CinValidator(string value);
void menu();
Nodo* crearNodo(int n, Nodo* father);
void insertarNodo(Nodo*& arbol, int n, Nodo* father);
void mostrarArbol(Nodo* arbol, int i);
bool buscarNodo(Nodo* arbol, int n);
void preOrden(Nodo* arbol);
void inOrden(Nodo* arbol);
void postOrden(Nodo* arbol);
void eliminarNodo(Nodo* arbol, int n);
Nodo* minimo(Nodo* arbol);
void eliminar(Nodo* Nodoeliminado);
void reemplazar(Nodo* arbol, Nodo* nuevoNodo);
void destruirNodo(Nodo* nodo);
bool vacio(Nodo* arbol);

int main()
{
    string valid;
    int dato;
    int op;
    int op2;
    int i = 0;
    bool sentinel1 = true;
    bool sentinel2 = true;

    do {

        menu();
        cin >> valid;
        op = CinValidator(valid);
        switch (op) {

        case 1:
            cout << "\n\n";
            cout << "   Ingrese numero y luego presione enter: ";
            cin >> valid;
           
            dato = CinValidator(valid);

            insertarNodo(arbol, dato, father);
            system("cls");
            cout << "\n\n";
            cout << "   Numero [" << dato << "] fue ingresado correctamente. Presione cualquier tecla para continuar.";

            break;

        case 2:
            if (vacio(arbol))
            {
                cout << "\nArbol vacio. Presione enter para continuar.\n";
            }
            else
            {
                cout << "\n";
                cout << "    Digite el elemento que quiere eliminar y luego presione enter: ";
                cin >> valid;
                dato = CinValidator(valid);
                eliminarNodo(arbol, dato);
            }
            break;

        case 3:
            if (vacio(arbol))
            {
                cout << "\nArbol vacio. Presione enter para continuar.\n";
            }
            else
            {
                mostrarArbol(arbol, i);
                cout << "\nPresione cualquier tecla para continuar.\n";
            }
            break;

        case 4:
            if (vacio(arbol))
            {
                cout << "\nArbol vacio. Presione enter para continuar.\n";
            }
            else
            {
                cout << "\n\n";
                cout << "   Digite el elemento que quiere buscar y luego presione enter: ";
                cin >> valid;
                dato = CinValidator(valid);
                if (buscarNodo(arbol, dato) == true) {
                    cout << "\n\n";
                    cout << "    El Elemento [" << dato << "] FUE encontrado en el arbol.";
                }
                else {
                    cout << "\n\n";
                    cout << "    El Elemento [" << dato << "] NO se encuentra en el arbol.";
                }
            }
            break;


        case 5:
            system("cls");
            if (vacio(arbol))
            {
                cout << "\nArbol vacio. Presione enter para continuar.\n";
            }
            else
            {
                do {
                    cout << "              ================================================\n";
                    cout << "              ++              [1] PreOrden                  ++\n";
                    cout << "              ++              [2] InOrden                   ++\n";
                    cout << "              ++              [3] PostOrden                 ++\n";
                    cout << "              ++              [4] Volver al menu anterior   ++\n";
                    cout << "              ================================================\n";

                    cout << "\n              Digite su opcion y luego presione ENTER: ";
                    cin >> valid;
                    op2 = CinValidator(valid);;
                    switch (op2) 
                    {
                        system("cls");
                    case 1:
                        cout << "          =============================" << endl;
                        cout << "          ==   Recorrido PreOrden    ==" << endl;
                        cout << "          =============================\n\n";
                        cout << "        ";
                        preOrden(arbol);
                        break;
                    case 2:
                        cout << "          =============================" << endl;
                        cout << "          ==   Recorrido InOrden    ==" << endl;
                        cout << "          =============================\n\n";
                        cout << "        ";
                        inOrden(arbol);
                        break;
                    case 3:
                        cout << "          =============================" << endl;
                        cout << "          ==   Recorrido PostOrden   ==" << endl;
                        cout << "          =============================\n\n";
                        cout << "        ";
                        postOrden(arbol);
                     
                        break;
                    case 4:
                        sentinel2 = false;
                        break;
                    default:
                        break;
                    }
                    cout << "\n\nPresione cualquier tecla para continuar.";
                    system("pause");
                    system("cls");
                } while (sentinel2);
                system("cls");
            }
            break;

        case 6:
            cout << "\nSaliendo...." << endl;//Mensaje de respuesta
            sentinel1 = false;//esperando interacion para salir
            break;

        default:
            cout << "Dato no implementado\n\npresione cualquier tecla para volver";
            break;
        }
        cout << endl << endl;
        system("pause");
        system("cls");

    } while (sentinel1);

    return 0;
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
void menu() {//Interfaz del programa

    cout << "\n\n";
    system("cls");
    cout << "              +++=======       Programa de Arbol   ========+++\n\n";
    cout << "              ================================================\n";
    cout << "              ++              [1] Insertar Nodo             ++\n";
    cout << "              ++              [2] Eliminar Nodo             ++\n";
    cout << "              ++              [3] Mostrar Arbol             ++\n";
    cout << "              ++              [4] Buscar Nodo               ++\n";
    cout << "              ++              [5] Recorrer Arbol            ++\n";
    cout << "              ++              [6] Salir                     ++\n";
    cout << "              ================================================\n";

    cout << "\n              Digite su opcion y luego presione ENTER: ";

}
Nodo* crearNodo(int n, Nodo* father) { // Este es nuestro contructor de nodos
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->right = NULL;
    nuevo_nodo->left = NULL;
    nuevo_nodo->father = father;
    return nuevo_nodo;
}
void insertarNodo(Nodo*& arbol, int n, Nodo* father) {
    if (arbol == NULL) {                              // Si el arbol esta vacio
        Nodo* nuevo_nodo = crearNodo(n, father);      // Se crea un nuevo nodo y este sera la raiz del arbol
        arbol = nuevo_nodo;
    }
    else {                                         // De lo contrario es que ya hay 1 o mas nodos
        int raiz = arbol->dato;                    // Se crea una variable para almacenar el valor de la raiz 
        if (n <= raiz) {                           // Si el nodo tiene un valor menor o igual a su padre, entonces va a la izquierda
            insertarNodo(arbol->left, n, arbol);
        }
        else
        {
            if (n > raiz) {                        // De lo contrario va a la derecha
                insertarNodo(arbol->right, n, arbol);
            }
        }
    }
}
void mostrarArbol(Nodo* arbol, int i) {
    if (arbol == NULL) {                        // Si el arbol esta vacio no se muestra nada

        return;
    }
    else {
        mostrarArbol(arbol->right, i + 1);     // Se ejecuta el metodo dentro de si mismo pero apuntando hacia la derecha
        for (int j = 0; j < i; j++) {          // Este bucle sirve para imprimir los espacios y darle formato de arbol
            cout << "   ";
        }
        cout << arbol->dato << endl;          // Se imprime el nodo
        mostrarArbol(arbol->left, i + 1);      // Se ejecuta el metodo dentro de si mismo pero apuntando hacia la izquierda
    }
}
bool buscarNodo(Nodo* arbol, int n) {
    if (arbol == NULL) {
        return false;  // Si el arbol esta vacio o sino se encuentra el dato se retorna false
    }
    else {
        if (arbol->dato == n) {
            return true;    // Si el dato existe entonces retorna true
        }
        else {
            if (n < arbol->dato) {   // El arbol no esta vacio pero no se ha encontrado el dato por lo tanto se va haciendo comparaciones con 
                                      // los nodos que se van recorriendo
                return buscarNodo(arbol->left, n);
            }
            else {
                return buscarNodo(arbol->right, n);
            }
        }
    }
}
void preOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;           // Si el arbol esta vacio no muestra nada
    }
    else {
        cout << " [" << arbol->dato << "] ->";   // Se comienza por la raiz
        preOrden(arbol->left);                    // Se sigue por la izquierda
        preOrden(arbol->right);                   // y se termina por la derecha
    }
}
void inOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;             // Si el arbol esta vacio no muestra nada
    }
    else {
        inOrden(arbol->left);       // Se inicia por la izquierda
        cout << " [" << arbol->dato << "] ->";   // Se sigue por la raiz
        inOrden(arbol->right);                   // Se termina por la derecha
    }
}
void postOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;            // Si el arbol esta vacio no muestra nada
    }
    else {
        postOrden(arbol->left);         // Se comienza por la izquierda
        postOrden(arbol->right);        // Se sigue por la derecha
        cout << " [" << arbol->dato << "] ->"; // Se termina por la raiz

    }
}
void eliminarNodo(Nodo* arbol, int n) {
    if (arbol == NULL) {  // Si el arbol esta vacio o el elemento no existe, no se elimina nada

        cout << "\n\n\n";
        cout << "           = = = = = = = = = = = = = = = = = " << endl;
        cout << "           =     NO EXISTE EL ELEMENTO!    = " << endl;
        cout << "           = = = = = = = = = = = = = = = = =" << endl;

        cout << "\nPresione cualquier tecla para continuar";
        return;
    }
    else {                               // De lo contrario hay nodos en el arbol
        if (n < arbol->dato) {
            eliminarNodo(arbol->left, n);       //
                                                //
        }                                       //  Esto es un recorrido en busca del nodo que queremos eliminar usando las propiedades de los arboles de busqueda
        else {                                  //
            if (n > arbol->dato) {              //
                eliminarNodo(arbol->right, n);  //
            }
            else {
                if (n == arbol->dato) {
                    eliminar(arbol);            // Ya que se encontro el nodo, se elimina con este metodo
                    cout << "   Numero [" << n << "] fue eliminado correctamente. Presione cualquier tecla para continuar.";
                }

            }
        }
    }
}
Nodo* minimo(Nodo* arbol) {
    if (arbol == NULL) {
        return NULL;
    }
    if (arbol->left) { // Si el arbol tiene parte izquierda, vete a la parte mas izquierda posible
        return minimo(arbol->left);
    }
    else
    {
        return arbol;   // Sino ya no tiene mas parte izquierda dame el nodo que quedo
    }
}
void eliminar(Nodo* Nodoeliminado) {
    if (Nodoeliminado->left && Nodoeliminado->right) { // Si el nodo tiene hijo izquierdo e hijo derecho
        Nodo* menor = minimo(Nodoeliminado->left);    // Se declara un puntero que apunte al minimo pero usando de parametro el nodo a la izquierda. 

        Nodoeliminado->dato = menor->dato;             // Se iguala los dos punteros que acceden al mismo dato
        eliminar(menor);                               // Se sigue ejecutando este metodo hasta que nos quede un nodo con un solo hijo izq o der
    }
    else {
        if (Nodoeliminado->left) {                     // Si es izquierdo, reemplazamelo con el nodo que buscamos anteriormente
            reemplazar(Nodoeliminado, Nodoeliminado->left);
            destruirNodo(Nodoeliminado);               // Ahora que el nodo se quedo solo, se desruye.
        }
        else {
            if (Nodoeliminado->right) {
                reemplazar(Nodoeliminado, Nodoeliminado->right);  // Si es derecho, reemplazamelo con el nodo que buscamos anteriormente
                destruirNodo(Nodoeliminado);
            }
            else {
                reemplazar(Nodoeliminado, NULL);  // Si el nodo a eliminar es una hoja pues no tiene hijos, por lo tanto solo se destruye
                destruirNodo(Nodoeliminado);
            }
        }
    }
}
void  reemplazar(Nodo* arbol, Nodo* nuevoNodo) {  // Metodo para reemplazar el nodo eliminado
    if (arbol->father) {                            // Si el nodo tiene padre, se le asigna al padre su nuevo hijo
        if (arbol->dato == arbol->father->left->dato) { // Si el nodo que queremos eiminar se encuentra en la izquierda
            arbol->father->left = nuevoNodo;    // Aqui se sustituye ese nodo que queremos eliminar por un nuevo nodo
        }
        else {
            if (arbol->dato == arbol->father->right->dato) { // Lo mismo pero para el derecho
                arbol->father->right = nuevoNodo;
            }
        }
    }
    if (nuevoNodo) {  // Aqui se le asigna al hijo su nuevo padre
        nuevoNodo->father = arbol->father;
    }
}
void destruirNodo(Nodo* nodo) { // Este metodo destruye el nodo
    nodo->left = NULL;
    nodo->right = NULL;
    delete nodo;
}
bool vacio(Nodo* arbol)
{
    if (arbol == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}