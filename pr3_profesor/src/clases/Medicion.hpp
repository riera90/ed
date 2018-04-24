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
		float temperaturaMaxima_;
		std::string horaTemperaturaMaxima_;
		float temperaturaMinima_;
		std::string horaTemperaturaMinima_;
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

		bool isValid(){return valid_;}

		void setTemperaturaMaxima(float temperaturaMaxima){
			temperaturaMaxima_=temperaturaMaxima;
		}

		float getTemperaturaMaxima(){
			return temperaturaMaxima_;
		}


		void setHoraTemperaturaMaxima(std::string horaTemperaturaMaxima){
			horaTemperaturaMaxima_=horaTemperaturaMaxima;
		}

		std::string getHoraTemperaturaMaxima(){
			return horaTemperaturaMaxima_;
		}


		void setTemperaturaMinima(float temperaturaMinima){
			temperaturaMinima_=temperaturaMinima;
		}

		float getTemperaturaMinima(){
			return temperaturaMinima_;
		}


		void setHoraTemperaturaMinima(std::string horaTemperaturaMinima){
			horaTemperaturaMinima_=horaTemperaturaMinima;
		}

		std::string getHoraTemperaturaMinima(){
			return horaTemperaturaMinima_;
		}


		void setTemperaturaMedia(float temperaturaMedia){
			temperaturaMedia_=temperaturaMedia;
		}

		float getTemperaturaMedia(){
			return temperaturaMedia_;
		}


		void setHumedaddRelativaMaxima(float humedaddRelativaMaxima){
			humedaddRelativaMaxima_=humedaddRelativaMaxima;
		}

		float getHumedaddRelativaMaxima(){
			return humedaddRelativaMaxima_;
		}


		void setHumedaddRelativaMinima(float humedaddRelativaMinima){
			humedaddRelativaMinima_=humedaddRelativaMinima;
		}

		float getHumedaddRelativaMinima(){
			return humedaddRelativaMinima_;
		}


		void setHumedadRelativaMedia(float humedadRelativaMedia){
			humedaddRelativaMedia_=humedadRelativaMedia;
		}

		float getHumedadRelativaMedia(){
			return humedaddRelativaMedia_;
		}


		void setVelocidadVientoMedia(float velocidadVientoMedia){
			velocidadVientoMedia_=velocidadVientoMedia;
		}

		float getVelocidadVientoMedia(){
			return velocidadVientoMedia_;
		}


		void setDireccionVientoMedia(float direccionVientoMedia){
			direccionVientoMedia_=direccionVientoMedia;
		}

		float getDireccionVientoMedia(){
			return direccionVientoMedia_;
		}


		void setRadiacionSolar(float radiacionSolar){
			radiacionSolar_=radiacionSolar;
		}

		float getRadiacionSolar(){
			return radiacionSolar_;
		}


		void setEto(float eto){
			eto_=eto;
		}

		float getEto(){
			return eto_;
		}

		bool equal(Medicion medicion){
			return medicion==*this;
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
		void escribirMedicion();

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
