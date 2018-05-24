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
		if (parentNode->getEdges()[i]->getVertexSon()!=NULL) {
			sons.push_back(parentNode->getEdges()[i]->getVertexSon());
		}
	}
	return sons;
}

std::vector<Vertex*> Tree::getAllRelactioned(Vertex* parentNode){
	std::vector<Vertex*> sons;
	if (parentNode==NULL) {
		// std::cout << "is NULL!!" << '\n';
		return sons;
	}
	//for edge in edges
	// std::cout << "not NULL, size is <" << parentNode->getEdges().size() << ">\n";
	for (int i = 0; i < parentNode->getEdges().size(); i++) {
		sons.push_back(parentNode->getEdges()[i]->getOtherVertex(*parentNode));
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
	std::vector<Vertex*> list2;
	std::vector<Vertex*>::iterator it_i;
	std::vector<Vertex*>::iterator it_o;
	list2 = iGetAllVertexes(getRoot(),std::vector<Vertex*>());
	list1.push_back(getRoot());
	list1.insert(list1.end(),list2.begin(),list2.end());


	//chechs for duplicated values
	for (it_o = list1.begin(); it_o != list1.end(); it_o++)
	{
		for (it_i = list1.begin(); it_i != list1.end(); it_i++)
		{
			if (it_o!=it_i)
			{
				if((*it_o)->getPoint().getPointString()==(*it_i)->getPoint().getPointString())
				{
					list1.erase(it_i);
					it_i--;
				}
			}
		}
	}

	// std::cout << "list: ";
	// for (it_o = list1.begin(); it_o != list1.end(); it_o++)
	// {
	// 	std::cout <<"("<<(*it_o)->getPoint().getPointString()<<") - ";
	// }
	// std::cout  << '\n';

	return list1;
}

std::vector<Vertex*> Tree::iGetAllVertexes(Vertex* base, std::vector<Vertex*> visited){
	#ifdef DEBUG
	std::cout << "start!" << '\n';
	#endif
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
	//adds all the relactioned vertex to the list
	directSons=getAllRelactioned(base);

	//filter the list for duplicated values (we dont want the base in here as it would cause INFINITE RECURSION!)
	#ifdef DEBUG
	std::cout << "sons: ("<<base->getPoint().getPointString()<<") =>" << '\n';
	#endif
	for (it = directSons.begin(); it != directSons.end() ; it++){
		#ifdef DEBUG
		std::cout << "    ->(" << (*it)->getPoint().getPointString()<<")";
		#endif
		if (base==*it) {
			#ifdef DEBUG
			std::cout << " <-[removing duplicated]";
			#endif
			directSons.erase(it);
			it--;
		}
	}
	#ifdef DEBUG
	std::cout << "\n    clear list:  ("<<base->getPoint().getPointString()<<") =>";
	for (it = directSons.begin(); it != directSons.end() ; it++){
		std::cout << "    ->(" << (*it)->getPoint().getPointString()<<")";
	}
	#endif
	visited.push_back(base);
	#ifdef DEBUG
	std::cout << "\nvisited: ";
	for (it = visited.begin(); it != visited.end() ; it++){
		std::cout << "   (" << (*it)->getPoint().getPointString()<<")";
	}
	std::cout << '\n';
	#endif


	finalList=directSons;

	//second filter


	for (it = directSons.begin(); it != directSons.end() ; it++){
		std::vector<Vertex*>::iterator it_visited;
		bool isVisited=false;
		for (it_visited = visited.begin(); it_visited != visited.end() ; it_visited++)
		{
			#ifdef DEBUG
			std::cout << (*it)->getPoint().getPointString() <<" vs " << (*it_visited)->getPoint().getPointString() << '\n';
			#endif
			if (*it_visited==*it) isVisited=true;
		}
		if (!isVisited) {
			#ifdef DEBUG
			std::cout << "\tson: ("<<(*it)->getPoint().getPointString()<<")" << '\n';
			#endif
			listTemp=iGetAllVertexes(*it, visited);

			finalList.insert(finalList.end(),listTemp.begin(),listTemp.end());
		}
	}

	#ifdef DEBUG
	std::cout << "end!!" << '\n';
	#endif
	return finalList;
}
// #define DEBUG
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
		std::cout <<"compare "<<(*it)->getPoint().getPointString()<<" - "<<vertex->getPoint().getPointString()<< '\n';
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
// #undef DEBUG
void Tree::printTree(){
	std::vector<Vertex*> list = getAllVertexes();
	std::vector<Vertex*>::iterator it;
	Vertex* vertexCurrParent;
	Vertex* vertexCurrSon;
	for (it = list.begin() ; it != list.end(); it++) {
		for (size_t i = 0; i < (*it)->getEdges().size(); i++) {
			vertexCurrParent=(*it);
			vertexCurrSon=(*it)->getEdges()[i]->getOtherVertex(*vertexCurrParent);
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
	std::cout << "begin!" << '\n';
	std::vector<Vertex*> list;
	std::vector<Vertex*> listInner;

	std::vector<Vertex*>::iterator itList;
	std::vector<Vertex*>::iterator itListInner;


	list = this->getAllVertexes();
	listInner = t.getAllVertexes();

	std::cout << "set 1: ";
	for (itList = list.begin(); itList < list.end(); itList++)
	{
		std::cout << "("<<(*itList)->getPoint().getPointString()<<")  -  ";
	}
	std::cout << "\nset 2: ";
	for (itListInner = listInner.begin(); itListInner < listInner.end(); itListInner++)
	{
		std::cout << "("<<(*itListInner)->getPoint().getPointString()<<")  -  ";
	}
	std::cout << '\n';


	for (itList = list.begin(); itList < list.end(); itList++)
	{
		for (itListInner = listInner.begin(); itListInner < listInner.end(); itListInner++)
		{
			std::cout<<(*itList)->getPoint().getPointString()<<" = "<<(*itListInner)->getPoint().getPointString()<<"\n";
			if((*itList)->getPoint()==(*itListInner)->getPoint())
			{
				// std::cout<<(*itList)->getPoint().getPointString()<<" = "<<(*itListInner)->getPoint().getPointString()<<"\n";
				std::cout << "are conected!" << '\n';
				return true;
			}
		}
	}
	std::cout << "are NOT connected" << '\n';
		return false;
}
