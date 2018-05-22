#include "Tree.hpp"

Vertex* Tree::getParent(Vertex* SonNode) {
	if (SonNode==_root) return NULL;
	return SonNode->getEdges()[0]->getVertexParent();
}

std::vector<Vertex*> Tree::getSons(Vertex* parentNode){
	std::vector<Vertex*> sons;
	if (parentNode==NULL) {
		// std::cout << "is NULL!!" << '\n';
		return sons;
	}
	//for edge in edges
	// std::cout << "not NULL, size is <" << parentNode->getEdges().size() << ">\n";
	for (int i = 0; i < parentNode->getEdges().size(); i++) {
		sons.push_back(parentNode->getEdges()[i]->getVertexSon());
	}
	return sons;
}

void Tree::printTree(){
	int level=0;
	iPrint(_root);
}

void Tree::iPrint(Vertex* vertex){
	//for edge in base
	for (size_t i = 0; i < vertex->getEdges().size(); i++) {
		if (vertex->getEdges()[i]->getVertexSon()!=vertex) {
			std::cout<<vertex->getPoint().getPointString();
			std::cout<<" -> ";
			std::cout<<vertex->getEdges()[i]->getVertexSon()->getPoint().getPointString();
			std::cout<<"\t";
		}
	}
	std::cout<<"\n";
	for (size_t i = 1; i < vertex->getEdges().size(); i++) {
		iPrint(vertex->getEdges()[i]->getVertexSon());
	}
}
