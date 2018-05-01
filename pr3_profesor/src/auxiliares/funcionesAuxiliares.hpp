/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 3
  \author
  \date
*/

#ifndef _FuncionesAuxiliares_HPP_
#define _FuncionesAuxiliares_HPP_

#include <iostream>
#include <fstream>
#include <string>

#include "MonticuloMediciones.hpp"
#include "Medicion.hpp"
#include "macros.hpp"

namespace ed
{
	void cargarMonticuloDeFichero(std::string const & nombreFichero, MonticuloMediciones & monticulo);


	void grabarMonticuloEnFichero (std::string const & nombreFichero, ed::MonticuloMediciones const & monticulo);

} // Fin del espacio de nombre de la asignatura: ed



// Fin de _FuncionesAuxiliares_HPP_
#endif
