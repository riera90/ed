#ifndef _PROVINCIA_BASE_H_
#define _PROVINCIA_BASE_H_

/*!
  \file   Provincia_base.hpp
  \brief  base class
	\author Diego Rodríguez Riera
*/


#include <string>
#include <list>
#include "Municipio.hpp"
#include "CSV_reader.hpp"

/*!
\class Provincia_base Provincia_base.hpp "Provincia_base.hpp"
\brief base class for provincia.
*/

class Provincia_base{
	public:
		/*!
		\brief builder
		\param string: provincia's name
		\param integer: provincia's code
		*/
		Provincia_base(std::string name="", int code=0){
			name_=name;
			code_=code;
		}

	private:
		/*!
		\brief provincia's name
		*/
		std::string name_;

		/*!
		\brief provincia's code_
		*/
		int code_;

	protected:
		/*!
		\brief provincia's municipios list
		*/
		std::list<Municipio> municipios_;

	public://getters
		/*!
		\brief name getter
		\return string
		*/
		inline std::string get_name() const { return name_; };

		/*!
		\brief code getter
		\return integer
		*/
		inline int get_code() const { return code_; };

	public://setters
		/*!
		\brief name setter
		\param string
		*/
		inline void set_name(std::string name){ name_=name; };

		/*!
		\brief code setter
		\param integer
		*/
		inline void set_code(int code){ code_=code; };

	public://observers
		/*!
		\brief observer for the number of municipios
		\return integer
		*/
		inline int n_municipios() const { return municipios_.size(); };

		/*!
		\brief evaluator for an empty provincia
		returns true if the Provincia have none municipios
		\return boolean
		*/
		inline bool is_empty() const {
			return n_municipios()==0 ? true:false;
		};

		/*!
		\brief observer for the number of mens
		\return integer
		*/
		int get_total_mens();

		/*!
		\brief observer for the number of womens
		\return integer
		*/
		int get_total_womens();

		/*!
		\brief observer for the number of habitants in the Provincia
		\return integer
		*/
		inline int get_total_habitants(){
			return get_total_mens()+get_total_womens();
		};
};

#endif
