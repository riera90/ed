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
	fichero.open("./output/Palma_del_Rio.txt.csv");
	if (!fichero.is_open()) {
		std::cout << "el fichero no se pudo abrir" << '\n';
		return;
	}
	//TODO chech for error
	Medicion aux;
	aux.cargarMedicionDeFichero(fichero);
	aux.cargarMedicionDeFichero(fichero);

	// while(aux.getFecha().getFechaString()!="0-0-0"){
	// 	aux.escribirMedicion();
	// 	monticulo.insert(aux);
	// 	aux.cargarMedicionDeFichero(fichero);
	// }
	fichero.close();
	return;


	// char cache[1000];
	// fichero.getline(cache, 1000);
	// std::cout << "cache: <" <<cache << ">\n";
	// fichero.getline(cache, 1000);
	// std::cout << "cache: <" <<cache << ">\n";
	// fichero.getline(cache, 1000);
	// std::cout << "cache: <" <<cache << ">\n";
	// fichero.getline(cache, 1000);
	// std::cout << "cache: <" <<cache << ">\n";
}


void ed::grabarMonticuloEnFichero(std::string const & nombreFichero,
							      ed::MonticuloMediciones const & monticulo)
{
 std::cout << "SE DEBE CODIFICAR ESTA FUNCIÓN" << std::endl << std::endl;

	return;
}
