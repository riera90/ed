#ifndef _PROVINCIA_HANDLER_HPP_
#define _PROVINCIA_HANDLER_HPP_

#include "Provincia_controler.hpp"

/*!
\file Provincia_handler.hpp
\brief contains the class Provincia_handler
*/

/*!
\class Provincia_handler Provincia_handler.hpp "Provincia_handler.hpp"
\brief handler class for provincia.
this class handles the petitions for the provincia class and manages constrol the procincia controler.
*/


class Provincia_handler : public Provincia_controler{

	private:

		std::list<Municipio>::iterator it_municipios_;

	public: //constructor
		/*!
		\brief builder of Provincia_handler
		\param string: provincia's name
		\param integer: provincia's code
		*/
		Provincia_handler(std::string name="", int code=0)
		: Provincia_controler(name, code){
			goto_head();
		};

	public: //goto's
		/*!
		\brief gets the municipio of the pointer
		\return Municipio
		*/
		Municipio get_municipio(){
			return *it_municipios_;
		}

		/*!
		\brief pointer=head
		*/
		inline void goto_head(){
			it_municipios_=municipios_.begin();
		}

		/*!
		\brief pointer=last_element
		*/
		inline void goto_last(){
			it_municipios_=--(municipios_.end());
		}

		/*!
		\brief pointer=next element
		*/
		inline void goto_next(){
			if (*it_municipios_==municipios_.back()) {
				goto_head();
			}else	it_municipios_++;
		}

		/*!
		\brief pointer=previous_element
		*/
		inline void goto_previous(){
			if (*it_municipios_==municipios_.front()) {
				goto_last();
			}else it_municipios_--;
		}

	public:

		/*!
		\brief adds a municipio to the provincia
		\param Municipio
		\post the class is in an stable condition
		*/
		inline void add(Municipio municipio){
			push_municipio(municipio);
			list_actialization();
		}

		/*!
		\brief checker for the existance of a municipio
		\param string: municipio's name
		\return boolean
		*/
		bool exists(std::string municipio);

		/*!
		\brief locator of a municipio
		\param Municipio
		\return std::list<Muncipio>::iterator
		*/
		std::list<Municipio>::iterator locate(Municipio municipio);

		/*!
		\brief checker for the existance of a municipio
		\param Municipio
		\return boolean
		*/
		bool find(std::string name);



	public://modifiers
		/*!
		\brief clears the list of municipios of the Provincia
		*/
		inline void clear(){municipios_.clear();}

		/*!
		\brief erase a given municipio of the Provincia
		\param Municipio
		*/
		inline bool erase(Municipio municipio){
			if (!exists(municipio.get_name())) return false;
			std::list<Municipio>::iterator it;
			it=locate(municipio);
			municipios_.erase(it);
			return true;
		}

		/*!
		\brief modify the selected municipio
		\param Municipio: with new values
		*/
		inline void modify(Municipio municipio){
			(*it_municipios_)=municipio;
			list_actialization();
		}

		/*!
		\brief insert a given municipio into the Provincia
		\param Municipio
		*/
		inline void insert(Municipio municipio){
			push_municipio(municipio);
			list_actialization();
		}
};

#endif
