/*!
   \file operadoresExternosPolinomios.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "operadoresExternosPolinomios.hpp"

#include "operadoresExternosMonomios.hpp"

// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed
{

bool operator==(ed::Polinomio const & lhs, ed::Polinomio const & rhs)
{
	for (int i = 0; i < lhs.getGrado() || i < rhs.getGrado(); i++) {
		if ( lhs.existeMonomio(i) || rhs.existeMonomio(i) ){
			
			if ( !lhs.existeMonomio(i) || !rhs.existeMonomio(i) )
				return false;
				
			if ( lhs.getMonomio(i) != lhs.getMonomio(i) )
				return false;
		}
	}

	return true;
}


bool operator==(ed::Polinomio const & lhs, ed::Monomio const & rhs)
{
	if ( lhs.getNumeroMonomios() != 1 )
		return false;
	
	if ( lhs.getMonomio(rhs.getGrado()) != rhs )
		return false;

	return true;
}


bool operator==(ed::Monomio const & lhs, ed::Polinomio const & rhs)
{
	return rhs == lhs;
}


bool operator==(ed::Polinomio const & lhs, float const & rhs)
{
	if ( lhs.getNumeroMonomios() != 1 )
		return false;
	
	if ( lhs.getMonomio(0) != rhs )
		return false;

	return true;
}


bool operator==(float const & lhs, ed::Polinomio const & rhs)
{
	return rhs == lhs;
}





////////////////////////////////////////////////////////////////////////////////////
// Operadores de desigualdad
bool operator!=(ed::Polinomio const & lhs, ed::Polinomio const & rhs)
{
	return !(lhs == rhs);
}

bool operator!=(ed::Polinomio const & lhs, ed::Monomio const & rhs)
{
	return !(lhs == rhs);
}

bool operator!=(ed::Monomio const & lhs, ed::Polinomio const & rhs)
{
	return !(lhs == rhs);
}

bool operator!=(ed::Polinomio const & lhs, float const & rhs)
{
	return !(lhs == rhs);
}

bool operator!=(float const & lhs, ed::Polinomio const & rhs)
{
	return !(lhs == rhs);
}


// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD

//////////////////////////////////////////////////////////////////////////////////////

// Operadores unarios

// COMPLETAR
ed::Polinomio & operator+(ed::Polinomio const & p)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	// ed::Polinomio *nuevo = new ed::Polinomio(p);

	// Se devuelve el resultado
	// return *nuevo;
}


// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta


//////////////////////////////////////////////////////////////////////////////////////

// Operadores binarios de la suma
ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	ed::Polinomio *nuevo = new ed::Polinomio;

	// Se devuelve el resultado
	return *nuevo;
}

	// COMPLETAR LOS OTROS OPERADORES DE SUMA

	////////////
	// Resta

	// COMPLETAR


	//////////////////
	// Multiplicación

	// COMPLETAR

	////////////
	// División

	// COMPLETAR


////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, Polinomio &p)
{
	// COMPLETAR

	// Se devuelve el flujo de entrada
  return stream;
}



// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, Polinomio const &p)
{
	// COMPLETAR

	// Se devuelve el flujo de salida
  return stream;
}


} // Fin del espacio de nombres ed
