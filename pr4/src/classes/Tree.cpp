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
