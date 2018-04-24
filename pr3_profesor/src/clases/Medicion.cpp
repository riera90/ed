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
	setHumedaddRelativaMaxima(0);
	setHumedaddRelativaMinima(0);
	setHumedadRelativaMedia(0);
	setVelocidadVientoMedia(0);
	setDireccionVientoMedia(0);
	setRadiacionSolar(0);
	setEto(0);
	setValid(false);
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

void Medicion::escribirMedicion() {
	std::cout<<"\t ";
	std::cout<<getFecha()<<",";
	std::cout<<getTemperaturaMaxima()<<",";
	std::cout<<getHoraTemperaturaMaxima()<<",";
	std::cout<<getTemperaturaMinima()<<",";
	std::cout<<getHoraTemperaturaMinima()<<",";
	std::cout<<getTemperaturaMedia()<<",";
	std::cout<<getHumedaddRelativaMaxima()<<",";
	std::cout<<getHumedaddRelativaMinima()<<",";
	std::cout<<getHumedadRelativaMedia()<<",";
	std::cout<<getVelocidadVientoMedia()<<",";
	std::cout<<getDireccionVientoMedia()<<",";
	std::cout<<getRadiacionSolar()<<",";
	std::cout<<getPrecipitacion()<<",";
	std::cout<<getEto()<<"\n";
}

void Medicion::cargarMedicionDeFichero(std::istream &stream){
	Medicion medicion;
	char cache_char[1000];
	stream.getline(cache_char, 10000, '\n');
	std::string all_cache=cache_char;
	std::cout << "cache:" <<all_cache<< '\n';


	// -
	// int dia=atoi(cache);
	// -
	// int mes=atoi(cache);
	// -
	// int ano=atoi(cache);
	// Fecha fecha(dia,mes,ano);
	// this->setFecha(fecha);
	// +
	// +
	// this->setTemperaturaMaxima(atof(cache));
	// +
	// this->setHoraTemperaturaMaxima(cache);
	// +
	// this->setTemperaturaMinima(atof(cache));
	// +
	// this->setHoraTemperaturaMinima(cache);
	// +
	// this->setTemperaturaMedia(atof(cache));
	// +
	// this->setHumedaddRelativaMaxima(atof(cache));
	// +
	// this->setHumedaddRelativaMinima(atof(cache));
	// +
	// this->setHumedadRelativaMedia(atof(cache));
	// +
	// this->setVelocidadVientoMedia(atof(cache));
	// +
	// this->setDireccionVientoMedia(atof(cache));
	// +
	// this->setRadiacionSolar(atof(cache));
	// +
	// this->setPrecipitacion(atof(cache));
	// +
	// this->setEto(atof(cache));


	this->setValid(true);
}




// Sobrecarga del operador de salida
std::ostream &operator<<(std::ostream &stream, Medicion const &medicion)
{
	stream << medicion.getFecha().getFechaString();
	stream << " ";
	stream << medicion.getPrecipitacion();
	stream << "\n";

  return stream;
}

// Sobrecarga del operador de entrada
std::istream &operator>>(std::istream &stream, Medicion &medicion)
{
	std::string cache;
	std::getline(stream, cache, '-');
	int dia=atoi(cache.c_str());
	std::getline(stream, cache, '-');
	int mes=atoi(cache.c_str());
	std::getline(stream, cache, '-');
	int ano=atoi(cache.c_str());
	Fecha fecha(dia,mes,ano);
	std::cout <<fecha.getFechaString()<< '\n';
	medicion.setFecha(fecha);
	std::getline(stream, cache, ';');
	std::getline(stream, cache, ';');
	medicion.setTemperaturaMaxima(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setHoraTemperaturaMaxima(cache.c_str());
	std::getline(stream, cache, ';');
	medicion.setTemperaturaMinima(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setHoraTemperaturaMinima(cache.c_str());
	std::getline(stream, cache, ';');
	medicion.setTemperaturaMedia(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setHumedaddRelativaMaxima(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setHumedaddRelativaMinima(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setHumedadRelativaMedia(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setVelocidadVientoMedia(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setDireccionVientoMedia(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setRadiacionSolar(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setPrecipitacion(atof(cache.c_str()));
	std::getline(stream, cache, '\n');
	medicion.setEto(atof(cache.c_str()));
	medicion.setValid(true);

  return stream;
}

} // Fin del espacio de nombres ed
