#include <iostream>
#include <string>
#include <vector>
#include <ed/Entity/Graph.hpp>
#include <ed/Algorithm/algo.hpp>

using namespace std;


int menu()
{
    int opcion;

    system("clear");
    cout << "  0. Salir................................\n";
    cout << "  1. Cargar grafo desde fichero...........\n";
    cout << "  2. Algoritmo de Floyd (GD y GND)......\n";

    cout << "Introduzca opcion...:";
    cin >> opcion;

    return opcion;
}


int main()
{
    Graph<string, int> g;
    int opcion;
    bool grafoIntroducido = false;

    do {
        opcion = menu();
        switch (opcion) {
            case 1: { // Cargar grafo desde fichero
                if (grafoIntroducido)
                    g.clear(); // Si hay un grafo introducido se borra.
                std::string edges, nodes;
                std::cout << "enter the nodes file: ";
                std::cin >> nodes;
                std::cout << "enter the edges file: ";
                std::cin >> edges;

                nodes = "Andalucia.txt";edges = "matrizAndalucia.txt";

                grafoIntroducido = g.LoadFromFile(nodes, edges);

                if (grafoIntroducido) {
                    cout << "Grafo cargado correctamente \n";
                    //Prueba de la asignación y del destructor
                    {
                        Graph<string, int> g1 = g;
                    }
                } else
                    cout << "Grafo no cargado \n";

                getchar();
                getchar();
                break;
            }

            case 2: //Algoritmo de Floyd
            {
                if ( grafoIntroducido )
                    floyd(g);
                else
                    cout << "Primero tiene que introducir un grafo\n";
                getchar();
                getchar();
                break;
            }
        }
    } while (opcion!=0);

    return 0;
}
