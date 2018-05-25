/*!
	\file DenseGraph.hpp
	\brief clase DenseGraph
*/


#ifndef _DENSE_GRAPH_HPP_
#define _DENSE_GRAPH_HPP_

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tree.hpp"

class DenseGraph {
private:
	std::vector<Vertex*> _vertexes;

private:
	bool remove_links(std::vector<Vertex*>::iterator);

public:
	inline DenseGraph () {}
	std::vector<Vertex*> getVertexes(){return _vertexes;}
	bool addVertex(Vertex* vertex);
	bool RemoveVertex(Vertex* vertex);

	Tree minTreePrim();
	Tree minTreeKruskal();
	Tree minTreeFloyd();

	void printListTrees(std::vector<Tree*> headsT);
	void print();
	std::vector<std::vector<Edge*>> getEdgesMatrix();
};

#endif
