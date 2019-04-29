#include <iostream>
#include <cstdlib> //para usar srand()

#include <ed/Entity/arbolbinarioordenadoenlazado.hpp>
#include <ed/Entity/operadornodo.hpp>
#include <ed/Entity/persona.hpp>
#include <ed/Generator/generarpersona.hpp>

using namespace ed;

int main()
{
    ArbolBinarioOrdenadoEnlazado<int> tree;
    srand(time(0));
    EscribirNodo<int> escritor;
    int option = -1;

    while(option != 0){
        std::cout<<"\n\n\n\n";
        std::cout<<"\t1. añadir numero.\n";
        std::cout<<"\t2. mostrar numeros.\n";
        std::cout<<"\t3. Borrar numero.\n";
        std::cout<<"\t4. Borrar el árbol completo.\n";
        std::cout<<"\t0. Salir\n\n";
        std::cout<<"\nElige una opcion: ";

        std::cin>>option;

        switch(option){
            case 1:
            {
                int number;
                std::cout<<"intoduzca el numero: ";
                std::cin>> number;
                tree.insertar(number);
                break;
            }


            case 2:
            {
                int orden;
                if (tree.estaVacio()) {
                    std::cout<<"El árbol está vacío"<<endl;
                    break;
                }
                std::cout<<"\t1. PreOrden\n";
                std::cout<<"\t2. InOrden\n";
                std::cout<<"\t3. PostOrden\n";
                std::cout<<"Elige el orden a mostrar:\n";

                std::cin>>orden;

                switch(orden){
                    case 1: {
                        tree.recorridoPreOrden(escritor);
                        break;
                    }

                    case 2: {
                        tree.recorridoInOrden(escritor);
                        break;
                    }

                    case 3: {
                        tree.recorridoPostOrden(escritor);
                        break;
                    }

                    default: {
                        cout << "Opción errónea." << endl;
                        break;
                    }
                }

                break;
            }

            case 3:{
                int number;
                std::cout<<"Introduca el numero a borrar: ";
                std::cin>>number;
                if (tree.buscar(number)) {
                    if (tree.borrar())
                        cout<<"\n\n"<<number<<" borrado."<<endl;
                }
                else
                    std::cout<<"Error al borrar."<<endl;
                break;
            }


            case 4:{
                std::cout <<"Árbol borrado.\n";
                tree.borrarArbol();
                break;
            }

            case 0:{
                std::cout <<"Adios.\n";
                break;
            }

            default:{
                std::cout<<"Opción incorrecta.\n";
                break;
            }
        }
    }
}