#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "Municipio.hpp"
#include "Provincia.hpp"

int main(int argc, char const *argv[]) {

	ed::ListaDoblementeEnlazadaOrdenadaMunicipios lista;
	ed::Provincia provincia;
	// std::cout<<"lista vacia: "<<(lista.isEmpty()?"true":"false")<<'\n';
	std::string route="/mnt/data_1/code/c++/ed/pr2_profesor/output/Cordoba.csv";
	std::string route2="/mnt/data_1/code/c++/ed/pr2_profesor/output/Cordoba2.csv";

	// ed::Municipio municipio1("a1",1,1,1);
	// ed::Municipio municipio2("b2",2,2,2);
	// ed::Municipio municipio5("f5",5,5,5);
	// ed::Municipio municipio3("c3",3,3,3);
	// ed::Municipio municipio4("d4",4,4,4);
	// ed::Municipio municipio6("g6",6,6,6);

	// lista.insert(municipio2);
	// lista.insert(municipio5);
	// lista.insert(municipio3);
	// lista.insert(municipio4);



	// std::cout<<"encontrado: "<<(lista.find(municipio6)?"true":"false")<<'\n';

	// lista.print();

	// lista.remove(municipio1);


	provincia.cargarFichero(route);
	provincia.grabarFichero(route2);

	provincia.escribirMunicipios();
	std::cout << "hombres: "<< provincia.getTotalHombres() << '\n';

	// lista.removeAll();

	return 0;
}


// std::cout<<"lista vacia: "<<(lista.isEmpty()?"true":"false")<<'\n';
