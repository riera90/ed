/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"

ed::Polinomio::Polinomio()
{
	
}

ed::Polinomio::Polinomio(const Polinomio &polinomio)
{
	for (int i = 0; i < polinomio.getGrado(); i++) {
		if ( polinomio.existeMonomio(i) ){
			this->monomios_.push_back(polinomio.getMonomio(i));
		}
	}
}


bool ed::Polinomio::esNulo() const
{
	if ( this->monomios_.empty() ) return true;
	
	for (size_t i = 0; i < this->monomios_.size(); i++) {
		if ( !this->monomios_[i].esNulo() )
			return false;
	}
	return true;
}


int ed::Polinomio::getGrado() const
{
	int gradoMax = 0;
	for (size_t i = 0; i < this->monomios_.size(); i++) {
		if ( monomios_[i].getGrado() > gradoMax )
			gradoMax = this->monomios_[i].getGrado();
	}
	return gradoMax;
}


int ed::Polinomio::getNumeroMonomios() const
{
	return this->monomios_.size();
}


bool ed::Polinomio::existeMonomio(int grado) const
{
	for (size_t i = 0; i < this->monomios_.size(); i++) {
		if ( this->monomios_[i].getGrado() == grado )
			return true;
	}
	return false;
}


ed::Monomio& ed::Polinomio::getMonomio(int grado) const
{
	for (size_t i = 0; i < this->monomios_.size(); i++) {
		if ( this->monomios_[i].getGrado() == grado ){
			return *new ed::Monomio(this->monomios_[i]);
		}
	}
	return *new ed::Monomio();
}


void ed::Polinomio::addMonomio(ed::Monomio monomio){
	if ( this->existeMonomio(monomio.getGrado()) ){
		for (int i = 0; i < this->monomios_.size(); i++) {
			if ( this->monomios_[i].getGrado() == monomio.getGrado() ){
				this->monomios_[i] = this->monomios_[i] + monomio;
				if (this->monomios_[i].esCero()){ // if its null it deletes the nomomio
					this->monomios_.erase(monomios_.begin() + i);
				}
				return;
			}
		}
	}
	else{
		this->monomios_.push_back(monomio);
	}
}

// Operadores de asignación

// COMPLETAR


/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p)
{
	this->monomios_.clear();

	for (int i = 0, n = 0; n < p.getNumeroMonomios(); i++) {
        if (p.existeMonomio(i)){
            this->addMonomio(p.getMonomio(i));
            n++;
        }
    }
	
	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	this->monomios_.clear();
	
	this->monomios_.push_back(m);

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{
	this->monomios_.clear();
	
	ed::Monomio m = x;
	
	this->monomios_.push_back(m);

	// Se devuelve el objeto actual
	return *this;
}

//////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}

// COMPLETAR EL RESTO DE OPERADORES



///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

// COMPLETAR


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

// COMPLETAR
