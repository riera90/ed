/*!
	\file Point2D.hpp
	\brief clase Point2D
*/

#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <sstream> //string included in this library
#include <iostream>
#include <cmath>
#include <cstdlib>

#include "common.hpp"

//!< Definicion de la clase Point2D
class Point2D {
private:
	float _x; //!< coordenada x
	float _y; //!< coordenada y

public:
	/*!
		\brief		constructor de la clase Point2D
		\param		x: coordenada x
		\param		y: coordenada y
		\note			funcion inline
	*/
	inline Point2D (float x=0, float y=0) : _x(x), _y(y) {};

	/*!
		\brief		constructor de copia de la clase Point2D
		\param		point: punto a copiar
		\note			funcion inline
	*/
	inline Point2D (const Point2D& point){*this=point;};

	/*!
		\brief		observador de la coordenada x
		\return 	coordenada x
		\note			funcion inline
	*/
	inline float getX() const { return _x; }

	/*!
		\brief		observador de la coordenada y
		\return 	coordenada y
		\note			funcion inline
	*/
	inline float getY() const { return _y; }

	/*!
		\brief		modificador de la coordenada x
		\param 		x: coordenada x
		\note			funcion inline
	*/
	inline void setX(float x) { _x=x; }

	/*!
		\brief		modificador de la coordenada y
		\param 		y: coordenada y
		\note			funcion inline
	*/
	inline void setY(float y) { _y=y; }

	/*!
		\brief		modificador del punto en formato string
		\param 		point: string del punto en formato x y
	*/
	void SetPointString(std::string point);

	/*!
		\brief		obsercador del punto en formato string
		\return		string del punto en formato x y
		\note			funcion constante
	*/
	std::string getPointString() const ;

	/*!
		\brief		lector de un punto por teclado
	*/
	void readPointStdin();

	/*!
		\brief		escritor de un punto por pantalla
	*/
	void writePointStdout() const ;

	/*!
		\brief		operador observador de igualdad
		\param		point: punto a comprobar con
		\return		booleano, verdadero si son iguales, falso en el caso contrario
	*/
	bool operator==(const Point2D& point) const ;

	/*!
		\brief		operador observador de desigualdad
		\param		point: punto a comprobar con
		\return		booleano, falso si son iguales, verdadero en el caso contrario
		\note			funcion inline
	*/
	inline bool operator!=(const Point2D& point) const {
		return (!(*this==point));
	};

	/*!
		\brief		modificador de igualdad
		\param		point: punto a igualar con
		\return		punto
	*/
	Point2D& operator=(const Point2D& point);

	/*!
		\brief		observador de distancia entre this y el punto pasado por parametro
		\param		point: punto a comprobar con
		\return		distancia real entre puntos
	*/
	float distance(const Point2D& point) const ;
};

#endif
