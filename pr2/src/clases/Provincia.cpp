#include "Municipio.hpp"
#include "Provincia.hpp"

void Provincia::load_data(std::string csv_file){
	CSV_reader csv(csv_file);
	CSV_data data=csv.load_csv();
	Provincia provincia;
	Municipio municipio;
	//dumps the data into the class
	for (size_t i = 0; i < data.lines(); i++) {

		Line line=data.get_line(i);

		municipio.set_postal_code	(line.get_field(0));
		municipio.set_name				(line.get_field(1));
		municipio.set_mens				(line.get_field(2));
		municipio.set_womens			(line.get_field(3));


	}
}
