/*!
   \file Medicion.hpp
   \brief Fichero de la clase Medicion: medición de una estación meteorológica
*/

#ifndef _MEDICION_HPP_
#define _MEDICION_HPP_

// Entrada y salida
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

// Definición de la clase Fecha
#include "Fecha.hpp"


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Se incluye la clase Medicion dentro del espacio de nombres de la asigantura: ed
namespace ed {

//!  Definición de la clase Medicion
class Medicion
{
  //! \name Atributos privados de la clase Medicion
  private:
		Fecha fecha_;					//!< fecha de la medicion
		float precipitacion_;	//!< cantidad de precipitacion


   //! \name Funciones o métodos públicos de la clase Medicion
  public:
		/*!
 		\brief     Constructor de la clase Medicion
 		\attention Función sobrecargada
 		\note      Función inline
 		\warning   Los parámetros tienen valores por defecto
 		\param     fecha; valor por defecto 1/1/1
 		\pre       Ninguna
 		\post      La fecha debe ser correcta
	 	*/
		Medicion(Fecha fecha=Fecha(1,1,1), float precipitacion=0)
		:fecha_(fecha), precipitacion_(precipitacion){};

		/*!
		\brief     observador de la fecha de la medicion
		\note      Función inline
		\return    fecha; fecha de la medicion
		\pre       Ninguna
		*/
		Fecha getFecha() const {return fecha_;}

		/*!
		\brief     observador de la precipitacion de la medicion
		\note      Función inline
		\return    precipitacion; cantidad de lluvia de la medicion
		\pre       Ninguna
		*/
		float getPrecipitacion() const {return precipitacion_;}

		/*!
		\brief     modificador de la fecha de la medicion
		\note      Función inline
		\param     fecha; fecha de la medicion
		\pre       la fecha es valida
		*/
		void setFecha(Fecha fecha){fecha_=fecha;}

		/*!
		\brief     modificador de la precipitacion de la medicion
		\note      Función inline
		\param     precipitacion; cantidad de lluvia de la medicion
		\pre       precipitacion >= 0
		*/
		void setPrecipitacion(float precipitacion){precipitacion_=precipitacion;}



		//! \name Operadores

		/*!
		\brief     	operador comparador de igualdad
		\note      	Función inline
		\param     	Medicion objeto pasado por referancia
		\sa 				getFecha(), getPrecipitacion()
		*/
		inline bool operator==(Medicion const &medicion) const {
			return (
							( this->getFecha()==medicion.getFecha() )
					and (this->getPrecipitacion()==medicion.getPrecipitacion())
			);
		}

		/*!
		\brief     	operador de asignacion
		\note      	Función inline
		\param     	Medicion objeto pasado por referancia
		\sa					getFecha(), setFecha(), getPrecipitacion(), setPrecipitacion()
		*/
		inline Medicion& operator=(Medicion const &medicion){
			this->setFecha(medicion.getFecha());
			this->setPrecipitacion(medicion.getPrecipitacion());
		}



		//! \name Funciones de lectura y escritura de la clase Medicion

		void inline leerMedicion(){
			std::cout << "introduzca la medicion con el siguiente formato:\n\tdia-mes-año precipitación" << '\n';
			std::cin >>(*this);//TODO
		}

		void inline escribirMedicion() const {
			std::cout <<(*this)<< '\n';//TODO
		}


}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN



} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif
