/*!
   \file PolinomioInterfaz.hpp
   \brief Definición de la interfaz de la clase Polinomio
*/

#ifndef _POLINOMIOINTERFAZ_HPP_
#define _POLINOMIOINTERFAZ_HPP_

#include "Monomio.hpp"

// Se incluye la clase PolinomioInterfaz dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase PolinomioInterfaz
class PolinomioInterfaz
{

   //! \name Funciones o métodos públicos de la clase
   public:

	//! \name Observadores: funciones de consulta

    virtual bool esNulo()const = 0;

    virtual int getGrado()const = 0;

    virtual int getNumeroMonomios()const = 0;

	virtual bool existeMonomio(int n)const = 0;

	virtual ed::Monomio & getMonomio(int n)const = 0;



}; // Fin de la definición de la clase PolinomioInterfaz


} // \brief Fin de namespace ed.

//  _POLINOMIOINTERFAZ_HPP_
#endif
