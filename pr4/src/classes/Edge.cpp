#include "Edge.hpp"

Vertex* Edge::getOtherVertex(Vertex baseVertex){
	if (baseVertex==*getVertex1()) return getVertex2();
	if (baseVertex==*getVertex2()) return getVertex1();
}

bool Edge::setOtherVertex(Vertex baseVertex, Vertex* vertex){
	if (baseVertex==*getVertex1()){
		setVertex2(vertex);
		return true;
	}
	if (baseVertex==*getVertex2()){
		setVertex1(vertex);
		return true;
	}
	return false;
}

float Edge::getDistance(){
	return getVertex1()->getPoint().distance(getVertex2()->getPoint());
}

bool Edge::operator==(Edge& edge){
	if (!(this->getVertex1()==edge.getVertex1())) return false;
	if (!(this->getVertex2()==edge.getVertex2())) return false;
	return true;
}

Edge& Edge::operator=(Edge& edge){
	this->setVertex1(edge.getVertex1());
	this->setVertex2(edge.getVertex2());
	return *this;
}
