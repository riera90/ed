/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author
  \date
*/


#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Monomio.hpp"

namespace ed
{
	/*!
		\brief   Muestra el menú del programa principal
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	/*!
		\brief   Hace el test del monomio
	*/
	void testMonomio();

	/*!
		\brief   Hace el test de los operadores externos del monimio
	*/
	void operadoresExternosMonomios();

	/*!
		\brief   introduce los datos del monomio
	*/
	void introducirDatos(ed::Monomio &m);

	/*!
		\brief   hace plot del momomio
	*/
	void plotMonomio(ed::Monomio &m);

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif
