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

Medicion::Medicion(Fecha fecha, float precipitacion){
	setFecha(fecha);
	setPrecipitacion(precipitacion);
	setTemperaturaMaxima(0);
	setHoraTemperaturaMaxima("nval");
	setTemperaturaMinima(0);
	setHoraTemperaturaMinima("nval");
	setTemperaturaMedia(0);
	setHumedadRelativaMaxima(0);
	setHumedadRelativaMinima(0);
	setHumedaRelativaMedia(0);
	setVelocidadVientoMedia(0);
	setDireccionVientoMedia(0);
	setRadiacionSolar(0);
	setEto(0);
}

void Medicion::leerMedicion(){
		std::cout << "Introduzca la medicion con el siguiente formato:\n\tdia-mes-año precipitación\n\t->";
		int dia, mes, ano;
		float precipitacion;
		std::string cache;
		std::getline(std::cin, cache, '-');
		dia=atoi(cache.c_str());
		std::getline(std::cin, cache, '-');
		mes=atoi(cache.c_str());
		std::getline(std::cin, cache, ' ');
		ano=atoi(cache.c_str());
		Fecha fecha(dia,mes,ano);
		std::getline(std::cin, cache, '\n');
		precipitacion=atof(cache.c_str());
		if (std::cin.fail()) {
			std::cout<<"Introduzca valores validos.\n";
		}else{
			ed::Fecha fecha(dia,mes,ano);
			if (!fecha.esCorrecta()) {
				std::cout<<"Introduzca una fecha válida.\n";
			}else{
				if (precipitacion<0){
					std::cout <<"Introduzca una precipitacion valida,\n\t(no se cuenta la evaporacion)\n";
				}else{
					if (0) {//exists TODO
						std::cout <<"medicion ya registrada\n";
					}else{
						this->setFecha(ed::Fecha(dia,mes,ano));
						this->setPrecipitacion(precipitacion);
						std::cout << "Medicion leida correctamente!" << '\n';
					}
				}
			}
		}
	}

void Medicion::escribirMedicion() const {
	std::cout << "\t";
	std::cout << this->getFecha().getFechaString();
	std::cout << " ";
	std::cout << this->getPrecipitacion();
	std::cout << "\n";
}

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
