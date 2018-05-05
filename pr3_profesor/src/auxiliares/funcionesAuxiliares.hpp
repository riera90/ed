/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 3
  \author Diego Rodriguez Riera
  \date
*/

#ifndef _FuncionesAuxiliares_HPP_
#define _FuncionesAuxiliares_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "MonticuloMediciones.hpp"
#include "Medicion.hpp"
#include "macros.hpp"

namespace ed
{
	/*!
	\brief     modificador de carga de datos desde fichero de texto
	\param		 nombreFichero:(string) nombre del fichero de entrada
	\param		 monticulo: (MonticuloMedicione) monticulo donde deseamos cargar las mediciones
	*/
	void cargarMonticuloDeFichero(std::string const & nombreFichero, MonticuloMediciones & monticulo);

	/*!
	\brief     modificador de guardado de datos a fichero de texto
	\param		 nombreFichero:(string) nombre del fichero de salida
	\param		 monticulo: (MonticuloMedicione) monticulo el cual contiene los datos a guardar
	*/
	void grabarMonticuloEnFichero (std::string const & nombreFichero, ed::MonticuloMediciones const & monticulo);

} // Fin del espacio de nombre de la asignatura: ed



// Fin de _FuncionesAuxiliares_HPP_
#endif
