#include <iostream>
#include <string>

#include "Provincia.hpp"
#include "Municipio.hpp"
#include "macros.hpp"

int main(){
	CSV_reader csv("/mnt/data_1/code/c++/ed/pr2/output/Cordoba.csv");

	CSV_data data=csv.load_csv();
	data.print();
	// for (size_t i = 0; i < data.lines(); i++) {
	// 	Line line=data.get_line(i);
	// 	for (size_t j = 0; j < line.fields(); j++) {
	// 		std::cout <<" | "<<line.get_field(j);
	// 	}
	// 	std::cout<< '\n';
	// }
	return 0;
}
