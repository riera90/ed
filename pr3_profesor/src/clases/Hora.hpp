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

	//!  Definición de la clase Hora
	class Hora
	{
		//! \name Atributos privados de la clase Hora
		private:
			int _hora;		//!< Hora de la hora
			int _minuto;	//!< Minuto de la hora

		//! \name Funciones o métodos públicos de la clase Fecha
		public:
			/*!
			\brief     Constructor de la clase Hora
			\note      Función inline
			\warning   Los parámetros tienen valores por defecto
			\param     Hora, valor por defecto 0:0
			\post      La Hora debe ser correcta
			*/
			Hora(int hora=0, int minuto=0);

			/*!
			\brief     modificador de la hora de la Hora
			\note      Función inline
			\param     hora; hora del tiempo
			\pre       la hora es valida
			*/
			void setHora(int hora);

			/*!
			\brief     modificador del minuto de la Hora
			\note      Función inline
			\param     minuto; minuto del tiempo
			\pre       la hora es valida
			*/
			void setMinuto(int minuto);

			/*!
			\brief     observador de la hora de un tiempo
			\note      Función inline
			\return    hora; (entero) hora de la hora
			*/
			int getHora() const;

			/*!
			\brief     observador del minuto de un tiempo
			\note      Función inline
			\return    minuto; (entero) minuto de la hora
			*/
			int getMinuto() const;

			/*!
			\brief     observador de una hora
			\note      Función inline
			\return    hora; (string) medicion de la hora total
			*/
			std::string getHoraString() const;

			/*!
			\brief     modificador de lectura por teclado de una hora
			\note      Función inline
			\post 		la hora es valida
			*/
			void leerHora();

			/*!
			\brief     observador de la validez de una hora
			\note      Función inline
			\return    booleano, verdadero si es correcta, falso en el caso contrario
			*/
			bool isValid() const;

			/*!
			\brief     operador de comparacion
			\param     Hora; hora a comparar
			\note      Función inline
			\return    booleano, verdadero si es correcta, falso en el caso contrario
			*/
			inline bool operator==(Hora const &hora) const {
				return (this->getHora()==hora.getHora() && this->getMinuto()==hora.getMinuto());
			}

	}; // \brief fin de la clase Hora
} // \brief Fin de namespace ed.

//  _HORA_HPP_
#endif
