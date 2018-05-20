#include "Edge.hpp"

Vertex& Edge::getOtherVertex(const Vertex& baseVertex){
	if (baseVertex==getVertex1()) return getVertex2();
	if (baseVertex==getVertex2()) return getVertex1();
}

bool Edge::setOtherVertex(const Vertex& baseVertex, Vertex& vertex){
	if (baseVertex==getVertex1()){
		setVertex2(vertex);
		return true;
	}
	if (baseVertex==getVertex2()){
		setVertex1(vertex);
		return true;
	}
	return false;
}

bool Edge::operator==(const Edge& edge) const {
	if (!((this->getVertex1())==(edge.getVertex1()))) return false;
	if (!((this->getVertex2())==(edge.getVertex2()))) return false;
	return true;
}

Edge& Edge::operator=(const Edge& edge){
	this->setVertex1(edge.getVertex1());
	this->setVertex2(edge.getVertex2());
	return *this;
}
