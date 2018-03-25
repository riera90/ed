#include "Provincia_handler.hpp"

bool Provincia_handler::exists(std::string municipio){
	std::list<Municipio>::iterator it_temp_municipios;
	it_temp_municipios=municipios_.begin();
	for (size_t i = 0; i < n_municipios(); i++) {
		if (municipio==it_temp_municipios->get_name())return true;
		it_temp_municipios++;
	}
	return false;
}

std::list<Municipio>::iterator Provincia_handler::locate(Municipio municipio){
	std::list<Municipio>::iterator it_temp_municipios;
	it_temp_municipios=municipios_.begin();
	for (size_t i = 0; i < n_municipios(); i++) {
		if (municipio==it_temp_municipios->get_name()){
			return it_temp_municipios;
		}
		it_temp_municipios++;
	}
	return municipios_.end();
}
