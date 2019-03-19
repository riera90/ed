/*!
    \file Monomio.hpp
    \brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>
#include "auxiliarFunctions.hpp"
#include <iostream>
#include <fstream>



#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$
class Monomio
{
    //! \name Atributos privados de la clase Monomio
    private:
    float coeficiente_; //< !Coeficiente del monomio
    int grado_; //< !Grado del monomio


    //! \name Funciones o métodos públicos de la clase Monomio
    public:

    //! \name Constructores de la clase Monomio

    /**
     * \brief Constructor parametrizado con valores por defecto de la clase monomio
     * \param real coeficiente: coeficiente del monomio
     * \param entero grado: grado del monomio
     * \pre el grado ha de ser mayor o igual a 0
     * \post el monomio se ha creado con los valores pasados en los parametros
     * \warning los valores por defecto son en ambas variables 0
     */
    Monomio(float coeficiente = 0, int grado = 0);

    /**
     * \brief Constructor de copia la clase monomio
     * \param Monomio coeficiente: monomio a copiar
     * \post el monomio se ha creado con los mismos valores que el pasado por parametro
     */
    Monomio(const Monomio &monomio);



    //! \name Observadores: funciones de consulta de la clase Monomio

    /**
     * \brief Observador del coeficiente de la clase Monomio
     * \retval real: coeficiente del monomio
     */
    float getCoeficiente() const;

    /**
     * \brief Observador del grado de la clase Monomio
     * \retval entero: grado del monomio
     */
    int getGrado() const;



    //! \name Funciones de modificación de la clase Monomio

    /**
     * \brief modificador del coeficiente de la clase Monomio
     * \param real coeficiente: nuevo coeficiente del monomio
     * \retval booleano: si el monomio ha sido modificado, este retornara verdadero, en otro caso sera falso
     */
    bool setCoeficiente(float coeficiente);

    /**
     * \brief modificador del grado de la clase Monomio
     * \param real grado: nuevo grado del monomio
     * \pre el grado es mayor o igual que 0
     * \retval booleano: si el monomio ha sido modificado, este retornara verdadero, en otro caso sera falso
     */
    bool setGrado(int grado);
    
    
    /**
     * \brief Observador de nulizez de la clase Monomio
     * \retval booleano: si el monomio es grado y coeficinete 0 retornará verdadero si no falso
     */
    bool esNulo() const;

    /**
     * \brief Observador de cero de la clase Monomio
     * \retval booleano: si el coeficinete 0 retornará verdadero si no falso
     */
    bool esCero() const;


    /////////////////////////////////////////////////

    //! \name Operadores de la clase Monomio

    // Operadores de asignación

    /**
     * \brief operador de asignación de la clase Monomio
     * \param Monomio m: monomio a copiar los valores de
     * \post los valores del monomio actual son iguales que al pasado como parametro
     * \retval Monomio: El monomio con los valores actualizados
     */
    Monomio & operator=(Monomio const &m);

    /**
     * \brief operador de asignación de la clase Monomio
     * \param real x: valor a asignar al monomio
     * \post el coeficiente del monomio es igual al parametro x
     * \post el grado del monomio es igual a 0
     * \retval Monomio: El monomio con los valores actualizados
     */
    Monomio & operator=(double const &x);


    // Operadores aritméticos y asignación

    /**
     * \brief operador aritmetico de suma y asignación de la clase Monomio
     * \param Monomio m: monomio a sumar y asignar los valores de
     * \post el coeficiente del monomio es igual a la suma del grado actual y el grado del monomio pasado por parametro
     * \post el grado del monomio no se ha modificado
     * \retval Monomio: El monomio con los valores actualizados
     */
    Monomio & operator+=(const Monomio &m);

    /**
     * \brief operador aritmetico de resta y asignación de la clase Monomio
     * \param Monomio rhs: monomio a restar y asignar los valores de
     * \pre el coeficiente del momomio actual es mayor a igual que el del monomio pasado por paraemtro
     * \post el coeficiente del monomio es igual a la resta del grado actual menos el grado del monomio pasado por parametro
     * \post el grado del monomio no se ha modificado
     * \retval Monomio: El monomio con los valores actualizados
     * \warning si las precondiciones no se cumplen la funcion retornara el monomio actual sin actualizar y tampoco lo actializará
     */
    Monomio & operator-=(const Monomio &rhs);

    /**
     * \brief operador aritmetico de multiplicación y asignación de la clase Monomio
     * \param Monomio rhs: monomio a multiplicar y asignar los valores de
     * \post el coeficiente del monomio es igual a la multiplicación del coeficiente actual menos el coeficiente del monomio pasado por parametro
     * \post el grado del monomio se ha incrementado en el grado del monomio pasado por parametro
     * \retval Monomio: El monomio con los valores actualizados
     */
    Monomio & operator*=(const Monomio &rhs);

    /**
     * \brief operador aritmetico de multiplicación y asignación de la clase Monomio
     * \param real rhs: real a multiplicar por el monomio y asignar valores
     * \post el coeficiente del monomio es igual a la multiplicación del parametro por el coeficiente actual
     * \post el grado del monomio no ha sido modificado
     * \retval Monomio: El monomio con los valores actualizados
     */
    Monomio & operator*=(const float &rhs);

    /**
     * \brief operador aritmetico de división y asignación de la clase Monomio
     * \param Monomio rhs: monomio a dividir entre y asignar los valores de
     * \pre el coeficiente del momomio pasado por parametro no es 0
     * \pre el grado del monomio pasado por parametro es igual o inferior que el grado del monomio actual
     * \post el coeficiente del monomio es igual a la resta del coeficiente actual menos el coeficiente del monomio pasado por parametro
     * \post el grado del monomio se ha incrementado en el grado del monomio pasado por parametro
     * \retval Monomio: El monomio con los valores actualizados
     * \warning si las precondiciones no se cumplen la funcion retornara el monomio actual sin actualizar y tampoco lo actializará
     */
    Monomio & operator/=(const Monomio &rhs);

    /**
     * \brief operador aritmetico de división y asignación de la clase Monomio
     * \param real rhs: numero a dividir entre y asignar los valores de
     * \pre el parametro no es 0
     * \pre el grado del monomio no se ha actualizado
     * \post el coeficiente del monomio es igual a la división del coeficiente actual y el parametro
     * \post el grado del monomio se ha incrementado en el grado del monomio pasado por parametro
     * \retval Monomio: El monomio con los valores actualizados
     * \warning si las precondiciones no se cumplen la funcion retornara el monomio actual sin actualizar y tampoco lo actializará
     */
    Monomio & operator/=(const float &rhs);



    /////////////////////////////////////////////////////////////////////////////////////

    //! \name Funciones lectura y escritura de la clase Monomio

    /**
     * \brief función de lectura del monomio por terminal
     * \post el monomio está en un estado estable
     */
    void leerMonomio();

    /**
     * \brief función de escritura del monomio en el terminal
     */
    void escribirMonomio() const;


    ///////////////////////////////////////////////////////////////////////

    //! \name Funciones auxiliares de la clase Monomio

    /**
     * \brief función calculo de valores en el monomio actual
     * \param real x: valor a evaluar en el monomio actual
     * \retval real: valor del parametro x evaluado en el monomio actual
     */
    float calcularValor(float x) const;

    /**
     * \brief representa una gráfica del monomio
     * \param real min_x: valor mínimo de x
     * \param real max_x: valor máximo de x
     */
    void plot(int min_x, int max_x) const;



};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
