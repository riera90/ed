#ifndef _EDGE_HPP_
#define _EDGE_HPP_

#include "Vertex.hpp"

class Vertex;

class Edge {
private:
	Vertex* _vertex1;
	Vertex* _vertex2;

public:
	inline Edge (Vertex* vertex1=NULL, Vertex* vertex2=NULL):_vertex1(vertex1), _vertex2(vertex2) {};
	inline Edge (Edge& edge) {*this=edge;};

	inline Vertex* getVertex1() {return _vertex1;};
	inline Vertex* getVertex2() {return _vertex2;};

	inline void setVertex1(Vertex* vertex) {_vertex1=vertex;};
	inline void setVertex2(Vertex* vertex) {_vertex2=vertex;};

	Vertex* getOtherVertex(Vertex* baseVertex);
	bool setOtherVertex(Vertex* baseVertex, Vertex* vertex);

	bool operator==(Edge& edge);
	Edge& operator=(Edge& edge);
};

#endif
