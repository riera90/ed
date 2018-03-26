#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

#include <iostream>
#include "Provincia_base.hpp"
#include "Provincia_controler.hpp"
#include "Provincia_handler.hpp"

class Provincia : public Provincia_handler{
	public:
		Provincia(std::string name="", int code=0)
		: Provincia_handler(name, code){};
	public:
		void print_all_names();
};

#endif
