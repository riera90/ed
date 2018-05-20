#ifndef _VERTEX_HPP_
#define _VERTEX_HPP_

#include "Point3D.hpp"
// #include "Edge.hpp"
#include <list>

class Edge;

class Vertex {
private:
	Point3D _point;
	// std::list<Edge*> _edges;

public:
	inline Vertex (Point3D point=Point3D()) {_point=point;};

	inline void setPoint(Point3D point) {
		_point=point;
	};
	inline Point3D getPoint() const {return _point;};

	// inline std::list<Edge*> getEdges() {return _edges;};
	//
	// bool addEdge(Edge* edge);
	// bool removeEdge(Edge Edge);

	bool operator==(const Vertex& vertex) const ;
	Vertex& operator=(const Vertex& vertex);
};

#endif
