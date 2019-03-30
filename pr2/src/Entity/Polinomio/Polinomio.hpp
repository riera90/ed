/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"
#include "operadoresExternosMonomios.hpp"
#include "auxiliarFunctions.hpp"


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public PolinomioInterfaz
{

    //! \name Atributos privados de la clase Polinomio
    private:
        std::vector<Monomio> monomios_;


    //! \name Funciones o métodos públicos de la clase Polinomio
    public:
        //! \name Constructores de la clase Polinomio
        /**
         * \brief Constructor sin parametros la clase Polinomio
         */
        Polinomio();
        
        /**
         * \brief Constructor de copia la clase Polinomio
         */
        Polinomio(const Polinomio &polinomio);
        
        /**
         * \brief Constructor de Parametrizado de la clase Polinomio
         * \param Monomio monomio: monomio a inicializar el Polinomio
         */
        Polinomio(const Monomio &monomio);
        
        //! \name Observadores: funciones de consulta de la clase Polinomio
        /**
         * \brief Observador de nulidez de la clase Polinomio
         * \ret booleano: verdero si es nulo, falso en el caso contrario
         */
        bool esNulo() const;
        
        /**
         * \brief Observador del grado de la clase Polinomio
         * \ret integer: grado del monomio de grado maximo del polinomio
         */
        int getGrado() const;
        
        /**
         * \brief Observador del numero de monomios de la clase Polinomio
         * \ret integer: numero de monomios del polinomio
         */
        int getNumeroMonomios() const;
        
        /**
         * \brief Observador logiuco de exstencia de monomio en el polinomio
         * \ret booleano: verdadero si el monomio existe en el polinomio
         */
        bool existeMonomio(int grado) const;
        
        /**
         * \brief Observador logico de exstencia de monomio en el polinomio
         * \pre el monomio de dicho grado existe
         * \ret Monomio: Monomio de grado 'grado'
         */
        ed::Monomio& getMonomio(int grado) const;

        //! \name Funciones de modificación de la clase Polinomio
        /**
         * \brief modificador de adicion de la clase polinomio
         * \param Monomio monomio: monomio a sumar
         * \post el monomio se ha sumado al polinonio actual
         */
        void addMonomio(ed::Monomio const &monomio);

        //! \name Operadores de la clase Polinomio
        /**
         * \brief modificador de asignacion de la clase polinomio
         * \param Polinomio polinomio: polinomio a copiar
         * \pre El polinomio “p” debe ser diferente del polinomio actual
         * \post el Polinomio se ha igualado al polinomio del parametro
         */
        Polinomio & operator=(Polinomio const &p);
        
        /**
         * \brief modificador de asignacion de la clase polinomio
         * \param Monomio Monomio: Monomio a copiar al Polinomio
         * \pre El polinomio actual debe tener un único monomio que será igual al
monomio “m”.
         * \post el Polinomio se ha igualado al monomio del parametro
         */
        Polinomio & operator=(Monomio const &m);
        
        /**
         * \brief modificador de asignacion de la clase polinomio
         * \param Real x: Real a copiar al polinomio
         * \post el Polinomio se ha igualado al numero del parametro
         */
        Polinomio & operator=(double const &x);

        // Operadores aritméticos y asignación
        
        /**\brief Operador aritmetico de asignacion y suma de la clase Polinomio
         * \param Polinomio rhs: polinomio a sumar con el Polinomio actual
         */
        Polinomio & operator+=(Polinomio const &rhs);
        
        /**\brief Operador aritmetico de asignacion y suma de la clase Polinomio
         * \param Monomio rhs: monomio a sumar con el Polinomio actual
         */
        Polinomio & operator+=(Monomio const &rhs);
        
        /**\brief Operador aritmetico de asignacion y suma de la clase Polinomio
         * \param Real rhs: mumero a sumar con el Polinomio actual
         */
        Polinomio & operator+=(float const &rhs);
        
        
        /**\brief Operador aritmetico de asignacion y xxxxx de la clase Polinomio
         * \param Polinomio rhs: polinomio a restar al polinomio actual
         */
        Polinomio & operator-=(Polinomio const &rhs);
        
        /**\brief Operador aritmetico de asignacion y xxxxx de la clase Polinomio
         * \param Monomio rhs: monomio a restar al polinomio actual
         */
        Polinomio & operator-=(Monomio const &rhs);
        
        /**\brief Operador aritmetico de asignacion y xxxxx de la clase Polinomio
         * \param xxxx rhs: numero a restar al polinomio actual
         */
        Polinomio & operator-=(float const &rhs);
        
        
        /**\brief Operador aritmetico de asignacion y xxxxx de la clase Polinomio
         * \param Polinomio rhs: Polinomio a multiplicar el polinomio actual por
         */
        Polinomio & operator*=(Polinomio const &rhs);
        
        /**\brief Operador aritmetico de asignacion y xxxxx de la clase Polinomio
         * \param Monomio rhs: Monomio a multiplicar el Polinomio actual por
         */
        Polinomio & operator*=(Monomio const &rhs);
        
        /**\brief Operador aritmetico de asignacion y xxxxx de la clase Polinomio
         * \param Real rhs: Real a multiplicar el Polinomio actual por
         */
        Polinomio & operator*=(float const &rhs);

        
        /**\brief Operador aritmetico de asignacion y xxxxx de la clase Polinomio
         * \param Polinomio rhs: Polinomio a divir el Polinomio actual entre
         * \pre el grado de rhs es menor o igual que el Polinomio actual entre
         * \pre rhs contiene algun monomio no nulo
         */
        Polinomio & operator/=(Polinomio const &rhs);
        
        /**\brief Operador aritmetico de asignacion y xxxxx de la clase Polinomio
         * \param Monomio rhs: Monomio a dividir el Polimomio actual entre
         * \pre el grado de rhs es menor o igual que el Polinomio actual entre
         * \pre rhs no es nulo
         */
        Polinomio & operator/=(Monomio const &rhs);
        
        /**\brief Operador aritmetico de asignacion y xxxxx de la clase Polinomio
         * \param Real rhs: numero a dividir el Polinomio actual entre
         */
        Polinomio & operator/=(float const &rhs);
        
        //! \name Funciones lectura y escritura de la clase Polinomio
        
        /**
         * \brief función de lectura del Polinomio por terminal
         * \post el Polinomio está en un estado estable
         */
        void leerPolinomio();
        
        /**
         * \brief función de escritura del Polinomio en el terminal
         */
        void escribirPolinomio() const;

        //! \name Funciones auxiliares de la clase Polinomio
        
        /**
         * \brief función calculo de valores en el Polinomio actual
         * \param real x: valor a evaluar en el Polinomio actual
         * \retval real: valor del parametro x evaluado en el Polinomio actual
         */
        float calcularValor(float x) const;
        
        /**
         * \brief representa una gráfica del polinomio
         * \param real min_x: valor mínimo de x
         * \param real max_x: valor máximo de x
         */
        void plot(int min_x, int max_x) const;

}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
