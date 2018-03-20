/*!
   \file Municipio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Municipio
*/


// Ficheros de cabecera
#include <iostream>
#include <string>

#include <stdlib.h>

#include "Municipio.hpp"


/*
 Definiciones de las funciones lectura y escritura de la clase Municipio
*/

void Municipio::read_Municipio(){
  int  n;
  std::string cadena;

  std::cout << "\n Lectura de los datos de un municipio" << std::endl;

  std::cout << " Nombre --> ";
  // Uso de getline para leer nombres compuestos separados por espacios
  std::getline(std::cin,cadena);
  this->set_name(cadena);

  std::cout << " Código postal --> ";
  std::cin >> n;
  // Se elimna el salto de línea
  std::cin.ignore();
  //
  this->set_postal_code(n);

  std::cout << " Número total de hombres --> ";
  std::cin >> n;
  // Se elimna el salto de línea
  std::cin.ignore();
  //
  this->set_mens(n);

  std::cout << " Número total de mujeres --> ";
  std::cin >> n;
  // Se elimna el salto de línea
  std::cin.ignore();
  //
  this->set_womens(n);

}


void Municipio::write_Municipio() const{
/*
  std::cout  << "Código postal: "  << this->get_postal_code() << std::endl;
  std::cout  << "Nombre: "   << this->get_name() << std::endl;
  std::cout  << "Habitantes: "  << this->getHabitantes() << std::endl;
  std::cout  << "Hombres: " 	<< this->get_mens() << std::endl;
  std::cout  << "Mujeres: " 	<< this->get_womens() << std::endl << std::endl;
*/

  std::cout  << this->get_postal_code();
  std::cout  << "\t";
  std::cout  << this->get_name();
  std::cout  << "\t\t";
  std::cout  << this->get_mens();
  std::cout  << "\t";
  std::cout  << this->get_womens();
  std::cout  << "\t";
  std::cout  << this->get_habitants() << std::endl;


}

////////////////////////////////////////////////////////////////////////////////

bool compare_haitants (Municipio const &objeto1, Municipio const &objeto2){
   	return (   objeto1.get_mens() + objeto1.get_womens()
             < objeto2.get_mens() + objeto2.get_womens() );
}


// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, Municipio const & objeto)
{
  // Se escriben los datos teniendo en cuenta el formato: CP Nombre; hombres; mujeres;
  stream << objeto.get_postal_code();
  stream << " ";
  stream << objeto.get_name();
  stream << ";";
  stream << objeto.get_mens();
  stream << ";";
  stream << objeto.get_womens();
  stream << ";";

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, Municipio & objeto){
 	// Se leen los datos teniendo en cuenta el formato: CP Nombre; hombres; mujeres;
  std::string cadena;

  std::getline(stream,cadena,' ');
  objeto.set_postal_code(atoi(cadena.c_str()));

  std::getline(stream,cadena,';');
  objeto.set_name(cadena.c_str());

  std::getline(stream,cadena,';');
  objeto.set_mens(atoi(cadena.c_str()));

  std::getline(stream,cadena,';');
  objeto.set_womens(atoi(cadena.c_str()));

  return stream;
}
