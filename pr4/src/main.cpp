/*!
 \mainpage Implementación de un montículo de mediciones
 \author   Diego Rodriguez Riera
 \date     26-May-2018
 \version  1.0
*/


/*!
	\file main.cpp
	\brief Programa principal de la practica 4 de Estructuras de Datos
*/


#include <iostream>

#include "DenseGraph.hpp"
#include "FileWrapper.hpp"

int main(int argc, char const *argv[]) {
	DenseGraph g;
	DenseGraph g_temp;
	std::string option;
	std::string filename;
	FileWrapper f("output/vertices.txt");
	while (option!="5"){
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		std::cout << "1) Cargar vertices desde fichero" << '\n';
		std::cout << "2) imprimir grafo" << '\n';
		std::cout << "3) arbol abarcador de coste minimo (Prim)" << '\n';
		std::cout << "4) arbol abarcador de coste minimo (Kruskal)" << '\n';
		std::cout << "5) exit!" << '\n';
		std::cout << "\n\t opcion -> ";
		std::cin >> option;
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		switch (atoi(option.c_str())) {
			case 1:{
				std::cout << "Cargar vertices desde fichero" << '\n';
				std::cout << "introduzca el nombre del fichero > ";
				std::cin >> filename;
				f.setFilename(filename);
				g=f.read();
				std::cout << "cargado correctamente!";
				std::cin.ignore();
				std::cin.ignore();
				break;
			}

			case 2:
				std::cout << "imprimir grafo" << '\n';
				g_temp=f.read();
				g_temp.print();
				std::cin.ignore();
				std::cin.ignore();
				break;

			case 3:
				std::cout << "arbol abarcador de coste minimo (Prim)" << '\n';
				g_temp=f.read();
				if (g_temp.getVertexes().size()>0) {
					g_temp.minTreePrim().printTree();
				}else std::cout << "el grafo esta vacio!" << '\n';
				std::cin.ignore();
				std::cin.ignore();
				break;

			case 4:
				std::cout << "arbol abarcador de coste minimo (Kruskal)" << '\n';
				g_temp=f.read();
				if (g_temp.getVertexes().size()>0) {
					g_temp.minTreeKruskal().printTree();
				}else std::cout << "el grafo esta vacio!" << '\n';
				std::cin.ignore();
				std::cin.ignore();
				break;

			case 5:
				break;


			default:
				std::cout << "introduzca una opcion válida" << '\n';
				std::cin.ignore();
				std::cin.ignore();
		}


	}
	std::cout << "exiting the program!" << '\n';
	return 0;
}
