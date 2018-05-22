#include "Tree.hpp"

Vertex* Tree::getParent(Vertex* SonNode) const {
	if (SonNode==_root) return NULL;
	return SonNode->getEdges()[0]->getVertexParent();
}

std::vector<Vertex*> Tree::getSons(Vertex* parentNode){
	std::vector<Vertex*> sons;
	parentNode->getEdges();
	std::cout << "test1: <"<<">\n";
	//for edge in edges
	for (int i = 0; i < parentNode->getEdges().size(); i++) {
		std::cout << "test" << '\n';
		// sons.push_back(parentNode->getEdges()[i]->getVertexSon());
	}
	return sons;
}
