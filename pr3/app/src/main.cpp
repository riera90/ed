#include <iostream>
#include <cstdlib> //para usar srand()

#include <ed/Entity/arbolbinarioordenadoenlazado.hpp>
#include <ed/Entity/operadornodo.hpp>
#include <ed/Entity/persona.hpp>
#include <ed/Generator/generarpersona.hpp>

using namespace ed;

int main()
{
    srand(time(0));
    ArbolBinarioOrdenadoEnlazado<Persona> a;
    EscribirNodo<Persona> escritor;
    a.recorridoInOrden(escritor);


    for (int i = 0; i < 30; ++i) {
        std::cout << "\n\ninserting\n";
        a.insertar(generarDatosPersonales());
    }


    std::cout<<"------------------------------\n";

    a.recorridoInOrden(escritor);

}
