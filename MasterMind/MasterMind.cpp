/*
REALIZAR UN MASTERMIND PARA PRINCIPIANTES EN C++

MasterMind.cpp

PARTICIPANTES:
Francisco Taveras  -  1107975
Gregorio Estevez   -  1106269
Guillermo Jorge    -  1107266
Mario lora         -  1106278
Reinaldo Cabrera   -  1085502

Fecha de realizacion:  12/11/2022
Fecha de presentacion: 21/11/2022 (10)
*/

#include <iostream>
#include <stdlib.h> // libreria para acceder a la sintaxis rand()
#include <time.h> //Libreria para controlar tiempo de ejecucion 
#include <process.h> //Libreria para tener comandos para la terminal

using namespace std;

int validatorCin(int n) //metodo para validar que el usuario coloque solo numeros y que los numeros no sean mayor que 6 ni menor que 1
{
    while (cin.fail() || n > 6 || n < 1) //bucle que verifica si una de las condiciones son verdaderas
    {
        cin.clear(); //el .clear() limpia lo almacenado dentro de cin (la entrada realizada)
        cin.ignore(); //hace que la entrada anterios sea obviada
        system("cls");
        cout << "valor invalido. vuelvalo a insertar (recuerde presionar enter despues de insertar la opcion): ";
        cin >> n;
    }
    system("cls"); //es un comando que se le hace directamente a la terminal de la maquina, cls limpia la terminal. (process.h)
    return n;
}

void loadcode(int code[])//metodo para cargar el codigo secreto
{
    for (int i = 0;i < 4; i++)
    {
        cout << code[i];
    }
}

bool checkerNumber(int select, int code[])//metodo para validad que no se repitan los numeros en el codigo secreto
{
    for (int i = 0; i < 4; i++)
    {
        if (select == code[i])
        {
            return true;// retornara verdadero si el numero se repite en x posicion
        }
    }
    return false; // retornara falso si el numero no se repite en x posicion
}

