#ifndef _VERTEX_HPP_
#define _VERTEX_HPP_

#include "Point2D.hpp"
#include "Edge.hpp"
#include <vector>

class Edge;

class Vertex {
private:
	std::string _tag;
	Point2D _point;
	std::vector<Edge*> _edges;

public:
	inline Vertex (Point2D point=Point2D()) {
		_point=point;
		_tag="";
	}

	inline void setTag(std::string tag){_tag=tag;}
	inline std::string getTag() const {return _tag;}

	inline void setPoint(Point2D point) {_point=point;}

	inline Point2D getPoint() const {return _point;}

	inline std::vector<Edge*> getEdges() const {return _edges;}

	bool addEdge(Edge* edge);
	bool removeEdge(Edge* Edge);

	bool operator==(const Vertex& vertex) const ;
	inline bool operator!=(const Vertex& vertex) const {
		return (!(*this==vertex));
	}

	Vertex& operator=(const Vertex& vertex);
};

#endif
