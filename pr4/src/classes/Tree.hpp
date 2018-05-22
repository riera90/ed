#ifndef _TREE_HPP_
#define _TREE_HPP_

#include "Vertex.hpp"
#include "Edge.hpp"

//This is a really bad implementation of a tree class, is only use for printing a tree on the screen.
//Please, don't re-use this class.

class Tree {
private:
	Vertex* _root;
	Vertex* _current;

private:

public:
	inline Tree () {
		_root=NULL;
		_current=NULL;
	}
	Vertex* getRoot() const {return _root;}
	Vertex* getParent(Vertex* SonNode) const ;
	std::vector<Vertex*> getSons(Vertex* parentNode);
	void addSon(Vertex* ParentNode, Vertex* newSonNode);
	void printTree() const ;
};

#endif
