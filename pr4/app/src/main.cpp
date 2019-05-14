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
    cout << "  1. Cargar grafo desde fichero\n";
    cout << "  2. Algoritmo de Floyd\n";
    cout << "  0. Salir\n";

    cout << "Introduzca opcion...:";
    cin >> opcion;

    return opcion;
}


int main()
{
   /* Graph<string, int> g2;
    g2.LoadFromFile("Andalucia.txt", "matrizAndalucia.txt");
    g2.print();

    cout<<"index of cordoba: "<<g2.getEdgeIndex("Cordoba")<<"\n";
    //cout << "size of path: " << getPathFromFloyd(g2,"Córdoba", "Sevilla").size()<<"\n";

    return 0;*/



    Graph<string, int> g;
    g.LoadFromFile("Andalucia.txt", "matrizAndalucia.txt");
    int opcion;
    bool grafoIntroducido = true;

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
                {
                    g.print();
                    std::string origin;
                    std::string target;
                    do {
                        cout << "introdizca el origen: ";
                        cin >> origin;
                        cout << "origen introducido: <"<<origin<<">\n";
                        if (!g.contains(origin))
                            cout << "la provincia no existe, introduzcala de nuevo\n";
                    } while (!g.contains(origin));
                    do {
                        cout << "introduzca el destino: ";
                        cin >> target;
                        if (!g.contains(target))
                            cout << "la provincia no existe, introduzcala de nuevo\n";
                    } while (!g.contains(target));

                    cout << "\nmatriz de floyd\n\n";
                    std::vector<std::vector<int>> floyd_matrix = floyd(g);

                    for (auto & row : floyd_matrix) {
                        for (auto & item : row) {
                            cout << item << " ";
                        }
                        cout << endl;
                    }

                    cout << "\nmatriz de floyd_warshall\n\n";
                    std::vector<std::vector<int>> floyd_warshall_matrix = floyd_warshall(g);

                    for (auto & row : floyd_warshall_matrix) {
                        for (auto & item : row) {
                            cout << "\t" << item;
                        }
                        cout << endl;
                    }
                    cout << endl;
                    if (g.existsPath(origin, target, floyd_matrix)) {
                        cout << "camino a seguir\n";
                        std::vector<std::string> path = getPathFromFloyd(g, origin, target);

                        cout << "size:" << path.size() << "\n";
                        cout << endl;
                        for (auto & item : path){
                            cout << item << " <- ";
                        }
                        cout << "start";
                        cout << endl;
                    }
                    else {
                        cout << "no existe camino a seguir\n";
                    }
                }
                else {
                    cout << "Primero tiene que introducir un grafo\n";
                }
                getchar();
                getchar();
                break;
            }
        }
    } while (opcion!=0);

    return 0;
}
