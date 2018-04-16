/*!
	\file MonticuloMedicionesInterfaz.hpp
	\brief Se define la interfaz del TAD MonticuloMediciones.
	\author Diego Rodriguez Riera
	\date 17.04.2018
*/

#ifndef _MONTICULO_MEDICIONES_INTERFAZ_HPP
#define _MONTICULO_MEDICIONES_INTERFAZ_HPP

#include "Medicion.hpp"


namespace ed
{

	class MonticuloMedicionesInterfaz
	{
		public:

			/*!
			\brief     observador del estado del monticulo
			\note      Función virtual pura
			\return    logico: verdadero si la lista esta vacia, falso de ser al contrario
			*/
			bool isEpty() const = 0;

			/*!
			\brief     observador del elemento de la cima del monticulo
			\note      Función virtual pura
			\return    Medicion: elemento de la cima del montuculo
			*/
			Medicion top() = 0;

			/*!
			\brief     modificador del montuculo, inserta un elemento en el monticulo
			\note      Función virtual pura
			\post 	   isEmpry()==falso
			*/
			void insert() = 0;

			/*!
			\brief     modificador del monticulo, elimina el elemento de la cima del montuculo
			\note      Función virtual pura
			\pre 			 isEmpty()==falso
			*/
			void remove() = 0;
	}; // Clase MonticuloMedicionesInterfaz

} // Espacio de nombres ed

#endif //  _MONTICULO_MEDICIONES_INTERFAZ_HPP
