/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"
#include "operadoresExternosPolinomios.hpp"


ed::Polinomio::Polinomio()
{
	// nothing to do beocuse the vector is already empty on creation.
}

ed::Polinomio::Polinomio(const Polinomio &polinomio)
{
	for (int i = 0, n = 0; n < polinomio.getNumeroMonomios(); i++) {
		if (polinomio.existeMonomio(i)){
			this->monomios_.push_back(polinomio.getMonomio(i));
			n++;
		}
	}
}

ed::Polinomio::Polinomio(const Monomio &monomio)
{
	this->addMonomio(monomio);
}


bool ed::Polinomio::esNulo() const
{
	if ( this->monomios_.empty() )
		return true;
	
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
				if ( this->monomios_[i].getCoeficiente() == 0 ){ // if its null it deletes the nomomio
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

ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &rhs)
{
	(*this) = (*this) + rhs;
	return *this;
}


ed::Polinomio & ed::Polinomio::operator+=(ed::Monomio const &rhs)
{
	(*this) = (*this) + rhs;
	return *this;
}


ed::Polinomio & ed::Polinomio::operator+=(float const &rhs)
{
	(*this) = (*this) + rhs;
	return *this;
}


ed::Polinomio & ed::Polinomio::operator-=(ed::Polinomio const &rhs)
{
	(*this) = (*this) - rhs;
	return *this;
}


ed::Polinomio & ed::Polinomio::operator-=(ed::Monomio const &rhs)
{
	(*this) = (*this) - rhs;
	return *this;
}


ed::Polinomio & ed::Polinomio::operator-=(float const &rhs)
{
	(*this) = (*this) - rhs;
	return *this;
}


ed::Polinomio & ed::Polinomio::operator*=(ed::Polinomio const &rhs)
{
	(*this) = (*this) * rhs;
	return *this;
}


ed::Polinomio & ed::Polinomio::operator*=(ed::Monomio const &rhs)
{
	(*this) = (*this) * rhs;
	return *this;
}


ed::Polinomio & ed::Polinomio::operator*=(float const &rhs)
{
	(*this) = (*this) * rhs;
	return *this;
}


ed::Polinomio & ed::Polinomio::operator/=(ed::Polinomio const &rhs)
{
	(*this) = (*this) / rhs;
	return *this;
}


ed::Polinomio & ed::Polinomio::operator/=(ed::Monomio const &rhs)
{
	(*this) = (*this) / rhs;
	return *this;
}


ed::Polinomio & ed::Polinomio::operator/=(float const &rhs)
{
	(*this) = (*this) / rhs;
	return *this;
}



void ed::Polinomio::leerPolinomio()
{
	std::cout << "de que grado es el polinomio? : ";
	std::string grado_max;
	std::cin >> grado_max;
	while ( !ed::isInt(grado_max) ){
		std::cout << "introduzca un grado válido" << '\n';
		std::cout << "de que grado es el polinomio? : ";
		std::cin >> grado_max;
	}
	
	std::string coeficiente;
	
	for (size_t i = 0; i <= ed::stoi(grado_max); i++) {
		std::cout << "introduzca el coeficiente polinomio de grado " << i << " : ";
		std::cin >> coeficiente;
		while ( !ed::isFloat(coeficiente) ){
			std::cout << "introduzca un coeficiente válido" << '\n';
			std::cout << "introduzca el coeficiente polinomio de grado " << i << " : ";
			std::cin >> coeficiente;
		}
		this->addMonomio(Monomio(ed::stoi(coeficiente), i));
		std::cout << "polinomio actual : "<< *this<< "\n";
	}
	
	std::cout << "\n\tpolinomio creado : ";
	this->escribirPolinomio();
	std::cout << '\n';
}


void ed::Polinomio::escribirPolinomio() const
{
	bool first = true;
	for (int i = 0; i <= this->getGrado(); i++) {
		if (this->existeMonomio(i)) {
			if (!first)
				std::cout << " + " << this->getMonomio(i);
			else{
				first = false;
				std::cout <<this->getMonomio(i);
			}
		}
	}
}


float ed::Polinomio::calcularValor(float x) const
{
	float retval = 0;
	for (int i = this->getGrado(); i >= 0; i--) {
		if (this->existeMonomio(i))
			retval += this->getMonomio(i).calcularValor(x);
	}
	
	return retval;
}


void ed::Polinomio::plot(int min_x, int max_x) const
{
    if (max_x <= min_x)
        return;
        
    float divisions = ((float)max_x - (float)min_x) / 500;
    std::ofstream plot;
    plot.open("./output/plot.dat");
    for (float x = min_x; x < max_x; x += divisions) {
        plot<<x<<" "<<this->calcularValor(x)<<"\n";
    }
    plot.close();

    system("gnuplot -e \"set xlabel 'x'; set ylabel 'y'; set title 'Polinomio'; plot 'output/plot.dat' with lines;\" -p");
}




