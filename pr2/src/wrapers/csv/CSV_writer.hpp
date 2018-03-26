#ifndef _CSV_WRITER_HPP_
#define _CSV_WRITER_HPP_

#include "CSV_data.hpp"

class CSV_writer{
	private:
		std::ofstream file_;
		std::string route;
	public:
		CSV_writer(std::string _route){
			route=_route;
		}
	public:
		void dump_csv(CSV_data data){//dumps all the data into the cvs file
			file_.open(route);
 			if (!file_.is_open()) {
 				std::cout << "ERROR!! Could not open the file!" << '\n';
 				exit(1);
 			}
			CSV_line line;
			for (size_t index_line = 0; index_line < data.lines(); index_line++) {
				line=data.get_line(index_line);
				file_<<line.get_field(0).c_str();
				for (size_t index_field = 1; index_field < line.fields(); index_field++) {
					file_<<SEPARATOR<<line.get_field(index_field).c_str();
				}
				file_<<'\n';
			}
			file_.flush();
			file_.close();
		}
};

#endif
