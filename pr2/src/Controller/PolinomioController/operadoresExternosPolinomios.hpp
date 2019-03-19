/*!
    \file operadoresExternosPolinomios.hpp
    \brief Ficheros con operadores de monomios y polinomios
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

////////////////////////////////////////////////////////////////////////////
    // Funciones y operadores que no pertenecen a la clase Polinomio


    ////////////////////////////////////////////////////////////
    //! \name Operadores de igualdad
    bool operator==(ed::Polinomio const & lhs, ed::Polinomio const & rhs);
    bool operator==(ed::Polinomio const & lhs, ed::Monomio const & rhs);
    bool operator==(ed::Monomio const & lhs, ed::Polinomio const & rhs);
    bool operator==(ed::Polinomio const & lhs, float const & rhs);
    bool operator==(float const & lhs, ed::Polinomio const & rhs);

    ////////////////////////////////////////////////////////////////////////////////////
    //! \name Operadores de desigualdad
    bool operator!=(ed::Polinomio const & lhs, ed::Polinomio const & rhs);
    bool operator!=(ed::Polinomio const & lhs, ed::Monomio const & rhs);
    bool operator!=(ed::Monomio const & lhs, ed::Polinomio const & rhs);
    bool operator!=(ed::Polinomio const & lhs, float const & rhs);
    bool operator!=(float const & lhs, ed::Polinomio const & rhs);

//////////////////////////////////////////////////////////////////////////////////////

    //! \name Operadores unarios
    ed::Polinomio & operator+(ed::Polinomio const & p);
    ed::Polinomio & operator-(ed::Polinomio const & p);


//////////////////////////////////////////////////////////////////////////////////////

    //! \name Operadores binarios de la suma

    // COMPLETAR LOS COMENTARIOS DE DOXYGEN
    ed::Polinomio & operator+(ed::Polinomio const &lhr,  ed::Polinomio const &rhs);

    // COMPLETAR LOS OTROS OPERADORES DE SUMA


    //////////////////////////////////////////////////////////
    //! \name Operador binario de la resta

    // COMPLETAR
    ed::Polinomio & operator-(ed::Polinomio const &lhr,  ed::Polinomio const &rhs);
    


    ///////////////////////////////////////////////////////////////////////////
    //! \name Operadores binarios de la multiplicación

    // COMPLETAR

    ///////////////////////////////////////////////////////////////////////////

    //! \name Operadores binarios de la división

    // COMPLETAR

    /////////////////////////////////////////////////////////////////////////////

    //! \name Sobrecarga de los operadores de flujo de la clase Polinomio.

    // COMPLETAR LOS COMENTARIOS DE DOXYGEN
    ostream &operator<<(ostream &stream, ed::Polinomio const &p);

    // COMPLETAR LOS COMENTARIOS DE DOXYGEN
    istream &operator>>(istream &stream, ed::Polinomio &p);

}  // Fin de namespace ed.

#endif // _OperadoresPolinomios_HPP_
