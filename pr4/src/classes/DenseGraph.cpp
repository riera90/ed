#include "DenseGraph.hpp"

bool DenseGrpah::remove_links(std::vector<Vertex*>::iterator base_it){
	Vertex* other;
	Vertex* base;
	Edge* edge;
	//for edges in base
	for (size_t pos_edge_base = 0; pos_edge_base < (*base_it)->getEdges().size(); pos_edge_base++){
		base=*(base_it);
		other=base->getEdges()[pos_edge_base]->getOtherVertex(*base);
		//for edge in other
		for (size_t pos_edge_other = 0; pos_edge_other < other->getEdges().size(); pos_edge_other++) {
			edge=other->getEdges()[pos_edge_other];
			//delete edge if same
			if (edge==base->getEdges()[pos_edge_base]) {
				if(! (other->removeEdge(edge))) return false;
			}
		}
	}
	return true;
}

bool DenseGrpah::addVertex(Vertex* vertex){
	for (size_t i = 0; i < _vertexes.size(); i++) {
		if (_vertexes[i]==vertex) {
			return false;
		}
	}
	std::vector<Vertex*>::iterator it;
	for (it = _vertexes.begin() ; it != _vertexes.end() ; it++) {
		Edge* edge=new Edge((*it),vertex);
		(*it)->addEdge(edge);
		vertex->addEdge(edge);
	}
	_vertexes.push_back(vertex);
	return true;
}

bool DenseGrpah::RemoveVertex(Vertex* vertex){
	std::vector<Vertex*>::iterator it;
	for (it=_vertexes.begin() ; it!=_vertexes.end() ; it++){
		if ( (*it) == vertex ) {
			remove_links(it);
			this->_vertexes.erase(it);
			return true;
		}
	}
	return false;
}


// Tree DenseGraph::minTreePrim(){
//
// }
