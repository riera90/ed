#include "menu_wraper.hpp"

void comprobarProvinciaVacia(Provincia &provincia){
	if (provincia.is_empty()){
		std::cout<<"\n\tla lista esta vacia\n\n";
	}else{
		std::cout<<"\n\tla lista NO esta vacia, contiene "<<provincia.n_municipios()<<" municipios.\n\n";
	}
}

void cargarProvincia(Provincia &provincia){
	provincia.load_data("output/Cordoba.csv");
	provincia.goto_head();
}

void grabarProvincia(Provincia &provincia){
	provincia.dump_data("output/Cordoba_dumped.csv");
}

void consultarDatosDeProvincia(Provincia &provincia){
	std::cout << "nombre: "<<provincia.get_name() << '\n';
	std::cout << "codigo: "<<provincia.get_code() << '\n';
}

void mostrarMunicipiosDeProvincia(Provincia &provincia){
	provincia.print_all_names();
}

void modificarDatosDeProvincia(Provincia &provincia){

}

void borrarTodosLosMunicipiosDeProvincia(Provincia &provincia){
	provincia.clear();
}

void consultarMunicipioDeProvincia(Provincia &provincia){
provincia.get_municipio().write_Municipio();
}

void insertarMunicipioEnProvincia(Provincia &provincia){
	Municipio municipio;
	municipio.read_Municipio();
	provincia.insert(municipio);
}

void borrarMunicipioDeProvincia(Provincia &provincia){
	std::cout << "borrando:" << '\n';
	(provincia.get_municipio()).write_Municipio();
	Municipio municipio=provincia.get_municipio();
	provincia.goto_next();
	provincia.erase(municipio);
}
