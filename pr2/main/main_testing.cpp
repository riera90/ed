#include <iostream>
#include <string>

#include "Provincia.hpp"
#include "Municipio.hpp"
#include "macros.hpp"

int main(){
	CSV_reader csv("/mnt/data_1/code/c++/ed/pr2/output/Cordoba.csv");

	// CSV_data data=csv.load_csv();
	// data.print();
	Provincia cordoba;
	cordoba.load_data();


	return 0;
}
