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
    cout << "  2. camino entre nodos\n";
    cout << "  3. Algoritmo de Floyd\n";
    cout << "  4. Algoritmo de Floyd-Warshall\n";
    cout << "  0. Salir\n";

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
                    cout << "error al cargar el grafo, asegurese de introducir un fichero valido.\n";

                getchar();
                getchar();
                break;
            }

            case 2: //Algoritmo de Floyd
            {
                if ( grafoIntroducido )
                {
                    std::string origin;
                    std::string target;
                    do {
                        cout << "introduzca el origen: ";
                        cin >> origin;
                        cout << "origen introducido: <"<<origin<<">\n";
                        if (!g.contains(origin)) {
                            cout << "la provincia no existe, introduzcala de nuevo\n";
                            cout << "posibles provincias:\n";
                            for (auto &privince : g.getNodes())
                                cout << privince << ", ";
                            cout << "\n";
                        }
                    } while (!g.contains(origin));
                    do {
                        cout << "introduzca el destino: ";
                        cin >> target;
                        cout << "destino introducido: <"<<target<<">\n";
                        if (!g.contains(target)) {
                            cout << "la provincia no existe, introduzcala de nuevo\n";
                            cout << "posibles provincias:\n";
                            for (auto &privince : g.getNodes())
                                cout << privince << ", ";
                            cout << "\n";
                        }
                    } while (!g.contains(target));


                    if (g.existsPath(origin, target, floyd(g))) {
                        cout << "camino a seguir\n";
                        std::vector<std::string> path = getPathFromFloyd(g, origin, target);
                        cout << endl;
                        cout << "finish" << " <- ";
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


            case 3:{
                if (!grafoIntroducido){
                    cout << "primero ha de introducir un grafo\n";
                    getchar();
                    getchar();
                    break;
                }

                cout << "\nmatriz de floyd\n\n";
                std::vector<std::vector<int>> floyd_matrix = floyd(g);
                int i = 0;
                for (auto & row : floyd_matrix) {
                    for (auto & item : row) {
                        cout << "\t" << item;
                    }
                    cout << "\t" << g.getNodes()[i];
                    i++;
                    cout << endl;
                }

                getchar();
                getchar();
                break;
            }

            case 4:{
                if (!grafoIntroducido){
                    cout << "primero ha de introducir un grafo\n";
                    getchar();
                    getchar();
                    break;
                }

                cout << "\nmatriz de floyd_warshall\n\n";
                std::vector<std::vector<int>> floyd_warshall_matrix = floyd_warshall(g);
                int i = 0;
                for (auto & row : floyd_warshall_matrix) {
                    for (auto & item : row) {
                        cout << "\t";
                        if ( item != -1 )
                            cout << " ";
                        cout << item;
                    }
                    cout << "\t" << g.getNodes()[i];
                    i++;
                    cout << endl;
                }
                cout << endl;

                getchar();
                getchar();
                break;
            }
        }
    } while (opcion!=0);

    return 0;
}
