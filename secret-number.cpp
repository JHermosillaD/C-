/* Crear un videojuego que inicialmente genere un número secreto de tipo entero entre 1 y 100. 
En cada turno el usuario introducirá un número y el programa responderá si el número introducido por el usuario es mayor o menor al número secreto. 
Si el usuario es capaz de adivinar el número secreto en 5 turnos, gana la partida. 
En caso contrario, pierde la partida. */

#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
using namespace std;


int main()
{

    cout << "╔═╗┌─┐┌─┐┬─┐┌─┐┌┬┐  ┌┐┌┬ ┬┌┬┐┌┐ ┌─┐┬─┐" << endl;   
    cout << "╚═╗├┤ │  ├┬┘├┤  │   ││││ ││││├┴┐├┤ ├┬┘" << endl;
    cout << "╚═╝└─┘└─┘┴└─└─┘ ┴   ┘└┘└─┘┴ ┴└─┘└─┘┴└─ \n" << endl;

    int n,x;
    srand (time(NULL));
    n = rand()%(100+1);

    for (int i = 1; i <= 5; ++i) { 

        cout << "Intento número " << i << " | Introduce un valor: " << endl;
        cin >> x;

        if (x > n)
        {
            cout << "Ese valor es mayor al numero secreto.\n" << endl;
        }
        else if (x < n)
        {
            cout << "Ese valor es menor al número secreto.\n" << endl;
        }
        else if (x == n)
        {
            cout << "┬ ┬┌─┐┬ ┬  ┬ ┬┬┌┐┌  ┬" << endl;
            cout << "└┬┘│ ││ │  │││││││  │" << endl;
            cout << " ┴ └─┘└─┘  └┴┘┴┘└┘  o" << endl;
            return 0;
        }
    }
    cout << "┌─┐┌─┐┌┬┐┌─┐  ┌─┐┬  ┬┌─┐┬─┐" << endl;
    cout << "│ ┬├─┤│││├┤   │ │└┐┌┘├┤ ├┬┘" << endl;
    cout << "└─┘┴ ┴┴ ┴└─┘  └─┘ └┘ └─┘┴└─  o  o  o\n" << endl;
    cout << "¡La respuesta era " << n << "!" << endl;
    return 0;
}