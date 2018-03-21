#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Line{
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

class CSV_data{
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
			if (file_.eof()) {
				std::cout << "this is the end..." << '\n';
				Line empty;
				return empty;
			}
			line=temp_line;
			field=line.substr(0,line.find(','));
			complete_line.push_field(field);
			while (line.find(',')!=std::string::npos) {
				line=line.substr(line.find(',')+1);
				field=line.substr(0,line.find(','));
				complete_line.push_field(field);
			}
			return complete_line;
		}
	public:
		CSV_data load_csv(){
			CSV_data data;
			Line line=load_csv_line();
			while (line.fields()){
				data.push_line(line);
				line=load_csv_line();
			}
			return data;
		}
};
