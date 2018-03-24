#ifndef _PROVINCIA_H_
#define _PROVINCIA_H_

#include <string>
#include <list>
#include "Municipio.hpp"
#include "CSV_reader.hpp"

void pr();
class Provincia{
	public:
		Provincia(std::string name="", int code=0){
			name_=name;
			code_=code;
		}

	private:
		std::string name_;
		int code_;
		std::list<Municipio> municipios_;

	public://getters
		std::string get_name(){ return name_; };
		int get_code(){ return code_; };

	public://setters
		void set_name(std::string name){ name_=name; };
		void set_code(int code){ code_=code; };

	public://observers
		int n_municipios(){ return municipios_.size(); };
		bool is_empty(){ return n_municipios()==0 ? true:false; };

	protected:
		void push_municipio(Municipio municipio){
			municipios_.push_back(municipio);
		}
};

#endif
