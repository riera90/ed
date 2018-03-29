#ifndef _CSV_DATA_HPP_
#define _CSV_DATA_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#define SEPARATOR ';'

/*!
\file CSV_data.hpp
\brief contains the class CSV_data
*/

/*!
\class CSV_line CSV_line.hpp "CSV_line.hpp"
\brief formated line of a csv file
*/
class CSV_line{//used in CSV_data class
	private:
		/*!
		\brief number of fields in the line
		\type integer
		*/
		int fields_;

		/*!
		\brief list of fields of the line
		\type std:vector<std::string>
		*/
		std::vector<std::string> field_;
	public:
		//biulder
		/*!
		\brief constructor of the class
		*/
		CSV_line(){ fields_=0; }

		/*!
		\brief pushes an specific line field the list of fields of the line
		\param std::string: new field
		*/
		void push_field(std::string field){
			field_.push_back(field);
			fields_++;
		};

		/*!
		\brief geter of number of filds of the line
		\return integer n_fields
		*/
		int fields() const {return fields_;}

		/*!
		\brief geter an specific field of the line
		\param integer: index of field
		\return std::string
		*/
		std::string get_field(int index) const {return field_[index];}

		/*!
		\brief clears the line into it's defaults values
		*/
		void clear(){
			field_.clear();
			fields_=0;
		}
};

/*!
\class CSV_data CSV_data.hpp "CSV_data.hpp"
\brief formated data of the CSV file
*/
class CSV_data{ //returned class for load_csv()
	private:
		/*!
		\brief number of lines in the data
		\type integer
		*/
		int lines_;

		/*!
		\brief list of lines in the data
		\type std:vector<CSV_lines>
		*/
		std::vector<CSV_line> line_;
	public:
		//builder
		/*!
		\brief constructor of the class
		*/

		CSV_data(){ lines_=0; }
		/*!
		\brief pushes an specific line into the list of lines
		\param CSV_line: new line
		*/

		void push_line(CSV_line new_line){
			line_.push_back(new_line);
			lines_++;
		}
		/*!
		\brief geter an specific line of the data
		\param integer: index of line
		\return CSV_line
		*/

		CSV_line get_line(int index) const {return line_[index];}
		/*!
		\brief geter of number of lines of the data
		\return integer n_lines
		*/

		int lines() const { return lines_; };
		/*!
		\brief prints all the formated data in the terminal
		*/
		void print() const ;
};

#endif
