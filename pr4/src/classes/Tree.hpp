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

class Tree {
private:
	Vertex* _root;
	// Vertex* _current; //not in use

private:

public:
	inline Tree () {
		_root=NULL;
		// _current=NULL;
	}
	Vertex* getRoot() {return _root;}
	void setRoot(Vertex* root) {_root=root;}

	Vertex* getParent(Vertex* SonNode) ;
	std::vector<Vertex*> getSons(Vertex* parentNode);
	std::vector<Vertex*> getAllRelactioned(Vertex* parentNode);

	void addSon(Vertex* ParentNode, Vertex* newSonNode);

	std::vector<Vertex*> getAllVertexes();
	std::vector<Vertex*> iGetAllVertexes(Vertex* base, std::vector<Vertex*> visited);

	Vertex* SearchVertex(Vertex* vertex);

	void printTree();
	void iPrint(Vertex* base);

	bool tryConnect(std::vector<Tree*>& headsT);
	bool areConnected(Tree t);
};

#endif
