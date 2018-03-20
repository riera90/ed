#ifndef _PROVINCIA_H_
#define _PROVINCIA_H_

#include <string>
#include <list>
#include "Municipio.hpp"
class Provincia{
	private:
		std::string name_;
		int code_;
		std::list<Municipio> municipios;

	public://getters
		std::string get_name(){ return name_; };
		int get_code(){ return code_; };

	public://setters
		void get_name(std::string name){ name_=name; };
		void get_code(int code){ code_=code; };

	public://observers
	int n_municipios(){ return municipios.size(); };
	bool is_empty(){ return n_municipios()==0 ? true:false; };
};

#endif
