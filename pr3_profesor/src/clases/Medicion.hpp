/*!
   \file Medicion.hpp
   \brief Fichero de la clase Medicion: medición de una estación meteorológica
*/

#ifndef _MEDICION_HPP_
#define _MEDICION_HPP_

// Entrada y salida
#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <string>

#include "Hora.hpp"
#include "Fecha.hpp"
#include "macros.hpp"
// #include "utils.hpp"


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
		float temperaturaMaxima_;
		Hora horaTemperaturaMaxima_;
		float temperaturaMinima_;
		Hora horaTemperaturaMinima_;
		float temperaturaMedia_;
		float humedaddRelativaMaxima_;
		float humedaddRelativaMinima_;
		float humedaddRelativaMedia_;
		float velocidadVientoMedia_;
		float direccionVientoMedia_;
		float radiacionSolar_;
		float precipitacion_;	//!< cantidad de precipitacion
		float eto_;
		bool valid_;


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
		Medicion(Fecha fecha=Fecha(1,1,1), float precipitacion=0);

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

		void setValid(bool val){valid_=val;}

		bool isValid() const {return valid_;}

		void setTemperaturaMaxima(float temperaturaMaxima){
			temperaturaMaxima_=temperaturaMaxima;
		}

		float getTemperaturaMaxima() const {
			return temperaturaMaxima_;
		}


		void setHoraTemperaturaMaxima(Hora horaTemperaturaMaxima){
			horaTemperaturaMaxima_=horaTemperaturaMaxima;
		}

		Hora getHoraTemperaturaMaxima() const {
			return horaTemperaturaMaxima_;
		}


		void setTemperaturaMinima(float temperaturaMinima){
			temperaturaMinima_=temperaturaMinima;
		}

		float getTemperaturaMinima() const {
			return temperaturaMinima_;
		}


		void setHoraTemperaturaMinima(Hora horaTemperaturaMinima){
			horaTemperaturaMinima_=horaTemperaturaMinima;
		}

		Hora getHoraTemperaturaMinima() const {
			return horaTemperaturaMinima_;
		}


		void setTemperaturaMedia(float temperaturaMedia){
			temperaturaMedia_=temperaturaMedia;
		}

		float getTemperaturaMedia() const {
			return temperaturaMedia_;
		}


		void setHumedadRelativaMaxima(float humedaddRelativaMaxima){
			humedaddRelativaMaxima_=humedaddRelativaMaxima;
		}

		float getHumedadRelativaMaxima() const {
			return humedaddRelativaMaxima_;
		}


		void setHumedadRelativaMinima(float humedaddRelativaMinima){
			humedaddRelativaMinima_=humedaddRelativaMinima;
		}

		float getHumedadRelativaMinima() const {
			return humedaddRelativaMinima_;
		}


		void setHumedadRelativaMedia(float humedadRelativaMedia){
			humedaddRelativaMedia_=humedadRelativaMedia;
		}

		float getHumedadRelativaMedia() const {
			return humedaddRelativaMedia_;
		}


		void setVelocidadVientoMedia(float velocidadVientoMedia){
			velocidadVientoMedia_=velocidadVientoMedia;
		}

		float getVelocidadVientoMedia() const {
			return velocidadVientoMedia_;
		}


		void setDireccionVientoMedia(float direccionVientoMedia){
			direccionVientoMedia_=direccionVientoMedia;
		}

		float getDireccionVientoMedia() const {
			return direccionVientoMedia_;
		}


		void setRadiacionSolar(float radiacionSolar){
			radiacionSolar_=radiacionSolar;
		}

		float getRadiacionSolar() const {
			return radiacionSolar_;
		}


		void setEto(float eto){
			eto_=eto;
		}

		float getEto() const {
			return eto_;
		}

		bool const equal(Medicion const &medicion)const{
			return \
			this->getFecha().fechaCompare(\
			medicion.getFecha())==0 ? \
			true : false;
		}


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
					and (this->getPrecipitacion()-medicion.getPrecipitacion() <= 0.00001)
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

		/*!
		\brief     	funcion de lectura por pantalla de una medicion
		\sa					setFecha(), setPrecipitacion()
		*/
		void leerMedicion();

		/*!
		\brief     	funcion de lectura de un fichero de una medicion
		\sa					setFecha(), setPrecipitacion()
		*/
		void cargarMedicionDeFichero(std::istream &stream);

		/*!
		\brief     	funcion de escritura por pantalla de una medicion
		\sa					getFecha(), getPrecipitacion()
		\note				funcion constante
		*/
		void escribirMedicion() const ;

		std::string getMedicionString() const ;

		void clear();

}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo




} // \brief Fin de namespace ed.

/*!
\brief     Sobrecarga del operador de salida o escritura "<<"
		   \n Se escribe la medicion por pantalla con el formato <d-m-aaaa precipitacion>
\param     stream Flujo de salida
\param     Medicion pasada como referencia constante
\pre       Ninguna
\post      Ninguna
\sa        operator>>()
*/
std::ostream& operator<<(std::ostream& stream, ed::Medicion const & medicion);

/*!
\brief     Sobrecarga del operador de entrada o lectura ">>"
\param     stream Flujo de entrada
\param     fecha Medicion como referencia
\pre       Ninguna
\post      Ninguna
\sa        operator<<()
*/
std::istream& operator>>(std::istream& stream, ed::Medicion& medicion);

//  _MEDICION_HPP_


#endif
