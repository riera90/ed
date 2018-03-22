#include "Municipio.hpp"
#include "Provincia.hpp"

void Provincia::load_data(std::string csv_file){
	CSV_reader csv(csv_file);
	data_=csv.load_csv();
	data_.print();
}
