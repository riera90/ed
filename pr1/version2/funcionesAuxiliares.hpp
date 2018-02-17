
/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author
  \date
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Vector3D.hpp"


namespace ed
{
	/*!
		\brief   Muestra el menú del programa principal
		\return  Devuelve el número de opción elegido
	*/
	/*!
	\brief imprime el menu de el main
	*/
	int menu();

	/*!
	\brief lee por teclado 3 vectores
	\param vector: 3 vectores
	*/
	void leerVectores(ed::Vector3D &u, ed::Vector3D &v, ed::Vector3D &w);

	/*!
	\brief escribe en pantalla 3 vectores
	\param vector: 3 vectores
	*/
	void escribirVectores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);

	/*!
	\brief prueba los observadores de dos vectores
	\param vector: 2 vectores
	*/
	void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v);

	/*!
	\brief modifica dos vectores y una constante
	\param vector: 2 vectores
	\param real: una constante
	*/
	void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k);

	/*!
	\brief prueba el producto escalar de dos vectores
	\param vector: 2 vectores
	*/
	void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v);

	/*!
	\brief prueba el producto escalar de dos vectores
	\param vector: 2 vectores
	*/
	void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v);

	/*!
	\brief prueba el producto mixto con vectores
	\param vector: 3 vectores
	*/
	void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);

	/*!
	\brief prueba los operadores tres vectores y una constante
	\param vector: 3 vectores
	\param real: constante
	*/
	void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k);



} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif
