#ifndef _CSV_reader_hpp_
#define _CSV_reader_hpp_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Line{//used in CSV_data class
	private:
		int fields_;
		std::vector<std::string> field_;
	public:
		Line(){ fields_=0; }
		void push_field(std::string field){
			field_.push_back(field);
			fields_++;
		};
		int fields(){return fields_;}
		std::string get_field(int index){return field_[index];}
};

class CSV_data{ //returned class for load_csv()
	private:
		int lines_;
		std::vector<Line> line_;
	public:
		CSV_data(){ lines_=0; }
		void push_line(Line new_line){
			line_.push_back(new_line);
			lines_++;
		}
		Line get_line(int index){return line_[index];}
		int lines(){ return lines_; };
		void print();
};

class CSV_reader{
	private:
		std::ifstream file_;
	public:
		CSV_reader(std::string route){
			file_.open(route);
			if (!file_.is_open()) {
				std::cout << "ERROR!! Could not open the file!" << '\n';
				exit(1);
			}
		}
		~CSV_reader(){
			file_.close();
		}
	private://load a line of the file
		Line load_csv_line(){
			Line complete_line;
			char temp_line[256];
			std::string line, field;
			file_.getline(temp_line, 256);
			//checks for end of file, if so, returns an empty line meaning the EOF
			if (file_.eof()) {
				Line empty;
				return empty;
			}
			line=temp_line;
			//substract the fiend from the string
			field=line.substr(0,line.find(','));
			//pushes the fiend into the line
			complete_line.push_field(field);
			//checks if thera are none fields to be read
			while (line.find(',')!=std::string::npos) {
				//delete the fiend from the string
				line=line.substr(line.find(',')+1);
				//gets the next field
				field=line.substr(0,line.find(','));
				//pushes the fiend into the line
				complete_line.push_field(field);
			}
			return complete_line;
		}
	public:
		CSV_data load_csv(){//loads all the cvs file
			CSV_data data;
			//gets the first line to launch the loop
			Line line=load_csv_line();
			//checks for empty lines (if is empty it means the endo of file)
			while (line.fields()){
				//pushes the line into the data class (returned class)
				data.push_line(line);
				//gets a new line
				line=load_csv_line();
			}
			return data;
		}
};

#endif
