/*!
   \file  Medicion.cpp
   \brief Fichero que contiene el código de las funciones de la clase Medicion
*/


// Ficheros de cabecera
#include <iostream>

// atoi, atof
#include <stdlib.h>

#include "Medicion.hpp"


// COMPLETAR


////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, ed::Medicion const &medicion)
{
	stream << medicion.getFecha().getFechaString();
	stream << " ";
	stream << medicion.getPrecipitacion();
	stream << "\n";

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Medicion &medicion)
{
	std::string cache;
	std::getline(stream, cache, '-');
	int dia=atoi(cache.c_str());
	std::getline(stream, cache, '-');
	int mes=atoi(cache.c_str());
	std::getline(stream, cache, ' ');
	int ano=atoi(cache.c_str());
	Fecha fecha(dia,mes,ano);
	std::getline(stream, cache, '\n');

  return stream;
}

} // Fin del espacio de nombres ed
