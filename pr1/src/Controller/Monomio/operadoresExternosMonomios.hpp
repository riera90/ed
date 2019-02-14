/*!
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"
#include "auxiliarFunctions.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;



// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	bool operator==(const ed::Monomio &lhs, const ed::Monomio &rhs);


	// COMPLETAR LOS OTROS OPERADORES DE IGUALDAD


	//! \name Operadores de desigualdad

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

	// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD

	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN

	ed::Monomio &operator+(ed::Monomio const & m);

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta


	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 ed::Monomio &operator+ (ed::Monomio const &lhs, ed::Monomio const &rhs);


	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta

	ed::Monomio &operator- (const ed::Monomio &rhs);

	ed::Monomio &operator- (ed::Monomio const &lhs, ed::Monomio const &rhs);


	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación

	ed::Monomio &operator* (const ed::Monomio &lhs, const ed::Monomio &rhs);

	ed::Monomio &operator* (const ed::Monomio &lhs, const int &rhs);

	ed::Monomio &operator* (const int &lhs, const ed::Monomio &rhs);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división

	ed::Monomio &operator/ (const ed::Monomio &lhs, const ed::Monomio &rhs);

	ed::Monomio &operator/ (const ed::Monomio &lhs, const int &rhs);

	ed::Monomio &operator/ (const int &lhs, const ed::Monomio &rhs);


	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 istream &operator>>(istream &stream, ed::Monomio &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_
