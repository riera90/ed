#include <iostream>
#include <string>

#include "Provincia.hpp"
#include "CSV_reader.hpp"
#include "CSV_writer.hpp"


int main(){
	std::cout << "main for testing" << '\n';
	CSV_reader rcsv("output/Cordoba.csv");
	CSV_writer wcsv("output/Cordoba_2.csv");
	CSV_data data;
	data=rcsv.load_csv();
	wcsv.dump_csv(data);



	return 0;
}
