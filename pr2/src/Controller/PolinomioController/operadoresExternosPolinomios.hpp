/*!
    \file operadoresExternosPolinomios.hpp
    \brief Ficheros con operadores externos de monomios y polinomios
*/

#ifndef _OperadoresPolinomios_HPP_
#define _OperadoresPolinomios_HPP_

// Facilita la entrada y salida
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include "Polinomio.hpp"

using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{

      //////////////////////////////////////////////////////////////////////////
    //! \name Operadores de igualdad
    /**
     * \brief operador lógico de igualdad de la clase Monomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \retval boolenano: verdadero si los dos Polinomios son iguales monomio a monomio, falso en quialquier ostro caso
     */
    bool operator==(Polinomio const & lhs, Polinomio const & rhs);
    
    /**
     * \brief operador lógico de igualdad de la clase Monomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Monomio rhs: Monomio de la parte derecha del operador
     * \retval boolenano: verdadero si el Monomio es igual al Polinomio, falso en quialquier ostro caso
     */
    bool operator==(Polinomio const & lhs, Monomio const & rhs);
    
    /**
     * \brief operador lógico de igualdad de la clase Monomio
     * \param Monomio lhs: Monomio de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \retval boolenano: verdadero si el Monomio es igual al Polinomio, falso en quialquier ostro caso
     */
    bool operator==(Monomio const & lhs, Polinomio const & rhs);
    
    /**
     * \brief operador lógico de igualdad de la clase Monomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Real rhs: numero de la parte derecha del operador
     * \retval boolenano: verdadero si el polinomio es rhs*x^0, falso en quialquier ostro caso
     */
    bool operator==(Polinomio const & lhs, float const & rhs);
    
    /**
     * \brief operador lógico de igualdad de la clase Monomio
     * \param Real lhs: Real de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \retval boolenano: verdadero si el polinomio es lhs*x^0, falso en quialquier ostro caso
     */
    bool operator==(float const & lhs, Polinomio const & rhs);

      //////////////////////////////////////////////////////////////////////////
    //! \name Operadores de desigualdad
    /**
     * \brief operador lógico de desigualdad de la clase Monomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \retval boolenano: falso si los dos Polinomios son iguales monomio a monomio, verdadero en quialquier ostro caso
     */
    bool operator!=(Polinomio const & lhs, Polinomio const & rhs);
    
    /**
     * \brief operador lógico de desigualdad de la clase Monomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Monomio rhs: Monomio de la parte derecha del operador
     * \retval boolenano: falso si el Monomio es igual al Polinomio, verdadero en quialquier ostro caso
     */
    bool operator!=(Polinomio const & lhs, Monomio const & rhs);
    
    /**
     * \brief operador lógico de desigualdad de la clase Monomio
     * \param Monomio lhs: Monomio de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \retval boolenano: falso si el Monomio es igual al Polinomio, verdadero en quialquier ostro caso
     */
    bool operator!=(Monomio const & lhs, Polinomio const & rhs);
    
    /**
     * \brief operador lógico de desigualdad de la clase Monomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Real rhs: numero de la parte derecha del operador
     * \retval boolenano: falso si el polinomio es rhs*x^0, verdadero en quialquier ostro caso
     */
    bool operator!=(Polinomio const & lhs, float const & rhs);
    
    /**
     * \brief operador lógico de desigualdad de la clase Monomio
     * \param Real lhs: Real de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \retval boolenano: falso si el polinomio es lhs*x^0, verdadero en quialquier ostro caso
     */
    bool operator!=(float const & lhs, Polinomio const & rhs);

      //////////////////////////////////////////////////////////////////////////
    //! \name Operadores unarios
    /**
     * \brief operador aritmetico de copia
     * \param Polinomio p: Polinomio a copiar
     * \retval Polinomio: copia del Polinomio por referencia
     */
    Polinomio & operator+(Polinomio const & p);
    
    /**
     * \brief operador aritmetico de copia e inversion de signo del coeficiente
     * \param Polinomio p: Polinomio a copiar
     * \retval Polinomio: copia del Polinomio por referencia con el coeficiente invertido en su signo en todos sus monomios
     */
    Polinomio & operator-(Polinomio const & p);


      //////////////////////////////////////////////////////////////////////////
    //! \name Operadores binarios de la suma
    /**
     * \brief operador aritmetico de suma de la clase Polinomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \retval Polinomio: suma de los dos Polinomio (suma de monomios)
     */
    Polinomio & operator+(Polinomio const &lhs, Polinomio const &rhs);
    /**
     * \brief operador aritmetico de suma de la clase Polinomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Monomio rhs: Monomio de la parte derecha del operador
     * \retval Polinomio: suma de los monomios del polinomio con el monomio (suma de monomios)
     */
    Polinomio & operator+(Polinomio const &lhs, Monomio const &rhs);
    /**
     * \brief operador aritmetico de suma de la clase Polinomio
     * \param Monomio lhs: Monomio de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \retval Polinomio: suma de los monomios del polinomio con el monomio (suma de monomios)
     */
    Polinomio & operator+(Monomio const &lhs, Polinomio const &rhs);
    /**
     * \brief operador aritmetico de suma de la clase Polinomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Real rhs: Real de la parte derecha del operador
     * \retval Polinomio: suma de los monomios del polinomio con el monomio rhs*x^0 (suma de monomios)
     */
    Polinomio & operator+(Polinomio const &lhs, float const &rhs);
    /**
     * \brief operador aritmetico de suma de la clase Polinomio
     * \param Real lhs: Real de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \retval Polinomio: suma de los monomios del polinomio con el monomio lhs*x^0 (suma de monomios)
     */
    Polinomio & operator+(float const &lhs, Polinomio const &rhs);


      //////////////////////////////////////////////////////////
    //! \name Operador binario de la resta
    /**
     * \brief operador aritmetico de resta de la clase Polinomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la presta derecha del operador
     * \retval Polinomio: suma de los dos Polinomio (suma de monomios)
     */
    Polinomio & operator-(Polinomio const &lhs, Polinomio const &rhs);
    /**
     * \brief operador aritmetico de resta de la clase Polinomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Monomio rhs: Monomio de la parte derecha del operador
     * \retval Polinomio: resta de los monomios del polinomio con el monomio (suma de monomios)
     */
    Polinomio & operator-(Polinomio const &lhs, Monomio const &rhs);
    /**
     * \brief operador aritmetico de resta de la clase Polinomio
     * \param Monomio lhs: Monomio de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \retval Polinomio: resta de los monomios del polinomio con el monomio (suma de monomios)
     */
    Polinomio & operator-(Monomio const &lhs, Polinomio const &rhs);
    /**
     * \brief operador aritmetico de resta de la clase Polinomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Real rhs: Real de la parte derecha del operador
     * \retval Polinomio: resta de los monomios del polinomio con el monomio rhs*x^0 (suma de monomios)
     */
    Polinomio & operator-(Polinomio const &lhs, float const &rhs);
    /**
     * \brief operador aritmetico de resta de la clase Polinomio
     * \param Real lhs: Real de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \retval Polinomio: resta de los monomios del polinomio con el monomio lhs*x^0 (suma de monomios)
     */
    Polinomio & operator-(float const &lhs, Polinomio const &rhs);
    


      //////////////////////////////////////////////////////////////////////////
    //! \name Operadores binarios de la multiplicación
    /**
     * \brief operador aritmetico de multiplicacion de la clase Polinomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la presta derecha del operador
     * \retval Polinomio: multiplicacion de los dos Polinomios
     */
    Polinomio & operator*(Polinomio const &lhs, Polinomio const &rhs);
    
    /**
     * \brief operador aritmetico de multiplicacion de la clase Polinomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Monomio rhs: Monomio de la presta derecha del operador
     * \retval Polinomio: multiplicacion del Polinomio por el Monomio
     */
    Polinomio & operator*(Polinomio const &lhs, Monomio const &rhs);
    
    /**
     * \brief operador aritmetico de multiplicacion de la clase Polinomio
     * \param Monomio lhs: Monomio de la presta izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \retval Polinomio: multiplicacion del Polinomio por el Monomio
     */
    Polinomio & operator*(Monomio const &lhs, Polinomio const &rhs);
    
    /**
     * \brief operador aritmetico de multiplicacion de la clase Polinomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Real rhs: numero de la presta derecha del operador
     * \retval Polinomio: multiplicacion del Polinomio por el numero
     */
    Polinomio & operator*(Polinomio const &lhs, float const &rhs);
    
    /**
     * \brief operador aritmetico de multiplicacion de la clase Polinomio
     * \param Real lhs: numero de la presta izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \retval Polinomio: multiplicacion del Polinomio por el numero
     */
    Polinomio & operator*(float const &lhs, Polinomio const &rhs);

      //////////////////////////////////////////////////////////////////////////
    //! \name Operadores binarios de la división
    /**
     * \brief operador aritmetico de multiplicacion de la clase Polinomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Polinomio rhs: Polinomio de la presta derecha del operador
     * \pre El grado de rhs es menor o igual que el de lhs
     * \retval Polinomio: division de lhs entre rhs
     */
    Polinomio & operator/(Polinomio const &lhs, Polinomio const &rhs);
    
    /**
     * \brief operador aritmetico de division de la clase Polinomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Monomio rhs: Monomio de la presta derecha del operador
     * \pre el grado del monomio es menor o igual al del polinomio
     * \retval Polinomio: division de lhs entre rhs
     */
    Polinomio & operator/(Polinomio const &lhs, Monomio const &rhs);
    
    /**
     * \brief operador aritmetico de division de la clase Polinomio
     * \param Monomio lhs: Monomio de la presta izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \pre el grado del polinomio es menor o igual que el del monomio
     * \retval Polinomio: division de lhs entre rhs
     */
    Polinomio & operator/(Monomio const &lhs, Polinomio const &rhs);
    
    /**
     * \brief operador aritmetico de division de la clase Polinomio
     * \param Polinomio lhs: Polinomio de la parte izquierda del operador
     * \param Real rhs: numero de la presta derecha del operador
     * \pre rhs no es cero
     * \retval Polinomio: division de lhs entre rhs
     */
    Polinomio & operator/(Polinomio const &lhs, float const &rhs);
    
    /**
     * \brief operador aritmetico de division de la clase Polinomio
     * \param Real lhs: numero de la presta izquierda del operador
     * \param Polinomio rhs: Polinomio de la parte derecha del operador
     * \pre el grado del polinomio es cero y su coeficiente no es 0
     * \retval Polinomio: division de lhs entre rhs
     */
    Polinomio & operator/(float const &lhs, Polinomio const &rhs);

      //////////////////////////////////////////////////////////////////////////
    //! \name Sobrecarga de los operadores de flujo de la clase Polinomio.
    /**
     * \brief operador de flujo de entrada de para la clase Polinomio
     * \param stream stream: stream
     * \param Polinomio p: Polinomio
     * \retval stream: resto del stream
     */
    ostream &operator<<(ostream &stream, Polinomio const &p);
    
    /**
     * \brief operador de flujo de salida de para la clase Polinomio, el formato es el siguiente: *[<coeficiente>x^<exponente>+]<coeficiente>x^<exponente>
     * \param stream stream: stream
     * \param Polinomio p: Polinomio
     * \retval stream: resto del stream
     */
    istream &operator>>(istream &stream, Polinomio &p);

}  // Fin de namespace ed.

#endif // _OperadoresPolinomios_HPP_
