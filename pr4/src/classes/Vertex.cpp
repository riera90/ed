#include "Tree.hpp"

bool Vertex::addEdge(Edge* edge){
	//checks if the MemAddress of an edge is in the list
	std::vector<Edge*>::iterator it;
	for (it = _edges.begin(); it!=_edges.end(); it++) {
		if (*it==edge) return false;
	}
	_edges.push_back(edge);
	return true;
}

bool Vertex::removeEdge(Edge* edge){
	//checks if the edge is in the list
	std::vector<Edge*>::iterator it;
	for (it = _edges.begin(); it!=_edges.end(); it++) {
		if ((*it)==edge) {
			_edges.erase(it);
			return true;
		}
	}
	return false;
}

bool Vertex::operator==(const Vertex& vertex) const {
	if (!(this->getPoint()==vertex.getPoint())) return false;
	return true;
}

Vertex& Vertex::operator=(const Vertex& vertex){
	this->setPoint(vertex.getPoint());
	for (size_t i = 0; i < vertex.getEdges().size(); i++) {
		this->addEdge(vertex.getEdges()[i]);
	}
	return *this;
}