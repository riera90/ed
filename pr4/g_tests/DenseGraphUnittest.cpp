#include "gtest/gtest.h"
#include "DenseGraph.hpp"

TEST(DenseGraph, Builder){
	DenseGrpah g;
	EXPECT_EQ(g.getVertexes().size(),0);
}

TEST(DenseGraph, add_with_duplicated_values){
	DenseGrpah g;
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
	DenseGrpah g;
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
	DenseGrpah g;
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
	DenseGrpah g;
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
	DenseGrpah g;
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


// TEST(DenseGraph, minTreePrim){
// 	DenseGrpah g;
// 	Vertex* v0=new Vertex(Point2D(0,0));
// 	Vertex* v1=new Vertex(Point2D(1,5));
// 	Vertex* v2=new Vertex(Point2D(2,1));
// 	Vertex* v3=new Vertex(Point2D(3,2));
// 	Vertex* v4=new Vertex(Point2D(4,4));
// 	Vertex* v5=new Vertex(Point2D(5,5));
//
// 	g.addVertex(v0);
// 	g.addVertex(v1);
// 	g.addVertex(v2);
// 	g.addVertex(v3);
// 	g.addVertex(v4);
// 	g.addVertex(v5);
//
// 	Tree t=g.minTreePrim();
// 	t.printTree();
// }
