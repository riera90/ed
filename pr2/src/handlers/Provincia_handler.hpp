#ifndef _PROVINCIA_HANDLER_HPP_
#define _PROVINCIA_HANDLER_HPP_

#include "Provincia_controler.hpp"

class Provincia_handler : public Provincia_controler{

	private:
		int index;
		std::list<Municipio>::iterator it_municipios_;

	public: //constructor
		Provincia_handler(std::string name="", int code=0)
		: Provincia_controler(name, code){
			goto_head();
		};

	public: //goto's
		Municipio get_municipio(){
			return *it_municipios_;
		}

		void goto_head(){
			it_municipios_=municipios_.begin();
		}

		void goto_last(){
			it_municipios_=--(municipios_.end());
		}

		void goto_next(){
			if (*it_municipios_==municipios_.back()) {
				goto_head();
			}else	it_municipios_++;
		}

		void goto_previous(){
			if (*it_municipios_==municipios_.front()) {
				goto_last();
			}else it_municipios_--;
		}

	public:
		void add(Municipio municipio){
			push_municipio(municipio);
			list_actialization();
		}
};

#endif
