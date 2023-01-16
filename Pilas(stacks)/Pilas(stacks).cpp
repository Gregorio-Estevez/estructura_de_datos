/*
 Construir un programa C++ para gestionar una Pila.

Pilas(stacks).cpp

PARTICIPANTES:
Francisco Taveras  -  1107975
Gregorio Estevez   -  1106269
Guillermo Jorge    -  1107266
Mario lora         -  1106278
Reinaldo Cabrera   -  1085502

Fecha de realizacion:  20/11/2022
Fecha de presentacion: 21/11/2022(5)
*/

#include <iostream>
#include <cmath>
#include <process.h>

using namespace std;

struct Nodo {//structura para declaracion de funciones para el uso de los metodos
    int dato;
    Nodo* siguiente;
};
void agregar(Nodo*&, int);//prototipo para metodo agregar
void sacar(Nodo*&, int&);//prototipo para metodo sacar
void ver(Nodo*&, int&);//prototipo para metodo ver

int validatorCin(int n) //metodo para validar que el usuario coloque solo numeros
{
    while (cin.fail()) //bucle que verifica si una de las condiciones son verdaderas
    {
        cin.clear(); //el .clear() limpia lo almacenado dentro de cin (la entrada realizada)
        cin.ignore(); //hace que la entrada anterios sea obviada
        system("cls");//clear
        cout << "valor invalido. vuelvalo a insertar (recuerde presionar enter despues de insertar la opcion): ";
        cin >> n;
    }
    system("cls"); //es un comando que se le hace directamente a la terminal de la maquina, cls limpia la terminal. (process.h)
    return n;
}
void agregar(Nodo*& pila, int n) {
    Nodo* nuevon = new Nodo(); //Nuevo nodo
    nuevon->dato = n; // nuevo nodo le da acceso a los datos
    nuevon->siguiente = pila;// nuevo nodo le da acceso al siguiente dato
    pila = nuevon;//se aplica el nuevo nodo
    cout << "\nElemento " << n << " agregado a la pila correctamente\n" << endl;
}
void sacar(Nodo*& pila, int& n) {
    Nodo* aux = pila;//ingreso del termino auxiliar en la pila
    n = aux->dato;//auxiliar le da acceso al dato ingresado
    pila = aux->siguiente;//auxiliar pasa al posicionamiento del siguiente nodo
    delete aux;//se elimina el anterior nodo ingresado
   /* cout << "\nElemento " << n << " salio de la pila correctamente\n" << endl;*/
}
void ver(Nodo*& pila, int& n) {//metodo ver
    Nodo* aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    cout << n << endl;
}
void menu() {//menu
    cout << "Estas en el codigo de pilas, que funcion desea realizas:\n1. agregar\n2. eliminar\n3. ver pila\n4. como funciona?\n5. salir\n\n";
    cout << "coloque el numero de la opcion y presione enter: ";
}

int main()
{
    int opcion;
    char respuesta;
    Nodo* pila = NULL;//declaracion de la pila vacia
    int dato;
    bool sentinent = true;//centinela activo
    while (sentinent)//Mantiene el stack activo
    {
        system("cls");//clear
        menu();//despliegue de menu
        cin >> opcion;
        switch (validatorCin(opcion))//metodo para validar que el usuario coloque solo numeros
        {
        case 1:
            system("cls");//clear
            do {
                system("cls");
                cout << "Digite un numero(luego de colocar el numero presione enter): ";
                cin >> dato;//ingreso de dato
                agregar(pila, validatorCin(dato));//metodo agregar el dato ingresado (Problema)

                cout << "\nDesea agregar otro numero a la pila(coloque 's' para agregar otro numero y";
                cout << "presione enter, de lo contrario coloque cualquier otra cosa y presione enter): ";
                cin >> respuesta;//ingreso de dato

            } while ((respuesta == 's') || (respuesta == 'S'));//punto de respuesta para el bucle
            system("cls");//clear

            break;

        case 2:
            system("cls");
            if (pila == NULL) {//Si la pila esta vacia que de el mensaje
                cout << "Empty Stack" << endl;
                system("pause");//Readline
            }
            else {
                cout << "Sacando los elementos de la pila: ";
                do
                {
                    sacar(pila, dato);//metodo sacar dato
                    if (pila != NULL) {//se elimina un dato de la pila
                        system("cls");//clear
                        cout << "El numero " << dato << " fue descartado correctamente\n";
                    }
                    else {//si es el ultimo dato de la pila
                        system("cls");//clear
                        cout << "El numero " << dato << " fue el ultimo numero a descartar de la pila\n";
                        system("pause");//readline
                        break;
                    }
                    cout << "\nDesea sacar otro nodo a la pila(s/n): ";
                    cin >> respuesta;
                } while ((respuesta == 's') || (respuesta == 'S'));//punto de respuesta para el bucle
            }
            system("cls");
            break;
        case 3:
            system("cls");
            if (pila == NULL) {//si la pila esta vacia da el mensaje
                cout << "Empty Stack\n";
            }
            else if (pila) {//si la pila almacena datos da el mensaje
                cout << "Todos los datos de la pila son (orden del ultimo al primero): " << endl;
                while (pila != NULL) {//muestra los datos de la pila hasta el ultimo ingresado

                    ver(pila, dato);//metodo ver
                }
            }
            system("pause");//readkey
            system("cls");//clear
            break;
        case 4:
            system("cls");//clear
            cout << "El tema de este trabajo es Pilas\nComo funciona?\nPilas funciona como una pila de platos\nQue si sacas el primero plato ingresado\nLos demas se cairan\nPor ello debe ser del ultimo al primero la eliminacion\n" << endl;
            cout << "\nPresione cualquier tecla para volver al menu.";
            system("pause");//readkey
            system("cls");//clear
            break;
        case 5:
            system("cls");//clear
            cout << "Nos vemos (Presione cualquier tecla para salir)";
            system("pause");//readkey
            sentinent = false;
            break;
        default:
            system("cls");//clear
            cout << "Coloco una opcion no contemplada, presione cualquier tecla para volver al menu.";
            system("pause");//readkey
            break;
        }
    }return 0;
}