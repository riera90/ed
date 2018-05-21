#ifndef _DENSE_GRAPH_HPP_
#define _DENSE_GRAPH_HPP_

#include "Vertex.hpp"
#include "Edge.hpp"

class DenseGrpah {
private:
	std::vector<Vertex> _vertexes;

private:
	void remove_links(std::vector<Vertex>::iterator);

public:
	DenseGrpah ();
	void addVertex(Vertex vertex);
	bool RemoveVertex(Vertex vertex);
	// void minTreePrim();
	// void minTreeKruskal();
	// void minTreeFloyd();
};

#endif
