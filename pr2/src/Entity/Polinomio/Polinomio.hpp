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
// #include "operadoresExternosPolinomios.hpp"


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
        Polinomio();
        Polinomio(const Polinomio &polinomio);
        Polinomio(const Monomio &monomio);
        
        //! \name Observadores: funciones de consulta de la clase Polinomio
        bool esNulo() const;
        int getGrado() const;
        int getNumeroMonomios() const;
        bool existeMonomio(int grado) const;
        ed::Monomio& getMonomio(int grado) const;

        //! \name Funciones de modificación de la clase Polinomio
        void addMonomio(ed::Monomio monomio);

        //! \name Operadores de la clase Polinomio
        Polinomio & operator=(Polinomio const &p);
        Polinomio & operator=(Monomio const &m);
        Polinomio & operator=(double const &x);

        // Operadores aritméticos y asignación
        Polinomio & operator+=(Polinomio const &rhs);
        Polinomio & operator+=(Monomio const &rhs);
        Polinomio & operator+=(float const &rhs);
        
        Polinomio & operator-=(Polinomio const &rhs);
        Polinomio & operator-=(Monomio const &rhs);
        Polinomio & operator-=(float const &rhs);
        
        Polinomio & operator*=(Polinomio const &rhs);
        Polinomio & operator*=(Monomio const &rhs);
        Polinomio & operator*=(float const &rhs);

        Polinomio & operator/=(Polinomio const &rhs);
        Polinomio & operator/=(Monomio const &rhs);
        Polinomio & operator/=(float const &rhs);
        
        //! \name Funciones lectura y escritura de la clase Polinomio
        
        void leerPolinomio();
        void escribirPolinomio();

        //! \name Funciones auxiliares de la clase Polinomio
        
        float calcularValor(float x);

}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
