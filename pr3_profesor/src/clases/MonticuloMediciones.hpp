/*!
	\file MonticuloMediciones.hpp
	\brief Se define el TAD MonticuloMediciones.
	\author Diego Rodriguez Riera
	\date 17.04.2018
*/

#ifndef _MONTICULO_MEDICIONES_HPP
#define _MONTICULO_MEDICIONES_HPP

#include <vector>
#include <cassert>

#include "Medicion.hpp"
#include "MonticuloMedicionesInterfaz.hpp"


namespace ed
{

class MonticuloMediciones : public MonticuloMedicionesInterfaz
{
	private:
		//! \name Atributos privados de la clase MonticuloMediciones
		std::vector<Medicion> mediciones_; //!< vector de Mediciones

		//! \name Métodos privados de la clase MonticuloMediciones

	//! \name Métodos públicos de la clase MonticuloMediciones
	public:

		//! \name Constructor
		MonticuloMediciones(){
		}

		//! \name Observadores
		bool isEmpty() const {
			return mediciones_.size()==0 ? true:false;
		}

		//! \name Operaciones de modificación
		void insert(Medicion &medicion){
			std::vector<Medicion>::iterator it;
			it=mediciones_.begin();
			//TODO search for the coresponding posicion to insert
			mediciones_.insert(it,medicion);
		}

		//! \name Operadores

		//! \name Función de escritura

	}; // Clase MonticuloMediciones

} // Espacio de nombres ed


#endif // _MONTICULO_MEDICIONES_HPP
