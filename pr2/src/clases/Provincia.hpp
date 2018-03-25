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
		int get_total_mans();
		int get_total_womans();
		inline int get_total_habitants(){
			return get_total_mans()+get_total_womans();
		};
};

#endif
