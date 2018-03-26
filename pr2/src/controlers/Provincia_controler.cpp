#include "Provincia_controler.hpp"

bool way_to_short(const Municipio &a, const Municipio &b){
	std::string a_str=a.get_name();
	std::string b_str=b.get_name();
	return 0>strcmp(a_str.c_str(),b_str.c_str());
}


void Provincia_controler::load_data(std::string csv_file){
	CSV_reader csv(csv_file);
	CSV_line line;
	CSV_data data=csv.load_csv();
	Provincia_base provincia;
	Municipio municipio;
	std::string postal_and_name, name;
	int separator, postal_code;
	//dumps the data into the class
	line=data.get_line(0);
	std::string provincia_data=line.get_field(0);
	separator=provincia_data.find(' ');
	set_code(atoi(provincia_data.substr(0,separator).c_str()));
	set_name(provincia_data.substr(separator+1));
	for (size_t i = 1; i < data.lines(); i++) {

		line=data.get_line(i);

		postal_and_name = line.get_field(0);
		separator=postal_and_name.find(' ');

		postal_code=atoi(postal_and_name.substr(0,separator).c_str());
		municipio.set_postal_code(postal_code);

		municipio.set_name(postal_and_name.substr(separator+1));

		municipio.set_mens(atoi(line.get_field(1).c_str()));
		municipio.set_womens(atoi(line.get_field(2).c_str()));
		if (municipio.get_name()!="") {
			push_municipio(municipio);
		}
	}
	list_actialization();
}

void Provincia_controler::dump_data(std::string csv_file){
	std::list<Municipio>::iterator it_municipios;
	CSV_line line;
	CSV_data data;
	CSV_writer csv(csv_file);
	std::string postal_and_name;
	it_municipios=municipios_.begin();

	line.push_field(std::to_string(get_code())+" "+get_name());
	data.push_line(line);

	for (; it_municipios != municipios_.end(); it_municipios++) {
		line.clear();
		postal_and_name=std::to_string(it_municipios->get_postal_code());
		postal_and_name+=" "+it_municipios->get_name();
		line.push_field(postal_and_name);
		line.push_field(std::to_string(it_municipios->get_mens()));
		line.push_field(std::to_string(it_municipios->get_womens()));
		data.push_line(line);

	}
	csv.dump_csv(data);
}

void Provincia_controler::list_actialization(){
	list_short();
}

void Provincia_controler::list_short(){
	municipios_.sort(way_to_short);
}
