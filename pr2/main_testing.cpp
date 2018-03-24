#include <iostream>
#include <string>

#include "Provincia_handler.hpp"
#include "Municipio.hpp"
#include "macros.hpp"
#include "paths.hpp"

int main(){
	Provincia_handler cordoba;
	cordoba.load_data(csv_file_path);



	return 0;
}
