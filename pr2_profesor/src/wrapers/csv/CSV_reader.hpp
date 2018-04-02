#ifndef _CSV_READER_HPP_
#define _CSV_READER_HPP_

#include "CSV_data.hpp"

/*!
\file CSV_reader.hpp
\brief contains the class CSV_reader
*/

/*!
\class CSV_reader CSV_reader.hpp "CSV_reader.hpp"
\brief reader of data of a csv file
*/
class CSV_reader{
	private:
		std::ifstream file_;
		std::string route;
	public:
		/*!
		\brief constructor of the class
		\param std::string : route of the file to be read from
		*/
		CSV_reader(std::string _route){
			route=_route;
		}
	private://load a line of the file
		/*!
		\brief line reader
		\return CSV_line: readed line
		*/
		CSV_line load_csv_line(){
			CSV_line complete_line;
			char temp_line[256];
			std::string line, field;
			file_.getline(temp_line, 256);
			//checks for end of file, if so, returns an empty line meaning the EOF
			if (file_.eof()) {
				CSV_line empty;
				return empty;
			}
			line=temp_line;
			//substract the fiend from the string
			field=line.substr(0,line.find(SEPARATOR));
			//pushes the fiend into the line
			complete_line.push_field(field);
			//checks if thera are none fields to be read
			while (line.find(SEPARATOR)!=std::string::npos) {
				//delete the fiend from the string
				line=line.substr(line.find(SEPARATOR)+1);
				//gets the next field
				field=line.substr(0,line.find(SEPARATOR));
				//pushes the fiend into the line
				complete_line.push_field(field);
			}
			return complete_line;
		}
	public:
		/*!
		\brief file reader
		\return CSV_data: readed data
		internally it calls read_line and pushes all the lines into the CSV_data class
		*/
		CSV_data load_csv(){//loads all the cvs file
			file_.open(route);
 			if (!file_.is_open()) {
 				std::cout << "ERROR!! Could not open the file!" << '\n';
 				exit(1);
 			}
			CSV_data data;
			//gets the first line to launch the loop
			CSV_line line=load_csv_line();
			//checks for empty lines (if is empty it means the endo of file)
			while (line.fields()){
				//pushes the line into the data class (returned class)
				data.push_line(line);
				//gets a new line
				line=load_csv_line();
			}
			file_.close();
			return data;
		}
};

#endif
