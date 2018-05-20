#ifndef _EDGE_HPP_
#define _EDGE_HPP_

#include "Vertex.hpp"

class Vertex;

class Edge {
private:
	Vertex& _vertex1;
	Vertex& _vertex2;

public:
	inline Edge (Vertex& vertex1, Vertex& vertex2)
	:_vertex1(vertex1), _vertex2(vertex2) {};
	inline Edge (Edge& edge)
	:_vertex1(edge.getVertex1()), _vertex2(edge.getVertex2()) {};

	inline Vertex& getVertex1() const {return _vertex1;};
	inline Vertex& getVertex2() const {return _vertex2;};

	inline void setVertex1(Vertex& vertex) {_vertex1=vertex;};
	inline void setVertex2(Vertex& vertex) {_vertex2=vertex;};

	Vertex& getOtherVertex(const Vertex& baseVertex);
	bool setOtherVertex(const Vertex& baseVertex, Vertex& vertex);

	bool operator==(const Edge& edge) const ;
	Edge& operator=(const Edge& edge);
};

#endif
