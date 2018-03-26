#include "Provincia_controler.hpp"

bool way_to_short(const Municipio &a, const Municipio &b){
	std::string a_str=a.get_name();
	std::string b_str=b.get_name();
	return 0>strcmp(a_str.c_str(),b_str.c_str());
}


void Provincia_controler::load_data(std::string csv_file){
	CSV_reader csv(csv_file);
	CSV_data data=csv.load_csv();
	Provincia_base provincia;
	Municipio municipio;
	//dumps the data into the class
	for (size_t i = 0; i < data.lines(); i++) {

		Line line=data.get_line(i);

		municipio.set_postal_code(atoi(line.get_field(0).c_str()));
		municipio.set_name(line.get_field(1));
		municipio.set_mens(atoi(line.get_field(2).c_str()));
		municipio.set_womens(atoi(line.get_field(3).c_str()));
		if (municipio.get_name()!="") {
			push_municipio(municipio);
		}
	}
	list_actialization();
}

void Provincia_controler::dump_data(std::string csv_file){

}

void Provincia_controler::list_actialization(){
	list_short();
}

void Provincia_controler::list_short(){
	municipios_.sort(way_to_short);
}
