#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "Municipio.hpp"

int main(int argc, char const *argv[]) {

	ed::ListaDoblementeEnlazadaOrdenadaMunicipios lista;
	// std::cout<<"lista vacia: "<<(lista.isEmpty()?"true":"false")<<'\n';

	ed::Municipio municipio1("a1",1,1,1);
	ed::Municipio municipio2("b2",2,2,2);
	ed::Municipio municipio5("f5",5,5,5);
	ed::Municipio municipio3("c3",3,3,3);
	ed::Municipio municipio4("d4",4,4,4);
	ed::Municipio municipio6("g6",6,6,6);

	lista.insert(municipio1);
	// lista.insert(municipio2);
	// lista.insert(municipio5);
	// lista.insert(municipio3);
	// lista.insert(municipio4);



	// std::cout<<"encontrado: "<<(lista.find(municipio6)?"true":"false")<<'\n';

	lista.print();

	lista.remove(municipio1);


	// lista.removeAll();

	lista.print();

	return 0;
}


// std::cout<<"lista vacia: "<<(lista.isEmpty()?"true":"false")<<'\n';
