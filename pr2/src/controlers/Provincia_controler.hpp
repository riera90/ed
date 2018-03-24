#ifndef _PROVINCIA_CONTROLER_HPP_
#define _PROVINCIA_CONTROLER_HPP_

#include "Provincia.hpp"
#include "Municipio.hpp"

class Provincia_controler : public Provincia{
	public:
		Provincia_controler(std::string name="", int code=0):Provincia(name, code){

		};

	private:
		CSV_data data_;

	public://csv reader
		void load_data(std::string csv_file);
};

#endif
