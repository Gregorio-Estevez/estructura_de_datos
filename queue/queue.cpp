/*
Realizar un programa C++ que simule una Cola (Queue).

queue.cpp

PARTICIPANTES:
Francisco Taveras  -  1107975
Gregorio Estevez   -  1106269
Guillermo Jorge    -  1107266
Mario lora         -  1106278

Fecha de realizacion:  29/11/2022
Fecha de presentacion: 4/12/2022 

     5/5

*/
#include <iostream>
#include <stdlib.h>
#include<string.h>

using namespace std;

struct nodo //Estrura para los nodos 
{
    int dato;           // El dato del nodo
    int priori;        // prioridad del nodo
    struct nodo* sgte;  // Puntero que apunta al siguiente nodo en la cola
};

struct cola //Estructura para las cola. Se declaran dos punteros para que uno apunte al principio y otro al final (se puede interpretar como una clase)
{
    nodo* delante;  // Puntero que apunta al principio de la cola
    nodo* atras;    // Puntero que apunta al final de la cola
};

struct nodo* crearNodo(int x, int pr)// Se crea un constructor
{
    struct nodo* nuevoNodo = new(struct nodo); // Se crea un nuevo nodo
    nuevoNodo->dato = x; // Se le asigna un valor
    nuevoNodo->priori = pr; // Se le asigna una prioridad
    return nuevoNodo;
};

int validatorCin(int n) //metodo para validar que el usuario coloque solo numeros y que los numeros no sean mayor que 6 ni menor que 1
{
    while (cin.fail() || n < 0) //bucle que verifica si una de las condiciones son verdaderas
    {
        cin.clear(); //el .clear() limpia lo almacenado dentro de cin (la entrada realizada)
        cin.ignore(); //hace que la entrada anterios sea obviada
        system("cls");//es un comando que se le hace directamente a la terminal de la maquina, cls limpia la terminal. (process.h)
        cout << " Valor invalido! Favor de volverlo a colocar y presione enter: ";
        cin >> n;
    }
    system("cls");
    return n;
}

void enfila(struct cola& q, int valor, int priori) //Metodo para agregar un nodo
{
    struct nodo* aux = crearNodo(valor, priori); // Se declara un puntero tipo nodo auxiliar que apuntara al nodo que creamos

    aux->sgte = NULL; // hacemos que el auxiliar acceda al puntero siguiente y que este sea igual a NULL

    if (q.delante == NULL) // Si el nodo de adelante de la fila esta vacio 
    {
        q.delante = aux;   // enfila el primer elemento
    }
    else
    {
        q.atras->sgte = aux; // Sino que entre por detras de la fila
    }

    q.atras = aux;        // puntero que siempre apunta al ultimo elemento
}

void ordenarPrioridad(struct cola& q) //metodo para ordenar la fila por prioridad
{
    struct nodo* aux1, * aux2; // Se crean dos punteros auxiliares para hacer las comparaciones entre las prioridades
                               // de los elementos de la fila
    int p_aux;  // Es una variable para almacenar la prioridad el nodo que se acaba de enfilar y que va a ser ordenado
    int i_aux;  // Es una variable para almacenar el valor el nodo que se acaba de enfilar y que va a ser ordenado
    aux1 = q.delante; // El primer puntero auxiliar apunta hacia el principio de la fila

    while (aux1->sgte != NULL) // Mientras que el siguiente elemento de la cola no este vacio se repetira el procesos
    { 
        aux2 = aux1->sgte; // El auxiliar 2 va a apuntar al primer auxiliar que accede al puntero siguiente

        while (aux2 != NULL) { // Mientras este puntero no sea Null

            if (aux1->priori > aux2->priori) // Aqui comienza el ordenamiento. Si la prioridad del nodo del auxiliar 1 es mayor la prioridad del 2
            { 
                p_aux = aux1->priori; // Se almacena la prioridad en esta variable

                i_aux = aux1->dato; // Se almacena el dato en esta variable

                aux1->priori = aux2->priori; // Los dos punteros acceden a la misma prioridad

                aux1->dato = aux2->dato; // Los dos punteros acceden al mismo valor 

                aux2->priori = p_aux;  // el auxiliar 2 que accede a la prioridad va a ser igual a la prioridad que teniamos almacenada anteriormente


                aux2->dato = i_aux; // el auxiliar 2 que accede al dato va a ser igual al dato que teniamos almacenado anteriormente
            }
            aux2 = aux2->sgte; // el auxiliar 2 va a la siguiente posicion.
        }
        aux1 = aux1->sgte; // el auxiliar 1 va a la siguiente posicion.
    }
}

