/*!
   \file Hora.hpp
   \brief Fichero de la clase Hora
*/

#ifndef _HORA_HPP_
#define _HORA_HPP_


#include <iostream>
#include <string>
#include <sstream>


// Se incluye la clase Fecha dentro del espacio de nombres de la asigantura: ed
namespace ed {

	//!  Definición de la clase Fecha
	class Hora
	{
		//! \name Atributos privados de la clase Fecha
		private:
			int _hora;  //!< Hora de la hora
			int _minuto;  //!< Minuto de la hora

		//! \name Funciones o métodos públicos de la clase Fecha
		public:

			Hora(int hora=0, int minuto=0);

			void setHora(int hora);

			void setMinuto(int minuto);

			int getHora() const;

			int getMinuto() const;

			std::string getHoraString() const;

			void leerHora();

			bool isValid() const;

			inline bool operator==(Hora const &hora) const {
				return (this->getHora()==hora.getHora() && this->getMinuto()==hora.getMinuto());
			}

	}; // \brief fin de la clase Hora
} // \brief Fin de namespace ed.

//  _FECHA_HPP_
#endif
