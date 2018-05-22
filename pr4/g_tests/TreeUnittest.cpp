#include "gtest/gtest.h"
#include "Tree.hpp"

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
}
