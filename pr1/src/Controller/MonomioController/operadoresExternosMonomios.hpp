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

	bool operator==(const ed::Monomio &lhs, const ed::Monomio &rhs);

	bool operator==(const float &lhs, const ed::Monomio &rhs);

	bool operator==(const ed::Monomio &lhs, const float &rhs);




	//! \name Operadores de desigualdad

	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

	bool operator!=(const float &lhs, const ed::Monomio &rhs);

	bool operator!=(const ed::Monomio &lhs, const float &rhs);

	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos


	ed::Monomio &operator+(ed::Monomio const & m);



	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma

	 ed::Monomio &operator+ (ed::Monomio const &lhs, ed::Monomio const &rhs);


	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta

	ed::Monomio &operator- (const ed::Monomio &rhs);

	ed::Monomio &operator- (ed::Monomio const &lhs, ed::Monomio const &rhs);


	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación

	ed::Monomio &operator* (const ed::Monomio &lhs, const ed::Monomio &rhs);

	ed::Monomio &operator* (const ed::Monomio &lhs, const float &rhs);

	ed::Monomio &operator* (const float &lhs, const ed::Monomio &rhs);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división

	ed::Monomio &operator/ (const ed::Monomio &lhs, const ed::Monomio &rhs);

	ed::Monomio &operator/ (const ed::Monomio &lhs, const float &rhs);

	ed::Monomio &operator/ (const float &lhs, const ed::Monomio &rhs);


	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida

	istream &operator>>(istream &stream, ed::Monomio &m);

	ostream &operator<<(ostream &stream, const ed::Monomio &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_
