#ifndef _PROVINCIA_CONTROLER_HPP_
#define _PROVINCIA_CONTROLER_HPP_

#include <algorithm>

#include "Provincia.hpp"
#include "Municipio.hpp"


bool way_to_short(const Municipio &a, const Municipio &b);


class Provincia_controler : public Provincia{

	public: //constructor
		Provincia_controler(std::string name="", int code=0)
		: Provincia(name, code){};

	public: //csv reader
		void load_data(std::string csv_file);

	protected:
		void push_municipio(Municipio municipio){
			municipios_.push_back(municipio);
		}

	protected:
		void list_actialization();
		void list_short();
};



#endif
