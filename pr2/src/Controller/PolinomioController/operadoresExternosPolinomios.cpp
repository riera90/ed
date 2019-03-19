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
    
    
    
    
    
    
    
    
    
    
      //////////////////////////////////////////////////////////////////////////
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












      //////////////////////////////////////////////////////////////////////////
    // Operadores unarios
    

    Polinomio & operator+(Polinomio const & p)
    {
        ed::Polinomio *nuevo = new ed::Polinomio(p);
        return *nuevo;
    }
    


    Polinomio & operator-(Polinomio const & p)
    {
        Polinomio *nuevo = new Polinomio;
        for (int i = 0, n = 0; n < p.getNumeroMonomios(); i++) {
            if (p.existeMonomio(i)){
                nuevo->addMonomio( - p.getMonomio(i) );
                n++;
            }
        }
        return *nuevo;
    }









      //////////////////////////////////////////////////////////////////////////
    // Operadores binarios de la suma
    
    
    Polinomio & operator+(Polinomio const &lhs, Polinomio const &rhs)
    {
        // COMPLETAR Y MODIFICAR
        // Se crea un nuevo objeto
        Polinomio *nuevo = new Polinomio;
        (*nuevo) = lhs;
        
        for (int i = 0, n = 0; n < rhs.getNumeroMonomios(); i++) {
            // printf("r iteration %i\n", i);
            if (rhs.existeMonomio(i)){
                // printf("\tadding %i, grado %i\n", i, n);
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
    
    
    
    Polinomio & operator+(Polinomio const &lhs, float const &rhs){
        ed::Polinomio *nuevo = new ed::Polinomio;
        (*nuevo) = lhs;
        nuevo->addMonomio(Monomio(rhs, 0));
        return *nuevo;
    }
    
    
    
    Polinomio & operator+(float const &lhs, Polinomio const &rhs){
        ed::Polinomio *nuevo = new ed::Polinomio;
        (*nuevo) = rhs;
        nuevo->addMonomio(Monomio(lhs, 0));
        return *nuevo;
    }
    
    
    
    
    
    
    
    
    
      ////////////
    // Resta

    Polinomio & operator-(Polinomio const &lhs,  Polinomio const &rhs)
    {
        // COMPLETAR Y MODIFICAR
        // Se crea un nuevo objeto
        Polinomio *nuevo = new Polinomio;
        (*nuevo) = lhs;
        
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
        

    Polinomio & operator-(Polinomio const &lhs, float const &rhs){
        ed::Polinomio *nuevo = new ed::Polinomio;
        (*nuevo) = lhs;
        nuevo->addMonomio(Monomio(-rhs, 0));
        return *nuevo;
    }
    
    
    Polinomio & operator-(float const &lhs, Polinomio const &rhs){
        ed::Polinomio *nuevo = new ed::Polinomio;
        (*nuevo) = - rhs;
        nuevo->addMonomio(Monomio(lhs, 0));
        return *nuevo;
    }






      //////////////////
    // Multiplicación









      ////////////
    // División









      //////////////////////////////////////////////////////////////////////////
    // Sobrecarga de flujos
    
    istream &operator>>(istream &stream, Polinomio &p)
    {
        // Se devuelve el flujo de entrada
      return stream;
    }



    ostream &operator<<(ostream &stream, Polinomio const &p)
    {
        // Se devuelve el flujo de salida
      return stream;
    }


} // Fin del espacio de nombres ed
