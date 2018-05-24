#include "gtest/gtest.h"
#include "Tree.hpp"
#include "DenseGraph.hpp"

TEST(Tree, Builder){
	Tree t;
	EXPECT_TRUE(t.getRoot()==NULL);
}

TEST(Tree, getSon_and_parent_empty){
	Tree t;
	EXPECT_TRUE(t.getParent(t.getRoot())==NULL);
	EXPECT_EQ(t.getSons(t.getRoot()).size(),0);
}

TEST(Tree, tree_build){
	Tree t;
	Point2D p0(0,0);
	Point2D p1(1,1);
	Point2D p2(2,2);
	Point2D p3(3,3);
	Point2D p4(4,4);
	Vertex* v0=new Vertex(p0);
	Vertex* v1=new Vertex(p1);
	Vertex* v2=new Vertex(p2);
	Vertex* v3=new Vertex(p3);
	Vertex* v4=new Vertex(p4);
	t.setRoot(v0);
	EXPECT_TRUE(t.getParent(t.getRoot())==NULL);
	EXPECT_EQ(t.getSons(t.getRoot()).size(),0);

	Edge* e0=new Edge(t.getRoot(), v1);
	t.getRoot()->addEdge(e0);
	v1->addEdge(e0);

	Edge* e1=new Edge(t.getRoot(), v2);
	t.getRoot()->addEdge(e1);
	v1->addEdge(e1);

	Edge* e2=new Edge(v2, v3);
	v2->addEdge(e2);
	v3->addEdge(e2);

	Edge* e3=new Edge(v2, v4);
	v2->addEdge(e3);
	v4->addEdge(e3);

	EXPECT_EQ(t.getSons(t.getRoot()).size(),2);

	Vertex* vaux;
	vaux=t.getSons(t.getRoot())[0];
	EXPECT_EQ(vaux,v1);
	vaux=t.getSons(t.getRoot())[1];
	EXPECT_EQ(vaux,v2);

	Vertex* vaux2;
	vaux2=t.getSons(vaux)[0];
	EXPECT_EQ(vaux2,v3);
	vaux2=t.getSons(vaux)[1];
	EXPECT_EQ(vaux2,v4);
}

TEST(Tree, getAllVertexes){
	Tree t;
	std::vector<Tree*> headsT;
	std::vector<Vertex*> list;
	Vertex* v0=new Vertex(Point2D(0,0));
	Vertex* v1=new Vertex(Point2D(1,5));
	Vertex* v2=new Vertex(Point2D(2,1));
	Vertex* v3=new Vertex(Point2D(3,2));
	Vertex* v4=new Vertex(Point2D(4,4));
	Vertex* v5=new Vertex(Point2D(5,5));
	t.setRoot(v0);
	EXPECT_TRUE(t.getParent(t.getRoot())==NULL);
	EXPECT_EQ(t.getSons(t.getRoot()).size(),0);

	t.addSon(t.getRoot(),v1);
	t.addSon(t.getRoot(),v2);

	list = t.getAllVertexes();
	EXPECT_EQ(list.size(),3);

	t.addSon(v1,v3);
	t.addSon(v2,v4);

	list = t.getAllVertexes();
	EXPECT_EQ(list.size(),5);

	t.addSon(v4,v5);

	list = t.getAllVertexes();
	EXPECT_EQ(list.size(),6);
}

// TEST(Tree, print){
// 	Tree t;
// 	Point2D p0(0,0);
// 	Point2D p1(1,1);
// 	Point2D p2(2,2);
// 	Point2D p3(3,3);
// 	Point2D p4(4,4);
// 	Vertex* v0=new Vertex(p0);
// 	Vertex* v1=new Vertex(p1);
// 	Vertex* v2=new Vertex(p2);
// 	Vertex* v3=new Vertex(p3);
// 	Vertex* v4=new Vertex(p4);
// 	t.setRoot(v0);
// 	EXPECT_TRUE(t.getParent(t.getRoot())==NULL);
// 	EXPECT_EQ(t.getSons(t.getRoot()).size(),0);
//
// 	Edge* e0=new Edge(t.getRoot(), v1);
// 	t.getRoot()->addEdge(e0);
// 	v1->addEdge(e0);
//
// 	Edge* e1=new Edge(t.getRoot(), v2);
// 	t.getRoot()->addEdge(e1);
// 	v1->addEdge(e1);
//
// 	Edge* e2=new Edge(v2, v3);
// 	v2->addEdge(e2);
// 	v3->addEdge(e2);
//
// 	Edge* e3=new Edge(v2, v4);
// 	v2->addEdge(e3);
// 	v4->addEdge(e3);
//
// 	t.printTree();
// 	std::string response;
// 	std::cout << "is this ok? [y/n]\n\t-> ";
// 	std::cin >> response;
// 	EXPECT_EQ(response,"y");
// }


TEST(Tree, areConnected){
	std::vector<Tree*> headsT;
	Vertex* v0=new Vertex(Point2D(0,0));
	Vertex* v1=new Vertex(Point2D(1,5));
	Vertex* v2=new Vertex(Point2D(2,1));
	Vertex* v3=new Vertex(Point2D(3,2));
	Vertex* v4=new Vertex(Point2D(4,4));
	Vertex* v5=new Vertex(Point2D(5,5));

	headsT.push_back(new Tree());
	headsT.push_back(new Tree());

	headsT[0]->setRoot(v0);
	headsT[1]->setRoot(v1);

	EXPECT_FALSE(headsT[0]->areConnected(*headsT[1]));

	headsT[0]->addSon(v0,v2);
	headsT[0]->addSon(v0,v4);
	headsT[1]->addSon(v1,v3);
	headsT[1]->addSon(v1,v5);

	EXPECT_FALSE(headsT[0]->areConnected(*headsT[1]));

	headsT[0]->addSon(v4,v5);

	EXPECT_TRUE(headsT[0]->areConnected(*headsT[1]));
}


TEST(Tree, tryConnect){
	std::vector<Tree*> headsT;
	Vertex* v0=new Vertex(Point2D(0,0));
	Vertex* v1=new Vertex(Point2D(1,5));
	Vertex* v2=new Vertex(Point2D(2,1));
	Vertex* v3=new Vertex(Point2D(3,2));
	Vertex* v4=new Vertex(Point2D(4,4));
	Vertex* v5=new Vertex(Point2D(5,5));

	headsT.push_back(new Tree());
	headsT.push_back(new Tree());

	headsT[0]->setRoot(v0);
	headsT[1]->setRoot(v1);

	headsT[0]->addSon(v0,v2);
	headsT[0]->addSon(v0,v4);
	headsT[1]->addSon(v1,v3);
	headsT[1]->addSon(v1,v5);

	headsT[0]->tryConnect(headsT);

	EXPECT_EQ(headsT.size(),2);

	headsT[0]->addSon(v4,v5);

	EXPECT_EQ(headsT.size(),2);

	headsT[0]->tryConnect(headsT);

	EXPECT_EQ(headsT.size(),1);
}


TEST(Tree, areConnected_2){
	std::vector<Tree*> headsT;
	Vertex* v0=new Vertex(Point2D(0,0));
	Vertex* v1=new Vertex(Point2D(1,5));
	Vertex* v2=new Vertex(Point2D(2,1));
	Vertex* v3=new Vertex(Point2D(3,2));
	Vertex* v4=new Vertex(Point2D(4,4));
	Vertex* v5=new Vertex(Point2D(5,5));

	headsT.push_back(new Tree());
	headsT.push_back(new Tree());

	headsT[0]->setRoot(v2);
	headsT[1]->setRoot(v4);

	headsT[0]->addSon(v2,v3);
	headsT[1]->addSon(v4,v5);

	EXPECT_FALSE(headsT[0]->areConnected(*headsT[1]));

	headsT[0]->addSon(v3,v4);

	EXPECT_TRUE(headsT[0]->areConnected(*headsT[1]));
}


TEST(Tree, areConnected_3){
	std::vector<Tree*> headsT;
	Edge* edge;
	Vertex* v0=new Vertex(Point2D(0,0));
	Vertex* v1=new Vertex(Point2D(1,5));
	Vertex* v2=new Vertex(Point2D(2,1));
	Vertex* v3=new Vertex(Point2D(3,2));
	Vertex* v4=new Vertex(Point2D(4,4));
	Vertex* v5=new Vertex(Point2D(5,5));

	headsT.push_back(new Tree());
	headsT.push_back(new Tree());
	headsT.push_back(new Tree());
	headsT.push_back(new Tree());
	headsT.push_back(new Tree());
	headsT.push_back(new Tree());

	headsT[0]->setRoot(v0);
	headsT[1]->setRoot(v1);
	headsT[2]->setRoot(v2);
	headsT[3]->setRoot(v3);
	headsT[4]->setRoot(v4);
	headsT[5]->setRoot(v5);

	EXPECT_FALSE(headsT[0]->areConnected(*(headsT[1])));
	EXPECT_FALSE(headsT[0]->areConnected(*(headsT[2])));
	EXPECT_FALSE(headsT[0]->areConnected(*(headsT[3])));
	EXPECT_FALSE(headsT[0]->areConnected(*(headsT[4])));
	EXPECT_FALSE(headsT[0]->areConnected(*(headsT[5])));

	edge=new Edge(headsT[1]->getRoot(), headsT[2]->getRoot());
	headsT[1]->getRoot()->addEdge(edge);
	headsT[2]->getRoot()->addEdge(edge);

	EXPECT_FALSE(headsT[0]->areConnected(*(headsT[1])));
	EXPECT_FALSE(headsT[0]->areConnected(*(headsT[2])));
	EXPECT_FALSE(headsT[0]->areConnected(*(headsT[3])));
	EXPECT_FALSE(headsT[0]->areConnected(*(headsT[4])));
	EXPECT_FALSE(headsT[0]->areConnected(*(headsT[5])));

	EXPECT_FALSE(headsT[1]->areConnected(*(headsT[0])));
	EXPECT_TRUE (headsT[1]->areConnected(*(headsT[2])));
	EXPECT_FALSE(headsT[1]->areConnected(*(headsT[3])));
	EXPECT_FALSE(headsT[1]->areConnected(*(headsT[4])));
	EXPECT_FALSE(headsT[1]->areConnected(*(headsT[5])));


	EXPECT_FALSE(headsT[0]->areConnected(*headsT[1]));
	EXPECT_FALSE(headsT[0]->areConnected(*headsT[3]));
	EXPECT_FALSE(headsT[0]->areConnected(*headsT[4]));
	EXPECT_FALSE(headsT[0]->areConnected(*headsT[5]));
}


// TEST(Tree, areConnected_4){
	// std::vector<Tree*> headsT;
	// DenseGraph g;
	// Edge* edge;
	// Vertex* v0=new Vertex(Point2D(0,0));
	// Vertex* v1=new Vertex(Point2D(1,5));
	// Vertex* v2=new Vertex(Point2D(2,1));
	// Vertex* v3=new Vertex(Point2D(3,2));
	// Vertex* v4=new Vertex(Point2D(4,4));
	// Vertex* v5=new Vertex(Point2D(5,5));
	//
	// headsT.push_back(new Tree());
	// headsT.push_back(new Tree());
	// headsT.push_back(new Tree());
	// headsT.push_back(new Tree());
	// headsT.push_back(new Tree());
	// headsT.push_back(new Tree());
	//
	// headsT[0]->setRoot(v0);
	// headsT[1]->setRoot(v1);
	// headsT[2]->setRoot(v2);
	// headsT[3]->setRoot(v3);
	// headsT[4]->setRoot(v4);
	// headsT[5]->setRoot(v5);
	//
	// edge=new Edge(v0,v2);
	//
	//
	// v0->addEdge(edge);
	// v2->addEdge(edge);
	//
	// g.printListTrees(headsT);
	//
	// EXPECT_TRUE(headsT[0]->areConnected(*headsT[2]));
	// EXPECT_FALSE(headsT[0]->areConnected(*headsT[1]));
	// EXPECT_FALSE(headsT[0]->areConnected(*headsT[3]));
	// EXPECT_FALSE(headsT[0]->areConnected(*headsT[4]));
	// EXPECT_FALSE(headsT[0]->areConnected(*headsT[5]));

	// v0->addEdge(new Edge(v2,v2));
	// v2->addEdge(new Edge(v2,v2));
// }
