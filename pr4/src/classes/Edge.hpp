/*!
	\file Edge.hpp
	\brief clase Edge
*/

#ifndef _EDGE_HPP_
#define _EDGE_HPP_

#include "common.hpp"
#include "Vertex.hpp"

class Vertex;


//!< Definicion de la clase Edge
class Edge {
private:
	Vertex* _vertex1; //!< puntero a vertice 1 del lado
	Vertex* _vertex2;	//!< puntero a vertice 2 del lado
	std::string _flag;  //!< flag del lado, puede usarse a placer

public:
	/*!
		\brief		constructor de la clase DenseGraph
		\param		vertex1: puntero a vertice 1 del lado
		\param		vertex2: puntero a vertice 2 del lado
		\note			funcion inline
	*/
	inline Edge (Vertex* vertex1=NULL, Vertex* vertex2=NULL)
	:_vertex1(vertex1), _vertex2(vertex2) {_flag="";};

	/*!
		\brief		constructor de copue de la clase DenseGraph
		\param		edge: lado a copiar
		\note			la copia no genera vertices nuevos, los reulitiza
		\note			funcion inline
	*/
	inline Edge (Edge& edge)
	:_vertex1(edge.getVertex1()), _vertex2(edge.getVertex2()) {_flag=getFlag();};

	/*!
		\brief		modificador de la flag
		\param		flag: flag nueva
		\note			funcion inline
	*/
	inline void setFlag(std::string flag){_flag=flag;}

	/*!
		\brief		observador de la flag
		\return		flag del lado
		\note			funcion inline
	*/
	inline std::string getFlag() const {return _flag;}

	/*!
		\brief		observador del vertice 1 del lado
		\return		puntero al vertice 1
		\note			funcion inline
	*/
	inline Vertex* getVertex1() {return _vertex1;};

	/*!
		\brief		observador del vertice 2 del lado
		\return		puntero al vertice 2
		\note			funcion inline
	*/
	inline Vertex* getVertex2() {return _vertex2;};

	/*!
		\brief		observador del vertice 1 del lado
		\return		puntero al vertice 1
		\note			funcion inline
	*/
	inline void setVertex1(Vertex* vertex) {_vertex1=vertex;};

	/*!
		\brief		observador del vertice 2 del lado
		\return		puntero al vertice 2
		\note			funcion inline
	*/
	inline void setVertex2(Vertex* vertex) {_vertex2=vertex;};

	/*!
		\brief		observador del vertice 1 del lado
		\return		puntero al vertice 1
		\note			funcion inline
	*/
	inline Vertex* getVertexParent() {return _vertex1;};

	/*!
		\brief		observador del vertice 2 del lado
		\return		puntero al vertice 2
		\note			funcion inline
	*/
	inline Vertex* getVertexSon() {return _vertex2;};

	/*!
		\brief		observador del vertice 1 del lado
		\return		puntero al vertice 1
		\note			funcion inline
	*/
	inline void setVertexParent(Vertex* vertex) {_vertex1=vertex;};

	/*!
		\brief		observador del vertice 2 del lado
		\return		puntero al vertice 2
		\note			funcion inline
	*/
	inline void setVertexSon(Vertex* vertex) {_vertex2=vertex;};

	/*!
		\brief		observador del vertice opuesto al pasado por parametro
		\param		baseVertex: puntero a vertice base
		\return		puntero opuesto
	*/
	Vertex* getOtherVertex(Vertex baseVertex);

	/*!
		\brief		modificador del vertice opuesto al pasado por parametro
		\param		baseVertex: puntero a vertice base
		\param		vertex: puntero a vertice opuesto
	*/
	bool setOtherVertex(Vertex baseVertex, Vertex* vertex);

	/*!
		\brief		observador de la distancia entre los dos vertices
		\return		distancia entre los dos vertices del lado
	*/
	float getDistance();

	/*!
		\brief		operador observador de igualdad
		\param		edge: lado a comprobar con
		\return		booleano, verdadero si son iguales, falso en el caso contrario
	*/
	bool operator==(Edge& edge);

	/*!
		\brief		operador observador de desigualdad
		\param		edge: lado a comprobar con
		\return		booleano, falso si son iguales, verdadero en el caso contrario
		\note			funcion inline
	*/
	inline bool operator!=(Edge& edge){
		return (!(*this==edge));
	};

	/*!
		\brief		modificador de igualdad
		\param		edge: lado a igualar con
		\return		lado
	*/
	Edge& operator=(Edge& edge);
};

#endif
