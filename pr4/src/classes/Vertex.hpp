/*!
	\file Vertex.hpp
	\brief clase Vertex
*/


#ifndef _VERTEX_HPP_
#define _VERTEX_HPP_

#include "common.hpp"
#include "Point2D.hpp"
#include "Edge.hpp"
#include <vector>

class Edge;

//!< Definicion de la clase Vertex
class Vertex {
private:
	std::string _flag; //!< flag del vertice
	Point2D _point; //!< punti del vertice
	std::vector<Edge*> _edges; //lista de lados del vertice

public:
	/*!
		\brief		constructor de la clase Vertex
		\param		point: punto del vertice
		\note			function inline
	*/
	inline Vertex (Point2D point=Point2D()) {
		_point=point;
		_flag="";
	}

	/*!
		\brief		constructor de copiea de la clase Vertex
		\param		vertex: vertice a copiar de
		\note			function inline
	*/
	inline Vertex (const Vertex &vertex) {
		_point=vertex.getPoint();
		_flag=vertex.getFlag();
		_edges=std::vector<Edge*>();
	}

	/*!
		\brief		modificador de la flag
		\param		flag: string de flag
		\note			function inline
	*/
	inline void setFlag(std::string flag){_flag=flag;}

	/*!
		\brief		observador de la flag
		\return		string de flag
		\note			function inline
		\note			funcion constante
	*/
	inline std::string getFlag() const {return _flag;}

	/*!
		\brief		modificador del punto
		\param		point: nuevo punto
		\note			function inline
	*/
	inline void setPoint(Point2D point) {_point=point;}

	/*!
		\brief		observador del punto
		\return		punto
		\note			function inline
		\note			funcion constante
	*/
	inline Point2D getPoint() const {return _point;}

	/*!
		\brief		observador de lados
		\return		vector de punteros a lados
		\note			function inline
		\note			funcion constante
	*/
	inline std::vector<Edge*> getEdges() const {return _edges;}

	/*!
		\brief		modificador de addicion de lado
		\param		edge: nuevo lado (puntero)
		\return verdadero si la operacion se llevo a cabo con exito, falso en el caso contrario
	*/
	bool addEdge(Edge* edge);

	/*!
		\brief		modificador de borrado de lado
		\param		edge: lado a borrar (puntero)
		\return verdadero si la operacion se llevo a cabo con exito, falso en el caso contrario
	*/
	bool removeEdge(Edge* Edge);

	/*!
		\brief		operador observador de igualdad
		\param		vertex: vertice a comprobar con
		\return		booleano, verdadero si son iguales, falso en el caso contrario
	*/
	bool operator==(const Vertex& vertex) const ;

	/*!
		\brief		operador observador de desigualdad
		\param		vertex: vertice a comprobar con
		\return		booleano, falso si son iguales, verdadero en el caso contrario
		\note			funcion inline
	*/
	inline bool operator!=(const Vertex& vertex) const {
		return (!(*this==vertex));
	}

	/*!
		\brief		modificador de igualdad
		\param		vertex: vertice a igualar con
		\return		vertice
	*/
	Vertex& operator=(const Vertex& vertex);
};

#endif
