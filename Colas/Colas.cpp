// Colas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Queue
{
    int Dato;
    int Priority;
    Queue* Next;
};

int ValidatorCin(int n)
{
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        system("cls");
        cout << "valor invalido, favor vuelvalo a colocar(despues de colocar el valor presione enter): ";
        cin >> n;
    }
    system("cls");
    return n;
}

bool EmptyQueue(Queue* front)
{
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void InsertQueue(Queue *&front, Queue *&end, int data, int prior)
{
    Queue* New_queue = new Queue();
    Queue* aux = new Queue();

    New_queue->Dato = data;
    New_queue->Next = NULL;
    New_queue->Priority = prior;
    aux = front;

    if (EmptyQueue(front))
    {
        front = New_queue;
    }
    else
    {
        while (prior != front->Priority)
        {

        }
        end->Next = New_queue;
    }
    end = New_queue;
}

void DeleteQueue(Queue *&front, Queue *&end, int &data, int prior)
{
    if (EmptyQueue(front))
    {
        cout << "No hay valores en la fila. ";
        cout << "Presione enter para continuar.\n\n";
        system("pause");
    }
    else
    {
        data = front->Dato;
        prior = front->Priority;
        Queue* aux = front;

        if (front == end)
        {
            front = NULL;
            end = NULL;
        }
        else
        {
            front = front->Next;
        }
        delete aux;
    }
}

void PrintQueue(Queue* Node) 
{
    if (EmptyQueue(Node))
    {
        cout << "No hay valores en la fila. Presione enter para continuar\n\n";
        system("pause");
    }
    else
    {
        while (Node != NULL)
        {
            cout << "Elemento: "<<Node->Dato<< "\n";
            Node = Node->Next;
        }
        cout << "Presione enter para continuar.";
        system("pause");
    }
}

int main()
{
    int value;
    int prior;
    int option;
    bool sentinent = true;
    string continuer;
    Queue* front =NULL;
    Queue* end = NULL;
    
    while (sentinent)
    {
        system("cls");
        cout << "                                       ================================================\n";
        cout << "                                       ==              [1] Insertar en cola          ==\n";
        cout << "                                       ==              [2] Quitar de la cola         ==\n";
        cout << "                                       ==              [3] Ver Cola                  ==\n";
        cout << "                                       ==              [4] Salir                     ==\n";
        cout << "                                       ================================================\n";

        cout << "\nDigite su opcion y luego presione enter: ";
        cin >> option;
        switch (ValidatorCin(option))
        {
        case 1:
            do
            {
                system("cls");
                cout << "Coloque el valor de su elemento(despues de colocarlo presione enter): ";
                cin >> value;
                value = ValidatorCin(value);

                cout << "\nColoque el valor de prioridad(despues de colocarlo presione enter): ";
                cin >> prior;
                prior = ValidatorCin(prior);

                InsertQueue(front, end, value, prior);

                cout << "\n\nValor ingresado correctamente.";
                cout << "\nSi desea ingresar otro elemento coloque [s] o [S] y presione enter.";
                cout << "\nEn caso contrario coloque cualquier valor  y presione enter.";
                cout << "\n\nSu opcion sera: ";
                cin >> continuer;

            } while (continuer == "s" || continuer == "S");
            break;

        case 2: 
            system("cls");
            if (EmptyQueue(front))
            {
               
                cout << "La lista esta vacia. Presione enter para continuar.";
                system("pause");
            }
            else
            {
                DeleteQueue(front, end, value);
                cout << "Valor borrado con exito de la cola. Presione enter para continuar";
                system("pause");
            }
            break;

        case 3:
            PrintQueue(front);
            break;
        case 4:
            system("cls");
            cout << "Nos vemos. presione enter para continuar\n\n";
            system("pause");
            sentinent = false;
            break;
        default:
            system("cls");
            cout << "Coloco una opcion no contemplada. presione enter para continuar\n\n";
            system("pause");
            break;
        }
    }

}

