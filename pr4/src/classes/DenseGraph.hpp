/*!
	\file DenseGraph.hpp
	\brief clase DenseGraph
*/


#ifndef _DENSE_GRAPH_HPP_
#define _DENSE_GRAPH_HPP_

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tree.hpp"

//!< Definición de la clase DenseGraph
class DenseGraph {
private:
	std::vector<Vertex*> _vertexes; //!< vector de vertices

private:
	/*!
		\brief		elimina los lados de un vertice y actualiza los conectados, eliminando dicho lado de todos ellos
		\param		base_it: iterador apuntando el vertice a eliminar todos sus lados
	*/
	bool remove_links(std::vector<Vertex*>::iterator base_it);

public:
	/*!
		\brief		constructor de la clase DenseGraph
		\note			funcion inline
	*/
	inline DenseGraph () {}

	/*!
		\brief		observador de el vector de vertices
		\return		Vector de la stl de punteros a vertices
		\note			funcion inline
	*/
	inline std::vector<Vertex*> getVertexes(){return _vertexes;}

	/*!
		\brief		modificador de adicion de un vertice a el grafo
		\param		vertex: puntero a vectice
	*/
	bool addVertex(Vertex* vertex);

	/*!
		\brief		modificador de eliminacion de un vertice del grafo
		\param		vertex: puntero a vectice
	*/
	bool RemoveVertex(Vertex* vertex);

	/*!
		\brief		observador de el arbol minimo por prim del grafo
		\return		instancia de la clase Tree
	*/
	Tree minTreePrim();

	/*!
		\brief		observador de el arbol minimo por kruskal del grafo
		\return		instancia de la clase Tree
	*/
	Tree minTreeKruskal();
	// Tree minTreeFloyd();


	/*!
		\brief		impresor de la lista de arboles
		\param		vector de la stl de punteros a arboles Tree
	*/
	void printListTrees(std::vector<Tree*> headsT);

	/*!
		\brief		impresor de la matrix de vertices de arboles
	*/
	void print();

	/*!
		\brief		observador de la matrix de lados89
		'¡0'
		\return		vector de vectores de punteros a lados (Edge) de la stl
	*/
	std::vector<std::vector<Edge*>> getEdgesMatrix();
};

#endif
