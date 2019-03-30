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
        

    Polinomio & operator-(Polinomio const &lhs, float const &rhs)
    {
        ed::Polinomio *nuevo = new ed::Polinomio;
        (*nuevo) = lhs;
        nuevo->addMonomio(Monomio(-rhs, 0));
        return *nuevo;
    }
    
    
    Polinomio & operator-(float const &lhs, Polinomio const &rhs)
    {
        ed::Polinomio *nuevo = new ed::Polinomio;
        (*nuevo) = - rhs;
        nuevo->addMonomio(Monomio(lhs, 0));
        return *nuevo;
    }






      //////////////////
    // Multiplicación

    Polinomio & operator*(Polinomio const &lhs, Polinomio const &rhs)
    {
        ed::Polinomio *nuevo = new ed::Polinomio;
        
        for (int li = 0, ln = 0; ln < lhs.getNumeroMonomios(); li++) {
            // printf("li %i\n", li);
            if (lhs.existeMonomio(li)){
                // printf("\tL in %i\n", li);
                
                
                for (int ri = 0, rn = 0; rn < rhs.getNumeroMonomios(); ri++) {
                    // printf("ri %i\n", ri);
                    if (rhs.existeMonomio(ri)){
                        // printf("\tR in %i\n", ri);
                        
                        nuevo->addMonomio(lhs.getMonomio(li) * rhs.getMonomio(ri));
                        rn++;
                    }
                }
                
                ln++;
            }
        }
        
        return *nuevo;
    }
    
    
    Polinomio & operator*(Polinomio const &lhs, Monomio const &rhs)
    {
        ed::Polinomio *nuevo = new ed::Polinomio;
        
        for (int i = 0, n = 0; n < lhs.getNumeroMonomios(); i++) {
            // printf("li %i\n", li);
            if (lhs.existeMonomio(i)){
                // printf("\tL in %i\n", li);
                nuevo->addMonomio(lhs.getMonomio(i) * rhs);
                n++;
            }
        }
        
        return *nuevo;
    }
    
    Polinomio & operator*(Monomio const &lhs, Polinomio const &rhs)
    {
        return rhs * lhs;
    }
    
    
    Polinomio & operator*(Polinomio const &lhs, float const &rhs)
    {
        ed::Polinomio *nuevo = new ed::Polinomio;
        
        for (int i = 0, n = 0; n < lhs.getNumeroMonomios(); i++) {
            // printf("li %i\n", li);
            if (lhs.existeMonomio(i)){
                // printf("\tL in %i\n", li);
                nuevo->addMonomio(lhs.getMonomio(i) * rhs);
                n++;
            }
        }
        
        return *nuevo;
    }
    
    Polinomio & operator*(float const &lhs, Polinomio const &rhs)
    {
        return rhs * lhs;
    }








      ////////////
    // División
    
    Polinomio & operator/(Polinomio const &lhs, Polinomio const &rhs)
    {
        Polinomio *nuevo = new ed::Polinomio;
        float coeficiente;
        int grado;
        
        // to be able to modify the parapeters, we copy them into another
        // internal varialbe
        Polinomio lhs_(lhs);
        Polinomio rhs_(rhs);
        Monomio res; // ressult of the division of 2 monomios
                
        if (lhs_.getGrado() < rhs_.getGrado())
            return *nuevo; 
        
        while (lhs_.getGrado() > rhs_.getGrado()){
            // division betwen the bigest monomio of lhs and the biggest of rhs
            res = lhs_.getMonomio(lhs_.getGrado()) / rhs_.getMonomio(rhs_.getGrado());
            // this is the difference betwen what it's left and what we have now
            // in 'lhs', so we must substract it from lhs
            // 'res' times 'rhs'
            lhs_ -= rhs_ * res;
            // we add this difference to the returned value
            (*nuevo) += res;
        }
        
        return *nuevo;
    }
    
    
    Polinomio & operator/(Polinomio const &lhs, Monomio const &rhs)
    {
        return lhs / Polinomio(rhs);
    }
    
    Polinomio & operator/(Monomio const &lhs, Polinomio const &rhs)
    {
        return Polinomio(rhs) / lhs;
    }
    
    
    Polinomio & operator/(Polinomio const &lhs, float const &rhs)
    {
        return lhs / Polinomio(Monomio(rhs));
    }
    
    Polinomio & operator/(float const &lhs, Polinomio const &rhs)
    {
        return Polinomio(Monomio(lhs)) / rhs;
    }








      //////////////////////////////////////////////////////////////////////////
    // Sobrecarga de flujos
    
    istream &operator>>(istream &stream, Polinomio &p)
    {
        std::cout << "begin procedure" << '\n';
        std::string aux;
        int coeficiente, grado;
        getline(stream, aux, '\n');
        
        /* all the line is read and is splits into sections
         * this sections are, the coeficient and the degree
         * this is parto of other divisions, each monomio is one division
         * 
         * each mon omio division is delimited by '+' and the last one by '\n'
         * 
         * each coeficient and degree are delimited by a "x^" and the plus of
         * the monomio
         * 
         * each cicle of the wile, a monomio is treated and deleted from the
         * string
         * 
         * the monomios are treated from the begin of the string to the back of
         * it
         * 
         * when there are no monomios left, the procedure is finished
         * 
         * 
         * VALID INPUT EXAMPLES:
         * 
         * 1x^2
         * 1x^2+3x^4+5x^0
         * 5x^0
         */
         
        while ( aux.find('+') != std::string::npos ){
            // in between monomios delimited by '+'
            coeficiente = ed::stof( aux.substr(0, aux.find('x')) );
            grado = ed::stof( aux.substr(aux.find('^')+1, aux.find('+')) );
            p.addMonomio(*new ed::Monomio(coeficiente, grado));
            
            aux = aux.substr(aux.find('+')+1 , aux.length());
            
        }
        
        
        // adds the last monomio
        coeficiente = ed::stof( aux.substr(0, aux.find('x')) );
        // last charracter is \n
        grado = ed::stof( aux.substr(aux.find('^')+1, aux.length()) );
        p.addMonomio(*new ed::Monomio(coeficiente, grado));
        
        return stream;
    }



    ostream &operator<<(ostream &stream, Polinomio const &p)
    {
        bool first = true;
        for (size_t i = 0; i <= p.getGrado(); i++) {
            if (p.existeMonomio(i)) {
                if (!first)
                    stream<<"+"<<p.getMonomio(i);
                else{
                    stream<<p.getMonomio(i);
                    first = false;                    
                }
            }
        }
        return stream;
    }


} // Fin del espacio de nombres ed
