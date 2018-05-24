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

void Tree::addSon(Vertex* ParentNode, Vertex* newSonNode){
	Edge* edge=new Edge(ParentNode, newSonNode);
	newSonNode->addEdge(edge);
	ParentNode->addEdge(edge);
}


std::vector<Vertex*> Tree::getAllVertexes(){
	std::vector<Vertex*> list1;
	std::vector<Vertex*> list2 = iGetAllVertexes(getRoot());
	list1.push_back(getRoot());
	list1.insert(list1.end(),list2.begin(),list2.end());
	return list1;
}

std::vector<Vertex*> Tree::iGetAllVertexes(Vertex* base){
	std::vector<Vertex*>::iterator it;
	std::vector<Vertex*> directSons;
	std::vector<Vertex*> listTemp;
	std::vector<Vertex*> finalList;

	if (base==NULL){
		#ifdef DEBUG
		std::cout << "NULL passed, returning empty list" << '\n';
		#endif
		return std::vector<Vertex*>();
	}
	#ifdef DEBUG
	std::cout << "base: ("<<base->getPoint().getPointString()<<")" << '\n';
	#endif

	directSons=getSons(base);
	finalList=directSons;
	for (it = directSons.begin(); it != directSons.end() ; it++){
		if (*it!=base){
			#ifdef DEBUG
			std::cout << "\tson: ("<<(*it)->getPoint().getPointString()<<")" << '\n';
			#endif
			listTemp=iGetAllVertexes(*it);
			finalList.insert(finalList.end(),listTemp.begin()+1,listTemp.end());
		}
	}
	return finalList;
}
#define DEBUG
Vertex* Tree::SearchVertex(Vertex* vertex){
	std::vector<Vertex*> list = getAllVertexes();
	std::vector<Vertex*>::iterator it;
	#ifdef DEBUG
	std::cout << "size for search: "<< list.size() << '\n';
	#endif
	#ifdef DEBUG
	std::cout << "returned values: \n";
	for (it = list.begin() ; it != list.end(); it++){
		if (it != list.begin()) {
			std::cout <<"   -   ";
		}
		std::cout << (*it)->getPoint().getPointString();
	}
	std::cout <<'\n';
	#endif
	for (it = list.begin() ; it != list.end(); it++) {
		#ifdef DEBUG
		std::cout << "compare " <<(*it)->getPoint().getPointString()<<" - "<<vertex->getPoint().getPointString()<< '\n';
		#endif
		if ((*it)->getPoint()==vertex->getPoint()) {
			#ifdef DEBUG
			std::cout << "\tvertex found in tree!!" << '\n';
			#endif
			return (*it);
		}
	}
	#ifdef DEBUG
	std::cout << "\tsearch failed!!" << '\n';
	#endif
	return NULL;
}
#undef DEBUG
void Tree::printTree(){
	std::vector<Vertex*> list = getAllVertexes();
	std::vector<Vertex*>::iterator it;
	Vertex* vertexCurrParent;
	Vertex* vertexCurrSon;
	for (it = list.begin() ; it != list.end(); it++) {
		for (size_t i = 0; i < (*it)->getEdges().size(); i++) {
			vertexCurrParent=(*it);
			vertexCurrSon=(*it)->getEdges()[i]->getVertexSon();
			if (vertexCurrParent!=vertexCurrSon) {
				std::cout << vertexCurrParent->getPoint().getPointString() << " -> " << vertexCurrSon->getPoint().getPointString() << '\n';
			}
		}
	}
}


bool Tree::tryConnect(std::vector<Tree*>& headsT)
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
				if ((**itTree).areConnected(**itTreeInner))
				{
					#ifdef DEBUG
					std::cout << "Vertice duplicado, eliminando entrada doble" << '\n';
					#endif
					std::cout << "Vertice duplicado, eliminando entrada doble" << '\n';
					headsT.erase(itTree);
					return true;
				}
			}
		}
	}
	return false;
}


bool Tree::areConnected(Tree t)
{
	std::vector<Vertex*> list;
	std::vector<Vertex*> listInner;

	std::vector<Vertex*>::iterator itList;
	std::vector<Vertex*>::iterator itListInner;


	list = this->getAllVertexes();
	listInner = t.getAllVertexes();

	for (itList = list.begin()+1; itList < list.end(); itList++)
	{
		for (itListInner = listInner.begin()+1; itListInner < listInner.end(); itListInner++)
		{
			if((*itList)->getPoint()==(*itListInner)->getPoint())
			{
				// std::cout<<(*itList)->getPoint().getPointString()<<" = "<<(*itListInner)->getPoint().getPointString()<<"\n";
				// std::cout << "are conected!" << '\n';
				return true;
			}
		}
	}
	// std::cout << "are NOT connected" << '\n';
		return false;
}
