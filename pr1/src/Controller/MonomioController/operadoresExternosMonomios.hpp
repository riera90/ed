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

    /**
     * \brief operador lógico de igualdad de la clase Monomio
     * \param Monomio lhs: monomio de la parte izquierda del operador
     * \param Monomio rhs: monomio de la parte derecha del operador
     * \retval boolenano: si los dos monomios son iguales (coeficiente y grado) el valor retornado sera verdadero, falso en quialquier ostro caso
     */
    bool operator==(const ed::Monomio &lhs, const ed::Monomio &rhs);

    /**
     * \brief operador lógico de igualdad de la clase Monomio
     * \param real lhs: número de la parte izquierda del operador
     * \param Monomio rhs: monomio de la parte derecha del operador
     * \retval boolenano: si el monomio tiene el coeficiente igual a lhs y su grado es 0 el valor retornado sera verdadero, falso en quialquier ostro caso
     */
    bool operator==(const float &lhs, const ed::Monomio &rhs);

    /**
     * \brief operador lógico de igualdad de la clase Monomio
     * \param Monomio lhs: monomio de la parte derecha del operador
     * \param real rhs: número de la parte izquierda del operador
     * \retval boolenano: si el monomio tiene el coeficiente igual a rhs y su grado es 0 el valor retornado sera verdadero, falso en quialquier ostro caso
     */
    bool operator==(const ed::Monomio &lhs, const float &rhs);




    //! \name Operadores de desigualdad

    /**
     * \brief operador lógico de desigualdad de la clase Monomio
     * \param Monomio lhs: monomio de la parte izquierda del operador
     * \param Monomio rhs: monomio de la parte derecha del operador
     * \retval boolenano: si los dos monomios no son iguales (coeficiente o grado) el valor retornado sera verdadero, falso en quialquier ostro caso
     */
    bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

    /**
     * \brief operador lógico de desigualdad de la clase Monomio
     * \param real lhs: número de la parte izquierda del operador
     * \param Monomio rhs: monomio de la parte derecha del operador
     * \retval boolenano: si el monomio no tiene el coeficiente igual a lhs o su grado no es 0 el valor retornado sera verdadero, falso en quialquier ostro caso
     */
    bool operator!=(const float &lhs, const ed::Monomio &rhs);

    /**
     * \brief operador lógico de precondicionesigualdad de la clase Monomio
     * \param Monomio lhs: monomio de la parte derecha del operador
     * \param real rhs: número de la parte izquierda del operador
     * \retval boolenano: si el monomio no tiene el coeficiente igual a rhs o su grado no es 0 el valor retornado sera verdadero, falso en quialquier ostro caso
     */
    bool operator!=(const ed::Monomio &lhs, const float &rhs);

    ///////////////////////////////////////////////////

    //! \name Operadores unarios prefijos

    /**
     * \brief operador aritmetico de copia
     * \param Monomio main: monomio a copiar
     * \retval Monomio: copia del monomio por referencia
     */
    ed::Monomio &operator+(ed::Monomio const & m);

    /**
     * \brief operador aritmetico de copia e inversion de signo del coeficiente
     * \param Monomio main: monomio a copiar
     * \retval Monomio: copia del monomio por referencia con el coeficiente invertido en su signo
     */
    ed::Monomio &operator- (const ed::Monomio &rhs);


    //////////////////////////////////////////////////////////

    //! \name Operador binario de la suma

    /**
     * \brief operador aritmetico de suma de la clase Monomio
     * \param Monomio lhs: monomio de la parte izquierda del operador
     * \param Monomio rhs: monomio de la parte derecha del operador
     * \pre Los grados de ambos monomios son iguales
     * \retval Monomio: suma de los dos monomios (suma de coeficientes)
     * \warning Si los grados de ambos monomios no son iguales se retornará un monomio por defecto (0, 0)
     */
     ed::Monomio &operator+ (ed::Monomio const &lhs, ed::Monomio const &rhs);


    //////////////////////////////////////////////////////////
    //! \name Operador binario de la resta

    /**
     * \brief operador aritmetico de resta de la clase Monomio
     * \param Monomio lhs: monomio de la parte izquierda del operador
     * \param Monomio rhs: monomio de la parte derecha del operador
     * \pre Los grados de ambos monomios son iguales
     * \retval Monomio: resta de los dos monomios (suma de coeficientes)
     * \warning Si los grados de ambos monomios no son iguales se retornará un monomio por defecto (0, 0)
     */
    ed::Monomio &operator- (ed::Monomio const &lhs, ed::Monomio const &rhs);


    ///////////////////////////////////////////////////////////////////////////
    //! \name Operadores binarios de la multiplicación

    /**
     * \brief operador aritmetico de multiplicación de la clase Monomio
     * \param Monomio lhs: monomio de la parte izquierda del operador
     * \param Monomio rhs: monomio de la parte derecha del operador
     * \retval Monomio: multiplicación de los dos monomios (suma de grados y cociente de coeficientes)
     * \warning Si los grados de ambos monomios no son iguales se retornará un monomio por defecto (0, 0)
     */
    ed::Monomio &operator* (const ed::Monomio &lhs, const ed::Monomio &rhs);

    /**
     * \brief operador aritmetico de multiplicación de la clase Monomio
     * \param Monomio lhs: monomio de la parte izquierda del operador
     * \param real rhs: número de la parte derecha del operador
     * \retval Monomio: multiplicación del monomio por el real dos monomios (mismo grado y producto de coeficiente por rhs)
     */
    ed::Monomio &operator* (const ed::Monomio &lhs, const float &rhs);

    /**
     * \brief operador aritmetico de multiplicación de la clase Monomio
     * \param real lhs: número de la parte derecha del operador
     * \param Monomio rhs: monomio de la parte izquierda del operador
     * \retval Monomio: multiplicación del monomio por el real dos monomios (mismo grado y producto de coeficiente por rhs)
     */
    ed::Monomio &operator* (const float &lhs, const ed::Monomio &rhs);

    ///////////////////////////////////////////////////////////////////////////

    //! \name Operadores binarios de la división

    /**
     * \brief operador aritmetico de multiplicación de la clase Monomio
     * \param Monomio lhs: monomio de la parte izquierda del operador
     * \param Monomio rhs: monomio de la parte derecha del operador
     * \pre el grado de lhs es mayor o igual que el de rhs
     * \pre el coeficiente de rhs no es 0
     * \retval Monomio: división de los dos monomios (resta de grados lhs-rhs y cociente de coeficientes lhs/rhs)
     * \warning Si las precondiciones no se cumplen, retornará un monomio por defecto (0, 0)
     */
    ed::Monomio &operator/ (const ed::Monomio &lhs, const ed::Monomio &rhs);

    /**
     * \brief operador aritmetico de multiplicación de la clase Monomio
     * \param Monomio lhs: monomio de la parte izquierda del operador
     * \param real rhs: número de la parte derecha del operador
     * \pre rhs no es 0
     * \retval Monomio: división del monimio entre rhs (mismo grado y cociente de coeficientes lhs/rhs)
     * \warning Si las precondiciones no se cumplen, retornará un monomio por defecto (0, 0)
     */
    ed::Monomio &operator/ (const ed::Monomio &lhs, const float &rhs);

    /**
     * \brief operador aritmetico de multiplicación de la clase Monomio
     * \param real lhs: número de la parte derecha del operador
     * \param Monomio rhs: monomio de la parte izquierda del operador
     * \pre el coeficiente y grado de rhs no es 0
     * \retval Monomio: división del número entre el monomio (grado 0 y coeficiente igual a la division del numero entre el coeficiente del monomio)
     * \warning Si las precondiciones no se cumplen, retornará un monomio por defecto (0, 0)
     */
    ed::Monomio &operator/ (const float &lhs, const ed::Monomio &rhs);


    /////////////////////////////////////////////////////////////////////////////

    //! \name Sobrecarga de los operadores de entrada y salida

    /**
     * \brief operador de flujo de entrada de para la clase monimio
     * \param Monomio m: monomio
     * \retval stream: resto del stream
     */
    istream &operator>>(istream &stream, ed::Monomio &m);

    /**
     * \brief operador de flujo de salida de para la clase monimio, el formato es el siguiente "[coeficiente] [grado]"
     * \param Monomio m: monomio
     * \retval stream: resto del stream
     */
    ostream &operator<<(ostream &stream, const ed::Monomio &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_
