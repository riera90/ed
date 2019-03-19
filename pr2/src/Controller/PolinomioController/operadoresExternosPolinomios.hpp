/*!
    \file operadoresExternosPolinomios.hpp
    \brief Ficheros con operadores externos de monomios y polinomios
*/

#ifndef _OperadoresPolinomios_HPP_
#define _OperadoresPolinomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Polinomio.hpp"

using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{

      //////////////////////////////////////////////////////////////////////////
    //! \name Operadores de igualdad
    bool operator==(Polinomio const & lhs, Polinomio const & rhs);
    bool operator==(Polinomio const & lhs, Monomio const & rhs);
    bool operator==(Monomio const & lhs, Polinomio const & rhs);
    bool operator==(Polinomio const & lhs, float const & rhs);
    bool operator==(float const & lhs, Polinomio const & rhs);

      //////////////////////////////////////////////////////////////////////////
    //! \name Operadores de desigualdad
    bool operator!=(Polinomio const & lhs, Polinomio const & rhs);
    bool operator!=(Polinomio const & lhs, Monomio const & rhs);
    bool operator!=(Monomio const & lhs, Polinomio const & rhs);
    bool operator!=(Polinomio const & lhs, float const & rhs);
    bool operator!=(float const & lhs, Polinomio const & rhs);

      //////////////////////////////////////////////////////////////////////////
    //! \name Operadores unarios
    Polinomio & operator+(Polinomio const & p);
    Polinomio & operator-(Polinomio const & p);


      //////////////////////////////////////////////////////////////////////////
    //! \name Operadores binarios de la suma

    Polinomio & operator+(Polinomio const &lhr, Polinomio const &rhs);
    Polinomio & operator+(Polinomio const &lhs, Monomio const &rhs);
    Polinomio & operator+(Monomio const &lhs, Polinomio const &rhs);
    Polinomio & operator+(Polinomio const &lhs, float const &rhs);
    Polinomio & operator+(float const &lhs, Polinomio const &rhs);


      //////////////////////////////////////////////////////////
    //! \name Operador binario de la resta
    Polinomio & operator-(Polinomio const &lhr, Polinomio const &rhs);
    Polinomio & operator-(Polinomio const &lhs, Monomio const &rhs);
    Polinomio & operator-(Monomio const &lhs, Polinomio const &rhs);
    Polinomio & operator-(Polinomio const &lhs, float const &rhs);
    Polinomio & operator-(float const &lhs, Polinomio const &rhs);
    


      //////////////////////////////////////////////////////////////////////////
    //! \name Operadores binarios de la multiplicación


      //////////////////////////////////////////////////////////////////////////
    //! \name Operadores binarios de la división


      //////////////////////////////////////////////////////////////////////////
    //! \name Sobrecarga de los operadores de flujo de la clase Polinomio.
    ostream &operator<<(ostream &stream, Polinomio const &p);
    istream &operator>>(istream &stream, Polinomio &p);

}  // Fin de namespace ed.

#endif // _OperadoresPolinomios_HPP_