void Enqueue(struct cola& q, int i, int pr) //  Se combinan los procesos de insertar un nodo en la fila y ordenarlo
{
    enfila(q, i, pr);                     
    ordenarPrioridad(q);
}

void Dequeue(nodo*& delante, nodo*& atras, int& n) //metodo para eliminar un nodo
{
    n = delante->dato; // Se accede al dato del nodo
    nodo* aux = delante; // Se crea un auxiliar que apunte al frente de la fila

    if (delante == atras) { // Si el delante es igual al de atras, es que hay un solo nodo o no hay ninguno
        delante = NULL; // En cualquier caso se igualan los dos punteros a NULL
        atras = NULL;
    }
    else {
        delante = delante->sgte; // Si hay mas de un nodo, entonces el puntero delante pasa a apuntar al que estaba detras de el
    }
    delete aux;
}

void muestraCola(struct cola q) //Metodo para recorrer la cola
{
    struct nodo* aux;

    aux = q.delante;

    cout << "        Caracter  Prioridad " << endl;
    cout << "        ------------------- " << endl;

    while (aux != NULL) {  // Un while que va imprimiendo los elementos de la fila mientras esta no este vacia

        cout << "\t    " << aux->dato << "   |   " << aux->priori << endl;
        aux = aux->sgte; // Este puntero auxiliar sirve para recorrer la cola
    }
}

void menu() //metodo para cargar el menu
{
    system("cls");
    cout << "                                       =======  Programa de gestion de colas  =========\n\n";
    cout << "                                       ================================================\n";
    cout << "                                       ==              [1] Insertar en cola          ==\n";
    cout << "                                       ==              [2] Quitar de la cola         ==\n";
    cout << "                                       ==              [3] Ver Cola                  ==\n";
    cout << "                                       ==              [4] Salir                     ==\n";
    cout << "                                       ================================================\n";

    cout << "\nDigite su opcion y luego presione enter: ";
}

int main()
{
    struct cola q;

    q.delante = NULL;
    q.atras = NULL;

    bool sentinel = true;
    int i;     // Entero a enfilar
    int pr;      // prioridad del nodo
    int op;      // opcion del menu

    while (sentinel)
    {
        menu();
        cin >> op;
        system("cls");

        switch (validatorCin(op)) 
        {
        case 1:
            cout << "Ingrese numero(Presione enter al colocarla):  ";
            cin >> i;
            i = validatorCin(i);    
            cout << "Ingrese prioridad(Presione enter al colocarla): ";
            cin >> pr;
            pr = validatorCin(pr);

            Enqueue(q, i, pr);

            cout << "\n\n\t\tNumero [" << i << "] en la cola...\n\n";
            break;

        case 2:
            if (q.delante != NULL)
            {
                cout << "El valor [" << q.delante->dato << "] fue sacado de la cola (presione enter para continuar)";
                Dequeue(q.delante, q.atras, i);
            }
            else
            {
                cout << "\n\n\t===============================";
                cout << "\n\t\tEmpty Queue." << endl;
                cout << "\t===============================";
            }
            break;

        case 3:
            if (q.delante != NULL)
            {
                cout << "\n\n MOSTRANDO COLA DE PRIORIDAD\n\n";
                muestraCola(q);   // Se muestra la cola
            }
            else
            {
                cout << "\n\n\tEmpty Queue." << endl;
            }
            while (q.delante != NULL)
            {
                Dequeue(q.delante, q.atras, i); // Se vacea la cola
            }
            break;

        case 4:
            cout << "Saliendo...." << endl;
            sentinel = false;
            break;

        default:
            cout << "Coloco un valor no contemplado, favor presione cualquier tecla para continuar.";
            break;
        }

        cout << endl << endl;
        system("pause");
        system("cls");
    } 
    return 0;
}