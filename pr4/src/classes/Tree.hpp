/*!
	\file Tree.hpp
	\brief clase Tree
*/

#ifndef _TREE_HPP_
#define _TREE_HPP_

#include "common.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include <algorithm>

//This is a really bad implementation of a tree class, is only use for printing a tree on the screen.
//Please, don't re-use this class.

//!< Definicion de la clase Tree
class Tree {
private:
	Vertex* _root; //!< Cabeza del arbol
	// Vertex* _current; //not in use

private:

public:
	/*!
		\brief		constructor de la clase Tree
	*/
	inline Tree () {
		_root=NULL;
		// _current=NULL;
	}

	/*!
		\brief		Observador de la raiz
		\return		untero a vertice Vertex
		\note			funcion inline
	*/
	inline Vertex* getRoot() {return _root;}

	/*!
		\brief		modificador de la raiz
		\param		root: puntero a vertice Vertex
		\note			funcion inline
	*/
	inline void setRoot(Vertex* root) {_root=root;}

	/*!
		\brief		observador del padre del vertice
		\param		SonNode: puntero a vertice Vertex
		\return		puntero a vertice del padre del vertice pasado por parametro
	*/
	Vertex* getParent(Vertex* SonNode) ;

	/*!
		\brief		observador de los hijos del vertice pasado por parametro
		\param		parentNode: puntero a vertice Vertex
		\return		lista de punteros a vertices
	*/
	std::vector<Vertex*> getSons(Vertex* parentNode);

	/*!
		\brief		observador de todos los vercices conectados a el pasado
		\param		parentNode: puntero a vertice Vertex
		\return		lista de punteros a vertices
	*/
	std::vector<Vertex*> getAllRelactioned(Vertex* parentNode);

	/*!
		\brief		modicifador de addicion de hijo
		\param		ParentNode: puntero a vertice Vertex padre
		\param		newSonNode: nuevo vertice hijo
	*/
	void addSon(Vertex* ParentNode, Vertex* newSonNode);

	/*!
		\brief		observador de todos los vercices del arbol
		\return		lista de punteros a vertices
	*/
	std::vector<Vertex*> getAllVertexes();

	/*!
		\brief		observador interno de todos los vertices de un nivel del arbol
		\param		base: puntero a vertice base
		\param		visited: lista de vertices visitados
		\return		lista de punteros a vertices
	*/
	private: std::vector<Vertex*> iGetAllVertexes(Vertex* base, std::vector<Vertex*> visited);

public:
	/*!
		\brief		observador de busqueda de un vertice del arbol
		\param		vertex: puntero a vertive a buscar
		\return		puntero a vertice del arbol
	*/
	Vertex* SearchVertex(Vertex* vertex);

	/*!
		\brief		escritor por pantalla del arbol
	*/
	void printTree();

	/*!
		\brief		escritor interno por pantalla de un nivel del arbol
		\param		base: puntero a vertice base
	*/
	private: void iPrint(Vertex* base);

public:
	/*!
		\brief		modificador de conexion de arboles
		\param		headsT: lista de punteros a arboles de la stl
		\return		booleano, verdadero si se han conectado al menos un par de arboles, falso de contrario
	*/
	bool tryConnect(std::vector<Tree*>& headsT);

	/*!
		\brief		observador de conexion de arboles
		\param		t: arbol Tree
		\return		booleano, verdadero si el par de arboles this y el parametro estan conectados, falso de contrario
	*/
	bool areConnected(Tree t);
};

#endif
