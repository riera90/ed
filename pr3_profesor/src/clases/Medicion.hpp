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
		Fecha fecha_;									//!< fecha de la medicion
		float temperaturaMaxima_;			//!< temperatura maxima
		Hora horaTemperaturaMaxima_;	//!< hora de la temperatura maxima
		float temperaturaMinima_;			//!< temepratira minima
		Hora horaTemperaturaMinima_;	//!< hora de la temperatura minima
		float temperaturaMedia_;			//!< temperatura media
		float humedaddRelativaMaxima_;//!< humedad relativa maxima
		float humedaddRelativaMinima_;//!< humedad relativa minima
		float humedaddRelativaMedia_;	//!< humedad relativa media
		float velocidadVientoMedia_;	//!< velocidad media del viento
		float direccionVientoMedia_;	//!< angulo medio del viento
		float radiacionSolar_;				//!< radiacion solar media
		float precipitacion_;					//!< cantidad de precipitacion
		float eto_;										//!< ETO (evaporacion en el campo)


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
		\note 		 funcion constante
		\return    fecha; fecha de la medicion
		\pre       Ninguna
		*/
		Fecha getFecha() const {return fecha_;}

		/*!
		\brief     observador de la precipitacion de la medicion
		\note      Función inline
		\note			 funcion constante
		\return    precipitacion; cantidad de lluvia de la medicion
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

		/*!
		\brief     observador de validez de una fecha
		\note      Función inline
		\note			 funcion cosntante
		\return		 booleano; verdadero si la fecha es valida, falso en el caso contrario
		*/
		bool isValid() const ;

		/*!
		\brief     modificador de la temperatura maxima de una precipitacion
		\note      Función inline
		\note 		 funcion constante
		\param     temperaturaMaxima; temperatura maxima de una medicion
		*/
		void setTemperaturaMaxima(float temperaturaMaxima){
			temperaturaMaxima_=temperaturaMaxima;
		}

		/*!
		\brief     observador de la temperatura maxima de la medicion
		\note      Función inline
		\return    temperaturaMaxima; temperatura maxima de una medicion
		*/
		float getTemperaturaMaxima() const {
			return temperaturaMaxima_;
		}

		/*!
		\brief     modificador de la temperatura maxima de una precipitacion
		\note      Función inline
		\param     horaTemperaturaMaxima; hora de la temperatura maxima de una medicion
		*/
		void setHoraTemperaturaMaxima(Hora horaTemperaturaMaxima){
			horaTemperaturaMaxima_=horaTemperaturaMaxima;
		}

		/*!
		\brief     observador de la hora de la temperatura maxima de la medicion
		\note      Función inline
		\note 		funcion constante
		\return    horaTemperaturaMaxima; hora de la temperatura maxima de una medicion
		*/
		Hora getHoraTemperaturaMaxima() const {
			return horaTemperaturaMaxima_;
		}

		/*!
		\brief     modificador de la temperatura minima de una precipitacion
		\note      Función inline
		\param     temperaturaMinima; temperatura minima de una medicion
		*/
		void setTemperaturaMinima(float temperaturaMinima){
			temperaturaMinima_=temperaturaMinima;
		}

		/*!
		\brief     observador de la  temperatura minima de la medicion
		\note      Función inline
		\note			 funcion constante
		\return    temperaturaMinima; temperatura minima de una medicion
		*/
		float getTemperaturaMinima() const {
			return temperaturaMinima_;
		}

		/*!
		\brief     modificador de la temperatura minima de una precipitacion
		\note      Función inline
		\param     horaTemperaturaMinima; hora de la temperatura minima de una medicion
		*/
		void setHoraTemperaturaMinima(Hora horaTemperaturaMinima){
			horaTemperaturaMinima_=horaTemperaturaMinima;
		}

		/*!
		\brief     observador de la hora de la temperatura minima de la medicion
		\note      Función inline
		\note			 funcion constante
		\return    horaTemperaturaMinima; hora de la temperatura minima de una medicion
		*/
		Hora getHoraTemperaturaMinima() const {
			return horaTemperaturaMinima_;
		}

		/*!
		\brief     modificador de la temperatura media de una precipitacion
		\note      Función inline
		\param     temperaturaMedia; temperatura media de una medicion
		*/
		void setTemperaturaMedia(float temperaturaMedia){
			temperaturaMedia_=temperaturaMedia;
		}

		/*!
		\brief     observador de la temperatura media de la medicion
		\note      Función inline
		\note			 funcion constante
		\return    temperaturaMedia; temperatura media de una medicion
		*/
		float getTemperaturaMedia() const {
			return temperaturaMedia_;
		}

		/*!
		\brief     modificador de la humedad relativa maxima de una medicion
		\note      Función inline
		\param     humedaddRelativaMaxima; humedad relativa maxima de una medicion
		*/
		void setHumedadRelativaMaxima(float humedaddRelativaMaxima){
			humedaddRelativaMaxima_=humedaddRelativaMaxima;
		}

		/*!
		\brief     observador de la humedad relativa maxima de la medicion
		\note      Función inline
		\note			 funcion constante
		\return    humedaddRelativaMaxima; humedad relativa maxima de una medicion
		*/
		float getHumedadRelativaMaxima() const {
			return humedaddRelativaMaxima_;
		}

		/*!
		\brief     modificador de la humedad relativa minima de una medicion
		\note      Función inline
		\param     humedaddRelativaMinima; humedad relativa minima de una medicion
		*/
		void setHumedadRelativaMinima(float humedaddRelativaMinima){
			humedaddRelativaMinima_=humedaddRelativaMinima;
		}

		/*!
		\brief     observador de la humedad relativa minima de la medicion
		\note      Función inline
		\note			 funcion constante
		\return    humedaddRelativaMinima; humedad relativa minima de una medicion
		*/
		float getHumedadRelativaMinima() const {
			return humedaddRelativaMinima_;
		}

		/*!
		\brief     modificador de la humedad relativa media de una medicion
		\note      Función inline
		\param     humedaddRelativaMedia; humedad relativa media de una medicion
		*/
		void setHumedadRelativaMedia(float humedadRelativaMedia){
			humedaddRelativaMedia_=humedadRelativaMedia;
		}

		/*!
		\brief     observador de la humedad relativa media de la medicion
		\note      Función inline
		\note			 funcion constante
		\return    humedadRelativaMedia; humedad relativa media de una medicion
		*/
		float getHumedadRelativaMedia() const {
			return humedaddRelativaMedia_;
		}

		/*!
		\brief     modificador de la velocidad media de una medicion
		\note      Función inline
		\param     velocidadVientoMedia: velocidad media del viento de una medicion
		*/
		void setVelocidadVientoMedia(float velocidadVientoMedia){
			velocidadVientoMedia_=velocidadVientoMedia;
		}

		/*!
		\brief     observador de la velocidad media del vieto de la medicion
		\note      Función inline
		\note			 funcion constante
		\return    velocidadVientoMedia; velocidad media del vieto de una medicion
		*/
		float getVelocidadVientoMedia() const {
			return velocidadVientoMedia_;
		}

		/*!
		\brief     modificador del angulo medio del viento de una medicion
		\note      Función inline
		\param     direccionVientoMedia: angulo medio del viento de una medicion
		*/
		void setDireccionVientoMedia(float direccionVientoMedia){
			direccionVientoMedia_=direccionVientoMedia;
		}

		/*!
		\brief     observador del angulo medio del viento de la medicion
		\note      Función inline
		\note			 funcion constante
		\return    direccionVientoMedia; angulo medio del viento de una medicion
		*/
		float getDireccionVientoMedia() const {
			return direccionVientoMedia_;
		}

		/*!
		\brief     modificador de la radiacion solar media de una medicion
		\note      Función inline
		\param     radiacionSolar: radiacion solar media del viento de una medicion
		*/
		void setRadiacionSolar(float radiacionSolar){
			radiacionSolar_=radiacionSolar;
		}

		/*!
		\brief     observador de la radiacion solar media de la medicion
		\note      Función inline
		\note			 funcion constante
		\return    radiacionSolar; radiacion solar media de una medicion
		*/
		float getRadiacionSolar() const {
			return radiacionSolar_;
		}

		/*!
		\brief     modificador del ETO medio de una medicion
		\note      Función inline
		\param     ETO: ETO medio de una medicion
		*/
		void setEto(float eto){
			eto_=eto;
		}

		/*!
		\brief     observador de la evaporacion media en el campo de la medicion
		\note      Función inline
		\note			 funcion constante
		\return    eto; evaporacion media en el campo de una medicion
		*/
		float getEto() const {
			return eto_;
		}

		/*!
		\brief     observador de igualdad
		\note      Función inline
		\param     medicion: (constante y por referencia) medicion a comparar con
		\return booleano: verdadero si las dos mediciones son iguales (misma hora) falso en el caso contrario
		*/
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
			this->setTemperaturaMaxima(medicion.getTemperaturaMaxima());
			this->setHoraTemperaturaMaxima(medicion.getHoraTemperaturaMaxima());
			this->setTemperaturaMinima(medicion.getTemperaturaMinima());
			this->setHoraTemperaturaMinima(medicion.getHoraTemperaturaMinima());
			this->setTemperaturaMedia(medicion.getTemperaturaMedia());
			this->setHumedadRelativaMaxima(medicion.getHumedadRelativaMaxima());
			this->setHumedadRelativaMinima(medicion.getHumedadRelativaMinima());
			this->setHumedadRelativaMedia(medicion.getHumedadRelativaMedia());
			this->setVelocidadVientoMedia(medicion.getVelocidadVientoMedia());
			this->setDireccionVientoMedia(medicion.getDireccionVientoMedia());
			this->setRadiacionSolar(medicion.getRadiacionSolar());
			this->setEto(medicion.getEto());
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
