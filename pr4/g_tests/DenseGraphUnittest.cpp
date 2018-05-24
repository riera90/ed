#include "gtest/gtest.h"
#include "DenseGraph.hpp"

TEST(DenseGraph, Builder){
	DenseGraph g;
	EXPECT_EQ(g.getVertexes().size(),0);
}

TEST(DenseGraph, add_with_duplicated_values){
	DenseGraph g;
	Vertex* v0=new Vertex(Point2D(0,0));
	Vertex* v1=new Vertex(Point2D(1,1));
	Vertex* v2=new Vertex(Point2D(2,2));
	g.addVertex(v0);
	g.addVertex(v1);
	g.addVertex(v2);
	EXPECT_EQ(g.getVertexes().size(),3);
	g.addVertex(v2);
	EXPECT_EQ(g.getVertexes().size(),3);
	EXPECT_EQ(g.getVertexes()[0]->getEdges().size(),2);
	EXPECT_EQ(g.getVertexes()[0]->getPoint(),Point2D(0,0));
	EXPECT_EQ(g.getVertexes()[1]->getPoint(),Point2D(1,1));
}

TEST(DenseGraph, delete){
	DenseGraph g;
	Vertex* v0=new Vertex(Point2D(0,0));
	Vertex* v1=new Vertex(Point2D(1,1));
	Vertex* v2=new Vertex(Point2D(2,2));
	g.addVertex(v0);
	g.addVertex(v1);
	g.addVertex(v2);
	g.RemoveVertex(v1);
	EXPECT_EQ(g.getVertexes().size(),2);
	EXPECT_EQ(g.getVertexes()[0]->getEdges().size(),1);
	EXPECT_EQ(g.getVertexes()[0]->getPoint(),Point2D(0,0));
	EXPECT_EQ(g.getVertexes()[1]->getPoint(),Point2D(2,2));
}

TEST(DenseGraph, edges){
	DenseGraph g;
	Vertex* v0=new Vertex(Point2D(0,0));
	Vertex* v1=new Vertex(Point2D(1,1));
	Vertex* v2=new Vertex(Point2D(2,2));
	g.addVertex(v0);
	g.addVertex(v1);
	g.addVertex(v2);
	EXPECT_EQ(g.getVertexes()[0]->getEdges()[0]->getOtherVertex(*g.getVertexes()[0])->getPoint(), g.getVertexes()[1]->getPoint());
	EXPECT_EQ(g.getVertexes()[0]->getEdges()[1]->getOtherVertex(*g.getVertexes()[0])->getPoint(), g.getVertexes()[2]->getPoint());
}

TEST(DenseGraph, edges_with_detete){
	DenseGraph g;
	Vertex* v0=new Vertex(Point2D(0,0));
	Vertex* v1=new Vertex(Point2D(1,1));
	Vertex* v2=new Vertex(Point2D(2,2));
	g.addVertex(v0);
	g.addVertex(v1);
	g.addVertex(v2);
	g.RemoveVertex(v1);
	EXPECT_EQ(g.getVertexes()[0]->getEdges()[0]->getOtherVertex(*g.getVertexes()[0])->getPoint(), g.getVertexes()[1]->getPoint());
	EXPECT_EQ(g.getVertexes()[0]->getEdges().size(),1);
	EXPECT_EQ(g.getVertexes()[1]->getEdges().size(),1);
}

TEST(DenseGraph, edges_with_detete_extended){
	DenseGraph g;
	Vertex* v0=new Vertex(Point2D(0,0));
	Vertex* v1=new Vertex(Point2D(1,1));
	Vertex* v2=new Vertex(Point2D(2,2));
	Vertex* v3=new Vertex(Point2D(3,3));

	g.addVertex(v0);
	g.addVertex(v1);
	g.addVertex(v2);
	g.addVertex(v3);
	g.RemoveVertex(v1);

	EXPECT_EQ(g.getVertexes()[0]->getEdges()[0]->getOtherVertex(*g.getVertexes()[0])->getPoint(), g.getVertexes()[1]->getPoint());
	EXPECT_EQ(g.getVertexes()[0]->getEdges()[1]->getOtherVertex(*g.getVertexes()[0])->getPoint(), g.getVertexes()[2]->getPoint());

	EXPECT_EQ(g.getVertexes()[1]->getEdges()[0]->getOtherVertex(*g.getVertexes()[1])->getPoint(), g.getVertexes()[0]->getPoint());
	EXPECT_EQ(g.getVertexes()[1]->getEdges()[1]->getOtherVertex(*g.getVertexes()[1])->getPoint(), g.getVertexes()[2]->getPoint());

	EXPECT_EQ(g.getVertexes()[2]->getEdges()[0]->getOtherVertex(*g.getVertexes()[2])->getPoint(), g.getVertexes()[0]->getPoint());
	EXPECT_EQ(g.getVertexes()[2]->getEdges()[1]->getOtherVertex(*g.getVertexes()[2])->getPoint(), g.getVertexes()[1]->getPoint());
}


TEST(DenseGraph, minTreePrim){
	DenseGraph g;
	Vertex* v0=new Vertex(Point2D(0,0));
	Vertex* v1=new Vertex(Point2D(1,5));
	Vertex* v2=new Vertex(Point2D(2,1));
	Vertex* v3=new Vertex(Point2D(3,2));
	Vertex* v4=new Vertex(Point2D(4,4));
	Vertex* v5=new Vertex(Point2D(5,5));

	g.addVertex(v0);
	g.addVertex(v1);
	g.addVertex(v2);
	g.addVertex(v3);
	g.addVertex(v4);
	g.addVertex(v5);

	Tree t=g.minTreePrim();
	std::vector<Vertex*> list = t.getAllVertexes();
	EXPECT_EQ(list.size(),6);
	EXPECT_EQ(*list[0],*v0);
	EXPECT_EQ(*list[1],*v2);
	EXPECT_EQ(*list[2],*v3);
	EXPECT_EQ(*list[3],*v4);
	EXPECT_EQ(*list[4],*v5);
	EXPECT_EQ(*list[5],*v1);
}

TEST(DenseGraph, minTreeKruskal){
	DenseGraph g;
	Vertex* v0=new Vertex(Point2D(0,0));
	Vertex* v1=new Vertex(Point2D(1,5));
	Vertex* v2=new Vertex(Point2D(2,1));
	Vertex* v3=new Vertex(Point2D(3,2));
	Vertex* v4=new Vertex(Point2D(4,4));
	Vertex* v5=new Vertex(Point2D(5,5));

	g.addVertex(v0);
	g.addVertex(v1);
	g.addVertex(v2);
	g.addVertex(v3);
	g.addVertex(v4);
	g.addVertex(v5);

	Tree t=g.minTreeKruskal();
	std::vector<Vertex*> list = t.getAllVertexes();
	t.printTree();
	// EXPECT_EQ(list.size(),6);
	// EXPECT_EQ(*list[0],*v0);
	// EXPECT_EQ(*list[1],*v2);
	// EXPECT_EQ(*list[2],*v3);
	// EXPECT_EQ(*list[3],*v4);
	// EXPECT_EQ(*list[4],*v5);
	// EXPECT_EQ(*list[5],*v1);
}
