#ifndef _PROVINCIA_CONTROLER_HPP_
#define _PROVINCIA_CONTROLER_HPP_

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <stdio.h>
#include <string.h>

#include "Provincia_base.hpp"
#include "Municipio.hpp"
#include "CSV_writer.hpp"
/*!
\file Provincia_controler.hpp
\brief contains the class Provincia_controler
*/

/*!
\brief evaluator for alphabetical ordering of municipios
\return boolean : true if a.name is greater than b.name
*/
bool way_to_short(const Municipio &a, const Municipio &b);


/*!
\class Provincia_controler Provincia_controler.hpp "Provincia_controler.hpp"
\brief controler class for provincia.
this class controls the Provincia_base class
*/
class Provincia_controler : public Provincia_base{

	public: //constructor
		/*!
		\brief builder of Provincia_controler
		\param string: provincia's name
		\param integer: provincia's code
		*/
		Provincia_controler(std::string name="", int code=0)
		: Provincia_base(name, code){};

	public: //csv reader
		/*!
		\brief data loader from csv
		using the VSC_reader wrapper
		\param string: file path
		*/
		void load_data(std::string csv_file);

		/*!
		\brief data dumper to csv
		using the VSC_writer wrapper
		\param string: file path
		*/
		void dump_data(std::string csv_file);

	protected:
		/*!
		\brief adds a municipio to the municipios list
		\param Municipio: municipio to save
		*/
		inline void push_municipio(Municipio municipio){
			municipios_.push_front(municipio);
		}

	public:
		/*!
		\brief makes all the necesary changes to the provincia when it's actualized
		*/
		void list_actialization();

	protected:
		/*!
		\brief shorts the list of municipios
		it shorts it alphabeticaly by name
		*/
		void list_short();
};



#endif
