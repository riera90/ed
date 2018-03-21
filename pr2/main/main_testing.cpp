#include <iostream>
#include <string>

#include "Provincia.hpp"
#include "Municipio.hpp"
#include "macros.hpp"

int main(){
	Provincia cordoba;
	cordoba.read_csv("Cordoba.csv");
	CSV_reader csv("/mnt/data_1/code/c++/ed/pr2/output/Cordoba.csv");

	CSV_data data=csv.load_csv();
	std::cout << "lines:" <<data.lines()<< '\n';
	for (size_t i = 0; i < data.lines(); i++) {
		Line line=data.get_line(i);
		for (size_t j = 0; j < line.fields(); j++) {
			std::cout <<" | "<<line.get_field(j);
		}
		std::cout<< '\n';
	}

	// Line line=csv.load_csv_line();
	// while (line.fields()){
	// 	std::cout << "line: ";
	// 	for (size_t i = 0; i < line.fields(); i++) {
	// 		std::cout<<"| "<<line.get_field(i);
	// 	}
	// 	std::cout<<'\n';
	// 	line=csv.load_csv_line();
	// }
	return 0;
}
