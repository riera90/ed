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



#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:
	float coeficiente_;
	int grado_;


	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	//! \name Constructores de la clase Monomio

	Monomio(float coeficiente = 0, int grado = 0);
	Monomio(const Monomio &monomio);



	//! \name Observadores: funciones de consulta de la clase Monomio

	float getCoeficiente() const;
	int getGrado() const;



	//! \name Funciones de modificación de la clase Monomio

	bool setCoeficiente(float coeficiente);
	bool setGrado(int grado);



	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio

	// Operadores de asignación

	Monomio & operator=(Monomio const &m);

	Monomio & operator=(double const &x);


	// Operadores aritméticos y asignación

	Monomio & operator+=(const Monomio &m);

	Monomio & operator-=(const Monomio &rhs);

	Monomio & operator*=(const Monomio &rhs);
	
	Monomio & operator*=(const float &rhs);

	Monomio & operator/=(const Monomio &rhs);

	Monomio & operator/=(const float &rhs);



	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

	// COMPLETAR


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio

	// COMPLETAR



};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
