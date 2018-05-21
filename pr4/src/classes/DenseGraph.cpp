#include "DenseGraph.hpp"

void DenseGrpah::remove_links(std::vector<Vertex>::iterator base){
	Vertex* other;
	Edge* edge;
	//for edges in base
	for (size_t pos_edge_base = 0; pos_edge_base < base->getEdges().size(); pos_edge_base++){
		other=base->getEdges()[pos_edge_base]->getOtherVertex(&(*base));
		//for edge in other
		for (size_t pos_edge_other = 0; pos_edge_other < other->getEdges().size(); pos_edge_other++) {
			edge=other->getEdges()[pos_edge_other];
			//delete edge if same
			if (edge==base->getEdges()[pos_edge_base]) {
				other->removeEdge(edge);
			}
		}
	}
}

void DenseGrpah::addVertex(Vertex vertex){
	std::vector<Vertex>::iterator it;
	for (it = _vertexes.begin() ; it != _vertexes.end() ; it++) {
		Edge* edge=new Edge(&(*it),&vertex);
		it->addEdge(edge);
		vertex.addEdge(edge);
	}
	_vertexes.push_back(vertex);
}

bool DenseGrpah::RemoveVertex(Vertex vertex){
	std::vector<Vertex>::iterator it;
	for (it=_vertexes.begin() ; it!=_vertexes.end() ; it++){
		if ( (*it) == vertex ) {
			remove_links(it);
			this->_vertexes.erase(it);
			return true;
		}
	}
	return false;
}
