/*
Realizar un programa C++ que simule una Listas Enlazadas (Linked List).

LinkedList.cpp

PARTICIPANTES:
Francisco Taveras  -  1107975
Gregorio Estevez   -  1106269
Guillermo Jorge    -  1107266
Mario lora         -  1106278

5/5

Fecha de realizacion:  9/12/2022
Fecha de presentacion: 12/12/2022
*/
#include <iostream>
using namespace std;


struct Nodo 
{
    int dato;
    Nodo* siguiente;
};

int validatorCin(int n) //metodo para validar que el usuario coloque solo numeros y que los numeros no sean mayor que 6 ni menor que 1
{
    string str;
    str = n;
    int i = 0;
    while (str[i] != '\0') //'\0' es el character que marca el final del string
    {
        if (isdigit(str[i]) == false)
        {
            cin.clear();
            cin.ignore();
            cin >> n;
            i = 0;
            str = n;
        }
        i++;
    }
    return n;
}

void menu() //Interfaz del programa 
{
    system("cls");
    cout << "=======     Programa de Linked list    =========\n\n";
    cout << "================================================\n";
    cout << "==              [1] INSERTAR                  ==\n";
    cout << "==              [2] ELIMINAR                  ==\n";
    cout << "==              [3] MOSTRAR                   ==\n";
    cout << "==              [4] BUSCAR                    ==\n";
    cout << "==              [5] SALIR                     ==\n";
    cout << "================================================\n";

    cout << "\nDigite su opcion y luego presione enter: ";
}

