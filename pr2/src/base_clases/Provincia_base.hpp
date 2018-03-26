#ifndef _PROVINCIA_BASE_H_
#define _PROVINCIA_BASE_H_

#include <string>
#include <list>
#include "Municipio.hpp"
#include "CSV_reader.hpp"

void pr();
class Provincia_base{
	public:
		Provincia_base(std::string name="", int code=0){
			name_=name;
			code_=code;
		}

	private:
		std::string name_;
		int code_;

	protected:
		std::list<Municipio> municipios_;

	public://getters
		inline std::string get_name() const { return name_; };
		inline int get_code() const { return code_; };

	public://setters
		inline void set_name(std::string name){ name_=name; };
		inline void set_code(int code){ code_=code; };

	public://observers
		inline int n_municipios() const { return municipios_.size(); };
		inline bool is_empty() const {
			return n_municipios()==0 ? true:false;
		};
		int get_total_mens();
		int get_total_womens();
		inline int get_total_habitants(){
			return get_total_mens()+get_total_womens();
		};
};

#endif
