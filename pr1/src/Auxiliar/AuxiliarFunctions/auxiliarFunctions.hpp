/*!
	\file auxiliarFunctions.hpp
	\brief prototipos de las funciones auxiliares para el monomio
*/

#ifndef __AUXILIAR_FUNCTIONS__
#define __AUXILIAR_FUNCTIONS__

#define FLOAT_NEAR_PRESICION 0.00000000003

#include <cmath>
#include <string>
#include <regex>

namespace ed
{
	/**
	 * \brief funcion que comprueba si dos flotantes son iguales
	 * \param real n1: numero 1
	 * \param real n2: numero 2
	 * \retval booleano: verdadero si son iguales, falso de lo contrario
	 */
	bool near(const float &n1, const float &n2);

	/**
	 * \brief funcion que comprueba si un string contiene un entero
	 * \param string s: string que contiene un entero
	 * \retval booleano: verdadero si es entero, falso de lo contrario
	 */
	bool isInt(std::string s);

	/**
	 * \brief funcion que comprueba si un string contiene un real
	 * \param string s: string que contiene un real
	 * \retval booleano: verdadero si es real, falso de lo contrario
	 */
	bool isFloat(std::string s);

	/**
	 * \brief convierte un string en un entero
	 * \param string s: string que contiene un entero
	 * \retval entero
	 */
	int stoi(std::string s);

	/**
	 * \brief convierte un string en un real
	 * \param string s: string que contiene un real
	 * \retval real
	 */
	float stof(std::string s);
}

#endif
