/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author
  \date
*/


#include <iostream>

#include <fstream>

#include <string>

#include "funcionesAuxiliares.hpp"

#include "MonticuloMediciones.hpp"

#include "Medicion.hpp"

#include "macros.hpp"

void ed::cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo)
{
	std::ifstream fichero;
	fichero.open(nombreFichero.c_str());
	std::string line;
	std::getline(fichero,line);
	std::getline(fichero,line);
	ed::Medicion aux;
	while (fichero>>aux)
		monticulo.insert(aux);
	return;
}


void ed::grabarMonticuloEnFichero(std::string const & nombreFichero,
							      ed::MonticuloMediciones const & monticulo)
{
 std::cout << "SE DEBE CODIFICAR ESTA FUNCIÓN" << std::endl << std::endl;

	return;
}
