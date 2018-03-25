#ifndef _PROVINCIA_HANDLER_HPP_
#define _PROVINCIA_HANDLER_HPP_

#include "Provincia_controler.hpp"

class Provincia_handler : public Provincia_controler{

	private:

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

		inline void goto_head(){
			it_municipios_=municipios_.begin();
		}

		inline void goto_last(){
			it_municipios_=--(municipios_.end());
		}

		inline void goto_next(){
			if (*it_municipios_==municipios_.back()) {
				goto_head();
			}else	it_municipios_++;
		}

		inline void goto_previous(){
			if (*it_municipios_==municipios_.front()) {
				goto_last();
			}else it_municipios_--;
		}

	public:

		inline void add(Municipio municipio){
			push_municipio(municipio);
			list_actialization();
		}

		bool exists(std::string municipio);
		std::list<Municipio>::iterator locate(Municipio municipio);


	public://modifiers

		inline void clear(){municipios_.clear();}

		inline bool erase(Municipio municipio){
			if (!exists(municipio.get_name())) return false;
			std::list<Municipio>::iterator it;
			it=locate(municipio);
			municipios_.erase(it);
			return true;
		}

		inline void modify(Municipio municipio){
			(*it_municipios_)=municipio;
		}
};

#endif
