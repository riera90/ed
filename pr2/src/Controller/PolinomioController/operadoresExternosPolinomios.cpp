/*!
   \file operadoresExternosPolinomios.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "operadoresExternosPolinomios.hpp"

#include "operadoresExternosMonomios.hpp"

// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed
{

    bool operator==(ed::Polinomio const & lhs, ed::Polinomio const & rhs)
    {
        for (int i = 0; i < lhs.getGrado() || i < rhs.getGrado(); i++) {
            if ( lhs.existeMonomio(i) || rhs.existeMonomio(i) ){
            
                if ( !lhs.existeMonomio(i) || !rhs.existeMonomio(i) )
                    return false;
                
                if ( lhs.getMonomio(i) != lhs.getMonomio(i) )
                    return false;
            }
        }

        return true;
    }



    bool operator==(ed::Polinomio const & lhs, ed::Monomio const & rhs)
    {
        if ( lhs.getNumeroMonomios() != 1 )
            return false;
        
        if ( lhs.getMonomio(rhs.getGrado()) != rhs )
            return false;

        return true;
    }



    bool operator==(ed::Monomio const & lhs, ed::Polinomio const & rhs)
    {
        return rhs == lhs;
    }



    bool operator==(ed::Polinomio const & lhs, float const & rhs)
    {
        if ( lhs.getNumeroMonomios() != 1 )
            return false;
        
        if ( lhs.getMonomio(0) != rhs )
            return false;

        return true;
    }



    bool operator==(float const & lhs, ed::Polinomio const & rhs)
    {
        return rhs == lhs;
    }
    
    
    
    
    
    
    
    
    
    
    ////////////////////////////////////////////////////////////////////////////////////
    // Operadores de desigualdad
    
    bool operator!=(ed::Polinomio const & lhs, ed::Polinomio const & rhs)
    {
        return !(lhs == rhs);
    }



    bool operator!=(ed::Polinomio const & lhs, ed::Monomio const & rhs)
    {
        return !(lhs == rhs);
    }
    
    

    bool operator!=(ed::Monomio const & lhs, ed::Polinomio const & rhs)
    {
        return !(lhs == rhs);
    }
    
    

    bool operator!=(ed::Polinomio const & lhs, float const & rhs)
    {
        return !(lhs == rhs);
    }
    
    

    bool operator!=(float const & lhs, ed::Polinomio const & rhs)
    {
        return !(lhs == rhs);
    }












    //////////////////////////////////////////////////////////////////////////////////////
    // Operadores unarios
    

    Polinomio & operator+(Polinomio const & p)
    {
        // COMPLETAR Y MODIFICAR
        // Se crea un nuevo objeto
        ed::Polinomio *nuevo = new ed::Polinomio(p);	
        // Se devuelve el resultado
        return *nuevo;
    }
    


    Polinomio & operator-(Polinomio const & p)
    {
        // COMPLETAR Y MODIFICAR
        // Se crea un nuevo objeto
        Polinomio *nuevo = new Polinomio(p);
        // for
        // nuevo->setGrado(-nuevo->getGrado());
        // Se devuelve el resultado
        return *nuevo;
    }









    //////////////////////////////////////////////////////////////////////////////////////
    //! Operadores binarios de la suma
    
    
    Polinomio & operator+(Polinomio const &lhs, Polinomio const &rhs)
    {
        // COMPLETAR Y MODIFICAR
        // Se crea un nuevo objeto
        Polinomio *nuevo = new Polinomio;

        for (int i = 0, n = 0; n < lhs.getNumeroMonomios(); i++) {
            // printf("l iteration %i\n", i);
            if (lhs.existeMonomio(i)){
                // printf("\tadding %i\n", i);
                nuevo->addMonomio(lhs.getMonomio(i));
                n++;
            }
        }
        
        for (int i = 0, n = 0; n < rhs.getNumeroMonomios(); i++) {
            // printf("r iteration %i\n", i);
            if (rhs.existeMonomio(i)){
                // printf("\tadding %i\n", i);
                nuevo->addMonomio(rhs.getMonomio(i));
                n++;
            }
        }
        
        // Se devuelve el resultado
        return *nuevo;
    }



    Polinomio & operator+(Polinomio const &lhs,  Monomio const &rhs)
    {
        Polinomio *nuevo = new Polinomio;
        (*nuevo) = lhs;
        nuevo->addMonomio(rhs);
        return *nuevo;
    }



    Polinomio & operator+(Monomio const &lhs,  Polinomio const &rhs)
    {
        ed::Polinomio *nuevo = new ed::Polinomio;
        (*nuevo) = rhs;
        nuevo->addMonomio(lhs);
        return *nuevo;
    }
    
    
    
    
    
    
    
    
    
          ////////////
        // Resta

    Polinomio & operator-(Polinomio const &lhs,  Polinomio const &rhs)
    {
        // COMPLETAR Y MODIFICAR
        // Se crea un nuevo objeto
        Polinomio *nuevo = new Polinomio;

        for (int i = 0, n = 0; n < lhs.getNumeroMonomios(); i++) {
            // printf("l iteration %i\n", i);
            if (lhs.existeMonomio(i)){
                // printf("\tadding %i\n", i);
                nuevo->addMonomio(lhs.getMonomio(i));
                n++;
            }
        }
        
        for (int i = 0, n = 0; n < rhs.getNumeroMonomios(); i++) {
            // printf("r iteration %i\n", i);
            if (rhs.existeMonomio(i)){
                // printf("\tadding %i\n", i);
                nuevo->addMonomio(-rhs.getMonomio(i));
                n++;
            }
        }
        
        // Se devuelve el resultado
        return *nuevo;
    }



    Polinomio & operator-(Polinomio const &lhs,  ed::Monomio const &rhs)
    {
        Polinomio *nuevo = new Polinomio;
        (*nuevo) = lhs;
        nuevo->addMonomio(-rhs);
        return *nuevo;
    }
    
    
    
    Polinomio & operator-(Monomio const &lhs,  ed::Polinomio const &rhs)
    {
        Polinomio *nuevo = new Polinomio;
        (*nuevo) = rhs;
        nuevo->addMonomio(-lhs);
        return *nuevo;
    }
        








        //////////////////
        // Multiplicación

        // COMPLETAR

        ////////////
        // División

        // COMPLETAR


    ////////////////////////////////////////////////////////////////////////////

    // Sobrecarga del operador de entrada
    istream &operator>>(istream &stream, Polinomio &p)
    {
        // COMPLETAR

        // Se devuelve el flujo de entrada
      return stream;
    }



    // Sobrecarga del operador de salida
    ostream &operator<<(ostream &stream, Polinomio const &p)
    {
        // COMPLETAR

        // Se devuelve el flujo de salida
      return stream;
    }


} // Fin del espacio de nombres ed
