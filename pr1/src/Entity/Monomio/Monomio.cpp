/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"
#include "auxiliarFunctions.hpp"



ed::Monomio::Monomio(float coeficiente, int grado)
{
	if (grado < 0) this->grado_ = 0;
	else this->grado_ = grado;

	this->coeficiente_ = coeficiente;
}

ed::Monomio::Monomio(const ed::Monomio &monomio)
{
	(*this) = monomio;
}


float ed::Monomio::getCoeficiente() const
{
	return this->coeficiente_;
}

int ed::Monomio::getGrado() const
{
	return this->grado_;
}


bool ed::Monomio::setCoeficiente(float coeficiente)
{
	this->coeficiente_ = coeficiente;
	return true;
}

bool ed::Monomio::setGrado(int grado)
{
	if (grado < 0) return false;

	this->grado_ = grado;
	return true;
}


// Operadores de asignación

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	/* The object is in a stable state, so no need to check fot out
	 * of range values or anything similar.
	 */
	this->coeficiente_ = m.getCoeficiente();
	this->grado_ = m.getGrado();

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x)
{
	this->grado_ = 0;
	this->coeficiente_ = x;

	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m)
{
	if (this->getGrado() != m.getGrado()) return *this;

	this->setCoeficiente(this->getCoeficiente() + m.getCoeficiente());

	// Se devuelve el objeto actual
	return *this;
}



ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m)
{
	if (this->getGrado() != m.getGrado()) return *this;

	this->setCoeficiente(this->getCoeficiente() - m.getCoeficiente());

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator*=(const ed::Monomio &rhs)
{
	if (this->getGrado() < rhs.getGrado()) return *this;
	if (rhs.getCoeficiente() == 0) return *this;

	this->setCoeficiente(this->getCoeficiente() * rhs.getCoeficiente());
	this->setGrado(this->getGrado() + rhs.getGrado());

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator*=(const float &rhs)
{
	if (rhs == 0) return *this;

	this->setCoeficiente(this->getCoeficiente() * rhs);

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator/=(const ed::Monomio &rhs)
{
	if (this->getGrado() < rhs.getGrado()) return *this;
	if (rhs.getCoeficiente() == 0) return *this;

	this->setCoeficiente(this->getCoeficiente() - rhs.getCoeficiente());
	this->setGrado(this->getGrado() + rhs.getGrado());

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator/=(const float &rhs)
{
	if (rhs == 0) return *this;

	this->setCoeficiente(this->getCoeficiente() / rhs);

	// Se devuelve el objeto actual
	return *this;
}




///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

void ed::Monomio::leerMonomio()
{
	/* This funciton loops untill the user uses a valid input
	 */
	std::string aux;
	std::cout << "por favor introduzca el coeficiente del monomio: ";
	std::cin >> aux;
	std::cin.ignore();
	while (!ed::isInt(aux)){
		std::cout << "introduzca un coeficiente valido:";
		std::cin.ignore();
		std::cin >> aux;
	}
	this->setCoeficiente(atof(aux.c_str()));

	std::cout << "por favor introduzca el grado del monomio: ";
	std::cin >> aux;
	std::cin.ignore();
	while (!ed::isFloat(aux)){
		std::cout << "introduzca un coeficiente valido:";
		std::cin.ignore();
		std::cin >> aux;
	}
	this->setGrado(atoi(aux.c_str()));

}

void ed::Monomio::escribirMonomio() const
{
	std::cout<<"Coeficiente: "<<this->getCoeficiente()<<", Grado: "<<this->getGrado()<<'\n';
}


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

float ed::Monomio::calcularValor(float x) const
{
	return pow(this->getCoeficiente() * x, this->getGrado());
}
