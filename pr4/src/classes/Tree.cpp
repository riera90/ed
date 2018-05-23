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

std::vector<Vertex*> Tree::getAllVertexes(){
	std::vector<Vertex*> list1;
	std::vector<Vertex*> list2 = iGetAllVertexes(getRoot());
	list1.push_back(getRoot());
	list1.insert(list1.end(),list2.begin(),list2.end());
	return list1;
}

std::vector<Vertex*> Tree::iGetAllVertexes(Vertex* base){
	std::vector<Vertex*> list;
	std::vector<Vertex*> list_temp;
	for (size_t i = 0; i < base->getEdges().size(); i++) {
		if (base->getEdges()[i]->getVertexSon()!=base) {
			list.push_back(base->getEdges()[i]->getVertexSon());
		}
	}
	for (size_t i = 1; i < base->getEdges().size(); i++) {
		if (base->getEdges()[i]->getVertexSon()!=base){
			list_temp=iGetAllVertexes(base->getEdges()[i]->getVertexSon());
			list.insert(list.end(),list_temp.begin(),list_temp.end());
		}
	}

	return list;
}

Vertex* Tree::SearchVertex(Vertex* vertex){
	for (std::vector<Vertex*>::iterator it = getAllVertexes().begin() ;\
	it != getAllVertexes().end() ; it++)
	{

	}
}

void Tree::printTree(){
	int level=0;
	if (_root==NULL) {
		std::cout <<"the tree is empty!"<< '\n';
	}else{
		iPrint(_root);
	}
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
		if (vertex->getEdges()[i]->getVertexSon()!=vertex) {
			iPrint(vertex->getEdges()[i]->getVertexSon());
		}
	}
}
