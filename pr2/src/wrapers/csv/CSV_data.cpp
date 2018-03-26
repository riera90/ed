#include "CSV_data.hpp"

void CSV_data::print() const {
	for (size_t i = 0; i < lines(); i++) {
		CSV_line line=get_line(i);
		for (size_t j = 0; j < line.fields(); j++) {
			std::cout <<" | "<<line.get_field(j);
		}
		std::cout<< '\n';
	}
}
