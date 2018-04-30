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

	// void agnadirMedicion(MonticuloMediciones heap);
	// void modificarMedicion(MonticuloMediciones heap);
	// void cargarDesdeFichero(MonticuloMediciones heap);
	// void guardarEnFichero(MonticuloMediciones heap);
	// void borrarRaiz(MonticuloMediciones heap);
	// void borrarTodo(MonticuloMediciones heap);
	// void buscarMedicionPorFecha(MonticuloMediciones heap);
	// void imprimirMediciones(MonticuloMediciones heap);
	// void imprimirRaiz(MonticuloMediciones heap);
	// void getNumeroDeMediciones(MonticuloMediciones heap);

	// inline bool is_number(const std::string& s){
	// 	std::string::const_iterator it = s.begin();
	// 	while (it != s.end() && std::isdigit(*it)) ++it;
	// 	return !s.empty() && it == s.end();
	// }

} // Fin del espacio de nombre de la asignatura: ed


// Fin de _FuncionesAuxiliares_HPP_
#endif
