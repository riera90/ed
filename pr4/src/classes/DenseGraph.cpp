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

Tree DenseGrpah::minTreePrim(){
	Tree tree;
	bool isDone=false;
	float shortestDistance;
	float distance;
	Edge* shortestEdge;
	tree.setRoot(new Vertex(this->getVertexes()[0]->getPoint()));
	this->getVertexes()[0]->setFlag("visited");

	while(!isDone){
		shortestDistance = -1;
		shortestEdge = NULL;

		//iterates trough all the vertexes
		for (size_t vertexIndex = 0; vertexIndex < this->getVertexes().size() && !isDone; vertexIndex++)
		{
			//only visited vertexes
			if (this->getVertexes()[vertexIndex]->getFlag()=="visited")
			{


				//seeks a new shortest edge in the vertex
				for (	size_t edgeIndex=0;\
				edgeIndex<this->getVertexes()[vertexIndex]->getEdges().size(); edgeIndex++)
				{
					distance = this	->getVertexes()[vertexIndex]\
													->getEdges()   [edgeIndex]\
													->getDistance();
					if ( (shortestDistance > distance) || (shortestDistance == -1) )
					{
						shortestDistance = distance;
						shortestEdge = this	->getVertexes()[vertexIndex]\
																->getEdges()   [edgeIndex];
					}
				}

				//update the tree with the new shortest edge



			}
		}

		//checks if there are nodes left for connecting
		isDone=true;
		for (size_t j = 0; j < this->getVertexes().size() && isDone ; j++) {
			if (this->getVertexes()[j]->getFlag()!="visited"){
				isDone=false;
			}
		}

	}
	return tree;
}

Tree DenseGrpah::minTreeKruskal(){
	Tree tree;
	for (size_t i = 0; i < this->getVertexes().size(); i++) {
	}
	return tree;
}

Tree DenseGrpah::minTreeFloyd(){
	Tree tree;
	for (size_t i = 0; i < this->getVertexes().size(); i++) {
	}
	return tree;
}
