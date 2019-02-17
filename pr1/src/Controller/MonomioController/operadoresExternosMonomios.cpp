/*!
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed
{
	// Operadores de igualdad


	bool operator==(const ed::Monomio &lhs, const ed::Monomio &rhs)
	{
		if ( (lhs.getGrado() == rhs.getGrado()) && ed::near(lhs.getCoeficiente(), rhs.getCoeficiente()))
		return true;
		else return false;
	}

	bool operator==(const float &lhs, const ed::Monomio &rhs)
	{
		if ( (rhs.getGrado() == 0 ) && ed::near(lhs, rhs.getCoeficiente()))
		return true;
		else return false;
	}

	bool operator==(const ed::Monomio &lhs, const float &rhs)
	{
		if ( (lhs.getGrado() == 0 ) && ed::near(lhs.getCoeficiente(), rhs))
		return true;
		else return false;
	}



	// Operadores de desigualdad

	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		return m1 == m2 ? false:true;
	}

	bool operator!=(const float &lhs, const ed::Monomio &rhs)
	{
		return lhs == rhs ? false:true;
	}

	bool operator!=(const ed::Monomio &lhs, const float &rhs)
	{
		return lhs == rhs ? false:true;
	}


	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos

	ed::Monomio & operator+(ed::Monomio const & m)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio(m);

		// Se devuelve el resultado
		return *nuevo;
	}



	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &lhs, ed::Monomio const &rhs)
	{
		ed::Monomio *nuevo = new ed::Monomio(lhs);

		if (lhs.getGrado() != rhs.getGrado())
		return *nuevo;

		nuevo->setCoeficiente(lhs.getCoeficiente() + rhs.getCoeficiente());
		nuevo->setGrado(lhs.getGrado());

		return *nuevo;
	}


	////////////
	// Resta

	ed::Monomio &operator- (const ed::Monomio &rhs)
	{
		ed::Monomio *nuevo = new ed::Monomio(rhs);
		nuevo->setCoeficiente(-nuevo->getCoeficiente());
		return *nuevo;
	}

	ed::Monomio & operator- (ed::Monomio const &lhs, ed::Monomio const &rhs)
	{
		ed::Monomio *nuevo = new ed::Monomio(lhs);

		if (lhs.getGrado() != rhs.getGrado())
		return *nuevo;

		nuevo->setCoeficiente(lhs.getCoeficiente() - rhs.getCoeficiente());
		nuevo->setGrado(lhs.getGrado());

		return *nuevo;
	}

	//////////////////
	// Multiplicación

	ed::Monomio &operator* (const ed::Monomio &lhs, const ed::Monomio &rhs)
	{
		ed::Monomio *monomio = new ed::Monomio();

		monomio->setGrado(lhs.getGrado() + rhs.getGrado());
		monomio->setCoeficiente(lhs.getCoeficiente() * rhs.getCoeficiente());

		return *monomio;
	}

	ed::Monomio &operator* (const ed::Monomio &lhs, const float &rhs)
	{
		ed::Monomio *monomio = new ed::Monomio();

		monomio->setGrado(lhs.getGrado());
		monomio->setCoeficiente(lhs.getCoeficiente() * rhs);

		return *monomio;
	}


	ed::Monomio &operator* (const float &lhs, const ed::Monomio &rhs)
	{
		ed::Monomio *monomio = new ed::Monomio();

		monomio->setGrado(rhs.getGrado());
		monomio->setCoeficiente(lhs * rhs.getCoeficiente());

		return *monomio;
	}


	////////////
	// División

	ed::Monomio &operator/ (const ed::Monomio &lhs, const ed::Monomio &rhs)
	{
		ed::Monomio *monomio = new ed::Monomio();

		if (lhs.getGrado() < rhs.getGrado()) return *monomio;
		if ( 0 == rhs.getGrado()) return *monomio;

		monomio->setGrado(lhs.getGrado() - rhs.getGrado());
		monomio->setCoeficiente(lhs.getCoeficiente() / rhs.getCoeficiente());

		return *monomio;
	}


	ed::Monomio &operator/ (const ed::Monomio &lhs, const float &rhs)
	{
		ed::Monomio *monomio = new ed::Monomio();

		if ( rhs == 0 ) return *monomio;

		monomio->setGrado(lhs.getGrado());
		monomio->setCoeficiente(lhs.getCoeficiente() / rhs);

		return *monomio;
	}


	ed::Monomio &operator/ (const float &lhs, const ed::Monomio &rhs)
	{
		ed::Monomio *monomio = new ed::Monomio();

		if ( rhs.getCoeficiente() == 0 ) return *monomio;

		monomio->setGrado(0);
		monomio->setCoeficiente(lhs / rhs.getCoeficiente());

		return *monomio;
	}


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	std::istream &operator>>(std::istream &stream, ed::Monomio &m)
	{
		std::string aux;
		getline(stream, aux, ' ');
		m.setCoeficiente(atof(aux.c_str()));
		getline(stream, aux, '\n');
		m.setGrado(atoi(aux.c_str()));
		return stream;
	}


	//  Sobrecarga del operador de salida
	std::ostream &operator<<(std::ostream &stream, const ed::Monomio &m)
	{

		stream<<"Coeficiente: "<<m.getCoeficiente()<<", Grado: "<<m.getGrado();
		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
