#ifndef _CSV_WRITER_HPP_
#define _CSV_WRITER_HPP_

#include "CSV_data.hpp"
/*!
\file CSV_writer.hpp
\brief contains the class CSV_writer
*/
/*!
\class CSV_writer CSV_writer.hpp "CSV_writer.hpp"
\brief writer/dumper of data into a csv file
*/
class CSV_writer{
	private:
		std::ofstream file_;
		std::string route;
	public:
		/*!
		\brief constructor of the class
		\param std::string : route of the file to be dump in
		*/
		CSV_writer(std::string _route){
			route=_route;
		}
	public:
		/*!
		\brief dumper
		\param CSV_data: data to be dumped into the file
		*/
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