bool Vacia(Nodo* lista) //metodo para ver si la lista esta vacia
{
    if (lista == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Insertar(Nodo*& lista, int n) // Funcion para Insertar Nodos a la Lista
{  
    Nodo* nuevo_nodo = new Nodo();  // Se crea espacio en la memoria para un nuevo nodo
    nuevo_nodo->dato = n; // Se accede al dato del nodo recien creado

    Nodo* aux1 = lista; // Se declara un puntero tipo Nodo auxiliar el cual apuntara a otro puntero por referencia
    Nodo* aux2 = NULL; // Se declara otro puntero tipo Nodo auxiliar que se inicializa en NULL

    while ((aux1 != NULL) && (aux1->dato < n)) { // Este while es para organizar los datos de los nodos en forma ascendente.
                                                 // Mientras el primer auxiliar no sea null (es decir mientras no lleguemos al final de la lista, o que este vacia) y el dato de dicho nodo
                                                 // que creamos sea mayor al dato del nodo que ya esta en la lista se ejecutaran las siguientes sentencias.

        aux2 = aux1; // el auxiliar 2 apunta hacia el auxiliar 1 
        aux1 = aux1->siguiente; // Y el 1 va hacia el siguiente nodo. Asi se recorre la lista mientras van organizandose
    }

    if (lista == aux1) //Si se entra a este if, porque el nodo que entramos fue el primero.
    {   
        lista = nuevo_nodo;
    }
    else 
    {
        aux2->siguiente = nuevo_nodo; // de lo contrario habian mas nodos y este nodo se inserta como el siguiente
    }

    nuevo_nodo->siguiente = aux1; // ahora el puntero siguiente apunta al auxiliar 1
}

void Mostrar(Nodo* lista) 
{
    cout << "Datos en Linked List" << endl;
    cout << "--------------------" << endl;

        while (!Vacia(lista)) // Mientras no este vacia se imprimiran los elementos de la lista
        {
            cout << "------\n";
            cout << "| " << lista->dato << " |\n";
            cout << "------\n";
            lista = lista->siguiente; // Cada vez que se imprime un elemento el puntero "actual" apunta al siguiente nodo en la lista
        }
}

void Buscar(Nodo* lista, int n) 
{
    bool encontrado = false;  // Se declara una variable booleana para decir que se encontro el dato o no
    Nodo* actual = new Nodo();
    actual = lista;

    while ((!Vacia(actual)) && (actual->dato <= n))   // Mientras la lista no este vacia y el dato que queremos buscar sea mayor o igual a el dato dentro de la lista
                                                     // se ejecutara lo siguiente
    { 
        if (actual->dato == n) // Si el dato es el que queriamos se devuelve true
        { 
            encontrado = true;
        }
        actual = actual->siguiente; // si no era simplemente se sigue recorriendo la lista hasta encontrarlo
    }
    system("cls");
    if (encontrado == true) 
    {
        cout << "El Elemento [" << n << "] FUE encontrado en la Lista.\n\nPresione cualquier tecla para volver..";

    }
    else 
    {
        cout << "El Elemento [" << n << "] NO se encuentra en la Lista.\n\nPresione cualquier tecla para volver..";
    }
}

void Eliminar(Nodo*& lista, int n) 
{
    system("cls");

    if (!Vacia(lista)) // SI LA LISTA NO ESTA VACIA
    { 
        Nodo* aux_borrar;  // se declara un puntero tipo nodo auxiliar para borrar 
        Nodo* anterior = NULL;
        aux_borrar = lista;  // El puntero para borrar se inicializa al principio de la lista

        while ((aux_borrar != NULL) && (aux_borrar->dato != n))  // Mientras no hayamos llegado al final de la lista y el dato que queremos eliminar se encuentre en la lista
        {
            anterior = aux_borrar;   // el anterior que es NULL va a apuntar al aux_borrar
            aux_borrar = aux_borrar->siguiente; // el auxiliar para borrar accede a siguiente
        }

        if (aux_borrar == NULL) // Si el aux_borrar es nulo entonces es que el elemento no existe en la lista
        { 
            cout << "Este elemento NO existe";
        }
        else if (anterior == NULL)   // En este caso el se recorrio la lista y si el primer elemento de la lista (que fue el unico que no se comparo en el while) es
                                     // es el elemento que estamos buscando
        { 
            lista = lista->siguiente;
            delete aux_borrar; // Se borra el elemento
            cout << "\n\n\t\tNumero eliminado de la lista...\n\n";
        }
        else // Sino es porque el elemento ya se encontro mas adelante en la lista
        {  
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;// Se borra el elemento
            cout << "\n\n\t\tNumero eliminado de la lista...\n\n";
        }
    }
    else // Si nada de esto paso, es que la lista debe estar vacia
    { 
        cout << "LA LISTA ESTA VACIA";
    }
}

int main()
{
    Nodo* lista = NULL;
    int op, dato, busqueda;
    bool sentinel = true;
    do 
    {
        menu();
        cin >> op;
        op = validatorCin(op);
        system("cls");

        switch (op) {

        case 1:
            cout << "Ingrese un numero y presione enter:  ";
            cin >> dato;
            dato = validatorCin(dato);
            Insertar(lista, dato);
            system("cls");
            cout << "Numero [" << dato << "] fue ingresado correctamente\n\nPresione cualquier tecla para volver..";
            break;

        case 2:
            if (Vacia(lista))
            {
                cout << "Lista Vacia\n\nPresione cualquier tecla para volver..";
            }
            else
            {
                cout << "Digite el dato que quiere eliminar y presione enter: ";
                cin >> busqueda;
                busqueda == validatorCin(busqueda);
                Eliminar(lista, busqueda);
            }
            break;

        case 3:
            if (Vacia(lista))
            {
                cout << "Lista Vacia\n\nPresione cualquier tecla para volver..";
            }
            else
            {
                Mostrar(lista);
                cout << "\nPresione cualquier tecla para continuar.";
            }
            break;
        case 4:
            if (Vacia(lista))
            {
                cout << "Lista Vacia\n\nPresione cualquier tecla para volver..";
            }
            else
            {
                cout << "Ingrese el dato que desea revisar y presione enter: ";
                cin >> busqueda;
                busqueda = validatorCin(busqueda);
                Buscar(lista, busqueda);
            }
            break;

        case 5:
            cout << "Saliendo...." << endl;
            sentinel = false;
            break;

        default:
            cout << "Opcion no contemplada. Presione cualquier tecla para continuar.";
            break;
        }

        cout << endl << endl;
        system("pause");
        system("cls");

    } while (sentinel);

    return 0;
}