/*!
	\file Edge.hpp
	\brief clase Edge
*/

#ifndef _EDGE_HPP_
#define _EDGE_HPP_

#include "common.hpp"
#include "Vertex.hpp"

class Vertex;

class Edge {
private:
	Vertex* _vertex1;
	Vertex* _vertex2;
	std::string _flag;

public:
	inline Edge (Vertex* vertex1=NULL, Vertex* vertex2=NULL)
	:_vertex1(vertex1), _vertex2(vertex2) {_flag="";};
	inline Edge (Edge& edge)
	:_vertex1(edge.getVertex1()), _vertex2(edge.getVertex2()) {_flag=getFlag();};

	inline void setFlag(std::string flag){_flag=flag;}
	inline std::string getFlag() const {return _flag;}

	inline Vertex* getVertex1() {return _vertex1;};
	inline Vertex* getVertex2() {return _vertex2;};

	inline void setVertex1(Vertex* vertex) {_vertex1=vertex;};
	inline void setVertex2(Vertex* vertex) {_vertex2=vertex;};

	inline Vertex* getVertexParent() {return _vertex1;};
	inline Vertex* getVertexSon() {return _vertex2;};

	inline void setVertexParent(Vertex* vertex) {_vertex1=vertex;};
	inline void setVertexSon(Vertex* vertex) {_vertex2=vertex;};

	Vertex* getOtherVertex(Vertex baseVertex);
	bool setOtherVertex(Vertex baseVertex, Vertex* vertex);

	float getDistance();

	bool operator==(Edge& edge);
	inline bool operator!=(Edge& edge){
		return (!(*this==edge));
	};

	Edge& operator=(Edge& edge);
};

#endif
