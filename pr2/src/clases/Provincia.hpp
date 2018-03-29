#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

#include <iostream>
#include "Provincia_base.hpp"
#include "Provincia_controler.hpp"
#include "Provincia_handler.hpp"
/*!
\file Provincia.hpp
\brief contains the class Provincia
*/

/*!
\class Provincia Provincia.hpp "Provincia.hpp"
\brief complete provincia class.
this class entends from Provincia_base, Provincia_controler and Provincia_handler.
*/
class Provincia : public Provincia_handler{
	public:
		/*!
		\brief builder of Provincia_controler
		\param string: provincia's name
		\param integer: provincia's code
		*/
		Provincia(std::string name="", int code=0)
		: Provincia_handler(name, code){};
	public:
		/*!
		\brief prints all the Municipio's names of the Provincia
		*/
		void print_all_names();
};

#endif
