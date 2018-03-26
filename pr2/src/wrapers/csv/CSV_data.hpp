#ifndef _CSV_DATA_HPP_
#define _CSV_DATA_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#define SEPARATOR ';'
class CSV_line{//used in CSV_data class
	private:
		int fields_;
		std::vector<std::string> field_;
	public:
		//biulder
		CSV_line(){ fields_=0; }
		void push_field(std::string field){
			field_.push_back(field);
			fields_++;
		};
		int fields() const {return fields_;}
		std::string get_field(int index) const {return field_[index];}
		void clear(){
			field_.clear();
			fields_=0;
		}
};

class CSV_data{ //returned class for load_csv()
	private:
		int lines_;
		std::vector<CSV_line> line_;
	public:
		//builder
		CSV_data(){ lines_=0; }
		void push_line(CSV_line new_line){
			line_.push_back(new_line);
			lines_++;
		}
		CSV_line get_line(int index) const {return line_[index];}
		int lines() const { return lines_; };
		void print() const ;
};

#endif
