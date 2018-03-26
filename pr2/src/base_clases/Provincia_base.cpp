#include "Provincia_base.hpp"

int Provincia_base::get_total_mens(){
	std::list<Municipio>::iterator it_temp_municipios;
	it_temp_municipios=municipios_.begin();
	int total_mens=0;
	for (size_t i = 0; i < n_municipios(); i++) {
		total_mens+=it_temp_municipios->get_mens();
		it_temp_municipios++;
	}
	return total_mens;
}


int Provincia_base::get_total_womens(){
	std::list<Municipio>::iterator it_temp_municipios;
	it_temp_municipios=municipios_.begin();
	int total_womens=0;
	for (size_t i = 0; i < n_municipios(); i++) {
		total_womens+=it_temp_municipios->get_womens();
		it_temp_municipios++;
	}
	return total_womens;
}
