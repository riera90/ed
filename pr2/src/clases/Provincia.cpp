#include "Provincia.hpp"

void Provincia::print_all_names(){
	std::list<Municipio>::iterator it_temp_municipios;
	it_temp_municipios=municipios_.begin();
	for (size_t i = 0; i < n_municipios(); i++) {
		std::cout<<it_temp_municipios->get_name()<<'\n';
		it_temp_municipios++;
	}
}
