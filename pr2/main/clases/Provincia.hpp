#ifndef _PROVINCIA_H_
#define _PROVINCIA_H_

#include <string>
#include <list>
#include "Municipio.hpp"
#include "CSV_reader.hpp"

void pr();
class Provincia{
	private:

		std::string name_;
		int code_;
		CSV_data data;
		std::list<Municipio> municipios;

	public://getters
		std::string get_name(){ return name_; };
		int get_code(){ return code_; };

	public://setters
		void set_name(std::string name){ name_=name; };
		void set_code(int code){ code_=code; };

	public://observers
		int n_municipios(){ return municipios.size(); };
		bool is_empty(){ return n_municipios()==0 ? true:false; };

	public://csv reader
		void load_data();
};

#endif