bool checkAnswer(int Ucode[], int code[]) //metodo para valorizar la respuesta del jugador y su estado
{
    string hints[4]; //creo un array de cadena para guardar la valorizacion (C,F o X)
    for (int i = 0; i < 4; i++)// for que movera la posicion de la respuesta del usuario
    {
        hints[i] = "X";
        for (int j = 0; j < 4; j++)// for que movera el la posicion del codigo secreto
        {
            if (Ucode[i] == code[j])
            {
                if (i == j) // esto es una confirmacion de si estan frente a frente
                {
                    hints[i] = "C";
                }
                else
                {
                    hints[i] = "F";
                }
            }
        }
        cout << Ucode[i] << " -> " << hints[i]<<"\n";// mostrara la respuesta valorizada
    }

    cout << "\nPresione cualquier tecla para continuar.";
    system("pause");//pause es un comando que detiene la terminal hasta que una señal sea enviada
    system("cls");

    for (int i = 0; i < sizeof(hints)/sizeof(string); i++) // for que funcionara a forma de confirmar si el usuario gano
    {
        if (hints[i] != "C") // si en algunas de las pistas hay letra diferente a la c quiere decir que aun hay un numero que no se a encontrado
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int secretCode[4]; //array entero que guardara el codigo secreto
    int valueCode; // variable entera que asignara el valor al array del codigo secreto
    int playerCode[4]; //array entero que guardara la respuesta del usuario
    int option; //variable entera que tomara la opcion por entrada del usuario
    int attemps; // variable entera que guarda el numero de intentos
    srand(time(NULL)); //srand almacena la semilla de ramdomizado de rand(), entonces a esta se le asigna un tiempo por time() el cual actualizara cada 0 segundos o null
    bool sentinent = true; // variable booleana para mantener el menu del juego activo
    bool endgame = true; // variable booleana para mantener el juego activo

    while (sentinent) //bucle que mantiene el juego activo con su menu
    {
        endgame = true;
        int attemps = 0;
        system("cls");
        cout << "Bienvenido a Mastermind. presione la opcion que desea y luego enter.";
        cout << "\n\n------------------------------------------------------------------";
        cout << "\n\n                     [1] Jugar";
        cout << "\n                     [2] Reglas";
        cout << "\n                     [3] Salir";
        cout << "\n\n------------------------------------------------------------------";
        cout << "\n\nSu opcion es: ";
        
        cin >> option;
      
        switch (validatorCin(option)) //tablero de opciones del jugador 
        {
        case 1:// caso 1, jugar
            for (int i = 0; i < 4; i++) //for para asignar los valores a codigo secreto
            {
                do
                {
                  valueCode = (rand() % 6 + 1);
                } while (checkerNumber(valueCode, secretCode)); // do while donde con el valor asignado a valueCode se hace una verificacion con el metodo de que el numero no se este repitiendo.

                secretCode[i] = valueCode;// saliendo del bucle do while el codigo secreto en la posicion indicada obtendra el valor de valueCode.

               cout << secretCode[i]; //vericador del codigo secreto(trampa ñaca ñaca)
               cout<<"\n"; //vericador del codigo secreto(trampa ñaca ñaca)
            }
            cout << "Su codigo fue generado, puede comenzar.(presione cualquier tecla para continuar.)\n\n\n";
            system("pause");
            system("cls");
            do
            {
                for (int i = 0; i < sizeof(secretCode)/sizeof(int); i++) //for para ingresar la respuesta en del usuario por digitos
                {
                    cout << "intento #" << attemps;
                    cout << "\nIngrese el digito #"<<i+1<<"(al colocar el digito presione enter.)"<< " ";
                    cin >> playerCode[i];
                    playerCode[i] = validatorCin(playerCode[i]); // esta doble "asignacion funciona para confirmar que el valor ingresado sea uno valido"
                }

                if (checkAnswer(playerCode, secretCode)) //aqui se verefica si su respuesta son valida
                {
                    cout << "                       YOU WIN :))))))))\n\n";
                    cout << "lo lograste en "<<attemps<<" intentos, por lo tanto su puntuacion sera: "<< 10-attemps<<"  (presione cualquier tecla para continuar.)\n";
                    system("pause");
                    endgame = false;
                }
                else
                {
                    attemps++;
                }
                if (attemps > 10)
                {
                    cout << "                       YOU LOSE :/\n\n";
                    cout << "Lo sentimos. no lograste resolver el codigo secreto.  (presione cualquier tecla para continuar.)"<<"\n";
                    cout << "codigo secreto: ", loadcode(secretCode),  "\n\n";
                    system("pause");
                    endgame = false;
                }
            } while (endgame);    
            break;

         case 2:
            system("cls");
            cout << "Mastermind consiste en que adivinara un codigo secreto con 4 digitos de forma aleatoria y";
            cout << "\ntu deberas adivinarlo colocando los numeros correctos en el orden correcto.";
            cout << "\n\nUnos destalles extras son:";
            cout << "\n- Este Mastermind esta en dificultad 'facil' por lo tanto el codigo secreto no tiene numeros repetidos.";
            cout << "\n- Se le colocan pistas adecuadas a cada numero colocado con la siguiente simbologia: X, C y F.";
            cout << "\n- X significa que el numero no se encuentra en el codigo secreto.";
            cout << "\n- C significa que el numero existe y esta en la posicion correcta, basicamente es el numero correcto.";
            cout << "\n- F significa que el numero se encuentra en el codigo secreto, pero no esta en la posicion correcta.";
            cout << "\n- El codigo secreto estara formado por numeros del 1 al 6.";
            cout << "\n- Tendra un limite de 10 intentos.";
            cout << "\n- Para colocar su codigo lo escribira digito por digito.";
            cout << "\n- Su puntaje sera calculado en base al numero de intentos restantes.";
            cout << "\n\nPor ultimo y no menos importante divierte :^)";
            cout << "\n\nPresione cualquier tecla para volver al menu principal.";
            system("pause");
            break;

        case 3:
            sentinent = false; // al ser falso, se terminara menu con el juego.
            system("cls");
            cout << "Nos vemos. (presione cualquier tecla para salir)";
            system("pause");
            break;

        default: //opcion no contemplada
            system("cls");
            cout << "valor invalido. (presione cualquier tecla para continuar)";
            system("pause");
            break;
        }
    }
        return 0;
}