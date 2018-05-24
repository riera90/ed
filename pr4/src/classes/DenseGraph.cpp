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
	int timer=0;
	int totalTimer=0;

	Tree tree;
	bool isDone=false;

	float shortestDistance;
	float distance;

	Vertex* nearestVertexG;//in the graph
	Vertex* nearestVertexT;//in the tree
	Vertex* baseVertexG;
	Vertex* baseVertexT;
	Edge* shortestEdgeG;

	tree.setRoot(new Vertex(this->getVertexes()[0]->getPoint()));
	this->getVertexes()[0]->setFlag("visited");

	//searchs for the shortest edge contained in a visited vertex (one per cicle)
	while(!isDone)
	{
		timer++;
		//sets the shortestDistance and shortestEdgeG to default
		shortestDistance = -1;
		shortestEdgeG = NULL;

		//iterates trough all the vertexes
		for (size_t vertexIndex = 0; vertexIndex < this->getVertexes().size() && !isDone; vertexIndex++)
		{
			//only visited vertexes (filter)
			if (this->getVertexes()[vertexIndex]->getFlag()=="visited")
			{
				#ifdef DEBUG
				std::cout << "\t\ttesting basepoint ("<<this->getVertexes()[vertexIndex]->getPoint().getPointString()<<") flagged as <"<<this->getVertexes()[vertexIndex]->getFlag()<<">" << '\n';
				#endif

				//seeks a new shortest edge in the current vertex
				for (	size_t edgeIndex=0;\
				edgeIndex<this->getVertexes()[vertexIndex]->getEdges().size(); edgeIndex++)
				{
					distance = this	->getVertexes()[vertexIndex]\
													->getEdges()   [edgeIndex]\
													->getDistance();
					#ifdef DEBUG
					std::cout <<"testing: "<<distance<< '\n';
					#endif
					totalTimer++;
					if ( (shortestDistance > distance) || (shortestDistance == -1) )
					{
						//only not visited vertexes
						if (this->getVertexes()[vertexIndex]\
										->getEdges()   [edgeIndex]\
										->getOtherVertex(*this->getVertexes()[vertexIndex])\
										->getFlag()\
								!="visited")
						{
							baseVertexG=this->getVertexes()[vertexIndex];
							shortestDistance = distance;
							shortestEdgeG = this->getVertexes()[vertexIndex]\
																	->getEdges()   [edgeIndex];
							nearestVertexG = shortestEdgeG->getOtherVertex(*this->getVertexes()[vertexIndex]);
							#ifdef DEBUG
							std::cout <<"new shortest distance with point ("<<nearestVertexG->getPoint().getPointString()<<") < "<<shortestEdgeG->getDistance()<<">\n";
							#endif
						}else{
							#ifdef DEBUG
							std::cout << "    maked as visited, not entering" << '\n';
							#endif
						}
					}
				}
			}
		}

		//update the tree with the new shortest edge
		#ifdef DEBUG
		std::cout << "\t\t\t\t\tnearest vertex flaged as visited ("<<nearestVertexG->getPoint().getPointString()<<")\n";
		#endif
		nearestVertexT=new Vertex(nearestVertexG->getPoint());
		baseVertexT=tree.SearchVertex(baseVertexG);
		tree.addSon(baseVertexT,nearestVertexT);

		//sets the new vertex to visited
		nearestVertexG->setFlag("visited");

		//checks if there are nodes left to be visited/connected
		isDone=true;
		for (size_t j = 0; j < this->getVertexes().size() && isDone ; j++) {
			if (this->getVertexes()[j]->getFlag()!="visited"){
				isDone=false;
			}
		}

	}
	#ifdef DEBUG
	std::cout << "done in "<<timer<<" total iretations and "<<totalTimer<<" comprobations\n";
	#endif
	return tree;
}




bool DenseGrpah::tryConnect(std::vector<Tree*>& headsT)
{
	std::vector<Tree*>::iterator itTree;
	std::vector<Tree*>::iterator itTreeInner;

	std::vector<Vertex*> list;
	std::vector<Vertex*> listInner;

	std::vector<Vertex*>::iterator itList;
	std::vector<Vertex*>::iterator itListInner;

	for (itTree = headsT.begin(); itTree != headsT.end(); itTree++)
	{
		for (itTreeInner = headsT.begin(); itTreeInner != headsT.end(); itTreeInner++)
		{
			if (itTree!=itTreeInner)
			{

				list = (*itTree)->getAllVertexes();
				listInner = (*itTreeInner)->getAllVertexes();

				for (itList = list.begin(); itList < list.end(); itList++)
				{
					for (itListInner = listInner.begin(); itListInner < listInner.end(); itListInner++)
					{
						if((*itList)->getPoint()==(*itListInner)->getPoint())
						{
							#ifdef DEBUG
							std::cout << "Vertice duplicado, eliminando entrada doble" << '\n';
							#endif
							headsT.erase(itTreeInner);
							return true;
						}
					}
				}

			}
		}
	}
	return false;
}





Tree DenseGrpah::minTreeKruskal(){
	int timer=0;
	int totalTimer=0;

	Tree tree;
	bool isDone=false;

	float shortestDistance;
	float distance;

	std::vector<Tree*> headsT;
	std::vector<Vertex*> vertexG;

	while(tryConnect(headsT));

	// std::vector<Vertex*> temp=getVertexes();
	// std::vector<Vertex*>::iterator it;
	//
	// for ( it = temp.begin(); it < temp.end(); it++) {
	// }
	//
	// while(!isDone)
	// {
	// 	isDone=true;
	// }

	return tree;
}





Tree DenseGrpah::minTreeFloyd(){
	Tree tree;
	for (size_t i = 0; i < this->getVertexes().size(); i++) {
	}
	return tree;
}
