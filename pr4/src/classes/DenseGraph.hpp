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

	bool tryConnect(std::vector<Tree*>& headsT);
	bool areConnected(Tree t1, Tree t2);

	Tree minTreePrim();
	Tree minTreeKruskal();
	Tree minTreeFloyd();
};

#endif
